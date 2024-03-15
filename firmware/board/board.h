/*
    ChibiOS - Copyright (C) 2006..2020 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/*
 * This file has been automatically generated using ChibiStudio board
 * generator plugin. Do not edit manually.
 */

#ifndef BOARD_H
#define BOARD_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*
 * Setup for STMicroelectronics STM32 Nucleo64-F030R8 board.
 */

/*
 * Board identifier.
 */
#define BOARD_ST_NUCLEO64_F030R8
#define BOARD_NAME                  "STMicroelectronics STM32 Nucleo64-F030R8"

/*
 * Board oscillators-related settings.
 * NOTE: LSE not fitted.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                0U
#endif

#define STM32_LSEDRV                (3U << 3U)

#if !defined(STM32_HSECLK)
#define STM32_HSECLK                8000000U
#endif

#define STM32_HSE_BYPASS

/*
 * MCU type as defined in the ST header.
 */
#define STM32F030x8

/*
 * IO pins assignments.
 */
#define ADC_BRIGHTNESS                0U
#define ADC_DEPTH                1U
#define USART2_TX_MCU                2U
#define USART2_RX_MCU                3U
#define GPIOA_ARD_A2                4U
#define GPIOA_LED_GREEN             5U
#define TIM3_CH1_LEDSTRING1               6U
#define TIM3_CH2_LEDSTRING2               7U
#define TIM1_CH1_INDICATOR_LED_BLUE                8U
#define TIM1_CH2_INDICATOR_LED_GREEN                9U
#define TIM1_CH3_INDICATOR_LED_RED                10U
#define GPIOA_PIN11                 11U
#define GPIOA_PIN12                 12U
#define GPIOA_SWDIO                 13U
#define GPIOA_SWCLK                 14U
#define GPIOA_PIN15                 15U

#define TIM3_CH3_LEDSTRING3                0U
#define TIM3_CH4_LEDSTRING4                  1U
#define GPIOB_PIN2                  2U
#define GPIOB_SWO                   3U
#define GPIOB_ARD_D3                3U
#define GPIOB_ARD_D5                4U
#define GPIOB_ARD_D4                5U
#define USART1_TX_MCU               6U
#define USART1_RX_MCU                  7U
#define I2C1_SCL               8U
#define I2C1_SDA               9U
#define BUTTON                10U
#define SPARE_3                 11U
#define SPARE_4                 12U
#define SPARE_5                 13U
#define TIM15_CH1_LEDSTRING5                 14U
#define TIM15_CH2_LEDSTRING6                 15U

#define LEDSTRING1_DRV_EN                0U
#define LEDSTRING2_DRV_EN                1U
#define VBAT_MEAS                  2U
#define ADC_FREQUENCY                  3U
#define LEDSTRING5_DRV_EN                  4U
#define LEDSTRING6_DRV_EN                  5U
#define GPIOC_PIN6                  6U
#define GPIOC_ARD_D9                7U
#define GPIOC_PIN8                  8U
#define GPIOC_PIN9                  9U
#define GPIOC_PIN10                 10U
#define GPIOC_PIN11                 11U
#define GPIOC_PIN12                 12U
#define GPIOC_BUTTON                13U
#define LEDSTRING3_DRV_EN              14U
#define LEDSTRING4_DRV_EN             15U

#define GPIOD_PIN0                  0U
#define GPIOD_PIN1                  1U
#define GPIOD_PIN2                  2U
#define GPIOD_PIN3                  3U
#define GPIOD_PIN4                  4U
#define GPIOD_PIN5                  5U
#define GPIOD_PIN6                  6U
#define GPIOD_PIN7                  7U
#define GPIOD_PIN8                  8U
#define GPIOD_PIN9                  9U
#define GPIOD_PIN10                 10U
#define GPIOD_PIN11                 11U
#define GPIOD_PIN12                 12U
#define GPIOD_PIN13                 13U
#define GPIOD_PIN14                 14U
#define GPIOD_PIN15                 15U

#define GPIOF_OSC_IN                0U
#define GPIOF_OSC_OUT               1U
#define GPIOF_PIN2                  2U
#define GPIOF_PIN3                  3U
#define GPIOF_PIN4                  4U
#define GPIOF_PIN5                  5U
#define SPARE_1                  6U
#define SPARE_2                  7U
#define GPIOF_PIN8                  8U
#define GPIOF_PIN9                  9U
#define GPIOF_PIN10                 10U
#define GPIOF_PIN11                 11U
#define GPIOF_PIN12                 12U
#define GPIOF_PIN13                 13U
#define GPIOF_PIN14                 14U
#define GPIOF_PIN15                 15U

/*
 * IO lines assignments.
 */
