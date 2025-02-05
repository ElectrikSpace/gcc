/*
 * Copyright (C) 2021 Kalray SA.
 *
 * Routines for KVX division and modulus on 64-bit integers.
 *
 * Based on the "TMS320C6000 Integer Division" Application Report, October 2000.
 *
 *     #define STSU(b, r) ( ((r) >= (b)) ? (((r) - (b)) << 1 | 1) : ((r) << 1) )
 *
 *     divmod_result_t
 *     divmodu32(uint32_t a, uint32_t b)
 *     {
 *         uint64_t r = a;
 *         if (b == 0) TRAP;
 *         if (b > a)
 *             return (divmod_result_t){ 0, a };
 *         int k = CLZ(b) - CLZ(a);
 *         b <<= k++;
 *         for (int i = 0; i < k; i++) {
 *             r = STSU(b, r);
 *         }
 *         uint32_t q = r & ((1<<k) - 1);
 *         r >>= k;
 *     end:;
 *         return (divmod_result_t){ q, r };
 *     }
 *
 * For 64-bit this algorithm may overflow on r and is corrected as in libgcc2.c:
 *
 *     divmod_result_t
 *     divmodu64(uint64_t a, uint64_t b)
 *     {
 *         uint64_t q = 0, r = a;
 *         if (b == 0) TRAP;
 *         if (b > a)
 *             goto end;
 *         int k = CLZ(b) - CLZ(a);
 *         b <<= k;
 *         if (r >= b) {
 *             r -= b;
 *             q = 1LL << k;
 *         }
 *         if (k > 0) {
 *             b >>= 1;
 *             uint64_t s = (1LL<<k) - 1;
 *             for (int i = 0; i < k; i++) {
 *                 r = STSU(b, r);
 *             }
 *             q += r & s;
 *             r >>= k;
 *         }
 *     end:;
 *         return (divmod_result_t){ q, r };
 *     }
 *
 * -- Benoit Dupont de Dinechin (benoit.dinechin@kalray.eu)
 */

#include "divmodtypes.h"

#if 0
static inline uint64x2_t
uint64_divmod (uint64_t a, uint64_t b)
{
  uint64_t q = 0, r = a;
  int k = __builtin_clzll (b) - __builtin_clzll (a);
  if (b == 0)
    goto div0;
  if (b > a)
    goto end;
  b <<= k;
  if (r >= b)
    {
      r -= b;
      q = 1LL << k;
    }
  if (k > 0)
    {
      b >>= 1;
      uint64_t s = (1LL << k) - 1;
      for (int i = 0; i < k; i++)
	{
	  r = __builtin_kvx_stsud (b, r);
	}
      q += r & s;
      r >>= k;
    }
end:
  return (uint64x2_t){q, r};
div0:
#ifndef __linux__
  if (&_KVX_NO_DIVMOD0_TRAP)
    return (uint64x2_t){0, 0};
#endif
  __builtin_trap ();
}
#else
static inline uint64x2_t
uint64_divmod (uint64_t a, uint64_t b)
{
  double double1 = 1.0;
  int64_t bbig = (int64_t)b < 0;
  int64_t bin01 = (uint64_t)b <= 1;
  int64_t special = bbig | bin01;
  // uint64_t q = bbig ? a >= b : a;
  uint64_t q = __builtin_kvx_selectd (a >= b, a, bbig, ".dnez");
  // uint64_t r = bbig ? a - (b&-q) : 0;
  uint64_t r = __builtin_kvx_selectd (a - (b & -q), 0, bbig, ".dnez");
  double doublea = __builtin_kvx_floatud (a, 0,  ".rn.s");
  double doubleb = __builtin_kvx_floatud (b, 0, ".rn.s");
  float floatb = __builtin_kvx_fnarrowdw (doubleb, ".rn.s");
  float floatrec = __builtin_kvx_frecw (floatb, ".rn.s");
  if (b == 0) goto div0;
  double doublerec = __builtin_kvx_fwidenwd (floatrec, ".s");
  double doubleq0 = __builtin_kvx_fmuld (doublea, doublerec, ".rn.s");
  uint64_t q0 = __builtin_kvx_fixedud (doubleq0, 0, ".rn.s");
  int64_t a1 = a - q0 * b;
  double alpha = __builtin_kvx_ffmsd (doubleb, doublerec, double1, ".rn.s");
  double beta = __builtin_kvx_ffmad (alpha, doublerec, doublerec, ".rn.s");
  double doublea1 = __builtin_kvx_floatd (a1, 0, ".rn.s");
  double gamma = __builtin_kvx_fmuld (beta, doublea1, ".rn.s");
  int64_t q1 = __builtin_kvx_fixedd (gamma, 0, ".rn.s");
  int64_t rem = a1 - q1 * b;
  uint64_t quo = q0 + q1;
  uint64_t cond = rem >> 63;
  // q = !special ? quo + cond : q;
  q = __builtin_kvx_selectd (quo + cond, q, special, ".deqz");
  // r = !special ? rem + (b & cond) : r;
  r = __builtin_kvx_selectd (rem + (b & cond), r, special, ".deqz");
  return (uint64x2_t){q, r};

div0:
#ifndef __linux__
  if (&_KVX_NO_DIVMOD0_TRAP)
    return 0 - (uint64x2_t){};
#endif
  __builtin_trap ();
}
#endif

#if !defined(TEST_V2DI) && !defined(TEST_V4DI)

uint64_t
__udivdi3 (uint64_t a, uint64_t b)
{
  uint64x2_t divmod = uint64_divmod (a, b);
  return divmod[0];
}

uint64_t
__umoddi3 (uint64_t a, uint64_t b)
{
  uint64x2_t divmod = uint64_divmod (a, b);
  return divmod[1];
}

uint64_t
__udivmoddi4 (uint64_t a, uint64_t b, uint64_t *c)
{
  uint64x2_t divmod = uint64_divmod (a, b);
  *c = divmod[1];
  return divmod[0];
}

int64_t
__divdi3 (int64_t a, int64_t b)
{
  uint64_t absa = __builtin_kvx_absd (a, "");
  uint64_t absb = __builtin_kvx_absd (b, "");
  uint64x2_t divmod = uint64_divmod (absa, absb);
  if ((a ^ b) < 0)
    divmod[0] = -divmod[0];
  return divmod[0];
}

int64_t
__moddi3 (int64_t a, int64_t b)
{
  uint64_t absa = __builtin_kvx_absd (a, "");
  uint64_t absb = __builtin_kvx_absd (b, "");
  uint64x2_t divmod = uint64_divmod (absa, absb);
  if (a < 0)
    divmod[1] = -divmod[1];
  return divmod[1];
}

#endif // TEST_V2DI, TEST_V4DI

