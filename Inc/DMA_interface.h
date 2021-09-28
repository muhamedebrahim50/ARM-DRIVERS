/*****************************************************************************************************/
/*                                                                                                   */
/*                                            Auther:Mahmoud Mohamed Mahmoud                         */
/*												Date:25/9/2021										 */
/*												 SWC:DMA											 */
/*											 Version:1.0											 */
/*																									 */
/*																									 */
/*****************************************************************************************************/

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

/***************************************************************************/

typedef enum
{
	EN,
	TCIE,
	HTIE,
	TEIE,
	DIR,
	CIRC,
	PINC,
	MINC,
	PSIZE,
	MSIZE=10,
	PL=12,
	MEM2MEM=14
}DMA_CRR;

typedef enum
{
	DMA_PriortyLow,
	DMA_PriortyMedium,
	DMA_PriortyHigh,
	DMA_PriortyVeryhigh
}Channelprioritylevel;

typedef enum
{
	_8_bits,
	_16_bits,
	_32_bits
}Data_size;

typedef enum
{
	CH1,
	CH2,
	CH3,
	CH4,
	CH5,
	CH6,
	CH7
}DMA_Channel_id_t;

typedef enum
{
	Read_from_peripheral,
	Read_from_memory
}Data_transfer_t;

typedef struct
{
	DMA_Channel_id_t 			Channel_Id;
	Channelprioritylevel	 	Channel_Priority;
	Data_size				 	Peripheral_Size;
	Data_size 					Memory_Size;
	Data_transfer_t 			Data_Dir;
	u32 						*MemAdd;
	u32 						*PrephAdd;
	u16 						NumOfData;
	u8 							MtoM_mode;
	u8 							MINC_mode;
	u8 							PINC_mode;
	u8 							CIRC_mode;
	u8 							Trans_err_EN;
	u8 							HalfTrans_err_EN;
	u8 							TransComp_err_EN;

}DMA_ChannelConfig_t;

void DMA_Init(DMA_ChannelConfig_t * Copy_PStr);
void DMA_Start(DMA_ChannelConfig_t * Copy_PStr);

#endif

