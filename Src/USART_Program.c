/*****************************************************************************************************/
/*                                                                                                   */
/*                                            Author:Mahmoud Mohamed Mahmoud                         */
/*												Date:21/9/2021										 */
/*												 SWC:USART									         */
/*											 Version:1.0											 */
/*																									 */
/*																									 */
/*****************************************************************************************************/
#include"STD_TYPES.h"
#include"bitMath.h"
#include"ARM_peripherals.h"
#include"USART_Private.h"
#include"USART_Configration.h"
#include"USART_Interface.h"
//#include"DMA_Interface.h"

static USART_RegDef_t*  USART_APStr[3]={USART1,USART2,USART3};
static void(*USART_APFun[3])(void)={NULL};
static u8 * USART_GArrPChar[3]={NULL};
static u8 USART_Index[3]={0};
static u8 StatusFlag=0;



void USART_Init (USART_Config * Copy_PStrUSART_Config)
{
	u32 baudrate=Copy_PStrUSART_Config->BaudRate;
	u16 mantissa=0;
	u8 fraction=0;
	/****************************** Calculating BaudRate value *****************************************/
	baudrate=baudrate*16;
	float BBR_value;
	BBR_value =  (USART_CLK_SYSTEM/(float)(baudrate));
	mantissa  =  BBR_value;
	BBR_value -= mantissa;
	fraction  =  (BBR_value*16) + 0.5;
	if(fraction>15)
	{
		mantissa++;
		fraction--;
	}
	
	/****************************** Setting BaudRate value ***********************************************/

	USART_APStr[Copy_PStrUSART_Config->UART_ID]->BRR  = 0;    														//clear BRR
	USART_APStr[Copy_PStrUSART_Config->UART_ID]->BRR |= (mantissa<<DIV_Mantissa)|(fraction<<DIV_Fraction);		 	//set BRR

	/****************************** Setting WordLength Mode **********************************************/

	CLRBit(USART_APStr[Copy_PStrUSART_Config->UART_ID]->CR1,M);														//clear word length bit
	USART_APStr[Copy_PStrUSART_Config->UART_ID]->CR1 |= ((Copy_PStrUSART_Config->Wordlength)<<M);					//set word length

	/****************************** Setting StopBit Mode *************************************************/

	CLRBit(USART_APStr[Copy_PStrUSART_Config->UART_ID]->CR2,STOP);													//clear stop 1st_bit
	CLRBit(USART_APStr[Copy_PStrUSART_Config->UART_ID]->CR2,(STOP+1));												//clear stop 2nd_bit
	USART_APStr[Copy_PStrUSART_Config->UART_ID]->CR2 |= ((Copy_PStrUSART_Config->Stopbit_Mode)<<STOP);				//set stop bit

	/****************************** Setting parityBit Mode ***********************************************/

	CLRBit(USART_APStr[Copy_PStrUSART_Config->UART_ID]->CR1,PS);													//clear parity bit
	USART_APStr[Copy_PStrUSART_Config->UART_ID]->CR1 |= ((Copy_PStrUSART_Config->Parity_Bit)<<PS);					//set sparity bit

	/***************************************** Enable UART **********************************************/
	SETBit(USART_APStr[Copy_PStrUSART_Config->UART_ID]->CR1,UE);
	SETBit(USART_APStr[Copy_PStrUSART_Config->UART_ID]->CR1,TE);													//Enable transmitter
	SETBit(USART_APStr[Copy_PStrUSART_Config->UART_ID]->CR1,RE);													//Enable reciever



}
/******************************************************************************************************/
void USART_Sync_SendChar      (USART_Config * Copy_PStrUSART_Config,u8 Copy_char)
{
	while(!(GETBit((USART_APStr[Copy_PStrUSART_Config->UART_ID]->SR),TXE)));
	USART_APStr[Copy_PStrUSART_Config->UART_ID]->DR=Copy_char;
}
/******************************************************************************************************/
u8 USART_Sync_RecieveChar     (USART_Config * Copy_PStrUSART_Config)
{
	while(!(GETBit((USART_APStr[Copy_PStrUSART_Config->UART_ID]->SR),RXNE)));
	return USART_APStr[Copy_PStrUSART_Config->UART_ID]->DR;
}
/******************************************************************************************************/
void USART_Sync_SendString      (USART_Config * Copy_PStrUSART_Config,u8 * Copy_String)
{
	u8 index=0;
	while((Copy_String[index])!='\0')
	{
		while(!(GETBit((USART_APStr[Copy_PStrUSART_Config->UART_ID]->SR),TXE)));
		USART_APStr[Copy_PStrUSART_Config->UART_ID]->DR=Copy_String[index];
		index++;
	}
}
/******************************************************************************************************/
void USART_Sync_RecieveString     (USART_Config * Copy_PStrUSART_Config,u8 * Copy_String)
{
	u8 index=0;
	do
	{
		while(!(GETBit((USART_APStr[Copy_PStrUSART_Config->UART_ID]->SR),RXNE)));
		Copy_String[index]=USART_APStr[Copy_PStrUSART_Config->UART_ID]->DR;
		index++;
		//USART_Sync_SendChar(Copy_PStrUSART_Config,Copy_String[index-1]);              //for debugging purpose

	}while(Copy_String[index-1]!='\r');
}
/******************************************************************************************************/
void USART_Async_SendChar			(USART_Config * Copy_PStrUSART_Config,u8 *Copy_char)
{
	USART_GArrPChar[Copy_PStrUSART_Config->UART_ID]=Copy_char;
	SETBit((USART_APStr[Copy_PStrUSART_Config->UART_ID]->CR1),TCIE);
	SETBit((USART_APStr[Copy_PStrUSART_Config->UART_ID]->CR1),TXEIE);
}
/******************************************************************************************************/
void USART_Async_RecieveChar    	(USART_Config * Copy_PStrUSART_Config,u8 * Copy_Pchar)
{
	SETBit((USART_APStr[Copy_PStrUSART_Config->UART_ID]->CR1),RXNEIE);
	USART_GArrPChar[Copy_PStrUSART_Config->UART_ID]=Copy_Pchar;
}
/******************************************************************************************************/
void USART_Async_RecieveString    	(USART_Config * Copy_PStrUSART_Config,u8 * Copy_String,void (*Copy_PFun)(void))
{
	StatusFlag=1;
	USART_APFun[Copy_PStrUSART_Config->UART_ID]=Copy_PFun;
	USART_GArrPChar[Copy_PStrUSART_Config->UART_ID]=Copy_String;
	SETBit((USART_APStr[Copy_PStrUSART_Config->UART_ID]->CR1),RXNEIE);
}
/******************************************************************************************************/
void USART_Async_SendString     	(USART_Config * Copy_PStrUSART_Config,u8 * Copy_String,void (*Copy_PFun)(void))
{
	StatusFlag=2;
	USART_APFun[Copy_PStrUSART_Config->UART_ID]=Copy_PFun;
	USART_GArrPChar[Copy_PStrUSART_Config->UART_ID]=Copy_String;
	SETBit((USART_APStr[Copy_PStrUSART_Config->UART_ID]->CR1),TXEIE);
}
/******************************************************************************************************/
void USART1_IRQHandler(void)
{
	//CLRBit(USART1->CR1,TCIE);
	//CLRBit(USART1->CR1,RXNEIE);
	//CLRBit(USART1->CR1,TXEIE);

	if(GETBit(USART1->SR,RXNE)&&StatusFlag!=2)
		{
		USART_GArrPChar[0][USART_Index[0]]=USART1->DR;
		if((USART_GArrPChar[0][USART_Index[0]])=='\r')
				{
					USART_APFun[0]();
					CLRBit(USART1->CR1,RXNEIE);
					USART_Index[0]=0;
					StatusFlag=0;
				}
		USART_Index[0]++;
		}
	if(GETBit(USART1->SR,TXE)&&StatusFlag==2)
	{
		USART1->DR=USART_GArrPChar[0][USART_Index[0]];
		if((USART_GArrPChar[0][USART_Index[0]])=='\0')
		{
			USART_APFun[0]();
			CLRBit(USART1->CR1,TXEIE);
			USART_Index[0]=0;
			StatusFlag=0;
		}
		USART_Index[0]++;

	}


}
/******************************************************************************************************/
void USART1_SendByDMA(USART_DMAConfig * Copy_USARTPStr)
{
	
/*
	UART_ID
	Channel_Priority;
	*MemAdd;
	NumOfData;
	MINC_mode;
	CIRC_mode;*/
	u8 Channel_Id;
	if(Copy_USARTPStr->UART_ID==USART1_ID)
	{
		Channel_Id=3;
	}
	else if(Copy_USARTPStr->UART_ID==USART2_ID)
	{
		Channel_Id=5;
	}
	else if(Copy_USARTPStr->UART_ID==USART3_ID)
	{
		Channel_Id=2;
	}
	else{}
	/*enable DMA receiver*/
	SETBit(USART_APStr[Copy_USARTPStr->UART_ID]->CR3,DMAT);
	/*disable the channel*/
	CLRBit(DMA->CHANNEL[Channel_Id].CCR,0);
	/*Clear DMA control register*/
	DMA->CHANNEL[Channel_Id].CCR=0;
	DMA->CHANNEL[Channel_Id].CCR=(Copy_USARTPStr->Channel_Priority<<12)|((Copy_USARTPStr->MINC_mode)<<7);
	DMA->CHANNEL[Channel_Id].CCR|=(Copy_USARTPStr->CIRC_mode<<5)|(1<<4);
	/*Set memory address*/
	DMA->CHANNEL[Channel_Id].CMAR=(u32)Copy_USARTPStr->MemAdd;
	/*Set pripheral address as USART Data register*/
	DMA->CHANNEL[Channel_Id].CPAR=(u32)(&USART_APStr[Copy_USARTPStr->UART_ID]->DR);
	/*set number of transfered data */
	DMA->CHANNEL[Channel_Id].CNDTR=Copy_USARTPStr->NumOfData;
	/*enable the channel*/
	SETBit(DMA->CHANNEL[Channel_Id].CCR,0);
}
/******************************************************************************************************/
void USART1_receiveByDMA(USART_DMAConfig * Copy_USARTPStr)
{
	
	/*
	UART_ID
	Channel_Priority;
	*MemAdd;
	NumOfData;
	MINC_mode;
	CIRC_mode;*/	u8 Channel_Id;
	if(Copy_USARTPStr->UART_ID==USART1_ID)
	{
		Channel_Id=4;
	}
	else if(Copy_USARTPStr->UART_ID==USART2_ID)
	{
		Channel_Id=5;
	}
	else if(Copy_USARTPStr->UART_ID==USART3_ID)
	{
		Channel_Id=2;
	}
	else{}
	/*enable DMA receiver*/
	SETBit(USART_APStr[Copy_USARTPStr->UART_ID]->CR3,DMAR);
	/*disable the channel*/
	CLRBit(DMA->CHANNEL[Channel_Id].CCR,0);
	/*Clear DMA control register*/
	DMA->CHANNEL[Channel_Id].CCR=0;
	DMA->CHANNEL[Channel_Id].CCR=(Copy_USARTPStr->Channel_Priority<<12)|((Copy_USARTPStr->MINC_mode)<<7);
	DMA->CHANNEL[Channel_Id].CCR|=(Copy_USARTPStr->CIRC_mode<<5);
	/*Set memory address*/
	DMA->CHANNEL[Channel_Id].CMAR=(u32)Copy_USARTPStr->MemAdd;
	/*Set pripheral address as USART Data register*/
	DMA->CHANNEL[Channel_Id].CPAR=(u32)(&USART_APStr[Copy_USARTPStr->UART_ID]->DR);
	/*set number of transfered data */
	DMA->CHANNEL[Channel_Id].CNDTR=Copy_USARTPStr->NumOfData;
	/*enable the channel*/
	SETBit(DMA->CHANNEL[Channel_Id].CCR,0);
}
