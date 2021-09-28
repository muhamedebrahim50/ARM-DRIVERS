/*****************************************************************************************************/
/*                                                                                                   */
/*                                            Author:Mahmoud Mohamed Mahmoud                         */
/*												Date:20/9/2021										 */
/*												 SWC:SYSTIC		 									 */
/*											 Version:1.0											 */
/*																									 */
/*																									 */
/*****************************************************************************************************/

#ifndef SYSTIC_INTERFACE_H_
#define SYSTIC_INTERFACE_H_

void 	STK_Init			(void);
void 	STK_Enable			(void);
void	STK_Disable			(void);
u32		STK_ElapsedTime		(void);
u32		STK_RemainingTime	(void);
void	STK_Delay_ms		(u32 DelayTime);
void 	STK_PriodicInterval	(u32 DelayTime,void(*STK_PF)(void));
void 	STK_SingleInterval	(u32 DelayTime,void(*STK_PF)(void));

#endif
