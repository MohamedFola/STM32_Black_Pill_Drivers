/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : MCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : RCC                                  */
/*************************************************************/
/*************************************************************/

#ifndef _RCC_INTERFACE_H_
#define _RCC_INTERFACE_H_


typedef enum
{
	RCC_GPIOA        ,
	RCC_GPIOB        ,
	RCC_GPIOC        ,
	RCC_GPIOD        ,
	RCC_GPIOE        ,
	RCC_GPIOH   = 7  ,
	RCC_CRC     = 12 ,
	RCC_DMA1    = 21 ,
	RCC_DMA2         ,
	RCC_OTGFS   = 30 ,
	RCC_TIM2         ,
	RCC_TIM3         ,
	RCC_TIM4         ,
	RCC_TIM5         ,
	RCC_WWDG    = 42 ,
	RCC_SPI2    = 45 ,
	RCC_SPI3         ,
	RCC_USART2  = 48 ,
	RCC_I2C1    = 52 ,
	RCC_I2C2         ,
	RCC_I2C3         ,
	RCC_PWR     = 59 ,
	RCC_TIM1         ,
	RCC_USART1  = 64 ,
	RCC_USART6       ,
	RCC_ADC1    = 68 ,
	RCC_SDIO    = 71 ,
	RCC_SPI1         ,
	RCC_SPI4         ,
	RCC_SYSCFG       ,
	RCC_TIM9    = 76 ,
	RCC_TIM10        ,
	RCC_TIM11        ,
}Clock_Peripherals_t;



/********************************************
 * Name        : RCC_voidSystemClockEnable  *
 * Return type : void                       *
 * Arguments   : void                       *
 * description : Enables System Clock       *
 *******************************************/
void RCC_voidSystemClockEnable(void);


/************************************************************************
 * Name        : RCC_voidPeripheralClockEnable                          *
 * Return type : void                                                   *
 * Arguments   : Copy_u8PerphiralName --> u8                            *
 * description : Enables Clock for a certain Peripheral                 *
 ***********************************************************************/
void RCC_voidPeripheralClockEnable(u8 Copy_PeripheralName);


/************************************************************************
 * Name        : RCC_voidPeripheralClockDisable                         *
 * Return type : void                                                   *
 * Arguments   : Copy_u8PerphiralName                                   *
 * description : Disables Clock for a certain Peripheral                *
 ***********************************************************************/
void RCC_voidPeripheralClockDisable(u8 Copy_PeripheralName);


/************************************************************************
 * Name        : RCC_voidPeripheralReset                                *
 * Return type : void                                                   *
 * Arguments   : Copy_u8PerphiralName                                   *
 * description : Resets a certain Peripheral                            *
 ***********************************************************************/
void RCC_voidPeripheralReset(u8 Copy_PeripheralName);


#endif /* RCC_INTERFACE_H_ */
