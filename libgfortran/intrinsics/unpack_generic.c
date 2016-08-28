/* Generic implementation of the UNPACK intrinsic
   Copyright (C) 2002-2015 Free Software Foundation, Inc.
   Contributed by Paul Brook <paul@nowt.org>

This file is part of the GNU Fortran runtime library (libgfortran).

Libgfortran is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

Ligbfortran is distributed in the hope that it will be useful,
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
#include <string.h>

/* All the bounds checking for unpack in one function.  If field is NULL,
   we don't check it, for the unpack0 functions.  */

static void
unpack_bounds (gfc_array_char *ret, const gfc_array_char *vector,
	 const gfc_array_l1 *mask, const gfc_array_char *field)
{
  index_type vec_size, mask_count;
  vec_size = size0 ((array_t *) vector);
  mask_count = count_0 (mask);
  if (vec_size < mask_count)
    runtime_error ("Incorrect size of return value in UNPACK"
		   " intrinsic: should be at least %ld, is"
		   " %ld", (long int) mask_count,
		   (long int) vec_size);

  if (field != NULL)
    bounds_equal_extents ((array_t *) field, (array_t *) mask,
			  "FIELD", "UNPACK");

  if (ret->base_addr != NULL)
    bounds_equal_extents ((array_t *) ret, (array_t *) mask,
			  "return value", "UNPACK");

}

static void
unpack_internal (gfc_array_char *ret, const gfc_array_char *vector,
		 const gfc_array_l1 *mask, const gfc_array_char *field,
		 index_type size)
{
  /* r.* indicates the return array.  */
  index_type rsm[GFC_MAX_DIMENSIONS];
  index_type rsm0;
  index_type rs;
  char * restrict rptr;
  /* v.* indicates the vector array.  */
  index_type vsm0;
  char *vptr;
  /* f.* indicates the field array.  */
  index_type fsm[GFC_MAX_DIMENSIONS];
  index_type fsm0;
  const char *fptr;
  /* m.* indicates the mask array.  */
  index_type msm[GFC_MAX_DIMENSIONS];
  index_type msm0;
  const GFC_LOGICAL_1 *mptr;

  index_type count[GFC_MAX_DIMENSIONS];
  index_type extent[GFC_MAX_DIMENSIONS];
  index_type n;
  index_type dim;

  int empty;
  int mask_kind;

  empty = 0;

  mptr = mask->base_addr;

  /* Use the same loop for all logical types, by using GFC_LOGICAL_1
     and using shifting to address size and endian issues.  */

  mask_kind = GFC_DESCRIPTOR_ELEM_LEN (mask);

  if (mask_kind == 1 || mask_kind == 2 || mask_kind == 4 || mask_kind == 8
#ifdef HAVE_GFC_LOGICAL_16
      || mask_kind == 16
#endif
      )
    {
      /*  Don't convert a NULL pointer as we use test for NULL below.  */
      if (mptr)
	mptr = GFOR_POINTER_TO_L1 (mptr, mask_kind);
    }
  else
    runtime_error ("Funny sized logical array");

  if (ret->base_addr == NULL)
    {
      /* The front end has signalled that we need to populate the
	 return array descriptor.  */
      dim = GFC_DESCRIPTOR_RANK (mask);
      rs = size;
      for (n = 0; n < dim; n++)
	{
	  count[n] = 0;
	  GFC_DIMENSION_SET(ret->dim[n], 0,
			    GFC_DESCRIPTOR_EXTENT(mask,n), rs);
	  extent[n] = GFC_DESCRIPTOR_EXTENT(ret,n);
	  empty = empty || extent[n] <= 0;
	  rsm[n] = GFC_DESCRIPTOR_SM(ret, n);
	  fsm[n] = GFC_DESCRIPTOR_SM(field, n);
	  msm[n] = GFC_DESCRIPTOR_SM(mask, n);
	  rs *= extent[n];
	}
      ret->offset = 0;
      ret->base_addr = xmalloc (rs);
    }
  else
    {
      dim = GFC_DESCRIPTOR_RANK (ret);
      for (n = 0; n < dim; n++)
	{
	  count[n] = 0;
	  extent[n] = GFC_DESCRIPTOR_EXTENT(ret,n);
	  empty = empty || extent[n] <= 0;
	  rsm[n] = GFC_DESCRIPTOR_SM(ret, n);
	  fsm[n] = GFC_DESCRIPTOR_SM(field, n);
	  msm[n] = GFC_DESCRIPTOR_SM(mask, n);
	}
    }

  if (empty)
    return;

  /* This assert makes sure GCC knows we can access *stride[0] later.  */
  assert (dim > 0);

  vsm0 = GFC_DESCRIPTOR_SM(vector,0);
  rsm0 = rsm[0];
  fsm0 = fsm[0];
  msm0 = msm[0];
  rptr = ret->base_addr;
  fptr = field->base_addr;
  vptr = vector->base_addr;

  while (rptr)
    {
      if (*mptr)
        {
          /* From vector.  */
          memcpy (rptr, vptr, size);
          vptr += vsm0;
        }
      else
        {
          /* From field.  */
          memcpy (rptr, fptr, size);
        }
      /* Advance to the next element.  */
      rptr += rsm0;
      fptr += fsm0;
      mptr += msm0;
      count[0]++;
      n = 0;
      while (count[n] == extent[n])
        {
          /* When we get to the end of a dimension, reset it and increment
             the next dimension.  */
          count[n] = 0;
          /* We could precalculate these products, but this is a less
             frequently used path so probably not worth it.  */
          rptr -= rsm[n] * extent[n];
          fptr -= fsm[n] * extent[n];
          mptr -= msm[n] * extent[n];
          n++;
          if (n >= dim)
            {
              /* Break out of the loop.  */
              rptr = NULL;
              break;
            }
          else
            {
              count[n]++;
              rptr += rsm[n];
              fptr += fsm[n];
              mptr += msm[n];
            }
        }
    }
}

