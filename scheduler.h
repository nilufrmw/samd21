#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>
#include <stdbool.h>

void add_task(uint8_t id, uint32_t period);
void run_scheduler(void);
bool is_task_ready(uint8_t id);

#endif
