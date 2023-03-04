/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 2.00                      ************/
/************ SWC     : RCC                       ************/
/*************************************************************/
/*************************************************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidSystemClockEnable( void )
{

	/* MCO1 Source Selection */
	RCC->CFGR |= (RCC_MCO1_SORUCE << MCO1);

	/* MCO1 PreScaler */
	RCC->CFGR |= (RCC_MCO1_PRE << MCO1PRE);

	/* MCO2 Source Selection */
	RCC->CFGR |= (RCC_MCO2_SORUCE << MCO2);

	/* MCO2 PreScaler */
	RCC->CFGR |= (RCC_MCO2_PRE << MCO2PRE);



	/* HSI Trimming Value */
#if RCC_HSI_TRIMMING_VALUE != RCC_DEFAULT_TRIMMING_VALUE

	if(RCC_HSI_TRIMMING_VALUE < 32 && RCC_HSI_TRIMMING_VALUE >= 0)
	{
		RCC->CR |= (RCC_HSI_TRIMMING_VALUE << HSITIRM);
	}

#endif


	/* HSE Enable */
#if RCC_HSE_ON == RCC_ENABLE

	RCC->CR |= (RCC_HSE_ON << HSEON);
	while(!(GET_BIT(RCC->CR, HSERDY)));

#endif


	/* HSE Bypass Enable */
#if RCC_HSE_BYPASS == RCC_ENABLE

	RCC->CR |= (RCC_HSE_BYPASS << HSEBYP);

#endif


	/* Clock Security Enable */
#if RCC_CLOCK_SECURITY_ON == RCC_ENABLE

	RCC->CR |= (RCC_CLOCK_SECURITY_ON << CSSON);

#endif



	/* PLL and PLLI2S Enable and set configurations */
#if RCC_PLL_ON == RCC_ENABLE || RCC_PLLI2S_ON == RCC_ENABLE

	/* Select PLLM */
#if RCC_PLLM < 64 && RCC_PLLM > 1

	RCC->PLLCFGR |= (RCC_PLLM << PLLM);

#endif

	/* Select PLLN */
#if RCC_PLLN < 433 && RCC_PLLN > 191

	RCC->PLLCFGR |= (RCC_PLLN << PLLN);

#endif

	/* Select PLLP */
#if RCC_PLLP < 4 && RCC_PLLP >= 0

	RCC->PLLCFGR |= (RCC_PLLP << PLLP);

#endif

	/* Select PLLQ */
#if RCC_PLLQ < 16 && RCC_PLLQ > 1

	RCC->PLLCFGR |= (RCC_PLLQ << PLLQ);

#endif


	/* PLL Enable */
#if RCC_PLL_ON == RCC_ENABLE

	/* Select the PLL Clock Source */
	RCC->PLLCFGR |= (RCC_PLL_SOURCE << PLLSRC);

	RCC->CR |= (RCC_PLL_ON << PLLON);
	while(!(GET_BIT(RCC->CR, PLLRDY)));

#endif

	/* PLLI2S Enable */
#if RCC_PLLI2S_ON == RCC_ENABLE

	/* I2S Source Selection */
	RCC->CFGR |= (RCC_I2S_Source << I2SSRC);


	RCC->CR |= (RCC_PLLI2S_ON << PLLI2SON);
	while(!(GET_BIT(RCC->CR, PLLI2SRDY)));

#endif

#endif


	/* Choose the System Clock */
	RCC->CFGR |= (RCC_SYSTEM_CLOCK << SW);

	/* AHB Prescaler */
	RCC->CFGR |= (RCC_AHB_PERSCALER << HPRE);

	/* APB1 Prescaler */
	RCC->CFGR |= (RCC_APB1_PERSCALER << PPRE1);

	/* APB2 Prescaler */
	RCC->CFGR |= (RCC_APB2_PERSCALER << PPRE2);

	/* HSI Disable if not used */
#if RCC_HSI_ON == RCC_DISABLE

	CLR_BIT(RCC->CR, HSION);

#endif

}


/*****************************************************************************************************/


