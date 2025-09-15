# Heatlh-tech-IoT-Device-Project3-KL

Overview

This project is a Health Monitoring IoT Device designed to collect, process, and display vital health data in real time. The device integrates multiple sensors and IoT capabilities to make health monitoring more accessible and efficient.

Features

Pulse Sensor – Monitors heart rate and sends readings to the system.

Temperature Sensor (MLX90614) – Measures body temperature accurately.

LCD Display – Displays live sensor data for quick reference.

WiFi Connectivity (ESP32) – Sends data to ThingSpeak/cloud for storage and analysis.

Portable Power – Can run on a rechargeable LiPo battery.

Components Used

ESP32 (C3 SuperMini)

Pulse Sensor

DFRobot MLX90614 (Infrared temperature sensor)

I2C LCD Display

LiPo Battery + Charger module

Push Button + basic circuit elements (resistors, wires, etc.)

Setup & Installation

Clone the repository

git clone https://github.com/yourusername/Health-IoT-Device.git


Install Arduino libraries

PulseSensor Playground

ThingSpeak

DFRobot_MLX90614

Wire

Open the code in Arduino IDE / PlatformIO

Select ESP32 Board

Connect your ESP32 and upload the code

Configure WiFi & ThingSpeak

Update ssid, password, and ThingSpeak API_KEY in the code

Run the device

Power on the device

Read live data on the LCD and monitor cloud updates on ThingSpeak

Data Visualization

All collected data can be viewed on the ThingSpeak dashboard with real-time graphs for:

Heart Rate (BPM)

Body Temperature (°C)

Prototype

(Insert images of your IoT box, wiring, and LCD output here)

Future Improvements

Adding SpO2 (Oxygen Level) sensor

Mobile app integration for easier access

Better power optimization for longer battery life

Contributing
