/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : MCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : EXTI                                 */
/*************************************************************/
/*************************************************************/

#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_


#define EXTI_BASE_ADDRESS     0x40013C00
#define SYSCFG_BASE_ADDRESS   0x40013800

#define SYSCFG_EXTICR1       *((volatile u32*)(SYSCFG_BASE_ADDRESS + 0x08))
#define SYSCFG_EXTICR2       *((volatile u32*)(SYSCFG_BASE_ADDRESS + 0x0C))
#define SYSCFG_EXTICR3       *((volatile u32*)(SYSCFG_BASE_ADDRESS + 0x10))
#define SYSCFG_EXTICR4       *((volatile u32*)(SYSCFG_BASE_ADDRESS + 0x14))

typedef struct
{
	volatile u32 IMR;        /* Interrupt Mask Register */
	volatile u32 EMR;        /* Event Mask Register */
	volatile u32 RTSR;       /* Rising Trigger Selection Register */
	volatile u32 FTSR;       /* Falling Trigger Selection Register */
	volatile u32 SWIER;      /* Software Interrupt Event Register */
	volatile u32 PR;         /* Pending Register */
}EXTI_t;

#define EXTI                 ((volatile EXTI_t*)(EXTI_BASE_ADDRESS))

#define SYSCFG_MASK          0b1111


#endif /* _EXTI_PRIVATE_H_ */
