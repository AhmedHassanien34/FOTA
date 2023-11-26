/********************************************************************************************/
/********************************************************************************************/
/**************************		Layer:   LIB								   	*************/
/**************************		SWC:	 BIT_MATH								*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOG_BIT(REG,BIT) (REG^=(1<<BIT))

/* Read a certain bit in any register */
#define GET_BIT(REG,BIT) ((REG>>BIT) & 1)

#endif


