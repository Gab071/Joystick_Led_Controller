# Joystick Led Controller 

## Table of Contents

1. [Overview](#overview)
2. [LED Color Reference](#led-color-reference)
3. [Hardware Components](#hardware-components)
4. [Pin mapping](#pin-mapping)
5. [How to Run](#how-to-run)

## Overview

This is a project that uses Arduino programmed in C++ (via Arduino IDE) language to allow a Joystick module to control LEDs. In more detail:

- There is a dead zone (joystick's "resting position") when all LEDs are turned off. 
- The closer we move joystick module to corresponding LED's position, the brighter it becomes. 
- Brightness of the diodes is controlled thanks to the PWM modulation (if we have only two states: high and low, we can "fake" voltage in between those two states thanks to the PWM modulation and get different brightness for the LED).
- If we press joystick module (press the switch) it turns on white LED (switch LED). 


## LED Color Reference 

The diagram below shows how each position corresponds to the color of an LED (white excluded). The center position is (X=510, Y=510) which means the joystick is not moved (is in "resting position").

<img src="images/LED color ref.png" width="600"/>


## Hardware Components

| Component | Quantity | Comments |
| ---- | ----- | ----- |
| Arduino Uno R3 | 1 | It is possible to use different Arduino board |
| Joystick module | 1 | PS2 style or compatible with KY-023 |
| Red LED | 1 | Controlled via PWM |
| Blue LED | 1 | Controlled via PWM |
| Yellow LED | 1 | Controlled via PWM |
| Green LED | 1 | Controlled via PWM |
| White LED | 1 | Button status indicator |
| Resistor $1\ \mathsf{k\Omega}$ | 5 | Limiting current for LEDs |
| Breadboard | 1 | - |
| Jumper wires | - | - |

## Pin Mapping
The connections are also shown in the code JoystickLedController.ino. Each number or symbol corresponds to the Arduino pin. In more detail:

| Component | Arduino pin | Comments |
| ---- | ----- | ----- |
| Joysticks X-coordinate  | A1 | ADC pin |
| Joysticks Y-coordinate | A0 | ADC pin |
| Joystick switch| 2 | - |
| Red LED | 11 | PWM pin |
| Blue LED | 10 | PWM pin |
| Yellow LED | 9 | PWM pin |
| Green LED | 6 | PWM pin |
| White LED | 7 | - |



### Fragment of the code:

```
#define LedLeft 11
#define LedUpper 10
#define LedLower 9
#define LedSw 7
#define ledLeftight 6
#define XPin A1
#define YPin A0
#define SW 2
```

## How to Run

### Step 1

Install and launch an IDE capable of compiling and uploading Arduino code (e.g., [Arduino IDE](https://www.arduino.cc/en/software/)).

### Step 2 

Connect all components according to the pin mapping above.

### Step 3 

Connect your board to the PC. Upload and run the code. 



