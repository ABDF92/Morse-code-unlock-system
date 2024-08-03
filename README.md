# 🚀 Morse code unlock system
Welcome to my Arduino project! This project involves an Arduino Uno, various sensors, and components to create a functional prototype. Below you'll find the details of the components used, the circuit diagram, and the code.

## 📸 Circuit Diagram
Here's the circuit diagram for the project:

![image](https://github.com/user-attachments/assets/745f7041-0755-48ec-bfe5-9dd10e6431c1)


## 📜 Project Description

This project includes the following components:
- 🔋 **Arduino Uno**
- 🟢 **PIR Motion Sensor**
- 🔊 **Ultrasonic Sensor**
- 🔄 **Servo Motor**
- 🔴 **LEDs**
- 🟩 **16x2 LCD Display**
- 🟢 **Push Button**

it uses morse code as an input to the system.

## 🛠️ Components

- Arduino Uno
- PIR Motion Sensor
- Ultrasonic Sensor (HC-SR04)
- Servo Motor
- LEDs
- 16x2 LCD Display
- Push Button
- Resistors
- Breadboard and Jumper Wires

## 🔧 Setup and Wiring

### Wiring Instructions:
1. **PIR Motion Sensor**: Connect to Digital Pin 2.
2. **Ultrasonic Sensor**:
   - VCC to 5V
   - GND to GND
   - Trig to Digital Pin 9
   - Echo to Digital Pin 10
3. **Servo Motor**: Connect to Digital Pin 6.
4. **LEDs**:
   - Red LED 1: Digital Pin 11
   - Red LED 2: Digital Pin 12
5. **16x2 LCD Display**: Connect using I2C
   - SDA to A4
   - SCL to A5
6. **Push Button**: Connect to Digital Pin 3

## 🖥️ Code

The code for this project can be found in the `sketch.ino` file.

## 🏁 Getting Started

1. **Clone the repository**:
   ```sh
   git clone https://github.com/ABDF92/Morse-code-unlock-system.git
   cd Morse-code-unlock-system
   ```
   
2. **Open the project in Arduino IDE**:
   - Launch Arduino IDE.
   - Open `sketch.ino`.
   - Compile the code.
3. **Upload the code:**:
   - Connect your Arduino Uno to your computer.
   - Select the correct board and port.
   - Upload the code to the Arduino.
