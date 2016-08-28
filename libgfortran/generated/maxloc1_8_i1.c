/* Implementation of the MAXLOC intrinsic
   Copyright (C) 2002-2015 Free Software Foundation, Inc.
   Contributed by Paul Brook <paul@nowt.org>

This file is part of the GNU Fortran runtime library (libgfortran).

Libgfortran is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

Libgfortran is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

#include "libgfortran.h"
#include <stdlib.h>
#include <assert.h>
#include <limits.h>


#if defined (HAVE_GFC_INTEGER_1) && defined (HAVE_GFC_INTEGER_8)


extern void maxloc1_8_i1 (gfc_array_i8 * const restrict, 
	gfc_array_i1 * const restrict, const index_type * const restrict);
export_proto(maxloc1_8_i1);

void
maxloc1_8_i1 (gfc_array_i8 * const restrict retarray, 
	gfc_array_i1 * const restrict array, 
	const index_type * const restrict pdim)
{
  index_type count[GFC_MAX_DIMENSIONS];
  index_type extent[GFC_MAX_DIMENSIONS];
  index_type sstride[GFC_MAX_DIMENSIONS];
  index_type dstride[GFC_MAX_DIMENSIONS];
  const GFC_INTEGER_1 * restrict base;
  GFC_INTEGER_8 * restrict dest;
  index_type rank;
  index_type n;
  index_type len;
  index_type delta;
  index_type dim;
  int continue_loop;

  /* Make dim zero based to avoid confusion.  */
  dim = (*pdim) - 1;
  rank = GFC_DESCRIPTOR_RANK (array) - 1;

  len = GFC_DESCRIPTOR_EXTENT(array,dim);
  if (len < 0)
    len = 0;
  delta = GFC_DESCRIPTOR_STRIDE_TYPEKNOWN(array,dim);

  for (n = 0; n < dim; n++)
    {
      sstride[n] = GFC_DESCRIPTOR_STRIDE_TYPEKNOWN(array,n);
      extent[n] = GFC_DESCRIPTOR_EXTENT(array,n);

      if (extent[n] < 0)
	extent[n] = 0;
    }
  for (n = dim; n < rank; n++)
    {
      sstride[n] = GFC_DESCRIPTOR_STRIDE_TYPEKNOWN(array, n + 1);
      extent[n] = GFC_DESCRIPTOR_EXTENT(array, n + 1);

      if (extent[n] < 0)
	extent[n] = 0;
    }

  if (retarray->base_addr == NULL)
    {
      size_t alloc_size, sm;

      for (n = 0; n < rank; n++)
	{
	  if (n == 0)
	    sm = sizeof (GFC_INTEGER_8);
	  else
	    sm = GFC_DESCRIPTOR_SM (retarray,n-1) * extent[n-1];

	  GFC_DIMENSION_SET (retarray->dim[n], 0, extent[n], sm);

	}

      retarray->offset = 0;
      retarray->elem_len = array->elem_len;
      retarray->type = array->type;

      alloc_size = GFC_DESCRIPTOR_SM (retarray, rank-1) * extent[rank-1];

      retarray->base_addr = xmallocarray (alloc_size, sizeof (GFC_INTEGER_8));
      if (alloc_size == 0)
	{
	  /* Make sure we have a zero-sized array.  */
	  GFC_DIMENSION_SET(retarray->dim[0], 0, -1, 1);
	  return;

	}
    }
  else
    {
      if (rank != GFC_DESCRIPTOR_RANK (retarray))
	runtime_error ("rank of return array incorrect in"
		       " MAXLOC intrinsic: is %ld, should be %ld",
		       (long int) (GFC_DESCRIPTOR_RANK (retarray)),
		       (long int) rank);

      if (unlikely (compile_options.bounds_check))
	bounds_ifunction_return ((array_t *) retarray, extent,
				 "return value", "MAXLOC");
    }

  for (n = 0; n < rank; n++)
    {
      count[n] = 0;
      dstride[n] = GFC_DESCRIPTOR_STRIDE_TYPEKNOWN(retarray,n);
      if (extent[n] <= 0)
	return;
    }

  base = array->base_addr;
  dest = retarray->base_addr;

  continue_loop = 1;
  while (continue_loop)
    {
      const GFC_INTEGER_1 * restrict src;
      GFC_INTEGER_8 result;
      src = base;
      {

	GFC_INTEGER_1 maxval;
#if defined (GFC_INTEGER_1_INFINITY)
	maxval = -GFC_INTEGER_1_INFINITY;
#else
	maxval = (-GFC_INTEGER_1_HUGE-1);
#endif
	result = 1;
	if (len <= 0)
	  *dest = 0;
	else
	  {
	    for (n = 0; n < len; n++, src += delta)
	      {

#if defined (GFC_INTEGER_1_QUIET_NAN)
		if (*src >= maxval)
		  {
		    maxval = *src;
		    result = (GFC_INTEGER_8)n + 1;
		    break;
		  }
	      }
	    for (; n < len; n++, src += delta)
	      {
#endif
		if (*src > maxval)
		  {
		    maxval = *src;
		    result = (GFC_INTEGER_8)n + 1;
		  }
	      }
	    
	    *dest = result;
	  }
      }
      /* Advance to the next element.  */
      count[0]++;
      base += sstride[0];
      dest += dstride[0];
      n = 0;
      while (count[n] == extent[n])
	{
	  /* When we get to the end of a dimension, reset it and increment
	     the next dimension.  */
	  count[n] = 0;
	  /* We could precalculate these products, but this is a less
	     frequently used path so probably not worth it.  */
	  base -= sstride[n] * extent[n];
	  dest -= dstride[n] * extent[n];
	  n++;
	  if (n == rank)
	    {
	      /* Break out of the look.  */
	      continue_loop = 0;
	      break;
	    }
	  else
	    {
	      count[n]++;
	      base += sstride[n];
	      dest += dstride[n];
	    }
	}
    }
}


