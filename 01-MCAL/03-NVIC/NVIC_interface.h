/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : MCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : NVIC                                 */
/*************************************************************/
/*************************************************************/

/*********************************************************************************************************************************
 * -NVIC --> Nested Vector Interrupt Controller                                                                                  *
 *                                                                                                                               *
 * -NVIC can manage up to 255 Interrupts                                                                                         *
 * 		- 15  Internal                                                                                                           *
 * 		- 240 External                                                                                                           *
 *                                                                                                                               *
 * -ARM is using a concept called NVIC Grouping.                                                                                 *
 * -NVIC Grouping:                                                                                                               *
 * 		-> you can by software group some peripherals to the same Priority called Group Priority                                 *
 * 		-> you can by software choose a sub-priority to each Peripheral inside a group                                           *
 *                                                                                                                               *
 * 	-Now each peripheral has 3 priorities --> Group Priority, Sub-Priority and HW priority                                       *
 *                                                                                                                               *
 * 	-WHAT IF??                                                                                                                   *
 * 		1) Two interrupts fired at the same time?                                                                                *
 * 			-> Interrupt with higher Group priority will execute first                                                           *
 * 			-> if they have the same group priority, the Interrupt with higher sub-priority will execute first                   *
 * 			-> if they have the same group and sub priorities, the Interrupt with higher HW priority will execute first          *
 *                                                                                                                               *
 * 		2) Interrupt fired while executing another Interrupt?                                                                    *
 * 			-> if both from the same group, NO NESTING                                                                           *
 * 			-> if both form different group and the late interrupt has higher group interrupt, it will execute first, NESTING    *
 *                                                                                                                               *
 * 		3) Interrupt is executing and another version of it is fired?                                                            *
 * 			-> NO SELF NESTING                                                                                                   *
 * 			-> the pending flag will set and the interrupt waits for active flag to be clear to execute the other interrupt      *
 *                                                                                                                               *
 * 		3) Interrupt is executing and another version of it is fired multiple times?                                             *
 * 			-> the processor will execute only one another interrupt, the remaining interrupt the processor will not             *
 * 			   feel their firing                                                                                                 *
 *                                                                                                                               *
 * 	- NVIC Features:                                                                                                             *
 * 		1) supports 255 ( 240 External and 15 Internal )                                                                         *
 * 		2) enable pin for each external interrupt                                                                                *
 * 		3) vector table based system with configurable SW priority                                                               *
 * 		4) support interrupt nesting by comparing group concept                                                                  *
 * 		5) software set for each pending flag for testing                                                                        *
 * 		6) NVIC manage all 255 interrupts but control only the 240 external interrupt                                            *
 * 		7) each interrupt has two flags                                                                                          *
 * 		   ----------------------------------------------------------------                                                      *
 * 		  | Pending Flag  |  Active Flag |            Action               |                                                     *
 * 		   ----------------------------------------------------------------                                                      *
 * 		  |      0        |       0      | No interrupt					   |                                                     *
 * 		   ----------------------------------------------------------------                                                      *
 * 		  |      1        |       0      | Interrupt happened but not      |                                                     *
 * 		  |               |              | executed yet, can be waiting    |                                                     *
 * 		  |               |				 |  for another interrupt or       |                                                     *
 * 		  |               |				 |  the NVIC is disabled for this  |                                                     *
 * 		  |               |				 |  interrupt 				       |                                                     *
 * 		   ----------------------------------------------------------------                                                      *
 * 		  |      0        |       1      | Interrupt fired and executed    |                                                     *
 * 		   ----------------------------------------------------------------                                                      *
 * 		  |      1        |       1      | Interrupt is executing and      |                                                     *
 * 		  |               |              |  another version of it is       |                                                     *
 * 		  |               |              |  fired					       |                                                     *
 * 		   ----------------------------------------------------------------                                                      *
 *********************************************************************************************************************************/

#ifndef _NVIC_INTERFACE_H_
#define _NVIC_INTERFACE_H_


