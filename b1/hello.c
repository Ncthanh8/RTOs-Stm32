#include <stdint.h>
#include "reg.h"

#define USART_FLAG_TXE ((unit16_t) 0x0080)

int puts(const char *str)
{
	while(*str){
		while (!(*(USART2_SR) & USART_FLAG_TXE));
		*(USART2_DR) = *str++ & 0xff;
	}
	return 0;
}

void main(void)
{
	*(RCC_APB2ENR) |= (uint32_t) (0x00000001 | 0x00000004);
	*(RCC_APB1ENR) |= (uint32_t) (0x00020000);

	/* USART2 config */

	*(GPIOA_CRL) = 0x00004B00;
	*(GPIOA_CRH) = 0x44444444;

	*(USART2_CR1) = 0x0000000C;
	*(USART2_CR1) |= 0X2000;

	puts("Hello VietNam\n");
	while (1)
}