#define LINE_ARD_A0                 PAL_LINE(GPIOA, 0U)
#define LINE_ARD_A1                 PAL_LINE(GPIOA, 1U)
#define LINE_ARD_D1                 PAL_LINE(GPIOA, 2U)
#define LINE_USART2_TX              PAL_LINE(GPIOA, 2U)
#define LINE_ARD_D0                 PAL_LINE(GPIOA, 3U)
#define LINE_USART2_RX              PAL_LINE(GPIOA, 3U)
#define LINE_ARD_A2                 PAL_LINE(GPIOA, 4U)
#define LINE_ADC1_IN4               PAL_LINE(GPIOA, 4U)
#define LINE_LED_GREEN              PAL_LINE(GPIOA, 5U)
#define LINE_ARD_D13                PAL_LINE(GPIOA, 5U)
#define LINE_ARD_D12                PAL_LINE(GPIOA, 6U)
#define LINE_ARD_D11                PAL_LINE(GPIOA, 7U)
#define LINE_ARD_D7                 PAL_LINE(GPIOA, 8U)
#define LINE_ARD_D8                 PAL_LINE(GPIOA, 9U)
#define LINE_ARD_D2                 PAL_LINE(GPIOA, 10U)
#define LINE_SWDIO                  PAL_LINE(GPIOA, 13U)
#define LINE_SWCLK                  PAL_LINE(GPIOA, 14U)
#define LINE_ARD_A3                 PAL_LINE(GPIOB, 0U)
#define LINE_ADC1_IN8               PAL_LINE(GPIOB, 0U)
#define LINE_SWO                    PAL_LINE(GPIOB, 3U)
#define LINE_ARD_D3                 PAL_LINE(GPIOB, 3U)
#define LINE_ARD_D5                 PAL_LINE(GPIOB, 4U)
#define LINE_ARD_D4                 PAL_LINE(GPIOB, 5U)
#define LINE_ARD_D10                PAL_LINE(GPIOB, 6U)
#define LINE_ARD_D15                PAL_LINE(GPIOB, 8U)
#define LINE_ARD_D14                PAL_LINE(GPIOB, 9U)
#define LINE_ARD_D6                 PAL_LINE(GPIOB, 10U)
#define LINE_ARD_A5                 PAL_LINE(GPIOC, 0U)
#define LINE_ADC1_IN11              PAL_LINE(GPIOC, 0U)
#define LINE_ARD_A4                 PAL_LINE(GPIOC, 1U)
#define LINE_ADC1_IN10              PAL_LINE(GPIOC, 1U)
#define LINE_ARD_D9                 PAL_LINE(GPIOC, 7U)
#define LINE_BUTTON                 PAL_LINE(GPIOC, 13U)
#define LINE_OSC32_IN               PAL_LINE(GPIOC, 14U)
#define LINE_OSC32_OUT              PAL_LINE(GPIOC, 15U)
#define LINE_OSC_IN                 PAL_LINE(GPIOF, 0U)
#define LINE_OSC_OUT                PAL_LINE(GPIOF, 1U)

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2U))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2U))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2U))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2U))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_VERYLOW(n)       (0U << ((n) * 2U))
#define PIN_OSPEED_LOW(n)           (1U << ((n) * 2U))
#define PIN_OSPEED_MEDIUM(n)        (2U << ((n) * 2U))
#define PIN_OSPEED_HIGH(n)          (3U << ((n) * 2U))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2U))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2U))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2U))
#define PIN_AFIO_AF(n, v)           ((v) << (((n) % 8U) * 4U))

/*
 * GPIOA setup:
 *
 * PA0  - ARD_A0 ADC1_IN0           (input pullup).
 * PA1  - ARD_A1 ADC1_IN1           (input pullup).
 * PA2  - ARD_D1 USART2_TX          (alternate 1).
 * PA3  - ARD_D0 USART2_RX          (alternate 1).
 * PA4  - ARD_A2 ADC1_IN4           (input pullup).
 * PA5  - LED_GREEN ARD_D13         (output pushpull high).
 * PA6  - ARD_D12                   (input pullup).
 * PA7  - ARD_D11                   (input pullup).
 * PA8  - ARD_D7                    (input pullup).
 * PA9  - ARD_D8                    (input pullup).
 * PA10 - ARD_D2                    (input pullup).
 * PA11 - PIN11                     (input pullup).
 * PA12 - PIN12                     (input pullup).
 * PA13 - SWDIO                     (alternate 0).
 * PA14 - SWCLK                     (alternate 0).
 * PA15 - PIN15                     (input pullup).
 */
#define VAL_GPIOA_MODER             (PIN_MODE_ANALOG(ADC_BRIGHTNESS) |         \
                                     PIN_MODE_ANALOG(ADC_DEPTH) |         \
                                     PIN_MODE_ALTERNATE(USART2_TX_MCU) |     \
                                     PIN_MODE_ALTERNATE(USART2_RX_MCU) |     \
                                     PIN_MODE_INPUT(GPIOA_ARD_A2) |         \
                                     PIN_MODE_OUTPUT(GPIOA_LED_GREEN) |     \
                                     PIN_MODE_ALTERNATE(TIM3_CH1_LEDSTRING1) |        \
                                     PIN_MODE_ALTERNATE(TIM3_CH2_LEDSTRING2) |        \
                                     PIN_MODE_ALTERNATE(TIM1_CH1_INDICATOR_LED_BLUE) |         \
                                     PIN_MODE_ALTERNATE(TIM1_CH2_INDICATOR_LED_GREEN) |         \
                                     PIN_MODE_ALTERNATE(TIM1_CH3_INDICATOR_LED_RED) |         \
                                     PIN_MODE_ALTERNATE(GPIOA_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOA_PIN12) |          \
                                     PIN_MODE_ALTERNATE(GPIOA_SWDIO) |      \
                                     PIN_MODE_ALTERNATE(GPIOA_SWCLK) |      \
                                     PIN_MODE_INPUT(GPIOA_PIN15))