void RCC_voidPeripheralClockEnable(u8 Copy_PeripheralName)
{
	if( Copy_PeripheralName < RCC_AHB1_PERIPHERAL_NUMBER )
	{
		SET_BIT( RCC->AHB1ENR, Copy_PeripheralName );
	}
	else if( Copy_PeripheralName < RCC_AHB2_PERIPHERAL_NUMBER )
	{
		SET_BIT( RCC->AHB2ENR, ( Copy_PeripheralName - RCC_AHB1_PERIPHERAL_NUMBER ) );
	}
	else if( Copy_PeripheralName < RCC_APB1_PERIPHERAL_NUMBER )
	{
		SET_BIT( RCC->APB1ENR, ( Copy_PeripheralName - RCC_AHB2_PERIPHERAL_NUMBER ) );
	}
	else if( Copy_PeripheralName < RCC_APB2_PERIPHERAL_NUMBER )
	{
		SET_BIT( RCC->APB2ENR, ( Copy_PeripheralName - RCC_APB1_PERIPHERAL_NUMBER ) );
	}
	else
	{
		/* DO NOTHING */
	}
}


/*****************************************************************************************************/


void RCC_voidPeripheralClockDisable( u8 Copy_PeripheralName )
{
	if( Copy_PeripheralName < RCC_AHB1_PERIPHERAL_NUMBER )
	{
		CLR_BIT( RCC->AHB1ENR, Copy_PeripheralName );
	}
	else if( Copy_PeripheralName < RCC_AHB2_PERIPHERAL_NUMBER )
	{
		CLR_BIT( RCC->AHB2ENR, ( Copy_PeripheralName - RCC_AHB1_PERIPHERAL_NUMBER ) );
	}
	else if( Copy_PeripheralName < RCC_APB1_PERIPHERAL_NUMBER )
	{
		CLR_BIT( RCC->APB1ENR, ( Copy_PeripheralName - RCC_AHB2_PERIPHERAL_NUMBER ) );
	}
	else if( Copy_PeripheralName < RCC_APB2_PERIPHERAL_NUMBER )
	{
		CLR_BIT( RCC->APB2ENR, ( Copy_PeripheralName - RCC_APB1_PERIPHERAL_NUMBER ) );
	}
	else
	{
		/* DO NOTHING */
	}
}


/*****************************************************************************************************/


void RCC_voidPeripheralReset( u8 Copy_PeripheralName )
{
	if( Copy_PeripheralName < RCC_AHB1_PERIPHERAL_NUMBER )
	{
		SET_BIT( RCC->AHB1RSTR, Copy_PeripheralName ) ;
		CLR_BIT( RCC->AHB1RSTR, Copy_PeripheralName ) ;
	}
	else if( Copy_PeripheralName < RCC_AHB2_PERIPHERAL_NUMBER )
	{
		SET_BIT( RCC->AHB2RSTR, ( Copy_PeripheralName - RCC_AHB1_PERIPHERAL_NUMBER ) ) ;
		CLR_BIT( RCC->AHB2RSTR, ( Copy_PeripheralName - RCC_AHB1_PERIPHERAL_NUMBER ) ) ;
	}
	else if( Copy_PeripheralName < RCC_APB1_PERIPHERAL_NUMBER )
	{
		SET_BIT( RCC->APB1RSTR, ( Copy_PeripheralName - RCC_AHB2_PERIPHERAL_NUMBER ) ) ;
		CLR_BIT( RCC->APB1RSTR, ( Copy_PeripheralName - RCC_AHB2_PERIPHERAL_NUMBER ) ) ;
	}
	else if( Copy_PeripheralName < RCC_APB2_PERIPHERAL_NUMBER )
	{
		SET_BIT( RCC->APB2RSTR, ( Copy_PeripheralName - RCC_APB1_PERIPHERAL_NUMBER ) ) ;
		CLR_BIT( RCC->APB2RSTR, ( Copy_PeripheralName - RCC_APB1_PERIPHERAL_NUMBER ) ) ;
	}
	else
	{
		/* DO NOTHING */
	}
}
