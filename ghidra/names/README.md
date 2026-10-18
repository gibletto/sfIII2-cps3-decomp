# Naming tables

The only source of 2nd Impact names: functions.tsv, globals.tsv, aliases.tsv, entries.tsv, types.h, enums.tsv,
locals.tsv. aliases.tsv holds second names of an address that already has a functions or globals row (the SHC
run-time library's _x/__x pairs, two table symbols at one address); they become secondary labels, never renames.
Each row carries its provenance class and 3rd Strike reference; columns, classes and rules are in
`docs/PROVENANCE.md`. `tools/ghidra-export.sh` applies them in a read-only session
(`ghidra/scripts/ApplyTables.java`); `tools/check-tables.py` checks them; `tools/seed-tables.py` adds rows from the
3s matches without changing existing ones.
