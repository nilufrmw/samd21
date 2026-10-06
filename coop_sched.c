/*
Cooperative task scheduler for periodic routines
*/

#include <stdint.h>
#include <stdbool.h>

struct task {
  uint8_t id;
  uint32_t period;
  uint32_t delay;
  bool ready;
};