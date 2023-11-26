
/*MCAL Layer*/
#include "MCAL/SYSTICK/STK_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/UART/UART_interface.h"
#include "MCAL/RCC/RCC_interface.h"

/*HAL Layer*/
#include "HAL/DCM/ROBOT_interface.h"

#define Delay 50

/*Uart Configuration*/
UART_configStruct_t BT_UARTConfig =
{
		9600,
		'\0',
		UART_u8_STOP_1_BIT,
		UART_u8_8_BITS,
		UART_u8_PARITY_DISABLED,
		UART_u8_POLLING
};


int main(void)
{
	/*Declare Local Variable*/
	uint8_t Local_u8RecieveData;

	/*Initialize SysTick Timer*/
	STK_u8Init(STK_u8_AHB_8);

	/*object choose HSI as clock source*/
	RCC_u8InitSysClk();

	/*object to enable RCC for UART*/
	RCC_u8EnableDisablPeripheralClk(RCC_u8_USART2, RCC_u8_Enable);

	/*object to enable RCC for GPIO*/
	RCC_u8EnableDisablPeripheralClk(RCC_u8_GPIOA, RCC_u8_Enable);
	RCC_u8EnableDisablPeripheralClk(RCC_u8_GPIOB, RCC_u8_Enable);
	RCC_u8EnableDisablPeripheralClk(RCC_u8_GPIOC, RCC_u8_Enable);

	/*initialize UART peripheral*/
	UART_u8Init(UART_u8_2, &BT_UARTConfig);

	/*select PIN A2 as TX */
	GPIO_u8SetPinMode(GPIO_u8_GPIOA,GPIO_u8_PIN2, GPIO_u8_OUTPUT_AF_PP_10MHZ);

	/*select PIN A3 as RX*/
	GPIO_u8SetPinMode(GPIO_u8_GPIOA,GPIO_u8_PIN3, GPIO_u8_INPUT_FLOATING);

	ROBOT_voidInit();
	/*Super Loop*/
	for(;;)
	{
		/*Receive data from Blue tooth*/
		UART_u8ReceiveByte(UART_u8_2,&Local_u8RecieveData);

		/*Choose from these cases*/
		switch (Local_u8RecieveData)
		{
		case 'F': ROBOT_voidForward();	break;
		case 'B': ROBOT_voidBackward(); break;
		case 'R': ROBOT_voidRight();	break;
		case 'L': ROBOT_voidLeft();		break;
		case 'S': ROBOT_voidStop();		break;
		default:						break;
		}

		/*Delay*/
		STK_u8SetmSBusyWait(Delay);
	}
}

