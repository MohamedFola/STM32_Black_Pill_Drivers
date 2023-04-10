/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : MCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : NVIC                                 */
/*************************************************************/
/*************************************************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "NVIC_private.h"
#include "NVIC_interface.h"
#include "NVIC_config.h"


/**********************************************************************************************************************/


void NVIC_voidInit ( void )
{
	SCB_AIRCR = ( SCB_AIRCR_KEY_VALUE ) + ( ( NVIC_PRIORITY_DISTRIBUTION + 3 ) << 8 );
}


/**********************************************************************************************************************/


void NVIC_voidSetPriority ( u8 Copy_u8InterruptPosition, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority )
{
	NVIC_IPR[ Copy_u8InterruptPosition ] = ( Copy_u8GroupPriority << ( 4 + NVIC_PRIORITY_DISTRIBUTION ) ) | ( Copy_u8SubPriority << 4 );
}


/**********************************************************************************************************************/

void NVIC_voidEnableInterrupt ( u8 Copy_u8InterruptPosition )
{
	if      ( Copy_u8InterruptPosition < 32  ) NVIC_ISER0 = ( 1 << ( Copy_u8InterruptPosition       ) ) ;
	else if ( Copy_u8InterruptPosition < 64  ) NVIC_ISER1 = ( 1 << ( Copy_u8InterruptPosition - 32  ) ) ;
	else if ( Copy_u8InterruptPosition < 96  ) NVIC_ISER2 = ( 1 << ( Copy_u8InterruptPosition - 64  ) ) ;
	else if ( Copy_u8InterruptPosition < 128 ) NVIC_ISER3 = ( 1 << ( Copy_u8InterruptPosition - 96  ) ) ;
	else if ( Copy_u8InterruptPosition < 160 ) NVIC_ISER4 = ( 1 << ( Copy_u8InterruptPosition - 128 ) ) ;
	else if ( Copy_u8InterruptPosition < 192 ) NVIC_ISER5 = ( 1 << ( Copy_u8InterruptPosition - 160 ) ) ;
	else if ( Copy_u8InterruptPosition < 224 ) NVIC_ISER6 = ( 1 << ( Copy_u8InterruptPosition - 192 ) ) ;
	else if ( Copy_u8InterruptPosition < 240 ) NVIC_ISER7 = ( 1 << ( Copy_u8InterruptPosition - 224 ) ) ;
	else    /* DO NOTHING */                                                                            ;
}


/**********************************************************************************************************************/

void NVIC_voidDisableInterrupt ( u8 Copy_u8InterruptPosition )
{
	if      ( Copy_u8InterruptPosition < 32  ) NVIC_ICER0 = ( 1 << ( Copy_u8InterruptPosition       ) ) ;
	else if ( Copy_u8InterruptPosition < 64  ) NVIC_ICER1 = ( 1 << ( Copy_u8InterruptPosition - 32  ) ) ;
	else if ( Copy_u8InterruptPosition < 96  ) NVIC_ICER2 = ( 1 << ( Copy_u8InterruptPosition - 64  ) ) ;
	else if ( Copy_u8InterruptPosition < 128 ) NVIC_ICER3 = ( 1 << ( Copy_u8InterruptPosition - 96  ) ) ;
	else if ( Copy_u8InterruptPosition < 160 ) NVIC_ICER4 = ( 1 << ( Copy_u8InterruptPosition - 128 ) ) ;
	else if ( Copy_u8InterruptPosition < 192 ) NVIC_ICER5 = ( 1 << ( Copy_u8InterruptPosition - 160 ) ) ;
	else if ( Copy_u8InterruptPosition < 224 ) NVIC_ICER6 = ( 1 << ( Copy_u8InterruptPosition - 192 ) ) ;
	else if ( Copy_u8InterruptPosition < 240 ) NVIC_ICER7 = ( 1 << ( Copy_u8InterruptPosition - 224 ) ) ;
	else    /* DO NOTHING */                                                                            ;
}


/**********************************************************************************************************************/


