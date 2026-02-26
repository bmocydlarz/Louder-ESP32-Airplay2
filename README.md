# AirPlay 2 Receiver for Louder-ESP32-S3

This project is a high-performance AirPlay 2 audio receiver tailored specifically for the **Louder-ESP32-S3** (and Plus) board. It features full support for the onboard **TAS5805M** Class-D amplifier with hardware volume control.

## 🚀 Hardware Features

* **MCU**: ESP32-S3 with 8MB Octal PSRAM.
* **Amplifier**: TI TAS5805M (Stereo Class-D).
* **Connectivity**: WiFi (AirPlay 2) with metadata and artwork support.

## 🛠 Hardware Configuration (GPIOs)

The following pins are pre-configured in this repository to match the Louder S3 hardware:

### Audio (I2S)

| Function | GPIO |
| --- | --- |
| **I2S BCLK** | 14 |
| **I2S WS (LRCK)** | 15 |
| **I2S DATA (DOUT)** | 16 |

### Control (I2C & Power)

| Function | Value |
| --- | --- |
| **I2C SDA** | 8 |
| **I2C SCL** | 9 |
| **I2C Port** | 1 |
| **TAS5805M Addr** | 0x2D (45) |
| **AMP PWDN (Reset)** | 17 |

## ⚡️ Important Requirements

1. External Power: You MUST provide 12V-24V DC to the power terminals. USB power from a PC/Mac is insufficient to drive the amplifier stage and will cause audio dropouts or "Failed to decrypt" errors.
2. PSRAM: Ensure your ESP-IDF project is configured for Octal PSRAM at 80MHz to handle AirPlay 2 decryption.

## 🔧 Installation

1. Setup ESP-IDF (v6.1-dev or later recommended).
2. Clone this repository.
3. Run `idf.py menuconfig` to verify I2S pins (14, 15, 16).
4. Build and flash:
```bash
idf.py build flash monitor

```

## 📶 WiFi Setup

Upon first boot, the device will create a WiFi hotspot named **`ESP32-AirPlay-Setup`**. Connect to it and navigate to `http://192.168.4.1` to enter your local WiFi credentials.
