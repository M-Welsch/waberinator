add

```c
#define STM32_TIM15_SUPPRESS_ISR
```

to `ChibiOS/os/hal/ports/STM32/LLD/TIMv1/hal_pwm_lld.c` at line 401



set `CHPRINTF_USE_FLOAT TRUE` in chprintf.h line 34

```
#if !defined(CHPRINTF_USE_FLOAT) || defined(__DOXYGEN__)
#define CHPRINTF_USE_FLOAT          TRUE
#endif
```