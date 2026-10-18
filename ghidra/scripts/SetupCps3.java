// Pre-analysis setup of the 2nd Impact program, run once at import (tools/ghidra-import.sh): the CPS3 address map
// around the program image, and the analysis seeds. Nothing here names anything; names come only from the tables
// (ApplyTables.java), so this script and the image reproduce the analysed project.
//
// Usage (headless, at import):
//   analyzeHeadless <proj_dir> <proj_name> -import prog.bin -loader BinaryLoader -loader-baseAddr 0x06000000 \
//     -processor SuperH:BE:32:SH-2 -scriptPath <scripts> -preScript SetupCps3.java <names dir> [<data view>]
//
// <data view>: when the imported image is the instruction view alone (prog_op.bin, before the merged image
// existed), the stored bytes (prog_data.bin): the exception table is data, so it is copied from there first.
//
// Memory: the loader gives the program image (06000000-06FFFFFF). Added, uninitialized, so references to them
// resolve to addresses a globals.tsv row can name: BIOS 00000000 (512K), work RAM 02000000 (512K), the video and
// I/O spaces 04000000 / 05000000 (volatile), cache RAM C0000000, the SH-2's on-chip registers FFFFFE00 (volatile).
// Seeds: every vector of the exception table at 06000000 (256 longwords) that points into the image, and the
// address of every row of <names dir>/entries.tsv and functions.tsv, are disassembled and made functions before
// auto-analysis runs.

import java.io.File;
import java.nio.file.Files;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.PointerDataType;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;

public class SetupCps3 extends GhidraScript {

	private static final long IMAGE = 0x06000000L, IMAGE_END = 0x07000000L;

	private void block(String name, long start, long size, boolean vol) throws Exception {
		Memory mem = currentProgram.getMemory();
		if (mem.getBlock(name) != null) return;
		MemoryBlock b = mem.createUninitializedBlock(name, toAddr(start), size, false);
		b.setRead(true);
		b.setWrite(true);
		b.setExecute(false);
		b.setVolatile(vol);
	}

	private boolean seed(long target) throws Exception {
		if (target < IMAGE || target >= IMAGE_END || (target & 1) != 0) return false;
		Address a = toAddr(target);
		if (getFunctionAt(a) != null) return false;
		disassemble(a);
		Function f = createFunction(a, null);
		return f != null;
	}

	@Override
	protected void run() throws Exception {
		MemoryBlock rom = currentProgram.getMemory().getBlock(toAddr(IMAGE));
		if (rom == null) throw new Exception("SetupCps3: no image at 06000000");
		rom.setName("prog");
		rom.setExecute(true);
		rom.setWrite(false);
		block("bios", 0x00000000L, 0x80000, false);
		block("ram", 0x02000000L, 0x80000, false);
		block("io04", 0x04000000L, 0x1000000, true);
		block("io05", 0x05000000L, 0x1000000, true);
		block("cache", 0xC0000000L, 0x400, false);
		block("onchip", 0xFFFFFE00L, 0x200, true);

		String[] args = getScriptArgs();
		if (args.length > 1) {
			byte[] d = Files.readAllBytes(new File(args[1]).toPath());
			currentProgram.getMemory().setBytes(toAddr(IMAGE), java.util.Arrays.copyOf(d, 0x400));
		}
		int vec = 0, ent = 0;
		for (int i = 0; i < 256; i++) {
			Address a = toAddr(IMAGE + 4 * i);
			createData(a, new PointerDataType());
			if (i == 1 || i == 3) continue;   // the reset stack pointers
			if (seed(getInt(a) & 0xFFFFFFFFL)) vec++;
		}
		for (String t : new String[] { "entries.tsv", "functions.tsv" }) {
			File f = args.length > 0 ? new File(args[0], t) : null;
			if (f == null || !f.isFile()) continue;
			for (String l : Files.readAllLines(f.toPath())) {
				if (l.trim().isEmpty() || l.startsWith("#")) continue;
				if (seed(Long.parseLong(l.split("\t")[0].trim(), 16))) ent++;
			}
		}
		println("SetupCps3: " + vec + " vector entries, " + ent + " table entries seeded");
	}
}
