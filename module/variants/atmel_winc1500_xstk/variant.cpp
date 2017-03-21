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
 * | 0          |                  |  PB09  | EXT1_13         | EIC/EXTINT[9] ADC/AIN[3] PTC/Y[15] *SERCOM4_ALT/PAD[1] TC4/WO[1]
 * | 1          |                  |  PB08  | EXT1_14         | EIC/EXTINT[8] ADC/AIN[2] PTC/Y[14] *SERCOM4_ALT/PAD[0] TC4/WO[0]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB,  9, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 }, // RX: SERCOM4/PAD[1]
  { PORTB,  8, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 }, // TX: SERCOM4/PAD[0]

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | LEDs & button    |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 2          | N/A              |  PB30  | LED0            | EXTINT[14] SERCOM5/PAD[0]                TCC0/WO[0] TCC1/WO[2]
 * | 3          | N/A              |  PA15  | SW0             | EXTINT[15] SERCOM2/PAD[3] SERCOM4/PAD[3] TC3/WO[1]  TCC0/WO[5] GCLK_IO[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB, 30, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), No_ADC_Channel, PWM2_CH1, NOT_ON_TIMER, EXTERNAL_INT_14 }, // TCC0/WO[0]
  { PORTA, 15, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15 },

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Digital          |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 4          |                  |  PB06  | EXT1_5          | EIC/EXTINT[6]  ADC/AIN[14]  PTC/Y[12]
 * | 5          |                  |  PB07  | EXT1_6          | EIC/EXTINT[7]  ADC/AIN[15]  PTC/Y[13
 * | 6          |                  |  PB04  | EXT1_9          | EIC/EXTINT[4]  ADC/AIN[12]  PTC/Y[10]
 * | 7          |                  |  PB05  | EXT1_10         | EIC/EXTINT[5]  ADC/AIN[13]  PTC/Y[11]
 * | 8          |                  |  PA20  | EXT2_5          | EIC/EXTINT[4]  PTC/X[8]  SERCOM5/PAD[2]  SERCOM3_ALT/PAD[2]  TC7/WO[0]  TCC0_ALT/WO[6]  I2S/SCK[0]  GCLK_IO[4]
 * | 9          |                  |  PA21  | EXT2_6          | EIC/EXTINT[5]  PTC/X[9]  SERCOM5/PAD[3]  SERCOM3_ALT/PAD[3]  TC7/WO[1]  TCC0_ALT/WO[7]  I2S/FS[0]  GCLK_IO[5]
 * | 10         |                  |  PB14  | EXT2_9          | EIC/EXTINT[14]  PTC/X[14]  SERCOM4/PAD[2]  TC5/WO[0]  GCLK_IO[0]
 * | 11         |                  |  PB15  | EXT2_10         | EIC/EXTINT[15]  PTC/X[15]  SERCOM4/PAD[3]  TC5/WO[1]  GCLK_IO[1]
 * | 12         |                  |  PB30  | EXT3_5          | EIC/EXTINT[14]  SERCOM5_ALT/PAD[0]  TCC0/WO[0]  TCC1_ALT/WO[2]
 * | 13         |                  |  PA15  | EXT3_6          | EIC/EXTINT[15]  SERCOM2/PAD[3]  SERCOM4_ALT/PAD[3]  TC3/WO[1]  TCC0_ALT/WO[5]  GCLK_IO[1]
 * | 14         |                  |  PA28  | EXT3_9          | EIC/EXTINT[8]  GCLK_IO[0]
 * | 15         |                  |  PA27  | EXT3_10         | EIC/EXTINT[15]  GCLK_IO[0]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB,  6, PIO_DIGITAL, PIN_ATTR_DIGITAL, ADC_Channel14, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 },
  { PORTB,  7, PIO_DIGITAL, PIN_ATTR_DIGITAL, ADC_Channel15, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 },
  { PORTB,  4, PIO_DIGITAL, PIN_ATTR_DIGITAL, ADC_Channel12, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4 },
  { PORTB,  5, PIO_DIGITAL, PIN_ATTR_DIGITAL, ADC_Channel13, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 },
  { PORTA, 20, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM7_CH0, TC7_CH0, EXTERNAL_INT_4 },
  { PORTA, 21, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM7_CH1, TC7_CH1, EXTERNAL_INT_5 },
  { PORTB, 14, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM5_CH0, TC5_CH0, EXTERNAL_INT_14 },
  { PORTB, 15, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM5_CH1, TC5_CH1, EXTERNAL_INT_15 },
  { PORTB, 30, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH0, TCC0_CH0, EXTERNAL_INT_14 },
  { PORTA, 15, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH1, TC3_CH1, EXTERNAL_INT_15 },
  { PORTA, 28, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 },
  { PORTA, 27, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15 },

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Digital/PWM      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 16         | PWM+             |  PB02  | EXT1_7          | EIC/EXTINT[2]  ADC/AIN[10]  PTC/Y[8]  SERCOM5_ALT/PAD[0] *TC6/WO[0]
 * | 17         | PWM-             |  PB03  | EXT1_8          | EIC/EXTINT[3]  ADC/AIN[11]  PTC/Y[9]  SERCOM5_ALT/PAD[1] *TC6/WO[1]
 * | 18         | PWM+             |  PB12  | EXT2_7          | EIC/EXTINT[12]              PTC/X[12]  SERCOM4/PAD[0] *TC4/WO[0]  TCC0_ALT/WO[6]  I2S/FS[1]  GCLK_IO[6]
 * | 19         | PWM-             |  PB13  | EXT2_8          | EIC/EXTINT[13]              PTC/X[13]  SERCOM4/PAD[1] *TC4/WO[1]  TCC0_ALT/WO[7]             GCLK_IO[7]
 * | 20         | PWM+             |  PA12  | EXT3_7          | EIC/EXTINT[12]                         SERCOM2/PAD[0]  SERCOM4_ALT/PAD[0] *TCC2/WO[0]  TCC0_ALT/WO[6]  AC/CMP[0]
 * | 21         | PWM-             |  PA13  | EXT3_8          | EIC/EXTINT[13]  SERCOM2/PAD[1]  SERCOM4_ALT/PAD[1] *TCC2/WO[1]  TCC0_ALT/WO[7]  AC/CMP[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB,  2, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel10, PWM6_CH0, TC6_CH0, EXTERNAL_INT_2 }, // TC6/WO[0]
  { PORTB,  3, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel11, PWM6_CH1, TC6_CH1, EXTERNAL_INT_3 }, // TC6/WO[1]
  { PORTB, 12, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM4_CH0, TC4_CH0, EXTERNAL_INT_12 }, // TC4/WO[0]
  { PORTB, 13, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM4_CH1, TC4_CH1, EXTERNAL_INT_13 }, // TC4/WO[1]
  { PORTA, 12, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM2_CH0, TCC2_CH0, EXTERNAL_INT_12 }, // TCC2/WO[0]
  { PORTA, 13, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM2_CH1, TCC2_CH1, EXTERNAL_INT_13 }, // TCC2/WO[1]

