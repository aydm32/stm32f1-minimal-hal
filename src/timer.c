#include "timer.h"
#include "rcc.h"
#include "utils.h"
#include <stddef.h>

static timer_callback_t tim1_callback = NULL;
static timer_callback_t tim2_callback = NULL;
static timer_callback_t tim3_callback = NULL;
static timer_callback_t tim4_callback = NULL;

static void timer_clock_enable(TIMx_t *timer)
{
  if (timer == TIM1) {
  SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1);  
  }
  else if(timer == TIM2)
  {
  SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM2);  
  }
  else if(timer == TIM3)
  {
  SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM3);  
  }
  else if(timer == TIM4)
  {
  SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM4);  
  }
}

void timer_init(TIMx_t *timer,timer_config cfg)
{ 
  // 1. Enable peripheral clock
  timer_clock_enable(timer);
  // 2. Configure PSC
  timer->PSC = cfg.prescaler;
  // 3. Configure ARR
  timer->ARR = cfg.period;
  // 4. Reset the counter 
  timer->CNT = 0; 
  // 5. Generate update event 
  SET_BIT(timer->EGR, EGR_UG);
}

void timer_start(TIMx_t * timer)
{
  // Enable counter 
  SET_BIT(timer->CR1, CR1_CEN);

}

void timer_stop(TIMx_t * timer)
{
  // Disable counter 
  CLEAR_BIT(timer->CR1, CR1_CEN);
}

void timer_enable_interrupt(TIMx_t *timer)
{
  SET_BIT(timer->DIER, DIER_UIE);
}

void timer_disable_interrupt(TIMx_t *timer)
{
  CLEAR_BIT(timer->DIER, DIER_UIE);
}

void timer_set_callback(TIMx_t* timer,timer_callback_t callback)
{
   
    if (timer == TIM1)
    {
        tim1_callback = callback;
    }
    else if (timer == TIM2)
    {
        tim2_callback = callback;
    }
    else if (timer == TIM3)
    {
        tim3_callback = callback;
    }
    else if (timer == TIM4)
    {
        tim4_callback = callback;
    }
}

void TIM2_IRQHandler(void)
{
  if(TIM2->SR & SR_UIF)
  {
    CLEAR_BIT(TIM2->SR, SR_UIF);
    if(tim2_callback != NULL)
    {
      tim2_callback();
    }
  }
}
