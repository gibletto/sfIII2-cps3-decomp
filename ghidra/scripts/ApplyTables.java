// Apply the 2nd Impact naming tables (ghidra/names/) to the program: data types, function names and signatures,
// global names and types, local variable names, and each name's provenance (docs/PROVENANCE.md). Adapted from the
// compiler rebuild's ApplyStageTables.java (gibletto/shc-5r26-decomp-sf3). The tables are the version-controlled record: the
// Ghidra project is never edited, tools/ghidra-export.sh opens it read-only and runs this script in every session,
// so a name exists only as a table row and every export reproduces it.
//
// Usage (headless):
//   analyzeHeadless <proj_dir> sfiii2 -process <image> -noanalysis -readOnly -scriptPath <scripts> //     -postScript ApplyTables.java <names dir>
//
// <names dir> holds (each optional; columns in docs/PROVENANCE.md):
//   entries.tsv    address, note                    code the analysis left without a function: made one first
//   enums.tsv      enum, size, member, value, class, sf3_src      class/sf3_src on an enum's first row
//   types.h        C struct/union definitions; "// @size NAME 0xNN" checked; "// @prov NAME class sf3_src" lines
//                  are the types' provenance (checked by tools/check-tables.py, not applied)
//   functions.tsv  address, name, signature, class, sf3_addr, sf3_name, sf3_src, note   a row asserts a function
//                  entry: made a function first if the analysis has none there
//   globals.tsv    address, name, type, class, sf3_addr, sf3_name, sf3_src, note
//   locals.tsv     function, old name, new name, type, first use, storage, class, note
// A function or global row's provenance is also set as the plate comment at its address ("prov: ..."), so the
// listing and the export (ExportFullDecomp.java writes it into each function's header) show where the name came
// from. Lines starting with # and blank lines are skipped. Any failure is printed as "ApplyTables: ERROR ..." and the
// script then throws, so an export never silently runs with half the tables.

import java.io.File;
import java.nio.file.*;
import java.util.*;

import ghidra.app.cmd.function.ApplyFunctionSignatureCmd;
import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.app.services.DataTypeManagerService;
import ghidra.app.util.cparser.C.CParser;
import ghidra.app.util.cparser.C.CParserUtils;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;
import ghidra.program.model.symbol.*;

public class ApplyTables extends GhidraScript {

	private int errors = 0;
	private final CategoryPath cat = new CategoryPath("/sfiii2");

	private void error(String msg) {
		println("ApplyTables: ERROR " + msg);
		errors++;
	}

	private List<String[]> rows(File f, int min) throws Exception {
		List<String[]> out = new ArrayList<>();
		if (!f.isFile()) return out;
		int n = 0;
		for (String l : Files.readAllLines(f.toPath())) {
			n++;
			if (l.trim().isEmpty() || l.startsWith("#")) continue;
			String[] p = l.split("\t", -1);
			if (p.length < min) {
				error(f.getName() + ":" + n + ": expected " + min + " columns: " + l);
				continue;
			}
			for (int i = 0; i < p.length; i++) p[i] = p[i].trim();
			out.add(p);
		}
		return out;
	}

	private static final Set<String> CLASSES = Set.of("3s-exact", "3s-reloc", "3s-near", "inferred", "new");

	/** columns 3-7 of a functions/globals row as the plate comment; null (and an error) for an unknown class */
	private String provenance(String table, String[] r) {
		String cls = r.length > 3 ? r[3] : "";
		if (!CLASSES.contains(cls)) {
			error(table + ": " + r[0] + " " + r[1] + ": provenance class '" + cls + "' is not one of " + CLASSES);
			return null;
		}
		StringBuilder b = new StringBuilder("prov: ").append(cls);
		if (r.length > 5 && !r[5].isEmpty()) b.append(" sf3 ").append(r[5]).append('@').append(r[4]);
		if (r.length > 6 && !r[6].isEmpty()) b.append(' ').append(r[6]);
		if (r.length > 7 && !r[7].isEmpty()) b.append(" -- ").append(r[7]);
		return b.toString();
	}

	private DataTypeManager dtm() {
		return currentProgram.getDataTypeManager();
	}

