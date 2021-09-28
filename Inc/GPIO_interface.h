/*****************************************************************************************************/
/*                                                                                                   */
/*                                            Auther:Mahmoud Mohamed Mahmoud                         */
/*												Date:19/9/2021										 */
/*												 SWC:GPIO											 */
/*											 Version:1.0											 */
/*																									 */
/*																									 */
/*****************************************************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
};

enum
{
	PORTA,PORTB,PORTC
};

enum
{
	GPIO_LOW,
	GPIO_HIGH
};

typedef enum
{
	
	/* Input Mode */
	GPIO_u8_INPUT_ANALOG       = 0b0000,
	GPIO_u8_INPUT_FLOATING     = 0b0100,
	GPIO_u8_INPUT_PULL_DOWN    = 0b1000,
	GPIO_u8_INPUT_PULL_UP      = 0b11000,
	/* Output Mode = 10MHZ */
	GPIO_u8_OUTPUT_GP_PP_10MHZ = 0b0001,
	GPIO_u8_OUTPUT_GP_OD_10MHZ = 0b0101,
	GPIO_u8_OUTPUT_AF_PP_10MHZ = 0b1001,
	GPIO_u8_OUTPUT_AF_OD_10MHZ = 0b1101,
	/* Output Mode = 2MHZ */
	GPIO_u8_OUTPUT_GP_PP_2MHZ  = 0b0010,
	GPIO_u8_OUTPUT_GP_OD_2MHZ  = 0b0110,
	GPIO_u8_OUTPUT_AF_PP_2MHZ  = 0b1010,
	GPIO_u8_OUTPUT_AF_OD_2MHZ  = 0b1110,
	/* Output Mode = 50MHZ */
	GPIO_u8_OUTPUT_GP_PP_50MHZ = 0b0011,
	GPIO_u8_OUTPUT_GP_OD_50MHZ = 0b0111,
	GPIO_u8_OUTPUT_AF_PP_50MHZ = 0b1011,
	GPIO_u8_OUTPUT_AF_OD_50MHZ = 0b1111
	
}PinMode_t;

typedef struct
{
	
	u8 PortId;
	u8 PinId;
	u8 PinMode;
	
}GPIO_PinMode_t;

void GPIO_PinMode_Init	(const GPIO_PinMode_t * Copy_GPIO_PinMode);
void GPIO_SetPin		(const GPIO_PinMode_t * Copy_GPIO_PinMode,u8 GPIO_Output_state);
void GPIO_TogglePin		(const GPIO_PinMode_t * Copy_GPIO_PinMode);
u8   GPIO_GetPin		(const GPIO_PinMode_t * Copy_GPIO_PinMode);


#endif

