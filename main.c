//////////////////////////////////////////////////////////////////////////////
// Project:		Wii Classic Controller  i.c.m. de STM32VLDISCOVERY (Quadcopter)
// Datum:		23-09-2013
// Naam:		Gregory Knauff (1587368)
//
// I2C test met de Wii Classic Controller
//////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>

int main(void)
{
 GPIO_InitTypeDef gpio;
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

 GPIO_StructInit(&gpio);
 gpio.GPIO_Mode = GPIO_Mode_Out_PP;
 gpio.GPIO_Speed = GPIO_Speed_2MHz;

 gpio.GPIO_Pin = GPIO_Pin_9; // Green LED
 GPIO_Init(GPIOC, &gpio);
 gpio.GPIO_Pin = GPIO_Pin_8; // Blue LED
 GPIO_Init(GPIOC, &gpio);

 printf("I2C Wii Classic Controller\r\n\r\n");
 //printf("1\r\n");

 gpio.GPIO_Pin = GPIO_Pin_9;
 GPIO_Init(GPIOB, &gpio);
 //GPIO_WriteBit(GPIOB, GPIO_Pin_9, Bit_SET);
 GPIOB->BSRR = 0x0200; // Set/Clear pin 9 of PORTB


 while(1)
 {
	 static int count=0;
	 static int i;
	 static int led_state=0;

	 for (i=0; i<1000000; ++i);
	 GPIO_WriteBit(GPIOC, GPIO_Pin_9, led_state ? Bit_SET : Bit_RESET);
	 led_state = !led_state;
	 GPIO_WriteBit(GPIOC, GPIO_Pin_8, led_state ? Bit_SET : Bit_RESET);

     //printf("%d\r\n", ++count);
 }
}
