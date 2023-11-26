
#include "LIB/BIT_MATH.h"
#include "LIB/stm32f103xx.h"
#include "LIB/Error_type.h"

#include "MCAL/SYSTICK/STK_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/UART/UART_interface.h"
#include "MCAL/RCC/RCC_interface.h"

#include "HAL/BUZZER/BUZZER_Interface.h"
#include "HAL/LED/LED_Interface.h"

#include "HAL/DCM/ROBOT_interface.h"
#include "HAL/LED/LED_interface.h"
#include "HAL/Buzzer/Buzzer_interface.h"


UART_configStruct_t Copy_PstrUARTConfig =
{
		9600,
		'#',
		UART_u8_STOP_1_BIT,
		UART_u8_8_BITS,
		UART_u8_PARITY_DISABLED,
		UART_u8_POLLING
};


int main(void)
{
	uint8_t Local_u8RecieveData;

 	STK_u8Init(STK_u8_AHB);

	/*object choose HSI as clock source*/
	RCC_u8InitSysClk();

	/*object to enable RCC for UART*/
	RCC_u8EnableDisablPeripheralClk(RCC_u8_USART2, RCC_u8_Enable);

	/*object to enable RCC for GPIO*/
	RCC_u8EnableDisablPeripheralClk(RCC_u8_GPIOA, RCC_u8_Enable);
	RCC_u8EnableDisablPeripheralClk(RCC_u8_GPIOB, RCC_u8_Enable);
	RCC_u8EnableDisablPeripheralClk(RCC_u8_GPIOC, RCC_u8_Enable);

	/*initialize UART peripheral*/
	UART_u8Init(UART_u8_2, &Copy_PstrUARTConfig);

	/*select PIN A9 as TX */
	GPIO_u8SetPinMode(GPIO_u8_GPIOA,GPIO_u8_PIN2, GPIO_u8_OUTPUT_AF_PP_10MHZ);

	/*select PIN A10 as RX*/
	GPIO_u8SetPinMode(GPIO_u8_GPIOA,GPIO_u8_PIN3, GPIO_u8_INPUT_FLOATING);

	/*select LEDs as output */
	GPIO_u8SetPinMode(GPIO_u8_GPIOA,RED_LED_PIN, GPIO_u8_OUTPUT_AF_PP_10MHZ);
	GPIO_u8SetPinMode(GPIO_u8_GPIOA,WHITE_LED_PIN, GPIO_u8_OUTPUT_AF_PP_10MHZ);

	/*select BUZZER as output */
	GPIO_u8SetPinMode(GPIO_u8_GPIOC,GPIO_u8_PIN13, GPIO_u8_OUTPUT_GP_PP_10MHZ);


	for(;;)
	{
		UART_u8ReceiveByte(UART_u8_2,&Local_u8RecieveData);

		switch (Local_u8RecieveData)
		{
			case 'F': ROBOT_voidForward();	HLED_voidTurnOff(GPIO_u8_GPIOC,GPIO_u8_PIN13); HLED_voidTurnOff(GPIO_u8_GPIOC,GPIO_u8_PIN15);	 break;
			case 'B': ROBOT_voidBackward(); HLED_voidTurnOff(GPIO_u8_GPIOC,GPIO_u8_PIN13); HLED_voidTurnOff(GPIO_u8_GPIOC,GPIO_u8_PIN15);    break;
			case 'R': ROBOT_voidRight(); 	HLED_voidTurnOff(GPIO_u8_GPIOC,GPIO_u8_PIN13); HLED_voidTurnOff(GPIO_u8_GPIOC,GPIO_u8_PIN15);	 break;
			case 'L': ROBOT_voidLeft();		HLED_voidTurnOff(GPIO_u8_GPIOC,GPIO_u8_PIN13); HLED_voidTurnOff(GPIO_u8_GPIOC,GPIO_u8_PIN15);	 break;
			case 'S': ROBOT_voidStop();		HLED_voidTurnOn(GPIO_u8_GPIOC,GPIO_u8_PIN13);  HLED_voidTurnOn(GPIO_u8_GPIOC,GPIO_u8_PIN15);     break;
			case 'W': HLED_voidTurnOff(GPIO_u8_GPIOB,GPIO_u8_PIN1);	HLED_voidTurnOff(GPIO_u8_GPIOB,GPIO_u8_PIN2);							 break;
			case 'w': HLED_voidTurnOff(GPIO_u8_GPIOB,GPIO_u8_PIN1);	HLED_voidTurnOff(GPIO_u8_GPIOB,GPIO_u8_PIN2);					    	 break;
			case 'X': HBuzzer_voidTurnOn(GPIO_u8_GPIOB,GPIO_u8_PIN11);                  												   	 break;
			case 'x': HBuzzer_voidTurnOff(GPIO_u8_GPIOB,GPIO_u8_PIN11);                            											 break;
			case 'Y': HLED_voidTurnOn(GPIO_u8_GPIOB,GPIO_u8_PIN3);  HLED_voidTurnOn(GPIO_u8_GPIOB,GPIO_u8_PIN4);                             break;
			case 'y': HLED_voidTurnOff(GPIO_u8_GPIOB,GPIO_u8_PIN3); HLED_voidTurnOff(GPIO_u8_GPIOB,GPIO_u8_PIN4);                            break;
			case 'Z': HLED_voidTurnOn(GPIO_u8_GPIOC,GPIO_u8_PIN15);                   											           	 break;
			case 'z': HLED_voidTurnOff(GPIO_u8_GPIOC,GPIO_u8_PIN15);                       												     break;
			default:						                                                     											 break;

		}
	}

}

