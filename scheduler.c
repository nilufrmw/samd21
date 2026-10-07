#include "scheduler.h"
#include "millis.h"

void scheduler_run(struct task *tasks, uint32_t count) {
  while(1) {
    uint32_t now = get_ms();
    for(int i = 0; i < count; i++) {
      if(now - tasks[i].last_ms >= tasks[i].interval_ms) {
        tasks[i].last_ms = now;
        tasks[i].run();
      }
    }
  }
}
