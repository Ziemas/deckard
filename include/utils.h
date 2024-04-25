#ifndef UTILS_H_
#define UTILS_H_

#include "types.h"

#define BIT(x) (1ULL << (x))
#define MASK(x) (BIT(x) - 1)
#define GENMASK(msb, lsb) ((BIT((msb + 1) - (lsb)) - 1) << (lsb))
#define _FIELD_LSB(field) ((field) & ~(field - 1))
#define FIELD_PREP(field, val) ((val) * (_FIELD_LSB(field)))
#define FIELD_GET(field, val) (((val) & (field)) / _FIELD_LSB(field))

static inline uint32
read32(uint32 addr)
{
	volatile uint32 *a = (volatile uint32 *)addr;

	return *a;
}

static inline uint8
read8(uint32 addr)
{
	volatile uint8 *a = (volatile uint8 *)addr;

	return *a;
}

static inline void
write32(uint32 addr, uint32 data)
{
	volatile uint32 *a = (volatile uint32 *)addr;

	*a = data;
}

static inline void
write8(uint32 addr, uint8 data)
{
	volatile uint8 *a = (volatile uint8 *)addr;

	*a = data;
}

static inline uint32
set32(uint32 addr, uint32 set)
{
	volatile uint32 *a = (volatile uint32 *)addr;
	uint32 d = *a | set;

	*a = d;
	return d;
}

static inline uint32
clear32(uint32 addr, uint32 clear)
{
	volatile uint32 *a = (volatile uint32 *)addr;
	uint32 d = *a & ~clear;

	*a = d;
	return d;
}

static inline uint32
mask32(uint32 addr, uint32 clear, uint32 set)
{
	volatile uint32 *a = (volatile uint32 *)addr;
	uint32 d = *a;

	d = (d & ~clear) | set;

	*a = d;
	return d;
}

static inline int
poll32(uint32 addr, uint32 mask, uint32 target)
{
	while (1) {
		uint32 value = read32(addr) & mask;
		if (value == target) {
			return 0;
		}
	}
}

#endif // UTILS_H_
