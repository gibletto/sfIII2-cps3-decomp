# Street Fighter III 2nd Impact - CPS3 program source (work in progress)

**AI Disclosure**: this project uses Claude, as the 3rd Strike decomp did.

The reverse-engineering of the CPS3 program ROM of *Street Fighter III 2nd Impact: Giant Attack* (sfiii2n), the
earlier game on the engine of [Street Fighter III 3rd Strike](https://github.com/gibletto/sfIII3-cps3-decomp). The
finished, byte-identical 3rd Strike decomp is the oracle: no debug symbols exist for 2nd Impact, so names come from
3rd Strike, with the evidence for each one recorded (`docs/PROVENANCE.md`). The program is built with the same
compiler, [SHC 5.0 Release 26 rebuilt in C](https://github.com/gibletto/shc-5r26-decomp-sf3) with its arcade rules.

The decomp tree is `sf2i/`. It builds a program byte-identical to the arcade's, and the packed program SIMMs equal
the original ROM's. So far 47 C modules and the boot, interrupt and library assembler are source; everything not yet
decompiled is generated from your ROM at build time (`tools/build2i.py`), so no ROM bytes are in this repository and
each new C module replaces a generated piece. 2nd Impact's own structure layouts are in `sf2i/include/structs.h`,
with the evidence for each in `docs/STRUCTS.md`.

## What is known so far

- **The ROM.** 2nd Impact stores its instructions encrypted (the CPS3 address mask, keys 0, 0) and the data the
  program reads (the vector table, the program header, literal pools, switch and address tables) plain, chosen per
  halfword. `tools/cps3rom2.py` writes both views; `tools/si2map.py` follows the code to build the program as the
  CPU sees it.
- **The code against 3rd Strike.** 38% of 2nd Impact's code is 3rd Strike routines byte for byte or with only
  addresses moved, 46% is the same routines with changes, and 16% has no 3rd Strike counterpart. All the boot and
  assembler routines are there.
- **The compiler.** Every 3rd Strike module whose routines all appear unchanged in 2nd Impact compiles with the
  rebuilt compiler, linked at its 2nd Impact address, to 2nd Impact's exact bytes; with the rules off, most don't.
  2nd Impact was built with the same arcade compiler.
- **The data.** About 46% of the program data is 3rd Strike tables, most with changed values (move timings, hit
  boxes, damage); the rest uses formats 3rd Strike already has (messages, screen maps, stage scripts, sound).

## Layout

    sf2i/           the decomp tree: src/, include/, lib/, bin/ (the compiler), sf2i.sub (the link)
    tools/          ROM reader, code/data map, the 3rd Strike census, data map, build/pack/status, Ghidra import/export
    ghidra/scripts  Ghidra scripts (import setup, table application, export)
    ghidra/names    the naming tables: every name with its provenance
    docs/           PROVENANCE.md, STRUCTS.md

The tools read a legally obtained `sfiii2n.zip`; nothing taken from the ROM is in this repository.

## License

GNU Affero General Public License v3.0 (`LICENSE`), as the 3rd Strike decomp. `NOTICE.md` lists what the license
does not cover.
