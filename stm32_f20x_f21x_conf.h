#ifndef STM32F2_API_STM32_F20X_F21X_CONF_H_
#define STM32F2_API_STM32_F20X_F21X_CONF_H_

/*
 * В данном файле происходит настройка всех параметров бибилиотеки.
 */
#include <stdint.h>

/*
 * Раскомментируйте строку с выбранным вами контроллером.
 */
// #define STM32F205RB
#define STM32F205RC
// #define STM32F205RE
// #define STM32F205RF
// #define STM32F205RG
// #define STM32F205VB
// #define STM32F205VC
// #define STM32F205VE
// #define STM32F205VF
// #define STM32F205VG
// #define STM32F205ZC
// #define STM32F205ZE
// #define STM32F205ZF
// #define STM32F205ZG

// #define STM32F207IC
// #define STM32F207IE
// #define STM32F207IF
// #define STM32F207IG
// #define STM32F207VC
// #define STM32F207VE
// #define STM32F207VF
// #define STM32F207VG
// #define STM32F207ZC
// #define STM32F207ZE
// #define STM32F207ZF
// #define STM32F207ZG

// Частота внешнего кварцевого генератора (если таковой будет использован).
#define	HSE_VALUE							25000000
//******************************************************************************************************************
// Модули, которые планируется использовать в проекте.
// Для того, чтобы библиотека могла использовать модуль - раскомментируйте строчку с
// требуемым модулем.
//******************************************************************************************************************
#define MODULE_PORT
#define MODULE_RCC

//******************************************************************************************************************
//								Определения, не касающиеся основных модулей.
//******************************************************************************************************************
#define BIT_BAND_SRAM_REF   0x20000000
#define BIT_BAND_SRAM_BASE  0x22000000

//Получаем адрес бита RAM в Bit Banding области.
#define MACRO_GET_BB_P_SRAM(reg, bit) ((BIT_BAND_SRAM_BASE + (reg - BIT_BAND_SRAM_REF)*32 + (bit * 4)))

#define BIT_BAND_PER_REF   ((uint32_t)0x40000000)
#define BIT_BAND_PER_BASE  ((uint32_t)0x42000000)

// Получаем адрес бита периферии в Bit Banding области.
#define M_GET_BB_P_PER(ADDRESS,BIT) ((BIT_BAND_PER_BASE + (ADDRESS - BIT_BAND_PER_REF)*32 + (BIT * 4)))

// Преобразует число в uint32_t переменной в указатель на uint32_t (или void).
// Причем запрещает переписывать то, что по указателю (только чтение).
#define M_U32_TO_P_CONST(point)		((const uint32_t *const)(point))

// Преобразует число в uint32_t переменной в указатель на uint32_t (или void).
// Данные по указателю можно изменять.
#define M_U32_TO_P(point)				((uint32_t *)(point))

// Преобразует enum class в uint8_t.
#define M_EC_TO_U8(ENUM_VALUE)			((uint8_t)ENUM_VALUE)

//******************************************************************************************************************
//											Для модуля PORT.
//******************************************************************************************************************

/*
 * Раскомментировать данный define, если требуется в случае наличия блокировки порта пропустить повторную
 * переинициализацию.
 * Без данного define, при обнаружении флага блокировки порта, повторная переинициализация производится, т.к.,
 * возможно, пользователь хочет переинициализировать не заблокированные выводы.
 */
//#define NO_REINIT_PORT_AFTER_LOOKING

#if defined(STM32F205RB)|defined(STM32F205RC)|defined(STM32F205RE)\
	|defined(STM32F205RF)|defined(STM32F205RG)
#define PORTA
#define PORTB
#define PORTC
#define PORTD
#define PORTH
#define STM32_F2_PORT_COUNT				5
#else
	#error Не выбран микроконтроллер. Выбирете модель микрококнтроллера. Например, STM32F205RC.
#endif
#endif