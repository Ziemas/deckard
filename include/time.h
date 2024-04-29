#ifndef TIME_H_
#define TIME_H_

#include "types.h"

u64 sysclock_get_clock();
u64 sysclock_from_usec(u32 usec);
void sysclock_to_usec(u64 clock, u32 *sec, u32 *usec);

#endif // TIME_H_
