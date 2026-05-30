# The cursing Lemon Tree
A ESP32 based project that remindes you when to water your plants.

## Overview
Whenever someone walks near the plant, a motion sensor triggers the system. The ESP32 then checks the soil moisture level using a dedicated sensor. If the plant is too dry, the system plays an audio file (typically a "friendly" reminder or a "curse") to get someone to water it.

## Why
Keeping track of plant hydration can be challenging. This system provides an interactive and humorous way to get reminde to water the plants

## Hardware Requirements

- ESP32 (in my case a Wemos d1 mini32)
- Motion Sensor
- Soil Moisture Sensor
- DFPlayer Mini with Micro-SD Card
- Small Speaker


## Installation and Usage

1. **Hardware Setup:**
   - Connect the sensors and the DFPlayer to the ESP32 according to the pin definitions in the source code.
   - Place the moisture sensor into the soil of the plant you wish to monitor.

2. **SD Card Preparation:**
   - Format your Micro-SD card to FAT16 or FAT32.
   - Create a folder (or root directory) and add at least 5 MP3 files.
   - Name the files `0001.mp3`, `0002.mp3`, `0003.mp3`, `0004.mp3`, and `0005.mp3`.
   - *Note:* If you add more tracks, remember to update the `random(1, 5)` range in `main.cpp` accordingly.

3. **Software:**
   - Flash the provided code onto your ESP32 using PlatformIO or the Arduino IDE.

4. **Deployment:**
   - Assemble everything into a case and place it next to your plant.
   - The system will enter Deep Sleep to save battery and only wake up when motion is detected.

Enjoy your talkative plants, and hopefully, you'll never forget to water them again! :)
