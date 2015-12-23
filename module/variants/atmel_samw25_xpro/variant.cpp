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
 * | Pin number | Serial1          |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 0          |                  |  PB11  | EXT1_13         | EIC/EXTINT[11] *SERCOM4/PAD[3]  TC5/WO[1]  TCC0/WO[5]  I2S/SCK[1]  GCLK_IO[5]
 * | 1          |                  |  PB10  | EXT1_14         | EIC/EXTINT[10] *SERCOM4/PAD[2]  TC5/WO[0]  TCC0/WO[4]  I2S/MCK[1]  GCLK_IO[4]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB, 11, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 }, // RX: SERCOM4/PAD[3]
  { PORTB, 10, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 }, // TX: SERCOM4/PAD[2]

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | LEDs & button    |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 2          | N/A              |  PA23  | LED0            | EIC/EXTINT[7]  PTC/X[11]  SERCOM3/PAD[1]  SERCOM5_ALT/PAD[1]  TC4/WO[1]  TCC0_ALT/WO[5]
 * | 3          | N/A              |  PB23  | SW0             | EIC/EXTINT[7]                             SERCOM5_ALT/PAD[3]                            GCLK_IO[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA, 23, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), No_ADC_Channel, PWM4_CH1, NOT_ON_TIMER, EXTERNAL_INT_14 }, // TC4/WO[1]
  { PORTB, 23, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1 },

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Digital          |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 4          |                  |  PB02  | EXT1_5          | EIC/EXTINT[2]  ADC/AIN[10]  PTC/Y[8]  SERCOM5_ALT/PAD[0]
 * | 5          |                  |  PB03  | EXT1_6          | EIC/EXTINT[3]  ADC/AIN[11]  PTC/Y[9]  SERCOM5_ALT/PAD[1]
 * | 6          |                  |  PA20  | EXT1_9          | EIC/EXTINT[4]  PTC/X[8]  SERCOM5/PAD[2]  SERCOM3_ALT/PAD[2]  TCC0_ALT/WO[6]  I2S/SCK[0]  GCLK_IO[4]
 * | 7          |                  |  PA21  | EXT1_10         | EIC/EXTINT[5]  PTC/X[9]  SERCOM5/PAD[3]  SERCOM3_ALT/PAD[3]  TCC0_ALT/WO[7]  I2S/FS[0]  GCLK_IO[5]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
