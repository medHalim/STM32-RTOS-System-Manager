#!/bin/bash
echo "======================================="
echo " STM32 DFU Flash Script (Linux / WSL)"
echo "======================================="

# --- Path to Windows STM32CubeProgrammer CLI ---
STM32_CLI="/mnt/c/Program Files/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin/STM32_Programmer_CLI.exe"

# --- Check OS environment ---
if [[ "$(uname -a)" == *Microsoft* ]]; then
    echo "Running in WSL. NOTE: USB DFU devices may not be accessible!"
fi

# --- Find first .bin in build/ ---
BIN_FILE=$(find build/ -name "*.bin" | head -n1)
if [ -z "$BIN_FILE" ]; then
    echo "ERROR: No .bin found in build/"
    exit 1
fi

echo "Binary to flash: $BIN_FILE"

# --- List DFU devices ---
"$STM32_CLI" -l

echo
echo "Using DFU port: USB1 (adjust if multiple devices)"
echo "Make sure BOOT0 = 1 (DFU mode) and USB connected"
echo

"$STM32_CLI" -c USB1 -w "$BIN_FILE" 0x08000000 -v

if [ $? -ne 0 ]; then
    echo "Flash FAILED!"
    exit 1
fi

echo "Flash SUCCESS! Remove BOOT0 jumper and press RESET."
