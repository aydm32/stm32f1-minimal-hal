#include "rcc.h"
#include "utils.h"

#define RCC_LOCK_TIMEOUT 100000UL

rcc_status_t rcc_init(void) {
    uint32_t timeout;

    SET_BIT(RCC->CR, BIT(16)); // HSEON
    timeout = RCC_LOCK_TIMEOUT;
    while (!READ_BIT(RCC->CR, BIT(17))) { // wait for HSE ready
        if (--timeout == 0) return RCC_ERR_HSE_TIMEOUT;
    }

    MODIFY_REG(FLASH_ACR, 0x3, 0x2);    // 2 wait states for 72 MHz

    MODIFY_REG(RCC->CFGR, (BIT(16) | (0xFUL << 18)),
               (RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLMUL9));

    SET_BIT(RCC->CR, BIT(24)); // PLLON
    timeout = RCC_LOCK_TIMEOUT;
    while (!READ_BIT(RCC->CR, BIT(25))) { // wait for PLL ready
        if (--timeout == 0) return RCC_ERR_PLL_TIMEOUT;
    }

    MODIFY_REG(RCC->CFGR, (3UL << 0), RCC_CFGR_SW_PLL);

    while (READ_BIT(RCC->CFGR, RCC_CFGR_SWS_MASK) != RCC_CFGR_SWS_PLL)
        ;

    SET_BIT(RCC->CFGR, RCC_CFGR_PPRE1_DIV2);

    return RCC_OK;
}

