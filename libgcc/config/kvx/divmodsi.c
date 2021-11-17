/*
 * Copyright (C) 2021 Kalray SA.
 *
 * Routines for KVX division and modulus on 32-bit integers.
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
 *         uint32_t q = r & ((1LL<<k) - 1);
 *         r >>= k;
 *     end:;
 *         return (divmod_result_t){ q, r };
 *     }
 *
 * -- Benoit Dupont de Dinechin (benoit.dinechin@kalray.eu)
 */

typedef __INT32_TYPE__ int32_t;
typedef __UINT32_TYPE__ uint32_t;
typedef uint32_t uint32x2_t __attribute ((vector_size (2 * sizeof (uint32_t))));

typedef __INT64_TYPE__ int64_t;
typedef __UINT64_TYPE__ uint64_t;
typedef uint64_t uint64x2_t __attribute ((vector_size (2 * sizeof (uint64_t))));

uint32_t __udivsi3 (uint32_t a, uint32_t b);
uint32_t __umodsi3 (uint32_t a, uint32_t b);
uint32_t __udivmodsi4 (uint32_t a, uint32_t b, uint32_t *c);
int32_t __divsi3 (int32_t a, int32_t b);
int32_t __modsi3 (int32_t a, int32_t b);

#ifndef __linux__
/*
 * Setting this symbol non-zero changes the behavior of divmod by zero.
 * The default behavior is to terminate the application with a trap.
 * This feature is needed by the OpenCL-C division where the result is
 * undefined instead of crashing the user application.
 */
extern char *_KVX_NO_DIVMOD0_TRAP __attribute__ ((weak));
#endif

#if 0
static inline uint32x2_t
uint32_divmod (uint32_t a, uint32_t b)
{
  uint32_t q = 0;
  uint64_t r = a;
  int k = __builtin_clz (b) - __builtin_clz (a);
  if (b == 0)
    goto div0;
  if (b > a)
    goto end;
  b <<= k++;
  uint64_t s = (1LL << k) - 1;
  for (int i = 0; i < k; i++)
    {
      r = __builtin_kvx_stsud (b, r);
    }
  q = r & s;
  r >>= k;
end:;
  return (uint32x2_t){q, r};
div0:
#ifndef __linux__
  if (&_KVX_NO_DIVMOD0_TRAP)
    return (uint32x2_t){0, 0};
#endif
  __builtin_trap ();
}
#else
static inline uint32x2_t
uint32_divmod (uint32_t a, uint32_t b)
{
  float floatb = __builtin_kvx_floatuw (b, 0,  ".rn.s");
  float floatrec =  __builtin_kvx_frecw(floatb, ".rn.s");
  if (b == 0) goto div0;
  double doublerec = __builtin_kvx_fwidenwd (floatrec, ".s");
  double alpha = __builtin_kvx_ffmsxwd(floatrec, floatb, 1.0, ".rn.s");
  double beta = __builtin_kvx_ffmad(alpha, doublerec, doublerec, ".rn.s");
  double doublea = __builtin_kvx_floatud (a, 0, ".rn.s");
  double gamma = __builtin_kvx_fmuld(doublea, beta, ".rn.s");
  uint32_t quo = __builtin_kvx_fixedud(gamma, 0, ".rn.s");
  int32_t rem = a - quo*b;
  uint32_t cond = rem >> 31;
  uint32_t q = quo + cond;
  uint32_t r = rem + (b & cond);
  return (uint32x2_t){q, r};
div0:
#ifndef __linux__
  if (&_KVX_NO_DIVMOD0_TRAP)
    return (uint32x2_t){0, 0};
#endif
  __builtin_trap ();
}
#endif

uint32_t
__udivsi3 (uint32_t a, uint32_t b)
{
  uint32x2_t divmod = uint32_divmod (a, b);
  return (uint32_t) divmod[0];
}

uint32_t
__umodsi3 (uint32_t a, uint32_t b)
{
  uint32x2_t divmod = uint32_divmod (a, b);
  return (uint32_t) divmod[1];
}

uint32_t
__udivmodsi4 (uint32_t a, uint32_t b, uint32_t *c)
{
  uint32x2_t divmod = uint32_divmod (a, b);
  *c = (uint32_t) divmod[1];
  return (uint32_t) divmod[0];
}

int32_t
__divsi3 (int32_t a, int32_t b)
{
  uint32_t absa = a < 0 ? -a : a;
  uint32_t absb = b < 0 ? -b : b;
  uint32x2_t divmod = uint32_divmod (absa, absb);
  int32_t result = (int32_t) divmod[0];
  if ((a ^ b) < 0)
    result = -result;
  return result;
}

int32_t
__modsi3 (int32_t a, int32_t b)
{
  uint32_t absa = a < 0 ? -a : a;
  uint32_t absb = b < 0 ? -b : b;
  uint32x2_t divmod = uint32_divmod (absa, absb);
  int32_t result = (int32_t) divmod[1];
  if (a < 0)
    result = -result;
  return result;
}