void NVIC_voidSetPendingFlag ( u8 Copy_u8InterruptPosition )
{
	if      ( Copy_u8InterruptPosition < 32  ) NVIC_ISPR0 = ( 1 << ( Copy_u8InterruptPosition       ) ) ;
	else if ( Copy_u8InterruptPosition < 64  ) NVIC_ISPR1 = ( 1 << ( Copy_u8InterruptPosition - 32  ) ) ;
	else if ( Copy_u8InterruptPosition < 96  ) NVIC_ISPR2 = ( 1 << ( Copy_u8InterruptPosition - 64  ) ) ;
	else if ( Copy_u8InterruptPosition < 128 ) NVIC_ISPR3 = ( 1 << ( Copy_u8InterruptPosition - 96  ) ) ;
	else if ( Copy_u8InterruptPosition < 160 ) NVIC_ISPR4 = ( 1 << ( Copy_u8InterruptPosition - 128 ) ) ;
	else if ( Copy_u8InterruptPosition < 192 ) NVIC_ISPR5 = ( 1 << ( Copy_u8InterruptPosition - 160 ) ) ;
	else if ( Copy_u8InterruptPosition < 224 ) NVIC_ISPR6 = ( 1 << ( Copy_u8InterruptPosition - 192 ) ) ;
	else if ( Copy_u8InterruptPosition < 240 ) NVIC_ISPR7 = ( 1 << ( Copy_u8InterruptPosition - 224 ) ) ;
	else    /* DO NOTHING */                                                                            ;
}


/**********************************************************************************************************************/


void NVIC_voidClearPendingFlag ( u8 Copy_u8InterruptPosition )
{
	if      ( Copy_u8InterruptPosition < 32  ) NVIC_ICPR0 = ( 1 << ( Copy_u8InterruptPosition       ) ) ;
	else if ( Copy_u8InterruptPosition < 64  ) NVIC_ICPR1 = ( 1 << ( Copy_u8InterruptPosition - 32  ) ) ;
	else if ( Copy_u8InterruptPosition < 96  ) NVIC_ICPR2 = ( 1 << ( Copy_u8InterruptPosition - 64  ) ) ;
	else if ( Copy_u8InterruptPosition < 128 ) NVIC_ICPR3 = ( 1 << ( Copy_u8InterruptPosition - 96  ) ) ;
	else if ( Copy_u8InterruptPosition < 160 ) NVIC_ICPR4 = ( 1 << ( Copy_u8InterruptPosition - 128 ) ) ;
	else if ( Copy_u8InterruptPosition < 192 ) NVIC_ICPR5 = ( 1 << ( Copy_u8InterruptPosition - 160 ) ) ;
	else if ( Copy_u8InterruptPosition < 224 ) NVIC_ICPR6 = ( 1 << ( Copy_u8InterruptPosition - 192 ) ) ;
	else if ( Copy_u8InterruptPosition < 240 ) NVIC_ICPR7 = ( 1 << ( Copy_u8InterruptPosition - 224 ) ) ;
	else    /* DO NOTHING */                                                                            ;
}


/**********************************************************************************************************************/


u8 NVIC_u8GetActiveFlag ( u8 Copy_u8InterruptPosition )
{
	u8 Local_u8Value = 0x55;

	if      ( Copy_u8InterruptPosition < 32  ) Local_u8Value = GET_BIT( NVIC_IABR0, Copy_u8InterruptPosition       ) ;
	else if ( Copy_u8InterruptPosition < 64  ) Local_u8Value = GET_BIT( NVIC_IABR1, Copy_u8InterruptPosition - 32  ) ;
	else if ( Copy_u8InterruptPosition < 96  ) Local_u8Value = GET_BIT( NVIC_IABR2, Copy_u8InterruptPosition - 64  ) ;
	else if ( Copy_u8InterruptPosition < 128 ) Local_u8Value = GET_BIT( NVIC_IABR3, Copy_u8InterruptPosition - 96  ) ;
	else if ( Copy_u8InterruptPosition < 160 ) Local_u8Value = GET_BIT( NVIC_IABR4, Copy_u8InterruptPosition - 128 ) ;
	else if ( Copy_u8InterruptPosition < 192 ) Local_u8Value = GET_BIT( NVIC_IABR5, Copy_u8InterruptPosition - 160 ) ;
	else if ( Copy_u8InterruptPosition < 224 ) Local_u8Value = GET_BIT( NVIC_IABR6, Copy_u8InterruptPosition - 192 ) ;
	else if ( Copy_u8InterruptPosition < 240 ) Local_u8Value = GET_BIT( NVIC_IABR7, Copy_u8InterruptPosition - 224 ) ;
	else    /* DO NOTHING */                                                                                          ;

	return Local_u8Value;
}


/**********************************************************************************************************************/


void NVIC_voidSoftwareTrigger ( u8 Copy_u8InterruptPosition )
{

	if    ( Copy_u8InterruptPosition < 240 ) NVIC_STIR |= Copy_u8InterruptPosition ;
	else  /* DO NOTHING */                                                         ;
}


/**********************************************************************************************************************/