extern void unpack1 (gfc_array_char *, const gfc_array_char *,
		     const gfc_array_l1 *, const gfc_array_char *);
export_proto(unpack1);

void
unpack1 (gfc_array_char *ret, const gfc_array_char *vector,
	 const gfc_array_l1 *mask, const gfc_array_char *field)
{
  CFI_type_t type;
  index_type size;

  if (unlikely(compile_options.bounds_check))
    unpack_bounds (ret, vector, mask, field);

  size = GFC_DESCRIPTOR_ELEM_LEN (vector);

  type = GFC_DESCRIPTOR_TYPE (vector);
  if ((type == CFI_type_struct || type == CFI_type_other)
      && GFC_DESCRIPTOR_ELEM_LEN (vector) == 1)
    type = CFI_type_Integer1;

  switch (type)
    {
    case CFI_type_Integer1:
    case CFI_type_Logical1:
      unpack1_i1 ((gfc_array_i1 *) ret, (gfc_array_i1 *) vector,
		  mask, (gfc_array_i1 *) field);
      return;

    case CFI_type_Integer2:
    case CFI_type_Logical2:
      unpack1_i2 ((gfc_array_i2 *) ret, (gfc_array_i2 *) vector,
		  mask, (gfc_array_i2 *) field);
      return;

    case CFI_type_Integer4:
    case CFI_type_Logical4:
      unpack1_i4 ((gfc_array_i4 *) ret, (gfc_array_i4 *) vector,
		  mask, (gfc_array_i4 *) field);
      return;

    case CFI_type_Integer8:
    case CFI_type_Logical8:
      unpack1_i8 ((gfc_array_i8 *) ret, (gfc_array_i8 *) vector,
		  mask, (gfc_array_i8 *) field);
      return;

#ifdef HAVE_GFC_INTEGER_16
    case CFI_type_Integer16:
    case CFI_type_Logical16:
      unpack1_i16 ((gfc_array_i16 *) ret, (gfc_array_i16 *) vector,
		   mask, (gfc_array_i16 *) field);
      return;
#endif

    case CFI_type_Real4:
      unpack1_r4 ((gfc_array_r4 *) ret, (gfc_array_r4 *) vector,
		  mask, (gfc_array_r4 *) field);
      return;

    case CFI_type_Real8:
      unpack1_r8 ((gfc_array_r8 *) ret, (gfc_array_r8 *) vector,
		  mask, (gfc_array_r8 *) field);
      return;

# ifdef HAVE_GFC_REAL_10
    case CFI_type_Real10:
      unpack1_r10 ((gfc_array_r10 *) ret, (gfc_array_r10 *) vector,
		   mask, (gfc_array_r10 *) field);
      return;
# endif

# ifdef HAVE_GFC_REAL_16
    case CFI_type_Real16:
      unpack1_r16 ((gfc_array_r16 *) ret, (gfc_array_r16 *) vector,
		   mask, (gfc_array_r16 *) field);
      return;
# endif

    case CFI_type_Complex4:
      unpack1_c4 ((gfc_array_c4 *) ret, (gfc_array_c4 *) vector,
		  mask, (gfc_array_c4 *) field);
      return;

    case CFI_type_Complex8:
      unpack1_c8 ((gfc_array_c8 *) ret, (gfc_array_c8 *) vector,
		  mask, (gfc_array_c8 *) field);
      return;

# ifdef HAVE_GFC_COMPLEX_10
    case CFI_type_Complex10:
      unpack1_c10 ((gfc_array_c10 *) ret, (gfc_array_c10 *) vector,
		   mask, (gfc_array_c10 *) field);
      return;
# endif

# ifdef HAVE_GFC_COMPLEX_16
    case CFI_type_Complex16:
      unpack1_c16 ((gfc_array_c16 *) ret, (gfc_array_c16 *) vector,
		   mask, (gfc_array_c16 *) field);
      return;
# endif

    case CFI_type_struct:
    case CFI_type_other:
      switch (GFC_DESCRIPTOR_ELEM_LEN(vector))
        {
        case 2:
	  if (GFC_UNALIGNED_2(ret->base_addr)
	      || GFC_UNALIGNED_2(vector->base_addr)
	      || GFC_UNALIGNED_2(field->base_addr))
	    break;
	  else
	    {
	      unpack1_i2 ((gfc_array_i2 *) ret, (gfc_array_i2 *) vector,
			  mask, (gfc_array_i2 *) field);
	      return;
	    }

        case 4:
	  if (GFC_UNALIGNED_4(ret->base_addr)
	      || GFC_UNALIGNED_4(vector->base_addr)
	      || GFC_UNALIGNED_4(field->base_addr))
	    break;
	  else
	    {
	      unpack1_i4 ((gfc_array_i4 *) ret, (gfc_array_i4 *) vector,
			  mask, (gfc_array_i4 *) field);
	      return;
	    }

        case 8:
	  if (GFC_UNALIGNED_8(ret->base_addr)
	      || GFC_UNALIGNED_8(vector->base_addr)
	      || GFC_UNALIGNED_8(field->base_addr))
	    break;
	  else
	    {
	      unpack1_i8 ((gfc_array_i8 *) ret, (gfc_array_i8 *) vector,
			  mask, (gfc_array_i8 *) field);
	      return;
	    }

#ifdef HAVE_GFC_INTEGER_16
        case 16:
	  if (GFC_UNALIGNED_16(ret->base_addr)
	      || GFC_UNALIGNED_16(vector->base_addr)
	      || GFC_UNALIGNED_16(field->base_addr))
	    break;
	  else
	    {
	      unpack1_i16 ((gfc_array_i16 *) ret, (gfc_array_i16 *) vector,
			   mask, (gfc_array_i16 *) field);
	      return;
	    }
#endif
        }
    }

  unpack_internal (ret, vector, mask, field, size);
}


