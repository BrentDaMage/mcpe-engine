/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp
	
	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

// Lifted from 17c3daef4a27018c34b4b1f14e865d1da52dbeed

#pragma once

#include <stdint.h>

// This appears to be VERY similar to https://github.com/SethRobinson/proton/blob/master/shared/util/CRandom.h#L10
// It turns out, RTsoft, Mojang, and the author of Game Coding Complete used the same reference implementation of
// the Mersenne Twister:
//  http://www.math.sci.hiroshima-u.ac.jp/m-mat/MT/MT2002/CODES/mt19937ar.c

//A random generator based on the Mersenne Twister originally developed by Takuji Nishimura and Makoto Matsumoto.
// From the book GameCoding Complete by Mike McShaffry

/* Period parameters */
#define CMATH_N 624
#define CMATH_M 397
#define CMATH_MATRIX_A 0x9908b0df /* constant vector a */
#define CMATH_UPPER_MASK 0x80000000 /* most significant w-r bits */
#define CMATH_LOWER_MASK 0x7fffffff /* least significant r bits */

/* Tempering parameters */
#define CMATH_TEMPERING_MASK_B 0x9d2c5680
#define CMATH_TEMPERING_MASK_C 0xefc60000
#define CMATH_TEMPERING_SHIFT_U(y) (y >> 11)
#define CMATH_TEMPERING_SHIFT_S(y) (y << 7)
#define CMATH_TEMPERING_SHIFT_T(y) (y << 15)
#define CMATH_TEMPERING_SHIFT_L(y) (y >> 18)

int getTimeMs();

class Random
{
	unsigned int rseed;
	uint32_t mt[CMATH_N];  // the array for the state vector
	int mti;                    // mti==N+1 means mt[N] is not initialized
	double nextNextGaussian;

public:
	Random(int32_t seed = getTimeMs());
	void setSeed(int32_t seed);
	void init_genrand(uint32_t);
	int nextInt(int max);
	uint32_t genrand_int32();
	float nextFloat();
	double genrand_real2();
	long nextLong();
	int nextInt();
	float nextGaussian();
};
