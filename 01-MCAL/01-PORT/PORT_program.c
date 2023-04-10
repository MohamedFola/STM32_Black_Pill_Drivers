/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : MCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : PORT                                 */
/*************************************************************/
/*************************************************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"


#include "../02-GPIO/GPIO_private.h"
#include "PORT_interface.h"
#include "PORT_config.h"
#include "PORT_private.h"



void PORT_voidInit( void )
{
	/* Load the mode to GPIOx_MODER register */
	GPIOA->MODER = GPIOA_Mode;
	GPIOB->MODER = GPIOB_Mode;
	GPIOC->MODER = GPIOC_Mode;

	/* Load the output type to GPIOx_OTYPER register */
	GPIOA->OTYPER = GPIOA_Output_Type;
	GPIOB->OTYPER = GPIOB_Output_Type;
	GPIOC->OTYPER = GPIOC_Output_Type;

	/* Load Speed to OSPEEDR */
	GPIOA->OSPEEDR = GPIOA_Speed ;
	GPIOB->OSPEEDR = GPIOB_Speed ;
	GPIOC->OSPEEDR = GPIOC_Speed ;

	/* Load Pull up or Pull down to GPIOx_PUPDR register */
	GPIOA->PUPDR = GPIOA_PUPD ;
	GPIOB->PUPDR = GPIOB_PUPD ;
	GPIOC->PUPDR = GPIOC_PUPD ;


	/* Alternative function selection */
	GPIOA->AFRL = ( u32 )( GPIOA_AF >> 0 );
	GPIOB->AFRL = ( u32 )( GPIOB_AF >> 0 );
	GPIOC->AFRL = ( u32 )( GPIOC_AF >> 0 );

	GPIOA->AFRH = ( u32 )( GPIOA_AF >> 32 );
	GPIOB->AFRH = ( u32 )( GPIOB_AF >> 32 );
	GPIOC->AFRH = ( u32 )( GPIOC_AF >> 32 );

}