	/** a C type spelling ("psd *", "int [4]", "unsigned char") -> a data type of this program */
	private DataType resolveType(String spec) throws Exception {
		String s = spec.trim();
		List<Integer> dims = new ArrayList<>();
		while (s.endsWith("]")) {
			int i = s.lastIndexOf('[');
			dims.add(0, Integer.decode(s.substring(i + 1, s.length() - 1).trim()));
			s = s.substring(0, i).trim();
		}
		int stars = 0;
		while (s.endsWith("*")) {
			stars++;
			s = s.substring(0, s.length() - 1).trim();
		}
		DataType base = findType(s);
		if (base == null) throw new Exception("unknown type '" + s + "' in '" + spec + "'");
		DataType t = base;
		for (int i = 0; i < stars; i++) t = new PointerDataType(t, dtm());
		for (int i = dims.size() - 1; i >= 0; i--) t = new ArrayDataType(t, dims.get(i), t.getLength(), dtm());
		return t;
	}

	private DataType findType(String name) {
		String n = name.replaceFirst("^(struct|union|enum)\\s+", "");
		Map<String, String> c = Map.of("unsigned char", "uchar", "unsigned short", "ushort", "unsigned int", "uint",
		                               "signed char", "char", "unsigned long", "ulong");
		n = c.getOrDefault(n, n);
		List<DataType> found = new ArrayList<>();
		dtm().findDataTypes(n, found);
		for (DataType d : found) if (d.getCategoryPath().equals(cat)) return d;
		if (!found.isEmpty()) return found.get(0);
		DataType b = BuiltInDataTypeManager.getDataTypeManager().getDataType(new CategoryPath("/"), n);
		return b == null ? null : dtm().resolve(b, null);
	}

	private void applyEnums(File f) throws Exception {
		Map<String, EnumDataType> enums = new LinkedHashMap<>();
		for (String[] r : rows(f, 4)) {
			EnumDataType e = enums.get(r[0]);
			if (e == null) {
				e = new EnumDataType(cat, r[0], Integer.decode(r[1]), dtm());
				enums.put(r[0], e);
			}
			e.add(r[2], Long.decode(r[3]));
		}
		for (EnumDataType e : enums.values()) dtm().addDataType(e, DataTypeConflictHandler.REPLACE_HANDLER);
		println("ApplyTables: " + enums.size() + " enums");
	}

	private void applyTypes(File f) throws Exception {
		if (!f.isFile()) return;
		String text = new String(Files.readAllBytes(f.toPath()));
		CParser p = new CParser(dtm(), true, new DataTypeManager[] { dtm() });
		p.setParseFileName("sfiii2");
		p.parse(text);
		// the parser files types under a category named after the parse file; keep them all in /sfiii2
		int moved = 0;
		Category from = dtm().getCategory(new CategoryPath("/sfiii2"));
		Map<String, Long> want = new LinkedHashMap<>();
		for (String l : text.split("\n")) {
			l = l.trim();
			if (l.startsWith("// @size ")) {
				String[] q = l.substring(9).trim().split("\\s+");
				want.put(q[0], Long.decode(q[1]));
			}
		}
		for (Map.Entry<String, Long> w : want.entrySet()) {
			DataType d = findType(w.getKey());
			if (d == null) error("types.h: @size of unknown type " + w.getKey());
			else if (d.getLength() != w.getValue())
				error("types.h: " + w.getKey() + " is 0x" + Integer.toHexString(d.getLength()) + " bytes, @size says 0x" + Long.toHexString(w.getValue()));
		}
		println("ApplyTables: types parsed, " + want.size() + " sizes checked");
	}

	private void applyEntries(File f) throws Exception {
		FunctionManager fm = currentProgram.getFunctionManager();
		int n = 0;
		for (String[] r : rows(f, 1)) {
			Address a = toAddr(r[0]);
			if (fm.getFunctionAt(a) != null) continue;
			if (fm.getFunctionContaining(a) != null) {
				// a label inside a function (a switch case, a shared tail): left as it is
				println("ApplyTables: entries.tsv: " + r[0] + " is inside " + fm.getFunctionContaining(a).getName());
				continue;
			}
			disassemble(a);
			Function fn = createFunction(a, null);
			if (fn == null) error("entries.tsv: cannot create a function at " + r[0]);
			else n++;
		}
		println("ApplyTables: " + n + " functions created");
	}

