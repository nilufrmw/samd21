#include "samd21.h"
#include "millis.h"
#include <stdint.h>
#include <stdbool.h>

#define MAX_TASKS 4

struct task {
  uint8_t id;
  uint32_t period;
  uint32_t last_run;
  bool ready;
};

struct task tasks[MAX_TASKS];
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

void run_scheduler(void) {
  uint32_t now = get_ms();
  for(int i = 0; i < task_ptr; ++i) {
    if((now - tasks[i].last_run) >= tasks[i].period) {
      tasks[i].last_run = now;
      tasks[i].ready = true;
    }
  }
}
