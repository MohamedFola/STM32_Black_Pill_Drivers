/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 1.00                      ************/
/************ SWC     : PORT                      ************/
/*************************************************************/
/*************************************************************/

#ifndef _PORT_CONFIG_H_
#define _PORT_CONFIG_H_

/*
	GPIO mode options:
		1) Input_Mode 
		2) General_Purpose_Output_Mode
		3) Alternate_Function_Mode
		4) Analog_Mode
*/
#define GPIOA_PIN0_MODE                       General_Purpose_Output_Mode
#define GPIOA_PIN1_MODE 		              General_Purpose_Output_Mode
#define GPIOA_PIN2_MODE 		              General_Purpose_Output_Mode
#define GPIOA_PIN3_MODE 		              General_Purpose_Output_Mode
#define GPIOA_PIN4_MODE 		              General_Purpose_Output_Mode
#define GPIOA_PIN5_MODE 		              General_Purpose_Output_Mode
#define GPIOA_PIN6_MODE 		              General_Purpose_Output_Mode
#define GPIOA_PIN7_MODE 		              General_Purpose_Output_Mode
#define GPIOA_PIN8_MODE 		              General_Purpose_Output_Mode
#define GPIOA_PIN9_MODE 		              General_Purpose_Output_Mode
#define GPIOA_PIN10_MODE 		              General_Purpose_Output_Mode
#define GPIOA_PIN11_MODE 		              General_Purpose_Output_Mode
#define GPIOA_PIN12_MODE 		              General_Purpose_Output_Mode
#define GPIOA_PIN15_MODE 		              General_Purpose_Output_Mode

#define GPIOB_PIN0_MODE 		              General_Purpose_Output_Mode
#define GPIOB_PIN1_MODE                       General_Purpose_Output_Mode
#define GPIOB_PIN2_MODE                       General_Purpose_Output_Mode
#define GPIOB_PIN5_MODE                       General_Purpose_Output_Mode
#define GPIOB_PIN6_MODE                       General_Purpose_Output_Mode
#define GPIOB_PIN7_MODE                       General_Purpose_Output_Mode
#define GPIOB_PIN8_MODE                       General_Purpose_Output_Mode
#define GPIOB_PIN9_MODE                       General_Purpose_Output_Mode
#define GPIOB_PIN10_MODE                      General_Purpose_Output_Mode
#define GPIOB_PIN11_MODE                      General_Purpose_Output_Mode
#define GPIOB_PIN12_MODE                      General_Purpose_Output_Mode
#define GPIOB_PIN13_MODE                      General_Purpose_Output_Mode
#define GPIOB_PIN14_MODE		              General_Purpose_Output_Mode
#define GPIOB_PIN15_MODE                      General_Purpose_Output_Mode

#define GPIOC_PIN13_MODE                      General_Purpose_Output_Mode
#define GPIOC_PIN14_MODE                      Input_Mode
#define GPIOC_PIN15_MODE                      Input_Mode


/*
	GPIO output type options:
		1) Output_Push_Pull
		2) Output_Open_Drain
*/
#define GPIOA_PIN0_Output_Type 		          Output_Push_Pull
#define GPIOA_PIN1_Output_Type                Output_Push_Pull
#define GPIOA_PIN2_Output_Type                Output_Push_Pull
#define GPIOA_PIN3_Output_Type                Output_Push_Pull
#define GPIOA_PIN4_Output_Type                Output_Push_Pull
#define GPIOA_PIN5_Output_Type                Output_Push_Pull
#define GPIOA_PIN6_Output_Type                Output_Push_Pull
#define GPIOA_PIN7_Output_Type                Output_Push_Pull
#define GPIOA_PIN8_Output_Type                Output_Push_Pull
#define GPIOA_PIN9_Output_Type                Output_Push_Pull
#define GPIOA_PIN10_Output_Type               Output_Push_Pull
#define GPIOA_PIN11_Output_Type               Output_Push_Pull
#define GPIOA_PIN12_Output_Type               Output_Push_Pull
#define GPIOA_PIN15_Output_Type               Output_Push_Pull

