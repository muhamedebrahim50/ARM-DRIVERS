/*****************************************************************************************************/
/*                                                                                                   */
/*                                            Auther:Mahmoud Mohamed Mahmoud                         */
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
	volatile u32 RCC_CR       ;
	volatile u32 RCC_CFGR     ;
	volatile u32 RCC_CIR      ;
    volatile u32 RCC_APB2RSTR ;
    volatile u32 RCC_APB1RSTR ;
    volatile u32 RCC_AHBENR   ;
    volatile u32 RCC_APB2ENR  ;
    volatile u32 RCC_APB1ENR  ;
    volatile u32 RCC_BDCR     ;
	volatile u32 RCC_CSR      
}RCC_RegDef_t;

#define RCC       ((RCC_RegDef_t*)RCC_BASE_ADDRESS)


#endif