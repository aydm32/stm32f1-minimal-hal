#ifndef GPIO_H
#define GPIO_H
#include <stdint.h>

// Registers definition
typedef struct {
  volatile uint32_t CRL;
  volatile uint32_t CRH;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t BRR;
  volatile uint32_t LCKR;
} GPIOx_t;

#define GPIO(bank) ((GPIOx_t *)(0x40010800UL + 0x400UL * (bank)))

// CNF bits [3:2] input modes (when MODE=00)
#define GPIO_CNF_IN_ANALOG 0x0
#define GPIO_CNF_IN_FLOAT 0x1
#define GPIO_CNF_IN_PULLUPDN 0x2

// CNF bits [3:2] output modes (when MODE != 00)
#define GPIO_CNF_OUT_PP 0x0
#define GPIO_CNF_OUT_OD 0x1
#define GPIO_CNF_OUT_AFPP 0x2
#define GPIO_CNF_OUT_AFOD 0x3

// MODE bits [1:0]
#define GPIO_MODE_INPUT 0x0
#define GPIO_MODE_OUT_10MHZ 0x1
#define GPIO_MODE_OUT_2MHZ 0x2
#define GPIO_MODE_OUT_50MHZ 0x3

void gpio_set_mode(uint32_t pin, uint8_t cnf, uint8_t mode);
void gpio_set(uint32_t pin, uint8_t state);
uint8_t gpio_read(uint32_t pin);
void gpio_toggle(uint32_t pin);

#endif // !GPIO_H
