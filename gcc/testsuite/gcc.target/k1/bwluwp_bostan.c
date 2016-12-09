/* { dg-do  compile } */
/* { dg-skip-if "Only supported on Bostan" { *-*-* }  { "*" } { "-march=k1b" } } */
/* { dg-options "-O3 -save-temps"  } */

void bwluwp_builtin(long long *ret_ef, long long ab, long long cd) {
  *ret_ef = __builtin_k1_bwluwp(ab, cd, 0x12345678 );
}

/* { dg-final { scan-assembler "bwluwp \\\$r\[0-9\]+r\[0-9\]+ = \\\$r\[0-9\]+r\[0-9\]+, \\\$r\[0-9\]+r\[0-9\]+, 0x12345678"  } } */
