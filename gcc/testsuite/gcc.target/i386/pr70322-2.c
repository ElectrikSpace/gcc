/* PR target/70322 */
/* { dg-do compile { target ia32 } } */
/* { dg-options "-O2 -msse2 -mstv -mno-bmi" } */
/* { dg-final { scan-assembler "pandn" { xfail *-*-* } } } */

extern long long z;

void
foo (long long x, long long y)
{
  z = ~x & y;
}
