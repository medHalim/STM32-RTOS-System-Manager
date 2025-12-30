@echo off
echo =====================================
echo  STM32 DFU Flash Script (Windows)
echo =====================================

REM --- Full path to STM32CubeProgrammer CLI (NO quotes here) ---
set STM32_CLI=C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin\STM32_Programmer_CLI.exe

REM --- Find the first .bin file in build folder ---
set BIN_FILE=
for %%f in ("%CD%\build\*.bin") do (
    set BIN_FILE=%%f
    goto :FOUND
)
:FOUND

if not defined BIN_FILE (
    echo ERROR: No .bin file found in build\
    echo Run: make all
    pause
    exit /b
)

echo Using binary: "%BIN_FILE%"
echo.

REM --- List DFU devices for verification ---
echo Listing available DFU devices...
"%STM32_CLI%" -l
echo.

REM --- Flash using USB1 (first DFU device) ---
echo Flashing to USB1 (make sure BOOT0 = 1)...
"%STM32_CLI%" -c USB1 -w "%BIN_FILE%" 0x08000000 -v

REM --- Check result ---
if %ERRORLEVEL% NEQ 0 (
    echo Flash FAILED!
    pause
    exit /b
)

echo Flash SUCCESS!
echo Remove BOOT0 jumper and press RESET to run your program.
pause
