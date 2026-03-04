# 🚗 Multi-ECU Collision Avoidance System using CAN Protocol

## 📌 Project Description

This project implements a distributed automotive safety system using a 4-ECU architecture interconnected via CAN Bus. The system performs real-time obstacle detection, speed monitoring, intelligent decision-making, dashboard visualization, hazard warning, and actuator control.

The architecture simulates modern automotive safety systems such as collision avoidance and adaptive speed regulation used in Advanced Driver Assistance Systems (ADAS).

---

## 🏗 System Architecture

The system consists of four Electronic Control Units (ECUs):

---

### 🔹 ECU 1 – Distance Measurement Node
- Interfaces with Ultrasonic Sensor
- Continuously measures obstacle distance
- Transmits real-time distance data via CAN

---

### 🔹 ECU 2 – Speed Measurement Node
- Reads vehicle speed using SPI-based voltage sensing
- Sends real-time speed data to ECU3 through CAN

---

### 🔹 ECU 3 – Main Decision & Dashboard ECU
- Receives distance (ECU1) and speed (ECU2)
- Performs threshold-based comparison
- Generates control codes:
  - `11` → Critical (<10 cm)
  - `22` → Warning (<30 cm)
  - `33` → Caution (<50 cm)
  - `44` → Safe (~70 cm)
- Sends control codes + speed to ECU4
- Displays real-time data on Dashboard:
  - Speed
  - Distance
  - Safety Status (SAFE / WARNING / CRITICAL)
  - Control Code

This ECU acts as the central intelligence unit of the system.

---

### 🔹 ECU 4 – Actuation & Safety Control Node
- Controls DC motor using PWM
- Adjusts duty cycle based on control code
- Deploys Airbag in critical condition
- Activates Hazard Buzzer during:
  - Warning (<30 cm)
  - Critical (<10 cm)
- Prints debug logs via UART

---

## 🔁 Communication Protocol

- CAN 2.0 based multi-node communication
- Message ID filtering
- Real-time broadcast architecture
- Deterministic communication between ECUs

---

## ⚙️ Technologies Used

- LPC21xx Microcontroller
- CAN Protocol
- PWM Motor Control
- SPI Communication
- UART Debugging
- Ultrasonic Sensor
- LCD Dashboard Display
- Buzzer Alert System
- Embedded C (Bare-Metal Programming)

---

## 🧠 System Logic Flow

1. ECU1 measures obstacle distance.
2. ECU2 measures vehicle speed.
3. ECU3:
   - Compares values with predefined thresholds
   - Displays real-time status on dashboard
   - Sends control codes + speed to ECU4
4. ECU4:
   - Adjusts motor PWM based on speed
   - Reduces speed based on proximity
   - Activates hazard buzzer for unsafe distances
   - Deploys airbag during critical collision condition

---

## 📊 PWM & Alert Strategy

| Code | Distance Condition | PWM Duty Cycle | Buzzer | Airbag |
|------|--------------------|---------------|--------|--------|
| 11   | < 10 cm            | 0% (Stop)     | ON     | ON     |
| 22   | < 30 cm            | 25%           | ON     | OFF    |
| 33   | < 50 cm            | 50%           | OFF    | OFF    |
| 44   | ~70 cm             | 75%           | OFF    | OFF    |

Dynamic PWM scaling is applied based on speed during normal conditions.

---

## 🚀 Key Features

✔ 4-ECU Distributed Architecture  
✔ Real-Time CAN Communication  
✔ Centralized Decision-Making Logic  
✔ Dashboard-Based Live Monitoring  
✔ Hazard Warning Buzzer  
✔ Adaptive PWM Motor Control  
✔ Emergency Airbag Deployment  
✔ Modular Firmware Design  

---

## 🎯 Applications

- Automotive Collision Avoidance Systems
- Adaptive Speed Regulation
- Embedded CAN Network Prototyping
- Automotive ECU Architecture Simulation
- ADAS Concept Demonstration

---

## 🔮 Future Enhancements

- Implement ABS braking simulation
- Add CAN error handling and fault detection
- Integrate SD card data logging
- Add Bluetooth diagnostic interface
- Implement automatic emergency braking logic
- Upgrade dashboard with graphical LCD

---

## 👨‍💻 Author

Hemanth Kumar  
Electronics and Communication Engineering  

---

## 📜 License

Developed for educational and research purposes.
