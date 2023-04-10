/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : HCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : Character LCD                        */
/*************************************************************/
/*************************************************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include "../../00-LIB/Software_Delay.h"

#include "../../01-MCAL/02-GPIO/GPIO_interface.h"
#include "../../01-MCAL/05-SYSTICK/SYSTICK_interface.h"

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"


void CLCD_voidSendCommand ( u8 Copy_u8Command )
{
	u8 Local_u8Data;

	/* Set RS pin to low for command */
	GPIO_voidSetChannelValue( CLCD_CONTROL_PORT, CLCD_RS_PIN, GPIOx_PIN_LOW );

	/* Set RW pin to low for write*/
	GPIO_voidSetChannelValue( CLCD_CONTROL_PORT, CLCD_RW_PIN, GPIOx_PIN_LOW );

	/* Send the command to the data pins*/
	GPIO_voidSetChannelGroupValue( CLCD_DATA_PORT, CLCD_DATA_STARTING_PIN, CLCD_DATA_WIDTH, Copy_u8Command );

	/* Send Enable pulse */
	GPIO_voidSetChannelValue( CLCD_CONTROL_PORT, CLCD_E_PIN, GPIOx_PIN_HIGH );
	STK_voidBusyWait( CLCD_ENABLE_WAIT );
	GPIO_voidSetChannelValue( CLCD_CONTROL_PORT, CLCD_E_PIN, GPIOx_PIN_LOW );
}



void CLCD_voidSendData( u8 Copy_u8Data )
{
	u8 Local_u8Data;

	/* Set RS pin to high for Data */
	GPIO_voidSetChannelValue( CLCD_CONTROL_PORT, CLCD_RS_PIN, GPIOx_PIN_HIGH );

	/* Set RW pin to low for write*/
	GPIO_voidSetChannelValue( CLCD_CONTROL_PORT, CLCD_RW_PIN, GPIOx_PIN_LOW );

	/* Send the command to the data pins*/
	GPIO_voidSetChannelGroupValue( CLCD_DATA_PORT, CLCD_DATA_STARTING_PIN, CLCD_DATA_WIDTH, Copy_u8Data );

	/* Send Enable pulse */
	GPIO_voidSetChannelValue( CLCD_CONTROL_PORT, CLCD_E_PIN, GPIOx_PIN_HIGH );
	STK_voidBusyWait( CLCD_ENABLE_WAIT );
	GPIO_voidSetChannelValue( CLCD_CONTROL_PORT, CLCD_E_PIN, GPIOx_PIN_LOW );
}



void CLCD_voidInit(void)
{

	/* Wait for more than 30ms */
	STK_voidBusyWait( CLCD_START_WAIT );

	/* Function Set Command : 2 Lines and 5*7 Font size */
	CLCD_voidSendCommand( CLCD_2LINES_5MUL8 );

	/* Display ON/OFF Command : Display Enable, Cursor Disable and No Blinking Cursor*/
	CLCD_voidSendCommand( CLCD_DISPLAY );

	/* Display Clear Command */
	CLCD_voidSendCommand( CLCD_CLR_SCREEN );

	/* Set Cursor Start Position */
	CLCD_voidSendCommand( CLCD_START_POSITION );
}



void CLCD_voidSetCursor ( u8 Copy_u8XPosition, u8 Copy_u8YPosition )
{
	/* For the second line display add 0x40 to the Address */
	u8 Local_u8Address = ( Copy_u8XPosition * 0x40 ) + ( Copy_u8YPosition );

	/* Set bit 7 for DDRAM Address Command then send the Command */
	CLCD_voidSendCommand( Local_u8Address + 128 );
}



void CLCD_voidClearDisplay ( void )
{
	CLCD_voidSendCommand( CLCD_CLEAR_DISPLAY );
}


void CLCD_voidSendString( const char* Ptr_u8Data, u8 Copy_u8XPosition, u8 Copy_u8YPosition )
{
	u8 Local_u8DataCounter = 0;
	u8 Local_u8AddressCounter = 0;

	CLCD_voidSetCursor( Copy_u8XPosition, Copy_u8YPosition );

	while ( Ptr_u8Data[ Local_u8DataCounter ] != '\0' )
	{
		CLCD_voidSendData( Ptr_u8Data[Local_u8DataCounter++] );
		Local_u8AddressCounter++;

		if ( ( Local_u8AddressCounter ) == ( 16 - Copy_u8YPosition ) && ( Copy_u8XPosition == CLCD_Row_1 ) )
		{
			CLCD_voidSendCommand( CLCD_SECOND_LINE );
			Local_u8AddressCounter = 0;
			Copy_u8YPosition = 0;
			Copy_u8XPosition = CLCD_Row_2;
		}
	}
}



void CLCD_voidWriteSpecialCharacter ( const char* Ptr_u8Data, u8 Copy_u8BlockNumber, u8 Copy_u8XPosition, u8 Copy_u8YPosition )
{
	u8 Local_u8Counter;

	/* Calculate CGRAM address whose each block is 8 bytes */
	u8 Local_u8CGRAMAddress = 8 * Copy_u8BlockNumber;

	/* Send CGRAM command to LCD, with setting bit 6 and clearing bit 7 */
	CLCD_voidSendCommand( Local_u8CGRAMAddress + 64 );

	/* Writing The pattern to the CGRAM */
	for ( Local_u8Counter = 0; Local_u8Counter < CLCD_CGRAM_BLOCK_NUMBER; Local_u8Counter++ )
	{
		CLCD_voidSendData( Ptr_u8Data[ Local_u8Counter ] );
	}

	/* Go back to the DDRAM to display data */
	CLCD_voidSetCursor( Copy_u8XPosition, Copy_u8YPosition );

	/* Display the pattern written in the CGRAM */
	CLCD_voidSendData( Copy_u8BlockNumber );
}



void CLCD_voidWriteNumber ( u32 Copy_u32Number, u8 Copy_u8XPosition, u8 Copy_u8YPosition )
{
	u8 Local_u8Counter = 0;
	u32 Local_u32Number = Copy_u32Number;

	while ( Local_u32Number != 0 )
	{
		Local_u32Number /= 10;
		Local_u8Counter++;
	}

	while ( Copy_u32Number != 0 )
	{
		CLCD_voidSetCursor( Copy_u8XPosition, ( Copy_u8YPosition + ( --Local_u8Counter ) ) );
		CLCD_voidSendData( ( Copy_u32Number % 10 ) + 48 );
		Copy_u32Number /= 10;
	}
}