typedef enum
{
	NVIC_WWDG                      ,
	NVIC_EXTI16_PVD                ,
	NVIC_EXTI21_TAMP_STAMP         ,
	NVIC_EXTI22_RTC_WKUP           ,
	NVIC_FLASH                     ,
	NVIC_RCC                       ,
	NVIC_EXTI0                     ,
	NVIC_EXTI1                     ,
	NVIC_EXTI2                     ,
	NVIC_EXTI3                     ,
	NVIC_EXTI4                     ,
	NVIC_DMA1_Stream0              ,
	NVIC_DMA1_Stream1              ,
	NVIC_DMA1_Stream2              ,
	NVIC_DMA1_Stream3              ,
	NVIC_DMA1_Stream4              ,
	NVIC_DMA1_Stream5              ,
	NVIC_DMA1_Stream6              ,
	NVIC_ADC                       ,
	NVIC_EXTI9_5             = 23  ,
	NVIC_TIM1_BRK_TIM9             ,
	NVIC_TIM1_UP_TIM10             ,
	NVIC_TIM1_TRG_COM_TIM11        ,
	NVIC_TIM1_CC                   ,
	NVIC_TIM2                      ,
	NVIC_TIM3                      ,
	NVIC_TIM4                      ,
	NVIC_I2C1_EV                   ,
	NVIC_I2C1_ER                   ,
	NVIC_I2C2_EV                   ,
	NVIC_I2C2_ER                   ,
	NVIC_SPI1                      ,
	NVIC_SPI2                      ,
	NVIC_USART1                    ,
	NVIC_USART2                    ,
	NVIC_EXTI15_10           = 40  ,
	NVIC_EXTI17_RTC_Alarm          ,
	NVIC_EXTI18_OTG_FS_WKUP        ,
	NVIC_DMA1_Stream7              ,
	NVIC_SDIO                = 49  ,
	NVIC_TIM5                      ,
	NVIC_SPI3                      ,
	NVIC_DMA2_Stream0        = 56  ,
	NVIC_DMA2_Stream1              ,
	NVIC_DMA2_Stream2              ,
	NVIC_DMA2_Stream3              ,
	NVIC_DMA2_Stream4              ,
	NVIC_OTG_FS              = 67  ,
	NVIC_DMA2_Stream5              ,
	NVIC_DMA2_Stream6              ,
	NVIC_DMA2_Stream7              ,
	NVIC_USART6                    ,
	NVIC_I2C3_EV                   ,
	NVIC_I2C3_ER                   ,
	NVIC_FPU                 = 81  ,
	NVIC_SPI4                = 84  ,
}NVIC_Table_t;



/*********************************************************************
 * Name        : NVIC_voidInit              						 *
 * Return type : void                       						 *
 * Arguments   : void                       						 *
 * Description : Sets the Priority Model for group & sub-priorities  *
 *********************************************************************/
void NVIC_voidInit ( void );


/*********************************************************************
 * Name        : NVIC_voidSetPriority	             				 *
 * Return type : void                       						 *
 * Arguments   : Copy_u8InterruptPosition  --> u8                    *
 * 				 Copy_u8GroupPriority 	   --> u8                  	 *
 * 				 Copy_u8SubPriority 	   --> u8  					 *
 * Description : Sets the priority for a specific interrupt		     *
 *********************************************************************/
void NVIC_voidSetPriority ( u8 Copy_u8InterruptPosition, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority );


/*********************************************************************
 * Name        : NVIC_voidEnableInterrupt              				 *
 * Return type : void                       						 *
 * Arguments   : Copy_u8InterruptPosition --> u8                   	 *
 * Description : Sets the NVIC enable pin for a specific interrupt   *
 *********************************************************************/
void NVIC_voidEnableInterrupt ( u8 Copy_u8InterruptPosition );


/*********************************************************************
 * Name        : NVIC_voidDisableInterrupt             				 *
 * Return type : void                       						 *
 * Arguments   : Copy_u8InterruptPosition --> u8                   	 *
 * Description : Sets the NVIC disable pin for a specific interrupt  *
 *********************************************************************/
void NVIC_voidDisableInterrupt ( u8 Copy_u8InterruptPosition );


/*********************************************************************
 * Name        : NVIC_voidSetPendingFlag             				 *
 * Return type : void                       						 *
 * Arguments   : Copy_u8InterruptPosition --> u8                   	 *
 * Description : Sets the NVIC enable pin for a specific interrupt   *
 *********************************************************************/
void NVIC_voidSetPendingFlag ( u8 Copy_u8InterruptPosition );


/*********************************************************************
 * Name        : NVIC_voidClearPendingFlag             				 *
 * Return type : void                       						 *
 * Arguments   : Copy_u8InterruptPosition --> u8                   	 *
 * Description : Sets the NVIC disable pin for a specific interrupt  *
 *********************************************************************/
void NVIC_voidClearPendingFlag ( u8 Copy_u8InterruptPosition );


/*********************************************************************
 * Name        : NVIC_u8GetActiveFlag                				 *
 * Return type : u8                       				  			 *
 * Arguments   : Copy_u8InterruptPosition --> u8                   	 *
 * Description : Gets the active flag for a specific interrupt 		 *
 *********************************************************************/
u8 NVIC_u8GetActiveFlag ( u8 Copy_u8InterruptPosition );


#endif /* 0_NVIC_INTERFACE_H_ */
