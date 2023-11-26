/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    28 June 2023	            			*************/
/**************************		Layer:   HAL								   	*************/
/**************************		SWC:	 ROBOT									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

/******************************************************/
/* guard of file will call one time in .c  			  */
/******************************************************/

#ifndef ROBOT_INTERFACE_H
#define ROBOT_INTERFACE_H

void ROBOT_voidInit(void);

void ROBOT_voidForward	(void);
void ROBOT_voidBackward	(void);
void ROBOT_voidRight	(void);
void ROBOT_voidLeft		(void);

void ROBOT_voidStop		(void);

#endif