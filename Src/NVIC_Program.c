/*****************************************************************************************************/
/*                                                                                                   */
/*                                            Author:Mahmoud Mohamed Mahmoud                         */
/*												Date:23/9/2021										 */
/*												 SWC:NVIC									         */
/*											 Version:1.0											 */
/*																									 */
/*																									 */
/*****************************************************************************************************/
#include"STD_TYPES.h"
#include"bitMath.h"
#include"ARM_peripherals.h"
#include"NVIC_Interface.h"

#define SCB_u32_AIRCR_REG                       *((volatile u32*)(0xE000ED00+0x0c))

u8 NVIC_u8EnableInterrupt      (u8 Copy_u8IRQNum)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	u8 Local_u8RegIndex,Local_u8BitNum;
	if(Copy_u8IRQNum <= 239)
	{
		Local_u8ErrorState = STD_TYPES_OK;
		Local_u8RegIndex = Copy_u8IRQNum/32;
		Local_u8BitNum   = Copy_u8IRQNum%32;
		NVIC->ISER[Local_u8RegIndex] = (1<<Local_u8BitNum);
	}
	return Local_u8ErrorState;
}

u8 NVIC_u8DisableInterrupt     (u8 Copy_u8IRQNum)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	u8 Local_u8RegIndex,Local_u8BitNum;
	if(Copy_u8IRQNum <= 239)
	{
		Local_u8ErrorState = STD_TYPES_OK;
		Local_u8RegIndex = Copy_u8IRQNum/32;
		Local_u8BitNum   = Copy_u8IRQNum%32;
		NVIC->ICER[Local_u8RegIndex] = (1<<Local_u8BitNum);
	}
	return Local_u8ErrorState;
}

u8 NVIC_u8SetPendingFlag       (u8 Copy_u8IRQNum)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	u8 Local_u8RegIndex,Local_u8BitNum;
	if(Copy_u8IRQNum <= 239)
	{
		Local_u8ErrorState = STD_TYPES_OK;
		Local_u8RegIndex = Copy_u8IRQNum/32;
		Local_u8BitNum   = Copy_u8IRQNum%32;
		NVIC->ISPR[Local_u8RegIndex] = (1<<Local_u8BitNum);
	}
	return Local_u8ErrorState;
}

u8 NVIC_u8ClearPendingFlag     (u8 Copy_u8IRQNum)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	u8 Local_u8RegIndex,Local_u8BitNum;
	if(Copy_u8IRQNum <= 239)
	{
		Local_u8ErrorState = STD_TYPES_OK;
		Local_u8RegIndex = Copy_u8IRQNum/32;
		Local_u8BitNum   = Copy_u8IRQNum%32;
		NVIC->ICPR[Local_u8RegIndex] = (1<<Local_u8BitNum);
	}
	return Local_u8ErrorState;
}

u8 NVIC_u8GetActiveFlag        (u8 Copy_u8IRQNum,u8 * Copy_pu8ActiveFlagState)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	u8 Local_u8RegIndex,Local_u8BitNum;
	if((Copy_u8IRQNum <= 239) && (Copy_pu8ActiveFlagState != NULL))
	{
		Local_u8ErrorState = STD_TYPES_OK;
		Local_u8RegIndex = Copy_u8IRQNum/32;
		Local_u8BitNum   = Copy_u8IRQNum%32;
		*Copy_pu8ActiveFlagState = GETBit(NVIC->IABR[Local_u8RegIndex],Local_u8BitNum);
	}
	return Local_u8ErrorState;
}
u8 NVIC_SetPriority            (u8 Copy_u8IRQNum,u8 Copy_u8GrpPriority,u8 Copy_u8SubPriority)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((Copy_u8IRQNum < 240) && (Copy_u8GrpPriority <= NVIC_u8_GRP_PRI_3) && (Copy_u8SubPriority <= NVIC_u8_SUB_PRI_3))
	{
		/* Init Priority Field *//* 2 Grp Priority field and 2 Sub Priority field */
		SCB_u32_AIRCR_REG = 0x05FA0500;

		NVIC->IPR[Copy_u8IRQNum] = ((Copy_u8GrpPriority<<6) | (Copy_u8SubPriority<<4));
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
