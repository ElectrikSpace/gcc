/*============================================================================

This C source file is part of the SoftFloat IEEE Floating-Point Arithmetic
Package, Release 3e, by John R. Hauser.

Copyright 2011, 2012, 2013, 2014 The Regents of the University of California.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice,
    this list of conditions, and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions, and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

 3. Neither the name of the University nor the names of its contributors may
    be used to endorse or promote products derived from this software without
    specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS "AS IS", AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ARE
DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=============================================================================*/
/*
 * Copyright (C) 2021 Kalray SA.
 *
 * All rights reserved.
 */
#include "kvxfp_f32.h"

/*
 * Returns a NaN propagated from its arguments.
 * `isanan` is known to be a NaN, `maybenan` must be checked for NaNity,
 * if one of them is a signaling NaN, the invalid exception is raised.
 * returns `isanan` silenced either way.
 */
static inline float
propagate_nan (union kvxfp_f32 isanan, union kvxfp_f32 maybenan)
{

  if (!(isanan.ui & UINT32_C (0x00400000)) || kvxfp_f32_issnan (maybenan))
    {
      kvxfp_raiseexcept (KVXFP_EXCEPT_INVALID);
    }

  isanan.ui |= UINT32_C (0x00400000);

  return isanan.f;
}

/*
 * Returns a NaN from an edge case (eg. division by zero)
 * raising an invalid exception on the way.
 */
static inline float
invalid_nan (void)
{

  kvxfp_raiseexcept (KVXFP_EXCEPT_INVALID);

  return (union kvxfp_f32){.ui = UINT32_C (0xFFC00000)}.f;
}

static inline float
adjust_pack (union kvxfp_f32 f32, int32_t adjustment)
{

  f32.ui += adjustment;

  return f32.f;
}

static float
round_pack (bool sign, int16_t exponent, uint32_t significand)
{
  const int round = kvxfp_getround ();
  unsigned int roundincrement, roundbits;

  if (round == KVXFP_ROUNDING_TONEAREST)
    { /* Or nearest away from zero, but it's not supported */
      roundincrement = 0x40;
    }
  else if (round == (sign ? KVXFP_ROUNDING_DOWNWARD : KVXFP_ROUNDING_UPWARD))
    {
      roundincrement = 0x7F;
    }
  else
    {
      roundincrement = 0;
    }
  roundbits = significand & 0x7F;

  if ((uint16_t) exponent >= 0xFD)
    {
      if (exponent < 0)
	{
	  const bool istiny
	    = KVXFP_DETECT_TININESS_BEFORE_ROUNDING || (exponent < -1)
	      || (significand + roundincrement < UINT32_C (0x80000000));

	  significand = jsr (significand, -exponent);
	  exponent = 0;
	  roundbits = significand & 0x7F;

	  if (istiny && roundbits)
	    {
	      kvxfp_raiseexcept (KVXFP_EXCEPT_UNDERFLOW);
	    }
	}
      else if ((0xFD < exponent)
	       || (UINT32_C (0x80000000) <= significand + roundincrement))
	{
	  kvxfp_raiseexcept (KVXFP_EXCEPT_OVERFLOW | KVXFP_EXCEPT_INEXACT);
	  return adjust_pack ((union kvxfp_f32){.sign = sign, .exponent = 0xFF},
			      -!roundincrement);
	}
    }

  significand = (significand + roundincrement) >> 7;
  if (roundbits)
    {
      kvxfp_raiseexcept (KVXFP_EXCEPT_INEXACT);
#ifdef KVXFP_ROUNDING_ODD
      if (round == KVXFP_ROUNDING_ODD)
	{
	  return adjust_pack ((union kvxfp_f32){.sign = sign,
						.exponent = exponent},
			      significand | 1);
	}
#endif
    }

  significand &= ~(uint32_t) (!(roundbits ^ 0x40)
			      & !!(round == KVXFP_ROUNDING_TONEAREST));
  if (!significand)
    {
      exponent = 0;
    }

  return adjust_pack ((union kvxfp_f32){.sign = sign, .exponent = exponent},
		      significand);
}

float
__divsf3 (float N, float D)
{
  union kvxfp_f32 A = {.f = N};
  union kvxfp_f32 B = {.f = D};
  const bool signZ = A.sign ^ B.sign;
  int exponentZ = A.exponent - B.exponent + 0x7E;

  /**************************
   * Eliminating edge cases *
   **************************/
  if (!kvxfp_f32_isnormal (A) || !kvxfp_f32_isnormal (B))
    {
      if (A.exponent == 0xFF)
	{
	  if (A.significand)
	    {
	      return propagate_nan (A, B);
	    }

	  if (B.exponent == 0xFF)
	    {
	      if (B.significand)
		{
		  return propagate_nan (B, A);
		}

	      return invalid_nan ();
	    }

	  return (union kvxfp_f32){.sign = signZ, .exponent = 0xFF}.f;
	}

      if (B.exponent == 0xFF)
	{
	  if (B.significand)
	    {
	      return propagate_nan (B, A);
	    }

	  return (union kvxfp_f32){.sign = signZ}.f;
	}

      if (!B.exponent)
	{
	  if (!B.significand)
	    {
	      if (!A.exponent & !A.significand)
		{
		  return invalid_nan ();
		}

	      kvxfp_raiseexcept (KVXFP_EXCEPT_DIVBYZERO);
	      return (union kvxfp_f32){.sign = signZ, .exponent = 0xFF}.f;
	    }

	  exponentZ -= kvxfp_f32_normalize_subnormal (&B);
	}

      if (!A.exponent)
	{
	  if (!A.significand)
	    {
	      return (union kvxfp_f32){.sign = signZ}.f;
	    }

	  exponentZ += kvxfp_f32_normalize_subnormal (&A);
	}
    }

  /***************
   * Computation *
   ***************/
  uint32_t significandA = A.significand | UINT32_C (0x00800000);
  uint32_t significandB = B.significand | UINT32_C (0x00800000);
  uint32_t significandZ;

  if (significandA < significandB)
    {
      --exponentZ;
      significandA <<= 8;
    }
  else
    {
      significandA <<= 7;
    }
  significandB <<= 8;
  significandZ
    = (uint64_t) significandA * kvxfp_approximate_reciprocal32 (significandB)
      >> 32;

  significandZ += 2;
  if ((significandZ & 0x3F) < 2)
    {
      significandZ &= ~3;
      const uint64_t remainder = ((uint64_t) significandA << 31)
				 - (uint64_t) significandZ * significandB;
      if (remainder & UINT64_C (0x8000000000000000))
	{
	  significandZ -= 4;
	}
      else
	{
	  if (remainder)
	    {
	      significandZ |= 1;
	    }
	}
    }

  return round_pack (signZ, exponentZ, significandZ);
}
