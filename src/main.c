#include "gpio.h"
#include "utils.h"
#include "rcc.h"
#include "timer.h"

void timer_callback(void)
{
  gpio_toggle(PIN('C',13));
}


int main(void)
{
rcc_init();

 SET_BIT(RCC->APB2ENR,RCC_APB2ENR_IOPC);
 SET_BIT(RCC->APB2ENR,RCC_APB1ENR_TIM2);
  
  gpio_set_mode(PIN('C',13),GPIO_CNF_OUT_PP, GPIO_MODE_OUT_2MHZ);  


  timer_config cfg = 
    {
     .period = 7199, .prescaler = 9999
    };

  timer_init(TIM2, cfg);
  timer_start(TIM2);
  timer_enable_interrupt(TIM2);

  timer_set_callback(TIM2,(timer_callback_t)timer_callback);

    
  while (1)
    {
       
    }
}
