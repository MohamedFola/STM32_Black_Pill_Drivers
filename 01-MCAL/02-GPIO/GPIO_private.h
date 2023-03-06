/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : MCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : GPIO                                 */
/*************************************************************/
/*************************************************************/

#ifndef _GPIO_PRIVATE_H_
#define _GPIO_PRIVATE_H_


#define GPIOC_BASE_ADDRESS                 ( u32 ) ( 0x40020800 )
#define GPIOB_BASE_ADDRESS                 ( u32 ) ( 0x40020400 )
#define GPIOA_BASE_ADDRESS                 ( u32 ) ( 0x40020000 )


typedef struct
{
	volatile u32 MODER;
	volatile u32 OTYPER;
	volatile u32 OSPEEDR;
	volatile u32 PUPDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u16 BSRR_Set;
	volatile u16 BSRR_Reset;
	volatile u32 LCKR;
	volatile u32 AFRL;
	volatile u32 AFRH;
}GPIO_MemMap_t;

#define GPIOA      ( ( volatile GPIO_MemMap_t* ) ( GPIOA_BASE_ADDRESS ) )
#define GPIOB      ( ( volatile GPIO_MemMap_t* ) ( GPIOB_BASE_ADDRESS ) )
#define GPIOC      ( ( volatile GPIO_MemMap_t* ) ( GPIOC_BASE_ADDRESS ) )


#define GPIO_MAX_PORT       3
#define GPIO_MAX_PIN        16
#define GPIO_PIN_MAX_VALUE  2



#endif /* _GPIO_PRIVATE_H_ */
