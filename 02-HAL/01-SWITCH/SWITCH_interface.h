/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : HAL                                  */
/*            Version : 1.00                                 */
/*            SWC     : Switch                               */
/*************************************************************/
/*************************************************************/

#ifndef _SWITCH_INTERFACE_H_
#define _SWITCH_INTERFACE_H_

typedef struct
{
	u8 Switch_Pin  : 4 ;
	u8 Switch_Port : 4 ;
}Switch_t;


typedef struct
{
	u8 Swtich_StartPin : 4 ;
	u8 Switch_Port     : 2 ;
	u8 Switch_width    : 2 ;
}Multiple_Switches_t;


void SWITCH_voidGetSwtichStatus (
		Switch_t* Ptr_Swtich   ,
		u16*      Ptr_u16Value );


/***********************************************************************************
 * When using this function your Switches have to be successive in the connection  *
 * and they must have the same type of connection                                  *
 ***********************************************************************************/
u8 SWITCH_u8GetMultipleSwitchesStatus (
		Multiple_Switches_t* Ptr_Switchs  ,
		u16*                 Ptr_u16Value );


#endif /* _SWITCH_INTERFACE_H_ */
