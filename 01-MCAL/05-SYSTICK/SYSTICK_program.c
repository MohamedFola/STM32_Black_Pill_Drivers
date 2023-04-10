/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : MCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : SYSTICK                              */
/*************************************************************/
/*************************************************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "SYSTICK_private.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"


static u8 STK_IntervalType = STK_SINGLE_INTERVAL;
static void ( *STK_CallBackFunction )( void ) = NULL;


/*-----------------------------------------------------------------------------------*/


void STK_voidSetClockSource ( u8 Copy_ClockSource )
{
	SYSTICK->CTRL |= ( Copy_ClockSource << STK_CTRL_CLKSOURCE );
}


/*-----------------------------------------------------------------------------------*/


void STK_voidBusyWait ( u32 Copy_Ticks )
{
	/* disable interrupt */
	CLR_BIT( SYSTICK->CTRL, STK_CTRL_TICKINT );

	/* load the tick to the load register */
	SYSTICK->LOAD = ( Copy_Ticks ) & STK_MASK;

	/* make sure that the val register is 0 */
	SYSTICK->VAL = 0;

	/* start the timer */
	SET_BIT( SYSTICK->CTRL, STK_CTRL_ENABLE );

	/* wait until the timer is over */
	while( !GET_BIT( SYSTICK->CTRL, STK_CTRL_COUNTINGFLAG ) );

	/* stop the timer */
	CLR_BIT( SYSTICK->CTRL, STK_CTRL_ENABLE );
}


/*-----------------------------------------------------------------------------------*/


void STK_voidSetTimeInterval (
		u32 Copy_Ticks                     ,
		u8  Copy_IntervalType              ,
		void ( *Ptr_CallBackFunction )( void )
)
{
	/* set the type of period */
	STK_IntervalType = Copy_IntervalType;

	/* set the call back function */
	STK_CallBackFunction = Ptr_CallBackFunction;

	/* load the tick to the load register */
	SYSTICK->LOAD = ( Copy_Ticks - ( Copy_IntervalType * 1 ) ) & STK_MASK;

	/* make sure that the val register is 0 */
	SYSTICK->VAL = 0;

	/* enable interrupt */
	SET_BIT( SYSTICK->CTRL, STK_CTRL_TICKINT );

	/* start the timer */
	SET_BIT( SYSTICK->CTRL, STK_CTRL_ENABLE );
}


/*-----------------------------------------------------------------------------------*/


u32 STK_u32GetElapsedTicks ( void )
{
	return (SYSTICK->LOAD) - (SYSTICK->VAL);
}


/*-----------------------------------------------------------------------------------*/


u32 STK_u32GetRemainingTicks ( void )
{
	return SYSTICK->VAL;
}


/*-----------------------------------------------------------------------------------*/


void SysTick_Handler ( void )
{
	/* run the call back function */
	if ( STK_CallBackFunction != NULL ) STK_CallBackFunction();

	/* check if the interval type is single then stop the timer */
	if ( STK_IntervalType == STK_SINGLE_INTERVAL ) CLR_BIT( SYSTICK->CTRL, STK_CTRL_ENABLE );

	/* clear the flag */
	SYSTICK->VAL = 0;
}
