
 **Smart-Car**

Smart car project using AVR ATmega32 with two modes:

* **Automatic Mode**: Obstacle avoidance using an ultrasonic sensor.
* **Manual Mode**: Control via Bluetooth (UART) with adjustable speed.

Powered by an L298N motor driver for two DC motors.

---

## **🛠 Hardware**

* ATmega32 MCU
* L298N Motor Driver
* HC-SR04 Ultrasonic Sensor
* HC-05 / HC-06 Bluetooth Module
* 2 DC Motors
* Battery pack


## **⚙️ Modes & Commands**

**Manual Mode (`m`):**
`f` = Forward | `b` = Backward | `l` = Left | `r` = Right | `w` = Stop
`+` = Increase speed | `-` = Decrease speed

**Automatic Mode (`a`):**
`s` = Stop | `a` = Resume automatic driving

**Switch Modes:**
`m` = Manual mode | `a` = Automatic mode

**🚀 Usage**

1. Flash firmware to ATmega32 using AVR toolchain.
2. Power the circuit and pair Bluetooth module with your phone.
3. Use Bluetooth terminal app to send commands.


**📂 Structure**

```
Smart-Car/
├── main/   # Main code
├── MCAL/   # MCU abstraction
├── HAL/    # Hardware drivers
├── LIB/    # Common libraries
└── README.md
```

