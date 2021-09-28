#include"STD_TYPES.h"
#include"bitMath.h"
#include"ARM_peripherals.h"
#include"RCC_interface.h"
#include"GPIO_interface.h"
#include"systic_Interface.h"
#include"USART_Interface.h"
#include"NVIC_Interface.h"
#include"DMA_Interface.h"

void toggle(void);
GPIO_PinMode_t integrated_LED={PORTC,PIN13,GPIO_u8_OUTPUT_GP_PP_2MHZ};
GPIO_PinMode_t UART_TX={PORTA,PIN9,GPIO_u8_OUTPUT_AF_PP_2MHZ};			//TX
GPIO_PinMode_t UART_RX={PORTA,PIN10,GPIO_u8_INPUT_PULL_UP};				//RX
USART_Config com1={9600,USART1_ID,_8_bit,_1_bit,even_parity};

u8 y[6000]="Mahmoud Mohamed & Ehab Abdo & Mohamed Ebrahim & Mohamed Ramadan";
u8 x[6000]="0";
USART_DMAConfig comSend={USART1_ID,DMA_PriortyLow,y,50,Enable,Disable};
USART_DMAConfig comRcv={USART1_ID,DMA_PriortyLow,x,5,Enable,Disable};

int main(void)
{
	RCC_SelectSysClk();
	RCC_Enable_peripheralClk(USART1EN);
	RCC_Enable_peripheralClk(IOPAEN);
	RCC_Enable_peripheralClk(IOPCEN);
	RCC_Enable_peripheralClk(DMA1EN);
	STK_Init();
	NVIC_SetPriority(37,1,1);
	NVIC_u8EnableInterrupt(37);
	GPIO_PinMode_Init(&UART_TX);
	GPIO_PinMode_Init(&UART_RX);
	GPIO_PinMode_Init(&integrated_LED);
	USART_Init(&com1);
	DMA_ChannelConfig_t ziad={CH1,DMA_PriortyLow,_8_bits,_8_bits,Read_from_peripheral,x,y,100,Enable,Enable,Enable,Disable,Disable,Disable,Disable};
	DMA_Init(&ziad);
	//DMA_Start(&ziad);

	//USART_Async_RecieveString(&com1,x,toggle);
	//USART_Async_SendString(&com1,y,toggle);
	USART1_SendByDMA(&comSend);
	USART1_receiveByDMA(&comRcv);
	while(1)
	{
		GPIO_TogglePin(&integrated_LED);
		STK_Delay_ms(1000);
	}
	return 0;
}
void toggle(void)
{
	GPIO_TogglePin(&integrated_LED);
	STK_Delay_ms(1000);
}



