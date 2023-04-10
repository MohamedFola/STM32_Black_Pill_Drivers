/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : MCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : SYSTICK                              */
/*************************************************************/
/*************************************************************/

#ifndef _SYSTICK_INTERFACE_H_
#define _SYSTICK_INTERFACE_H_


#define STK_AHB_DIV_8             0
#define STK_AHB_CLK               1

#define STK_SINGLE_INTERVAL       0
#define STK_PERIODIC_INTERVAL     1


/***********************************************
 * Name        : STK_voidSetClockSource        *
 * Return type : void                          *
 * Arguments   : Copy_ClockSource --> u8       *
 * Type        : Synchronous                   *
 * Description : Choosing the Clock Source     *
 **********************************************/
void STK_voidSetClockSource ( u8 Copy_ClockSource );



/*****************************************************
 * Name        : STK_voidBusyWait                    *
 * Return type : void                                *
 * Arguments   : Copy_Ticks --> u32                  *
 * Type        : Synchronous                         *
 * Description : Busy Waiting for a Certain time     *
 *****************************************************/
void STK_voidBusyWait ( u32 Copy_Ticks );



/*************************************************************
 * Name        : STK_voidSetTimeInterval                     *
 * Return type : void                                        *
 * Arguments   :                                             *
 * 		Copy_Ticks        --> u32                            *
 * 		Copy_IntervalType --> u8		                     *
 *      Ptr_CallBackFunction  --> pointer to function        *
 * Type        : Asynchronous                                *
 * Description :                                             *
 * 		Starts a Single or Periodic Interval Asynchronous    *
 * 		Wait                                                 *
 *************************************************************/
void STK_voidSetTimeInterval (
		u32 Copy_Ticks                     ,
		u8  Copy_IntervalType              ,
		void ( *Ptr_CallBackFunction )( void )
);



/***************************************************************
 * Name        : STK_u32GetElapsedTicks                        *
 * Return type : u32                                           *
 * Arguments   : void                                          *
 * Type        : Synchronous                                   *
 * Description : Returns the Ticks that has been Ticked        *
 ***************************************************************/
u32 STK_u32GetElapsedTicks ( void );



/**************************************************
 * Name        : STK_u32GetRemainingTicks         *
 * Return type : u32                              *
 * Arguments   : void                             *
 * Type        : Synchronous                      *
 * Description : Returns the Remaining Ticks      *
 **************************************************/
u32 STK_u32GetRemainingTicks ( void );


#endif /* _SYSTICK_INTERFACE_H_ */
