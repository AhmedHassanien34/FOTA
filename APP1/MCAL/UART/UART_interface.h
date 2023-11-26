/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 UART									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/*******************************************************************************
*                         Types Declaration                                   *
*******************************************************************************/

/*******************************************************************************
* Name: UART_configStruct_t
* Type: Structure
* Description: Data type to initialize the DMA channel
********************************************************************************/

typedef struct
{
	uint32_t UART_u32_BAUD_RATE;
	uint8_t UART_u8_END_STRING;
	uint8_t UART_u8_STOP_BIT;
	uint8_t UART_u8_DATA_SIZE;
	uint8_t UART_u8_PARTIY;
	uint8_t UART_u8_RECEIVE_METHOD;
}UART_configStruct_t;

/*******************************************************************************
*                        		Definitions                                    *
*******************************************************************************/

/*******************************************************************************
*                       	   	UART		                	        	   *
*******************************************************************************/
#define UART_u8_1								0
#define UART_u8_2								1
#define UART_u8_3								2

/*******************************************************************************
*                       	   	STOP BITS		   		                       *
*******************************************************************************/
#define UART_u8_STOP_1_BIT						0b00
#define UART_u8_STOP_0_5_BIT					0b01
#define UART_u8_STOP_2_BITS						0b10
#define UART_u8_STOP_1_5_BITS					0b11

/*******************************************************************************
*                       	   	DATA SIZE		                	           *
*******************************************************************************/
#define UART_u8_8_BITS							0
#define UART_u8_9_BITS							1

/*******************************************************************************
*                       	   	PARTIY		   		             	           *
*******************************************************************************/
#define UART_u8_PARITY_DISABLED					0b00
#define UART_u8_PARITY_EVEN						0b10
#define UART_u8_PARITY_ODD						0b11

/*******************************************************************************
*                       	   	RECEIVE METHOD		                	       *
*******************************************************************************/
#define UART_u8_POLLING							0b000 /* DMA disabled, send and receive with poling */
#define UART_u8_INTERRUP						0b001 /* DMA disabled, send with polling and receive with interrupt */
#define UART_u8_DMA_TX_POL_RX					0b100 /* Send with DMA receive with polling */
#define UART_u8_DMA_TX_INT_RX					0b101 /* Send with DMA receive with interrupt */
#define UART_u8_DMA_RX							0b010 /* Receive with DMA send with polling */
#define UART_u8_DMA_TX_RX						0b110 /* Send with DMA receive with DMA */

/*******************************************************************************
*                       Functions Prototypes                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		UART_u8Init
* Description:			Function to initialize the UART
* Parameters (in):    	Pointer to structure of type UART_RegDef_t
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
uint8_t UART_u8Init(uint8_t Copy_u8UartNumber, UART_configStruct_t * Copy_PstrUARTConfig);

/*******************************************************************************
* Function Name:		UART_uint8_tSendByte
* Description:			Function to send one byte using the UART
* Parameters (in):    	Data Byte
* Parameters (out):   	uint8_t
* Return value:      	OK or Error
********************************************************************************/
uint8_t UART_u8SendByte(uint8_t Copy_u8UartNumber, uint8_t Copy_u8DataByte);

/*******************************************************************************
* Function Name:		UART_u8SendString
* Description:			Function to send string using the UART
* Parameters (in):    	Data Byte
* Parameters (out):   	uint8_t
* Return value:      	OK or Error
********************************************************************************/
uint8_t UART_u8SendString(uint8_t Copy_u8UartNumber, uint8_t* Copy_Pu8DataString);

/*******************************************************************************
* Function Name:		UART_u8SendStream
* Description:			Function to send stream of data using UART
* Parameters (in):    	Pointer to variable to receive the stream on it and the data size
* Parameters (out):   	uint8_t
* Return value:      	OK or Error
********************************************************************************/
uint8_t UART_u8SendStream(uint8_t Copy_u8UartNumber, uint8_t* Copy_pu8DataByte, uint16_t Copy_u16DataSize);

/*******************************************************************************
* Function Name:		UART_u8ReceiveByte
* Description:			Function to receive one byte using UART
* Parameters (in):    	Pointer to variable to save the data on it
* Parameters (out):   	uint8_t
* Return value:      	OK or Error
********************************************************************************/
uint8_t UART_u8ReceiveByte(uint8_t Copy_u8UartNumber, uint8_t* Copy_pu8DataByte);

/*******************************************************************************
* Function Name:		UART_u8ReceiveString
* Description:			Function to receive string using UART
* Parameters (in):    	Pointer to variable to receive the string on it
* Parameters (out):   	uint8_t
* Return value:      	OK or Error
********************************************************************************/
uint8_t UART_u8ReceiveString(uint8_t Copy_u8UartNumber, uint8_t* Copy_pu8DataByte);

/*******************************************************************************
* Function Name:		UART_u8ReceiveStream
* Description:			Function to receive string using UART
* Parameters (in):    	Pointer to variable to receive the stream on it and the data size
* Parameters (out):   	uint8_t
* Return value:      	OK or Error
********************************************************************************/
uint8_t UART_u8ReceiveStream(uint8_t Copy_u8UartNumber, uint8_t* Copy_pu8DataByte, uint16_t Copy_u8DataSize);

/*******************************************************************************
* Function Name:		UART_u8SetCallBack
* Description:			Function to set the ISR
* Parameters (in):    	Pointer to function to act as the ISR
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
uint8_t UART_u8SetCallBack(uint8_t Copy_u8UartNumber, void(*Copy_pfCallback)(void));



#endif /* UART_INTERFACE_H_ */