extern void unpack1_char (gfc_array_char *, GFC_INTEGER_4,
			  const gfc_array_char *, const gfc_array_l1 *,
			  const gfc_array_char *, GFC_INTEGER_4,
			  GFC_INTEGER_4);
export_proto(unpack1_char);

void
unpack1_char (gfc_array_char *ret,
	      GFC_INTEGER_4 ret_length __attribute__((unused)),
	      const gfc_array_char *vector, const gfc_array_l1 *mask,
	      const gfc_array_char *field, GFC_INTEGER_4 vector_length,
	      GFC_INTEGER_4 field_length __attribute__((unused)))
{

  if (unlikely(compile_options.bounds_check))
    unpack_bounds (ret, vector, mask, field);

  unpack_internal (ret, vector, mask, field, vector_length);
}


extern void unpack1_char4 (gfc_array_char *, GFC_INTEGER_4,
			   const gfc_array_char *, const gfc_array_l1 *,
			   const gfc_array_char *, GFC_INTEGER_4,
			   GFC_INTEGER_4);
export_proto(unpack1_char4);

void
unpack1_char4 (gfc_array_char *ret,
	       GFC_INTEGER_4 ret_length __attribute__((unused)),
	       const gfc_array_char *vector, const gfc_array_l1 *mask,
	       const gfc_array_char *field, GFC_INTEGER_4 vector_length,
	       GFC_INTEGER_4 field_length __attribute__((unused)))
{

  if (unlikely(compile_options.bounds_check))
    unpack_bounds (ret, vector, mask, field);

  unpack_internal (ret, vector, mask, field,
		   vector_length * sizeof (gfc_char4_t));
}


