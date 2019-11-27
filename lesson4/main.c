#include <stdint.h>
#include <stdbool.h>

int main(void)
{
  
    volatile uint32_t * const RCGCGPIO_ptr = (uint32_t *)0x400FE608U;
    volatile uint32_t * const GPIODIR_ptr =  (uint32_t *)0x40025400U;
    volatile uint32_t * const GPIODEN_ptr =  (uint32_t *)0x4002551CU;
    volatile uint32_t * const led_ptr =      (uint32_t *)0x400253FCU;
    
    *RCGCGPIO_ptr |= (1 << 5);
    
    *GPIODIR_ptr |= (1 << 1) | (1 << 2) | (1 << 3);
    
    *GPIODEN_ptr |= (1 << 1) | (1 << 2) | (1 << 3);
    
    // set Red led ON
    *led_ptr |= (1 << 1);
    
    // set Red led OFF
    *led_ptr &= ~(1 << 1);
    
    return 0;
}