	private void applyFunctions(File f) throws Exception {
		FunctionManager fm = currentProgram.getFunctionManager();
		int named = 0, sigs = 0;
		List<String[]> withSig = new ArrayList<>();
		for (String[] r : rows(f, 4)) {
			Function fn = fm.getFunctionAt(toAddr(r[0]));
			if (fn == null && fm.getFunctionContaining(toAddr(r[0])) == null) {
				// a row asserts a function entry (the import seeds it too, SetupCps3.java); code the analysis never
				// made a function (reached only through a pointer constant) is disassembled from its entry here
				disassemble(toAddr(r[0]));
				fn = createFunction(toAddr(r[0]), r[1]);
			}
			if (fn == null) {
				error("functions.tsv: no function at " + r[0]);
				continue;
			}
			if (!fn.getName().equals(r[1])) {
				// a secondary label of that name already there (Ghidra's function ID leaves "FID_conflict" alternatives
				// as labels): remove it, then rename the function
				Symbol other = currentProgram.getSymbolTable().getSymbol(r[1], fn.getEntryPoint(), null);
				if (other != null) other.delete();
				fn.setName(r[1], SourceType.USER_DEFINED);
			}
			String prov = provenance("functions.tsv", r);
			if (prov != null) setPlateComment(fn.getEntryPoint(), prov);
			named++;
			if (r.length > 2 && !r[2].isEmpty()) withSig.add(r);
		}
		// signatures after all names, so a prototype may name any type; each is checked to name its own function
		for (String[] r : withSig) {
			Function fn = fm.getFunctionAt(toAddr(r[0]));
			// the parser takes the name to be everything after the last space: "psd *f(" would name "*f"
			String text = r[2].replaceAll("\\*\\s*(\\w+)\\s*\\(", "* $1(");
			FunctionDefinitionDataType sig = CParserUtils.parseSignature((DataTypeManagerService) null, currentProgram, text, false);
			if (sig == null) {
				error("functions.tsv: cannot parse " + r[2]);
				continue;
			}
			if (!sig.getName().equals(r[1])) {
				error("functions.tsv: " + r[0] + " signature names " + sig.getName() + ", not " + r[1]);
				continue;
			}
			sig.setCallingConvention(fn.getCallingConventionName());
			ApplyFunctionSignatureCmd cmd = new ApplyFunctionSignatureCmd(fn.getEntryPoint(), sig, SourceType.USER_DEFINED);
			if (!cmd.applyTo(currentProgram, monitor)) error("functions.tsv: " + r[2] + ": " + cmd.getStatusMsg());
			else sigs++;
		}
		println("ApplyTables: " + named + " functions named, " + sigs + " signatures");
	}

	private void applyGlobals(File f) throws Exception {
		SymbolTable st = currentProgram.getSymbolTable();
		Listing listing = currentProgram.getListing();
		int n = 0, typed = 0;
		for (String[] r : rows(f, 4)) {
			Address a = toAddr(r[0]);
			if (r.length > 2 && !r[2].isEmpty()) {
				DataType t;
				try {
					t = resolveType(r[2]);
				}
				catch (Exception e) {
					error("globals.tsv: " + r[0] + ": " + e.getMessage());
					continue;
				}
				Data d = listing.getDataAt(a);
				if (d == null || !d.getDataType().isEquivalent(t)) {
					listing.clearCodeUnits(a, a.add(t.getLength() - 1), false);
					listing.createData(a, t);
				}
				typed++;
			}
			String prov = provenance("globals.tsv", r);
			if (prov != null) setPlateComment(a, prov);
			Symbol s = st.getPrimarySymbol(a);
			if (s != null && s.getSource() != SourceType.DEFAULT) {
				if (!s.getName().equals(r[1])) s.setName(r[1], SourceType.USER_DEFINED);
			}
			else {
				createLabel(a, r[1], true, SourceType.USER_DEFINED);
			}
			n++;
		}
		println("ApplyTables: " + n + " globals named, " + typed + " typed");
	}

	private HighFunction decompile(DecompInterface iface, Function fn) {
		DecompileResults res = iface.decompileFunction(fn, 120, monitor);
		return res == null ? null : res.getHighFunction();
	}

