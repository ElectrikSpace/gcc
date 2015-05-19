#include <assert.h>
#include <stdlib.h>

/* Test switch containing vector-partitioned loops inside gang-partitioned
   loops.  */

int
main (int argc, char *argv[])
{
  int n[32], arr[1024], i;

  for (i = 0; i < 1024; i++)
    arr[i] = 0;

  for (i = 0; i < 32; i++)
    n[i] = i % 5;

  #pragma acc parallel copy(n, arr) num_gangs(32) num_workers(1) \
		       vector_length(32)
  {
    int j, k;

    #pragma acc loop gang(static:*)
    for (j = 0; j < 32; j++)
      n[j]++;

    #pragma acc loop gang(static:*)
    for (j = 0; j < 32; j++)
      switch (n[j])
	{
	case 1:
	  #pragma acc loop vector
	  for (k = 0; k < 32; k++)
	    arr[j * 32 + k] += 1;
	  break;

	case 2:
	  #pragma acc loop vector
	  for (k = 0; k < 32; k++)
	    arr[j * 32 + k] += 2;
	  break;

	case 3:
	  #pragma acc loop vector
	  for (k = 0; k < 32; k++)
	    arr[j * 32 + k] += 3;
	  break;

	case 4:
	  #pragma acc loop vector
	  for (k = 0; k < 32; k++)
	    arr[j * 32 + k] += 4;
	  break;

	case 5:
	  #pragma acc loop vector
	  for (k = 0; k < 32; k++)
	    arr[j * 32 + k] += 5;
	  break;

	default:
	  abort ();
	}

    #pragma acc loop gang(static:*)
    for (j = 0; j < 32; j++)
      n[j]++;
  }

  for (i = 0; i < 32; i++)
    assert (n[i] == (i % 5) + 2);

  for (i = 0; i < 1024; i++)
    assert (arr[i] == ((i / 32) % 5) + 1);

  return 0;
}
