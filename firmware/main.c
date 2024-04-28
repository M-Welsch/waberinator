/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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

#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "serial_interface.h"
#include "waber_thread.h"
#include "led_string.h"
#include "adc.h"
#include "modem.h"
#include "smps.h"

/*
 * Green LED blinker thread, times are in milliseconds.
 */
static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg) {

  (void)arg;
  chRegSetThreadName("blinker");
  while (true) {
    palClearPad(GPIOA, GPIOA_LED_GREEN);
    chThdSleepMilliseconds(200);
    palSetPad(GPIOA, GPIOA_LED_GREEN);
    chThdSleepMilliseconds(200);
  }
}


/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  /*
   * Activates the serial driver 2 using the driver default configuration.
   */

  /*
   * Creates the blinker thread.
   */
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);

    /*
     * Normal main() thread activity, in this demo it does nothing except
     * sleeping in a loop and check the button state.
     */
    led_string_init();
    adc_init();
    //communicationThreads_init();
    //waberthread_init();
    modem_on();
    smps_setOn();
    led_string_setBrightness(1, 0.5f);
    led_string_setBrightness(2, 0.5f);
    led_string_setBrightness(3, 0.5f);
    led_string_setBrightness(4, 0.5f);
    led_string_setBrightness(5, 0.5f);
    led_string_setBrightness(6, 0.5f);
    while (true) {
        chThdSleepMilliseconds(100);

    }
}
