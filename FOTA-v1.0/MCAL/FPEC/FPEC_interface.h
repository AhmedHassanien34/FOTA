/*=================================================================================*/
/*  File        : FPEC interface.h                                                 */
/*  Description : This Header file includes FPEC interface                         */
/*  Author      : Ahmed Mohamed Mohamed Hassanien . Embedded SW Engineer       	   */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-mohamed-a23651294/             */
/*  Git account : https://github.com/AhmedTorres2000				               */
/*  mail        : Ahmedtorres2000@gmil.com                                         */
/*=================================================================================*/

#ifndef FPEC_INTERFACE
#define FPEC_INTERFACE


void FPEC_voidEraseAppArea(void);

void FPEC_voidFlashPageErase(u8 Copy_u8PageNumber);

void FPEC_voidFlashWrite(u32 Copy_u32Address, u16* Copy_u16Data, u8 Copy_u8Length);


#endif
