/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : MCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : NVIC                                 */
/*************************************************************/
/*************************************************************/

#ifndef _NVIC_PRIVATE_H_
#define _NVIC_PRIVATE_H_


#define NVIC_BASE_ADDRESS              (u32) 0xE000E000

/* Interrupt set-enable registers */
#define NVIC_ISER0       	  	      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x100 ) )
#define NVIC_ISER1		  		      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x104 ) )
#define NVIC_ISER2          	      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x108 ) )
#define NVIC_ISER3         		      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x10c ) )
#define NVIC_ISER4    			      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x110 ) )
#define NVIC_ISER5   			      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x114 ) )
#define NVIC_ISER6    			      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x118 ) )
#define NVIC_ISER7    			      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x11c ) )


/* Interrupt clear-enable registers */
#define NVIC_ICER0       	          *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x180 ) )
#define NVIC_ICER1		  		      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x184 ) )
#define NVIC_ICER2          	      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x188 ) )
#define NVIC_ICER3         		      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x18c ) )
#define NVIC_ICER4    			      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x190 ) )
#define NVIC_ICER5   			      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x194 ) )
#define NVIC_ICER6    			      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x198 ) )
#define NVIC_ICER7    			      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x19c ) )


/* Interrupt set-pending register */
#define NVIC_ISPR0       	          *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x200 ) )
#define NVIC_ISPR1		  		      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x204 ) )
#define NVIC_ISPR2          	      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x208 ) )
#define NVIC_ISPR3         		      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x20c ) )
#define NVIC_ISPR4    			      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x210 ) )
#define NVIC_ISPR5   			      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x214 ) )
#define NVIC_ISPR6    			      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x218 ) )
#define NVIC_ISPR7    			      *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x21c ) )


/* Interrupt clear-pending register */
#define NVIC_ICPR0                    *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x280 ) )
#define NVIC_ICPR1                    *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x284 ) )
#define NVIC_ICPR2                    *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x288 ) )
#define NVIC_ICPR3                    *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x28c ) )
#define NVIC_ICPR4                    *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x290 ) )
#define NVIC_ICPR5                    *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x294 ) )
#define NVIC_ICPR6                    *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x298 ) )
#define NVIC_ICPR7                    *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x29c ) )


/* Interrupt active bit register */
#define NVIC_IABR0                    *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x300 ) )
#define NVIC_IABR1                    *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x304 ) )
#define NVIC_IABR2                    *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x308 ) )
#define NVIC_IABR3                    *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x30c ) )
#define NVIC_IABR4                    *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x310 ) )
#define NVIC_IABR5                    *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x314 ) )
#define NVIC_IABR6                    *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x318 ) )
#define NVIC_IABR7                    *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0x31c ) )


/* Interrupt priority register */
#define NVIC_IPR                       ( ( volatile u8* ) ( NVIC_BASE_ADDRESS + 0x400 ) )


/* Interrupt priority register */
#define NVIC_STIR                     *( ( volatile u32* ) ( NVIC_BASE_ADDRESS + 0xE00 ) )


#define	SCB_AIRCR				      *((volatile u32*)(0xE000ED0C))

#define SCB_AIRCR_KEY_VALUE            0x05FA0000


typedef enum
{
	_4Bit_Group_0Bit_SubGroup,
	_3Bit_Group_1Bit_SubGroup,
	_2Bit_Group_2Bit_SubGroup,
	_1Bit_Group_3Bit_SubGroup,
	_0Bit_Group_4Bit_SubGroup,
}NVIC_GROUP_t;


#endif /* _NVIC_PRIVATE_H_ */
