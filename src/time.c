#include "time.h"

/*    clockspeed, microsonds
 *     440mhz,    1000000
 * gcd(440000000, 1000000) = 1000000
 * 440000000 / 1000000 = 440
 *   1000000 / 1000000 = 1
 */

/* i guess it's simpler than the iop with how even this is (if correct) */
#define USEC_SYSCLOCK_NUM 440
#define USEC_SYSCLOCK_DENOM 1

u64
sysclock_get_clock()
{
	u32 hi, lo;
	u32 temp;

	do {
		__asm__ volatile("mftbu %0\n"
						 "mftb %1\n"
						 : "=r"(hi), "=r"(lo)::);

		__asm__ volatile("mftbu %0\n" : "=r"(temp) : :);
	} while (temp != hi);

	return ((u64)hi << 32) | lo;
}

u64
sysclock_from_usec(u32 usec)
{
	u64 clock;

	clock = (u64)usec * USEC_SYSCLOCK_NUM;
	clock = clock / USEC_SYSCLOCK_DENOM;

	return clock;
}

void
sysclock_to_usec(u64 clock, u32 *sec, u32 *usec)
{
	clock = clock * USEC_SYSCLOCK_DENOM;
	clock = clock / USEC_SYSCLOCK_NUM;

	*sec = clock / 1000000;
	*usec = clock % 1000000;
}
