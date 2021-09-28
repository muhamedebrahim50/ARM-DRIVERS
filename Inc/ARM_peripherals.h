/*****************************************************************************************************/
/*                                                                                                   */
/*                                            Author:Mahmoud Mohamed Mahmoud                         */
/*												Date:19/9/2021										 */
/*												 SWC:Peripherals									 */
/*											 Version:1.0											 */
/*																									 */
/*																									 */
/*****************************************************************************************************/

#ifndef ARM_PERIPHERALS_H_
#define ARM_PERIPHERALS_H_

#define RCC_BASE_ADDRESS   0x40021000

typedef struct 
{                
	volatile u32 RCC_CR;
	volatile u32 RCC_CFGR;
	volatile u32 RCC_CIR;
    volatile u32 RCC_APB2RSTR;
    volatile u32 RCC_APB1RSTR;
    volatile u32 RCC_AHBENR;
    volatile u32 RCC_APB2ENR;
    volatile u32 RCC_APB1ENR;
    volatile u32 RCC_BDCR;
	volatile u32 RCC_CSR;
}RCC_RegDef_t;

#define RCC       ((RCC_RegDef_t*)RCC_BASE_ADDRESS)
       /*******************************************************/
#define GPIOA_BASE_ADDRESS 	0x40010800
#define GPIOB_BASE_ADDRESS 	0x40010C00
#define GPIOC_BASE_ADDRESS 	0x40011000

typedef struct 
{ 
	volatile 	u32 CRL;
	volatile 	u32 CRH;
	volatile 	u32 IDR;
	volatile 	u32 ODR;
	volatile 	u32 BSRR;
	volatile 	u32 BRR;
	volatile 	u32 LCKR;
}GPIO_RegDef_t;

#define GPIOA       ((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define GPIOB       ((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define GPIOC       ((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
       /*******************************************************/

#define STK_BASE_ADDRESS   0xE000E010
typedef struct
{
	volatile 	u32 CTRL;
	volatile 	u32 LOAD;
	volatile 	u32 VAL;
	volatile 	u32 CALIB;
}STK_RegDef_t;

#define STK       ((STK_RegDef_t*)STK_BASE_ADDRESS)


       /*******************************************************/
#define USART1_BASE_ADDRESS   0x40013800
#define USART2_BASE_ADDRESS   0x40004400
#define USART3_BASE_ADDRESS   0x40004800

typedef struct
{
	volatile u32 SR   ;
	volatile u32 DR   ;
	volatile u32 BRR  ;
	volatile u32 CR1  ;
	volatile u32 CR2  ;
	volatile u32 CR3  ;
	volatile u32 GTPR ;
}USART_RegDef_t;


#define USART1       ((USART_RegDef_t*)USART1_BASE_ADDRESS)
#define USART2       ((USART_RegDef_t*)USART2_BASE_ADDRESS)
#define USART3       ((USART_RegDef_t*)USART3_BASE_ADDRESS)

       /*******************************************************/
#define NVIC_BASE_ADDRESS   0xE000E100

typedef struct
{
	volatile u32 ISER[8];
	volatile u32 RESERVED1[24];
	volatile u32 ICER[8];
	volatile u32 RESERVED2[24];
	volatile u32 ISPR[8];
	volatile u32 RESERVED3[24];
	volatile u32 ICPR[8];
	volatile u32 RESERVED4[24];
	volatile u32 IABR[8];
	volatile u32 RESERVED5[56];
	volatile u8  IPR[240];
	volatile u32 RESERVED6[643];
	volatile u32  STIR;

}NVIC_RegDef_t;

#define NVIC       ((NVIC_RegDef_t*)NVIC_BASE_ADDRESS)
       /*******************************************************/
#define DMA_BASE_ADDRESS   0x40020000
typedef struct
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 DMA_RESERVED;
}Channel_RegDef_t;
typedef struct
{
	volatile u32   	 ISR;
	volatile u32 	 IFCR;
	Channel_RegDef_t CHANNEL[7];
}DMA_RegDef_t;


#define DMA       ((DMA_RegDef_t*)DMA_BASE_ADDRESS)


#endif
