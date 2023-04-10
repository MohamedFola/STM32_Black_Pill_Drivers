/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : MCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : SYSTICK                              */
/*************************************************************/
/*************************************************************/

#ifndef _SYSTICK_PRIVATE_H_
#define _SYSTICK_PRIVATE_H_


#define STK_BASE_ADDRESS    0xE000E010

typedef struct
{
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VAL   ;
	volatile u32 CALIB ;
}STK_MemMap_t;

#define SYSTICK             ( ( volatile STK_MemMap_t* )( STK_BASE_ADDRESS ) )


typedef enum
{
	STK_CTRL_ENABLE            ,
	STK_CTRL_TICKINT           ,
	STK_CTRL_CLKSOURCE         ,
	STK_CTRL_COUNTINGFLAG = 16 ,
	STK_CALIB_TENMS       = 0  ,
	STK_CALIB_SKEW        = 30 ,
	STK_CALIB_NOREF            ,
}STK_Bits_t;



#define STK_MASK                  0x00FFFFFF


#endif /* _SYSTICK_PRIVATE_H_ */
