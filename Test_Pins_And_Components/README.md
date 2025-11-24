# LAFVIN 4WD Robot - Our Adventure 🤖

## How We Started

My buddy and I started with this LAFVIN robot thinking it would be easy - write some code, robot drives, done! But... we weren't even close! 😅

## The Problem That Almost Broke Us

### What Was Happening:
- We write code for **forward (F)** → robot goes **BACKWARD!** 😡
- We write code for **backward (B)** → robot goes **FORWARD!** 🤯
- Left wheels go one direction, right wheels go another
- Total chaos!

### Why It Was a Problem:
**WE DIDN'T KNOW WHICH PIN CONTROLS WHICH WHEEL!**

We tried "blindly" - try pin 2, then pin 4, then 6... and everything got more and more mixed up. We wasted hours trying different combinations without a system.

---

## Our Solution: SYSTEMATIC TESTING! 💡

After a lot of struggle, we realized we had to be **systematic**. We created a test that:

1. **Tries ALL possible PWM pins** (3, 5, 6, 9, 10, 11) - for speed
2. **Tries ALL possible digital pins** (2, 4, 7, 8, 12, 13) - for direction
3. **Records which combination does what** - forward, backward, left, right
4. **Has pauses between tests** - so we can see what's happening

### Test Results:

#### ✅ **WHEELS - FINALLY SOLVED!**
- **Left wheel pair:**
  - PWM pin: **5**
  - Forward: pin 6=HIGH, pin 9=HIGH (others LOW)
  - Backward: pin 2=HIGH, pin 4=HIGH, pin 6=HIGH, pin 9=HIGH

- **Right wheel pair:**
  - PWM pin: **11**
  - Forward: pin 6=HIGH, pin 9=HIGH
  - Backward: pin 2=HIGH, pin 3=HIGH, pin 4=HIGH, pin 6=HIGH, pin 9=HIGH

#### ✅ **ULTRASONIC SENSOR**
- TRIG pin: **12**
- ECHO pin: **13**
- Found it with a test that tried **156 combinations!**

#### ✅ **SERVO MOTOR (for radar)**
- Servo pin: **10**

---

## What The Files Do

### 📁 **Main Files:**

#### `Robot_Final_Complete.ino`
- **Bluetooth control** of the robot
- Commands: F (forward), B (backward), L (left), R (right), S (stop)
- Robot **maintains** movement until you send a new command
- **THIS WORKS PERFECTLY!** ✅

#### `Robot_Ultimate.ino`
- **3 MODES** in one code:
  - **Mode 1**: Automatic (drives by itself, avoids obstacles)
  - **Mode 2**: Manual control (F/B/L/R/S)
  - **Mode 3**: Radar scanning (servo + sensor)
- Commands: '1', '2', '3' to change modes

---

### 📁 **Tests/ Folder - Our Tests:**

#### **Wheel Tests:**

1. `Test_SAMO_Levi_Napred.ino`
   - Test for left wheels forward only
   - We found that PWM pin is 5

2. `Test_SAMO_Donji_Levi_A2.ino`
   - We tried to control ONLY the bottom left wheel
   - **Conclusion**: Can't do it! Motor driver only has 2 channels (left pair, right pair)

3. `Test_Donji_Levi_Napred.ino`
   - Automatically tests **ALL combinations** of PWM and digital pins
   - Each test runs for 3 seconds, then STOP for 10 seconds
   - **THIS TEST SAVED OUR SANITY!**

4. `Test_Unazad_Sve_Pinove.ino`
   - Test for finding backward pins
   - 6 different combinations with pauses

5. `Test_Unazad-Finalno.ino`
   - Final test for all 4 wheels backward

6. `Test_Unazad-Perfektno.ino`
   - Simpler backward test (without pins 2,4)

#### **Sensor Tests:**

7. `Test_Senzor_Pin10.ino`
   - We thought the sensor was on pin 10 (it wasn't!)
   - Pin 10 is the **servo motor**

8. `Test_Radar_Hunting_Mode.ino`
   - **CRAZY TEST!** 🎯
   - Servo scans the area, finds the closest "target"
   - "Shoots" 3 times at target (measures distance)
   - Fun for testing!

---

## Lessons We Learned 📚

### ❌ **WHAT DOESN'T WORK:**
1. **"Try-and-see"** approach without a system
2. Assuming pins are standard
3. Trying to control each wheel individually (motor driver only has 2 channels!)

### ✅ **WHAT WORKS:**
1. **SYSTEMATIC TESTING** of all combinations
2. **Recording results** - each test shows which combination works
3. **Pauses between tests** - 10 seconds to see what's happening
4. **Serial Monitor** - to see which test is running
5. **Patience** - sometimes it takes 156 tests to find the right pins!

---

## Pin Map - FINAL! 🎯

```
MOTORS:
├─ Left Pair (PWM pin 5)
│  ├─ Forward: 6=HIGH, 9=HIGH
│  └─ Backward: 2=HIGH, 4=HIGH, 6=HIGH, 9=HIGH
│
└─ Right Pair (PWM pin 11)
   ├─ Forward: 6=HIGH, 9=HIGH
   └─ Backward: 2=HIGH, 3=HIGH, 4=HIGH, 6=HIGH, 9=HIGH

SENSORS:
├─ Ultrasonic Sensor
│  ├─ TRIG: pin 12
│  └─ ECHO: pin 13
│
└─ Servo Motor: pin 10

BLUETOOTH:
└─ RX/TX: Serial port (9600 baud)
```

---

## How to Use

### 1. **Basic Control:**
```arduino
Upload: Robot_Final_Complete.ino
Open: Serial Monitor (9600 baud)
Send: F (forward), B (backward), L (left), R (right), S (stop)
```

### 2. **Advanced Control (3 modes):**
```arduino
Upload: Robot_Ultimate.ino
Open: Serial Monitor (9600 baud)
Send: 
  - '1' for automatic mode (avoids obstacles)
  - '2' for manual control (F/B/L/R/S)
  - '3' for radar scanning
```

### 3. **Pin Testing:**
```arduino
Upload: Test_Donji_Levi_Napred.ino (or another test)
Open: Serial Monitor (9600 baud)
Watch: Robot and Serial Monitor - record which combination works!
```

---

## Next Steps 🚀

- [ ] Autonomous driving (robot drives by itself and avoids obstacles)
- [ ] Follow me mode (robot follows you)
- [ ] **LINE TRACKING** (follows black line) - need to make a track first!
- [ ] Advanced obstacle avoidance algorithms
- [ ] Speed control and optimization

---

## Conclusion

**DON'T GIVE UP!** It seemed impossible when the robot went backward instead of forward, but we solved it! 

**Key to success**: Systematic testing, patience, and a good friend by your side! 💪

---

*Made with ❤️ (and a LOT of frustration) by klinac & me*

*"It's not a bug, it's a feature... or maybe it's actually a bug."* 😄

