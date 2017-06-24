#pragma once

#include "stm32_f20x_f21x_conf.h"

#ifdef MODULE_RCC

/**********************************************************************
 * Область упакованных структур.
 **********************************************************************/

/*
 * Перечень регистров физического порта ввода-вывода.
 */
struct __attribute__( ( packed ) ) pll_cfg_struct {
    const uint32_t  pllcfg_reg_msk;
    const uint32_t  dev_bus_msk;
};

#endif
