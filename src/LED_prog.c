/*   Author  : FATMA           */
/*   Date    : 30 sep 2021    */
/*   Version : V1              */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"
#include "DELAY.h"



 void LED_voidShiftLedRightLed(void){
	 //Right to Left
		for(u8 LedNumber = 0; LedNumber < 8; LedNumber++){
			MGPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], HIGH);
			  // delay
				delay_ms(350);
		  MGPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], LOW);
		  // delay
		  delay_ms(350);
		}

	//Left to Right
	  for(u8 LedNumber = 6; LedNumber > 0; LedNumber--){
		  MGPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], HIGH);
		  // delay
		  delay_ms(350);
		  MGPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], LOW);
		  // delay
		  delay_ms(350);
	 }

	 }



void LED_voidLedOnLedOut(void){
		    u8 Local_u8Decreasing=3;
			u8 Local_u8Increasing=1;
	//From in to out
	for(u8 LedNumber = 4; LedNumber < 8; LedNumber++){
		MGPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], HIGH);
		MGPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[Local_u8Decreasing], HIGH);
		  // delay
		delay_ms(350);

	  MGPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], LOW);
	  MGPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[Local_u8Decreasing], LOW);

	  Local_u8Decreasing--;
	  // delay
	  delay_ms(350);

	}
		//From out to in
	for(u8 LedNumber = 6; LedNumber >= 4; LedNumber--){
		MGPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], HIGH);
		MGPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[Local_u8Increasing], HIGH);
		  // delay
		delay_ms(350);

	  MGPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], LOW);
	  MGPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[Local_u8Increasing], LOW);

	  Local_u8Increasing++;

	  // delay
	  delay_ms(350);

}
	 }



void LED_voidTFlashingLed(void){
	//Led on
for(u8 iteration=0; iteration<3; iteration++)
{
	for(u8 LedNumber = 0; LedNumber < 8; LedNumber++){
		MGPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], HIGH);
	}
	  // delay
	delay_ms(350);
		for(u8 LedNumber = 0; LedNumber < 8; LedNumber++){
			MGPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], LOW);
	}
		  // delay
		delay_ms(350);
	 }
}
