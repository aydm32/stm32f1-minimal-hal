#ifndef I2C_H
#define I2C_H
#include "utils.h"
#include <stdint.h>

typedef struct {
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t OAR1;
  volatile uint32_t OAR2;
  volatile uint32_t DR;
  volatile uint32_t SR1;
  volatile uint32_t SR2;
  volatile uint32_t CCR;
  volatile uint32_t TRISE;
} I2Cx_t;

#define I2C2 (*I2Cx_t)0x40005800
#define I2C1 (*I2Cx_t)0x40005400
#define I2C_CR1_PE BIT(0)

#define I2C_CR1_PE BIT(0)

#endif // I2C_H