#define VAL_GPIOA_OTYPER            (PIN_OTYPE_PUSHPULL(ADC_BRIGHTNESS) |     \
                                     PIN_OTYPE_PUSHPULL(ADC_DEPTH) |     \
                                     PIN_OTYPE_PUSHPULL(USART2_TX_MCU) |     \
                                     PIN_OTYPE_PUSHPULL(USART2_RX_MCU) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_ARD_A2) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_LED_GREEN) |  \
                                     PIN_OTYPE_PUSHPULL(TIM3_CH1_LEDSTRING1) |    \
                                     PIN_OTYPE_PUSHPULL(TIM3_CH2_LEDSTRING2) |    \
                                     PIN_OTYPE_PUSHPULL(TIM1_CH1_INDICATOR_LED_BLUE) |     \
                                     PIN_OTYPE_PUSHPULL(TIM1_CH2_INDICATOR_LED_GREEN) |     \
                                     PIN_OTYPE_PUSHPULL(TIM1_CH3_INDICATOR_LED_RED) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWDIO) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWCLK) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN15))
#define VAL_GPIOA_OSPEEDR           (PIN_OSPEED_HIGH(ADC_BRIGHTNESS) |        \
                                     PIN_OSPEED_HIGH(ADC_DEPTH) |        \
                                     PIN_OSPEED_LOW(USART2_TX_MCU) |         \
                                     PIN_OSPEED_LOW(USART2_RX_MCU) |         \
                                     PIN_OSPEED_HIGH(GPIOA_ARD_A2) |        \
                                     PIN_OSPEED_LOW(GPIOA_LED_GREEN) |      \
                                     PIN_OSPEED_HIGH(TIM3_CH1_LEDSTRING1) |       \
                                     PIN_OSPEED_HIGH(TIM3_CH2_LEDSTRING2) |       \
                                     PIN_OSPEED_HIGH(TIM1_CH1_INDICATOR_LED_BLUE) |        \
                                     PIN_OSPEED_HIGH(TIM1_CH2_INDICATOR_LED_GREEN) |        \
                                     PIN_OSPEED_HIGH(TIM1_CH3_INDICATOR_LED_RED) |        \
                                     PIN_OSPEED_HIGH(GPIOA_PIN11) |         \
                                     PIN_OSPEED_HIGH(GPIOA_PIN12) |         \
                                     PIN_OSPEED_HIGH(GPIOA_SWDIO) |         \
                                     PIN_OSPEED_HIGH(GPIOA_SWCLK) |         \
                                     PIN_OSPEED_HIGH(GPIOA_PIN15))
#define VAL_GPIOA_PUPDR             (PIN_PUPDR_PULLUP(ADC_BRIGHTNESS) |       \
                                     PIN_PUPDR_PULLUP(ADC_DEPTH) |       \
                                     PIN_PUPDR_FLOATING(USART2_TX_MCU) |     \
                                     PIN_PUPDR_FLOATING(USART2_RX_MCU) |     \
                                     PIN_PUPDR_PULLUP(GPIOA_ARD_A2) |       \
                                     PIN_PUPDR_FLOATING(GPIOA_LED_GREEN) |  \
                                     PIN_PUPDR_PULLUP(TIM3_CH1_LEDSTRING1) |      \
                                     PIN_PUPDR_PULLUP(TIM3_CH2_LEDSTRING2) |      \
                                     PIN_PUPDR_PULLUP(TIM1_CH1_INDICATOR_LED_BLUE) |       \
                                     PIN_PUPDR_PULLUP(TIM1_CH2_INDICATOR_LED_GREEN) |       \
                                     PIN_PUPDR_PULLUP(TIM1_CH3_INDICATOR_LED_RED) |       \
                                     PIN_PUPDR_PULLUP(GPIOA_PIN11) |        \
                                     PIN_PUPDR_PULLUP(GPIOA_PIN12) |        \
                                     PIN_PUPDR_PULLUP(GPIOA_SWDIO) |        \
                                     PIN_PUPDR_PULLDOWN(GPIOA_SWCLK) |      \
                                     PIN_PUPDR_PULLUP(GPIOA_PIN15))
