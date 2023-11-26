/*=================================================================================*/
/*  File        : STD_TYPES.h                           	                       */
/*  Description : This Header file includes Standard types for STM32f103C8T6       */
/*  Author      : Ahmed Mohamed Mohamed Hassanien . Embedded SW Engineer           */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-mohamed-a23651294/             */
/*  Git account : https://github.com/AhmedTorres2000				               */
/*  mail        : Ahmedtorres2000@gmil.com                                         */
/*=================================================================================*/

#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char       u8;
typedef signed char         s8;
typedef unsigned short int u16;
typedef signed short int   s16;
typedef unsigned long int  u32;
typedef signed long int    s32;
typedef float              f32;
typedef double             f64;
typedef long double        f128;
typedef void(*fptr_t)(void);

#define STD_TYPES_OK            1
#define STD_TYPES_NOK           0

#define F_CPU				8000000 /* 8Mhz */

#endif
