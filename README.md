# Arduino-UART-Communication
 📡 Arduino UART Communication System

> Serial communication between two Arduino UNO boards using digital signals and pulse-time encoding — 3 buttons control 3 LEDs wirelessly via UART.

---

## 📌 Project Overview

This project demonstrates **serial (UART) communication** between two Arduino UNO boards. When a button is pressed on the **emitter** Arduino, it transmits a unique signal pattern. The **receiver** Arduino reads the pattern using `pulseIn()` and lights up the corresponding LED.

Each button generates a unique signal based on **pulse timing** (HIGH/LOW durations in microseconds), allowing the receiver to identify which button was pressed.

---

## ⚙️ How It Works

```
[Emitter Arduino]                    [Receiver Arduino]
  Button 1 ──► Signal (500/700/300µs) ──► LED 1
  Button 2 ──► Signal (300/100/800µs) ──► LED 2
  Button 3 ──► Signal (800/200/600µs) ──► LED 3

TX (Pin 3) ────────────────────────── RX (Pin 0)
GND ──────────────────────────────── GND
```

**Signal encoding per button:**

| Button | HIGH (t1) | LOW (t2) | HIGH (t3) |
|--------|-----------|----------|-----------|
| Button 1 | 500 µs | 700 µs | 300 µs |
| Button 2 | 300 µs | 100 µs | 800 µs |
| Button 3 | 800 µs | 200 µs | 600 µs |

---

## 🛠️ Hardware Components

- 2× Arduino UNO boards
- 3× Push buttons (normally open)
- 3× LEDs
- 3× 330Ω resistors
- Jumper wires

---

## 🔌 Wiring

**Emitter:**
- Button 1 → A0 (INPUT_PULLUP)
- Button 2 → A1 (INPUT_PULLUP)
- Button 3 → A2 (INPUT_PULLUP)
- TX signal → Pin 3

**Receiver:**
- LED 1 → A0
- LED 2 → A1
- LED 3 → A2
- RX signal → Pin 0

**Connection between boards:**
- Emitter Pin 3 (TX) → Receiver Pin 0 (RX)
- Emitter GND → Receiver GND

---

## 💻 Technologies

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=flat&logo=Arduino&logoColor=white)
![C](https://img.shields.io/badge/Embedded%20C-00599C?style=flat&logo=c&logoColor=white)

- **Language:** Embedded C (Arduino)
- **Protocol:** UART / Serial communication
- **Key functions:** `pulseIn()`, `digitalRead()`, `digitalWrite()`, `delayMicroseconds()`

---

## 📁 Project Structure

```
Arduino-UART-Communication/
├── emission/
│   └── emission.ino       # Emitter code (buttons → signal)
├── reception/
│   └── reception.ino      # Receiver code (signal → LEDs)
└── README.md
```

---

## 🐛 Key Bugs Fixed

| Bug | Original | Fixed |
|-----|----------|-------|
| Wrong read function | `analogRead()` for digital buttons | `digitalRead()` |
| Wrong comparison | `0 < t1 < 500` (invalid in C) | `t1 > 0 && t1 < 500` |
| Wrong pin mode | `pinMode(3, x1)` | Removed, not needed |
| Wrong LED off | `analogWrite(led1, 0)` | `digitalWrite(led3, LOW)` |
| Missing comment syntax | `delay(200); signal emit...` | `// signal emit...` |

---

## 👩‍💻 Author

**Nada Djazari** — Electronics of Embedded Systems Engineer
📧 nada.djazari@gmail.com
🎓 University of Jijel, Algeria
