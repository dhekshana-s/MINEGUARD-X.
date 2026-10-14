# MINEGUARD-X — ESP32-Based Mine Safety Prototype

## Overview

MINEGUARD-X is a student project developed for an internal Smart India Hackathon (SIH) round. The prototype explores the use of an ESP32 microcontroller, ultrasonic sensing, and alert and motor-control hardware in a mine-safety-related application.

The implemented prototype uses an ultrasonic sensor to detect nearby obstacles or objects and uses output devices to provide alerts or demonstrate motor control, according to the uploaded hardware and program.

This repository documents the implemented prototype. It does not represent a certified mine-safety system.

## Features

- ESP32-based embedded control
- Ultrasonic distance sensing
- Buzzer-based alert output
- Motor control using a motor-driver module
- Integration of sensors and output devices

Only retain features that match the actual hardware and code.

## Hardware Components

- ESP32 development board
- Ultrasonic sensor
- Buzzer
- Motor-driver module
- DC motor(s)
- Connecting wires and supporting hardware

Add exact component or module names when confirmed from your project records.

## Hardware Connections

The ultrasonic sensor interfaces with the ESP32 to provide distance measurements. The buzzer and motor-driver module are connected to the ESP32's output pins to control alerts and motor operation.

### Pin Connections

| Component | Signal | ESP32 Pin |
|---|---|---|
| Ultrasonic sensor | TRIG | 18 |
| Ultrasonic sensor | ECHO | 19 |
| Buzzer | Signal | 32 |
| Motor driver | IN1 | 26 |
| Motor driver | IN2 | 27 |


## Working Principle

1. The ultrasonic sensor measures the distance to an object by transmitting an ultrasonic pulse and detecting its echo.
2. The ESP32 reads and processes the sensor measurement.
3. The program checks the measured distance against its configured conditions, if implemented.
4. The buzzer and motor-driver outputs respond according to the program logic.

The exact alert conditions and motor behaviour depend on the implemented code.

## Software and Tools

- Arduino IDE
- Arduino C/C++ programming
- ESP32 development environment

## Limitations

- Ultrasonic measurements can be affected by object shape, surface properties, alignment, and environmental conditions.
- Motor and buzzer behaviour depends on the implemented control logic and hardware configuration.
- The prototype has not been established as a certified or fail-safe mine-safety system.
- Further testing, fault handling, and validation would be required before any real-world safety application.

## Future Improvements

- Improve sensor reliability and fault handling.
- Add structured testing and documented performance measurements.
- Improve the alert logic and user feedback.
- Evaluate additional sensing methods if required by the project design.

## Repository Contents

- `MINEGUARD-X.ino` — Arduino program for the prototype.
- `README.md` — Project overview, connections, working principle, and documentation.

## Project Context

Developed as a student prototype for an internal SIH round. The documentation describes the implemented work rather than implying that the project was selected for the national finale or deployed in a real mine.
