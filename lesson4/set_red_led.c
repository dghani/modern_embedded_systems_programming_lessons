#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

int main(void)
{
    volatile uint8_t * const RCGCGPIO = (uint8_t *)(0x400FE000);
    uint32_t const RCGCGPIO_port_f_offset = 0x608;
  
    // This is the APB interface, not AHB interface
    volatile uint8_t * const GPIO_port_f = (uint8_t *)(0x40025000);
    uint32_t const GPIODIR_port_f_offset = 0x400;
    //uint32_t const GPIODEN_port_f_offset = 0x51C;
    
    // Enable clock for GPIO Port F
    volatile uint8_t * const gpio_port_f_clock_enable = RCGCGPIO + RCGCGPIO_port_f_offset;
    *gpio_port_f_clock_enable |= (1 << 5);
    
    // Set direction to Output for R/G/B pins
    // bit 1: Red
    // bit 2: Green
    // bit 3: Blue
    volatile uint8_t * const gpio_port_f_direction = GPIO_port_f + GPIODIR_port_f_offset;
    *gpio_port_f_direction |= (1 << 1) || (1 << 2) || (1 << 3);
    
    // set Red led
    *((uint8_t*)0x400253FC) |= (1 << 1);
    
    return 0;
}
