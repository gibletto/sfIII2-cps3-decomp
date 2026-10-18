STREET FIGHTER III 2nd IMPACT  -  GIANT ATTACK
CPS3 program ROM source (work in progress)

--------------------------------------------------------------------------
LAYOUT
--------------------------------------------------------------------------

  The tree follows the 3rd Strike one (gibletto/sfIII3-cps3-decomp; tools that read it take $SF3_TREE):

    src\        C and assembler modules (from the 3rd Strike tree where 2nd Impact has the same routines)
    lib\        the compiler's run-time routines, as linked into the program
    include\    headers (the 3rd Strike tree's)
    data\       typed tables (none yet)
    bin\        the compiler: the 3rd Strike tree's bin\ (SHC 5.0 with the arcade rebuilt stages,
                asmsh, lnk, rof2bin), unchanged
    units.txt   optimisation per C module (speed / nospeed / opt0 / speed_noinline ...)
    layout.tsv  every piece of the program image at its 2nd Impact address
    sf2i.sub    the link: section starts and the objects in link order

  Both layout.tsv and sf2i.sub are written by tools\layout2i.py. Everything not yet in src\ or lib\ is a
  blob: build\blob\<name>.src, written at build time from the 2nd Impact image (the ROM set is never
  part of the tree), with a label for every name of the naming tables (ghidra\names). A module that comes
  in as source replaces its blob, so the image is the 2nd Impact program at every step.

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

  From the project root (Python 3, Windows; the 2nd Impact image in scratch\rom\prog.bin and si2map's
  hmap.bin in scratch\si2map, see ..\README.md):

    python tools\layout2i.py          after a module comes in as source (places its sections, writes the
                                      link and the names its code needs that the tables lack)
    python tools\build2i.py           blobs, compile, link, rof2bin -v=FF, compare with 2nd Impact
    python tools\build2i.py --pack <sfiii2n.zip>
                                      and encrypt the program into the ROM set (build\rom\sfiii2n.zip)
    python tools\status2i.py          per-function match status (build\status.tsv)
    python tools\import2i.py <module> bring a 3rd Strike module in (then layout2i)

  The build must leave prog.bin byte-identical to the 2nd Impact image.
