# Line Follower Bot using Arduino Uno (5 IR Sensors, LSRB Algorithm)

A simple yet intelligent **line follower robot** built using **Arduino Uno** and **5 IR sensors** that follows a black line on a white surface using the **LSRB (Left–Straight–Right–Backward)** algorithm.

This project demonstrates fundamental concepts of **autonomous navigation**, **sensor-based decision-making**, and **motor control logic** in embedded systems.

---

## 🧠 Features

- 🧭 **Smart Line Following** using 5 IR sensors (A0–A4)
- ⚙️ **LSRB Logic** for decision-based path correction
- 🛑 **Stops automatically** when all sensors detect black (end of path)
- 🔄 **Line recovery system** when bot loses track (all sensors white)
- ⚡ Compatible with **L298N** or similar motor driver modules

---

## ⚙️ Hardware Requirements

| Component | Quantity | Description |
|------------|-----------|-------------|
| Arduino Uno | 1 | Main microcontroller board |
| L298N Motor Driver | 1 | Controls direction and speed of motors |
| IR Sensors | 5 | Detect black and white lines |
| DC Motors | 2 | For left and right wheel control |
| Chassis | 1 | Base for mounting all components |
| Wheels | 2 | Coupled with motors |
| Battery (9V or 12V) | 1 | Power source |
| Jumper Wires | - | For connections |

---

## 🧩 Circuit Connections

| IR Sensor | Arduino Pin |
|------------|-------------|
| Left-most Sensor | A0 |
| Left-center Sensor | A1 |
| Center Sensor | A2 |
| Right-center Sensor | A3 |
| Right-most Sensor | A4 |

| Motor | L298N Pins | Arduino Pins |
|--------|-------------|--------------|
| Left Motor | IN1, IN2 | 5, 6 |
| Right Motor | IN3, IN4 | 9, 10 |

**Note:** Ensure all grounds (Arduino, motor driver, and sensors) are connected together.

---

## 💡 Algorithm Overview (LSRB)

| Condition | Sensor Pattern (S1–S5) | Action |
|------------|------------------------|--------|
| On Track | 11101 / 10111 | Move Forward |
| Slight Left | 11001 / 10011 | Turn Left |
| Slight Right | 11100 / 01110 | Turn Right |
| Sharp Left | 10000 / 11000 | Turn Left |
| Sharp Right | 00001 / 00011 | Turn Right |
| All Black | 00000 | Stop Bot |
| All White | 11111 | Search for Line (rotate based on last direction) |

---

## 🚀 How It Works

1. Each IR sensor detects whether it’s on the black line (`0`) or white surface (`1`).
2. The Arduino continuously reads all five sensors.
3. Based on the detected pattern, it decides:
   - Whether to go straight, turn left/right, or stop.
4. If the bot loses the line, it rotates in the **last known direction** to recover the path.

---

## 🔧 Code Explanation

- **`readSensors()`** → Reads all five IR sensors and prints their state via Serial Monitor.  
- **`forward(), left(), right(), stopBot()`** → Motor control functions.  
- **LSRB Logic** → Implements direction correction based on real-time sensor data.  
- **Lost Line Handling** → Rotates bot in the last direction to find line again.  
- **Stop Condition** → Bot halts when all sensors detect black (endpoint).

---

## 🧰 Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software)
- Board: **Arduino Uno**
- Serial Monitor (optional, for debugging)
- Baud Rate: **9600**

---

## ▶️ Upload Instructions

1. Open Arduino IDE.
2. Copy the code.
3. Select the correct **Board** → Arduino Uno.
4. Select the correct **COM Port**.
5. Click **Upload**.
6. Power your bot and place it on the track — it will start following the black line automatically!

---

## 🧩 Future Enhancements

- Add **PID control** for smoother turns.  
- Use **analog IR sensors** for finer path correction.  
- Integrate **Bluetooth** or **ultrasonic sensor** for remote control and obstacle avoidance.

---

## 🏁 Author

**Aaryan Pandey**  
📧 [aaryanp345@gmail.com]  
🌐 [GitHub: Aaryan-cyg](https://github.com/Aaryan-cyg)

---

## 📜 License

This project is licensed under the **MIT License** – feel free to modify and use it for educational or personal purposes.

