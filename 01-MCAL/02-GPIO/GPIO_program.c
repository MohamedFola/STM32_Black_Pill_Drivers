/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : MCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : GPIO                                 */
/*************************************************************/
/*************************************************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "GPIO_config.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"


/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/


void GPIO_voidSetChannelValue(
		u8 Copy_u8PortName ,
		u8 Copy_u8PinNumber,
		u8 Copy_u8Value)
{
	if ( Copy_u8PortName < GPIO_MAX_PORT && Copy_u8PinNumber < GPIO_MAX_PIN && Copy_u8Value < GPIO_PIN_MAX_VALUE )
	{
		switch ( Copy_u8PortName )
		{
		case GPIOx_PORTA:
			if ( Copy_u8Value == GPIOx_PIN_HIGH ) SET_BIT( GPIOA->BSRR_Set  , Copy_u8PinNumber );
			else 							      SET_BIT( GPIOA->BSRR_Reset, Copy_u8PinNumber );
			break;

		case GPIOx_PORTB:
			if ( Copy_u8Value == GPIOx_PIN_HIGH ) SET_BIT( GPIOB->BSRR_Set  , Copy_u8PinNumber );
			else 							      SET_BIT( GPIOB->BSRR_Reset, Copy_u8PinNumber );
			break;

		case GPIOx_PORTC:
			if ( Copy_u8Value == GPIOx_PIN_HIGH ) SET_BIT( GPIOC->BSRR_Set  , Copy_u8PinNumber );
			else 							      SET_BIT( GPIOC->BSRR_Reset, Copy_u8PinNumber );
			break;
		}
	}
	else
	{
		/* DO NOTHING */
	}
}


/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/


void GPIO_voidSetPortValue(
		u8  Copy_u8PortName,
		u16 Copy_u8Value)
{

	if ( Copy_u8PortName < GPIO_MAX_PORT )
	{
		switch ( Copy_u8PortName )
		{
		case GPIOx_PORTA:
			GPIOA->BSRR_Set   =    Copy_u8Value  ;
			GPIOA->BSRR_Reset = ~( Copy_u8Value );
			break;

		case GPIOx_PORTB:
			GPIOB->BSRR_Set   =    Copy_u8Value  ;
			GPIOB->BSRR_Reset = ~( Copy_u8Value );
			break;

		case GPIOx_PORTC:
			GPIOC->BSRR_Set   =    Copy_u8Value  ;
			GPIOC->BSRR_Reset = ~( Copy_u8Value );
			break;
		}
	}
	else
	{
		/* DO NOTHING */
	}
}


/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/


void GPIO_voidToggleChannelValue(
		u8 Copy_u8PortName,
		u8 Copy_u8PinNumber)
{

	if ( Copy_u8PortName < GPIO_MAX_PORT && Copy_u8PinNumber < GPIO_MAX_PIN )
	{
		switch ( Copy_u8PortName )
		{
		case GPIOx_PORTA:
			TOG_BIT( GPIOA->ODR, Copy_u8PinNumber ); break;

		case GPIOx_PORTB:
			TOG_BIT( GPIOB->ODR, Copy_u8PinNumber ); break;

		case GPIOx_PORTC:
			TOG_BIT( GPIOC->ODR, Copy_u8PinNumber ); break;
		}
	}
	else
	{
		/* DO NOTHING */
	}
}


/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/


