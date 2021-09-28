/*****************************************************************************************************/
/*                                                                                                   */
/*                                            Author:Mahmoud Mohamed Mahmoud                         */
/*												Date:21/9/2021										 */
/*												 SWC:USART									         */
/*											 Version:1.0											 */
/*																									 */
/*																									 */
/*****************************************************************************************************/
#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

	   /********************* status register *****************/
       /*******************************************************/

typedef enum 
{
	PE,
	FE,
	NE,
	ORE,
	IDLE,
	RXNE, 
	TC,
	TXE,
	LBD,
	CTS,

}USART_SR;

       /*******************************************************/
       /******************** Baud_Rate register ***************/
       /*******************************************************/



typedef enum 
{
	DIV_Fraction,
	DIV_Mantissa=4
}USART_BRR;

       /*******************************************************/
       /******************** Baud_Rate register ***************/
       /*******************************************************/

typedef enum 
{
	SBK,
	RWU,
	RE,
	TE,
	IDLEIE,
	RXNEIE,
	TCIE,
	TXEIE,
	PEIE,
	PS,
	PCE,
	WAKE,
	M,
	UE           
}USART_CR1;

typedef enum 
{
	ADD,
	LBDL=5,
	LBDIE,
	LBCL=8,
	CPHA,
	CPOL,
	CLKEN,
	STOP,
	LINEN=14
}USART_CR2;

typedef enum 
{
	EIE,
	IREN,
	IRLP,
	HDSEL,
	NACK,
	SCEN,
	DMAR,
	DMAT,
	RTSE,
	CTSE,
	CTSIE
}USART_CR3;





#endif


