#ifndef MILLIS_H
#define MILLIS_H

#include <stdint.h>

void systick_init(void);
uint32_t get_ms(void);
void delay_ms(uint32_t ms);

#endif