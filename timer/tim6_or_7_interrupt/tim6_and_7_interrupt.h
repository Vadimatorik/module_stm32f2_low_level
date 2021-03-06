#pragma once

#include "f2_api_conf.h"

#ifdef MODULE_TIMER

#include "mc_hardware_interfaces_timer.h"
#include "tim_6_and_7_struct.h"

//
// Генератор прерываний.
//
template < TIM6_OR_TIM7        P_TIM,                   // Используемый таймер.
           uint16_t            PRESCALER,               // Предделитель 1..0x10000.
           uint16_t            PERIOD_TOGGLE >          // Еще 1 делитель 1..0x10000.
class tim6_and_7_interrupt : public tim_interrupt_base {
public:
    tim6_and_7_interrupt ();
    void reinit                 ( void ) const;
    void clear_interrupt_flag   ( void ) const;         // Вызывать по входу в прерывание.
    void on                     ( void ) const;
    void off                    ( void ) const;

    // Специфичные функции.
    void period_dev             ( uint32_t dev ) const;     // Уменьшить период в dev раз.
    void period_reset           ( void )         const;     // Вернуть как было.

private:
    tim_6_and_7_registers_struct*            const tim;
    const tim_6_and_7_registers_struct       cfg;
};

#include "tim6_and_7_interrupt_func.h"

#endif
