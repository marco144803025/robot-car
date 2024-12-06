# Robotic Car Project - EIE3105 Integrated Project (Part II)

Welcome to the repository for the Robotic Car Project for EIE3105. This project demonstrates the development of a robotic car with various functionalities, including remote control, ultrasonic sensing, line tracking, parking, and group relay tasks. The repository contains the source code, schematics, and resources needed to replicate and understand the project.

## Features
1. **Remote Control**: Operate the car wirelessly to move in specific directions.
2. **Ultrasonic Sensing**: Measure distances and display them in Tera Term.
3. **Line Tracking**: Follow a pre-defined line using IR sensors.
4. **Car Parking**: Automatically park the car near a wall using PWM control.
5. **Group Activities**:
   - **Ball Hitting**: Hit a table tennis ball between cars.
   - **Relay Race**: Coordinate two cars for a race involving turns and ultrasonic sensing.

---

## Project Demonstrations

### Demonstration 1: Robot Car and Ultrasonic Sensor Development
- **Hardware**:
  - PCB soldering for car and remote control.
  - STM32 microcontroller programming using [STM32 Flash](https://www.st.com/en/development-tools/flasher-stm32.html).
- **Software**:
  - Remote control for forward, backward, left, and right movement.
  - Ultrasonic distance readings displayed in Tera Term.

### Demonstration 2: Line Tracking
- **Sensors**: IR LEDs and phototransistors.
- **Method**: Process readings from sensors, convert to ASCII, and debug using LEDs.
- **Optimization**:
  - Adjust speed dynamically for straight paths and turns.

### Demonstration 3: Car Parking
- **Goal**: Park close to a wall without collision using ultrasonic feedback.
- **Method**: Use conditional PWM logic for precise movements.

### Demonstration 4: Group Tasks
- **Ball Hitting**:
  - Control speed and timing for hitting the ball six times.
- **Relay Race**:
  - Ultrasonic sensing for detecting incoming cars and coordinating maneuvers.

---

## Block Diagrams and Configurations

### Communication
- **Baud Rate**: 115200
- **Modules**: Arduino and ARM via USART (HC-05/HC-06).

### PWM Configuration
| Function            | Device Pin |  
|---------------------|------------|  
| Left Wheel (Fwd)    | TIM1_CH1 - PA8  |  
| Left Wheel (Bwd)    | TIM1_CH1N - PB13 |  
| Right Wheel (Fwd)   | TIM1_CH2N - PB14 |  
| Right Wheel (Bwd)   | TIM1_CH2 - PA9   |  