	private Map<String, HighSymbol> localSymbols(HighFunction hf) {
		Map<String, HighSymbol> m = new HashMap<>();
		Iterator<HighSymbol> it = hf.getLocalSymbolMap().getSymbols();
		while (it.hasNext()) {
			HighSymbol s = it.next();
			m.put(s.getName(), s);
		}
		return m;
	}

	/** a row's variable: by its first-use address (column 5) when the row has one, since the decompiler's temporary
	    names (iVar3) are renumbered by changes elsewhere; several first used there: the one with the row's storage
	    (column 6) or old name; no address: by the old name */
	private HighSymbol find(Map<String, HighSymbol> syms, String[] r) {
		String pc = r.length > 4 ? r[4] : "";
		if (pc.isEmpty()) return syms.get(r[1]);
		List<HighSymbol> at = new ArrayList<>();
		for (HighSymbol s : syms.values()) {
			Address a = s.getPCAddress();
			if (a != null && a.toString().equals(pc)) at.add(s);
		}
		if (at.size() == 1) return at.get(0);
		for (HighSymbol s : at) if (r.length > 5 && s.getStorage().toString().equals(r[5])) return s;
		for (HighSymbol s : at) if (s.getName().equals(r[1])) return s;
		return at.isEmpty() ? syms.get(r[1]) : null;
	}

	private void applyLocals(File f) throws Exception {
		List<String[]> rs = rows(f, 3);
		if (rs.isEmpty()) return;
		DecompInterface iface = new DecompInterface();
		iface.setOptions(new DecompileOptions());
		iface.toggleCCode(true);
		iface.setSimplificationStyle("decompile");
		iface.openProgram(currentProgram);
		FunctionManager fm = currentProgram.getFunctionManager();
		Map<String, List<String[]>> byFn = new LinkedHashMap<>();
		for (String[] r : rs) byFn.computeIfAbsent(r[0], k -> new ArrayList<>()).add(r);
		int n = 0;
		for (Map.Entry<String, List<String[]>> e : byFn.entrySet()) {
			Function fn = fm.getFunctionAt(toAddr(e.getKey()));
			if (fn == null) {
				error("locals.tsv: no function at " + e.getKey());
				continue;
			}
			// every rename of a function from one decompilation: the old names are the export's, and committing one
			// variable renumbers the decompiler's remaining temporaries
			HighFunction hf = decompile(iface, fn);
			if (hf == null) {
				error("locals.tsv: cannot decompile " + e.getKey());
				continue;
			}
			Map<String, HighSymbol> syms = localSymbols(hf);
			for (String[] r : e.getValue()) {
				HighSymbol sym = find(syms, r);
				if (sym == null) {
					error("locals.tsv: " + r[0] + " has no variable " + r[1] +
					      (r.length > 4 && !r[4].isEmpty() ? " (first used at " + r[4] + ")" : ""));
					continue;
				}
				DataType t = null;
				if (r.length > 3 && !r[3].isEmpty()) {
					try {
						t = resolveType(r[3]);
					}
					catch (Exception x) {
						error("locals.tsv: " + r[0] + " " + r[1] + ": " + x.getMessage());
						continue;
					}
				}
				HighFunctionDBUtil.updateDBVariable(sym, r[2], t, SourceType.USER_DEFINED);
				n++;
			}
			// the new names must all be there afterwards
			HighFunction after = decompile(iface, fn);
			Map<String, HighSymbol> now = after == null ? new HashMap<>() : localSymbols(after);
			for (String[] r : e.getValue())
				if (!now.containsKey(r[2])) error("locals.tsv: " + r[0] + " " + r[1] + " -> " + r[2] + " is not in the decompilation afterwards");
		}
		iface.dispose();
		println("ApplyTables: " + n + " locals renamed");
	}

	@Override
	protected void run() throws Exception {
		File dir = new File(getScriptArgs()[0]);
		if (!dir.isDirectory()) throw new Exception("no tables directory " + dir);
		applyEntries(new File(dir, "entries.tsv"));
		applyEnums(new File(dir, "enums.tsv"));
		applyTypes(new File(dir, "types.h"));
		applyFunctions(new File(dir, "functions.tsv"));
		applyGlobals(new File(dir, "globals.tsv"));
		applyLocals(new File(dir, "locals.tsv"));
		if (errors > 0) throw new Exception("ApplyTables: " + errors + " errors");
		println("ApplyTables: done");
	}
}
