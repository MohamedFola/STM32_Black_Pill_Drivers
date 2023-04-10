/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : MCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : EXTI                                 */
/*************************************************************/
/*************************************************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"


static void( *ptr_CallBack[ 23 ] )( void ) = { NULL };


/**********************************************************************************************************************/


void EXTI_voidSelectPort (
		u8 Copy_u8EXTI_line ,
		u8 Copy_u8Port      )
{
	/*
	 Check for Pin number
	 If number is less than 16              --> applicable
	 If number is greater than or equal 16  --> not applicable
	 */

	if(Copy_u8Port < 8 && Copy_u8Port != 5 && Copy_u8Port != 6 )
	{
		/*
		 Check for the EXTI number to Know Which Register to use
		 for EXTI0 to EXTI3   --> use SYSCFG_EXTICR1
		 for EXTI4 to EXTI7   --> use SYSCFG_EXTICR2
		 for EXTI8 to EXTI11  --> use SYSCFG_EXTICR3
		 for EXTI12 to EXTI5  --> use SYSCFG_EXTICR4
		 */

		if      ( Copy_u8EXTI_line < 4 )
		{
			SYSCFG_EXTICR1 &= ~( SYSCFG_MASK << ( 4 * (Copy_u8EXTI_line ) ) ) ;
			SYSCFG_EXTICR1 |=  ( Copy_u8Port << ( 4 * (Copy_u8EXTI_line ) ) ) ;
		}
		else if ( Copy_u8EXTI_line < 8 )
		{
			SYSCFG_EXTICR2 &= ~( SYSCFG_MASK << ( 4 * ( Copy_u8EXTI_line ) ) )     ;
			SYSCFG_EXTICR2 |=  ( Copy_u8Port << ( 4 * ( Copy_u8EXTI_line - 4 ) ) ) ;
		}
		else if ( Copy_u8EXTI_line < 12 )
		{
			SYSCFG_EXTICR3 &= ~( SYSCFG_MASK << ( 4 * ( Copy_u8EXTI_line ) ) )     ;
			SYSCFG_EXTICR3 |=  ( Copy_u8Port << ( 4 * ( Copy_u8EXTI_line - 8 ) ) ) ;
		}
		else if ( Copy_u8EXTI_line < 16 )
		{
			SYSCFG_EXTICR4 &= ~( SYSCFG_MASK << ( 4 * ( Copy_u8EXTI_line ) ) )      ;
			SYSCFG_EXTICR4 |=  ( Copy_u8Port << ( 4 * ( Copy_u8EXTI_line - 12 ) ) ) ;
		}
		else
		{
			/* DO NOTHING */;
		}
	}
	else
	{
		/* Wrong EXTI line number */
		/* DO NOTHING */
	}
}


/**********************************************************************************************************************/


void EXTI_voidSelectTrigger (
		u8 Copy_u8EXTI_line        ,
		u8 Copy_u8TriggerSelection )
{
	/*
	 Check for EXTI number
	 If number is less than 23              --> applicable
	 If number is greater than or equal 23  --> not applicable
	 */

	if ( Copy_u8EXTI_line < 23 )
	{
		/* Selecting trigger */

		if ( Copy_u8TriggerSelection == EXTI_RISING_EDGE_TRIGGER )
		{
			/*
			 For Rising Edge only
			 Set EXTI line for Rising Trigger Selection Register
			 Clear EXTI line for Falling Trigger Selection Register
			 */

			SET_BIT( EXTI->RTSR, Copy_u8EXTI_line );
			CLR_BIT( EXTI->FTSR, Copy_u8EXTI_line );
		}
		else if ( Copy_u8TriggerSelection == EXTI_FALLING_EDGE_TRIGGER )
		{
			/*
			 For Falling Edge only
			 Clear EXTI line for Rising Trigger Selection Register
			 Set EXTI line for Falling Trigger Selection Register
			 */

			SET_BIT( EXTI->FTSR, Copy_u8EXTI_line );
			CLR_BIT( EXTI->RTSR, Copy_u8EXTI_line );
		}
		else if ( Copy_u8TriggerSelection == EXTI_BOTH_EDGES_TRIGGER )
		{
			/*
			 For Both Triggers
			 Set EXTI line for Rising Trigger Selection Register
			 Set EXTI line for Falling Trigger Selection Register
			 */

			SET_BIT( EXTI->RTSR, Copy_u8EXTI_line );
			SET_BIT( EXTI->FTSR, Copy_u8EXTI_line );
		}
		else
		{
			/* Wrong Trigger Selection */
			/* DO NOTHING */
		}
	}
	else
	{
		/* Wrong EXTI line number */
		/* DO NOTHING */
	}
}


/**********************************************************************************************************************/


