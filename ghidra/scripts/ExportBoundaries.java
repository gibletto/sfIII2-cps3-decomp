// Export every function's boundaries, for comparing Ghidra's analysis with the code/data map and the 3s matches.
//
// Usage (headless):
//   analyzeHeadless <proj_dir> sfiii2 -process <image> -noanalysis -readOnly -scriptPath <scripts> \
//     [-postScript ApplyTables.java <names dir>] -postScript ExportBoundaries.java <out.tsv>
// Output: entry <tab> end <tab> body (bytes) <tab> ranges <tab> instructions <tab> name <tab> prov
//   end: the address after the highest byte of the body; ranges: the body's address ranges (1 = contiguous);
//   prov: the plate comment ApplyTables set, without its "prov: ", empty for an unnamed function.

import java.io.*;
import java.nio.charset.StandardCharsets;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.*;

public class ExportBoundaries extends GhidraScript {
	@Override
	protected void run() throws Exception {
		File out = new File(getScriptArgs()[0]);
		Listing listing = currentProgram.getListing();
		int n = 0;
		try (Writer w = new OutputStreamWriter(new FileOutputStream(out), StandardCharsets.UTF_8)) {
			w.write("entry\tend\tbody\tranges\tinstructions\tname\tprov\n");
			for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
				AddressSetView b = f.getBody();
				int insns = 0;
				InstructionIterator it = listing.getInstructions(b, true);
				while (it.hasNext()) {
					it.next();
					insns++;
				}
				String prov = getPlateComment(f.getEntryPoint());
				w.write(f.getEntryPoint() + "\t" + b.getMaxAddress().add(1) + "\t" + b.getNumAddresses() + "\t" +
				        b.getNumAddressRanges() + "\t" + insns + "\t" + f.getName() + "\t" +
				        (prov == null ? "" : prov.replaceFirst("^prov: ", "").replace('\t', ' ').replace('\n', ' ')) + "\n");
				n++;
			}
		}
		println("ExportBoundaries: " + n + " functions -> " + out);
	}
}
