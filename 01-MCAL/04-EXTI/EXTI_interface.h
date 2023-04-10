/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : MCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : EXTI                                 */
/*************************************************************/
/*************************************************************/

#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_


/* EXTI sense mode options */
#define EXTI_RISING_EDGE_TRIGGER    0
#define EXTI_FALLING_EDGE_TRIGGER   1
#define EXTI_BOTH_EDGES_TRIGGER     2


/* EXTI line state options */
#define EXTI_ENABLE                 1
#define EXTI_DISABLE                0


/* EXTI line options */
typedef enum
{
	EXTI_0       ,
	EXTI_1       ,
	EXTI_2       ,
	EXTI_3       ,
	EXTI_4       ,
	EXTI_5       ,
	EXTI_6       ,
	EXTI_7       ,
	EXTI_8       ,
	EXTI_9       ,
	EXTI_10      ,
	EXTI_11      ,
	EXTI_12      ,
	EXTI_13      ,
	EXTI_14      ,
	EXTI_15      ,
	EXTI_16      ,     /* PVD output */
	EXTI_17      ,     /* RTC Alarm event  */
	EXTI_18      ,     /* USB OTG FS Wake-up event */
	EXTI_21 = 21 ,     /* RTC Tamper and TimeStamp events */
	EXTI_22 = 22 ,     /* RTC Wake-up event */
}EXTI_Line_t;


/* Port Options */
typedef enum
{
	PAx_Pin     ,
	PBx_Pin     ,
	PCx_Pin     ,
	PDx_Pin     ,
	PEx_Pin     ,
	PHx_Pin = 7 ,
}EXTI_px_t;



/****************************************************************
 * Name        : EXTI_voidSelectPort                            *
 * Return type : void                                           *
 * Arguments   :                                                *
 *			1 --> Copy_u8EXTI_line, u8                          *
 *			2 --> Copy_u8Port, u8                               *
 *											                    *
 * Description : Selects the pin for a Specific EXTI            *
 ****************************************************************/
void EXTI_voidSelectPort (
		u8 Copy_u8EXTI_line ,
		u8 Copy_u8Port      );


/*************************************************************************
 * Name        : EXTI_voidSelectTrigger                                  *
 * Return type : void                                                    *
 * Arguments   :                                                         *
 *			1 --> Copy_u8EXTI_line, u8                                   *
 *			2 --> Copy_u8TriggerSelection, u8                            *
 *											                             *
 * Description : Configures the Trigger Signal EXTI for a certain line   *
 *************************************************************************/
void EXTI_voidSelectTrigger (
		u8 Copy_u8EXTI_line        ,
		u8 Copy_u8TriggerSelection );


/*******************************************************************
 * Name        : EXTI_voidControlLine                              *
 * Return type : void                                              *
 * Arguments   :                                                   *
 *			1 --> Copy_u8EXTI_line, u8                             *
 *			2 --> Copy_u8LineState, u8                             *
 *											                       *
 * Description : Sets the State for a Specific EXTI line           *
 *******************************************************************/
void EXTI_voidControlLine (
		u8 Copy_u8EXTI_line ,
		u8 Copy_u8LineState );


/*************************************************************************
 * Name        : EXTI_voidSoftwareTrigger                            	 *
 * Return type : void                                                    *
 * Arguments   :                                                   		 *
 *			1 --> Copy_u8EXTI_line, u8                             		 *
 *											                           	 *
 * description : Sets the State for a Specific EXTI line by Software     *
 *************************************************************************/
void EXTI_voidSoftwareTrigger ( u8 Copy_u8EXTI_line );


/*************************************************************************
 * Name        : EXTI_voidClearFlag                                 	 *
 * Return type : void                                                    *
 * Arguments   :                                                   		 *
 *			1 --> Copy_u8EXTI_line, u8                             		 *
 *											                           	 *
 * Description : Clears Flag for a Specific EXTI line by Software        *
 *************************************************************************/
void EXTI_voidClearFlag ( u8 Copy_u8EXTI_line );


/*************************************************************************
 * Name        : EXTI_voidSetCallBack                                 	 *
 * Return type : void                                                    *
 * Arguments   :                                                   		 *
 *			1 --> Copy_u8EXTI_line, u8                                   *
 *			2 --> ptr_Function, pointer to function                      *
 *											                           	 *
 * Description : Sets the Call Back Function for a Specific EXTI line    *
 *************************************************************************/
void EXTI_voidSetCallBack (
		u8 Copy_u8EXTI_line           ,
		void ( *ptr_Function )( void ) );


#endif /* _EXTI_INTERFACE_H_ */
