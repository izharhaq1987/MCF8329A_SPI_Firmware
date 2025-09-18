# DESIGN.md – MCF8329A SPI Firmware for STM32


##  Overview

This project simulates STM32 firmware to configure the **Texas Instruments MCF8329A** BLDC motor driver via SPI. It demonstrates a realistic firmware initialization sequence using a fake register map and mock SPI transmission, without requiring hardware.


##  Architecture


+-----------------------+
| main.c |
| └─ calls init() |
+-----------------------+
↓
+-----------------------+
| mcf8329a.c/h |
| └─ mcf8329a_write_register() |
| └─ shadow reg_map[] |
+-----------------------+
↓
+-----------------------+
| spi_mock.c/h |
| └─ mock_spi_transmit()|
| └─ printf byte log |
+-----------------------+


##  Firmware Flow

```c
mcf8329a_write_register(0x20, 0x1234);  // Write CTRL register
 → Formats 3-byte SPI frame
 → Logs register + bytes
 → Sends via mock_spi_transmit()
 → Data stored in reg_map[0x20]


Simulated Register Write Format

| Byte Index | Meaning         | Notes             |
| ---------- | --------------- | ----------------- |
| TX\[0]     | Address (7-bit) | MSB = 0 for write |
| TX\[1]     | Data\[15:8]     | High byte         |
| TX\[2]     | Data\[7:0]      | Low byte          |


Example Register Write Log

| Address | Simulated Register   |
| ------- | -------------------- |
| 0x20    | Control Register 1   |
| 0x21    | Control Register 2   |
| 0x22    | Motor Startup Config |
| 0x30    | Motor Parameters     |
| 0x31    | Gate Drive Strength  |
| 0x3E    | Fault Masking        |
| 0x3F    | Enable Driver        |


Stored in:
static uint16_t reg_map[64];


No Hardware Mode
SPI is not wired to physical pins
No HAL drivers required
Entire simulation runs in user space using gcc + make


Future Enhancements
Add mcf8329a_read_register()
Support readback verification
Integrate with unit tests (e.g. Unity)


##  `build-policy.md` – Build Instructions & Simulation Policy

```md
# build-policy.md – Build System & Simulation Policy


##  Build Toolchain

This firmware simulation project uses a minimal toolchain:

| Component | Version / Tool       |
|----------|-----------------------|
| Compiler | `gcc` (native host)   |
| Build    | `make`                |
| IDE      | Optional – VSCode / CubeIDE (IOC only) |


##  Simulation Directory
All simulation-related logic is self-contained in:
sim/
├── main.c # Entry point
├── mcf8329a.c/h # SPI register logic
├── spi_mock.c/h # Raw SPI transmitter log
├── Makefile # One-line build



---

##  How to Build and Run

```bash
cd sim
make clean && make
./mcf_sim


Notes
This project is not intended to run on STM32 hardware.
It mimics HAL-style API behavior using pure C
Can be extended to support RTOS stubs or integration tests





