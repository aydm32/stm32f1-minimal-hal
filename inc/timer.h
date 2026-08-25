#ifndef TIMER_H
#define TIMER_H
#include <stdint.h>

typedef struct {
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMCR;
  volatile uint32_t DIER;
  volatile uint32_t SR;
  volatile uint32_t EGR;
  volatile uint32_t CCMR1;
  volatile uint32_t CCMR2;
  volatile uint32_t CCER;
  volatile uint32_t CNT;
  volatile uint32_t PSC;
  volatile uint32_t ARR;
  uint32_t RESV1;
  volatile uint32_t CCR1;
  volatile uint32_t CCR2;
  volatile uint32_t CCR3;
  volatile uint32_t CCR4;
  uint32_t RESV2;
  volatile uint32_t DCR;
  volatile uint32_t DMAR;
} TIMx_t;

#define TIM1 ((TIMx_t *)0x40012C00)
#define TIM2 ((TIMx_t *)0x40000000)
#define TIM3 ((TIMx_t *)0x40000400)
#define TIM4 ((TIMx_t *)0x40000800)

#define CR1_CEN BIT(0) // Counter enable

#define EGR_UG BIT(0) // Update generation

#define SR_UIF BIT(0) // Update interrupt flag

#define DIER_UIE BIT(0) // Update interrupt enable

typedef void (*timer_callback_t)(void);

typedef struct {
  uint16_t prescaler;
  uint16_t period;
} timer_config;

void timer_init(TIMx_t *, timer_config);
void timer_start(TIMx_t *);
void timer_stop(TIMx_t *);

void timer_set_callback(TIMx_t *, timer_callback_t);
void timer_enable_interrupt(TIMx_t *);
void timer_disable_interrupt(TIMx_t *);

#endif // !TIMER_H
