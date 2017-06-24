#include "stm32_f20x_f21x_conf.h"

#ifdef MODULE_RCC

#include "stm32_f20x_f21x_rcc.h"

/*
 * Метод включет основной PLL (конфигурация должна быть заданна заранее).
 */
void rcc::pll_main_on ( void ) const {
    RCC->C |= M_EC_TO_U32(EC_CR_REG_BIT_MSK::PLLON);
}

/*
 * Метод отключает основной PLL
 * (ядро должно тактироваться от другого источника).
 */
void rcc::pll_main_off ( void ) const {
    RCC->C &= ~M_EC_TO_U32(EC_CR_REG_BIT_MSK::PLLON);
}

/*
 * Метод включает I2S PLL
 * (конфигурация должна быть заданна заранее).
 */
void rcc::pll_i2s_on ( void ) const {
    RCC->C |= M_EC_TO_U32(EC_CR_REG_BIT_MSK::PLLI2SON);
}

/*
 * Метод отключает I2S PLL.
 */
void rcc::pll_i2s_off ( void ) const {
    RCC->C &= ~M_EC_TO_U32(EC_CR_REG_BIT_MSK::PLLI2SON);
}

/*
 * Метод включает внешний источник тактового сигнала.
 */
void rcc::hse_clock_on ( void ) const {
    RCC->C |= M_EC_TO_U32(EC_CR_REG_BIT_MSK::HSEON);
}

/*
 * Метод отключает внешний источник.
 */
void rcc::hse_clock_off ( void ) const {
    RCC->C &= ~M_EC_TO_U32(EC_CR_REG_BIT_MSK::HSEON);
}

/*
 * Метод запускает внутренний источник тактового сигнала.
 */
void rcc::hsi_clock_on ( void ) const {
    RCC->C |= M_EC_TO_U32(EC_CR_REG_BIT_MSK::HSION);
}

/*
 * Метод отключает внутренний источник тактового сигнала.
 */
void rcc::hsi_clock_off ( void ) const {
    RCC->C &= ~M_EC_TO_U32(EC_CR_REG_BIT_MSK::HSION);
}

/*
 * Метод проверят, включен ли основной PLL.
 */
EC_ANSWER_PLL_STATUS rcc::pll_main_status_get ( void ) const {
    return ( *M_U32_TO_P(M_GET_BB_P_PER(static_cast< uint32_t >( RCC->C ), M_EC_TO_U8(EC_CR_REG_BIT_MSK::PLLON))) ) ? EC_ANSWER_PLL_STATUS::PLL_ON : EC_ANSWER_PLL_STATUS::PLL_OFF;
}

/*
 * Метод проверят, включен ли I2S PLL.
 */
EC_ANSWER_PLL_STATUS rcc::pll_i2s_status_get ( void ) const {
    return ( *M_U32_TO_P(M_GET_BB_P_PER(static_cast< uint32_t >( RCC->C ), M_EC_TO_U8(EC_CR_REG_BIT_MSK::PLLI2SON))) ) ? EC_ANSWER_PLL_STATUS::PLL_ON : EC_ANSWER_PLL_STATUS::PLL_OFF;
}

/*
 * Метод проверяет, заблокирован ли основной PLL.
 */
EC_ANSWER_PLL_READY_FLAG rcc::pll_main_clock_ready_flag_get ( void ) const {
    return ( *M_U32_TO_P(M_GET_BB_P_PER(static_cast< uint32_t >( RCC->C ), M_EC_TO_U8(EC_CR_REG_BIT_MSK::PLLRDY))) ) ? EC_ANSWER_PLL_READY_FLAG::PLL_LOCKED : EC_ANSWER_PLL_READY_FLAG::PLL_UNLOCKED;
}

/*
 * Метод проверяет, заблокирован ли I2S PLL.
 */
EC_ANSWER_PLL_READY_FLAG rcc::pll_i2s_clock_ready_flag_get ( void ) const {
    return ( *M_U32_TO_P(M_GET_BB_P_PER(static_cast< uint32_t >( RCC->C ), M_EC_TO_U8(EC_CR_REG_BIT_MSK::PLLI2SRDY))) ) ? EC_ANSWER_PLL_READY_FLAG::PLL_LOCKED : EC_ANSWER_PLL_READY_FLAG::PLL_UNLOCKED;
}

/*
 * Метод проверяет, включен ли внешний источник тактового сигнала или нет.
 */
EC_ANSWER_OSCILLATOR_STATUS rcc::hse_clock_status_get ( void ) const {
    return ( *M_U32_TO_P(M_GET_BB_P_PER(static_cast< uint32_t >( RCC->C ), M_EC_TO_U8(EC_CR_REG_BIT_MSK::HSEON))) ) ? EC_ANSWER_OSCILLATOR_STATUS::ON : EC_ANSWER_OSCILLATOR_STATUS::OFF;
}

/*
 * Метод проверяет, включен ли внутренний источник тактового сигнала или нет.
 */
EC_ANSWER_OSCILLATOR_STATUS rcc::hsi_clock_status_get ( void ) const {
    return ( *M_U32_TO_P(M_GET_BB_P_PER(static_cast< uint32_t >( RCC->C ), M_EC_TO_U8(EC_CR_REG_BIT_MSK::HSION))) ) ? EC_ANSWER_OSCILLATOR_STATUS::ON : EC_ANSWER_OSCILLATOR_STATUS::OFF;
}

/*
 * Метод проверяет, готов ли внешний источник тактового сигнала стать источникм тактирования.
 */
EC_ANSWER_OSCILLATOR_STATE rcc::hse_clock_ready_flag_get ( void ) const {
    return ( *M_U32_TO_P(M_GET_BB_P_PER(static_cast< uint32_t >( RCC->C ), M_EC_TO_U8(EC_CR_REG_BIT_MSK::HSERDY))) ) ? EC_ANSWER_OSCILLATOR_STATE::READY : EC_ANSWER_OSCILLATOR_STATE::NOT_READY;
}

/*
 * Метод проверяет, готов ли внутренний источник тактирования сигнала стать источникм тактирования.
 */
EC_ANSWER_OSCILLATOR_STATE rcc::hsi_clock_ready_flag_get ( void ) const {
    return ( *M_U32_TO_P(M_GET_BB_P_PER(static_cast< uint32_t >( RCC->C ), M_EC_TO_U8(EC_CR_REG_BIT_MSK::HSIRDY))) ) ? EC_ANSWER_OSCILLATOR_STATE::READY : EC_ANSWER_OSCILLATOR_STATE::NOT_READY;
}


#endif