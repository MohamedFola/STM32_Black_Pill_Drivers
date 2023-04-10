/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : MCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : SPI                                  */
/*************************************************************/
/*************************************************************/
/*************************************************************************************************
                                                                                                 *
                                  |      |      |      |                                         *
                                  ----------------------                                         *
1  :    VBAT                    -|                      |-       3V3                    : 40     *
2  :    PC13                    -|                      |-       GND                    : 39     *
3  :    PC14                    -|                      |-       5V                     : 38     *
4  :    PC15                    -|                      |-       PB9  --> NSS           : 37     *
5  :    RST                     -|                      |-       PB8  --> MOSI5         : 36     *
6  :    PA0                     -|      STM32F401       |-       PB7                    : 35     *
7  :    PA1  --> MOSI4          -|                      |-       PB6                    : 34     *
8  :    PA2                     -|     Based on ARM     |-       PB5  --> MOSI1, MOSI3  : 33     *
9  :    PA3                     -|                      |-       PB4  --> MSIO1, MISO3  : 32     *
10 :    PA4  --> NSS1, NSS3     -|                      |-       PB3  --> SCK1, SCK3    : 31     *
11 :    PA5  --> SCK1           -|                      |-       PA15 --> NSS1, NSS3    : 30     *
12 :    PA6  --> MISO1          -|                      |-       PA12 --> MISO5         : 29     *
13 :    PA7  --> MOSI1          -|                      |-       PA11 --> MISO4         : 28     *
14 :    PB0  --> SCK5           -|                      |-       PA10 --> MOSI5         : 27     *
15 :    PB1  --> NSS5           -|                      |-       PA9                    : 26     *
16 :    PB2                     -|                      |-       PA8                    : 25     *
17 :    PB10 --> SCK2           -|                      |-       PB15 --> MOSI2         : 24     *
18 :    3V3                     -|                      |-       PB14 --> MISO2         : 23     *
19 :    GND                     -|                      |-       PB13 --> SCK2          : 22     *
20 :    5V                      -|                      |-       PB12 --> NSS2, NSS4    : 21     *
                                  ----------------------                                         *
                                                                                                 *
**************************************************************************************************/

#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_


/* SPI Errors */
typedef enum
{
	SPI_NoError          ,
	SPI_PointerError     ,
	SPI_ClkPhaseError    ,
	SPI_ClkPolarityError ,
	SPI_ClkRateError     ,
	SPI_DataOrderError   ,
	SPI_ModeError        ,
}SPI_Errors_t;


/* SPI used */
typedef enum
{
	SPI1,
	SPI2,
}SPI_Number_t;


typedef enum
{
	SPI_Slave  ,
	SPI_Master ,
}SPI_Mode_t;


/* Clock Phase Options */
typedef enum
{
	SPI_ClkPhase_LeadingEdge  ,
	SPI_ClkPhase_TrailingEdge ,
}SPI_Phase_t;


/* Clock Polarity Options */
typedef enum
{
	SPI_ClkPol_IdleLow  ,
	SPI_ClkPol_IdleHigh ,
}SPI_Polarity_t;


/* Clock Rate Options */
typedef enum
{
	SPI_ClkRateDiv2   ,
	SPI_ClkRateDiv4   ,
	SPI_ClkRateDiv8   ,
	SPI_ClkRateDiv16  ,
	SPI_ClkRateDiv32  ,
	SPI_ClkRateDiv64  ,
	SPI_ClkRateDiv128 ,
	SPI_ClkRateDiv256 ,
}SPI_CLkRate_t;


/* Data Order Options */
typedef enum
{
	SPI_MSBFirst,
	SPI_LSBFirst,
}SPI_DataOrder_t;




typedef struct
{
	SPI_Number_t    SPI_Number    ;
	SPI_Mode_t      SPI_Mode      ;
	SPI_Phase_t     SPI_Phase     ;
	SPI_Polarity_t  SPI_Polartity ;
	SPI_CLkRate_t   SPI_ClkRate   ;
	SPI_DataOrder_t SPI_DataOrder ;
}SPI_t;



SPI_Errors_t SPI_Init ( SPI_t* Ptr_SPI );

SPI_Errors_t SPI_u8SynchTransceive(
		SPI_Number_t Copy_SPI,
		u8* Ptr_u8DataSend,
		u8* Ptr_u8DataReceived,
		u32 Copy_u32Size
		);


#endif /* _SPI_INTERFACE_H_ */
