/* Copyright (C) 2010, 2011 Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GCC is distributed in the hope that it will be useful,
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

#ifndef _X86INTRIN_H_INCLUDED
# error "Never use <bmi2intrin.h> directly; include <x86intrin.h> instead."
#endif

#ifndef __BMI2__
# error "BMI2 instruction set not enabled"
#endif /* __BMI2__ */

#ifndef _BMI2INTRIN_H_INCLUDED
#define _BMI2INTRIN_H_INCLUDED

extern __inline unsigned int
__attribute__((__gnu_inline__, __always_inline__, __artificial__))
_bzhi_u32 (unsigned int __X, unsigned int __Y)
{
  return __builtin_ia32_bzhi_si (__X, __Y);
}

extern __inline unsigned int
__attribute__((__gnu_inline__, __always_inline__, __artificial__))
_pdep_u32 (unsigned int __X, unsigned int __Y)
{
  return __builtin_ia32_pdep_si (__X, __Y);
}

extern __inline unsigned int
__attribute__((__gnu_inline__, __always_inline__, __artificial__))
_pext_u32 (unsigned int __X, unsigned int __Y)
{
  return __builtin_ia32_pext_si (__X, __Y);
}

#ifdef  __x86_64__

extern __inline unsigned long long
__attribute__((__gnu_inline__, __always_inline__, __artificial__))
_bzhi_u64 (unsigned long long __X, unsigned long long __Y)
{
  return __builtin_ia32_bzhi_di (__X, __Y);
}

extern __inline unsigned long long
__attribute__((__gnu_inline__, __always_inline__, __artificial__))
_pdep_u64 (unsigned long long __X, unsigned long long __Y)
{
  return __builtin_ia32_pdep_di (__X, __Y);
}

extern __inline unsigned long long
__attribute__((__gnu_inline__, __always_inline__, __artificial__))
_pext_u64 (unsigned long long __X, unsigned long long __Y)
{
  return __builtin_ia32_pext_di (__X, __Y);
}

#endif /* __x86_64__  */

#endif /* _BMI2INTRIN_H_INCLUDED */
