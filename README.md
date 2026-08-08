# Smart Obstacle Detection System

## Project Description

The Smart Obstacle Detection System is an ESP32-based embedded system designed to detect obstacles from the left, front, and right sides using ultrasonic sensors.

The system continuously measures the distance between the sensors and nearby obstacles. When an obstacle is detected within a predefined distance, the system provides an alert using LEDs and a buzzer. Different LEDs indicate the direction of the detected obstacle, helping the user identify where the obstacle is located.

The project is developed and simulated using Wokwi and ESP32.

## Hardware Used

- ESP32
- 3 Ultrasonic Sensors
- Red LED
- Green LED
- Blue LED
- Buzzer
- Connecting wires

## Software / Tools

- Arduino IDE
- Wokwi Simulator
- Embedded C / Arduino C++

## Working

1. The three ultrasonic sensors measure the distance to obstacles.
2. The ESP32 receives the distance values from the sensors.
3. The measured distances are compared with a predefined threshold.
4. If an obstacle is detected, the corresponding LED is turned ON.
5. The buzzer provides an audible warning.
6. If no obstacle is detected, the system remains in the normal state.

## Applications

- Vehicle obstacle detection
- Robotics
- Smart navigation systems
- Autonomous vehicles
- Parking assistance systems
- Indoor obstacle detection

## Project Simulation

The project was simulated using Wokwi with an ESP32 microcontroller.
