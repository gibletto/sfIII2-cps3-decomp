STREET FIGHTER III 2nd IMPACT  -  GIANT ATTACK
CPS3 program ROM source

--------------------------------------------------------------------------
LAYOUT
--------------------------------------------------------------------------

  The tree follows the 3rd Strike one (gibletto/sfIII3-cps3-decomp; tools that read it take $SF3_TREE):

    src\        C and assembler modules (from the 3rd Strike tree where 2nd Impact has the same routines)
    lib\        the compiler's run-time routines, as linked into the program
    include\    headers (the 3rd Strike tree's)
    data\       hand-maintained tables (sections.src; a data unit's <unit>.c here replaces its generated file)
    data.tsv    the data layout: the data units (C files of typed tables) and their objects in CTBL, with
                names, types and provenance (tools\emit2i_data.py plan; no ROM bytes)
    bin\        the compiler: the 3rd Strike tree's bin\ (SHC 5.0 with the arcade rebuilt stages,
                asmsh, lnk, rof2bin), the rebuilt stages with the 2nd Impact settings added. 2nd Impact
                was built by a slightly different compiler revision, so tools\build2i.py turns some
                rebuilt-stage settings on (REVISION there; off, every setting gives the 3rd Strike compiler)
    units.txt   optimisation per C module (speed / nospeed / opt0 / speed_noinline ...)
    layout.tsv  every piece of the program image at its 2nd Impact address
    sf2i.sub    the link: section starts and the objects in link order
    layout\     the names the source objects define and refer to (defs.tsv, externs.tsv)
    functions.tsv  every routine: 2nd Impact address, size, name, file, kind

  layout.tsv, sf2i.sub and layout\ are written by tools\layout2i.py. Every routine is in src\ or lib\;
  what is left as a blob is data: the graphics, the vector table and a few initialised RAM blocks,
  build\blob\<name>.src, written at build time from the 2nd Impact image (the ROM set is never part of
  the tree), with a label for every name of the naming tables (ghidra\names).

  The tables of data.tsv are C: build\data\<unit>.c, written at build time from the 2nd Impact image by
  tools\emit2i_data.py (3rd Strike types and names, pointer words as symbols) and compiled like the
  modules. Like the blobs they are ROM content and never part of the tree.

  Sections (2nd Impact addresses):
    CVECT  06000000-060001FF  vector table
    P      06000400-060FC563  code
    CTBL   060FC564-0657732F  constant tables
    D      02000000-0200873B  initialised work RAM; its ROM copy at 06577330
    B      0200873C-02074109  work RAM cleared at boot
    CCDVOL 067FFFE0, CCG 06800000-06DA767B, CCDVOL2 06FFFFE0: SIMM headers and graphics

--------------------------------------------------------------------------
BUILDING
--------------------------------------------------------------------------

  From the project root (Python 3, Windows), with your sfiii2n.zip in rom\:

    build.bat                         (python tools\build_all.py) the whole build from the ROM set:
                                      extract, si2map (seeded by functions.tsv), build2i --all --pack;
                                      writes build\prog.bin and build\sfiii2n.zip and checks the SHA-1

  The steps on their own (the 2nd Impact image in build\si2map\prog.bin, si2map's hmap.bin beside it):

    python tools\build2i.py --rom build\si2map --map build\si2map
                                      data units and blobs, compile, link, rof2bin -v=FF, compare
    python tools\build2i.py ... --pack rom\sfiii2n.zip
                                      and encrypt the program into the ROM set (build\rom\sfiii2n.zip)
    python tools\status2i.py          per-function match status (build\status.tsv)
    python tools\functions2i.py       functions.tsv from that status
    python tools\layout2i.py          after a module's sections change (needs a built 3rd Strike tree,
                                      $SF3_TREE); also writes layout\defs.tsv and layout\externs.tsv,
                                      which the build uses when layout2i has not run

  The build must leave prog.bin byte-identical to the 2nd Impact image. Every routine is source
  (functions.tsv: 7,902 C, 37 assembler, 66 library, 178 second entries); the data tables, the graphics,
  the vector table and a few initialised RAM blocks are written from the ROM at build time.
