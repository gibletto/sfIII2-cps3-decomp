LIB\  the compiler's run-time routines, as linked into the program

These are Hitachi SHC's support routines, not game code: compiled C calls them for work the SH-2 has no
single instruction for.

  shclib.src        signed/unsigned division and remainder (__divls __divlu __divws __modls __modlu),
                    the block move for structure copies (__quick_mvn), the variable left shift (__sftl)
                    and abs()
  slow_mvn.src      byte-wise block move for structures that may be unaligned (__slow_mvn), byte-wise
                    string copy (__slow_strcpy) and variable logical right shift (__sftrl)
  sta_sftra.src     fixed arithmetic right shifts (_sta_sftra8 ... _sta_sftra12, _sta_sftra21)
  quick_strcpy.src  word-at-a-time string copy (_quick_strcpy)

They come from the compiler's library, not from the game's sources, but the link puts them between game
modules (see sf2i.sub), so they are kept as objects in that order rather than taken from a .lib at the end.
They are the routines as the ROM has them. The link has no __sftra (the library's variable arithmetic right
shift), and __quick_mvn's jump table points into its move run.
