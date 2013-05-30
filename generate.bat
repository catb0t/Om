@echo off
setlocal enableextensions

set argC=0
for %%x in (%*) do Set /A argC+=1
if not %argC% == 1 (
	echo Usage: %0 {CMake Generator}
	exit /b 1
)

set Directory=%CD%

if not exist "output\intermediate\%~1" mkdir "output\intermediate\%~1"
cd "output\intermediate\%~1"
cmake -G %* "%Directory%"
cd "%Directory%"