/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Analog pins      |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 22         |                  |  PB00  | A0/EXT1_3       | EIC/EXTINT[0]                   *ADC/AIN[8]            PTC/Y[6]                  SERCOM5_ALT/PAD[2]  TC7/WO[0]
 * | 23         |                  |  PB01  | A1/EXT1_4       | EIC/EXTINT[1]                   *ADC/AIN[9]            PTC/Y[7]                  SERCOM5_ALT/PAD[3]  TC7/WO[1]
 * | 24         |                  |  PA10  | A2/EXT2_3       | EIC/EXTINT[10]                  *ADC/AIN[18]           PTC/X[2]  SERCOM0/PAD[2]                      TCC0/WO[2]  TCC1_ALT/WO[0]
 * | 25         |                  |  PA11  | A3/EXT2_4       | EIC/EXTINT[11]                  *ADC/AIN[19]           PTC/X[3]  SERCOM0/PAD[3]  SERCOM2_ALT/PAD[3]  TCC0/WO[3]  TCC1_ALT/WO[1]
 * | 26         |                  |  PA02  | A4/EXT3_3       | EIC/EXTINT[2]                   *ADC/AIN[0]  DAC/VOUT  PTC/Y[0]
 * | 27         |                  |  PA03  | A5/EXT3_4       | EIC/EXTINT[3]   [ADC|DAC]/VREFA *ADC/AIN[1]            PTC/Y[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB,  0, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel8, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_0 }, // ADC/AIN[8]
  { PORTB,  1, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel9, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1 }, // ADC/AIN[9]
  { PORTA, 10, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel18, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 }, // ADC/AIN[18]
  { PORTA, 11, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel19, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 }, // ADC/AIN[19]
  { PORTA,  2, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // ADC/AIN[0] and also DAC/VOUT
  { PORTA,  3, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel1, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, // ADC/AIN[1]

/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Serial           |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 28         |                  |  PA23  | EDBG/RX         | EIC/EXTINT[7]  PTC/X[11] *SERCOM3/PAD[1]  SERCOM5_ALT/PAD[1]  TC4/WO[1]  TCC0_ALT/WO[5]
 * | 29         |                  |  PA22  | EDBG/TX         | EIC/EXTINT[6]  PTC/X[10] *SERCOM3/PAD[0]  SERCOM5_ALT/PAD[0]  TC4/WO[0]  TCC0_ALT/WO[4]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA, 23, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // RX: SERCOM3/PAD[1]
  { PORTA, 22, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // TX: SERCOM3/PAD[0]

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Serial2          |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 30         |                  |  PB11  | EXT2_13/EXT3_13 | EIC/EXTINT[11] *SERCOM4/PAD[3]  TC5/WO[1]  TCC0/WO[5]  I2S/SCK[1]  GCLK_IO[5]
 * | 31         |                  |  PB10  | EXT2_14/EXT3_14 | EIC/EXTINT[10] *SERCOM4/PAD[2]  TC5/WO[0]  TCC0/WO[4]  I2S/MCK[1]  GCLK_IO[4]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB, 11, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 }, // RX: SERCOM4/PAD[3]
  { PORTB, 10, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 }, // TX: SERCOM4/PAD[2]

/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | Wire             |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 32         | SCL              |  PA09  | EXTx_11         | EIC/EXTINT[9]  ADC/AIN[17]  PTC/X[1]  SERCOM0/PAD[1] *SERCOM2_ALT/PAD[1]  TCC0/WO[1]  TCC1/WO[3]
 * | 33         | SDA              |  PA08  | EXTx_12         | EIC/NMI        ADC/AIN[16]  PTC/X[0]  SERCOM0/PAD[0] *SERCOM2_ALT/PAD[0]  TCC0/WO[0]  TCC1/WO[2]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA,  9, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, ADC_Channel17, PWM0_CH1, TCC0_CH1, EXTERNAL_INT_9 }, // SCL:SERCOM2_ALT/PAD[1]
  { PORTA,  8, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, ADC_Channel16, PWM0_CH0, TCC0_CH0, EXTERNAL_INT_NMI }, // SDA:SERCOM2_ALT/PAD[0]

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | SPI              |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 34         |                  |  PA06  | MOSI/EXT1_16    | EIC/EXTINT[6]             ADC/AIN[6]  AC/AIN[2]  PTC/Y[4] *SERCOM0_ALT/PAD[2]  TCC1/WO[0]
 * | 35         |                  |  PA04  | MISO/EXT1_17    | EIC/EXTINT[4]  ADC/VREFB  ADC/AIN[4]  AC/AIN[0]  PTC/Y[2] *SERCOM0_ALT/PAD[0]  TCC0/WO[0]
 * | 36         |                  |  PA07  | SCK/EXT1_18     | EIC/EXTINT[7]             ADC/AIN[7]  AC/AIN[3]  PTC/Y[5] *SERCOM0_ALT/PAD[3]  TCC1/WO[1]  I2S/SD[0]
 * | 37         |                  |  PA05  | SS_A/EXT1_15    | EIC/EXTINT[5]             ADC/AIN[5]  AC/AIN[1]  PTC/Y[3] *SERCOM0_ALT/PAD[1]  TCC0/WO[1]
 * | 38         |                  |  PB05  | SS_B/EXT1_10    | EIC/EXTINT[5]             ADC/AIN[13]            PTC/Y[11]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA,  6, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel6, PWM1_CH0, TCC1_CH0, EXTERNAL_INT_6 }, // SERCOM0_ALT/PAD[2]
  { PORTA,  4, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel4, PWM0_CH0, TCC0_CH0, EXTERNAL_INT_4 }, // SERCOM0_ALT/PAD[0]
  { PORTA,  7, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel7, PWM1_CH1, TCC1_CH1, EXTERNAL_INT_7 }, // SERCOM0_ALT/PAD[3]
  { PORTA,  5, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel5, PWM0_CH1, TCC0_CH1, EXTERNAL_INT_5 }, // SERCOM0_ALT/PAD[1]
  { PORTB,  5, PIO_DIGITAL, PIN_ATTR_DIGITAL, ADC_Channel13, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 }, // GPIO for alternate SPI/SS

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | SPI1             |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 39         |                  |  PA18  | MOSI/EXT2_16    | EIC/EXTINT[2]  PTC/X[6] *SERCOM1/PAD[2]  SERCOM3_ALT/PAD[2]  TC3/WO[0]  TCC0_ALT/WO[2]  AC/CMP[0]
 * | 40         |                  |  PA16  | MISO/EXT2_17    | EIC/EXTINT[0]  PTC/X[4] *SERCOM1/PAD[0]  SERCOM3_ALT/PAD[0]  TCC2/WO[0]  TCC0_ALT/WO[6]  GCLK_IO[2]
 * | 41         |                  |  PA19  | SCK/EXT2_18     | EIC/EXTINT[3]  PTC/X[7] *SERCOM1/PAD[3]  SERCOM3_ALT/PAD[3]  TC3/WO[1]  TCC0_ALT/WO[3]  I2S/SD[0]  AC/CMP[1]
 * | 42         |                  |  PA17  | SS_A/EXT2_15    | EIC/EXTINT[1]  PTC/X[5] *SERCOM1/PAD[1]  SERCOM3_ALT/PAD[1]  TCC2/WO[1]  TCC0/WO[7]  GCLK_IO[3]
 * | 43         |                  |  PB15  | SS_B/EXT2_10    | EIC/EXTINT[15]  PTC/X[15]  SERCOM4/PAD[3]  TC5/WO[1]  GCLK_IO[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA, 18, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH0, TC3_CH0, EXTERNAL_INT_2 }, // SERCOM1/PAD[2]
  { PORTA, 16, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM2_CH0, TCC2_CH0, EXTERNAL_INT_0 }, // SERCOM1/PAD[0]
  { PORTA, 19, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH1, TC3_CH1, EXTERNAL_INT_3 }, // SERCOM1/PAD[3]
  { PORTA, 17, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM2_CH1, TCC2_CH1, EXTERNAL_INT_1 }, // SERCOM1/PAD[1]
  { PORTB, 15, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM5_CH1, TC5_CH1, EXTERNAL_INT_15 }, // GPIO for alternate SPI/SS

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | SPI2             |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 44         |                  |  PB22  | MOSI/EXT3_16    | EIC/EXTINT[6]                 *SERCOM5_ALT/PAD[2]  TC7/WO[0]                             GCLK_IO[0]
 * | 45         |                  |  PB16  | MISO/EXT3_17    | EIC/EXTINT[0] *SERCOM5/PAD[0]                      TC6/WO[0]  TCC0_ALT/WO[4]  I2S/SD[1]  GCLK_IO[2]
 * | 46         |                  |  PB23  | SCK/EXT3_18     | EIC/EXTINT[7]                 *SERCOM5_ALT/PAD[3]  TC7/WO[1]                             GCLK_IO[1]
 * | 47         |                  |  PB17  | SS_A/EXT3_15    | EIC/EXTINT[1] *SERCOM5/PAD[1]                      TC6/WO[1]  TCC0_ALT/WO[5]  I2S/MCK[0]  GCLK_IO[3]
 * | 48         |                  |  PA27  | SS_B/EXT3_10    | EIC/EXTINT[15]  GCLK_IO[0]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB, 22, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM7_CH0, TC7_CH0, EXTERNAL_INT_6 }, // SERCOM5_ALT/PAD[2]
  { PORTB, 16, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM6_CH0, TC6_CH0, EXTERNAL_INT_0 }, // SERCOM5/PAD[0]
  { PORTB, 23, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM7_CH1, TC7_CH1, EXTERNAL_INT_7 }, // SERCOM5_ALT/PAD[3]
  { PORTB, 17, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM6_CH1, TC6_CH1, EXTERNAL_INT_1 }, // SERCOM5/PAD[1]
  { PORTA, 27, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15 }, // GPIO for alternate SPI/SS

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Pin number | USB              |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 49         |                  |  PA25  | USB_POSITIVE    | *USB/DP
 * | 50         |                  |  PA24  | USB_NEGATIVE    | *USB/DM
 * | 51         |                  |  PA14  | USB_HOST_ENABLE | USB/VBUS
 * | 52         |                  |  PA03  | USB_ID          | USB/ID
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DP
  { PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DM
  { PORTA, 14, PIO_DIGITAL, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/VBUS
  { PORTA,  3, PIO_DIGITAL, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/ID
};

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5, TC6, TC7 } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;

Uart Serial( &sercom3, PIN_SERIAL_RX, PIN_SERIAL_TX, PAD_SERIAL_RX, PAD_SERIAL_TX ) ;

void SERCOM3_Handler(void)
{
  Serial.IrqHandler();
}

Uart Serial1( &sercom4, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;

void SERCOM4_Handler(void)
{
  Serial1.IrqHandler();
}

/*
Uart Serial2( &sercom4, PIN_SERIAL2_RX, PIN_SERIAL2_TX, PAD_SERIAL2_RX, PAD_SERIAL2_TX ) ;

void SERCOM4_Handler(void)
{
  Serial2.IrqHandler();
}
*/
