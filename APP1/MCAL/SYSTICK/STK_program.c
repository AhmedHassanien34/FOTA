/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 SYSTICK								*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

/*******************************************************************************
*                        		Inclusions                                     *
*******************************************************************************/


#include "LIB/Error_type.h"
#include "LIB/BIT_MATH.h"
#include "LIB/stm32f103xx.h"

#include "MCAL/SYSTICK/STK_interface.h"
#include "MCAL/SYSTICK/STK_private.h"
#include "MCAL/SYSTICK/STK_config.h"



/*******************************************************************************
*                      Functions Definitions                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		STK_voidInit
********************************************************************************/
uint8_t STK_u8Init(uint8_t Copy_u8ClockSource)
{
	uint8_t Local_u8ErrorState = OK;

	/* Choose the Clock Source */
	if(Copy_u8ClockSource == STK_u8_AHB)
	{
		SET_BIT(STK->CTRL,2);
	}
	else if (Copy_u8ClockSource == STK_u8_AHB_8)
	{
		CLR_BIT(STK->CTRL,2);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	/* Disable the timer */
	CLR_BIT(STK->CTRL,0);

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8SetBusyWait
********************************************************************************/
uint8_t STK_u8SetuSBusyWait(uint32_t Copy_u32Time_us)
{
	uint8_t Local_u8ErrorState = OK;
	uint32_t Local_u32LoadValue;

	if(GET_BIT(STK->CTRL,2)) /* The clock source is AHB/1 */
	{
		Local_u32LoadValue = (F_CPU/1000000)*Copy_u32Time_us ;
	}
	else /* The clock source is AHB/8 */
	{
		Local_u32LoadValue = (F_CPU/8000000)*Copy_u32Time_us ;
	}

	if(Local_u32LoadValue <= 0x00FFFFFFFF)
	{
		/* Close the exception request */
		CLR_BIT(STK->CTRL,1);
		/* Load the required delay */
		STK->LOAD = Local_u32LoadValue ;
		/* Enable the timer */
		SET_BIT(STK->CTRL,0);
		/* Start the change immediately by writing any value to VAL register */
		STK->VAL = 0;
		/* Wait until timer reach zero */
		while(GET_BIT(STK->CTRL,16) == 0);
		/* Disable Timer */
		CLR_BIT(STK->CTRL,0);
		STK->LOAD = 0;
		STK->VAL  = 0;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8SetmSBusyWait
********************************************************************************/
uint8_t STK_u8SetmSBusyWait(uint32_t Copy_u32Time_ms)
{
	uint8_t Local_u8ErrorState = OK;

	for(uint32_t i = 0 ; i < Copy_u32Time_ms ; i++)
	{
		STK_u8SetuSBusyWait(1000);
	}

	return Local_u8ErrorState;
}



