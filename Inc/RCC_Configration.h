/*****************************************************************************************************/
/*                                                                                                   */
/*                                            Auther:Mahmoud Mohamed Mahmoud                         */
/*												Date:19/9/2021										 */
/*												 SWC:RCC		 									 */
/*											 Version:1.0											 */
/*																									 */
/*																									 */
/*****************************************************************************************************/

/*************************************************************************/
#ifndef RCC_CONFIGRATION_H_
#define RCC_CONFIGRATION_H_

/***********************     system clock options ************************/
            //1-HSI_SELECTED_AS_SYS_CLK
            //2-HSE_SELECTED_AS_SYS_CLK
            //3-PLL_SELECTED_AS_SYS_CLK

#define RCC_SYSTEM_CLK          HSE_SELECTED_AS_SYS_CLK
/*************************************************************************/
/***********************     PLL Source options   ************************/
			//1-HSI_CLK_DIVIDED_BY_2
            //2-HSE_CLK_NOT_DIVIDED
            //3-HSE_CLK_DIVIDED_BY_2
			
#define PLL_CLK_SRC          	HSE_CLK_NOT_DIVIDED
/*************************************************************************/
/*********************     PLL MUL_Factor options   **********************/

			//1-PLL_INPUT_CLK_X2
            //2-PLL_INPUT_CLK_X3
			//        .
			//        .
			//        .
			//14-PLL_INPUT_CLK_X15
			//15-PLL_INPUT_CLK_X16
			
#define PLL_MUL_FACTOR	 		PLL_INPUT_CLK_X2
/*************************************************************************/
/*******************     APB1+APB2_Prescaler options   *******************/


			//1- HCLK_NOT_DIVIDED  
			//2- HCLK_DIVIDED_BY_2 	
            //3- HCLK_DIVIDED_BY_4 
            //4- HCLK_DIVIDED_BY_8 
            //5- HCLK_DIVIDED_BY_16

#define	APB1_PRESCALER			HCLK_NOT_DIVIDED
#define APB2_PRESCALER			HCLK_NOT_DIVIDED
/*************************************************************************/
/*********************     AHB_Prescaler options   ***********************/


			//1-SYSCLK_NOT_DIVIDED		
            //2-SYSCLK_DIVIDED_BY_2	
            //3-SYSCLK_DIVIDED_BY_4	
            //4-SYSCLK_DIVIDED_BY_8	
            //5-SYSCLK_DIVIDED_BY_16
            //6-SYSCLK_DIVIDED_BY_64
	        //7-SYSCLK_DIVIDED_BY_128
            //8-SYSCLK_DIVIDED_BY_256
            //9-SYSCLK_DIVIDED_BY_512
			
#define	AHB_PRESCALER	  		SYSCLK_NOT_DIVIDED		

/*************************************************************************/
/*********************     ADC_Prescaler options   ***********************/

			//1-PCLK2_DIVIDED_BY_2
            //2-PCLK2_DIVIDED_BY_4
			//3-PCLK2_DIVIDED_BY_6
            //4-PCLK2_DIVIDED_BY_8

#define	ADC_PRESCALER			PCLK2_DIVIDED_BY_2
/*************************************************************************/
/*********************     USB_Prescaler options   ***********************/

			//1-PLL_CLK_DIVIDED_BY_1_5	
            //2-PLL_CLK_NOT_DIVIDED	
			
#define	USB_PRESCALER		PLL_CLK_NOT_DIVIDED	

/*************************************************************************/
/*********************     MCO_CLK_Source options   ***********************/

				
			//1-MCO_NO_CLK				
			//2-MCO_SYSTRM_CLK			
            //3-MCO_HSI_CLK			
            //4-MCO_HSE_CLK			
			//5-MCO_PLL_CLK_DIVIDED_BY_2
			
#define MCO_CLK_SRC			MCO_SYSTRM_CLK	
			
#endif			
			
			