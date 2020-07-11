#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

# Define cores and platforms
CORES=(arduino:avr arduino:samd esp8266:esp8266)
PLATFORMS=(arduino:avr:uno arduino:samd:arduino_zero_native esp8266:esp8266:nodemcu)

# Define additional URLs for arduino-cli
ADDITIONAL_URLS=http://arduino.esp8266.com/stable/package_esp8266com_index.json

# Define colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'

# Create directories
mkdir $HOME/Arduino
mkdir $HOME/Arduino/libraries

# Install arduino IDE
echo -e "\n########################################################################";
echo -e "${YELLOW}INSTALLING ARDUINO CLI"
echo "########################################################################";
export PATH=$PATH:$GITHUB_WORKSPACE/bin
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
arduino-cli config init
arduino-cli core update-index --additional-urls "${ADDITIONAL_URLS}"

# Install arduino cores
for c in ${CORES[*]} ; do
    echo -e "\n########################################################################";
    echo -e "${YELLOW}INSTALLING ARDUINO CORE: ${c}"
    echo "########################################################################";
    arduino-cli core install $c --additional-urls "${ADDITIONAL_URLS}"
    if [ $? -ne 0 ]; then echo -e "${RED}\xe2\x9c\x96"; else echo -e "${GREEN}\xe2\x9c\x93"; fi
done

# Link arduino library
ln -s $GITHUB_WORKSPACE $HOME/Arduino/libraries/CI_Test_Library

# Build example sketches
for p in ${PLATFORMS[*]} ; do
    for d in examples/* ; do
        echo -e "\n########################################################################";
        echo -e "${YELLOW}BUILD ${d} FOR ${p}"
        echo "########################################################################";
        arduino-cli compile -b $p $d
        if [ $? -ne 0 ]; then echo -e "${RED}\xe2\x9c\x96"; else echo -e "${GREEN}\xe2\x9c\x93"; fi
    done
done
