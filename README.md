# STM32F103C8T6 Bare-Metal Peripheral Library

  A peripheral driver library for the [STM32F103C8T6](https://www.st.com/en/microcontrollers-microprocessors/stm32f103c8.html) (Blue Pill),
written in C. This approach guarantee the deep understanding of your MCU,
and full control over the resources.
  This library uses Make and arm-none-eabi-gcc for building the firmware.
  For testing I used the actual board and later, I start using very interesting Hardware emulator called [Renode](https://antmicro.com/platforms/renode/), to use Renode (after install it) you can use this command `renode sim/bluepill.resc` in the project root.

---

## What's Implemented

| Module | File | Status |
| -------- | ------ | -------- |
| GPIO | `src/gpio.c` | Complete |
| RCC | `src/rcc.c` | Complete |
| SPI | `src/spi.c` | Complete |
| UART | `src/uart.c` | Complete |
| I2C | `src/i2c.c` | In progress |
| PWM | — | Planned |
| Interrupts | — | Planned |
| DMA | — | Planned |

---

## Project Structure

```
├── src/          # Driver implementations
├── inc/          # Header files
├── linker/       # linker script 
├── sim/          # Renode simulation 
├── docs/         # Documentations of stm32f103c8
└── build/        # Compiled output 

```

---

## Toolchain

- Compiler: `arm-none-eabi-gcc`
- Build system: GNU Make
- Flashing: `st-flash`
- OS: Void Linux
- Text Editor: Neovim (Lazyvim)

---

## Build

```bash
make        # compile
make flash  # flash to board via ST-Link
make clean  # clean build artifacts
```

---

## Hardware

- **MCU:** STM32F103C8T6 (Blue Pill, 72MHz Cortex-M3)
- **Programmer:** ST-Link V2
- **Testing**: Arduino Nano
- Simulation: Renode

---

## Checklist

- [x] GPIO driver (input, output, alternate function)
- [x] RCC clock configuration
- [x] Custom startup file and vector table
- [x] Custom linker script
- [x] SPI driver
- [x] UART driver
- [ ] Timer / PWM driver
- [ ] I2C driver
- [ ] DMA
- [ ] Interrupts

---

## Author

Mohamed Ayad
[![LinkedIn](https://img.shields.io/badge/LinkedIn-blue?logo=linkedin)](https://www.linkedin.com/in/mohamed-ayad-863b00449/?lipi=urn%3Ali%3Apage%3Ad_flagship3_profile_view_base_contact_details%3By9hqtjIqTbuYSSHZ1QFQDQ%3D%3D)
[![GitHub](https://img.shields.io/badge/GitHub-black?logo=github)](https://github.com/aydm32)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
