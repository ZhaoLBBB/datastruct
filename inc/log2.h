#ifndef LOG2_H
#define LOG2_h
#include "bitops.h"
/**
 * is_power_of_2() - check if a value is a power of two
 * @n: the value to check
 *
 * Determine whether some value is a power of two, where zero is
 * *not* considered a power of two.
 * Return: 1 if @n is a power of 2, otherwise false.
 */
static inline int is_power_of_2(unsigned long n)
{
    return (n != 0 && ((n & (n - 1)) == 0));
}

static inline unsigned int roundup_pow_of_two(unsigned int n)
{
    return 1UL << fls(n - 1); 
}

static inline unsigned long roundup_pow_of_two_long(unsigned long n)
{
    return 1UL << fls_long(n - 1); 
}

/*
 * round down to nearest power of two
 */
static inline unsigned int rounddown_pow_of_two(unsigned int n)
{
    return 1UL << (fls(n) - 1); 
}

static inline unsigned long rounddown_pow_of_two_long(unsigned long n)
{
    return 1UL << (fls_long(n) - 1); 
}

static inline int ilog2(unsigned long v)
{
	int l = 0;
	while ((1UL << l) < v)
		l++;
	return l;
}

/*
 * This looks more complex than it should be. But we need to
 * get the type for the ~ right in round_down (it needs to be
 * as wide as the result!), and we want to evaluate the macro
 * arguments just once each.
 */
#define __round_mask(x, y) ((__typeof__(x))((y)-1))
/**
 * round_up - round up to next specified power of 2
 * @x: the value to round
 * @y: multiple to round up to (must be a power of 2)
 *
 * Rounds @x up to next multiple of @y (which must be a power of 2).
 * To perform arbitrary rounding up, use roundup() below.
 */
#define round_up(x, y) ((((x)-1) | __round_mask(x, y))+1)
/**
 * round_down - round down to next specified power of 2
 * @x: the value to round
 * @y: multiple to round down to (must be a power of 2)
 *
 * Rounds @x down to next multiple of @y (which must be a power of 2).
 * To perform arbitrary rounding down, use rounddown() below.
 */
#define round_down(x, y) ((x) & ~__round_mask(x, y))


#endif
