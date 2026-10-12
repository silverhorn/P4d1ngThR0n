# 🤖 My First Robot: A Father & Son Journey

> Building dreams, one component at a time

[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)](https://www.arduino.cc/)
[![Bluetooth](https://img.shields.io/badge/Bluetooth-0082FC?style=for-the-badge&logo=Bluetooth&logoColor=white)](https://www.bluetooth.com/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)](LICENSE)
[![Built with Love](https://img.shields.io/badge/Built%20with-❤️-red?style=for-the-badge)](https://github.com/silverhorn/P4d1ngThR0n)

![Our robot](images/1.jpeg)

---

## 📖 About

My son's first steps into robotics, at just 6 years old! 🎉

We're building a **Bluetooth-controlled robot car** from scratch using the **Lafvin Tech Arduino robot car kit**. This repository documents our learning process, experiments and all the little victories along the way.

**Why we're doing this:**
- 🧠 Learn electronics and programming together
- 🔧 Develop problem-solving skills
- 👨‍👦 Quality father-son time
- 🚀 Inspire other young makers

---

## 🎯 Roadmap

- [x] Unbox and organize components
- [x] Set up Arduino IDE
- [x] Test pins and each component individually
- [x] Bluetooth module pairing
- [ ] Build the chassis
- [ ] Motor control on the finished chassis
- [ ] Bluetooth control from a phone
- [ ] Mobile app controller
- [ ] Sensors (ultrasonic, line following)
- [ ] Autonomous mode

---

## 🛠️ Hardware

| Part | Qty | Notes |
|------|-----|-------|
| Arduino UNO R3 | 1 | Main board |
| L298N motor driver | 1 | Drives the DC motors |
| HC-05 Bluetooth module | 1 | Wireless control |
| DC motors | 4 | |
| Chassis, wheels, battery holder | 1 set | From the kit |
| Jumper wires, breadboard | - | |
| Sensors | - | To be added |

> Full part numbers and prices will be added as we test each module.

### Wiring

<!-- TODO: add wiring diagram (Fritzing export) to /docs/wiring.png -->
![Wiring diagram](docs/wiring.png)

| Component pin | Arduino pin |
|---------------|-------------|
| TODO | TODO |

---

## 💻 Software

- **Arduino IDE** for development
- **Language:** Arduino (C/C++)
- **Phone app:** a Bluetooth RC controller app (custom app TBD)

### Setup

1. Download the [Arduino IDE](https://www.arduino.cc/en/software)
2. Install the USB driver for the Arduino UNO
3. **Tools → Board → Arduino UNO**
4. **Tools → Port →** select your COM port
5. Open a sketch from `/code` and click **Upload**

---

## 🔍 Progress

### Phase 1: Component testing ✅
- [x] LED blink
- [x] Motor driver
- [x] Individual motors
- [x] Bluetooth pairing
- [x] Sensor calibration

### Phase 2: Integration 🚧
- [x] Motor control via serial commands
- [x] Bluetooth command reception
- [x] Basic movement (forward, backward, turn)

### Phase 3: Advanced features
- [ ] Obstacle detection
- [ ] Line following
- [ ] Speed control

---

## 📸 Gallery

![Progress photo](images/1.jpeg)

<!-- Add more photos and a short GIF of the robot moving: images/2.jpeg, images/demo.gif -->

---

## 🎓 What we're learning

**My 6-year-old:** how electricity works, following instructions, patience, and cause and effect (code → robot action).

**Dad:** teaching electronics to a young child, breaking down complex ideas, Arduino programming, and being patient with tiny fingers and big questions!

---

## 🚀 Quick start

```cpp
// Coming soon: our first working sketch!
```

---

## 📂 Repository structure

```
P4d1ngThR0n/
├── code/      # Arduino sketches (.ino)
├── docs/      # Wiring diagrams, notes
├── images/    # Photos and GIFs
├── LICENSE
└── README.md
```

---

## 🤝 Contributing

Ideas and tips for young makers are very welcome. Open an issue or a pull request!

## 📄 License

MIT. See [LICENSE](LICENSE).
