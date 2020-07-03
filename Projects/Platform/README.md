Platform project
================

The **Platform** project configures the hardware of the evaluation board
and is a CMSIS-RTOS2 based software template that can be further expanded.

RTX5 Real-Time Operating System
-------------------------------
The [RTX5 RTOS](https://arm-software.github.io/CMSIS_5/RTOS2/html/rtx5_impl.html)
implements the resource management. It is configured with the following settings:

- Global Dynamic Memory size: 24000 bytes
- Default Thread Stack size:  3072 bytes

NXP LPCXpresso55S69 Target Board
--------------------------------
The Board layer contains the following configured interface drivers:

**CMSIS-Driver USART2** routed to Arduino UNO R3 connector (P18):
 - TX:         pin D1      (FC2_USART_TXD_ARD)
 - RX:         pin D0      (PLU_OUT6/GPIO/FC2_USART_RXD_ARD)

**CMSIS-Driver SPI8** routed to Arduino UNO R3 connector (P17):
 - SCK:        pin D13     (LSPI_HS_SCK)
 - MISO:       pin D12     (LSPI_HS_MISO)
 - MOSI:       pin D11     (LSPI_HS_MOSI)

**GPIO** pins routed to Arduino UNO R3 connector (P17):
 - output:     pin D10     (LSPI_HS_SSEL1)
 - input:      pin D9      (PIO1_5_GPIO_ARD)

**CMSIS-Driver VIO** with the following board hardware mapping:
 - vioBUTTON0: Button USER (PIO1_9)
 - vioLED0:    LED RED     (PIO1_6)
 - vioLED1:    LED GREEN   (PIO1_7)
 - vioLED2:    LED BLUE    (PIO1_4)

The board configuration can be modified using [MCUxpresso](https://www.keil.com/nxp)
and is stored in the file `LPCXpresso55S69.mex`.
