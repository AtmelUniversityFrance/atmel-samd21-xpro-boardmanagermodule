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

#include <Arduino.h>

/*
 * Pins descriptions
 */
const PinDescription g_APinDescription[]=
{
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Serial           |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 0          |                  |  PA05  | EXT1_14/EDBG TX | EIC/EXTINT[5]             ADC/AIN[5]  AC/AIN[1]  PTC/Y[3] *SERCOM0_ALT/PAD[1]  TCC0/WO[1]
 * | 1          |                  |  PA04  | EXT1_13/EDBG RX | EIC/EXTINT[4]  ADC/VREFB  ADC/AIN[4]  AC/AIN[0]  PTC/Y[2] *SERCOM0_ALT/PAD[0]  TCC0/WO[0]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA,  5, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 }, // RX: SERCOM0_ALT/PAD[1]
  { PORTA,  4, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4 }, // TX: SERCOM0_ALT/PAD[0]

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | LEDs & button    |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 2          | N/A              |  PA19  | LED0            | EIC/EXTINT[3]  PTC/X[7]  SERCOM1/PAD[3]  SERCOM3_ALT/PAD[3] *TC3/WO[1]  TCC0_ALT/WO[3]  I2S/SD[0]  AC/CMP[1]
 * | 3          | N/A              |  PA28  | SW0             | EIC/EXTINT[8]  GCLK_IO[0]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA, 19, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), No_ADC_Channel, PWM3_CH1, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // TC3/WO[1]
  { PORTA, 28, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 },

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Digital          |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 4          |                  |  PA13  | EXT1_5          | EIC/EXTINT[13]  SERCOM2/PAD[1]  SERCOM4_ALT/PAD[1]  TCC2/WO[1]  FECTRL[3]  AC/CMP[1]
 * | 5          |                  |  PA28  | EXT1_6          | EIC/EXTINT[8]  GCLK_IO[0]
 * | 6          |                  |  PA22  | EXT1_9          | EIC/EXTINT[6]  PTC/X[10]  SERCOM3/PAD[0]  SERCOM5_ALT/PAD[0]  TC4/WO[0]  TCC0_ALT/WO[4]
 * | 7          |                  |  PA23  | EXT1_10         | EIC/EXTINT[7]  PTC/X[11]  SERCOM3/PAD[1]  SERCOM5_ALT/PAD[1]  TC4/WO[1]  TCC0_ALT/WO[5]
 * | 8          |                  |  PA15  | EXT3_5          | EIC/EXTINT[15] SERCOM2/PAD[3] SERCOM4/PAD[3] TC3/WO[1]  FECTRL[5] GCLK_IO[1]
 * | 9          |                  |  PA08  | EXT3_10         | EIC/NMI  ADC/AIN[16]  PTC/X[0]  SERCOM0/PAD[0]  SERCOM2_ALT/PAD[0]  TCC0/WO[0]  FECTRL[0]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
*/
  { PORTA, 13, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, PWM2_CH1, TCC2_CH1, EXTERNAL_INT_13 },
  { PORTA, 28, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 }, // Also SW0
  { PORTA, 22, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM4_CH0, TC4_CH0, EXTERNAL_INT_6 },
  { PORTA, 23, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM4_CH1, TC4_CH1, EXTERNAL_INT_7 },
  { PORTA, 15, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH1, TC3_CH1, EXTERNAL_INT_15 },
  { PORTA,  8, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel16, PWM0_CH0, TCC0_CH0, EXTERNAL_INT_NMI },

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Digital/PWM      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 10         | PWM+             |  PA18  | EXT1_7          | EIC/EXTINT[2]  PTC/X[6]  SERCOM1/PAD[2]  SERCOM3_ALT/PAD[2]  TC3/WO[0] *TCC0_ALT/WO[2]  AC/CMP[0]
 * | 11         | PWM-             |  PA19  | EXT1_8          | EIC/EXTINT[3]  PTC/X[7]  SERCOM1/PAD[3]  SERCOM3_ALT/PAD[3]  TC3/WO[1] *TCC0_ALT/WO[3]  I2S/SD[0]  AC/CMP[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
*/
  { PORTA, 18, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH2, TCC0_CH2, EXTERNAL_INT_2 }, // TCC0/WO[2]
  { PORTA, 19, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH3, TCC0_CH3, EXTERNAL_INT_3 }, // TCC0/WO[3], also LED0

/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Analog pins      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 12         |                  |  PA06  | A0/EXT1_3       | EIC/EXTINT[6] *ADC/AIN[6]  AC/AIN[2]  PTC/Y[4]  SERCOM0_ALT/PAD[2]  TCC1/WO[0]
 * | 13         |                  |  PA07  | A1/EXT1_4       | EIC/EXTINT[7] *ADC/AIN[7]  AC/AIN[3]  PTC/Y[5]  SERCOM0_ALT/PAD[3]  TCC1/WO[1]  I2S/SD[0]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA,  6, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel6, PWM1_CH0, TCC1_CH0, EXTERNAL_INT_6 }, // ADC/AIN[6]
  { PORTA,  7, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel7, PWM1_CH1, TCC1_CH1, EXTERNAL_INT_7 }, // ADC/AIN[7], if R332 is not soldered, this signal is used for USB VBUS

