/*****************************************************************************************************/
/*                                                                                                   */
/*                                            Author:Mahmoud Mohamed Mahmoud                         */
/*												Date:23/9/2021										 */
/*												 SWC:NVIC									         */
/*											 Version:1.0											 */
/*																									 */
/*																									 */
/*****************************************************************************************************/
#ifndef _NVIC_INTERFACE_H_
#define _NVIC_INTERFACE_H_

typedef enum
{
NVIC_WWDG_ID,
NVIC_PVD_ID,
NVIC_TAMPER_ID,
NVIC_RTC_ID,
NVIC_FLASH_ID,
NVIC_RCC_ID,
NVIC_EXTI0_ID,
NVIC_EXTI1_ID,
NVIC_EXTI2_ID,
NVIC_EXTI3_ID,
NVIC_EXTI4_ID,
NVIC_DMA1_Channel1_ID,
NVIC_DMA1_Channel2_ID,
NVIC_DMA1_Channel3_ID,
NVIC_DMA1_Channel4_ID,
NVIC_DMA1_Channel5_ID,
NVIC_DMA1_Channel6_ID,
NVIC_DMA1_Channel7_ID,
NVIC_ADC1_2_ID,
NVIC_USB_HP_CAN_TX_ID,
NVIC_USB_LP_CAN_IXRX0_ID,
NVIC_CAN_RX1_ID,
NVIC_CAN_SCE_ID,
NVIC_EXTI9_5_ID,
NVIC_TIM1_BRK_ID,
NVIC_TIM1_UP_ID,
NVIC_TIM1_TRG_COM_ID,
NVIC_TIM1_CC_ID,
NVIC_TIM2_ID,
NVIC_TIM3_ID,
NVIC_TIM4_ID,
NVIC_I2C1_EV_ID,
NVIC_I2C1_ER_ID,
NVIC_I2C2_EV_ID,
NVIC_I2C2_ER_ID,
NVIC_SPI1_ID,
NVIC_SPI2_ID,
NVIC_USART1_ID,
NVIC_USART2_ID,
NVIC_USART3_ID,
NVIC_EXTI15_10_ID,
NVIC_RTCAlarm_ID,
NVIC_USBWakeup_ID,
NVIC_TIM8_BRK_ID,
NVIC_TIM8_UP_ID,
NVIC_TIM8_TRG_COM_ID,
NVIC_TIM8_CC_ID,
NVIC_ADC3_ID,
NVIC_FSMC_ID,
NVIC_SDIO_ID,
NVIC_TIM5_ID,
NVIC_SPI3_ID,
NVIC_UART4_ID,
NVIC_UART5_ID,
NVIC_TIM6_ID,
NVIC_TIM7_ID,
NVIC_DMA2_Channel1_ID,
NVIC_DMA2_Channel2_ID,
NVIC_DMA2_Channel3_ID,
NVIC_DMA2_Channel4_5
}Int_IdDef_t;




#define NVIC_u8_GRP_PRI_0              0
#define NVIC_u8_GRP_PRI_1              1
#define NVIC_u8_GRP_PRI_2              2
#define NVIC_u8_GRP_PRI_3              3

#define NVIC_u8_SUB_PRI_0              0
#define NVIC_u8_SUB_PRI_1              1
#define NVIC_u8_SUB_PRI_2              2
#define NVIC_u8_SUB_PRI_3              3

u8 NVIC_u8EnableInterrupt      (u8 Copy_u8IRQNum);

u8 NVIC_u8DisableInterrupt     (u8 Copy_u8IRQNum);

u8 NVIC_u8SetPendingFlag       (u8 Copy_u8IRQNum);

u8 NVIC_u8ClearPendingFlag     (u8 Copy_u8IRQNum);

u8 NVIC_u8GetActiveFlag        (u8 Copy_u8IRQNum,u8 * Copy_pu8ActiveFlagState);

u8 NVIC_SetPriority            (u8 Copy_u8IRQNum,u8 Copy_u8GrpPriority,u8 Copy_u8SubPriority);


#endif

