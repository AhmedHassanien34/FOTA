/*=================================================================================*/
/*  File        : LED_Interface.h                                                  */
/*  Description : This Header file includes LED_Interface                          */
/*  Author      : Ahmed Mohamed Mohamed Hassanien . Embedded SW Engineer       	   */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-mohamed-a23651294/             */
/*  Git account : https://github.com/AhmedTorres2000				               */
/*  mail        : Ahmedtorres2000@gmil.com                                         */
/*=================================================================================*/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

typedef enum
{
	LA0,LA1,LA2,LA3,LA4,LA5,LA6,LA7,LA8,LA9,LA10,LA11,LA12,LA13,LA14,LA15,
	LB0,LB1,LB2,LB3,LB4,LB5,LB6,LB7,LB8,LB9,LB10,LB11,LB12,LB13,LB14,LB15,
	LC13=45,LC14,LC15
}LED_NUM;
/*******************************************************************************
* Function Name:		LED_init
********************************************************************************/
u8 LED_init(LED_NUM led);
/*******************************************************************************
* Function Name:		LED_ON
********************************************************************************/
u8 LED_ON(LED_NUM led);
/*******************************************************************************
* Function Name:		LED_OFF
********************************************************************************/
u8 LED_OFF(LED_NUM led);
/*******************************************************************************
* Function Name:		LED_TOG
********************************************************************************/
u8 LED_TOG(LED_NUM led);


#endif /* LED_INTERFACE_H_ */
