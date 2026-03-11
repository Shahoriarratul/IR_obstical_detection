# IR Obstacle Detection Car (Arduino + L298N)

This project controls a 2-wheel robot car using:
- **Arduino**
- **L298N motor driver**
- **IR obstacle sensor (digital output)**

The robot behavior is simple:
- If obstacle is detected (`sensor = 0`) → **stop motors**
- If no obstacle (`sensor = 1`) → **move forward**

---

## File in this project

- `sketch_dec3a.ino` – main Arduino sketch

---

## Current pin configuration (active code)

### L298N motor driver

**Motor A (Left):**
- `enA` → Pin **10** (PWM speed)
- `in1` → Pin **2** (direction)
- `in2` → Pin **3** (direction)

**Motor B (Right):**
- `enB` → Pin **11** (PWM speed)
- `in3` → Pin **4** (direction)
- `in4` → Pin **5** (direction)

### IR sensor
- `OUT` → Pin **9**
- `VCC` → **5V**
- `GND` → **GND**

---

## How the code works

### `setup()`
- Starts serial communication at `9600`
- Sets all motor pins as `OUTPUT`
- Sets sensor pin as `INPUT`
- Prints startup messages to Serial Monitor

### `loop()`
1. Reads sensor value using `digitalRead(sensorPin)`
2. Prints sensor + motor status to Serial Monitor
3. Decision:
   - `0` → calls `stopMotors()`
   - `1` → calls `moveForward()`
4. Waits `500 ms`

### `moveForward()`
- Sets both motors to forward direction
- Uses PWM speed:
  - `analogWrite(enA, 70)`
  - `analogWrite(enB, 70)`

### `stopMotors()`
- Sets direction pins LOW
- Sets speed PWM to 0

---

## Upload and run

1. Open `sketch_dec3a.ino` in Arduino IDE
2. Select your board and COM port
3. Upload sketch
4. Open **Serial Monitor** at **9600 baud**
5. Place an obstacle in front of the IR sensor and verify stop behavior

---

## Notes

- Many IR sensors are **active-low** (obstacle = `0`), which matches this sketch.
- If your sensor logic is reversed, swap the `if` condition in `loop()`.
- There is an older, commented-out version of code at the bottom of `sketch_dec3a.ino` with a different pin map; the active code is the one at the top.
