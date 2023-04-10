/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : MCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : PORT                                 */
/*************************************************************/
/*************************************************************/

#ifndef _PORT_PRIVATE_H_
#define _PORT_PRIVATE_H_


#define Input_Mode                             00
#define General_Purpose_Output_Mode            01
#define Alternate_Function_Mode                10
#define Analog_Mode                            11


#define Output_Push_Pull                       0
#define Output_Open_Drain                      1


#define Low_Speed                              00
#define Medium_Speed                           01
#define High_Speed                             10
#define Very_High_Speed                        11


#define No_Pull_Up_or_Down                     00
#define Pull_Up                                01
#define Pull_Down                              10


#define Deactive_Lock                          0
#define Active_Lock                            1 


#define Not_Locked                             0 
#define Locked                                 1



#define AF0                                    0000
#define AF1                                    0001
#define AF2                                    0010
#define AF3                                    0011
#define AF4                                    0100
#define AF5                                    0101
#define AF6                                    0110
#define AF7                                    0111
#define AF8                                    1000
#define AF9                                    1001
#define AF10                                   1010
#define AF11                                   1011
#define AF12                                   1100
#define AF13                                   1101
#define AF14                                   1110
#define AF15                                   1111



/* Macros for concatenating 15 elements */
#define CONC(Bit15, Bit14, Bit13, Bit12, Bit11, Bit10, Bit9, Bit8, Bit7, Bit6, Bit5, Bit4, Bit3, Bit2, Bit1, Bit0)\
CONC_HELPER(Bit15, Bit14, Bit13, Bit12, Bit11, Bit10, Bit9, Bit8, Bit7, Bit6, Bit5, Bit4, Bit3, Bit2, Bit1, Bit0)

#define CONC_HELPER(Bit15, Bit14, Bit13, Bit12, Bit11, Bit10, Bit9, Bit8, Bit7, Bit6, Bit5, Bit4, Bit3, Bit2, Bit1, Bit0)\
0b##Bit15##Bit14##Bit13##Bit12##Bit11##Bit10##Bit9##Bit8##Bit7##Bit6##Bit5##Bit4##Bit3##Bit2##Bit1##Bit0   



/********************************************************************************************************/
/****************************           Mode Macros                 *************************************/
/********************************************************************************************************/

#define GPIOA_Mode  CONC(GPIOA_PIN15_MODE, \
						 10,               \
						 10,               \
						 GPIOA_PIN12_MODE, \
						 GPIOA_PIN11_MODE, \
						 GPIOA_PIN10_MODE, \
						 GPIOA_PIN9_MODE,  \
						 GPIOA_PIN8_MODE,  \
						 GPIOA_PIN7_MODE,  \
						 GPIOA_PIN6_MODE,  \
						 GPIOA_PIN5_MODE,  \
						 GPIOA_PIN4_MODE,  \
						 GPIOA_PIN3_MODE,  \
						 GPIOA_PIN2_MODE,  \
						 GPIOA_PIN1_MODE,  \
						 GPIOA_PIN0_MODE)

#define GPIOB_Mode  CONC(GPIOB_PIN15_MODE, \
					     GPIOB_PIN14_MODE, \
						 GPIOB_PIN13_MODE, \
						 GPIOB_PIN12_MODE, \
						 GPIOB_PIN11_MODE, \
						 GPIOB_PIN10_MODE, \
						 GPIOB_PIN9_MODE,  \
						 GPIOB_PIN8_MODE,  \
						 GPIOB_PIN7_MODE,  \
						 GPIOB_PIN6_MODE,  \
						 GPIOB_PIN5_MODE,  \
						 10,               \
						 10,               \
						 GPIOB_PIN2_MODE,  \
						 GPIOB_PIN1_MODE,  \
						 GPIOB_PIN0_MODE)

#define GPIOC_Mode  CONC(GPIOC_PIN15_MODE, \
					     GPIOC_PIN14_MODE, \
						 GPIOC_PIN13_MODE, \
						 00,               \
						 00,               \
						 00,               \
						 00,               \
						 00,               \
						 00,               \
						 00,               \
						 00,               \
						 00,               \
						 00,               \
						 00,               \
						 00,               \
						 00)


