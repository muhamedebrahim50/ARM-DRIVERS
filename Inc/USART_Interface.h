/*****************************************************************************************************/
/*                                                                                                   */
/*                                            Author:Mahmoud Mohamed Mahmoud                         */
/*												Date:21/9/2021										 */
/*												 SWC:USART									         */
/*											 Version:1.0											 */
/*																									 */
/*																									 */
/*****************************************************************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

typedef enum
{
	USART1_ID,USART2_ID,USART3_ID
}USART_Ids_t;

typedef enum
{
	_8_bit,
	_9_Bit
}WordLength_t;

typedef enum
{
	_1_bit,
	_half_Bit,
	_2_Bit,
	_1and_half_Bit

}StopBit_Mode_t;

typedef enum
{
	even_parity,
	odd_parity
	
}Parity_Bit_t;


typedef struct
{
	u32                    BaudRate;
	USART_Ids_t            UART_ID;
	WordLength_t           Wordlength;
	StopBit_Mode_t         Stopbit_Mode;
	Parity_Bit_t           Parity_Bit;

}USART_Config;
typedef struct
{
	USART_Ids_t				UART_ID;
	u8						Channel_Priority;
	u8						*MemAdd;
	u16						NumOfData;
	u8						MINC_mode;
	u8						CIRC_mode;
}USART_DMAConfig;


void USART_Init               (USART_Config * Copy_PStrUSART_Config);

			/**************************************************/
			/******************   Synchronous  ****************/
			/**************************************************/


void USART_Sync_SendChar          	(USART_Config * Copy_PStrUSART_Config,u8 Copy_char);
u8   USART_Sync_RecieveChar       	(USART_Config * Copy_PStrUSART_Config);
void USART_Sync_RecieveString     	(USART_Config * Copy_PStrUSART_Config,u8 * Copy_String);
void USART_Sync_SendString        	(USART_Config * Copy_PStrUSART_Config,u8 * Copy_String);

			/**************************************************/
			/******************  ASynchronous  ****************/
			/**************************************************/


void USART_Async_SendChar			(USART_Config * Copy_PStrUSART_Config,u8 *Copy_char);
void USART_Async_RecieveChar    	(USART_Config * Copy_PStrUSART_Config,u8 * Copy_Pchar);
void USART_Async_RecieveString    	(USART_Config * Copy_PStrUSART_Config,u8 * Copy_String,void (*Copy_PFun)(void));
void USART_Async_SendString     	(USART_Config * Copy_PStrUSART_Config,u8 * Copy_String,void (*Copy_PFun)(void));

		    /**************************************************/
		    /******************  Using DMA  ****************/
		    /**************************************************/

void USART1_SendByDMA 				(USART_DMAConfig * Copy_USARTPStr);
void USART1_receiveByDMA			(USART_DMAConfig * Copy_USARTPStr);

#endif
