#ifndef UTILS_H_
#define UTILS_H_

#include "types.h"

#define BIT(x) (1ULL << (x))
#define MASK(x) (BIT(x) - 1)
#define GENMASK(msb, lsb) ((BIT((msb + 1) - (lsb)) - 1) << (lsb))
#define FIELD_PREP(field, val) ((val) << (__builtin_ffsll(field) - 1))
#define FIELD_GET(field, val) \
	(((val) & (field)) >> (__builtin_ffsll(field) - 1))

static inline u32
read32(u32 addr)
{
	volatile u32 *a = (volatile u32 *)addr;

	return *a;
}

static inline u8
read8(u32 addr)
{
	volatile u8 *a = (volatile u8 *)addr;

	return *a;
}

static inline void
write32(u32 addr, u32 data)
{
	volatile u32 *a = (volatile u32 *)addr;

	*a = data;
}

static inline void
write8(u32 addr, u8 data)
{
	volatile u8 *a = (volatile u8 *)addr;

	*a = data;
}

static inline u32
set32(u32 addr, u32 set)
{
	volatile u32 *a = (volatile u32 *)addr;
	u32 d = *a | set;

	*a = d;
	return d;
}

static inline u32
clear32(u32 addr, u32 clear)
{
	volatile u32 *a = (volatile u32 *)addr;
	u32 d = *a & ~clear;

	*a = d;
	return d;
}

static inline u32
mask32(u32 addr, u32 clear, u32 set)
{
	volatile u32 *a = (volatile u32 *)addr;
	u32 d = *a;

	d = (d & ~clear) | set;

	*a = d;
	return d;
}

static inline int
poll32(u32 addr, u32 mask, u32 target)
{
	while (1) {
		u32 value = read32(addr) & mask;
		if (value == target) {
			return 0;
		}
	}
}

#endif // UTILS_H_
