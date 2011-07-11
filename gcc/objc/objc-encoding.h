/* Routines dealing with ObjC encoding of types
   Copyright (C) 1992, 1993, 1994, 1995, 1997, 1998, 1999, 2000, 2001,
   2002, 2003, 2004, 2005, 2007, 2008, 2009, 2010, 2011
   Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#ifndef GCC_OBJC_ENCODING_H
#define GCC_OBJC_ENCODING_H

/* TODO: Hide the following obstack code in objc-encoding.c, and have
   a objc_encoding_init() that is called by objc_init() to set them
   up.  */

/* Set up for use of obstacks.  */
#include "obstack.h"

/* This obstack is used to accumulate the encoding of a data type.  */
extern struct obstack util_obstack;

/* This points to the beginning of obstack contents, so we can free
   the whole contents.  */
extern char *util_firstobj;

/* This will be used to initialize the obstacks used by encoding.  It
   should be called before any encoding function is used.  It is
   usually done in objc_init().  */
/* extern void objc_encoding_init (void); */


/* Encode a method prototype.  The format is described in
   gcc/doc/objc.texi, section 'Method signatures'.  */
extern tree encode_method_prototype (tree method_decl);

/* This is used to implement @encode().  See gcc/doc/objc.texi,
   section '@encode'.  */
extern tree objc_build_encode_expr (tree type);

/* (Decide if these can ever be validly changed.)  */
#define OBJC_ENCODE_INLINE_DEFS		0
#define OBJC_ENCODE_DONT_INLINE_DEFS	1

/* Encode the attributes of a property.  */
extern tree objc_v2_encode_prop_attr (tree property);

/* Encode the type of a field.  */
extern void encode_field_decl (tree field_decl, int curtype, int format);

/* Tells "encode_pointer/encode_aggregate" whether we are generating
   type descriptors for instance variables (as opposed to methods).
   Type descriptors for instance variables contain more information
   than methods (for static typing and embedded structures).

   TODO: Replace this global variable with an argument that is passed
   to the various encode() functions.

   TODO: Change it to a 'bool'.  */
extern int generating_instance_variables;

#endif /* GCC_OBJC_ENCODING_H */
