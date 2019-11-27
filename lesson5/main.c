#include <stdint.h>
#include <stdbool.h>

#include "inc/tm4c123gh6pm.h"

//#define RCGCGPIO (*((uint32_t *)0x400FE608U))

//#define GPIOF_DIR  (*((uint32_t *)0x40025400U))
//#define GPIOF_DEN  (*((uint32_t *)0x4002551CU))
//#define GPIOF_DATA (*((uint32_t *)0x400253FCU))

#define GPIOF_LED_RED   (1 << 1)
#define GPIOF_LED_BLUE  (1 << 2)
#define GPIOF_LED_GREEN (1 << 3)

void delay_blink(void)
{
    for (volatile int i = 0; i < 300; i++)
    {
    }
}

void delay_roughly_1_second(void)
{
    for (volatile int i = 0; i < 1250000; i++)
    {
    }
}

int main(void)
{

    // Enable GPIO Port F
    SYSCTL_RCGCGPIO_R |= (1 << 5);
    
    GPIO_PORTF_DIR_R |= GPIOF_LED_RED | GPIOF_LED_BLUE | GPIOF_LED_GREEN;
    GPIO_PORTF_DEN_R |= GPIOF_LED_RED | GPIOF_LED_BLUE | GPIOF_LED_GREEN;
    
    while (1)
    {
        // Red led ON
        GPIO_PORTF_DATA_R |= GPIOF_LED_RED;
        
        delay_blink();
        
        // Red led OFF
        GPIO_PORTF_DATA_R &= ~GPIOF_LED_RED;
        
        delay_roughly_1_second();
        
        // Blue led ON
        GPIO_PORTF_DATA_R |= GPIOF_LED_BLUE;
        
        delay_blink();
        
        // Blue led OFF
        GPIO_PORTF_DATA_R &= ~GPIOF_LED_BLUE;
        
        delay_roughly_1_second();
        
        // Green led ON
        GPIO_PORTF_DATA_R |= GPIOF_LED_GREEN;
        
        delay_blink();
        
        // Green led OFF
        GPIO_PORTF_DATA_R &= ~GPIOF_LED_GREEN;
        
        delay_roughly_1_second();
    }
    
    return 0;
}
