/*=================================================================================*/
/*  File        : LCD Interface.h                                                  */
/*  Description : This Header file includes LCD Interface                          */
/*  Author      : Ahmed Mohamed Mohamed Hassanien . Embedded SW Engineer       	   */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-mohamed-a23651294/             */
/*  Git account : https://github.com/AhmedTorres2000				               */
/*  mail        : Ahmedtorres2000@gmil.com                                         */
/*=================================================================================*/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/

void LCD_sendCommand(u8 command);

void LCD_init(void);

void LCD_displayCharacter(u8 data);

void LCD_displayString(char * string);

void LCD_clearScreen();

void LCD_moveCursor(u8 row,u8 column);

void LCD_displayStringRowColumn(u8 row , u8 column , char * string);

void LCD_intgerToString(long number);

#endif /* LCD_INTERFACE_H_ */