/********************************************************************************************************/
/****************************           Type Macros                 *************************************/
/********************************************************************************************************/

#define GPIOA_Output_Type  CONC(GPIOA_PIN15_Output_Type, \
                                0,                       \
                                0,                       \
                                GPIOA_PIN12_Output_Type, \
                                GPIOA_PIN11_Output_Type, \
                                GPIOA_PIN10_Output_Type, \
                                GPIOA_PIN9_Output_Type,  \
                                GPIOA_PIN8_Output_Type,  \
                                GPIOA_PIN7_Output_Type,  \
                                GPIOA_PIN6_Output_Type,  \
                                GPIOA_PIN5_Output_Type,  \
                                GPIOA_PIN4_Output_Type,  \
                                GPIOA_PIN3_Output_Type,  \
                    	        GPIOA_PIN2_Output_Type,  \
                    	        GPIOA_PIN1_Output_Type,  \
                                GPIOA_PIN0_Output_Type)


#define GPIOB_Output_Type  CONC(GPIOB_PIN15_Output_Type, \
                                GPIOB_PIN14_Output_Type, \
                                GPIOB_PIN13_Output_Type, \
                                GPIOB_PIN12_Output_Type, \
                                GPIOB_PIN11_Output_Type, \
                                GPIOB_PIN10_Output_Type, \
                                GPIOB_PIN9_Output_Type,  \
                                GPIOB_PIN8_Output_Type,  \
                                GPIOB_PIN7_Output_Type,  \
                                GPIOB_PIN6_Output_Type,  \
                                GPIOB_PIN5_Output_Type,  \
                                0,                       \
                                0,                       \
                    	        GPIOB_PIN2_Output_Type,  \
                    	        GPIOB_PIN1_Output_Type,  \
                                GPIOB_PIN0_Output_Type)

#define GPIOC_Output_Type  CONC(GPIOC_PIN15_Output_Type, \
				                GPIOC_PIN14_Output_Type, \
				                GPIOC_PIN13_Output_Type, \
                                0,                       \
                                0,                       \
                                0,                       \
                                0,                       \
                                0,                       \
                                0,                       \
                                0,                       \
                                0,                       \
                                0,                       \
                                0,                       \
						        0,                       \
						        0,                       \
                                0)


/********************************************************************************************************/
/****************************           Spedd Macros                *************************************/
/********************************************************************************************************/

#define GPIOA_Speed  CONC(GPIOA_PIN15_Speed, \
                          00,                \
                          00,                \
                          GPIOA_PIN12_Speed, \
                          GPIOA_PIN11_Speed, \
                          GPIOA_PIN10_Speed, \
                          GPIOA_PIN9_Speed,  \
                          GPIOA_PIN8_Speed,  \
                          GPIOA_PIN7_Speed,  \
                          GPIOA_PIN6_Speed,  \
                          GPIOA_PIN5_Speed,  \
                          GPIOA_PIN4_Speed,  \
                          GPIOA_PIN3_Speed,  \
                          GPIOA_PIN2_Speed,  \
                    	  GPIOA_PIN1_Speed,  \
                          GPIOA_PIN0_Speed)

#define GPIOB_Speed  CONC(GPIOB_PIN15_Speed, \
                          GPIOB_PIN14_Speed, \
                          GPIOB_PIN13_Speed, \
                          GPIOB_PIN12_Speed, \
                          GPIOB_PIN11_Speed, \
                          GPIOB_PIN10_Speed, \
                          GPIOB_PIN9_Speed,  \
                          GPIOB_PIN8_Speed,  \
                          GPIOB_PIN7_Speed,  \
                          GPIOB_PIN6_Speed,  \
                          GPIOB_PIN5_Speed,  \
                          00,                \
                          11,                \
                          GPIOB_PIN2_Speed,  \
                    	  GPIOB_PIN1_Speed,  \
                          GPIOB_PIN0_Speed)

#define GPIOC_Speed  CONC(GPIOC_PIN15_Speed, \
				          GPIOC_PIN14_Speed, \
				          GPIOC_PIN13_Speed, \
                          00,                \
                          00,                \
                          00,                \
                          00,                \
                          00,                \
                          00,                \
                          00,                \
                          00,                \
                          00,                \
                          00,                \
						  00,                \
						  00,                \
                          00)