void GPIO_voidSetChannelGroupValue(
		u8  Copy_u8PortName     ,
		u8  Copy_u8PinNumber    ,
		u8  Copy_u8ChannelLength,
		u16 Copy_u8Value)
{
	if ( Copy_u8PortName < GPIO_MAX_PORT && Copy_u8PinNumber < GPIO_MAX_PIN && Copy_u8ChannelLength <= ( GPIO_MAX_PIN - Copy_u8PinNumber ) )
	{
		switch ( Copy_u8PortName )
		{
		case GPIOx_PORTA:
			GPIOA->BSRR_Set   = BitManipulationSetBits( GPIOA->BSRR_Set  , Copy_u8PinNumber, Copy_u8ChannelLength,    Copy_u8Value )  ;
			GPIOA->BSRR_Reset = BitManipulationSetBits( GPIOA->BSRR_Reset, Copy_u8PinNumber, Copy_u8ChannelLength, ~( Copy_u8Value ) );
			break;

		case GPIOx_PORTB:
			GPIOB->BSRR_Set   = BitManipulationSetBits( GPIOB->BSRR_Set  , Copy_u8PinNumber, Copy_u8ChannelLength,    Copy_u8Value )  ;
			GPIOB->BSRR_Reset = BitManipulationSetBits( GPIOB->BSRR_Reset, Copy_u8PinNumber, Copy_u8ChannelLength, ~( Copy_u8Value ) );
			break;

		case GPIOx_PORTC:
			GPIOC->BSRR_Set   = BitManipulationSetBits( GPIOC->BSRR_Set  , Copy_u8PinNumber, Copy_u8ChannelLength,   Copy_u8Value )  ;
			GPIOC->BSRR_Reset = BitManipulationSetBits( GPIOC->BSRR_Reset, Copy_u8PinNumber, Copy_u8ChannelLength, ~(Copy_u8Value ) );
			break;
		}
	}
	else
	{
		/* DO NOTHING */
	}
}


/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/


u8 GPIO_u8GetChannelValue(
		u8   Copy_u8PortName ,
		u8   Copy_u8PinNumber,
		u16* Ptr_u16Value)
{
	u8 Local_u8ErrorStatus = OK;

	if ( Ptr_u16Value != NULL && Copy_u8PortName < GPIO_MAX_PORT && Copy_u8PinNumber < GPIO_MAX_PIN )
	{
		switch ( Copy_u8PortName )
		{
		case GPIOx_PORTA:
			( *Ptr_u16Value ) = GET_BIT( GPIOA->IDR, Copy_u8PinNumber ); break;
		case GPIOx_PORTB:
			( *Ptr_u16Value ) = GET_BIT( GPIOB->IDR, Copy_u8PinNumber ); break;
		case GPIOx_PORTC:
			( *Ptr_u16Value ) = GET_BIT( GPIOC->IDR, Copy_u8PinNumber ); break;
		}
	}
	else
	{
		Local_u8ErrorStatus = NOK;
	}

	return Local_u8ErrorStatus;
}


/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/


u8 GPIO_u8GetChannelGroupValue(
		u8   Copy_u8PortName     ,
		u8   Copy_u8PinNumber    ,
		u8   Copy_u8ChannelLength,
		u16* Ptr_u16Value)
{
	u8 Local_u8ErrorStatus = OK;

	if ( Ptr_u16Value != NULL && Copy_u8PortName < GPIO_MAX_PORT && Copy_u8PinNumber < GPIO_MAX_PIN && Copy_u8ChannelLength <= ( GPIO_MAX_PIN - Copy_u8PinNumber ) )
	{
		switch ( Copy_u8PortName )
		{
		case GPIOx_PORTA:
			( *Ptr_u16Value ) = ( u16 )BitManipulationGetBits( GPIOA->IDR, Copy_u8PinNumber, Copy_u8ChannelLength ); break;
		case GPIOx_PORTB:
			( *Ptr_u16Value ) = ( u16 )BitManipulationGetBits( GPIOB->IDR, Copy_u8PinNumber, Copy_u8ChannelLength ); break;
		case GPIOx_PORTC:
			( *Ptr_u16Value ) = ( u16 )BitManipulationGetBits( GPIOC->IDR, Copy_u8PinNumber, Copy_u8ChannelLength ); break;
		}
	}
	else
	{
		Local_u8ErrorStatus = NOK;
	}


	return Local_u8ErrorStatus;
}
