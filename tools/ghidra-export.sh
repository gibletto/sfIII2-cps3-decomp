#!/bin/sh
# Export the 2nd Impact program from the Ghidra project in a read-only session: the project is never changed, and
# every name, type and provenance note the export shows is applied from the tables in that session
# (ghidra/scripts/ApplyTables.java; docs/PROVENANCE.md). Writes under scratch/si2ghidra/<out> (default export):
#   boundaries.tsv     every function: entry, end, body, ranges, instructions, name, prov (ExportBoundaries.java)
#   decomp/, functions.tsv, variables.tsv, globals.tsv, symbols.tsv, datatypes.txt   (ExportFullDecomp.java)
#   global_types.tsv   with --types: each global's decompiler type per function (ExportGlobalTypes.java)
# Usage: tools/ghidra-export.sh [--boundaries] [--types] [<out>]
#   --boundaries: boundaries.tsv only (no decompilation)
# GHIDRA_HOME (required: a Ghidra 12 install); NAMES_DIR: another tables directory to try (default ghidra/names).
set -e
cd "$(dirname "$0")/.."
B=; T=
while [ $# -gt 0 ]; do
  case $1 in
    --boundaries) B=1; shift ;;
    --types) T=1; shift ;;
    *) break ;;
  esac
done
OUT=scratch/si2ghidra/${1:-export}
GH=${GHIDRA_HOME:?set GHIDRA_HOME to a Ghidra 12 install}
export JAVA_HOME=${SI2_JAVA_HOME:-$JAVA_HOME}
w() { cygpath -w "$1"; }
P=ghidra/project
N=${NAMES_DIR:-ghidra/names}
[ -f $P/sfiii2.gpr ] || { echo "no project: run tools/ghidra-import.sh first"; exit 2; }
rm -rf $OUT
mkdir -p $OUT
S="-postScript ExportBoundaries.java $(w $OUT/boundaries.tsv)"
[ -n "$B" ] || S="$S -postScript ExportFullDecomp.java $(w $OUT)"
[ -n "$T" ] && S="$S -postScript ExportGlobalTypes.java $(w $OUT/global_types.tsv)"
cmd.exe //c "$(w "$GH/support/analyzeHeadless.bat") $(w $P) sfiii2 -process -noanalysis -readOnly \
  -scriptPath $(w ghidra/scripts) -postScript ApplyTables.java $(w "$N") $S" < /dev/null > $OUT/export.log 2>&1
grep -q "ApplyTables: done" $OUT/export.log || { grep "ApplyTables" $OUT/export.log | head -20; echo "tables not applied, see $OUT/export.log"; exit 1; }
grep "ApplyTables:" $OUT/export.log | sed 's/.*ApplyTables: /  /; s/ (GhidraScript).*//'
echo "$(($(wc -l < $OUT/boundaries.tsv) - 1)) functions -> $OUT"
