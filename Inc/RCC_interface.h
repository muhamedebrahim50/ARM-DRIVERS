/*****************************************************************************************************/
/*                                                                                                   */
/*                                            Auther:Mahmoud Mohamed Mahmoud                         */
/*												Date:19/9/2021										 */
/*												 SWC:RCC											 */
/*											 Version:1.0											 */
/*																									 */
/*																									 */
/*****************************************************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/***************************************************************************/
/*RCC_AHBENR Register*/
typedef enum{
	DMA1EN,
	DMA2EN,
	SRAMEN,
	FLIFTEN = 4,
	CRCEN = 6,
	FSMCEN = 8,
	SDIOEN = 10
}AHBEN_peripherals;

/***************************************************************************/
/*RCC_APB2ENR Register*/
#define APB2ENR_offset	32
typedef enum{
	AFIOEN = 32,
	IOPAEN = 34,
	IOPBEN,
	IOPCEN,
	IOPDEN,
	IOPEEN,
	IOPFEN,
	IOPGEN,
	ADC1EN,
	ADC2EN,
	TIM1REN,
	SPI1EN,
	TIM8EN,
	USART1EN,
	ADC3EN,
	TIM9EN = 51,
	TIM10EN,
	TIM11EN
}APB2ENR_peripherals;

/***************************************************************************/
/*RCC_APB1ENR Register*/
#define APB1ENR_offset	64
typedef enum{
	TIM2EN = 64,
	TIM3EN,
	TIM4EN,
	TIM5EN,
	TIM6EN,
	TIM7EN,
	TIM12EN,
	TIM13EN,
	TIM14EN,
	WWDGEN = 75,
	SPI2EN = 78,
	SPI3EN,
	USART2EN = 81,
	USART3EN,
	UART4EN,
	UART5EN,
	I2C1EN,
	I2C2EN,
	USBEN,
	CANEN = 89,
	BKPEN = 91,
	PWREN,
	DACEN
}APB1ENR_peripherals;
void RCC_SelectSysClk(void);
void RCC_Enable_peripheralClk(u8 RCC_u8peripheralId);
void RCC_Disable_peripheralClk(u8 RCC_u8peripheralId);
#endif

