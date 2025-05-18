

#include <stdint.h>

#define GPIOA 	 		0x40020000U
#define RCC				0x40023800U

#define GPIOA_MODER 	(*(uint32_t volatile *)	(GPIOA + 0x00U))
#define GPIOA_OTYPER 	(*(uint32_t volatile *)	(GPIOA + 0x04U))
#define GPIOA_PUPDR 	(*(uint32_t volatile *)	(GPIOA + 0x0CU))
#define GPIOA_BSRR		(*(uint32_t volatile *)	(GPIOA + 0x18U))
#define RCC_AHB1_GPIOA_EN (*(uint32_t volatile*)(RCC  +  0x30U))

int main(void)
{
	RCC_AHB1_GPIOA_EN |= (1U << 0U);
	GPIOA_MODER  &= ~(3U << 10U);
	GPIOA_MODER  |=  (1U << 10U);
	GPIOA_OTYPER &= ~(1u << 5U);
	GPIOA_PUPDR  &= ~(3U << 10U);

	while(1)
	{
		GPIOA_BSRR = (1U << 5U);
		uint32_t volatile counter= 0;
		while(counter < 500000){
			counter++;
		}

		counter = 0;
		GPIOA_BSRR = (1U << (5U+16U));
		while(counter < 500000){
					counter++;
		}
	}
}