extern void mmaxloc1_8_i1 (gfc_array_i8 * const restrict, 
	gfc_array_i1 * const restrict, const index_type * const restrict,
	gfc_array_l1 * const restrict);
export_proto(mmaxloc1_8_i1);

void
mmaxloc1_8_i1 (gfc_array_i8 * const restrict retarray, 
	gfc_array_i1 * const restrict array, 
	const index_type * const restrict pdim, 
	gfc_array_l1 * const restrict mask)
{
  index_type count[GFC_MAX_DIMENSIONS];
  index_type extent[GFC_MAX_DIMENSIONS];
  index_type sstride[GFC_MAX_DIMENSIONS];
  index_type dstride[GFC_MAX_DIMENSIONS];
  index_type mstride[GFC_MAX_DIMENSIONS];
  GFC_INTEGER_8 * restrict dest;
  const GFC_INTEGER_1 * restrict base;
  const GFC_LOGICAL_1 * restrict mbase;
  int rank;
  int dim;
  index_type n;
  index_type len;
  index_type delta;
  index_type mdelta;
  int mask_kind;

  dim = (*pdim) - 1;
  rank = GFC_DESCRIPTOR_RANK (array) - 1;

  len = GFC_DESCRIPTOR_EXTENT(array,dim);
  if (len <= 0)
    return;

  mbase = mask->base_addr;

  mask_kind = GFC_DESCRIPTOR_ELEM_LEN (mask);

  if (mask_kind == 1 || mask_kind == 2 || mask_kind == 4 || mask_kind == 8
#ifdef HAVE_GFC_LOGICAL_16
      || mask_kind == 16
#endif
      )
    mbase = GFOR_POINTER_TO_L1 (mbase, mask_kind);
  else
    runtime_error ("Funny sized logical array");

  delta = GFC_DESCRIPTOR_STRIDE_TYPEKNOWN(array,dim);
  mdelta = GFC_DESCRIPTOR_SM(mask,dim);

  for (n = 0; n < dim; n++)
    {
      sstride[n] = GFC_DESCRIPTOR_STRIDE_TYPEKNOWN(array,n);
      mstride[n] = GFC_DESCRIPTOR_SM(mask,n);
      extent[n] = GFC_DESCRIPTOR_EXTENT(array,n);

      if (extent[n] < 0)
	extent[n] = 0;

    }
  for (n = dim; n < rank; n++)
    {
      sstride[n] = GFC_DESCRIPTOR_STRIDE_TYPEKNOWN(array,n + 1);
      mstride[n] = GFC_DESCRIPTOR_SM(mask, n + 1);
      extent[n] = GFC_DESCRIPTOR_EXTENT(array, n + 1);

      if (extent[n] < 0)
	extent[n] = 0;
    }

  if (retarray->base_addr == NULL)
    {
      size_t alloc_size, sm ;

      for (n = 0; n < rank; n++)
	{
	  if (n == 0)
	    sm  = sizeof (GFC_INTEGER_8);
	  else
	    sm = GFC_DESCRIPTOR_SM (retarray, n-1) * extent[n-1];

	  GFC_DIMENSION_SET (retarray->dim[n], 0, extent[n], sm);

	}

      alloc_size = GFC_DESCRIPTOR_SM (retarray, rank-1) * extent[rank-1];

      retarray->offset = 0;
      retarray->elem_len = array->elem_len;
      retarray->type = array->type;

      if (alloc_size == 0)
	{
	  /* Make sure we have a zero-sized array.  */
	  GFC_DIMENSION_SET(retarray->dim[0], 0, -1, 1);
	  return;
	}
      else
	retarray->base_addr = xmallocarray (alloc_size, sizeof (GFC_INTEGER_8));

    }
  else
    {
      if (rank != GFC_DESCRIPTOR_RANK (retarray))
	runtime_error ("rank of return array incorrect in MAXLOC intrinsic");

      if (unlikely (compile_options.bounds_check))
	{
	  bounds_ifunction_return ((array_t *) retarray, extent,
				   "return value", "MAXLOC");
	  bounds_equal_extents ((array_t *) mask, (array_t *) array,
	  			"MASK argument", "MAXLOC");
	}
    }

  for (n = 0; n < rank; n++)
    {
      count[n] = 0;
      dstride[n] = GFC_DESCRIPTOR_STRIDE_TYPEKNOWN(retarray,n);
      if (extent[n] <= 0)
	return;
    }

  dest = retarray->base_addr;
  base = array->base_addr;

  while (base)
    {
      const GFC_INTEGER_1 * restrict src;
      const GFC_LOGICAL_1 * restrict msrc;
      GFC_INTEGER_8 result;
      src = base;
      msrc = mbase;
      {

	GFC_INTEGER_1 maxval;
#if defined (GFC_INTEGER_1_INFINITY)
	maxval = -GFC_INTEGER_1_INFINITY;
#else
	maxval = (-GFC_INTEGER_1_HUGE-1);
#endif
#if defined (GFC_INTEGER_1_QUIET_NAN)
	GFC_INTEGER_8 result2 = 0;
#endif
	result = 0;
	for (n = 0; n < len; n++, src += delta, msrc += mdelta)
	  {

		if (*msrc)
		  {
#if defined (GFC_INTEGER_1_QUIET_NAN)
		    if (!result2)
		      result2 = (GFC_INTEGER_8)n + 1;
		    if (*src >= maxval)
#endif
		      {
			maxval = *src;
			result = (GFC_INTEGER_8)n + 1;
			break;
		      }
		  }
	      }
#if defined (GFC_INTEGER_1_QUIET_NAN)
	    if (unlikely (n >= len))
	      result = result2;
	    else
#endif
	    for (; n < len; n++, src += delta, msrc += mdelta)
	      {
		if (*msrc && *src > maxval)
		  {
		    maxval = *src;
		    result = (GFC_INTEGER_8)n + 1;
		  }
	  }
	*dest = result;
      }
      /* Advance to the next element.  */
      count[0]++;
      base += sstride[0];
      mbase += mstride[0];
      dest += dstride[0];
      n = 0;
      while (count[n] == extent[n])
	{
	  /* When we get to the end of a dimension, reset it and increment
	     the next dimension.  */
	  count[n] = 0;
	  /* We could precalculate these products, but this is a less
	     frequently used path so probably not worth it.  */
	  base -= sstride[n] * extent[n];
	  mbase -= mstride[n] * extent[n];
	  dest -= dstride[n] * extent[n];
	  n++;
	  if (n == rank)
	    {
	      /* Break out of the look.  */
	      base = NULL;
	      break;
	    }
	  else
	    {
	      count[n]++;
	      base += sstride[n];
	      mbase += mstride[n];
	      dest += dstride[n];
	    }
	}
    }
}