extern void unpack0 (gfc_array_char *, const gfc_array_char *,
		     const gfc_array_l1 *, char *);
export_proto(unpack0);

void
unpack0 (gfc_array_char *ret, const gfc_array_char *vector,
	 const gfc_array_l1 *mask, char *field)
{
  gfc_array_char tmp;
  CFI_type_t type;

  if (unlikely(compile_options.bounds_check))
    unpack_bounds (ret, vector, mask, NULL);

  type = GFC_DESCRIPTOR_TYPE (vector);
  if ((type == CFI_type_struct || type == CFI_type_other)
      && GFC_DESCRIPTOR_ELEM_LEN (vector) == 1)
    type = CFI_type_Integer1;

  switch (type)
    {
    case CFI_type_Integer1:
    case CFI_type_Logical1:
      unpack0_i1 ((gfc_array_i1 *) ret, (gfc_array_i1 *) vector,
		  mask, (GFC_INTEGER_1 *) field);
      return;

    case CFI_type_Integer2:
    case CFI_type_Logical2:
      unpack0_i2 ((gfc_array_i2 *) ret, (gfc_array_i2 *) vector,
		  mask, (GFC_INTEGER_2 *) field);
      return;

    case CFI_type_Integer4:
    case CFI_type_Logical4:
      unpack0_i4 ((gfc_array_i4 *) ret, (gfc_array_i4 *) vector,
		  mask, (GFC_INTEGER_4 *) field);
      return;

    case CFI_type_Integer8:
    case CFI_type_Logical8:
      unpack0_i8 ((gfc_array_i8 *) ret, (gfc_array_i8 *) vector,
		  mask, (GFC_INTEGER_8 *) field);
      return;

#ifdef HAVE_GFC_INTEGER_16
    case CFI_type_Integer16:
    case CFI_type_Logical16:
      unpack0_i16 ((gfc_array_i16 *) ret, (gfc_array_i16 *) vector,
		   mask, (GFC_INTEGER_16 *) field);
      return;
#endif

    case CFI_type_Real4:
      unpack0_r4 ((gfc_array_r4 *) ret, (gfc_array_r4 *) vector,
		  mask, (GFC_REAL_4 *) field);
      return;

    case CFI_type_Real8:
      unpack0_r8 ((gfc_array_r8 *) ret, (gfc_array_r8*) vector,
		  mask, (GFC_REAL_8  *) field);
      return;

# ifdef HAVE_GFC_REAL_10
    case CFI_type_Real10:
      unpack0_r10 ((gfc_array_r10 *) ret, (gfc_array_r10 *) vector,
		   mask, (GFC_REAL_10 *) field);
      return;
# endif

# ifdef HAVE_GFC_REAL_16
    case CFI_type_Real16:
      unpack0_r16 ((gfc_array_r16 *) ret, (gfc_array_r16 *) vector,
		   mask, (GFC_REAL_16 *) field);
      return;
# endif

    case CFI_type_Complex4:
      unpack0_c4 ((gfc_array_c4 *) ret, (gfc_array_c4 *) vector,
		  mask, (GFC_COMPLEX_4 *) field);
      return;

    case CFI_type_Complex8:
      unpack0_c8 ((gfc_array_c8 *) ret, (gfc_array_c8 *) vector,
		  mask, (GFC_COMPLEX_8 *) field);
      return;

# ifdef HAVE_GFC_COMPLEX_10
    case CFI_type_Complex10:
      unpack0_c10 ((gfc_array_c10 *) ret, (gfc_array_c10 *) vector,
		   mask, (GFC_COMPLEX_10 *) field);
      return;
# endif

# ifdef HAVE_GFC_COMPLEX_16
    case CFI_type_Complex16:
      unpack0_c16 ((gfc_array_c16 *) ret, (gfc_array_c16 *) vector,
		   mask, (GFC_COMPLEX_16 *) field);
      return;
# endif

    case CFI_type_struct:
    case CFI_type_other:
      switch (GFC_DESCRIPTOR_ELEM_LEN(vector))
	{
	case 2:
	  if (GFC_UNALIGNED_2(ret->base_addr)
	      || GFC_UNALIGNED_2(vector->base_addr)
	      || GFC_UNALIGNED_2(field))
	    break;
	  else
	    {
	      unpack0_i2 ((gfc_array_i2 *) ret, (gfc_array_i2 *) vector,
			  mask, (GFC_INTEGER_2 *) field);
	      return;
	    }

	case 4:
	  if (GFC_UNALIGNED_4(ret->base_addr)
	      || GFC_UNALIGNED_4(vector->base_addr)
	      || GFC_UNALIGNED_4(field))
	    break;
	  else
	    {
	      unpack0_i4 ((gfc_array_i4 *) ret, (gfc_array_i4 *) vector,
			  mask, (GFC_INTEGER_4 *) field);
	      return;
	    }

	case 8:
	  if (GFC_UNALIGNED_8(ret->base_addr)
	      || GFC_UNALIGNED_8(vector->base_addr)
	      || GFC_UNALIGNED_8(field))
	    break;
	  else
	    {
	      unpack0_i8 ((gfc_array_i8 *) ret, (gfc_array_i8 *) vector,
			  mask, (GFC_INTEGER_8 *) field);
	      return;
	    }

#ifdef HAVE_GFC_INTEGER_16
	case 16:
	  if (GFC_UNALIGNED_16(ret->base_addr)
	      || GFC_UNALIGNED_16(vector->base_addr)
	      || GFC_UNALIGNED_16(field))
	    break;
	  else
	    {
	      unpack0_i16 ((gfc_array_i16 *) ret, (gfc_array_i16 *) vector,
			   mask, (GFC_INTEGER_16 *) field);
	      return;
	    }
#endif
      }
    }

  memset (&tmp, 0, sizeof (tmp));
  tmp.type = 0;
  tmp.base_addr = field;
  unpack_internal (ret, vector, mask, &tmp, GFC_DESCRIPTOR_ELEM_LEN (vector));
}


