/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : HAL                                  */
/*            Version : 1.00                                 */
/*            SWC     : LED                                  */
/*************************************************************/
/*************************************************************/

#include "../../00-LIB/BIT_MATH.h"
#include "../../00-LIB/STD_TYPES.h"

#include "../../01-MCAL/02-GPIO/GPIO_interface.h"

#include "LED_interface.h"


void LED_voidStatus (
		LED_t* Ptr_Led       ,
		u8     Copy_u8Status )
{
	u8 Local_u8LedStatus = ( Copy_u8Status ) ^ ( Ptr_Led->LED_ConnectionType );

	GPIO_voidSetChannelValue( Ptr_Led->LED_Port, Ptr_Led->LED_Pin, Local_u8LedStatus );
}



u8 LED_u8SetMultipleLeds (
		Multiple_LEDs_t* Ptr_Led      ,
		u8               Copy_u8Value )
{
	u8 Local_u8Error = OK;

	if ( ( ( Ptr_Led->LED_Width + Ptr_Led->LED_StartPin) < 16 ) )
	{
		if ( ( Ptr_Led->LED_Port == GPIOx_PORTC ) && ( ( Ptr_Led->LED_Width + Ptr_Led->LED_StartPin) < 14 ) )
		{
			Local_u8Error = NOK;
		}
		else
		{
			GPIO_voidSetChannelGroupValue( Ptr_Led->LED_Port, Ptr_Led->LED_StartPin, Ptr_Led->LED_Width, Copy_u8Value );
		}
	}
	else
	{
		Local_u8Error = NOK;
	}

	return Local_u8Error;
}

