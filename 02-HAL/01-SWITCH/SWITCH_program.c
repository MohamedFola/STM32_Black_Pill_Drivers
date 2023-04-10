/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : HAL                                  */
/*            Version : 1.00                                 */
/*            SWC     : Switch                               */
/*************************************************************/
/*************************************************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "../../01-MCAL/02-GPIO/GPIO_interface.h"

#include "SWITCH_interface.h"


void SWITCH_voidGetSwtichStatus (
		Switch_t* Ptr_Swtich   ,
		u16*      Ptr_u16Value )
{
	GPIO_u8GetChannelValue( Ptr_Swtich->Switch_Port, Ptr_Swtich->Switch_Pin, Ptr_u16Value );
}


u8 SWITCH_u8GetMultipleSwitchesStatus (
		Multiple_Switches_t* Ptr_Switchs  ,
		u16*                 Ptr_u16Value )
{
	u8 Local_u8Error = OK;

	if ( ( Ptr_Switchs->Swtich_StartPin + Ptr_Switchs->Switch_width ) < 16 )
	{
		if ( ( Ptr_Switchs->Switch_Port == GPIOx_PORTC ) && ( ( Ptr_Switchs->Swtich_StartPin + Ptr_Switchs->Switch_width ) < 14 ) )
		{
			Local_u8Error = NOK;
		}
		else
		{
			GPIO_u8GetChannelGroupValue(Ptr_Switchs->Switch_Port, Ptr_Switchs->Swtich_StartPin, Ptr_Switchs->Switch_width, Ptr_u16Value);
		}
	}
	else
	{
		Local_u8Error = NOK;
	}

	return Local_u8Error;
}


