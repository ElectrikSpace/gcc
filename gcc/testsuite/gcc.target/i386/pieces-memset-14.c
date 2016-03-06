/* { dg-do compile { target { ! ia32 } } } */
/* { dg-options "-O2 -mno-avx2 -mavx -mtune=haswell" } */

extern char *dst;

void
foo (void)
{
  __builtin_memset (dst, 3, 33);
}

/* { dg-final { scan-assembler-times "vmovups\[ \\t\]+\[^\n\]*%xmm" 2 } } */
