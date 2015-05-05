/* { dg-do run } */

#include <stdlib.h>
#include <openacc.h>

int
main (int argc, char **argv)
{
  const int N = 256;
  int i;
  unsigned char *h;

  h = (unsigned char *) malloc (N);

  for (i = 0; i < N; i++)
    {
      h[i] = i;
    }

  (void) acc_copyin (h, N);

  (void) acc_copyin (h, N);

  free (h);

  return 0;
}

/* { dg-output "\\\[0x\[0-9a-f\]+,\\\+256\\\] already mapped to \\\[0x\[0-9a-f\]+,\\\+256\\\]" } */
/* { dg-shouldfail "" } */