void EXTI_voidControlLine (
		u8 Copy_u8EXTI_line ,
		u8 Copy_u8LineState )
{
	/*
	 Check for EXTI number
	 If number is less than 23              --> applicable
	 If number is greater than or equal 23  --> not applicable
	 */

	if ( Copy_u8EXTI_line < 23 )
	{
		/*
		 Enable or Disable EXTI interrupt
		 If State is EXTI_ENABLE Set EXTI line for Interrupt Mask Register
		 If State is EXTI_DISABLE Clear EXTI line for Interrupt Mask Register
		 */

		if ( Copy_u8LineState == EXTI_ENABLE )
		{
			SET_BIT( EXTI->IMR , Copy_u8EXTI_line );
		}
		else if ( Copy_u8LineState == EXTI_DISABLE )
		{
			CLR_BIT( EXTI->IMR , Copy_u8EXTI_line );
		}
		else
		{
			/* Wrong EXTI line state */
			/* DO NOTHING */
		}
	}
	else
	{
		/* Wrong EXTI line number */
		/* DO NOTHING */
	}
}


/**********************************************************************************************************************/


void EXTI_voidSoftwareTrigger ( u8 Copy_u8EXTI_line )
{
	/*
	 Check for EXTI number
	 If number is less than 23              --> applicable
	 If number is greater than or equal 23  --> not applicable
	 */

	if ( Copy_u8EXTI_line < 23 )
	{
		/* Set EXTI line for Software Interrupt Event Register */

		SET_BIT( EXTI->SWIER, Copy_u8EXTI_line );
	}
	else
	{
		/* Wrong EXTI line number */
		/* DO NOTHING */
	}
}


/**********************************************************************************************************************/


void EXTI_voidClearFlag ( u8 Copy_u8EXTI_line )
{
	/*
	 Check for EXTI number
	 If number is less than 23              --> applicable
	 If number is greater than or equal 23  --> not applicable
	 */

	if ( Copy_u8EXTI_line < 23 )
	{
		/* Clear Bit for Pending Register by Writing one to it */

		SET_BIT( EXTI->PR, Copy_u8EXTI_line );
	}
	else
	{
		/* Wrong EXTI line number */
		/* DO NOTHING */
	}
}


/**********************************************************************************************************************/


void EXTI_voidSetCallBack (
		u8 Copy_u8EXTI_line           ,
		void ( *ptr_Function )( void ) )
{
	/*
	 Check for EXTI number
	 If number is less than 23              --> applicable
	 If number is greater than or equal 23  --> not applicable
	 */

	if ( Copy_u8EXTI_line < 23 )
	{
		/* Set the Function Address to the Call Back Function */

		ptr_CallBack[ Copy_u8EXTI_line ] = ptr_Function;
	}
	else
	{
		/* Wrong EXTI line number */
		/* DO NOTHING */
	}
}


/**********************************************************************************************************************/


/* ISR for EXTI0 */
void EXTI0_IRQHandler( void )
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI0_CallBack not NULL then Call the Function
	 */

	if ( ptr_CallBack[ EXTI_0 ] != NULL )
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[ EXTI_0 ]();
		EXTI_voidClearFlag( EXTI_0 );
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}


/* ISR for EXTI1 */
void EXTI1_IRQHandler( void )
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI1_CallBack not NULL then Call the Function
	 */

	if ( ptr_CallBack[ EXTI_1 ] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[ EXTI_1 ]();
		EXTI_voidClearFlag( EXTI_1 );
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}


/* ISR for EXTI2 */
void EXTI2_IRQHandler( void )
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI2_CallBack not NULL then Call the Function
	 */

	if ( ptr_CallBack[ EXTI_2 ] != NULL )
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[ EXTI_2 ]();
		EXTI_voidClearFlag( EXTI_2 );
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}


/* ISR for EXTI3 */
void EXTI3_IRQHandler( void )
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI3_CallBack not NULL then Call the Function
	 */

	if ( ptr_CallBack[ EXTI_3 ] != NULL )
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[ EXTI_3 ]();
		EXTI_voidClearFlag( EXTI_3 );
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}


/* ISR for EXTI4 */
void EXTI4_IRQHandler( void )
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI4_CallBack not NULL then Call the Function
	 */

	if ( ptr_CallBack[ EXTI_4 ] != NULL )
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[ EXTI_4 ]();
		EXTI_voidClearFlag( EXTI_4 );
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}



/* ISR for EXTI5 to EXTI9 */
void EXTI9_5_IRQHandler( void )
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI5_CallBack not NULL then Call the Function
	 */

	if ( ptr_CallBack[ EXTI_5 ] != NULL )
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[ EXTI_5 ]();
		EXTI_voidClearFlag( EXTI_5 );
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}


/* ISR for EXTI10 to EXTI15 */
void EXTI15_10_IRQHandler( void )
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI6_CallBack not NULL then Call the Function
	 */

	if ( ptr_CallBack[ EXTI_6 ] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[ EXTI_6 ]();
		EXTI_voidClearFlag( EXTI_6 );
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}



/* ISR for EXTI17 and RTC */
void EXTI17_RTC_Alarm_IRQHandler( void )
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI7_CallBack not NULL then Call the Function
	 */

	if ( ptr_CallBack[ EXTI_7 ] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[ EXTI_7 ]();
		EXTI_voidClearFlag( EXTI_7 );
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}



/* ISR for EXTI18 and OTG */
void EXTI18_OTG_FS_WKUP_IRQHandler( void )
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI8_CallBack not NULL then Call the Function
	 */

	if ( ptr_CallBack[ EXTI_8 ] != NULL )
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[ EXTI_8 ]();
		EXTI_voidClearFlag( EXTI_8 );
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}


