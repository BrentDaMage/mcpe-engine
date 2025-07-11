/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp
	
	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

// Lifted from 17c3daef4a27018c34b4b1f14e865d1da52dbeed

#include <limits>

#include "Random.h"

/* Period parameters */
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */

Random::Random(int32_t seed)
{
	setSeed(seed);
	nextNextGaussian = std::numeric_limits<double>::max();;
}

void Random::setSeed(int32_t seed)
{
	rseed = seed;
	mti = N + 1;
	init_genrand(seed);
}

/* initializes mt[N] with a seed */
void Random::init_genrand(uint32_t s)
{
	mt[0] = s & 0xffffffffUL;
	for (mti = 1; mti < N; mti++) {
		mt[mti] =
			(1812433253UL * (mt[mti - 1] ^ (mt[mti - 1] >> 30)) + mti);
		/* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
		/* In the previous versions, MSBs of the seed affect   */
		/* only MSBs of the array mt[].                        */
		/* 2002/01/09 modified by Makoto Matsumoto             */
		mt[mti] &= 0xffffffffUL;
		/* for >32 bit machines */
	}
}

int Random::nextInt(int max)
{
	return int(genrand_int32() % unsigned(max));
}

// Returns a number from 0 to n (excluding n)
uint32_t Random::genrand_int32()
{
	uint32_t y;
	static uint32_t mag01[2]={0x0UL, MATRIX_A};
	/* mag01[x] = x * MATRIX_A  for x=0,1 */

	if (mti >= N) { /* generate N words at one time */
		int kk;

		if (mti == N+1)   /* if init_genrand() has not been called, */
			init_genrand(5489UL); /* a default initial seed is used */

		for (kk=0;kk<N-M;kk++) {
			y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
			mt[kk] = mt[kk+M] ^ (y >> 1) ^ mag01[y & 0x1UL];
		}
		for (;kk<N-1;kk++) {
			y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
			mt[kk] = mt[kk+(M-N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
		}
		y = (mt[N-1]&UPPER_MASK)|(mt[0]&LOWER_MASK);
		mt[N-1] = mt[M-1] ^ (y >> 1) ^ mag01[y & 0x1UL];

		mti = 0;
	}
  
	y = mt[mti++];

	/* Tempering */
	y ^= (y >> 11);
	y ^= (y << 7) & 0x9d2c5680UL;
	y ^= (y << 15) & 0xefc60000UL;
	y ^= (y >> 18);

	return y;
}

float Random::nextFloat()
{
	return float(genrand_real2());
}

double Random::genrand_real2()
{
	return double(genrand_int32()) * (1.0 / 4294967296.0);
}

long Random::nextLong()
{
	// @TODO: Not a real long on 64-bit architectures
	return long(genrand_int32() >> 1);
}

int Random::nextInt()
{
	return int(genrand_int32() >> 1);
}

float Random::nextGaussian()
{
	if (nextNextGaussian < std::numeric_limits<double>::max())
	{
		double backup = nextNextGaussian;
		nextNextGaussian = std::numeric_limits<double>::max();
		return backup;
	}
	// See Knuth, ACP, Section 3.4.1 Algorithm C.
	float v1, v2, s;
	do
	{
		v1 = 2 * nextFloat() - 1;
		v2 = 2 * nextFloat() - 1;
		s = v1 * v1 + v2 * v2;
	}
	while (s >= 1 || s == 0);
	float mult = sqrtf(-2 * log(s) / s);
	nextNextGaussian = v2 * mult;
	return v1 * mult;
}
