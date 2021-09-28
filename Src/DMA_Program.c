/*****************************************************************************************************/
/*                                                                                                   */
/*                                            Author:Mahmoud Mohamed Mahmoud                         */
/*												Date:25/9/2021										 */
/*												 SWC:DMA		 									 */
/*											 Version:1.0											 */
/*																									 */
/*																									 */
/*****************************************************************************************************/
 #include"STD_TYPES.h"
 #include"bitMath.h"
 #include"ARM_peripherals.h"
 #include"DMA_Private.h"
 #include"DMA_Configration.h"
 #include"DMA_interface.h"

void DMA_Init(DMA_ChannelConfig_t * Copy_PStr)
 {
	//DMA->CHANNEL[Copy_PStr->Channel_Id].CCR=((Copy_PStr->MtoM_mode)<<MEM2MEM)|((Copy_PStr->Channel_Priority)<<PL)|((Copy_PStr->Memory_Size)<<MSIZE)|((Copy_PStr->Peripheral_Size)<<PSIZE)|((Copy_PStr->MINC_mode)<<MINC)|((Copy_PStr->PINC_mode)<<PINC)|(Copy_PStr->CIRC_mode<<CIRC)|(Copy_PStr->Data_Dir<<DIR)|(Copy_PStr->Trans_err_EN<<TEIE)|(Copy_PStr->HalfTrans_err_EN<<HTIE)|(Copy_PStr->TransComp_err_EN<<TCIE);

	/*
	*Configure :
	*1-memory to memory mode
	*2-channel priority
	*3-memory size
	*4-Peripheral size
	*5-Memory increment mode
	*6-Peripheral increment mode
	*/
	DMA->CHANNEL[Copy_PStr->Channel_Id].CCR=((Copy_PStr->MtoM_mode)<<MEM2MEM)|((Copy_PStr->Channel_Priority)<<PL)|((Copy_PStr->Memory_Size)<<MSIZE)|((Copy_PStr->Peripheral_Size)<<PSIZE)|((Copy_PStr->MINC_mode)<<MINC)|((Copy_PStr->PINC_mode)<<PINC);
	/*
	*1-Circular mode
	*2-Data transfer direction
	*3-Transfer error interrupt enable
	*4-Half transfer interrupt enable
	*5-TCIE: Transfer complete interrupt enable
	*/
	
	DMA->CHANNEL[Copy_PStr->Channel_Id].CCR|=(Copy_PStr->CIRC_mode<<CIRC)|(Copy_PStr->Data_Dir<<DIR)|(Copy_PStr->Trans_err_EN<<TEIE)|(Copy_PStr->HalfTrans_err_EN<<HTIE)|(Copy_PStr->TransComp_err_EN<<TCIE);
 
 }

void DMA_Start(DMA_ChannelConfig_t * Copy_PStr)
{
	/*disable the channel*/
	CLRBit(DMA->CHANNEL[Copy_PStr->Channel_Id].CCR,EN);
	/*Set memory address*/
	DMA->CHANNEL[Copy_PStr->Channel_Id].CMAR=(u32)Copy_PStr->MemAdd;
	/*Set prephiral address*/
	DMA->CHANNEL[Copy_PStr->Channel_Id].CPAR=(u32)Copy_PStr->PrephAdd;
	/*set number of transfered data */
	DMA->CHANNEL[Copy_PStr->Channel_Id].CNDTR=Copy_PStr->NumOfData;
	/*enable the channel*/
	SETBit(DMA->CHANNEL[Copy_PStr->Channel_Id].CCR,EN);
}










