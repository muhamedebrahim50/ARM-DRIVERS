/*****************************************************************************************************/
/*                                                                                                   */
/*                                            Author:Mahmoud Mohamed Mahmoud                         */
/*												Date:19/9/2021										 */
/*												 SWC:RCC		 									 */
/*											 Version:1.0											 */
/*																									 */
/*																									 */
/*****************************************************************************************************/
 #include"STD_TYPES.h"
 #include"bitMath.h"
 #include"ARM_peripherals.h"
 #include"RCC_Private.h"
 #include"RCC_Configration.h"
 #include"RCC_interface.h"

 
 void RCC_SelectSysClk(void)
 {
	 	/***************** CONFIGRATION OF SYSTEM CLOCK ******************/
		/*****************************************************************/

	#if RCC_SYSTEM_CLK==HSI_SELECTED_AS_SYS_CLK
			 SETBit(RCC->RCC_CR,HSION);							//Enable HSI Clock
			 while(!GETBit(RCC->RCC_CR,HSIRDY));					//Wait till HSI to be Ready
			 RCC->RCC_CFGR&=~(0b11<<SW) ;
		 RCC->RCC_CFGR|= (RCC_SYSTEM_CLK<<SW) ;					//select HSI AS SYS CLK
		/*****************************************************************/
	#elif RCC_SYSTEM_CLK == HSE_SELECTED_AS_SYS_CLK
		 SETBit(RCC->RCC_CR,HSEON);								//Enable HSE Clock
		 while(!GETBit(RCC->RCC_CR,HSERDY));						//Wait till HSE to be Ready
		 RCC->RCC_CFGR&=~(0b11<<SW) ;
		 RCC->RCC_CFGR |= (RCC_SYSTEM_CLK<<SW) ;				//select HSE AS SYS CLK
		/*****************************************************************/

	#elif RCC_SYSTEM_CLK == PLL_SELECTED_AS_SYS_CLK
					/*****  chek the Pll configration  ****/
		#if PLL_CLK_SRC==HSI_CLK_DIVIDED_BY_2
		 RCC->RCC_CFGR|=(PLL_CLK_SRC<<PLLSRC);
		#elif PLL_CLK_SRC == HSE_CLK_NOT_DIVIDED
		 RCC->RCC_CFGR|=(PLL_CLK_SRC<<PLLSRC);
		#elif PLL_CLK_SRC == HSE_CLK_DIVIDED_BY_2
		 RCC->RCC_CFGR|=(PLL_CLK_SRC<<PLLSRC);
		#else
			#error "wrong choice"
	    #endif
		 SETBit(RCC->RCC_CR,PLLON);                             //Enable PLL Clock
		 while(!GETBit(RCC->RCC_CR,PLLRDY));                     //Wait till PLL to be Ready
		 RCC->RCC_CFGR&=~(0b11<<SW) ;
		 RCC->RCC_CFGR|= (RCC_SYSTEM_CLK<<SW) ;					//select PLL AS SYS CLK

		 	 	 	 /*************************************/
		/*****************************************************************/

	#else
		 #error "wrong choice"
	#endif
		 	/************* PRESCELER OF PERIPHERAL CLOCK & bUSES *************/
			/*****************************************************************/
	#if	ADC_ENABLE
		 RCC->RCC_CFGR|= (ADC_PRESCALER<<ADCPRE);
  	#endif

  	#if	USB_ENABLE
		 RCC->RCC_CFGR|= (USB_PRESCALER<<USBPRE);
  	#endif

    #if	APB1_ENABLE
		 RCC->RCC_CFGR|= (APB1_PRESCALER<<PPRE1);
  	#endif

	#if	APB2_ENABLE
			 RCC->RCC_CFGR|= (APB2_PRESCALER<<PPRE2);
	#endif

	#if	AHB_ENABLE
			 RCC->RCC_CFGR|= (AHB_PRESCALER<<HPRE);
	#endif

	#if	MCO_ENABLE
		 RCC->RCC_CFGR|= (MCO_CLK_SRC<<MCO);
  	#endif

           /*****************************************************************/
 }
 void RCC_Enable_peripheralClk(u8 RCC_u8peripheralId)
 {
	 if(RCC_u8peripheralId<32)
	 {
		 SETBit(RCC->RCC_AHBENR,RCC_u8peripheralId);
	 }
	 else if(RCC_u8peripheralId<64)
	 {
		 SETBit(RCC->RCC_APB2ENR,(RCC_u8peripheralId-APB2ENR_offset));
	 }
	 else if(RCC_u8peripheralId<96)
	 {
		 SETBit(RCC->RCC_APB1ENR,(RCC_u8peripheralId-APB1ENR_offset));
	 }
	 else{}
	 
 }
 void RCC_Disable_peripheralClk(u8 RCC_u8peripheralId)
 {
	 if(RCC_u8peripheralId<32)
	 {
		 CLRBit(RCC->RCC_AHBENR,RCC_u8peripheralId);
	 }
	 else if(RCC_u8peripheralId<64)
	 {
		 CLRBit(RCC->RCC_APB2ENR,(RCC_u8peripheralId-APB2ENR_offset));
	 }
	 else if(RCC_u8peripheralId<96)
	 {
		 CLRBit(RCC->RCC_APB1ENR,(RCC_u8peripheralId-APB1ENR_offset));
	 }
	 else{}
 }
 
