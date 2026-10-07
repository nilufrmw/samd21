#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

struct task {
  void (*run) (void);
  uint32_t interval_ms;
  uint32_t last_ms;
};

void scheduler_run(struct task *tasks, int count);

#endif
