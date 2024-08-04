# STM32 Bare Metal Project

This project demonstrates how to configure and use the UART2 peripheral on an STM32 microcontroller in a bare-metal environment. The code initializes the UART2 interface to transmit and receive data without relying on any external libraries or IDE-specific features.

## Prerequisites

- STM32 microcontroller (e.g., STM32F4 series)
- ARM GCC toolchain or any compatible toolchain for STM32 development
- ST-Link or any compatible debugger/programmer
- Serial terminal application (e.g., PuTTY, Tera Term)

## Project Structure

- ```main.c```: Main application code and peripheral initialization

## Code Overview

### Purpose

The purpose of this project is to provide a hands-on example of bare-metal programming for STM32 microcontrollers. It focuses on direct register manipulation to configure and use UART2, which is a fundamental skill for embedded systems development.

### Register Definitions

Peripheral base addresses and register definitions are essential for accessing and configuring the microcontroller's hardware without using any pre-defined headers or libraries. This approach gives you a deeper understanding of how the hardware operates and how the peripherals are controlled.

### Clock and GPIO Configuration

The first step in setting up the UART2 is to enable the clocks for the GPIOA and USART2 peripherals. This is done by writing to the RCC (Reset and Clock Control) registers. Then, the GPIOA pins (PA2 and PA3) are configured for alternate function mode to be used for UART2. This configuration allows the microcontroller's pins to function as UART TX and RX.

### USART2 Initialization

USART2 is configured with the desired baud rate and other parameters, such as enabling the transmitter (TE) and receiver (RE). The initialization sequence includes setting the baud rate, enabling the UART, and ensuring the correct alternate function is selected for the GPIO pins.

## Usage

1. **Compile and Flash the Code:**
   - Use your preferred toolchain to compile the `main.c` file.
   - Flash the compiled binary to your STM32 microcontroller using ST-Link or any compatible programmer.

2. **Connect UART:**
   - Connect the TX (PA2) and RX (PA3) pins to a UART interface, such as a USB-to-Serial adapter connected to your PC.

3. **Open Serial Terminal:**
   - Open a serial terminal (e.g., PuTTY, Tera Term) on your PC and configure it to the baud rate of 9600.

4. **Run the Application:**
   - After flashing, the application will start. Type characters in the serial terminal and observe them being echoed back.

## Learning Objectives

- Understand how to manipulate peripheral registers directly for hardware control.
- Learn the basics of UART communication in a bare-metal environment.
- Gain hands-on experience with configuring microcontroller peripherals without relying on high-level libraries or IDE-specific features.
- Develop skills for debugging and troubleshooting low-level embedded code.

This project serves as a foundational exercise for embedded systems programming, providing insights into the inner workings of microcontroller peripherals and low-level hardware interactions.
