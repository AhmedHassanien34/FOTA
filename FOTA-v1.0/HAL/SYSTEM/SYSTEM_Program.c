/*=================================================================================*/
/*  File        : SYSTEM Program.c                                                 */
/*  Description : This Program file includes SYSTEM program                        */
/*  Author      : Ahmed Mohamed Mohamed Hassanien . Embedded SW Engineer           */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-mohamed-a23651294/             */
/*  Git account : https://github.com/AhmedTorres2000				               */
/*  mail        : Ahmedtorres2000@gmil.com                                         */
/*=================================================================================*/


#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/STK/STK_interface.h"
#include "SYSTYM_Interface.h"

void SYSTEM_Init(void)
{
	STK_u8Init(STK_u8_AHB_8);
	RCC_u8InitSysClk();
}
