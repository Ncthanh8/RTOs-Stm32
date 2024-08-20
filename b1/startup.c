#include <stdint.h>

extern void main(void)
void reset_handler(void)
{
	main();
}

__attribute((section(".isr_vector")))
unit32_t *isr_vector[] = {
	0,(uint32_t *)reset_handler,
};