extern void unpack0_char (gfc_array_char *, GFC_INTEGER_4,
			  const gfc_array_char *, const gfc_array_l1 *,
			  char *, GFC_INTEGER_4, GFC_INTEGER_4);
export_proto(unpack0_char);

void
unpack0_char (gfc_array_char *ret,
	      GFC_INTEGER_4 ret_length __attribute__((unused)),
	      const gfc_array_char *vector, const gfc_array_l1 *mask,
	      char *field, GFC_INTEGER_4 vector_length,
	      GFC_INTEGER_4 field_length __attribute__((unused)))
{
  gfc_array_char tmp;

  if (unlikely(compile_options.bounds_check))
    unpack_bounds (ret, vector, mask, NULL);

  memset (&tmp, 0, sizeof (tmp));
  tmp.type = 0;
  tmp.base_addr = field;
  unpack_internal (ret, vector, mask, &tmp, vector_length);
}


extern void unpack0_char4 (gfc_array_char *, GFC_INTEGER_4,
			   const gfc_array_char *, const gfc_array_l1 *,
			   char *, GFC_INTEGER_4, GFC_INTEGER_4);
export_proto(unpack0_char4);

void
unpack0_char4 (gfc_array_char *ret,
	       GFC_INTEGER_4 ret_length __attribute__((unused)),
	       const gfc_array_char *vector, const gfc_array_l1 *mask,
	       char *field, GFC_INTEGER_4 vector_length,
	       GFC_INTEGER_4 field_length __attribute__((unused)))
{
  gfc_array_char tmp;

  if (unlikely(compile_options.bounds_check))
    unpack_bounds (ret, vector, mask, NULL);

  memset (&tmp, 0, sizeof (tmp));
  tmp.type = 0;
  tmp.base_addr = field;
  unpack_internal (ret, vector, mask, &tmp,
		   vector_length * sizeof (gfc_char4_t));
}
