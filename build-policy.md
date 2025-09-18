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


##  How to Build and Run

```bash
cd sim
make clean && make
./mcf_sim


Expected output:
All register writes logged
SPI byte transmission logged per write
No dependency on STM32 hardware or HAL


Notes
This project is not intended to run on STM32 hardware.
It mimics HAL-style API behavior using pure C
Can be extended to support RTOS stubs or integration tests

