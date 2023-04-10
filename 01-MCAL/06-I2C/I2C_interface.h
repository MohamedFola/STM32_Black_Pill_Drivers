/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : MCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : I2C                                  */
/*************************************************************/
/*************************************************************/
/*****************************************************************************************
                                                                                         *
                            |      |      |      |                                       *
                            ----------------------                                       *
1  :    VBAT              -|                      |-       3V3                  : 40     *
2  :    PC13              -|                      |-       GND                  : 39     *
3  :    PC14              -|                      |-       5V                   : 38     *
4  :    PC15              -|                      |-       PB9 --> SDA1(SDA2)   : 37     *
5  :    RST               -|                      |-       PB8 --> SCL1(SDA3)   : 36     *
6  :    PA0               -|      STM32F401       |-       PB7 --> SDA1         : 35     *
7  :    PA1               -|                      |-       PB6 --> SCL1         : 34     *
8  :    PA2               -|     Based on ARM     |-       PB5                  : 33     *
9  :    PA3               -|                      |-       PB4 --> SDA3         : 32     *
10 :    PA4               -|                      |-       PB3 --> SDA2         : 31     *
11 :    PA5               -|                      |-       PA15                 : 30     *
12 :    PA6               -|                      |-       PA12                 : 29     *
13 :    PA7               -|                      |-       PA11                 : 28     *
14 :    PB0               -|                      |-       PA10                 : 27     *
15 :    PB1               -|                      |-       PA9                  : 26     *
16 :    PB2               -|                      |-       PA8  --> SCL3        : 25     *
17 :    PB10 --> SCL2     -|                      |-       PB15                 : 24     *
18 :    3V3               -|                      |-       PB14                 : 23     *
19 :    GND               -|                      |-       PB13                 : 22     *
20 :    5V                -|                      |-       PB12                 : 21     *
                            ----------------------                                       *
                                                                                         *
******************************************************************************************/

#ifndef _I2C_INTERFACE_H_
#define _I2C_INTERFACE_H_

/**********************************/
/* Note the three I2C are on APB1 */
/**********************************/

#include "I2C_private.h"

typedef enum
{
	I2C1,
	I2C2,
	I2C3,
}I2C_t;


I2C_Errors_t I2C_Init ( I2C_t Copy_Number );

I2C_Errors_t I2C_Start ( I2C_t Copy_Number );

I2C_Errors_t I2C_Stop ( I2C_t Copy_Number );

I2C_Errors_t I2C_SendAddress (
		I2C_t Copy_Number    ,
		u8    Copy_u8Address
		);

I2C_Errors_t I2C_SendData (
		I2C_t Copy_Number      ,
		u8*   Copy_u8Data      ,
		u32   Copy_u32DataSize
		);

I2C_Errors_t I2C_Read (
		I2C_t Copy_Number   ,
		u8    Copy_u8Add    ,
		u8*   Copy_u8Buffer ,
		u32   Copy_u32Size
		);


#endif /* _I2C_INTERFACE_H_ */
