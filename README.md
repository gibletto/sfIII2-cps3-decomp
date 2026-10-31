# Street Fighter III 2nd Impact - CPS3 program source

**AI Disclosure**:
Yes, this used Claude, as the 3rd Strike decomp did. 2nd Impact has no debug symbols of its own: the finished
[3rd Strike decomp](https://github.com/gibletto/sfIII3-cps3-decomp) was the reference for its layout and names, and
the names of the files here follow Capcom's 3rd Strike file names (2nd Impact's own modules are named in the same
style).

## What this is

This is the program of the arcade game *Street Fighter III 2nd Impact: Giant Attack* (sfiii2n), turned back into
source code. It is a decompilation: the machine code in the CPS3 program ROM has been rewritten as C and as SH-2
assembler (the SH-2 is the arcade board's CPU), so people can read it and change it. 2nd Impact is the game before
3rd Strike, on the same engine; where the two differ, the comments in the code say so.

It is also a byte-for-byte match. It builds with the original Hitachi toolchain (SHC 5.0, asmsh, lnk 6.0, rof2bin):
the compiler turns the C into machine code, the assembler does the same for the assembler files, and the linker
joins the pieces into one program. Every routine comes out as the arcade's exact bytes. `build/prog.bin` has the
arcade program's SHA-1 (a fingerprint of the whole file), 234c5afdefb008d0feba0b7b9b448082e71499b6, and the eight
program SIMM chips written into `build/sfiii2n.zip` are the original ROM's:

    sfiii2-simm1.0  crc 2d666f0b  sha1 68de034b3a3aeaf4b26122a84ad48b0b763e4122
    sfiii2-simm1.1  crc 2a3a8ef6  sha1 31fb58fd1360ed8c951e2c4ac898a5a7104528d6
    sfiii2-simm1.2  crc 161d2206  sha1 58999f876e64c1a088e8765962a9cd504f22a706
    sfiii2-simm1.3  crc 87ded8a3  sha1 4ccef64f80d2ee63940b0958b500364ee515db51
    sfiii2-simm2.0  crc 94a4ce0f  sha1 2c8e26a66d1dcd17c22c70baa2a3ff5a54511514
    sfiii2-simm2.1  crc 67585033  sha1 24df9968a54c330fbe95f8e4dfe6e7dfd144ed0c
    sfiii2-simm2.2  crc fabffcd5  sha1 9399f64c42f63a64e44a21a2690e44779943a2b2
    sfiii2-simm2.3  crc 623c09ca  sha1 dc9618a08bb7f44e569ac17605d268511155a14e

## Building

You need Windows (the tools in `bin/` are Win32 programs), Python 3 and your own ROM set.

1. Put your `sfiii2n.zip` in `rom/`.
2. Run `build.bat` (or `make`).

The graphics pattern tables are not in this source, so the build reads them from your ROM. Then it compiles and
links the program, and writes:

- `build/prog.bin` - the program image, 06000000-06FFFFFF
- `build/sfiii2n.zip` - your ROM set with the two program SIMMs (the eight chips above) replaced

The build checks `build/prog.bin` against the SHA-1 in `tools/prog.sha1` (the arcade program's), and checks each
rebuilt program chip against yours. If any differs, it still writes both files, then stops with BUILD FAILED
(`make` fails too).

On the 2nd Impact ROM, instructions are stored encrypted and data is stored plain, chosen for each halfword (2
bytes). So the packing has to know which halfwords are instructions. It works this out by following the code of the
built program (`tools/codemap.py`), so a program you have changed is packed correctly too.

To run a new build in MAME, use an empty `-nvram_directory`. MAME keeps the program SIMMs' flash memory in nvram
and loads it over the ROM files, so an old nvram would run the old program instead of your build.

## Layout

    src/      game code (C, and SH-2 assembler in .src files), and the work RAM the modules share (*_work.c)
    data/     game tables, the vector table, the CD volume identifiers, and the graphics' labels
              (cg_labels.src: names and sizes only; the bytes come from the ROM)
    include/  headers
    lib/      the compiler's run-time routines (its built-in helpers), as linked into the program
    bin/      Hitachi SHC toolchain: shcmdl, shcgen, shcpep and shcasm are the rebuilt stages (see Compiler; the
              originals are in bin/original)
    sf2i.sub  link order and section addresses
    functions.tsv  every routine of the arcade program: arcade address, size, name, file
    tools/    cps3rom2.py: reads the ROM set, writes the new one (codemap.py, sh2.py: its code walk)

Work RAM is the memory where the game keeps its variables while it runs.

How the data files are named: a data file holds the tables of the 3rd Strike file of that name. A `_b` or `_c`
suffix means a further object of tables from that file, linked elsewhere. Where no 3rd Strike file fits, the file is
named after the module that reads its tables (`<module>_tbl`).

## Compiler

2nd Impact was built with the same arcade compiler as 3rd Strike, [SHC 5.0 Release 26, decompiled and rebuilt in
C](https://github.com/gibletto/shc-5r26-decomp-sf3), in a slightly different revision. (The 3rd Strike README
explains why the compiler had to be rebuilt to get a byte match.)

- The rebuilt stages in `bin/` carry the rules found for 3rd Strike.
- `build.bat` and the `Makefile` set sixteen further settings at the top for the revision that built 2nd Impact,
  and `GEN_NARROW_CONST=0` for the `-optimize=0` modules (the ones compiled without optimization).
- The compiler project's [SF3.md](https://github.com/gibletto/shc-5r26-decomp-sf3/blob/main/SF3.md) lists each
  setting with the routine that shows it.

None of them tests for a function's name or address, but several have been seen in only one routine so far and
rest on that single example. As for 3rd Strike, a source form found later could make some of them unnecessary.

With them, all 7,913 C routines (and the 37 assembler and 19 run-time routines) compile to the arcade's exact bytes,
and the linked `build/prog.bin` has the arcade program's SHA-1.

## Contributing

As this is an exact byte-match, every contribution must keep the match. Contributions should either:

- improve or explain the code, or
- replace a compiler setting with source that produces the same bytes (with a PR to the compiler decomp project
  too).

The first candidates are matching forms that look like workarounds rather than original source: source that builds
the right bytes but is unlikely to be what Capcom wrote (dead reads, `if (0)` blocks, odd spellings).

## Thanks

Thanks to the 3sx Team and Artem for the 3s-decomp, which helped recover a large amount of the 3rd Strike code style
this tree builds on, and to DrewDos for his matching work and help.

Thanks also to Dominic Evans (X: [@oldmanuk](https://x.com/oldmanuk)) for clean-up suggestions.

## License

GNU Affero General Public License v3.0 (`LICENSE`): parts of the source come from the 3rd Strike decomp and through it
from the 3s-decomp, which is AGPL-3.0. `NOTICE.md` lists what the license does not cover.