#define VAL_GPIOA_ODR               (PIN_ODR_HIGH(ADC_BRIGHTNESS) |           \
                                     PIN_ODR_HIGH(ADC_DEPTH) |           \
                                     PIN_ODR_HIGH(USART2_TX_MCU) |           \
                                     PIN_ODR_HIGH(USART2_RX_MCU) |           \
                                     PIN_ODR_HIGH(GPIOA_ARD_A2) |           \
                                     PIN_ODR_LOW(GPIOA_LED_GREEN) |         \
                                     PIN_ODR_HIGH(TIM3_CH1_LEDSTRING1) |          \
                                     PIN_ODR_HIGH(TIM3_CH2_LEDSTRING2) |          \
                                     PIN_ODR_HIGH(TIM1_CH1_INDICATOR_LED_BLUE) |           \
                                     PIN_ODR_HIGH(TIM1_CH2_INDICATOR_LED_GREEN) |           \
                                     PIN_ODR_HIGH(TIM1_CH3_INDICATOR_LED_RED) |           \
                                     PIN_ODR_HIGH(GPIOA_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOA_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOA_SWDIO) |            \
                                     PIN_ODR_HIGH(GPIOA_SWCLK) |            \
                                     PIN_ODR_HIGH(GPIOA_PIN15))
#define VAL_GPIOA_AFRL              (PIN_AFIO_AF(ADC_BRIGHTNESS, 0U) |        \
                                     PIN_AFIO_AF(ADC_DEPTH, 0U) |        \
                                     PIN_AFIO_AF(USART2_TX_MCU, 1U) |        \
                                     PIN_AFIO_AF(USART2_RX_MCU, 1U) |        \
                                     PIN_AFIO_AF(GPIOA_ARD_A2, 0U) |        \
                                     PIN_AFIO_AF(GPIOA_LED_GREEN, 0U) |     \
                                     PIN_AFIO_AF(TIM3_CH1_LEDSTRING1, 1U) |       \
                                     PIN_AFIO_AF(TIM3_CH2_LEDSTRING2, 1U))
#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(TIM1_CH1_INDICATOR_LED_BLUE, 2U) |        \
                                     PIN_AFIO_AF(TIM1_CH2_INDICATOR_LED_GREEN, 2U) |        \
                                     PIN_AFIO_AF(TIM1_CH3_INDICATOR_LED_RED, 2U) |        \
                                     PIN_AFIO_AF(GPIOA_PIN11, 2U) |         \
                                     PIN_AFIO_AF(GPIOA_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOA_SWDIO, 0U) |         \
                                     PIN_AFIO_AF(GPIOA_SWCLK, 0U) |         \
                                     PIN_AFIO_AF(GPIOA_PIN15, 0U))

/*
 * GPIOB setup:
 *
 * PB0  - ARD_A3 ADC1_IN8           (input pullup).
 * PB1  - PIN1                      (input pullup).
 * PB2  - PIN2                      (input pullup).
 * PB3  - SWO ARD_D3                (alternate 0).
 * PB4  - ARD_D5                    (input pullup).
 * PB5  - ARD_D4                    (input pullup).
 * PB6  - ARD_D10                   (input pullup).
 * PB7  - PIN7                      (input pullup).
 * PB8  - ARD_D15                   (input pullup).
 * PB9  - ARD_D14                   (input pullup).
 * PB10 - ARD_D6                    (input pullup).
 * PB11 - PIN11                     (input pullup).
 * PB12 - PIN12                     (input pullup).
 * PB13 - PIN13                     (input pullup).
 * PB14 - PIN14                     (input pullup).
 * PB15 - PIN15                     (input pullup).
 */
#define VAL_GPIOB_MODER             (PIN_MODE_ALTERNATE(TIM3_CH3_LEDSTRING3) |         \
                                     PIN_MODE_ALTERNATE(TIM3_CH4_LEDSTRING4) |           \
                                     PIN_MODE_INPUT(GPIOB_PIN2) |           \
                                     PIN_MODE_ALTERNATE(GPIOB_SWO) |        \
                                     PIN_MODE_INPUT(GPIOB_ARD_D5) |         \
                                     PIN_MODE_INPUT(GPIOB_ARD_D4) |         \
                                     PIN_MODE_ALTERNATE(USART1_TX_MCU) |        \
                                     PIN_MODE_ALTERNATE(USART1_RX_MCU) |           \
                                     PIN_MODE_ALTERNATE(I2C1_SCL) |        \
                                     PIN_MODE_ALTERNATE(I2C1_SDA) |        \
                                     PIN_MODE_INPUT(BUTTON) |         \
                                     PIN_MODE_INPUT(SPARE_3) |          \
                                     PIN_MODE_INPUT(SPARE_4) |          \
                                     PIN_MODE_INPUT(SPARE_5) |          \
                                     PIN_MODE_ALTERNATE(TIM15_CH1_LEDSTRING5) |          \
                                     PIN_MODE_ALTERNATE(TIM15_CH2_LEDSTRING6))
