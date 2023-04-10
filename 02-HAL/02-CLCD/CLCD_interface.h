/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : HCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : Character LCD                        */
/*************************************************************/
/*************************************************************/
/*************************************************************

     VSS  VDD  V0   RS   RW    E   D0   D1   D2   D3   D4   D5   D6   D7    A    K
      |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
	 ------------------------------------------------------------------------------
	| ---------------------------------------------------------------------------- |
	||																			  ||
	||																			  ||
	||																			  ||
	| ---------------------------------------------------------------------------- |
	 ------------------------------------------------------------------------------

Power Pins:
	VSS     --> GND
	VDD     --> 5v
	V0      --> Power Supply to control contrast " You can use potentiometer to control contrast "

Control Pins:
	RS      --> Register Select:   0 for Command -- 1 for Data
	RW      --> Read\!Write:       0 for writing -- 1 for reading
	E       --> Enable

Data Pins:
	D0--D7  --> 8-bit data pins used to send information to the LCD

LED Backlight Pins:
	A       --> LED power supply 5v
	K       --> LED power supply 0v

**************************************************************/


#ifndef _CLCD_INTERFACE_H_
#define _CLCD_INTERFACE_H_

typedef enum
{
	CLCD_Row_1              ,
	CLCD_Row_2              ,

	CLCD_Column_1      = 0  ,
	CLCD_Column_2           ,
	CLCD_Column_3           ,
	CLCD_Column_4           ,
	CLCD_Column_5           ,
	CLCD_Column_6           ,
	CLCD_Column_7           ,
	CLCD_Column_8           ,
	CLCD_Column_9           ,
	CLCD_Column_10          ,
	CLCD_Column_11          ,
	CLCD_Column_12          ,
	CLCD_Column_13          ,
	CLCD_Column_14          ,
	CLCD_Column_15          ,
	CLCD_Column_16          ,

	CLCD_CGRAM_Block_1 = 0  ,
	CLCD_CGRAM_Block_2      ,
	CLCD_CGRAM_Block_3      ,
	CLCD_CGRAM_Block_4      ,
	CLCD_CGRAM_Block_5      ,
	CLCD_CGRAM_Block_6      ,
	CLCD_CGRAM_Block_7      ,
	CLCD_CGRAM_Block_8      ,
}CLCD;


#define CLCD_SECOND_LINE_POS2        0xC0

#define CLCD_CLEAR_DISPLAY           0x01

#define CLCD_SPECIAL_CHAR_SIZE       8


void CLCD_voidSendToCLCD ( u8 Copy_Data, u8 Copy_RS );

void CLCD_voidSendCommand ( u8 Copy_u8Command );

void CLCD_voidSendData ( u8 Copy_u8Data );

void CLCD_voidInit ( void );

void CLCD_voidSetCursor ( u8 Copy_u8XPosition, u8 Copy_u8YPosition );

void CLCD_voidClearDisplay ( void );

void CLCD_voidSendString ( const char* Ptr_u8Data, u8 Copy_u8XPosition, u8 Copy_u8YPosition );

void CLCD_voidWriteSpecialCharacter ( const char* Ptr_u8Data, u8 Copy_u8BlockNumber, u8 Copy_u8XPosition, u8 Copy_u8YPosition );

void CLCD_voidWriteNumber ( u32 Copy_u32Number, u8 Copy_u8XPosition, u8 Copy_u8YPosition );


#endif /* _CLCD_INTERFACE_H_ */