/********************************************************************************************************/
/****************************      Pull_Up\Pull_Down Macros         *************************************/
/********************************************************************************************************/

#define GPIOA_PUPD  CONC(GPIOA_PIN15_PU_PD, \
                         10,                \
                         01,                \
                         GPIOA_PIN12_PU_PD, \
                         GPIOA_PIN11_PU_PD, \
                         GPIOA_PIN10_PU_PD, \
                         GPIOA_PIN9_PU_PD,  \
                         GPIOA_PIN8_PU_PD,  \
                         GPIOA_PIN7_PU_PD,  \
                         GPIOA_PIN6_PU_PD,  \
                         GPIOA_PIN5_PU_PD,  \
                         GPIOA_PIN4_PU_PD,  \
                         GPIOA_PIN3_PU_PD,  \
                    	 GPIOA_PIN2_PU_PD,  \
                    	 GPIOA_PIN1_PU_PD,  \
                         GPIOA_PIN0_PU_PD)

#define GPIOB_PUPD  CONC(GPIOB_PIN15_PU_PD, \
				         GPIOB_PIN14_PU_PD, \
				         GPIOB_PIN13_PU_PD, \
                         GPIOB_PIN12_PU_PD, \
                         GPIOB_PIN11_PU_PD, \
                         GPIOB_PIN10_PU_PD, \
                         GPIOB_PIN9_PU_PD,  \
                         GPIOB_PIN8_PU_PD,  \
                         GPIOB_PIN7_PU_PD,  \
                         GPIOB_PIN6_PU_PD,  \
                         GPIOB_PIN5_PU_PD,  \
                         01,                \
                         00,                \
						 GPIOB_PIN2_PU_PD,  \
						 GPIOB_PIN1_PU_PD,  \
                         GPIOB_PIN0_PU_PD)

#define GPIOC_PUPD  CONC(GPIOC_PIN15_PU_PD, \
				         GPIOC_PIN14_PU_PD, \
				         GPIOC_PIN13_PU_PD, \
                         00,                \
                         00,                \
                         00,                \
                         00,                \
                         00,                \
                         00,                \
                         00,                \
                         00,                \
                         00,                \
                         00,                \
						 00,                \
						 00,                \
                         00)




/********************************************************************************************************/
/****************************    Alternative functinos Macros       *************************************/
/********************************************************************************************************/

#define GPIOA_AF    CONC(GPIOA_PIN15_AF, \
                         0000,           \
                         0000,           \
                         GPIOA_PIN12_AF, \
                         GPIOA_PIN11_AF, \
                         GPIOA_PIN10_AF, \
                         GPIOA_PIN9_AF,  \
                         GPIOA_PIN8_AF,  \
                         GPIOA_PIN7_AF,  \
                         GPIOA_PIN6_AF,  \
                         GPIOA_PIN5_AF,  \
                         GPIOA_PIN4_AF,  \
                         GPIOA_PIN3_AF,  \
                    	 GPIOA_PIN2_AF,  \
                    	 GPIOA_PIN1_AF,  \
                         GPIOA_PIN0_AF)

#define GPIOB_AF    CONC(GPIOB_PIN15_AF, \
				         GPIOB_PIN14_AF, \
				         GPIOB_PIN13_AF, \
                         GPIOB_PIN12_AF, \
                         GPIOB_PIN11_AF, \
                         GPIOB_PIN10_AF, \
                         GPIOB_PIN9_AF,  \
                         GPIOB_PIN8_AF,  \
                         GPIOB_PIN7_AF,  \
                         GPIOB_PIN6_AF,  \
                         GPIOB_PIN5_AF,  \
                         0000,           \
                         0000,           \
						 GPIOB_PIN2_AF,  \
						 GPIOB_PIN1_AF,  \
                         GPIOB_PIN0_AF)

#define GPIOC_AF    CONC(GPIOC_PIN15_AF, \
				         GPIOC_PIN14_AF, \
				         GPIOC_PIN13_AF, \
                         0000,           \
                         0000,           \
                         0000,           \
                         0000,           \
                         0000,           \
                         0000,           \
                         0000,           \
                         0000,           \
                         0000,           \
                         0000,           \
						 0000,           \
						 0000,           \
                         0000)

#endif