/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Wire             |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 14         | SCL              |  PA17  | EXTx_11         | EIC/EXTINT[1]  PTC/X[5] *SERCOM1/PAD[1]  SERCOM3_ALT/PAD[1]  TCC2/WO[1]  TCC0/WO[7]  GCLK_IO[3]
 * | 15         | SDA              |  PA16  | EXTx_12         | EIC/EXTINT[0]  PTC/X[4] *SERCOM1/PAD[0]  SERCOM3_ALT/PAD[0]  TCC2/WO[0]  TCC0_ALT/WO[6]  GCLK_IO[2]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA, 17, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, PWM2_CH1, TCC2_CH1, EXTERNAL_INT_1 }, // SCL:SERCOM1/PAD[1]
  { PORTA, 16, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, PWM2_CH0, TCC2_CH0, EXTERNAL_INT_0 }, // SDA:SERCOM1/PAD[0]

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | SPI              |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 16         |                  |  PB22  | MOSI/EXT1_16    | EIC/EXTINT[6]                        *SERCOM5_ALT/PAD[2]  TC7/WO[0]  GCLK_IO[0]
 * | 17         |                  |  PB02  | MISO/EXT1_17    | EIC/EXTINT[2]  ADC/AIN[10]  PTC/Y[8] *SERCOM5_ALT/PAD[0]  TC6/WO[0]
 * | 18         |                  |  PB23  | SCK/EXT1_18     | EIC/EXTINT[7]                        *SERCOM5_ALT/PAD[3]  TC7/WO[1]  GCLK_IO[1]
 * | 19         |                  |  PB03  | SS_A/EXT1_15    | EIC/EXTINT[3]  ADC/AIN[11]  PTC/Y[9] *SERCOM5_ALT/PAD[1]
 * | 20         |                  |  PA23  | SS_B/EXT1_10    | EIC/EXTINT[7]  PTC/X[11]  SERCOM3/PAD[1]  SERCOM5_ALT/PAD[1]  TC4/WO[1]  TCC0_ALT/WO[5]
 * | 21         |                  |  PA14  | SS_A/EXT3_15    | EIC/EXTINT[14]  SERCOM2/PAD[2]  TC3/WO[0]  FECTRL[4]  GCLK_IO[0]
 * | 22         |                  |  PA08  | SS_B/EXT3_10    | EIC/NMI  ADC/AIN[16]  PTC/X[0]  SERCOM0/PAD[0]  SERCOM2_ALT/PAD[0]  TCC0/WO[0]  FECTRL[0]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB, 22, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, PWM7_CH0, TC7_CH0, EXTERNAL_INT_6 }, // SERCOM5_ALT/PAD[2]
  { PORTB,  2, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, PWM6_CH0, TC6_CH0, EXTERNAL_INT_2 }, // SERCOM5_ALT/PAD[0]
  { PORTB, 23, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, PWM7_CH1, TC7_CH1, EXTERNAL_INT_7 }, // SERCOM5_ALT/PAD[3]
  { PORTB,  3, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, ADC_Channel11, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, // SERCOM5_ALT/PAD[1]
  { PORTA, 23, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 }, // GPIO for alternate SPI/SS
  { PORTA, 14, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // GPIO for SPI/SS on EXT3
  { PORTA,  8, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel16, PWM0_CH0, TCC0_CH0, EXTERNAL_INT_NMI }, // GPIO for alternate SPI/SS

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | ATRF233          |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 23         |                  |  PB30  | MOSI            | SERCOM4/PAD[2]
 * | 24         |                  |  PC19  | MISO            | SERCOM4/PAD[0]
 * | 25         |                  |  PC18  | SCK             | SERCOM4/PAD[3]
 * | 26         |                  |  PB31  | SS              | SERCOM4/PAD[1]
 * | 27         |                  |  PC16  | CLKM            | GCLK/IO[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB, 30, PIO_TIMER_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SERCOM4_ALT/PAD[2]
  { PORTC, 19, PIO_TIMER_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SERCOM4_ALT/PAD[0]
  { PORTC, 18, PIO_TIMER_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SERCOM4_ALT/PAD[3]
  { PORTB, 31, PIO_TIMER_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SERCOM4_ALT/PAD[1]
  { PORTC, 16, PIO_TIMER_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // GCLK/IO[1]

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | USB              |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 28         |                  |  PA25  | USB_POSITIVE    | *USB/DP
 * | 29         |                  |  PA24  | USB_NEGATIVE    | *USB/DM
 * | 30         |                  |  PA07  | USB_HOST_ENABLE | USB/VBUS
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DP
  { PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DM
  { PORTA,  7, PIO_DIGITAL, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/VBUS
} ;

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5 } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ; // Serial/EDBG
SERCOM sercom1( SERCOM1 ) ; // Wire
SERCOM sercom4( SERCOM4 ) ; // ATRF233/802.15.4
SERCOM sercom5( SERCOM5 ) ; // SPI

Uart Serial( &sercom0, PIN_SERIAL_RX, PIN_SERIAL_TX, PAD_SERIAL_RX, PAD_SERIAL_TX ) ;

void SERCOM0_Handler(void)
{
  Serial.IrqHandler();
}