*/
  { PORTB,  2, PIO_TIMER, PIN_ATTR_DIGITAL, ADC_Channel10, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 },
  { PORTB,  3, PIO_TIMER, PIN_ATTR_DIGITAL, ADC_Channel11, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 },
  { PORTA, 20, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH6, TCC0_CH6, EXTERNAL_INT_4 },
  { PORTA, 21, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH7, TCC0_CH7, EXTERNAL_INT_5 },

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Digital/PWM      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 8          | PWM+             |  PA10  | EXT1_7          | EIC/EXTINT[10]  ADC/AIN[18]  PTC/X[2]  SERCOM0/PAD[2]                     *TCC0/WO[2]  TCC1_ALT/WO[0]
 * | 9          | PWM-             |  PA11  | EXT1_8          | EIC/EXTINT[11]  ADC/AIN[19]  PTC/X[3]  SERCOM0/PAD[3]  SERCOM2_ALT/PAD[3] *TCC0/WO[3]  TCC1_ALT/WO[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
*/
  { PORTA, 10, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel18, PWM0_CH2, TCC0_CH2, EXTERNAL_INT_10 }, // TCC0/WO[2]
  { PORTA, 11, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel19, PWM0_CH3, TCC0_CH3, EXTERNAL_INT_11 }, // TCC0/WO[3]

/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Analog pins      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 10         |                  |  PA02  | A0/EXT1_3       | EIC/EXTINT[2]                   *ADC/AIN[0]  DAC/VOUT  PTC/Y[0]
 * | 11         |                  |  PA03  | A1/EXT1_4       | EIC/EXTINT[3]   [ADC|DAC]/VREFA *ADC/AIN[1]            PTC/Y[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA,  2, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // ADC/AIN[0] and also DAC/VOUT
  { PORTA,  3, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel1, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, // ADC/AIN[1]

/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Serial           |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 12         |                  |  PB11  | EDBG_RX/EXT1_13 | EIC/EXTINT[11] *SERCOM4_ALT/PAD[3]  TC5/WO[1]  TCC0/WO[5]  I2S/SCK[1]  GCLK_IO[5]
 * | 13         |                  |  PB10  | EDBG_TX/EXT1_14 | EIC/EXTINT[10] *SERCOM4_ALT/PAD[2]  TC5/WO[0]  TCC0/WO[4]  I2S/MCK[1]  GCLK_IO[4]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB, 11, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 }, // RX: SERCOM4/PAD[3]
  { PORTB, 10, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 }, // TX: SERCOM4/PAD[2]

/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Wire             |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 14         | SCL              |  PA09  | EXT1_11         | EIC/EXTINT[9]  ADC/AIN[17]  PTC/X[1] *SERCOM0/PAD[1]  SERCOM2_ALT/PAD[1]  TCC0/WO[1]  TCC1/WO[3]
 * | 15         | SDA              |  PA08  | EXT1_12         | EIC/NMI        ADC/AIN[16]  PTC/X[0] *SERCOM0/PAD[0]  SERCOM2_ALT/PAD[0]  TCC0/WO[0]  TCC1/WO[2]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA,  9, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, ADC_Channel17, PWM0_CH1, TCC0_CH1, EXTERNAL_INT_9 }, // SCL:SERCOM0/PAD[1]
  { PORTA,  8, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, ADC_Channel16, PWM0_CH0, TCC0_CH0, EXTERNAL_INT_NMI }, // SDA:SERCOM0/PAD[0]

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | SPI              |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 16         |                  |  PA18  | MOSI/EXT1_16    | EIC/EXTINT[2]  PTC/X[6] *SERCOM1/PAD[2]  SERCOM3_ALT/PAD[2]  TC3/WO[0]  TCC0_ALT/WO[2]  AC/CMP[0]
 * | 17         |                  |  PA16  | MISO/EXT1_17    | EIC/EXTINT[0]  PTC/X[4] *SERCOM1/PAD[0]  SERCOM3_ALT/PAD[0]  TCC2/WO[0]  TCC0_ALT/WO[6]  GCLK_IO[2]
 * | 18         |                  |  PA19  | SCK/EXT1_18     | EIC/EXTINT[3]  PTC/X[7] *SERCOM1/PAD[3]  SERCOM3_ALT/PAD[3]  TC3/WO[1]  TCC0_ALT/WO[3]  I2S/SD[0]  AC/CMP[1]
 * | 19         |                  |  PA17  | SS_A/EXT1_15    | EIC/EXTINT[1]  PTC/X[5] *SERCOM1/PAD[1]  SERCOM3_ALT/PAD[1]  TCC2/WO[1]  TCC0/WO[7]  GCLK_IO[3]
 * | 20         |                  |  PA21  | SS_B/EXT1_10    | EIC/EXTINT[5]  PTC/X[9]  SERCOM5/PAD[3]  SERCOM3_ALT/PAD[3]  TCC0_ALT/WO[7]  I2S/FS[0]  GCLK_IO[5]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA, 18, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH0, TC3_CH0, EXTERNAL_INT_2 }, // SERCOM1/PAD[2]
  { PORTA, 16, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM2_CH0, TCC2_CH0, EXTERNAL_INT_0 }, // SERCOM1/PAD[0]
  { PORTA, 19, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH1, TC3_CH1, EXTERNAL_INT_3 }, // SERCOM1/PAD[3]
  { PORTA, 17, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM2_CH1, TCC2_CH1, EXTERNAL_INT_1 }, // SERCOM1/PAD[1]
  { PORTA, 21, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 }, // GPIO for alternate SPI/SS

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | WINC1500/SPI1    |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 21         |                  |  PA12  | MOSI            | SERCOM2/PAD[0]
 * | 22         |                  |  PA15  | MISO            | SERCOM2/PAD[3]
 * | 23         |                  |  PA13  | SCK             | SERCOM2/PAD[1]
 * | 24         |                  |  PA14  | SS              | SERCOM2/PAD[2]
 * | 25         |                  |  PB09  | IRQN            | EIC/EXTINT[9] (or digital input?)
 * | 26         |                  |  PB08  | WAKE            | (digital output)
 * | 27         |                  |  PA27  | RESET           | (digital output)
 * | 28         |                  |  PA28  | CHIP_EN         | (digital output)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA, 12, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SERCOM2/PAD[0]
  { PORTA, 15, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SERCOM2/PAD[3]
  { PORTA, 13, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SERCOM2/PAD[1]
  { PORTA, 14, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SERCOM2/PAD[2]
  { PORTB,  9, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9 }, // IRQN
  { PORTB,  8, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // WAKE
  { PORTA, 27, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // RESET
  { PORTA, 28, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // CHIP_EN

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | USB              |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 30         |                  |  PA25  | USB_POSITIVE    | *USB/DP
 * | 31         |                  |  PA24  | USB_NEGATIVE    | *USB/DM
 * | 32         |                  |  PA05  | USB_HOST_ENABLE | USB/VBUS
 * | 33         |                  |  PA04  | USB_ID          | USB/ID
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
*/
  { PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DP
  { PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DM
  { PORTA,  5, PIO_DIGITAL, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/VBUS
  { PORTA,  4, PIO_DIGITAL, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/ID
} ;

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5 } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
//SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
//SERCOM sercom5( SERCOM5 ) ;

Uart Serial( &sercom4, PIN_SERIAL_RX, PIN_SERIAL_TX, PAD_SERIAL_RX, PAD_SERIAL_TX ) ;

void SERCOM4_Handler(void)
{
  Serial.IrqHandler();
}

//SPIClass WINC1500(&PERIPH_WINC1500, PIN_WINC1500_MISO, PIN_WINC1500_SCK, PIN_WINC1500_MOSI, PAD_WINC1500_TX, PAD_WINC1500_RX);
