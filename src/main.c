
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "IR_interface.h"
#include "LED_interface.h"


void voidDetermineKey(u8 Copy_u8Key)
{
	switch(Copy_u8Key)
	{
		case ONE		:	 LED_voidShiftLedRightLed();            break;
		case TWO		:	 LED_voidLedOnLedOut();          		break;
		case THREE		:	 LED_voidTFlashingLed();                break;

	}
}
void main (void)
{
	/* RCC Initialize */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(APB2, IOPA); /* GPIOA Enable Clock */

	MGPIO_voidSetPinDirection(GPIOA,PIN0,INPUT_FLOATING); /* A0 Input Floating        */
	MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP); /* A1 OUTPUT_SPEED_2MHZ_PP        */
	MGPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP); /* A2 OUTPUT_SPEED_2MHZ_PP        */
	MGPIO_voidSetPinDirection(GPIOA,PIN3,OUTPUT_SPEED_2MHZ_PP); /* A3 OUTPUT_SPEED_2MHZ_PP        */
	MGPIO_voidSetPinDirection(GPIOA,PIN4,OUTPUT_SPEED_2MHZ_PP); /* A4 OUTPUT_SPEED_2MHZ_PP        */
	MGPIO_voidSetPinDirection(GPIOA,PIN5,OUTPUT_SPEED_2MHZ_PP); /* A5 OUTPUT_SPEED_2MHZ_PP        */
	MGPIO_voidSetPinDirection(GPIOA,PIN6,OUTPUT_SPEED_2MHZ_PP); /* A6 OUTPUT_SPEED_2MHZ_PP        */
	MGPIO_voidSetPinDirection(GPIOA,PIN7,OUTPUT_SPEED_2MHZ_PP); /* A7 OUTPUT_SPEED_2MHZ_PP        */
	MGPIO_voidSetPinDirection(GPIOA,PIN8,OUTPUT_SPEED_2MHZ_PP); /* A8 OUTPUT_SPEED_2MHZ_PP        */


	/* EXTI Initializtion */
	MEXTI_voidSetCallBack(HIR_voidGetFrame, LINE0);
	MEXTI_voidInit(); /* A0 EXTI0 Enabled / Falling Edge */

	/* Enable EXTI0 from NVIC */
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(6); /* EXTI0 */

	/* SysTick Init */
	MSTK_voidInit();

	while(1)
	{
		HIR_voidSetCallBack(voidDetermineKey);
	}


}
