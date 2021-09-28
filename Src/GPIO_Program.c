/*****************************************************************************************************/
/*                                                                                                   */
/*                                            Auther:Mahmoud Mohamed Mahmoud                         */
/*												Date:19/9/2021										 */
/*												 SWC:GPIO		 									 */
/*											 Version:1.0											 */
/*																									 */
/*																									 */
/*****************************************************************************************************/
 #include"STD_TYPES.h"
 #include"bitMath.h"
 #include"ARM_peripherals.h"
 #include"GPIO_interface.h"

 GPIO_RegDef_t*GPIO_APStrGPIOPORT[3]={GPIOA,GPIOB,GPIOC};
 
 void GPIO_PinMode_Init	(const GPIO_PinMode_t * Copy_GPIO_PinMode)
 {
	 u8 pinmode=Copy_GPIO_PinMode->PinMode;

	 if(pinmode == GPIO_u8_INPUT_PULL_UP)
	 {
		 CLRBit(pinmode,4);
		 GPIO_APStrGPIOPORT[Copy_GPIO_PinMode->PortId]->BSRR=  (1<<(Copy_GPIO_PinMode->PinId));
	 }
	 
	 else if(pinmode == GPIO_u8_INPUT_PULL_DOWN)
	 {
		 GPIO_APStrGPIOPORT[Copy_GPIO_PinMode->PortId]->BRR=  (1<<(Copy_GPIO_PinMode->PinId));
	 }
	 else{}
	 if((Copy_GPIO_PinMode->PinId)>=PIN0 && (Copy_GPIO_PinMode->PinId)<=PIN7)
	 {
		 GPIO_APStrGPIOPORT[Copy_GPIO_PinMode->PortId]->CRL &= ~((0b1111)<<(4*(Copy_GPIO_PinMode->PinId)));
		 GPIO_APStrGPIOPORT[Copy_GPIO_PinMode->PortId]->CRL |=  ((pinmode)<<(4*(Copy_GPIO_PinMode->PinId)));
	 }
	 else if((Copy_GPIO_PinMode->PinId)>=PIN8 && (Copy_GPIO_PinMode->PinId)<=PIN15)
	 	 {
	 		 GPIO_APStrGPIOPORT[Copy_GPIO_PinMode->PortId]->CRH &= ~((0b1111)<<(4*((Copy_GPIO_PinMode->PinId)-8)));
	 		 GPIO_APStrGPIOPORT[Copy_GPIO_PinMode->PortId]->CRH |=  ((pinmode)<<(4*((Copy_GPIO_PinMode->PinId)-8)));
	 	 }
	 else{}


 }
 void GPIO_SetPin		(const GPIO_PinMode_t * Copy_GPIO_PinMode,u8 GPIO_Output_state)
 {
	 if(GPIO_Output_state == GPIO_HIGH)
	 {
		 GPIO_APStrGPIOPORT[Copy_GPIO_PinMode->PortId]->BSRR=  (1<<(Copy_GPIO_PinMode->PinId));
	 }
	 else if(GPIO_Output_state == GPIO_LOW)
	 {
	 	 GPIO_APStrGPIOPORT[Copy_GPIO_PinMode->PortId]->BRR=  (1<<(Copy_GPIO_PinMode->PinId));
	 }
 }
 void GPIO_TogglePin	(const GPIO_PinMode_t * Copy_GPIO_PinMode)
 {
	 TGLBit((GPIO_APStrGPIOPORT[Copy_GPIO_PinMode->PortId]->ODR),(Copy_GPIO_PinMode->PinId));
 }
 u8   GPIO_GetPin		(const GPIO_PinMode_t * Copy_GPIO_PinMode)
 {
	 return GETBit((GPIO_APStrGPIOPORT[Copy_GPIO_PinMode->PortId]->ODR),(Copy_GPIO_PinMode->PinId));
 }