#define VAL_GPIOB_OTYPER            (PIN_OTYPE_PUSHPULL(TIM3_CH3_LEDSTRING3) |     \
                                     PIN_OTYPE_PUSHPULL(TIM3_CH4_LEDSTRING4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_SWO) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_ARD_D5) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOB_ARD_D4) |     \
                                     PIN_OTYPE_PUSHPULL(USART1_TX_MCU) |    \
                                     PIN_OTYPE_PUSHPULL(USART1_RX_MCU) |       \
                                     PIN_OTYPE_PUSHPULL(I2C1_SCL) |    \
                                     PIN_OTYPE_PUSHPULL(I2C1_SDA) |    \
                                     PIN_OTYPE_PUSHPULL(BUTTON) |     \
                                     PIN_OTYPE_PUSHPULL(SPARE_3) |      \
                                     PIN_OTYPE_PUSHPULL(SPARE_4) |      \
                                     PIN_OTYPE_PUSHPULL(SPARE_5) |      \
                                     PIN_OTYPE_PUSHPULL(TIM15_CH1_LEDSTRING5) |      \
                                     PIN_OTYPE_PUSHPULL(TIM15_CH2_LEDSTRING6))
#define VAL_GPIOB_OSPEEDR           (PIN_OSPEED_HIGH(TIM3_CH3_LEDSTRING3) |        \
                                     PIN_OSPEED_HIGH(TIM3_CH4_LEDSTRING4) |          \
                                     PIN_OSPEED_HIGH(GPIOB_PIN2) |          \
                                     PIN_OSPEED_HIGH(GPIOB_SWO) |           \
                                     PIN_OSPEED_HIGH(GPIOB_ARD_D5) |        \
                                     PIN_OSPEED_HIGH(GPIOB_ARD_D4) |        \
                                     PIN_OSPEED_HIGH(USART1_TX_MCU) |       \
                                     PIN_OSPEED_HIGH(USART1_RX_MCU) |          \
                                     PIN_OSPEED_HIGH(I2C1_SCL) |       \
                                     PIN_OSPEED_HIGH(I2C1_SDA) |       \
                                     PIN_OSPEED_HIGH(BUTTON) |        \
                                     PIN_OSPEED_HIGH(SPARE_3) |         \
                                     PIN_OSPEED_HIGH(SPARE_4) |         \
                                     PIN_OSPEED_HIGH(SPARE_5) |         \
                                     PIN_OSPEED_HIGH(TIM15_CH1_LEDSTRING5) |         \
                                     PIN_OSPEED_HIGH(TIM15_CH2_LEDSTRING6))
#define VAL_GPIOB_PUPDR             (PIN_PUPDR_PULLUP(TIM3_CH3_LEDSTRING3) |       \
                                     PIN_PUPDR_PULLUP(TIM3_CH4_LEDSTRING4) |         \
                                     PIN_PUPDR_PULLUP(GPIOB_PIN2) |         \
                                     PIN_PUPDR_PULLUP(GPIOB_SWO) |          \
                                     PIN_PUPDR_PULLUP(GPIOB_ARD_D5) |       \
                                     PIN_PUPDR_PULLUP(GPIOB_ARD_D4) |       \
                                     PIN_PUPDR_PULLUP(USART1_TX_MCU) |      \
                                     PIN_PUPDR_PULLUP(USART1_RX_MCU) |         \
                                     PIN_PUPDR_PULLUP(I2C1_SCL) |      \
                                     PIN_PUPDR_PULLUP(I2C1_SDA) |      \
                                     PIN_PUPDR_PULLUP(BUTTON) |       \
                                     PIN_PUPDR_PULLUP(SPARE_3) |        \
                                     PIN_PUPDR_PULLUP(SPARE_4) |        \
                                     PIN_PUPDR_PULLUP(SPARE_5) |        \
                                     PIN_PUPDR_PULLUP(TIM15_CH1_LEDSTRING5) |        \
                                     PIN_PUPDR_PULLUP(TIM15_CH2_LEDSTRING6))
#define VAL_GPIOB_ODR               (PIN_ODR_HIGH(TIM3_CH3_LEDSTRING3) |           \
                                     PIN_ODR_HIGH(TIM3_CH4_LEDSTRING4) |             \
                                     PIN_ODR_HIGH(GPIOB_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOB_SWO) |              \
                                     PIN_ODR_HIGH(GPIOB_ARD_D5) |           \
                                     PIN_ODR_HIGH(GPIOB_ARD_D4) |           \
                                     PIN_ODR_HIGH(USART1_TX_MCU) |          \
                                     PIN_ODR_HIGH(USART1_RX_MCU) |             \
                                     PIN_ODR_HIGH(I2C1_SCL) |          \
                                     PIN_ODR_HIGH(I2C1_SDA) |          \
                                     PIN_ODR_HIGH(BUTTON) |           \
                                     PIN_ODR_HIGH(SPARE_3) |            \
                                     PIN_ODR_HIGH(SPARE_4) |            \
                                     PIN_ODR_HIGH(SPARE_5) |            \
                                     PIN_ODR_HIGH(TIM15_CH1_LEDSTRING5) |            \
                                     PIN_ODR_HIGH(TIM15_CH2_LEDSTRING6))
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(TIM3_CH3_LEDSTRING3, 1U) |        \
                                     PIN_AFIO_AF(TIM3_CH4_LEDSTRING4, 1U) |          \
                                     PIN_AFIO_AF(GPIOB_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOB_SWO, 0U) |           \
                                     PIN_AFIO_AF(GPIOB_ARD_D5, 0U) |        \
                                     PIN_AFIO_AF(GPIOB_ARD_D4, 0U) |        \
                                     PIN_AFIO_AF(USART1_TX_MCU, 0U) |       \
                                     PIN_AFIO_AF(USART1_RX_MCU, 0U))
