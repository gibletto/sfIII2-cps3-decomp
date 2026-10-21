# Street Fighter III 2nd Impact - CPS3 program source

**AI Disclosure**: this project uses Claude, as the 3rd Strike decomp did.

C and SH-2 assembler source for the CPS3 program ROM of *Street Fighter III 2nd Impact: Giant Attack* (sfiii2n),
built with the original Hitachi toolchain (SHC 5.0, asmsh, lnk 6.0, rof2bin). It is the earlier game on the engine of
[Street Fighter III 3rd Strike](https://github.com/gibletto/sfIII3-cps3-decomp), and the finished 3rd Strike decomp
was its oracle: no debug symbols exist for 2nd Impact, so names and types come from 3rd Strike, with the evidence for
each one recorded (`docs/PROVENANCE.md`, `docs/STRUCTS.md`).

The build is a byte-for-byte copy of the arcade program: every routine (7,902 C routines, 37 assembler, 66 from the
compiler's library) compiles from this source to the arcade's exact bytes. `build/prog.bin` has the arcade program's
SHA-1, 234c5afdefb008d0feba0b7b9b448082e71499b6, and the eight program SIMM chips written into `build/sfiii2n.zip`
are the original ROM's:

    sfiii2-simm1.0  crc 2d666f0b  sha1 68de034b3a3aeaf4b26122a84ad48b0b763e4122
    sfiii2-simm1.1  crc 2a3a8ef6  sha1 31fb58fd1360ed8c951e2c4ac898a5a7104528d6
    sfiii2-simm1.2  crc 161d2206  sha1 58999f876e64c1a088e8765962a9cd504f22a706
    sfiii2-simm1.3  crc 87ded8a3  sha1 4ccef64f80d2ee63940b0958b500364ee515db51
    sfiii2-simm2.0  crc 94a4ce0f  sha1 2c8e26a66d1dcd17c22c70baa2a3ff5a54511514
    sfiii2-simm2.1  crc 67585033  sha1 24df9968a54c330fbe95f8e4dfe6e7dfd144ed0c
    sfiii2-simm2.2  crc fabffcd5  sha1 9399f64c42f63a64e44a21a2690e44779943a2b2
    sfiii2-simm2.3  crc 623c09ca  sha1 dc9618a08bb7f44e569ac17605d268511155a14e

## Building

Needs Windows (the tools in `sf2i/bin/` are Win32 programs) and Python 3.

1. Put your `sfiii2n.zip` in `rom/`.
2. Run `build.bat` (or `python tools/build_all.py`).

The build reads the program SIMMs of your ROM set, compiles and links the program, and writes:

- `build/prog.bin` - the program image, 06000000-06FFFFFF
- `build/sfiii2n.zip` - your ROM set with the two program SIMMs rebuilt

It prints whether `build/prog.bin` has the SHA-1 in `tools/prog.sha1` and whether the rebuilt SIMMs equal yours.

No ROM bytes are in this repository. The data tables are described in `sf2i/data.tsv` (every object's address, name,
type and provenance) and written as C from your ROM at build time (`tools/emit2i_data.py`); the graphics, the
vector table and a few initialised RAM blocks are copied from it the same way.

When running a new build in MAME, use an empty `-nvram_directory`: MAME keeps the program SIMMs' flash in nvram and
loads it over the ROM files.

## Layout

    sf2i/src/        game code (C, and SH-2 assembler in .src files)
    sf2i/include/    headers; sf2i/include/structs.h has 2nd Impact's own structure layouts
    sf2i/lib/        the compiler's run-time routines, as linked into the program
    sf2i/bin/        the Hitachi SHC toolchain with the rebuilt compiler stages
    sf2i/data.tsv    the data tables (generated as C from your ROM)
    sf2i/sf2i.sub    link order and section addresses; sf2i/layout.tsv every piece of the image
    sf2i/functions.tsv  every routine of the arcade program: address, size, name, file
    tools/           the build (build_all.py, build2i.py), the ROM reader (cps3rom2.py: 2nd Impact keeps its
                     instructions encrypted and its data plain, per halfword; si2map.py tells them apart),
                     status, and the tools that mapped 2nd Impact against 3rd Strike
    ghidra/          Ghidra scripts and the naming tables (every name with its provenance)
    docs/            PROVENANCE.md, STRUCTS.md

## Compiler

2nd Impact was built with the same arcade compiler as 3rd Strike: [SHC 5.0 Release 26 rebuilt in
C](https://github.com/gibletto/shc-5r26-decomp-sf3), with its rules for the arcade's code generation. It was a
slightly different revision, so `tools/build2i.py` turns on sixteen further settings of the rebuilt stages
(`REVISION` there, plus one per-module option); with all of them off the stages are the 3rd Strike compiler. As with
3rd Strike, none tests for a function's name or address, but several have been seen in only one routine so far and
rest on that single example. The 2nd Impact settings are in the published compiler source, each with the routine
that shows it (`SF3.md` there, "Another compiler revision").

## Contributing

This is an exact byte match, so contributions should keep the match while improving or explaining the code, or
replace a compiler setting with source that produces the same bytes. Matching forms that look like levers rather
than 1996 source (dead reads, `if (0)` blocks, odd spellings) are the first candidates for that.

## Thanks

To the 3sx Team and Artem for the 3s-decomp, and to DrewDos for his matching work, both of which reach this tree
through the 3rd Strike decomp.

## License

GNU Affero General Public License v3.0 (`LICENSE`), as the 3rd Strike decomp. `NOTICE.md` lists what the license
does not cover.
