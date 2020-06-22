Platform Project
================

The 'Platform' project configures the hardware of the evaluation board
and is a CMSIS-RTOS2 based software template that can be further expanded.

This implementation contains the following configured interface drivers:

  - CMSIS-Driver USART2 routed to Arduino UNO R3 connector
    - TX:    J18 pin 13
    - Rx:    J18 pin 15

  - CMSIS-Driver SPI8 (LSPI_HS) routed to Arduino UNO R3 connector
    - SCK:   J17 pin 9
    - MISO:  J17 pin 11
    - MOSI:  J17 pin 13
    - SSEL1: J17 pin 15

  - CMSIS-Driver VIO with the following board hardware mapping
    - vioBUTTON0: PIO1_9 - Button USER (SW3)
    - vioLED0:    PIO1_6 - LED RED
    - vioLED1:    PIO1_7 - LED GREEN
    - vioLED2:    PIO1_4 - LED BLUE

  - GPIO mapping
    - PIO1_5_GPIO_ARD (J17 pin 17) input

The CMSIS-RTOS2 is based on RTX5 with the following configuration settings:

   - Global Dynamic Memory size: 32768 bytes

   - Default Thread Stack size: 3072 bytes