#define VAL_GPIOB_AFRH              (PIN_AFIO_AF(I2C1_SCL, 1U) |       \
                                     PIN_AFIO_AF(I2C1_SDA, 1U) |       \
                                     PIN_AFIO_AF(BUTTON, 0U) |        \
                                     PIN_AFIO_AF(SPARE_3, 0U) |         \
                                     PIN_AFIO_AF(SPARE_4, 0U) |         \
                                     PIN_AFIO_AF(SPARE_5, 0U) |         \
                                     PIN_AFIO_AF(TIM15_CH1_LEDSTRING5, 1U) |         \
                                     PIN_AFIO_AF(TIM15_CH2_LEDSTRING6, 1U))

/*
 * GPIOC setup:
 *
 * PC0  - ARD_A5 ADC1_IN11          (input pullup).
 * PC1  - ARD_A4 ADC1_IN10          (input pullup).
 * PC2  - PIN2                      (input pullup).
 * PC3  - PIN3                      (input pullup).
 * PC4  - PIN4                      (input pullup).
 * PC5  - PIN5                      (input pullup).
 * PC6  - PIN6                      (input pullup).
 * PC7  - ARD_D9                    (input pullup).
 * PC8  - PIN8                      (input pullup).
 * PC9  - PIN9                      (input pullup).
 * PC10 - PIN10                     (input pullup).
 * PC11 - PIN11                     (input pullup).
 * PC12 - PIN12                     (input pullup).
 * PC13 - BUTTON                    (input floating).
 * PC14 - OSC32_IN                  (input floating).
 * PC15 - OSC32_OUT                 (input floating).
 */
#define VAL_GPIOC_MODER             (PIN_MODE_OUTPUT(LEDSTRING1_DRV_EN) |         \
                                     PIN_MODE_OUTPUT(LEDSTRING2_DRV_EN) |         \
                                     PIN_MODE_ANALOG(VBAT_MEAS) |           \
                                     PIN_MODE_ANALOG(ADC_FREQUENCY) |           \
                                     PIN_MODE_OUTPUT(LEDSTRING5_DRV_EN) |           \
                                     PIN_MODE_OUTPUT(LEDSTRING6_DRV_EN) |           \
                                     PIN_MODE_INPUT(GPIOC_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOC_ARD_D9) |         \
                                     PIN_MODE_INPUT(GPIOC_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOC_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOC_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOC_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOC_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOC_BUTTON) |         \
                                     PIN_MODE_OUTPUT(LEDSTRING3_DRV_EN) |       \
                                     PIN_MODE_OUTPUT(LEDSTRING4_DRV_EN))
#define VAL_GPIOC_OTYPER            (PIN_OTYPE_PUSHPULL(LEDSTRING1_DRV_EN) |     \
                                     PIN_OTYPE_PUSHPULL(LEDSTRING2_DRV_EN) |     \
                                     PIN_OTYPE_PUSHPULL(VBAT_MEAS) |       \
                                     PIN_OTYPE_PUSHPULL(ADC_FREQUENCY) |       \
                                     PIN_OTYPE_PUSHPULL(LEDSTRING5_DRV_EN) |       \
                                     PIN_OTYPE_PUSHPULL(LEDSTRING6_DRV_EN) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_ARD_D9) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOC_BUTTON) |     \
                                     PIN_OTYPE_PUSHPULL(LEDSTRING3_DRV_EN) |   \
                                     PIN_OTYPE_PUSHPULL(LEDSTRING4_DRV_EN))
#define VAL_GPIOC_OSPEEDR           (PIN_OSPEED_HIGH(LEDSTRING1_DRV_EN) |        \
                                     PIN_OSPEED_HIGH(LEDSTRING2_DRV_EN) |        \
                                     PIN_OSPEED_HIGH(VBAT_MEAS) |          \
                                     PIN_OSPEED_HIGH(ADC_FREQUENCY) |          \
                                     PIN_OSPEED_HIGH(LEDSTRING5_DRV_EN) |          \
                                     PIN_OSPEED_HIGH(LEDSTRING6_DRV_EN) |          \
                                     PIN_OSPEED_HIGH(GPIOC_PIN6) |          \
                                     PIN_OSPEED_HIGH(GPIOC_ARD_D9) |        \
                                     PIN_OSPEED_HIGH(GPIOC_PIN8) |          \
                                     PIN_OSPEED_HIGH(GPIOC_PIN9) |          \
                                     PIN_OSPEED_HIGH(GPIOC_PIN10) |         \
                                     PIN_OSPEED_HIGH(GPIOC_PIN11) |         \
                                     PIN_OSPEED_HIGH(GPIOC_PIN12) |         \
                                     PIN_OSPEED_HIGH(GPIOC_BUTTON) |        \
                                     PIN_OSPEED_HIGH(LEDSTRING3_DRV_EN) |      \
                                     PIN_OSPEED_HIGH(LEDSTRING4_DRV_EN))
