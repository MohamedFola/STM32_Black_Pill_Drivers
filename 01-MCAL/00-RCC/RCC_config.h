/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 2.00                      ************/
/************ SWC     : RCC                       ************/
/*************************************************************/
/*************************************************************/

#ifndef _RCC_CONFIG_H_
#define _RCC_CONFIG_H_


/************************************
 * HSE, HSI, PLL and PLLI2S state   *
 * Options:                         *
 * 		1 --> RCC_ENABLE            *
 * 		2 --> RCC_DISABLE           *
 ************************************/
#define RCC_HSE_ON                     RCC_DISABLE
#define RCC_HSI_ON                     RCC_ENABLE
#define RCC_PLL_ON                     RCC_DISABLE
#define RCC_PLLI2S_ON                  RCC_DISABLE


/*********************************************
 * HSI Trimming Value                        *
 * Options:                                  *
 * 		1 --> RCC_DEFAULT_TRIMMING_VALUE     *
 * 		2 --> Number form 0 to 31            *
 *********************************************/
#define RCC_HSI_TRIMMING_VALUE         RCC_DEFAULT_TRIMMING_VALUE


/***************************
 * HSE Bypass state        *
 * Options:                *
 * 		1 --> RCC_ENABLE   *
 * 		2 --> RCC_DISABLE  *
 ***************************/
#define RCC_HSE_BYPASS                 RCC_DISABLE


/***************************
 * Clock Security state    *
 * Options:                *
 * 		1 --> RCC_ENABLE   *
 * 		2 --> RCC_DISABLE  *
 ***************************/
#define RCC_CLOCK_SECURITY_ON          RCC_ENABLE


/*************************************************************************************************/
/****************** If You Choose PLL as SYSCLK Set these Configurations *************************/
/*************************************************************************************************/

/*************************************************************************************
 *	PLLM: Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock  *
 *	PLLM Options: Choose number between 2 and 63 or RCC_PLLM_DEFAULT                 *
 *************************************************************************************/
#define RCC_PLLM                       RCC_PLLM_DEFAULT

/************************************************************************
 * 	PLLN: Main PLL (PLL) multiplication factor for VCO                  *
 *	PLLN Options: Choose number between 192 and 432 or RCC_PLLN_DEFAULT *
 ************************************************************************/
#define RCC_PLLN                       RCC_PLLN_DEFAULT

/*****************************************************************
 *	PLLP: Main PLL (PLL) division factor for main system clock   *                 *
 *	PLLP Options:                                                *
 *		1) PLLP_2                                                *
 *		2) PLLP_4                                                *
 *		3) PLLP_6                                                *
 *		4) PLLP_8                                                *
 *		5) RCC_PLLP_DEFAULT                                      *
 *****************************************************************/
#define RCC_PLLP                       RCC_PLLP_DEFAULT


/*********************************************
 *	Main and Audio PLL Clock Source          *
 *	Options:                                 *
 *		1 --> RCC_HSI                        *
 *		2 --> RCC_HSE                        *
 *********************************************/
#define RCC_PLL_SOURCE                 RCC_HSI


/*******************************************************************************************
 *	PLLQ: Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator  *
 *	clocks                                                                                 *
 *	PLLQ Options: number between 2 and 15 or Choose RCC_PLLQ_DEFAULT                       *
 *******************************************************************************************/
#define RCC_PLLQ                       RCC_PLLQ_DEFAULT

/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/


/**************************
 * System Clock Choices   *
 * Options:               *
 * 		1 --> RCC_HSI     *
 * 		2 --> RCC_HSE     *
 * 		3 --> RCC_PLL     *
 **************************/
#define RCC_SYSTEM_CLOCK                RCC_HSI


/***********************************
 * AHB Prescaler                   *
 * Options:                        *
 * 		1  --> AHB_NO              *
 * 		2  --> AHB_PRE_2           *
 * 		3  --> AHB_PRE_4           *
 * 		4  --> AHB_PRE_8           *
 * 		5  --> AHB_PRE_16          *
 * 		6  --> AHB_PRE_64          *
 * 		7  --> AHB_PRE_128         *
 * 		8  --> AHB_PRE_256         *
 * 		9  --> AHB_PRE_512         *
 * 		10 --> AHB_Default         *
 ***********************************/
#define RCC_AHB_PERSCALER               AHB_Default


/********************************
 * APB1 Prescaler               *
 * Options:                     *
 * 		1  --> APB_NO           *
 * 		2  --> APB_PRE_2        *
 * 		3  --> APB_PRE_4        *
 * 		4  --> APB_PRE_8        *
 * 		5  --> APB_PRE_16       *
 * 		6  --> APB_Default      *
 ********************************/
#define RCC_APB1_PERSCALER              APB_Default


/********************************
 * APB2 Prescaler               *
 * Options:                     *
 * 		1  --> APB_NO           *
 * 		2  --> APB_PRE_2        *
 * 		3  --> APB_PRE_4        *
 * 		4  --> APB_PRE_8        *
 * 		5  --> APB_PRE_16       *
 * 		6  --> APB_Default      *
 ********************************/
#define RCC_APB2_PERSCALER               APB_Default


/********************************************
 *	Microcontroller Clock Output 1 Options: *
 *		1 --> MCO1_HSI                      *
 *		2 --> MCO1_LSE                      *
 *		3 --> MCO1_HSE                      *
 *		4 --> MCO1_PLL                      *
 *		5 --> MCO1_Default                  *
 ********************************************/
#define RCC_MCO1_SORUCE                  MCO1_HSI


/********************************************
 *	Microcontroller Clock Output 2 Options: *
 *		1 --> MCO2_SYSTICK                  *
 *		2 --> MCO2_PLLI2S                   *
 *		3 --> MCO2_HSE                      *
 *		4 --> MCO2_PLL                      *
 *		5 --> MCO2_Default                  *
 ********************************************/
#define RCC_MCO2_SORUCE                  MCO2_SYSTICK


/******************************************************
 *	Microcontroller Clock Output Pre-scaler Options:  *
 *		1 --> No_Division                             *
 *		2 --> Division_By_2                           *
 *		3 --> Division_By_3                           *
 *		4 --> Division_By_4                           *
 *		5 --> Division_By_5                           *
 ******************************************************/
#define RCC_MCO1_PRE                     No_Division
#define RCC_MCO2_PRE                     No_Division


/***********************************
 * I2S Clock Source                *
 * Options:                        *
 * 		1 --> RCC_I2S_CLOCK        *
 * 		2 --> RCC_I2S_EXTERNAL     *
 ***********************************/
#define RCC_I2S_Source                   RCC_I2S_CLOCK


#endif /* RCC_CONFIG_H_ */
