/*=================================================================================*/
/*  File        : LCD_Private.h                                                    */
/*  Description : This Header file includes LCD Private                            */
/*  Author      : Ahmed Mohamed Mohamed Hassanien . Embedded SW Engineer       	   */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-mohamed-a23651294/             */
/*  Git account : https://github.com/AhmedTorres2000				               */
/*  mail        : Ahmedtorres2000@gmil.com                                         */
/*=================================================================================*/

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_


/*******************************************************************************
*                      			LCD COMMANDS 	                              *
*******************************************************************************/
#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80


#endif /* LCD_PRIVATE_H_ */
