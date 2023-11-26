/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Layer:   LIB								   	*************/
/**************************		SWC:	 Registers								*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/


#ifndef STM32F103xx_H
#define STM32F103xx_H

#include <stdint.h>
/*******************************************************************************
*                      				RCC                     		           *
*******************************************************************************/

#define RCC_u32_BASE_ADDRESS						0x40021000

typedef struct
{	
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_RegDef_t;

#define RCC						((RCC_RegDef_t *)RCC_u32_BASE_ADDRESS)

/*******************************************************************************
*                      				GPIO                     		           *
*******************************************************************************/

#define GPIOA_u32_BASE_ADDRESS						0x40010800U
#define GPIOB_u32_BASE_ADDRESS						0x40010C00U
#define GPIOC_u32_BASE_ADDRESS						0x40011000U
#define GPIOD_u32_BASE_ADDRESS						0x40011400U
#define GPIOE_u32_BASE_ADDRESS						0x40011800U

typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_RegDef_t;

#define GPIOA					((GPIO_RegDef_t *)GPIOA_u32_BASE_ADDRESS)
#define GPIOB					((GPIO_RegDef_t *)GPIOB_u32_BASE_ADDRESS)
#define GPIOC					((GPIO_RegDef_t *)GPIOC_u32_BASE_ADDRESS)
#define GPIOD					((GPIO_RegDef_t *)GPIOD_u32_BASE_ADDRESS)
#define GPIOE					((GPIO_RegDef_t *)GPIOE_u32_BASE_ADDRESS)

/*******************************************************************************
*                      				SYSTICK                    		           *
*******************************************************************************/

#define STK_u32_BASE_ADDRESS						0xE000E010U

typedef struct
{
	volatile uint32_t CTRL;
	volatile uint32_t LOAD;
	volatile uint32_t VAL;
	volatile uint32_t CALIB;
}STK_RegDef_t;

#define STK						((STK_RegDef_t *)STK_u32_BASE_ADDRESS)

/*******************************************************************************
*                      				NVIC                    		           *
*******************************************************************************/

#define NVIC_BASE_ADDRESS 	    0xE000E100UL

typedef struct
{
	volatile uint32_t ISER[3];		/* Interrupt set-enable register */
	uint32_t Reserved2[30];			/* Offset */
	volatile uint32_t ICER[3]; 		/* Interrupt clear-enable register */
	uint32_t Reserved3[30];			/* Offset */
	volatile uint32_t ISPR[3];		/* Interrupt set-pending register */
	uint32_t Reserved4[30];			/* Offset */
	volatile uint32_t ICPR[3];		/* Interrupt clear-pending register */
	uint32_t Reserved5[30];			/* Offset */
	volatile uint32_t IABR[3];		/* Interrupt active bit register */
	uint32_t Reserved6[62];			/* Offset */
	volatile uint8_t IPR[33];		/* Interrupt Priority Registers */

} NVIC_RegDef_t;

#define NVIC  		   ((NVIC_RegDef_t*)NVIC_BASE_ADDRESS)

/*******************************************************************************
*                      				SCB		                   		           *
*******************************************************************************/

#define SCB_BASE_ADDRESS 	    0xE000ED00UL

typedef struct {
	uint32_t CPUID;
	uint32_t ICSR;
	uint32_t VTOR;
	uint32_t AIRCR;
	uint32_t SCR;
	uint32_t CCR;
	uint32_t SHPR[4];
	uint32_t CFSR;
	uint32_t HFSR;
	uint32_t rev;
	uint32_t MMAR;
	uint32_t BFAR;
}SCB_regDef_t;

#define SCB  		   ((SCB_regDef_t*)SCB_BASE_ADDRESS)
/*******************************************************************************
*                      			UART	                    		          *
*******************************************************************************/

#define UART1_u32_BASE_ADDRESS						0x40013800U
#define UART2_u32_BASE_ADDRESS						0x40004400U
#define UART3_u32_BASE_ADDRESS						0x40004800U

typedef struct
{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;
}UART_RegDef_t;

#define UART1						((UART_RegDef_t*)UART1_u32_BASE_ADDRESS)
#define UART2						((UART_RegDef_t*)UART2_u32_BASE_ADDRESS)
#define UART3						((UART_RegDef_t*)UART3_u32_BASE_ADDRESS)

/*******************************************************************************
*                      			FPEC	                    		          *
*******************************************************************************/

#define FPEC_BASE_ADDRESS						0x40022000U

typedef struct
{
	volatile uint32_t ACR;
	volatile uint32_t KEYR;
	volatile uint32_t OPTKEYR;
	volatile uint32_t SR;
	volatile uint32_t CR;
	volatile uint32_t AR;
	volatile uint32_t RESERVED;
	volatile uint32_t OBR;
	volatile uint32_t WRPR;
}FPEC_RegDef_t;

#define FPEC ((FPEC_RegDef_t*)FPEC_BASE_ADDRESS)



#endif
