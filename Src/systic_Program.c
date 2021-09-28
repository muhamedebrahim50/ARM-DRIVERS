#include"STD_TYPES.h"
#include"bitMath.h"
#include"ARM_peripherals.h"
#include"systic_Private.h"
#include"systic_Configration.h"
#include"systic_Interface.h"

static void (*STK_GPF)(void) = NULL;
static u8 STK_busyFlag = 0;

void STK_Init(void)
{
	STK->CTRL |= (STK_PRESCELER<<CLKSOURCE);
}
void STK_Enable(void)
{
	SETBit(STK->CTRL,ENABLE);
}
void STK_Disable(void)
{
	CLRBit(STK->CTRL,ENABLE);
	(STK->LOAD) = 0;
	(STK->VAL)  = 0;

}
u32 STK_ElapsedTime(void)
{
	return ((STK->LOAD)-(STK->VAL));
}
u32  STK_RemainingTime(void)
{
	return (STK->VAL);
}
void STK_Delay_ms(u32 DelayTime)
{
	if(STK_PRESCELER == AHB_DIVIDED_BY_8)
	{
		(STK->LOAD)= DelayTime * 1000;
	}
	else if(STK_PRESCELER == PROCESSOR_CLOCK)
	{
		(STK->LOAD)= DelayTime * 8000;
	}
	else {}
	STK_Enable();
	while(!GETBit(STK->CTRL,COUNTFLAG));
	STK_Disable();

}
void STK_PriodicInterval(u32 DelayTime,void(*STK_PF)(void))
{
	STK_busyFlag=0;
	SETBit(STK->CTRL,TICKINT);
	if(STK_PRESCELER == AHB_DIVIDED_BY_8)
	{
		(STK->LOAD)= DelayTime * 1000 -1;
	}
	else if(STK_PRESCELER == PROCESSOR_CLOCK)
	{
		(STK->LOAD)= DelayTime * 8000 -1;
	}
	else {}
	STK_GPF = STK_PF;
	STK_Enable();
}
void STK_SingleInterval(u32 DelayTime,void(*STK_PF)(void))
{
	STK_busyFlag=2;
	SETBit(STK->CTRL,TICKINT);
		if(STK_PRESCELER == AHB_DIVIDED_BY_8)
		{
			(STK->LOAD)= DelayTime * 1000 ;
		}
		else if(STK_PRESCELER == PROCESSOR_CLOCK)
		{
			(STK->LOAD)= DelayTime * 8000;
		}
		else {}
		STK_GPF = STK_PF;
		STK_Enable();
}

void SysTick_Handler (void)
{
	if(STK_busyFlag==2)
	{
		STK_Disable();
		CLRBit(STK->CTRL,TICKINT);
	}
	STK_GPF();
	STK_busyFlag= GETBit(STK->CTRL,COUNTFLAG);


}

