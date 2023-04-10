/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : HCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : Character LCD                        */
/*************************************************************/
/*************************************************************/


#ifndef _CLCD_PRIVATE_H_
#define _CLCD_PRIVATE_H_

#define CLCD_START_WAIT                    40000
#define CLCD_ENABLE_WAIT                   2000

#define CLCD_DATA_WIDTH                    8

#define CLCD_CLR_SCREEN                    0x01

#define CLCD_2LINES_5MUL8                  0x38


#define CLCD_DISPLAY_OFF_CURSOR_OFF        0x08
#define CLCD_DISPLAY_ON_CURSOR_OFF         0x0C
#define CLCD_DISPLAY_ON_CURSOR_ON          0x0E
#define CLCD_DISPLAY_ON_CURSOR_BLINK       0x0F

#define CLCD_START_POSITION                0x80

#define CLCD_SECOND_LINE                   0xC0

#define CLCD_CGRAM_BLOCK_NUMBER            8



#endif /* _CLCD_PRIVATE_H_ */
