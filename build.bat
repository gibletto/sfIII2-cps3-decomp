@echo off
setlocal
pushd "%~dp0"
rem STREET FIGHTER III 2nd IMPACT -- program ROM
rem Hitachi SHC 5.0 (rebuilt stages), asmsh, lnk 6.0; SEGA rof2bin
python tools\build_all.py %*
set RC=%ERRORLEVEL%
popd
exit /b %RC%
