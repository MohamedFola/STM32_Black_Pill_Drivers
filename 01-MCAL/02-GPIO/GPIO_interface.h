/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : MCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : GPIO                                 */
/*************************************************************/
/*************************************************************/

#ifndef _GPIO_INTERFACE_H_
#define _GPIO_INTERFACE_H_


typedef enum
{
	GPIOx_PIN_LOW            ,
	GPIOx_PIN_HIGH           ,
	GPIOx_PORT_LOW  = 0x0000 ,
	GPIOx_PORT_HIGH = 0xFFFF ,
}GPIOxVALUES_t;

typedef enum
{
	GPIOx_PORTA ,
	GPIOx_PORTB ,
	GPIOx_PORTC ,
}GPIOxPORTs_t;

typedef enum
{
	GPIOA_PIN0  	 , /* allowed pins for PORTA */
	GPIOA_PIN1  	 ,
	GPIOA_PIN2  	 ,
	GPIOA_PIN3  	 ,
	GPIOA_PIN4  	 ,
	GPIOA_PIN5  	 ,
	GPIOA_PIN6  	 ,
	GPIOA_PIN7  	 ,
	GPIOA_PIN8  	 ,
	GPIOA_PIN9  	 ,
	GPIOA_PIN10 	 ,
	GPIOA_PIN11 	 ,
	GPIOA_PIN12      ,
	GPIOA_PIN15	= 15 ,

	GPIOB_PIN0  = 0  , /* allowed pins for PORTB */
	GPIOB_PIN1       ,
	GPIOB_PIN2 		 ,
	GPIOB_PIN3       ,
	GPIOB_PIN4       ,
	GPIOB_PIN5       ,
	GPIOB_PIN6       ,
	GPIOB_PIN7       ,
	GPIOB_PIN8       ,
	GPIOB_PIN9       ,
	GPIOB_PIN10      ,
	GPIOB_PIN12 = 12 ,
	GPIOB_PIN13      ,
	GPIOB_PIN14      ,
	GPIOB_PIN15      ,

	GPIOC_PIN13 = 13 , /* allowed pins for PORTC */
	GPIOC_PIN14		 ,
	GPIOC_PIN15		 ,
}GPIOxPINs_t;


#define GPIO_PORTA   0
#define GPIO_PORTB   1
#define GPIO_PORTC   2

#define GPIO_PIN0    0
#define GPIO_PIN1    1
#define GPIO_PIN2    2
#define GPIO_PIN3    3
#define GPIO_PIN4    4
#define GPIO_PIN5    5
#define GPIO_PIN6    6
#define GPIO_PIN7    7
#define GPIO_PIN8    8
#define GPIO_PIN9    9
#define GPIO_PIN10   10
#define GPIO_PIN11   11
#define GPIO_PIN12   12
#define GPIO_PIN13   13
#define GPIO_PIN14   14
#define GPIO_PIN15   15



/***********************************************
 * Name        : GPIO_voidSetChannelValue      *
 * Return type : void                          *
 * Arguments   :                               *
 *			1 --> Copy_u8PortName , u8         *
 *			2 --> Copy_u8PinNumber, u8         *
 *			3 --> Copy_u8Value    , u8         *
 *											   *
 * Description : Set value for a certain pin   *
 **********************************************/
void GPIO_voidSetChannelValue (
		u8 Copy_u8PortName  ,
		u8 Copy_u8PinNumber ,
		u8 Copy_u8Value     );




/***********************************************
 * Name        : GPIO_voidSetPortValue         *
 * Return type : void                          *
 * Arguments   :                               *
 *			1 --> Copy_u8PortName, u8          *
 *			2 --> Copy_u8Value   , u16         *
 *											   *
 * Description : Set value for a certain port  *
 **********************************************/
void GPIO_voidSetPortValue (
		u8  Copy_u8PortName ,
		u16 Copy_u8Value    );




/**************************************************
 * Name        : GPIO_voidToggleChannelValue      *
 * Return type : void                             *
 * Arguments   :                                  *
 *			1 --> Copy_u8PortName , u8            *
 *			2 --> Copy_u8PinNumber, u8            *
 *											      *
 * Description : Toggle value for a certain port  *
 **************************************************/
void GPIO_voidToggleChannelValue (
		u8 Copy_u8PortName  ,
		u8 Copy_u8PinNumber );




/************************************************************
 * Name        : GPIO_voidSetChannelGroupValue              *
 * Return type : void                                       *
 * Arguments   :                                            *
 *			1 --> Copy_u8PortName     , u8                  *
 *			2 --> Copy_u8PinNumber    , u8                  *
 *			3 --> Copy_u8ChannelLength, u8                  *
 *			4 --> Copy_u8Value        , u16                 *
 *											                *
 * Description : Set value for a certain consecutive pins   *
 ***********************************************************/
void GPIO_voidSetChannelGroupValue (
		u8  Copy_u8PortName      ,
		u8  Copy_u8PinNumber     ,
		u8  Copy_u8ChannelLength ,
		u16 Copy_u8Value         );




/***********************************************
 * Name        : GPIO_u8GetChannelValue        *
 * Return type : u8                            *
 * Arguments   :                               *
 *			1 --> Copy_u8PortName , u8         *
 *			2 --> Copy_u8PinNumber, u8         *
 *			3 --> Ptr_u16Value    , u16*       *
 *											   *
 * Description : Get value from a certain pin  *
 **********************************************/
u8 GPIO_u8GetChannelValue (
		u8   Copy_u8PortName  ,
		u8   Copy_u8PinNumber ,
		u16* Ptr_u16Value     );


/************************************************************
 * Name        : GPIO_u8GetChannelGroupValue                *
 * Return type : void                                       *
 * Arguments   :                                            *
 *			1 --> Copy_u8PortName     , u8                  *
 *			2 --> Copy_u8PinNumber    , u8                  *
 *			3 --> Copy_u8ChannelLength, u8                  *
 *			4 --> Ptr_u16Value        , u16*                *
 *											                *
 * Description : Get value from a certain consecutive pins  *
 ***********************************************************/
u8 GPIO_u8GetChannelGroupValue (
		u8   Copy_u8PortName      ,
		u8   Copy_u8PinNumber     ,
		u8   Copy_u8ChannelLength ,
		u16* Ptr_u16Value         );


#endif /* _GPIO_INTERFACE_H_ */
