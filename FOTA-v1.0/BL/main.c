/*=======================================================================================*/
/*  File        : main.c                                                 		   		 */
/*  Description : This Program file  For BootLoader Application    						 */
/*  Author      : Ahmed Mohamed Mohamed Hassanien . Embedded SW Engineer         		 */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-mohamed-a23651294/           		 */
/*  Git account : https://github.com/AhmedTorres2000				              		 */
/*  mail        : Ahmedtorres2000@gmil.com                                        		 */
/*=======================================================================================*/

#include "MCAL/UART/UART_interface.h"
#include "MCAL/FPEC/FPEC_interface.h"

#include "HAL/LCD/LCD_interface.h"
#include "HAL/LED/LED_Interface.h"
#include "HAL/SWITCH/SWITCH_Interface.h"
#include "HAL/WIFI/WIFI_intrface.h"

#include "HAL/SYSTEM/SYSTYM_Interface.h"

volatile u8 g_update_Found = 0;

void Jump_Into_APP(void)
{
	typedef void(*function_t)(void);

	function_t add_to_call = 0;

	/*Address of SCB_VTOR Register*/
	#define SCB_VTOR  *((volatile u32*)0xE000ED08)
	/*
	 * Page 10 = 0x08000000 + (20 * 1024)
	 */
	SCB_VTOR = 0x08005000;

	/* Reset handler definition function of our main application */
	add_to_call = *(function_t*)(0x08005004);

	/* Jump to Application Reset Handler */
	add_to_call();
}


int main(void)
{
	/* Initialize System*/
	SYSTEM_Init();

	LED_init(LC13);
	SWITCH_init(SC14,SW_PULLDOWN);
	LCD_init();

	STK_u8SetmSBusyWait(1500);

	if(SWITCH_RAISING(SC14))
	{
		STK_u8SetmSBusyWait(50);
		if(SWITCH_RAISING(SC14))
		{
			LCD_displayStringRowColumn(0, 0, "Booting");
			for(u8 i=0;i<6;i++)
			{
				LCD_displayCharacter('.');
				STK_u8SetmSBusyWait(100);
			}
			WIFI_voidInit();

			WIFI_Check_update();

			if(g_update_Found)
			{
				FPEC_voidEraseAppArea();
				WIFI_VoidReceiveRecords_ACK();
			}
		}
	}
	Jump_Into_APP();

	for(;;)
	{


	}
}
