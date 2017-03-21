/*
  Copyright (c) 2015 Atmel Corp./Thibaut VIARD. All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_ATMEL_SAMD21_XPRO_
#define _VARIANT_ATMEL_SAMD21_XPRO_

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK		    (48000000ul)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"
#include <stdbool.h>

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (53ul)
#define NUM_DIGITAL_PINS     (22ul)
#define NUM_ANALOG_INPUTS    (6ul)
#define NUM_ANALOG_OUTPUTS   (1ul)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

// Interrupts
#define digitalPinToInterrupt(P)   ( g_APinDescription[P].ulExtInt )

// LED(s)
#define PIN_LED_13           (2ul)
#define PIN_LED              PIN_LED_13
#define PIN_LED0             PIN_LED_13
#define LED_BUILTIN          PIN_LED_13

// Button(s)
#define PIN_BUTTON           (3ul)
#define PIN_SW0              PIN_BUTTON

/*
 * Analog pins
 */
#define PIN_A0               (22ul)
#define PIN_A1               (23ul)
#define PIN_A2               (24ul)
#define PIN_A3               (25ul)
#define PIN_A4               (26ul) // is also analog output (DAC)
#define PIN_A5               (27ul)

static const uint8_t A0  = PIN_A0 ;
static const uint8_t A1  = PIN_A1 ;
static const uint8_t A2  = PIN_A2 ;
static const uint8_t A3  = PIN_A3 ;
static const uint8_t A4  = PIN_A4 ;
static const uint8_t A5  = PIN_A5 ;
#define ADC_RESOLUTION		12

/*
 * Serial interfaces
 */
// Serial (EDBG)
#define PIN_SERIAL_RX       (28ul)
#define PIN_SERIAL_TX       (29ul)
#define PAD_SERIAL_RX       (SERCOM_RX_PAD_1)
#define PAD_SERIAL_TX       (UART_TX_PAD_0)

// Serial1
#define PIN_SERIAL1_RX       (0ul)
#define PIN_SERIAL1_TX       (1ul)
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_1)
#define PAD_SERIAL1_TX       (UART_TX_PAD_0)

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 3

#define PIN_SPI_MOSI         (34ul)
#define PIN_SPI_MISO         (35ul)
#define PIN_SPI_SCK          (36ul)
#define PIN_SPI_SS           (37ul)
#define PERIPH_SPI           sercom0
#define PAD_SPI_TX           SPI_PAD_2_SCK_3
#define PAD_SPI_RX           SERCOM_RX_PAD_0

#define PIN_SPI1_MOSI        (39ul)
#define PIN_SPI1_MISO        (40ul)
#define PIN_SPI1_SCK         (41ul)
#define PIN_SPI1_SS          (42ul)
#define PERIPH_SPI1          sercom1
#define PAD_SPI1_TX          SPI_PAD_2_SCK_3
#define PAD_SPI1_RX          SERCOM_RX_PAD_0

#define PIN_SPI2_MOSI        (44ul)
#define PIN_SPI2_MISO        (45ul)
#define PIN_SPI2_SCK         (46ul)
#define PIN_SPI2_SS          (47ul)
#define PERIPH_SPI2          sercom5
#define PAD_SPI2_TX          SPI_PAD_2_SCK_3
#define PAD_SPI2_RX          SERCOM_RX_PAD_0

static const uint8_t SS	  = PIN_SPI_SS ;
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

// Needed for WINC1501B (WiFi101) library (plugged to port EXT2)
// --------------------------------------
#define WINC1501_RESET_PIN   (8ul)
#define WINC1501_CHIP_EN_PIN (11ul)
#define WINC1501_INTN_PIN    (10ul)
#define WINC1501_SPI         SPI1
#define WINC1501_SPI_CS_PIN  PIN_SPI1_SS

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SCL         (32ul)
#define PIN_WIRE_SDA         (33ul)
#define PERIPH_WIRE          sercom2
#define WIRE_IT_HANDLER      SERCOM2_Handler

/*
 * USB
 */
#define PIN_USB_DP           (49ul)
#define PIN_USB_DM           (50ul)
#define PIN_USB_HOST_ENABLE  (51ul)
#define PIN_USB_VBUS         PIN_USB_HOST_ENABLE
#define PIN_USB_ID           (52ul)

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
 */
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;

extern Uart Serial;

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         SerialUSB
// Serial has no physical pins broken out, so it's not listed as HARDWARE port
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1

#endif /* _VARIANT_ATMEL_SAMD21_XPRO_ */

