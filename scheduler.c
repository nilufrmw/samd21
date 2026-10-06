#include "samd21.h"
#include "millis.h"
#include <stdint.h>
#include <stdbool.h>

struct task {
  uint8_t id;
  uint32_t period;
  uint32_t last_run;
  bool ready;
};

struct task tasks[8];
int task_ptr = 0;

void add_task(uint8_t id, uint32_t period) {
  if(task_ptr < 8) {
    tasks[task_ptr].id = id;
    tasks[task_ptr].period = period;
    tasks[task_ptr].last_run = 0;
    tasks[task_ptr].ready = false;
    task_ptr++;
  }
}