extern void smaxloc1_8_i1 (gfc_array_i8 * const restrict, 
	gfc_array_i1 * const restrict, const index_type * const restrict,
	GFC_LOGICAL_4 *);
export_proto(smaxloc1_8_i1);

void
smaxloc1_8_i1 (gfc_array_i8 * const restrict retarray, 
	gfc_array_i1 * const restrict array, 
	const index_type * const restrict pdim, 
	GFC_LOGICAL_4 * mask)
{
  index_type count[GFC_MAX_DIMENSIONS];
  index_type extent[GFC_MAX_DIMENSIONS];
  index_type dstride[GFC_MAX_DIMENSIONS];
  GFC_INTEGER_8 * restrict dest;
  index_type rank;
  index_type n;
  index_type dim;


  if (*mask)
    {
      maxloc1_8_i1 (retarray, array, pdim);
      return;
    }
  /* Make dim zero based to avoid confusion.  */
  dim = (*pdim) - 1;
  rank = GFC_DESCRIPTOR_RANK (array) - 1;

  for (n = 0; n < dim; n++)
    {
      extent[n] = GFC_DESCRIPTOR_EXTENT(array,n);

      if (extent[n] <= 0)
	extent[n] = 0;
    }

  for (n = dim; n < rank; n++)
    {
      extent[n] =
	GFC_DESCRIPTOR_EXTENT(array,n + 1);

      if (extent[n] <= 0)
	extent[n] = 0;
    }

  if (retarray->base_addr == NULL)
    {
      size_t alloc_size, sm;

      for (n = 0; n < rank; n++)
	{
	  if (n == 0)
	    sm = sizeof (GFC_INTEGER_8);
	  else
	    sm = GFC_DESCRIPTOR_SM (retarray,n-1) * extent[n-1];

	  GFC_DIMENSION_SET (retarray->dim[n], 0, extent[n], sm);
	}

      retarray->elem_len = array->elem_len;
      retarray->type = array->type;
      retarray->offset = 0;

      alloc_size = GFC_DESCRIPTOR_SM (retarray, rank-1) * extent[rank-1];

      if (alloc_size == 0)
	{
	  /* Make sure we have a zero-sized array.  */
	  GFC_DIMENSION_SET(retarray->dim[0], 0, -1, 1);
	  return;
	}
      else
	retarray->base_addr = xmallocarray (alloc_size, sizeof (GFC_INTEGER_8));
    }
  else
    {
      if (rank != GFC_DESCRIPTOR_RANK (retarray))
	runtime_error ("rank of return array incorrect in"
		       " MAXLOC intrinsic: is %ld, should be %ld",
		       (long int) (GFC_DESCRIPTOR_RANK (retarray)),
		       (long int) rank);

      if (unlikely (compile_options.bounds_check))
	{
	  for (n=0; n < rank; n++)
	    {
	      index_type ret_extent;

	      ret_extent = GFC_DESCRIPTOR_EXTENT(retarray,n);
	      if (extent[n] != ret_extent)
		runtime_error ("Incorrect extent in return value of"
			       " MAXLOC intrinsic in dimension %ld:"
			       " is %ld, should be %ld", (long int) n + 1,
			       (long int) ret_extent, (long int) extent[n]);
	    }
	}
    }

  for (n = 0; n < rank; n++)
    {
      count[n] = 0;
      dstride[n] = GFC_DESCRIPTOR_STRIDE_TYPEKNOWN(retarray,n);
    }

  dest = retarray->base_addr;

  while(1)
    {
      *dest = 0;
      count[0]++;
      dest += dstride[0];
      n = 0;
      while (count[n] == extent[n])
	{
	  /* When we get to the end of a dimension, reset it and increment
	     the next dimension.  */
	  count[n] = 0;
	  /* We could precalculate these products, but this is a less
	     frequently used path so probably not worth it.  */
	  dest -= dstride[n] * extent[n];
	  n++;
	  if (n == rank)
	    return;
	  else
	    {
	      count[n]++;
	      dest += dstride[n];
	    }
      	}
    }
}

#endif