#define VAL_GPIOC_PUPDR             (PIN_PUPDR_PULLUP(LEDSTRING1_DRV_EN) |       \
                                     PIN_PUPDR_PULLUP(LEDSTRING2_DRV_EN) |       \
                                     PIN_PUPDR_PULLUP(VBAT_MEAS) |         \
                                     PIN_PUPDR_PULLUP(ADC_FREQUENCY) |         \
                                     PIN_PUPDR_PULLUP(LEDSTRING5_DRV_EN) |         \
                                     PIN_PUPDR_PULLUP(LEDSTRING6_DRV_EN) |         \
                                     PIN_PUPDR_PULLUP(GPIOC_PIN6) |         \
                                     PIN_PUPDR_PULLUP(GPIOC_ARD_D9) |       \
                                     PIN_PUPDR_PULLUP(GPIOC_PIN8) |         \
                                     PIN_PUPDR_PULLUP(GPIOC_PIN9) |         \
                                     PIN_PUPDR_PULLUP(GPIOC_PIN10) |        \
                                     PIN_PUPDR_PULLUP(GPIOC_PIN11) |        \
                                     PIN_PUPDR_PULLUP(GPIOC_PIN12) |        \
                                     PIN_PUPDR_FLOATING(GPIOC_BUTTON) |     \
                                     PIN_PUPDR_FLOATING(LEDSTRING3_DRV_EN) |   \
                                     PIN_PUPDR_FLOATING(LEDSTRING4_DRV_EN))
#define VAL_GPIOC_ODR               (PIN_ODR_HIGH(LEDSTRING1_DRV_EN) |           \
                                     PIN_ODR_HIGH(LEDSTRING2_DRV_EN) |           \
                                     PIN_ODR_HIGH(VBAT_MEAS) |             \
                                     PIN_ODR_HIGH(ADC_FREQUENCY) |             \
                                     PIN_ODR_HIGH(LEDSTRING5_DRV_EN) |             \
                                     PIN_ODR_HIGH(LEDSTRING6_DRV_EN) |             \
                                     PIN_ODR_HIGH(GPIOC_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOC_ARD_D9) |           \
                                     PIN_ODR_HIGH(GPIOC_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOC_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOC_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOC_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOC_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOC_BUTTON) |           \
                                     PIN_ODR_HIGH(LEDSTRING3_DRV_EN) |         \
                                     PIN_ODR_HIGH(LEDSTRING4_DRV_EN))
#define VAL_GPIOC_AFRL              (PIN_AFIO_AF(LEDSTRING1_DRV_EN, 0U) |        \
                                     PIN_AFIO_AF(LEDSTRING2_DRV_EN, 0U) |        \
                                     PIN_AFIO_AF(VBAT_MEAS, 0U) |          \
                                     PIN_AFIO_AF(ADC_FREQUENCY, 0U) |          \
                                     PIN_AFIO_AF(LEDSTRING5_DRV_EN, 0U) |          \
                                     PIN_AFIO_AF(LEDSTRING6_DRV_EN, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_ARD_D9, 0U))
#define VAL_GPIOC_AFRH              (PIN_AFIO_AF(GPIOC_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOC_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOC_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOC_BUTTON, 0U) |        \
                                     PIN_AFIO_AF(LEDSTRING3_DRV_EN, 0U) |      \
                                     PIN_AFIO_AF(LEDSTRING4_DRV_EN, 0U))

/*
 * GPIOD setup:
 *
 * PD0  - PIN0                      (input pullup).
 * PD1  - PIN1                      (input pullup).
 * PD2  - PIN2                      (input pullup).
 * PD3  - PIN3                      (input pullup).
 * PD4  - PIN4                      (input pullup).
 * PD5  - PIN5                      (input pullup).
 * PD6  - PIN6                      (input pullup).
 * PD7  - PIN7                      (input pullup).
 * PD8  - PIN8                      (input pullup).
 * PD9  - PIN9                      (input pullup).
 * PD10 - PIN10                     (input pullup).
 * PD11 - PIN11                     (input pullup).
 * PD12 - PIN12                     (input pullup).
 * PD13 - PIN13                     (input pullup).
 * PD14 - PIN14                     (input pullup).
 * PD15 - PIN15                     (input pullup).
 */
