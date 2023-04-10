/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : MCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : NVIC                                 */
/*************************************************************/
/*************************************************************/

#ifndef _NVIC_CONFIG_H_
#define _NVIC_CONFIG_H_


/******************************************
 * NVIC Priority Distribution Selection   *
 * Options:                               *
 * 		1 --> _4Bit_Group_0Bit_SubGroup   *
 * 		2 --> _3Bit_Group_1Bit_SubGroup   *
 * 		3 --> _2Bit_Group_2Bit_SubGroup   *
 * 		4 --> _1Bit_Group_3Bit_SubGroup   *
 * 		5 --> _0Bit_Group_4Bit_SubGroup   *
 ******************************************/
#define NVIC_PRIORITY_DISTRIBUTION      _2Bit_Group_2Bit_SubGroup


#endif /* _NVIC_CONFIG_H_ */
