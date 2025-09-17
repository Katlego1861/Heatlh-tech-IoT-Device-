# Heatlh-tech-IoT-Device-Project3-KL

Health IoT Device – Pulse Wave Project
Overview

This repository contains the design, code, and documentation for a Health IoT device that monitors pulse and temperature, sends data to the cloud, and enables visualization through ThingSpeak and MIT App Inventor.

The project integrates hardware, IoT connectivity, and app development to create a portable health monitoring solution.

Repository Contents
File / Folder	Description
3D casing.zip	3D casing design files for the device (all angles)
Bill of Material - Sheet1.csv	Complete Bill of Materials (components list)
Copy of Pulse wave Flowchart.drawio.png	Flowchart showing the IoT data flow from sensors to app
Pulse Wave.drawio	Schematic diagram of the hardware connections
Pulse_Wave_code.ino	Arduino/ESP32 source code for the IoT device
README.md	Project overview and documentation (this file)
Features

Heart rate measurement using a pulse sensor

Temperature measurement using MLX90614 sensor

Live data display on LCD

IoT connectivity via ESP32 to ThingSpeak

Cloud data retrieval and visualization in MIT App Inventor

Getting Started
Requirements

ESP32 (C3 SuperMini or equivalent)

Pulse Sensor

MLX90614 Temperature Sensor

I2C LCD Display

LiPo Battery and Charger Module

Arduino IDE with the following libraries:

PulseSensor Playground

ThingSpeak

DFRobot_MLX90614

Wire

Setup

Clone this repository:

git clone https://github.com/yourusername/Health-IoT-Device.git


Open Pulse_Wave_code.ino in Arduino IDE.

Install required libraries.

Update WiFi credentials and ThingSpeak API key in the code.

Upload the code to the ESP32.

Documentation
Flowchart

The following flowchart explains how data moves from the sensors through the ESP32, into ThingSpeak, and finally into the MIT App Inventor application:

Schematic

The schematic shows the wiring and hardware connections for the pulse sensor, temperature sensor, LCD, and ESP32:

3D Design

See 3D casing.zip for all casing design files (exported views and CAD).

Bill of Materials

See Bill of Material - Sheet1.csv for the full list of components.

Future Work

Add SpO2 sensor for oxygen level monitoring

Develop a dedicated mobile app (beyond MIT App Inventor)

Optimize power consumption for longer battery life

License

This project is licensed under the MIT License.
