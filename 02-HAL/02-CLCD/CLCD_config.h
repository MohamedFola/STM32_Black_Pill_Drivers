/*************************************************************/
/*************************************************************/
/*            Author  : Mohamed Hassan Hassan                */
/*            Layer   : HCAL                                 */
/*            Version : 1.00                                 */
/*            SWC     : Character LCD                        */
/*************************************************************/
/*************************************************************/


#ifndef _CLCD_CONFIG_H_
#define _CLCD_CONFIG_H_

/*
 Options:

 Ports:
	GPIO_PORTA
    GPIO_PORTB
    GPIO_PORTC

 Pins:
    GPIO_PIN0
    GPIO_PIN1
    GPIO_PIN2
    GPIO_PIN3
    GPIO_PIN4
    GPIO_PIN5
    GPIO_PIN6
    GPIO_PIN7
    GPIO_PIN8
    GPIO_PIN9
    GPIO_PIN10
    GPIO_PIN11
    GPIO_PIN12
    GPIO_PIN13
    GPIO_PIN14
    GPIO_PIN15
*/


#define CLCD_DATA_PORT             GPIO_PORTA
#define CLCD_CONTROL_PORT          GPIO_PORTC


#define CLCD_DATA_STARTING_PIN     GPIO_PIN0
#define CLCD_RS_PIN                GPIO_PIN13
#define CLCD_RW_PIN                GPIO_PIN14
#define CLCD_E_PIN                 GPIO_PIN15


/*
	Display Options:
		1) CLCD_DISPLAY_OFF_CURSOR_OFF
		2) CLCD_DISPLAY_ON_CURSOR_OFF
		3) CLCD_DISPLAY_ON_CURSOR_ON
		4) CLCD_DISPLAY_ON_CURSOR_BLINK
*/
#define CLCD_DISPLAY              CLCD_DISPLAY_ON_CURSOR_OFF




#endif /* _CLCD_CONFIG_H_ */
