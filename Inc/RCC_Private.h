/*****************************************************************************************************/
/*                                                                                                   */
/*                                            Auther:Mahmoud Mohamed Mahmoud                         */
/*												Date:19/9/2021										 */
/*												 SWC:RCC		 									 */
/*											 Version:1.0											 */
/*																									 */
/*																									 */
/*****************************************************************************************************/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/*************************************************************************/

/*RCC_CR register*/
#define HSION		0
#define	HSIRDY		1
#define	HSITRIM		3	//5 bits
#define	HSICAL		8	//8bits
#define HSEON		16
#define	HSERDY		17
#define HSEBYP		18  //can be written only if the HSE oscillator is disabled.
#define	CSSON		19	//Clock security system enable
#define PLLON		24
#define PLLRDY		25
/*************************************************************************/

/*RCC_CFGR register*/
#define SW			0	//2 bits,System clock switch
#define	HPRE		4	//4 bits,AHB prescaler.
#define	PPRE1		8	//3 bits,APB high-speed prescaler (APB1)
#define	PPRE2		11	//3 bits,APB high-speed prescaler (APB2)
#define	ADCPRE		14	//2 bits
#define	PLLSRC		16	//PLL entry clock source,This bit can be written only when PLL is disabled.
#define PLLXTPRE	17	//HSE divider for PLL entry,this bit can be written only when PLL is disabled.
#define PLLMUL		18  //3 bits These bits can be written only when PLL is disabled.
#define USBPRE		22
#define MCO			24	//3 bits define source for MCU clock output
/*************************************************************************/
/*CLK source for MCO*/
enum{
	 MCO_NO_CLK					=	0b000,
	 MCO_SYSTRM_CLK				=	0b100,
	 MCO_HSI_CLK				=	0b101,
	 MCO_HSE_CLK				=	0b110,
	 MCO_PLL_CLK_DIVIDED_BY_2	=	0b111	
};
/*************************************************************************/
/*Prescaler for USB*/
enum{
	 PLL_CLK_DIVIDED_BY_1_5		=	0,
	 PLL_CLK_NOT_DIVIDED		=	1
};
/*************************************************************************/

/*CLK factoe for PLL*/
enum{
	 PLL_INPUT_CLK_X2			=	0b0000,
	 PLL_INPUT_CLK_X3  			=	0b0001,
	 PLL_INPUT_CLK_X4  			=	0b0010,
	 PLL_INPUT_CLK_X5  			=	0b0011,
	 PLL_INPUT_CLK_X6  			=	0b0100,
	 PLL_INPUT_CLK_X7  			=	0b0101,
	 PLL_INPUT_CLK_X8  			=	0b0110,
	 PLL_INPUT_CLK_X9  			=	0b0111,					
	 PLL_INPUT_CLK_X10 			=	0b1000,
	 PLL_INPUT_CLK_X11 			=	0b1001,
	 PLL_INPUT_CLK_X12 			=	0b1010,
	 PLL_INPUT_CLK_X13 			=	0b1011,
	 PLL_INPUT_CLK_X14 			=	0b1100,
	 PLL_INPUT_CLK_X15 			=	0b1101,
	 PLL_INPUT_CLK_X16 			=	0b1110
};
/*************************************************************************/
/*PLL CLK source*/
enum{
	 HSI_CLK_DIVIDED_BY_2		=	0b00,
	 HSE_CLK_NOT_DIVIDED		=	0b01,
	 HSE_CLK_DIVIDED_BY_2       =	0b11
};

/*************************************************************************/
/*************************************************************************/
/*ADC prescaler*/
enum{
     PCLK2_DIVIDED_BY_2 		=	0b00,
     PCLK2_DIVIDED_BY_4 		=	0b01,
     PCLK2_DIVIDED_BY_6 		=	0b10,
     PCLK2_DIVIDED_BY_8 		=	0b11
};
/*************************************************************************/
/*APB high-speed prescaler (APB2) and APB low-speed prescaler (APB1)*/
enum{
	 HCLK_NOT_DIVIDED           =	0b000,
     HCLK_DIVIDED_BY_2          =	0b100,
     HCLK_DIVIDED_BY_4          =	0b101,
     HCLK_DIVIDED_BY_8          =	0b110,
     HCLK_DIVIDED_BY_16			=	0b111
};                                  
/*************************************************************************/
/*AHB prescaler*/                   
enum{                               
	 SYSCLK_NOT_DIVIDED			=	0b0000,
     SYSCLK_DIVIDED_BY_2		=	0b1000,
     SYSCLK_DIVIDED_BY_4		=	0b1001,
     SYSCLK_DIVIDED_BY_8		=	0b1010,
     SYSCLK_DIVIDED_BY_16		=	0b1011,
     SYSCLK_DIVIDED_BY_64		=	0b1100,
     SYSCLK_DIVIDED_BY_128		=	0b1101,
     SYSCLK_DIVIDED_BY_256		=	0b1110,
     SYSCLK_DIVIDED_BY_512		=	0b1111
};

/*************************************************************************/
/*System clock switch*/

	 #define HSI_SELECTED_AS_SYS_CLK 		0
     #define HSE_SELECTED_AS_SYS_CLK 		1
     #define PLL_SELECTED_AS_SYS_CLK 		2
/*************************************************************************/
#endif