#define VAL_GPIOD_MODER             (PIN_MODE_INPUT(GPIOD_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN15))
#define VAL_GPIOD_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOD_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN15))
#define VAL_GPIOD_OSPEEDR           (PIN_OSPEED_HIGH(GPIOD_PIN0) |          \
                                     PIN_OSPEED_HIGH(GPIOD_PIN1) |          \
                                     PIN_OSPEED_HIGH(GPIOD_PIN2) |          \
                                     PIN_OSPEED_HIGH(GPIOD_PIN3) |          \
                                     PIN_OSPEED_HIGH(GPIOD_PIN4) |          \
                                     PIN_OSPEED_HIGH(GPIOD_PIN5) |          \
                                     PIN_OSPEED_HIGH(GPIOD_PIN6) |          \
                                     PIN_OSPEED_HIGH(GPIOD_PIN7) |          \
                                     PIN_OSPEED_HIGH(GPIOD_PIN8) |          \
                                     PIN_OSPEED_HIGH(GPIOD_PIN9) |          \
                                     PIN_OSPEED_HIGH(GPIOD_PIN10) |         \
                                     PIN_OSPEED_HIGH(GPIOD_PIN11) |         \
                                     PIN_OSPEED_HIGH(GPIOD_PIN12) |         \
                                     PIN_OSPEED_HIGH(GPIOD_PIN13) |         \
                                     PIN_OSPEED_HIGH(GPIOD_PIN14) |         \
                                     PIN_OSPEED_HIGH(GPIOD_PIN15))
#define VAL_GPIOD_PUPDR             (PIN_PUPDR_PULLUP(GPIOD_PIN0) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN1) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN2) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN3) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN4) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN5) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN6) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN7) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN8) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN9) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN10) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN11) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN12) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN13) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN14) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN15))
#define VAL_GPIOD_ODR               (PIN_ODR_HIGH(GPIOD_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN15))
#define VAL_GPIOD_AFRL              (PIN_AFIO_AF(GPIOD_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN7, 0U))
#define VAL_GPIOD_AFRH              (PIN_AFIO_AF(GPIOD_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN15, 0U))

/*
 * GPIOF setup:
 *
 * PF0  - OSC_IN                    (input floating).
 * PF1  - OSC_OUT                   (input floating).
 * PF2  - PIN2                      (input pullup).
 * PF3  - PIN3                      (input pullup).
 * PF4  - PIN4                      (input pullup).
 * PF5  - PIN5                      (input pullup).
 * PF6  - PIN6                      (input pullup).
 * PF7  - PIN7                      (input pullup).
 * PF8  - PIN8                      (input pullup).
 * PF9  - PIN9                      (input pullup).
 * PF10 - PIN10                     (input pullup).
 * PF11 - PIN11                     (input pullup).
 * PF12 - PIN12                     (input pullup).
 * PF13 - PIN13                     (input pullup).
 * PF14 - PIN14                     (input pullup).
 * PF15 - PIN15                     (input pullup).
 */
#define VAL_GPIOF_MODER             (PIN_MODE_INPUT(GPIOF_OSC_IN) |         \
                                     PIN_MODE_INPUT(GPIOF_OSC_OUT) |        \
                                     PIN_MODE_INPUT(GPIOF_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN5) |           \
                                     PIN_MODE_INPUT(SPARE_1) |           \
                                     PIN_MODE_INPUT(SPARE_2) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN15))
#define VAL_GPIOF_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOF_OSC_IN) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOF_OSC_OUT) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(SPARE_1) |       \
                                     PIN_OTYPE_PUSHPULL(SPARE_2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN15))
#define VAL_GPIOF_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOF_OSC_IN) |     \
                                     PIN_OSPEED_VERYLOW(GPIOF_OSC_OUT) |    \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN3) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN4) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN5) |       \
                                     PIN_OSPEED_VERYLOW(SPARE_1) |       \
                                     PIN_OSPEED_VERYLOW(SPARE_2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN8) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN9) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN10) |      \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN11) |      \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN12) |      \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN13) |      \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN14) |      \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN15))
#define VAL_GPIOF_PUPDR             (PIN_PUPDR_FLOATING(GPIOF_OSC_IN) |     \
                                     PIN_PUPDR_FLOATING(GPIOF_OSC_OUT) |    \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN2) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN3) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN4) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN5) |         \
                                     PIN_PUPDR_PULLUP(SPARE_1) |         \
                                     PIN_PUPDR_PULLUP(SPARE_2) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN8) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN9) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN10) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN11) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN12) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN13) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN14) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN15))
#define VAL_GPIOF_ODR               (PIN_ODR_HIGH(GPIOF_OSC_IN) |           \
                                     PIN_ODR_HIGH(GPIOF_OSC_OUT) |          \
                                     PIN_ODR_HIGH(GPIOF_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN5) |             \
                                     PIN_ODR_HIGH(SPARE_1) |             \
                                     PIN_ODR_HIGH(SPARE_2) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN15))
#define VAL_GPIOF_AFRL              (PIN_AFIO_AF(GPIOF_OSC_IN, 0U) |        \
                                     PIN_AFIO_AF(GPIOF_OSC_OUT, 0U) |       \
                                     PIN_AFIO_AF(GPIOF_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN5, 0U) |          \
                                     PIN_AFIO_AF(SPARE_1, 0U) |          \
                                     PIN_AFIO_AF(SPARE_2, 0U))
#define VAL_GPIOF_AFRH              (PIN_AFIO_AF(GPIOF_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN15, 0U))

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* BOARD_H */