#define GPIOB_PIN0_Output_Type 		          Output_Push_Pull
#define GPIOB_PIN1_Output_Type                Output_Push_Pull
#define GPIOB_PIN2_Output_Type                Output_Push_Pull
#define GPIOB_PIN5_Output_Type                Output_Push_Pull
#define GPIOB_PIN6_Output_Type                Output_Push_Pull
#define GPIOB_PIN7_Output_Type                Output_Push_Pull
#define GPIOB_PIN8_Output_Type                Output_Push_Pull
#define GPIOB_PIN9_Output_Type                Output_Push_Pull
#define GPIOB_PIN10_Output_Type               Output_Push_Pull
#define GPIOB_PIN11_Output_Type               Output_Push_Pull
#define GPIOB_PIN12_Output_Type               Output_Push_Pull
#define GPIOB_PIN13_Output_Type               Output_Push_Pull
#define GPIOB_PIN14_Output_Type		          Output_Push_Pull
#define GPIOB_PIN15_Output_Type               Output_Push_Pull

#define GPIOC_PIN13_Output_Type               Output_Push_Pull
#define GPIOC_PIN14_Output_Type		          Output_Push_Pull
#define GPIOC_PIN15_Output_Type               Output_Push_Pull


/*
	GPIO output speed options:
		1) Low_Speed 
		2) Medium_Speed
		3) High_Speed
		4) Very_High_Speed
*/
#define GPIOA_PIN0_Speed                      Very_High_Speed
#define GPIOA_PIN1_Speed 		              Very_High_Speed
#define GPIOA_PIN2_Speed 		              Very_High_Speed
#define GPIOA_PIN3_Speed 		              Very_High_Speed
#define GPIOA_PIN4_Speed 		              Very_High_Speed
#define GPIOA_PIN5_Speed 		              Very_High_Speed
#define GPIOA_PIN6_Speed 		              Very_High_Speed
#define GPIOA_PIN7_Speed 		              Very_High_Speed
#define GPIOA_PIN8_Speed 		              Very_High_Speed
#define GPIOA_PIN9_Speed 		              Very_High_Speed
#define GPIOA_PIN10_Speed		              Very_High_Speed
#define GPIOA_PIN11_Speed		              Very_High_Speed
#define GPIOA_PIN12_Speed		              Very_High_Speed
#define GPIOA_PIN15_Speed		              Very_High_Speed

#define GPIOB_PIN0_Speed 	              	  Very_High_Speed
#define GPIOB_PIN1_Speed                      Very_High_Speed
#define GPIOB_PIN2_Speed                      Very_High_Speed
#define GPIOB_PIN5_Speed                      Very_High_Speed
#define GPIOB_PIN6_Speed                      Very_High_Speed
#define GPIOB_PIN7_Speed                      Very_High_Speed
#define GPIOB_PIN8_Speed                      Very_High_Speed
#define GPIOB_PIN9_Speed                      Very_High_Speed
#define GPIOB_PIN10_Speed                     Very_High_Speed
#define GPIOB_PIN11_Speed                     Very_High_Speed
#define GPIOB_PIN12_Speed                     Very_High_Speed
#define GPIOB_PIN13_Speed                     Very_High_Speed
#define GPIOB_PIN14_Speed	               	  Very_High_Speed
#define GPIOB_PIN15_Speed                     Very_High_Speed

#define GPIOC_PIN13_Speed                     Very_High_Speed
#define GPIOC_PIN14_Speed                     Very_High_Speed
#define GPIOC_PIN15_Speed                     Very_High_Speed


/*
	GPIO Pull_Up or Pull_Down options:
		1) No_Pull_Up_or_Down 
		2) Pull_Up            
		3) Pull_Down          
*/
#define GPIOA_PIN0_PU_PD                      No_Pull_Up_or_Down
#define GPIOA_PIN1_PU_PD 		              No_Pull_Up_or_Down
#define GPIOA_PIN2_PU_PD 		              No_Pull_Up_or_Down
#define GPIOA_PIN3_PU_PD 		              No_Pull_Up_or_Down
#define GPIOA_PIN4_PU_PD 		              No_Pull_Up_or_Down
#define GPIOA_PIN5_PU_PD 		              No_Pull_Up_or_Down
#define GPIOA_PIN6_PU_PD 		              No_Pull_Up_or_Down
#define GPIOA_PIN7_PU_PD 		              No_Pull_Up_or_Down
#define GPIOA_PIN8_PU_PD 		              No_Pull_Up_or_Down
#define GPIOA_PIN9_PU_PD 		              No_Pull_Up_or_Down
#define GPIOA_PIN10_PU_PD		              No_Pull_Up_or_Down
#define GPIOA_PIN11_PU_PD		              No_Pull_Up_or_Down
#define GPIOA_PIN12_PU_PD		              No_Pull_Up_or_Down
#define GPIOA_PIN15_PU_PD		              No_Pull_Up_or_Down

