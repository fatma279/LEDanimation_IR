/*   Author  : FATMA           */
/*   Date    : 24 July 2021    */
/*   Version : V1              */



#ifndef LED_CONFIG_H
#define LED_CONFIG_H

 /* Options for LED PORT:     GPIOA
				                   GPIOB
								   GPIOC */
#define LED_PORT  GPIOA

/* LEDS SIZE */
#define LEDs_SIZE      8

/* optins pins for LEDs from 0 to 15 */

 u8 ArrayOfLeds[LEDs_SIZE] ={PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7, PIN8};





#endif
