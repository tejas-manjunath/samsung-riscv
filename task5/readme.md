#  Traffic Control System with Emergency Button using RISC V processor

## Overview:
This project is a simple traffic control system using a RISC-V processor to simulate a traffic light. The system will control three LEDs (Red, Yellow, Green) to represent traffic lights and provide manual control through push buttons for pedestrian crossing and emergency override. Optionally, a buzzer alerts users during an emergency override.

## Features:
* Automatic traffic light control (Red, Yellow, Green) using LEDs.
* Manual control with push buttons for pedestrian crossing and emergency override.
* Optional buzzer to signal emergency override.
* Simple code logic for controlling the traffic lights and handling user input.

## Components Required:
* RISC-V Processor 
* LEDs (Red, Yellow, Green)
* Push Buttons (Pedestrian crossing, Emergency override)
* Resistors (220Ω for LEDs, 10kΩ pull-down for buttons)
* Buzzer
* Breadboard and jumper wires
* External power supply (3.3V)

## Process of Implementation:

**1. Set Up the Components:**
* Connect the LEDs to GPIO pins (D2 for Red, D3 for Yellow, D4 for Green) with appropriate resistors.
* Connect the buttons to GPIO pins (D5 for Pedestrian, D6 for Emergency) with pull-down resistors.

**2.Configure the GPIO Pins:**
* Configure the LED pins as OUTPUT and button pins as INPUT_PULLUP in the RISC-V processor.

**3.Implement the Traffic Light Logic:**
* Write code to control the LEDs in a timed sequence (Green, Yellow, Red) to simulate traffic light behavior.

**4.Add Manual Override Functionality:**
* Implement code to detect button presses for pedestrian crossing and emergency override. Button 1 (Pedestrian) forces Red, and Button 2 (Emergency) turns on the buzzer and overrides the system.

**5.Test and Debug:**
* Test the system for correct behavior, ensuring the LEDs switch at the right times, and buttons trigger the intended actions (e.g., pedestrian crossing or emergency).