#define GPIOB_PIN0_PU_PD 	                  No_Pull_Up_or_Down
#define GPIOB_PIN1_PU_PD                      No_Pull_Up_or_Down
#define GPIOB_PIN2_PU_PD                      No_Pull_Up_or_Down
#define GPIOB_PIN5_PU_PD                      No_Pull_Up_or_Down
#define GPIOB_PIN6_PU_PD                      No_Pull_Up_or_Down
#define GPIOB_PIN7_PU_PD                      No_Pull_Up_or_Down
#define GPIOB_PIN8_PU_PD                      No_Pull_Up_or_Down
#define GPIOB_PIN9_PU_PD                      No_Pull_Up_or_Down
#define GPIOB_PIN10_PU_PD                     No_Pull_Up_or_Down
#define GPIOB_PIN11_PU_PD                     No_Pull_Up_or_Down
#define GPIOB_PIN12_PU_PD                     No_Pull_Up_or_Down
#define GPIOB_PIN13_PU_PD                     No_Pull_Up_or_Down
#define GPIOB_PIN14_PU_PD	                  No_Pull_Up_or_Down
#define GPIOB_PIN15_PU_PD                     No_Pull_Up_or_Down

#define GPIOC_PIN13_PU_PD                     Pull_Up
#define GPIOC_PIN14_PU_PD                     Pull_Up
#define GPIOC_PIN15_PU_PD                     Pull_Up



/*
	NOTE --> see to the MC pin-out to know the multiple function of each pin and choose one of them
	
	alternate functions options:
		1)  AF0            --> system
		2)  AF1            --> TIM1\TIM2
		3)  AF2            --> TIM3..5
		4)  AF3            --> TIM9..11
		5)  AF4            --> I2C1..3
		6)  AF5            --> SPI1..4
		7)  AF6            --> SPI3
		8)  AF7            --> USART1..2
		9)  AF8            --> USART6
		10) AF9            --> I2C2..3
		11) AF10           --> OTG_FS
		12) AF11           --> 
		13) AF12           --> SDIO
		14) AF13           --> 
		15) AF14           --> 
		16) AF15           --> EVENTOUT
*/
#define GPIOA_PIN0_AF                         AF11 
#define GPIOA_PIN1_AF		                  AF11
#define GPIOA_PIN2_AF		                  AF11
#define GPIOA_PIN3_AF		                  AF11
#define GPIOA_PIN4_AF		                  AF11
#define GPIOA_PIN5_AF		                  AF11
#define GPIOA_PIN6_AF		                  AF11
#define GPIOA_PIN7_AF		                  AF11  
#define GPIOA_PIN8_AF		                  AF11 
#define GPIOA_PIN9_AF		                  AF11 
#define GPIOA_PIN10_AF	                      AF11
#define GPIOA_PIN11_AF	                      AF11
#define GPIOA_PIN12_AF	                      AF11
#define GPIOA_PIN15_AF	                      AF11

#define GPIOB_PIN0_AF 	                      AF11
#define GPIOB_PIN1_AF                         AF11
#define GPIOB_PIN2_AF                         AF11
#define GPIOB_PIN5_AF                         AF11
#define GPIOB_PIN6_AF                         AF11
#define GPIOB_PIN7_AF                         AF11
#define GPIOB_PIN8_AF                         AF11
#define GPIOB_PIN9_AF                         AF11
#define GPIOB_PIN10_AF                        AF11
#define GPIOB_PIN11_AF                        AF11
#define GPIOB_PIN12_AF                        AF11
#define GPIOB_PIN13_AF                        AF11
#define GPIOB_PIN14_AF		                  AF11
#define GPIOB_PIN15_AF                        AF11

#define GPIOC_PIN13_AF                        AF11
#define GPIOC_PIN14_AF                        AF11
#define GPIOC_PIN15_AF                        AF11




#endif                          





