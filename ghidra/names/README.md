# Naming tables

The only source of 2nd Impact names: functions.tsv, globals.tsv, entries.tsv, types.h, enums.tsv, locals.tsv.
Each row carries its provenance class and 3rd Strike reference; columns, classes and rules are in
`docs/PROVENANCE.md`. `tools/ghidra-export.sh` applies them in a read-only session
(`ghidra/scripts/ApplyTables.java`); `tools/check-tables.py` checks them; `tools/seed-tables.py` adds rows from the
3s matches without changing existing ones.
