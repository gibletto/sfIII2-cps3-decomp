#!/bin/sh
# Create the headless Ghidra project for the 2nd Impact program: import the image at 06000000 as SH-2 big-endian,
# set up the address map and seeds (ghidra/scripts/SetupCps3.java with ghidra/names/entries.tsv), run the default
# auto-analysis. The project is generated: ghidra/project/ is ignored, never edited, and rebuilt by this script.
# Names are not applied here; tools/ghidra-export.sh applies the tables in each read-only session.
# Usage: tools/ghidra-import.sh <image> [<data view>]
#   <image>: scratch/rom/prog.bin (the merged program), or scratch/rom/prog_op.bin with <data view>
#   scratch/rom/prog_data.bin (the exception table is then copied from the data view)
# GHIDRA_HOME (required: a Ghidra 12 install); JAVA_HOME must be a JDK 21.
set -e
cd "$(dirname "$0")/.."
IMG=$1
[ -f "$IMG" ] || { echo "usage: $0 <image> [<data view>]"; exit 2; }
GH=${GHIDRA_HOME:?set GHIDRA_HOME to a Ghidra 12 install}
export JAVA_HOME=${SI2_JAVA_HOME:-$JAVA_HOME}
w() { cygpath -w "$1"; }
P=ghidra/project
LOG=scratch/si2ghidra/import.log
mkdir -p $P scratch/si2ghidra
NAME=$(basename "$IMG")
rm -rf "$P/sfiii2.gpr" "$P/sfiii2.rep"
DATA=
[ -n "$2" ] && DATA=$(w "$2")
cmd.exe //c "$(w "$GH/support/analyzeHeadless.bat") $(w $P) sfiii2 -import $(w "$IMG") -loader BinaryLoader \
  -loader-baseAddr 0x06000000 -processor SuperH:BE:32:SH-2 -cspec default -scriptPath $(w ghidra/scripts) \
  -preScript SetupCps3.java $(w ghidra/names) $DATA -analysisTimeoutPerFile 7200" < /dev/null > $LOG 2>&1
grep -q "SetupCps3:" $LOG || { echo "import failed, see $LOG"; exit 1; }
grep "SetupCps3:" $LOG
echo "imported $NAME into $P/sfiii2.gpr (log $LOG)"
