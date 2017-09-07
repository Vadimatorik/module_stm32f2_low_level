#pragma once

#include "stm32_f20x_f21x_conf.h"

#ifdef MODULE_RCC

#include "rcc.h"
#include "stm32_f20x_f21x_port.h"
#include <cmath>

/**********************************************************************
 * Область constexpr конструкторов.
 **********************************************************************/

constexpr rcc::rcc( const rcc_cfg* const cfg ):
    cfg( cfg ) {};

#endif