/* GCC MELT GENERATED FILE warmelt-normal+06.c - DO NOT EDIT */
/* secondary MELT generated C file of rank #6 */
#include "melt-run.h"


/* used hash from melt-run.h when compiling this file: */
MELT_EXTERN const char meltrun_used_md5_melt_f6[] =
  MELT_RUN_HASHMD5 /* from melt-run.h */ ;


/**** warmelt-normal+06.c declarations ****/
/**** MELT GENERATED DECLARATIONS for warmelt-normal ** DO NOT EDIT ; see gcc-melt.org ****/

/****++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
***
    Copyright 2008 - 2013 Free Software Foundation, Inc.
    Contributed by Basile Starynkevitch <basile@starynkevitch.net>

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
    <http://www.gnu.org/licenses/>.
***
----------------------------------------------------------------****/


/** ordinary MELT module meltbuild-sources/warmelt-normal**/
#define MELT_HAS_INITIAL_ENVIRONMENT 1	/*usualmodule */


/**** no MELT module variables ****/

/*** 3 MELT called hook declarations ***/

/*declare MELT called hook #0 HOOK_FRESH_ENVIRONMENT_REFERENCE_MAKER **/
MELT_EXTERN melt_ptr_t
melthook_HOOK_FRESH_ENVIRONMENT_REFERENCE_MAKER (melt_ptr_t melthookdata,
						 melt_ptr_t meltinp0_PREVENV,
						 const char
						 *meltinp1_MODULNAME);

/*declare MELT called hook #1 HOOK_SYMBOL_IMPORTER **/
MELT_EXTERN melt_ptr_t melthook_HOOK_SYMBOL_IMPORTER (melt_ptr_t melthookdata,
						      const char
						      *meltinp0_SYMNAMESTR,
						      const char
						      *meltinp1_MODULENAMESTR,
						      melt_ptr_t
						      meltinp2_PARENV);

/*declare MELT called hook #2 HOOK_VALUE_EXPORTER **/
MELT_EXTERN void melthook_HOOK_VALUE_EXPORTER (melt_ptr_t melthookdata,
					       melt_ptr_t meltinp0_SYM,
					       melt_ptr_t meltinp1_VAL,
					       melt_ptr_t meltinp2_CONTENV);

/*** end of 3 MELT called hook declarations ***/

/*** no extra MELT c-headers ***/




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_1_WARMELTmiNORMAL_NORMAL_IMPORT (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_2_WARMELTmiNORMAL_ADD_NCTX_DATA (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_3_WARMELTmiNORMAL_FILL_INITIAL_PREDEFMAP (meltclosure_ptr_t
						   meltclosp_,
						   melt_ptr_t meltfirstargp_,
						   const melt_argdescr_cell_t
						   meltxargdescr_[],
						   union meltparam_un
						   *meltxargtab_,
						   const melt_argdescr_cell_t
						   meltxresdescr_[],
						   union meltparam_un
						   *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_4_WARMELTmiNORMAL_REGISTER_LITERAL_VALUE (meltclosure_ptr_t
						   meltclosp_,
						   melt_ptr_t meltfirstargp_,
						   const melt_argdescr_cell_t
						   meltxargdescr_[],
						   union meltparam_un
						   *meltxargtab_,
						   const melt_argdescr_cell_t
						   meltxresdescr_[],
						   union meltparam_un
						   *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_5_WARMELTmiNORMAL_CREATE_NORMCONTEXT (meltclosure_ptr_t meltclosp_,
					       melt_ptr_t meltfirstargp_,
					       const melt_argdescr_cell_t
					       meltxargdescr_[],
					       union meltparam_un
					       *meltxargtab_,
					       const melt_argdescr_cell_t
					       meltxresdescr_[],
					       union meltparam_un
					       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_6_WARMELTmiNORMAL_CREATE_NORMAL_EXTENDING_CONTEXT (meltclosure_ptr_t
							    meltclosp_,
							    melt_ptr_t
							    meltfirstargp_,
							    const
							    melt_argdescr_cell_t
							    meltxargdescr_[],
							    union meltparam_un
							    *meltxargtab_,
							    const
							    melt_argdescr_cell_t
							    meltxresdescr_[],
							    union meltparam_un
							    *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_7_WARMELTmiNORMAL_NORMEXP_IDENTICAL (meltclosure_ptr_t meltclosp_,
					      melt_ptr_t meltfirstargp_,
					      const melt_argdescr_cell_t
					      meltxargdescr_[],
					      union meltparam_un
					      *meltxargtab_,
					      const melt_argdescr_cell_t
					      meltxresdescr_[],
					      union meltparam_un
					      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_8_WARMELTmiNORMAL_NORMEXP_NULL (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_9_WARMELTmiNORMAL_NORMEXP_ANY_OBJECT (meltclosure_ptr_t meltclosp_,
					       melt_ptr_t meltfirstargp_,
					       const melt_argdescr_cell_t
					       meltxargdescr_[],
					       union meltparam_un
					       *meltxargtab_,
					       const melt_argdescr_cell_t
					       meltxresdescr_[],
					       union meltparam_un
					       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_10_WARMELTmiNORMAL_NORMEXP_ANY_VALUE (meltclosure_ptr_t meltclosp_,
					       melt_ptr_t meltfirstargp_,
					       const melt_argdescr_cell_t
					       meltxargdescr_[],
					       union meltparam_un
					       *meltxargtab_,
					       const melt_argdescr_cell_t
					       meltxresdescr_[],
					       union meltparam_un
					       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_11_WARMELTmiNORMAL_NORMEXP_SRC_CATCHALL (meltclosure_ptr_t
						  meltclosp_,
						  melt_ptr_t meltfirstargp_,
						  const melt_argdescr_cell_t
						  meltxargdescr_[],
						  union meltparam_un
						  *meltxargtab_,
						  const melt_argdescr_cell_t
						  meltxresdescr_[],
						  union meltparam_un
						  *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_12_WARMELTmiNORMAL_NORMEXP_LAZYMACROEXP (meltclosure_ptr_t
						  meltclosp_,
						  melt_ptr_t meltfirstargp_,
						  const melt_argdescr_cell_t
						  meltxargdescr_[],
						  union meltparam_un
						  *meltxargtab_,
						  const melt_argdescr_cell_t
						  meltxresdescr_[],
						  union meltparam_un
						  *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_13_WARMELTmiNORMAL_GECTYP_ANYRECV (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_14_WARMELTmiNORMAL_GECTYP_ROOT (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_15_WARMELTmiNORMAL_GECTYP_INTEGER (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_16_WARMELTmiNORMAL_GECTYP_STRING (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_17_WARMELTmiNORMAL_NORMALIZE_TUPLE (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_18_WARMELTmiNORMAL_LAMBDA_cl1 (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_19_WARMELTmiNORMAL_WRAP_NORMAL_LET1 (meltclosure_ptr_t meltclosp_,
					      melt_ptr_t meltfirstargp_,
					      const melt_argdescr_cell_t
					      meltxargdescr_[],
					      union meltparam_un
					      *meltxargtab_,
					      const melt_argdescr_cell_t
					      meltxresdescr_[],
					      union meltparam_un
					      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_20_WARMELTmiNORMAL_LAMBDA_cl2 (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_21_WARMELTmiNORMAL_WRAP_NORMAL_LETSEQ (meltclosure_ptr_t meltclosp_,
						melt_ptr_t meltfirstargp_,
						const melt_argdescr_cell_t
						meltxargdescr_[],
						union meltparam_un
						*meltxargtab_,
						const melt_argdescr_cell_t
						meltxresdescr_[],
						union meltparam_un
						*meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_22_WARMELTmiNORMAL_LAMBDA_cl3 (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_23_WARMELTmiNORMAL_CHECK_CTYPE_NARGS (meltclosure_ptr_t meltclosp_,
					       melt_ptr_t meltfirstargp_,
					       const melt_argdescr_cell_t
					       meltxargdescr_[],
					       union meltparam_un
					       *meltxargtab_,
					       const melt_argdescr_cell_t
					       meltxresdescr_[],
					       union meltparam_un
					       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_24_WARMELTmiNORMAL_LAMBDA_cl4 (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_25_WARMELTmiNORMAL_NORMBIND_FAILANY (meltclosure_ptr_t meltclosp_,
					      melt_ptr_t meltfirstargp_,
					      const melt_argdescr_cell_t
					      meltxargdescr_[],
					      union meltparam_un
					      *meltxargtab_,
					      const melt_argdescr_cell_t
					      meltxresdescr_[],
					      union meltparam_un
					      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_26_WARMELTmiNORMAL_NORMBIND_ANYBIND (meltclosure_ptr_t meltclosp_,
					      melt_ptr_t meltfirstargp_,
					      const melt_argdescr_cell_t
					      meltxargdescr_[],
					      union meltparam_un
					      *meltxargtab_,
					      const melt_argdescr_cell_t
					      meltxresdescr_[],
					      union meltparam_un
					      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_27_WARMELTmiNORMAL_NORMBIND_FORMALBIND (meltclosure_ptr_t meltclosp_,
						 melt_ptr_t meltfirstargp_,
						 const melt_argdescr_cell_t
						 meltxargdescr_[],
						 union meltparam_un
						 *meltxargtab_,
						 const melt_argdescr_cell_t
						 meltxresdescr_[],
						 union meltparam_un
						 *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_28_WARMELTmiNORMAL_NORMBIND_LETBIND (meltclosure_ptr_t meltclosp_,
					      melt_ptr_t meltfirstargp_,
					      const melt_argdescr_cell_t
					      meltxargdescr_[],
					      union meltparam_un
					      *meltxargtab_,
					      const melt_argdescr_cell_t
					      meltxresdescr_[],
					      union meltparam_un
					      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_29_WARMELTmiNORMAL_NORMBIND_FIXBIND (meltclosure_ptr_t meltclosp_,
					      melt_ptr_t meltfirstargp_,
					      const melt_argdescr_cell_t
					      meltxargdescr_[],
					      union meltparam_un
					      *meltxargtab_,
					      const melt_argdescr_cell_t
					      meltxresdescr_[],
					      union meltparam_un
					      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_30_WARMELTmiNORMAL_NORMBIND_DEFINEDVALBIND (meltclosure_ptr_t
						     meltclosp_,
						     melt_ptr_t
						     meltfirstargp_,
						     const
						     melt_argdescr_cell_t
						     meltxargdescr_[],
						     union meltparam_un
						     *meltxargtab_,
						     const
						     melt_argdescr_cell_t
						     meltxresdescr_[],
						     union meltparam_un
						     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_31_WARMELTmiNORMAL_NORMBIND_CONSTRUCTBIND (meltclosure_ptr_t
						    meltclosp_,
						    melt_ptr_t meltfirstargp_,
						    const melt_argdescr_cell_t
						    meltxargdescr_[],
						    union meltparam_un
						    *meltxargtab_,
						    const melt_argdescr_cell_t
						    meltxresdescr_[],
						    union meltparam_un
						    *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_32_WARMELTmiNORMAL_NORMEXP_SYMBOL (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_33_WARMELTmiNORMAL_GECTYP_SYMOCC (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_34_WARMELTmiNORMAL_GECTYP_MODVAROCC (meltclosure_ptr_t meltclosp_,
					      melt_ptr_t meltfirstargp_,
					      const melt_argdescr_cell_t
					      meltxargdescr_[],
					      union meltparam_un
					      *meltxargtab_,
					      const melt_argdescr_cell_t
					      meltxresdescr_[],
					      union meltparam_un
					      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_35_WARMELTmiNORMAL_NORMEXP_CLASS (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_36_WARMELTmiNORMAL_NORMEXP_PRIMITIVE (meltclosure_ptr_t meltclosp_,
					       melt_ptr_t meltfirstargp_,
					       const melt_argdescr_cell_t
					       meltxargdescr_[],
					       union meltparam_un
					       *meltxargtab_,
					       const melt_argdescr_cell_t
					       meltxresdescr_[],
					       union meltparam_un
					       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_37_WARMELTmiNORMAL_NORMEXP_HOOK_CALL (meltclosure_ptr_t meltclosp_,
					       melt_ptr_t meltfirstargp_,
					       const melt_argdescr_cell_t
					       meltxargdescr_[],
					       union meltparam_un
					       *meltxargtab_,
					       const melt_argdescr_cell_t
					       meltxresdescr_[],
					       union meltparam_un
					       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_38_WARMELTmiNORMAL_NORMEXP_BOX (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_39_WARMELTmiNORMAL_NORMEXP_CONSTBOX (meltclosure_ptr_t meltclosp_,
					      melt_ptr_t meltfirstargp_,
					      const melt_argdescr_cell_t
					      meltxargdescr_[],
					      union meltparam_un
					      *meltxargtab_,
					      const melt_argdescr_cell_t
					      meltxresdescr_[],
					      union meltparam_un
					      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_40_WARMELTmiNORMAL_NORMEXP_UNBOX (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_41_WARMELTmiNORMAL_NORMEXP_CODE_CHUNK (meltclosure_ptr_t meltclosp_,
						melt_ptr_t meltfirstargp_,
						const melt_argdescr_cell_t
						meltxargdescr_[],
						union meltparam_un
						*meltxargtab_,
						const melt_argdescr_cell_t
						meltxresdescr_[],
						union meltparam_un
						*meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_42_WARMELTmiNORMAL_LAMBDA_cl5 (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_43_WARMELTmiNORMAL_NORMEXP_EXPR_CHUNK (meltclosure_ptr_t meltclosp_,
						melt_ptr_t meltfirstargp_,
						const melt_argdescr_cell_t
						meltxargdescr_[],
						union meltparam_un
						*meltxargtab_,
						const melt_argdescr_cell_t
						meltxresdescr_[],
						union meltparam_un
						*meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_44_WARMELTmiNORMAL_NORMEXP_CMATCHEXPR (meltclosure_ptr_t meltclosp_,
						melt_ptr_t meltfirstargp_,
						const melt_argdescr_cell_t
						meltxargdescr_[],
						union meltparam_un
						*meltxargtab_,
						const melt_argdescr_cell_t
						meltxresdescr_[],
						union meltparam_un
						*meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_45_WARMELTmiNORMAL_LAMBDA_cl6 (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_46_WARMELTmiNORMAL_LAMBDA_cl7 (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_47_WARMELTmiNORMAL_NORMEXP_FUNMATCHEXPR (meltclosure_ptr_t
						  meltclosp_,
						  melt_ptr_t meltfirstargp_,
						  const melt_argdescr_cell_t
						  meltxargdescr_[],
						  union meltparam_un
						  *meltxargtab_,
						  const melt_argdescr_cell_t
						  meltxresdescr_[],
						  union meltparam_un
						  *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_48_WARMELTmiNORMAL_NORMEXP_APPLY (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_49_WARMELTmiNORMAL_NORMEXP_MSEND (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_50_WARMELTmiNORMAL_NORMEXP_RETURN (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_51_WARMELTmiNORMAL_NORMEXP_IF (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_52_WARMELTmiNORMAL_LAMBDA_cl8 (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_53_WARMELTmiNORMAL_NORMEXP_IFELSE (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_54_WARMELTmiNORMAL_LAMBDA_cl9 (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_55_WARMELTmiNORMAL_LAMBDA_cl10 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_56_WARMELTmiNORMAL_NORMEXP_CPPIF (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_57_WARMELTmiNORMAL_LAMBDA_cl11 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_58_WARMELTmiNORMAL_LAMBDA_cl12 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_59_WARMELTmiNORMAL_NORMEXP_OR (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_60_WARMELTmiNORMAL_LAMBDA_cl13 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_61_WARMELTmiNORMAL_LAMBDA_cl14 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_62_WARMELTmiNORMAL_NORMEXP_PROGN (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_63_WARMELTmiNORMAL_LAMBDA_cl15 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_64_WARMELTmiNORMAL_NORMEXP_LET (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_65_WARMELTmiNORMAL_LAMBDA_cl16 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_66_WARMELTmiNORMAL_LAMBDA_cl17 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_67_WARMELTmiNORMAL_NORMEXP_UNSAFE_GET_FIELD (meltclosure_ptr_t
						      meltclosp_,
						      melt_ptr_t
						      meltfirstargp_,
						      const
						      melt_argdescr_cell_t
						      meltxargdescr_[],
						      union meltparam_un
						      *meltxargtab_,
						      const
						      melt_argdescr_cell_t
						      meltxresdescr_[],
						      union meltparam_un
						      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_68_WARMELTmiNORMAL_NORMEXP_GET_FIELD (meltclosure_ptr_t meltclosp_,
					       melt_ptr_t meltfirstargp_,
					       const melt_argdescr_cell_t
					       meltxargdescr_[],
					       union meltparam_un
					       *meltxargtab_,
					       const melt_argdescr_cell_t
					       meltxresdescr_[],
					       union meltparam_un
					       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_69_WARMELTmiNORMAL_NORMEXP_UNSAFE_PUT_FIELDS (meltclosure_ptr_t
						       meltclosp_,
						       melt_ptr_t
						       meltfirstargp_,
						       const
						       melt_argdescr_cell_t
						       meltxargdescr_[],
						       union meltparam_un
						       *meltxargtab_,
						       const
						       melt_argdescr_cell_t
						       meltxresdescr_[],
						       union meltparam_un
						       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_70_WARMELTmiNORMAL_LAMBDA_cl18 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_71_WARMELTmiNORMAL_LAMBDA_cl19 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_72_WARMELTmiNORMAL_NORMEXP_PUT_FIELDS (meltclosure_ptr_t meltclosp_,
						melt_ptr_t meltfirstargp_,
						const melt_argdescr_cell_t
						meltxargdescr_[],
						union meltparam_un
						*meltxargtab_,
						const melt_argdescr_cell_t
						meltxresdescr_[],
						union meltparam_un
						*meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_73_WARMELTmiNORMAL_NORMEXP_SETQ (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_74_WARMELTmiNORMAL_LAMBDA_cl20 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_75_WARMELTmiNORMAL_NORMEXP_INSTANCE (meltclosure_ptr_t meltclosp_,
					      melt_ptr_t meltfirstargp_,
					      const melt_argdescr_cell_t
					      meltxargdescr_[],
					      union meltparam_un
					      *meltxargtab_,
					      const melt_argdescr_cell_t
					      meltxresdescr_[],
					      union meltparam_un
					      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_76_WARMELTmiNORMAL_LAMBDA_cl21 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_77_WARMELTmiNORMAL_LAMBDA_cl22 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_78_WARMELTmiNORMAL_NORMEXP_FOREVER (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_79_WARMELTmiNORMAL_NORMEXP_EXIT (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_80_WARMELTmiNORMAL_NORMEXP_AGAIN (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_81_WARMELTmiNORMAL_NORMEXP_IFVARIADIC (meltclosure_ptr_t meltclosp_,
						melt_ptr_t meltfirstargp_,
						const melt_argdescr_cell_t
						meltxargdescr_[],
						union meltparam_un
						*meltxargtab_,
						const melt_argdescr_cell_t
						meltxresdescr_[],
						union meltparam_un
						*meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_82_WARMELTmiNORMAL_NORMEXP_COMPILEWARNING (meltclosure_ptr_t
						    meltclosp_,
						    melt_ptr_t meltfirstargp_,
						    const melt_argdescr_cell_t
						    meltxargdescr_[],
						    union meltparam_un
						    *meltxargtab_,
						    const melt_argdescr_cell_t
						    meltxresdescr_[],
						    union meltparam_un
						    *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_83_WARMELTmiNORMAL_LAMBDA_cl23 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_84_WARMELTmiNORMAL_REPLACE_LAST_BY_RETURN (meltclosure_ptr_t
						    meltclosp_,
						    melt_ptr_t meltfirstargp_,
						    const melt_argdescr_cell_t
						    meltxargdescr_[],
						    union meltparam_un
						    *meltxargtab_,
						    const melt_argdescr_cell_t
						    meltxresdescr_[],
						    union meltparam_un
						    *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_85_WARMELTmiNORMAL_LAMBDA_cl24 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_86_WARMELTmiNORMAL_NORMEXP_DEFUN (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_87_WARMELTmiNORMAL_LAMBDA_cl25 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_88_WARMELTmiNORMAL_LAMBDA_cl26 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_89_WARMELTmiNORMAL_NORMEXP_DEFHOOK (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_90_WARMELTmiNORMAL_LAMBDA_cl27 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_91_WARMELTmiNORMAL_NORMALIZE_LAMBDA (meltclosure_ptr_t meltclosp_,
					      melt_ptr_t meltfirstargp_,
					      const melt_argdescr_cell_t
					      meltxargdescr_[],
					      union meltparam_un
					      *meltxargtab_,
					      const melt_argdescr_cell_t
					      meltxresdescr_[],
					      union meltparam_un
					      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_92_WARMELTmiNORMAL_LAMBDA_cl28 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_93_WARMELTmiNORMAL_NORMEXP_LAMBDA (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_94_WARMELTmiNORMAL_NORMEXP_MULTICALL (meltclosure_ptr_t meltclosp_,
					       melt_ptr_t meltfirstargp_,
					       const melt_argdescr_cell_t
					       meltxargdescr_[],
					       union meltparam_un
					       *meltxargtab_,
					       const melt_argdescr_cell_t
					       meltxresdescr_[],
					       union meltparam_un
					       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_95_WARMELTmiNORMAL_LAMBDA_cl29 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_96_WARMELTmiNORMAL_LAMBDA_cl30 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_97_WARMELTmiNORMAL_LAMBDA_cl31 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_98_WARMELTmiNORMAL_NORMEXP_TUPLE (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_99_WARMELTmiNORMAL_NORMEXP_LIST (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_100_WARMELTmiNORMAL_LAMBDA_cl32 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_101_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_102_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_103_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_104_WARMELTmiNORMAL_PREPCONS_LAMBDA (meltclosure_ptr_t meltclosp_,
					      melt_ptr_t meltfirstargp_,
					      const melt_argdescr_cell_t
					      meltxargdescr_[],
					      union meltparam_un
					      *meltxargtab_,
					      const melt_argdescr_cell_t
					      meltxresdescr_[],
					      union meltparam_un
					      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_105_WARMELTmiNORMAL_NORMLETREC_LAMBDA (meltclosure_ptr_t meltclosp_,
						melt_ptr_t meltfirstargp_,
						const melt_argdescr_cell_t
						meltxargdescr_[],
						union meltparam_un
						*meltxargtab_,
						const melt_argdescr_cell_t
						meltxresdescr_[],
						union meltparam_un
						*meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_106_WARMELTmiNORMAL_PREPCONS_TUPLE (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_107_WARMELTmiNORMAL_NORMLETREC_TUPLE (meltclosure_ptr_t meltclosp_,
					       melt_ptr_t meltfirstargp_,
					       const melt_argdescr_cell_t
					       meltxargdescr_[],
					       union meltparam_un
					       *meltxargtab_,
					       const melt_argdescr_cell_t
					       meltxresdescr_[],
					       union meltparam_un
					       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_108_WARMELTmiNORMAL_PREPCONS_LIST (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_109_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM (meltclosure_ptr_t
						   meltclosp_,
						   melt_ptr_t meltfirstargp_,
						   const melt_argdescr_cell_t
						   meltxargdescr_[],
						   union meltparam_un
						   *meltxargtab_,
						   const melt_argdescr_cell_t
						   meltxresdescr_[],
						   union meltparam_un
						   *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_110_WARMELTmiNORMAL_NORMLETREC_LIST (meltclosure_ptr_t meltclosp_,
					      melt_ptr_t meltfirstargp_,
					      const melt_argdescr_cell_t
					      meltxargdescr_[],
					      union meltparam_un
					      *meltxargtab_,
					      const melt_argdescr_cell_t
					      meltxresdescr_[],
					      union meltparam_un
					      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_111_WARMELTmiNORMAL_PREPCONS_INSTANCE (meltclosure_ptr_t meltclosp_,
						melt_ptr_t meltfirstargp_,
						const melt_argdescr_cell_t
						meltxargdescr_[],
						union meltparam_un
						*meltxargtab_,
						const melt_argdescr_cell_t
						meltxresdescr_[],
						union meltparam_un
						*meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_112_WARMELTmiNORMAL_NORMLETREC_INSTANCE (meltclosure_ptr_t
						  meltclosp_,
						  melt_ptr_t meltfirstargp_,
						  const melt_argdescr_cell_t
						  meltxargdescr_[],
						  union meltparam_un
						  *meltxargtab_,
						  const melt_argdescr_cell_t
						  meltxresdescr_[],
						  union meltparam_un
						  *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_113_WARMELTmiNORMAL_LAMBDA_cl33 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_114_WARMELTmiNORMAL_NORMEXP_LETREC (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_115_WARMELTmiNORMAL_NORMAL_PREDEF (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_116_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA (meltclosure_ptr_t meltclosp_,
						 melt_ptr_t meltfirstargp_,
						 const melt_argdescr_cell_t
						 meltxargdescr_[],
						 union meltparam_un
						 *meltxargtab_,
						 const melt_argdescr_cell_t
						 meltxresdescr_[],
						 union meltparam_un
						 *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_117_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA (meltclosure_ptr_t
						  meltclosp_,
						  melt_ptr_t meltfirstargp_,
						  const melt_argdescr_cell_t
						  meltxargdescr_[],
						  union meltparam_un
						  *meltxargtab_,
						  const melt_argdescr_cell_t
						  meltxresdescr_[],
						  union meltparam_un
						  *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_118_WARMELTmiNORMAL_CREATE_DATA_SLOTS (meltclosure_ptr_t meltclosp_,
						melt_ptr_t meltfirstargp_,
						const melt_argdescr_cell_t
						meltxargdescr_[],
						union meltparam_un
						*meltxargtab_,
						const melt_argdescr_cell_t
						meltxresdescr_[],
						union meltparam_un
						*meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_119_WARMELTmiNORMAL_FILL_DATA_SLOT (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_120_WARMELTmiNORMAL_NORMEXP_QUOTE (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_121_WARMELTmiNORMAL_NORMEXP_COMMENT (meltclosure_ptr_t meltclosp_,
					      melt_ptr_t meltfirstargp_,
					      const melt_argdescr_cell_t
					      meltxargdescr_[],
					      union meltparam_un
					      *meltxargtab_,
					      const melt_argdescr_cell_t
					      meltxresdescr_[],
					      union meltparam_un
					      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_122_WARMELTmiNORMAL_NORMEXP_KEYWORD (meltclosure_ptr_t meltclosp_,
					      melt_ptr_t meltfirstargp_,
					      const melt_argdescr_cell_t
					      meltxargdescr_[],
					      union meltparam_un
					      *meltxargtab_,
					      const melt_argdescr_cell_t
					      meltxresdescr_[],
					      union meltparam_un
					      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_123_WARMELTmiNORMAL_FILL_NORMAL_FORMALBIND (meltclosure_ptr_t
						     meltclosp_,
						     melt_ptr_t
						     meltfirstargp_,
						     const
						     melt_argdescr_cell_t
						     meltxargdescr_[],
						     union meltparam_un
						     *meltxargtab_,
						     const
						     melt_argdescr_cell_t
						     meltxresdescr_[],
						     union meltparam_un
						     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_124_WARMELTmiNORMAL_FILL_NORMAL_FORMALS (meltclosure_ptr_t
						  meltclosp_,
						  melt_ptr_t meltfirstargp_,
						  const melt_argdescr_cell_t
						  meltxargdescr_[],
						  union meltparam_un
						  *meltxargtab_,
						  const melt_argdescr_cell_t
						  meltxresdescr_[],
						  union meltparam_un
						  *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_125_WARMELTmiNORMAL_FILL_NORMAL_EXPANSION (meltclosure_ptr_t
						    meltclosp_,
						    melt_ptr_t meltfirstargp_,
						    const melt_argdescr_cell_t
						    meltxargdescr_[],
						    union meltparam_un
						    *meltxargtab_,
						    const melt_argdescr_cell_t
						    meltxresdescr_[],
						    union meltparam_un
						    *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_126_WARMELTmiNORMAL_LAMBDA_cl34 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_127_WARMELTmiNORMAL_NORMEXP_DEFPRIMITIVE (meltclosure_ptr_t
						   meltclosp_,
						   melt_ptr_t meltfirstargp_,
						   const melt_argdescr_cell_t
						   meltxargdescr_[],
						   union meltparam_un
						   *meltxargtab_,
						   const melt_argdescr_cell_t
						   meltxresdescr_[],
						   union meltparam_un
						   *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_128_WARMELTmiNORMAL_NORMEXP_DEFCITERATOR (meltclosure_ptr_t
						   meltclosp_,
						   melt_ptr_t meltfirstargp_,
						   const melt_argdescr_cell_t
						   meltxargdescr_[],
						   union meltparam_un
						   *meltxargtab_,
						   const melt_argdescr_cell_t
						   meltxresdescr_[],
						   union meltparam_un
						   *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_129_WARMELTmiNORMAL_NORMEXP_CITERATION (meltclosure_ptr_t meltclosp_,
						 melt_ptr_t meltfirstargp_,
						 const melt_argdescr_cell_t
						 meltxargdescr_[],
						 union meltparam_un
						 *meltxargtab_,
						 const melt_argdescr_cell_t
						 meltxresdescr_[],
						 union meltparam_un
						 *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_130_WARMELTmiNORMAL_LAMBDA_cl35 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_131_WARMELTmiNORMAL_LAMBDA_cl36 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_132_WARMELTmiNORMAL_LAMBDA_cl37 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_133_WARMELTmiNORMAL_LAMBDA_cl38 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_134_WARMELTmiNORMAL_LAMBDA_cl39 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_135_WARMELTmiNORMAL_LAMBDA_cl40 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_136_WARMELTmiNORMAL_LAMBDA_cl41 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_137_WARMELTmiNORMAL_NORMEXP_DEFCMATCHER (meltclosure_ptr_t
						  meltclosp_,
						  melt_ptr_t meltfirstargp_,
						  const melt_argdescr_cell_t
						  meltxargdescr_[],
						  union meltparam_un
						  *meltxargtab_,
						  const melt_argdescr_cell_t
						  meltxresdescr_[],
						  union meltparam_un
						  *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_138_WARMELTmiNORMAL_NORMEXP_DEFUNMATCHER (meltclosure_ptr_t
						   meltclosp_,
						   melt_ptr_t meltfirstargp_,
						   const melt_argdescr_cell_t
						   meltxargdescr_[],
						   union meltparam_un
						   *meltxargtab_,
						   const melt_argdescr_cell_t
						   meltxresdescr_[],
						   union meltparam_un
						   *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_139_WARMELTmiNORMAL_NORMEXP_DEFCLASS (meltclosure_ptr_t meltclosp_,
					       melt_ptr_t meltfirstargp_,
					       const melt_argdescr_cell_t
					       meltxargdescr_[],
					       union meltparam_un
					       *meltxargtab_,
					       const melt_argdescr_cell_t
					       meltxresdescr_[],
					       union meltparam_un
					       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_140_WARMELTmiNORMAL_NORMEXP_DEFINSTANCE (meltclosure_ptr_t
						  meltclosp_,
						  melt_ptr_t meltfirstargp_,
						  const melt_argdescr_cell_t
						  meltxargdescr_[],
						  union meltparam_un
						  *meltxargtab_,
						  const melt_argdescr_cell_t
						  meltxresdescr_[],
						  union meltparam_un
						  *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_141_WARMELTmiNORMAL_LAMBDA_cl42 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_142_WARMELTmiNORMAL_NORMEXP_DEFVAR (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_143_WARMELTmiNORMAL_NORMEXP_DEFINE (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_144_WARMELTmiNORMAL_LAMBDA_cl43 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_145_WARMELTmiNORMAL_NORMEXP_DEFSELECTOR (meltclosure_ptr_t
						  meltclosp_,
						  melt_ptr_t meltfirstargp_,
						  const melt_argdescr_cell_t
						  meltxargdescr_[],
						  union meltparam_un
						  *meltxargtab_,
						  const melt_argdescr_cell_t
						  meltxresdescr_[],
						  union meltparam_un
						  *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_146_WARMELTmiNORMAL_LAMBDA_cl44 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_147_WARMELTmiNORMAL_NORMAL_EXPORTED_VALUE (meltclosure_ptr_t
						    meltclosp_,
						    melt_ptr_t meltfirstargp_,
						    const melt_argdescr_cell_t
						    meltxargdescr_[],
						    union meltparam_un
						    *meltxargtab_,
						    const melt_argdescr_cell_t
						    meltxresdescr_[],
						    union meltparam_un
						    *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_148_WARMELTmiNORMAL_NORMEXP_EXPORT_VALUES (meltclosure_ptr_t
						    meltclosp_,
						    melt_ptr_t meltfirstargp_,
						    const melt_argdescr_cell_t
						    meltxargdescr_[],
						    union meltparam_un
						    *meltxargtab_,
						    const melt_argdescr_cell_t
						    meltxresdescr_[],
						    union meltparam_un
						    *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_149_WARMELTmiNORMAL_NORMEXP_EXPORT_SYNONYM (meltclosure_ptr_t
						     meltclosp_,
						     melt_ptr_t
						     meltfirstargp_,
						     const
						     melt_argdescr_cell_t
						     meltxargdescr_[],
						     union meltparam_un
						     *meltxargtab_,
						     const
						     melt_argdescr_cell_t
						     meltxresdescr_[],
						     union meltparam_un
						     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_150_WARMELTmiNORMAL_NORMEXP_EXPORT_CLASS (meltclosure_ptr_t
						   meltclosp_,
						   melt_ptr_t meltfirstargp_,
						   const melt_argdescr_cell_t
						   meltxargdescr_[],
						   union meltparam_un
						   *meltxargtab_,
						   const melt_argdescr_cell_t
						   meltxresdescr_[],
						   union meltparam_un
						   *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_151_WARMELTmiNORMAL_LAMBDA_cl45 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_152_WARMELTmiNORMAL_LAMBDA_cl46 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_153_WARMELTmiNORMAL_NORMAL_EXPORTED_MACRO (meltclosure_ptr_t
						    meltclosp_,
						    melt_ptr_t meltfirstargp_,
						    const melt_argdescr_cell_t
						    meltxargdescr_[],
						    union meltparam_un
						    *meltxargtab_,
						    const melt_argdescr_cell_t
						    meltxresdescr_[],
						    union meltparam_un
						    *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_154_WARMELTmiNORMAL_NORMEXP_EXPORT_MACRO (meltclosure_ptr_t
						   meltclosp_,
						   melt_ptr_t meltfirstargp_,
						   const melt_argdescr_cell_t
						   meltxargdescr_[],
						   union meltparam_un
						   *meltxargtab_,
						   const melt_argdescr_cell_t
						   meltxresdescr_[],
						   union meltparam_un
						   *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_155_WARMELTmiNORMAL_NORMAL_EXPORTED_PATMACRO (meltclosure_ptr_t
						       meltclosp_,
						       melt_ptr_t
						       meltfirstargp_,
						       const
						       melt_argdescr_cell_t
						       meltxargdescr_[],
						       union meltparam_un
						       *meltxargtab_,
						       const
						       melt_argdescr_cell_t
						       meltxresdescr_[],
						       union meltparam_un
						       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_156_WARMELTmiNORMAL_NORMEXP_EXPORT_PATMACRO (meltclosure_ptr_t
						      meltclosp_,
						      melt_ptr_t
						      meltfirstargp_,
						      const
						      melt_argdescr_cell_t
						      meltxargdescr_[],
						      union meltparam_un
						      *meltxargtab_,
						      const
						      melt_argdescr_cell_t
						      meltxresdescr_[],
						      union meltparam_un
						      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_157_WARMELTmiNORMAL_NORMEXP_CURRENT_MODULE_ENVIRONMENT_REFERENCE
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_158_WARMELTmiNORMAL_NORMEXP_PARENT_MODULE_ENVIRONMENT
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_159_WARMELTmiNORMAL_NORMEXP_UPDATE_CURRENT_MODULE_ENVIRONMENT_REFERENCE
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_160_WARMELTmiNORMAL_NORMEXP_FETCH_PREDEFINED (meltclosure_ptr_t
						       meltclosp_,
						       melt_ptr_t
						       meltfirstargp_,
						       const
						       melt_argdescr_cell_t
						       meltxargdescr_[],
						       union meltparam_un
						       *meltxargtab_,
						       const
						       melt_argdescr_cell_t
						       meltxresdescr_[],
						       union meltparam_un
						       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_161_WARMELTmiNORMAL_LAMBDA_cl47 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_162_WARMELTmiNORMAL_NORMEXP_STORE_PREDEFINED (meltclosure_ptr_t
						       meltclosp_,
						       melt_ptr_t
						       meltfirstargp_,
						       const
						       melt_argdescr_cell_t
						       meltxargdescr_[],
						       union meltparam_un
						       *meltxargtab_,
						       const
						       melt_argdescr_cell_t
						       meltxresdescr_[],
						       union meltparam_un
						       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_163_WARMELTmiNORMAL_LAMBDA_cl48 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_164_WARMELTmiNORMAL_NORMEXP_CHEADER (meltclosure_ptr_t meltclosp_,
					      melt_ptr_t meltfirstargp_,
					      const melt_argdescr_cell_t
					      meltxargdescr_[],
					      union meltparam_un
					      *meltxargtab_,
					      const melt_argdescr_cell_t
					      meltxresdescr_[],
					      union meltparam_un
					      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_165_WARMELTmiNORMAL_NORMEXP_CIMPLEMENT (meltclosure_ptr_t meltclosp_,
						 melt_ptr_t meltfirstargp_,
						 const melt_argdescr_cell_t
						 meltxargdescr_[],
						 union meltparam_un
						 *meltxargtab_,
						 const melt_argdescr_cell_t
						 meltxresdescr_[],
						 union meltparam_un
						 *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_166_WARMELTmiNORMAL_NORMEXP_USE_PACKAGE_FROM_PKG_CONFIG
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);



MELT_EXTERN void *melt_start_this_module (void *);
struct melt_initial_frame_st;

/*declare opaque initial frame: */
typedef struct melt_initial_frame_st meltinitial_frame_t;


/* define different names when debugging or not */
#if MELT_HAVE_DEBUG
MELT_EXTERN const char meltmodule_WARMELTmiNORMAL__melt_have_debug_enabled[];
#define melt_have_debug_string meltmodule_WARMELTmiNORMAL__melt_have_debug_enabled
#else /*!MELT_HAVE_DEBUG */
MELT_EXTERN const char meltmodule_WARMELTmiNORMAL__melt_have_debug_disabled[];
#define melt_have_debug_string meltmodule_WARMELTmiNORMAL__melt_have_debug_disabled
#endif /*!MELT_HAVE_DEBUG */



void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_0 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_1 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_2 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_3 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_4 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_5 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_6 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_7 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_8 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_9 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_10 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_11 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_12 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_13 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_14 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_15 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_16 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_17 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_18 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_19 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_20 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_21 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_22 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_23 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_24 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_25 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_26 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_27 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_28 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_29 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_30 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_31 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_32 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_33 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_34 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_35 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_36 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_37 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_38 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_39 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_40 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_41 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_42 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_43 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_44 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_45 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_46 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_47 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_48 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_49 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_50 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_51 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_52 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_53 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_54 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_55 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_56 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__forward_or_mark_module_start_frame (struct
							      melt_callframe_st
							      *fp,
							      int marking);



/**** warmelt-normal+06.c implementations ****/




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_154_WARMELTmiNORMAL_NORMEXP_EXPORT_MACRO (meltclosure_ptr_t
						   meltclosp_,
						   melt_ptr_t meltfirstargp_,
						   const melt_argdescr_cell_t
						   meltxargdescr_[],
						   union meltparam_un
						   *meltxargtab_,
						   const melt_argdescr_cell_t
						   meltxresdescr_[],
						   union meltparam_un
						   *meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_154_WARMELTmiNORMAL_NORMEXP_EXPORT_MACRO_melt
    = melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_154_WARMELTmiNORMAL_NORMEXP_EXPORT_MACRO_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 32
    melt_ptr_t mcfr_varptr[32];
#define MELTFRAM_NBVARNUM 10
    long mcfr_varnum[10];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_154_WARMELTmiNORMAL_NORMEXP_EXPORT_MACRO is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_154_WARMELTmiNORMAL_NORMEXP_EXPORT_MACRO_st
	 *) meltfirstargp_;
      /* use arguments meltrout_154_WARMELTmiNORMAL_NORMEXP_EXPORT_MACRO output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 32; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_154_WARMELTmiNORMAL_NORMEXP_EXPORT_MACRO nbval 32*/
  meltfram__.mcfr_nbvar = 32 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMEXP_EXPORT_MACRO", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:8074:/ getarg");
 /*_.RECV__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2])) != NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3])) != NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.PSLOC__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.PSLOC__V5*/ meltfptr[4])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8075:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L1*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8075:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8075:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8075;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp export_macro recv=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V6*/ meltfptr[5] =
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8075:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V6*/ meltfptr[5] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8075:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V6*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8076:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_EXPORT_MACRO */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:8076:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[5] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8076:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check export_macro recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8076) ? (8076) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8076:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8077:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:8077:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8077:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8077) ? (8077) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V10*/ meltfptr[5] = /*_._IFELSE___V11*/ meltfptr[10];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8077:/ clear");
	     /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8078:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L5*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[3])));;
      MELT_LOCATION ("warmelt-normal.melt:8078:/ cond");
      /*cond */ if ( /*_#IS_A__L5*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V13*/ meltfptr[12] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8078:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8078) ? (8078) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V12*/ meltfptr[10] = /*_._IFELSE___V13*/ meltfptr[12];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8078:/ clear");
	     /*clear *//*_#IS_A__L5*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V12*/ meltfptr[10] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:8079:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:8080:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.SLOC__V15*/ meltfptr[14] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8081:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "SEXPMAC_MNAME");
  /*_.MNAME__V16*/ meltfptr[15] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8082:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 3, "SEXPMAC_MVAL");
  /*_.MVALEXP__V17*/ meltfptr[16] = slot;
    };
    ;
 /*_.BINDSLIST__V18*/ meltfptr[17] =
      (meltgc_new_list
       ((meltobject_ptr_t) (( /*!DISCR_LIST */ meltfrout->tabval[4]))));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8084:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NREP_NIL */ meltfrout->
					     tabval[5])), (1),
			      "CLASS_NREP_NIL");
  /*_.INST__V20*/ meltfptr[19] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V20*/ meltfptr[19])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V20*/ meltfptr[19]), (0),
			  ( /*_.SLOC__V15*/ meltfptr[14]), "NREP_LOC");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V20*/ meltfptr[19],
				  "newly made instance");
    ;
    /*_.NREPNIL__V19*/ meltfptr[18] = /*_.INST__V20*/ meltfptr[19];;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8086:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L6*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.MNAME__V16*/ meltfptr[15]),
			     (melt_ptr_t) (( /*!CLASS_SYMBOL */ meltfrout->
					    tabval[6])));;
      MELT_LOCATION ("warmelt-normal.melt:8086:/ cond");
      /*cond */ if ( /*_#IS_A__L6*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V22*/ meltfptr[21] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8086:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check mname"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8086) ? (8086) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V22*/ meltfptr[21] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V21*/ meltfptr[20] = /*_._IFELSE___V22*/ meltfptr[21];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8086:/ clear");
	     /*clear *//*_#IS_A__L6*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V22*/ meltfptr[21] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V21*/ meltfptr[20] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8087:/ quasiblock");


    /*^multimsend */
    /*multimsend */
    {
      union meltparam_un argtab[3];
      union meltparam_un restab[1];
      memset (&argtab, 0, sizeof (argtab));
      memset (&restab, 0, sizeof (restab));
      /*^multimsend.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.ENV__V3*/ meltfptr[2];	/*^multimsend.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];	/*^multimsend.arg */
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V15*/ meltfptr[14];
      /*^multimsend.xres */
      restab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NBINDS__V25*/ meltfptr[24];	/*^multimsend.send */
      /*_.NEXP__V24*/ meltfptr[23] =
	meltgc_send ((melt_ptr_t) ( /*_.MVALEXP__V17*/ meltfptr[16]),
		     ((melt_ptr_t)
		      (( /*!NORMAL_EXP */ meltfrout->tabval[7]))),
		     (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		     argtab, (MELTBPARSTR_PTR ""), restab);
    }
    ;
    /*^quasiblock */



    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8090:/ apply");
    /*apply */
    {
      union meltparam_un argtab[1];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NBINDS__V25*/ meltfptr[24];
      /*_.LIST_APPEND2LIST__V26*/ meltfptr[25] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!LIST_APPEND2LIST */ meltfrout->tabval[8])),
		    (melt_ptr_t) ( /*_.BINDSLIST__V18*/ meltfptr[17]),
		    (MELTBPARSTR_PTR ""), argtab, "",
		    (union meltparam_un *) 0);
    }
    ;
    MELT_LOCATION ("warmelt-normal.melt:8091:/ quasiblock");



    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8092:/ apply");
    /*apply */
    {
      union meltparam_un argtab[5];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NEXP__V24*/ meltfptr[23];
      /*^apply.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.ENV__V3*/ meltfptr[2];
      /*^apply.arg */
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
      /*^apply.arg */
      argtab[3].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V15*/ meltfptr[14];
      /*^apply.arg */
      argtab[4].meltbp_aptr =
	(melt_ptr_t *) & /*_.BINDSLIST__V18*/ meltfptr[17];
      /*_.NEXPM__V27*/ meltfptr[26] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMAL_EXPORTED_MACRO */ meltfrout->tabval[9])),
		    (melt_ptr_t) ( /*_.MNAME__V16*/ meltfptr[15]),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR
		     MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "",
		    (union meltparam_un *) 0);
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8094:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L7*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8094:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L7*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L8*/ meltfnum[0] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8094:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L8*/ meltfnum[0];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8094;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_export_macro nexpm";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NEXPM__V27*/ meltfptr[26];
	      /*_.MELT_DEBUG_FUN__V29*/ meltfptr[28] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V28*/ meltfptr[27] =
	      /*_.MELT_DEBUG_FUN__V29*/ meltfptr[28];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8094:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L8*/ meltfnum[0] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V29*/ meltfptr[28] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V28*/ meltfptr[27] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8094:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L7*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V28*/ meltfptr[27] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_LOCATION ("warmelt-normal.melt:8091:/ clear");
	   /*clear *//*_.NEXPM__V27*/ meltfptr[26] = 0;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8096:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L9*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8096:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L9*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L10*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8096:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L10*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8096;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_export_macro final nrepnil=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NREPNIL__V19*/ meltfptr[18];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " bindslist=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.BINDSLIST__V18*/ meltfptr[17];
	      /*_.MELT_DEBUG_FUN__V31*/ meltfptr[27] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V30*/ meltfptr[28] =
	      /*_.MELT_DEBUG_FUN__V31*/ meltfptr[27];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8096:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L10*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V31*/ meltfptr[27] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V30*/ meltfptr[28] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8096:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L9*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V30*/ meltfptr[28] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8098:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.NREPNIL__V19*/ meltfptr[18];;
    MELT_LOCATION ("warmelt-normal.melt:8098:/ putxtraresult");
    if (!meltxrestab_ || !meltxresdescr_)
      goto meltlabend_rout;
    if (meltxresdescr_[0] != MELTBPAR_PTR)
      goto meltlabend_rout;
    if (meltxrestab_[0].meltbp_aptr)
      *(meltxrestab_[0].meltbp_aptr) =
	(melt_ptr_t) ( /*_.BINDSLIST__V18*/ meltfptr[17]);
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;

    MELT_CHECK_SIGNAL ();
    ;
    /*_.MULTI___V23*/ meltfptr[21] = /*_.RETURN___V32*/ meltfptr[26];;

    MELT_LOCATION ("warmelt-normal.melt:8087:/ clear");
	   /*clear *//*_.LIST_APPEND2LIST__V26*/ meltfptr[25] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V32*/ meltfptr[26] = 0;

    /*^clear */
	   /*clear *//*_.NBINDS__V25*/ meltfptr[24] = 0;
    /*_.LET___V14*/ meltfptr[12] = /*_.MULTI___V23*/ meltfptr[21];;

    MELT_LOCATION ("warmelt-normal.melt:8079:/ clear");
	   /*clear *//*_.SLOC__V15*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.MNAME__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.MVALEXP__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.BINDSLIST__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.NREPNIL__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V21*/ meltfptr[20] = 0;
    /*^clear */
	   /*clear *//*_.MULTI___V23*/ meltfptr[21] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8074:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V14*/ meltfptr[12];;

    {
      MELT_LOCATION ("warmelt-normal.melt:8074:/ locexp");
      /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
      if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
      ;
    }
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*epilog */

    /*^clear */
	   /*clear *//*_.IFCPP___V8*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V10*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V12*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.LET___V14*/ meltfptr[12] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMEXP_EXPORT_MACRO", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_154_WARMELTmiNORMAL_NORMEXP_EXPORT_MACRO_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_154_WARMELTmiNORMAL_NORMEXP_EXPORT_MACRO */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_155_WARMELTmiNORMAL_NORMAL_EXPORTED_PATMACRO (meltclosure_ptr_t
						       meltclosp_,
						       melt_ptr_t
						       meltfirstargp_,
						       const
						       melt_argdescr_cell_t
						       meltxargdescr_[],
						       union meltparam_un *
						       meltxargtab_,
						       const
						       melt_argdescr_cell_t
						       meltxresdescr_[],
						       union meltparam_un *
						       meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_155_WARMELTmiNORMAL_NORMAL_EXPORTED_PATMACRO_melt
    = melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_155_WARMELTmiNORMAL_NORMAL_EXPORTED_PATMACRO_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 54
    melt_ptr_t mcfr_varptr[54];
#define MELTFRAM_NBVARNUM 14
    long mcfr_varnum[14];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_155_WARMELTmiNORMAL_NORMAL_EXPORTED_PATMACRO is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct
	 meltframe_meltrout_155_WARMELTmiNORMAL_NORMAL_EXPORTED_PATMACRO_st *)
	meltfirstargp_;
      /* use arguments meltrout_155_WARMELTmiNORMAL_NORMAL_EXPORTED_PATMACRO output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 54; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_155_WARMELTmiNORMAL_NORMAL_EXPORTED_PATMACRO nbval 54*/
  meltfram__.mcfr_nbvar = 54 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMAL_EXPORTED_PATMACRO", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:8109:/ getarg");
 /*_.SYM__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NMACROXP__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NMACROXP__V3*/ meltfptr[2])) !=
	      NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NPATTXP__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NPATTXP__V4*/ meltfptr[3])) !=
	      NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V5*/ meltfptr[4])) != NULL);


  /*getarg#4 */
  /*^getarg */
  if (meltxargdescr_[3] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V6*/ meltfptr[5] =
    (meltxargtab_[3].meltbp_aptr) ? (*(meltxargtab_[3].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V6*/ meltfptr[5])) != NULL);


  /*getarg#5 */
  /*^getarg */
  if (meltxargdescr_[4] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.PSLOC__V7*/ meltfptr[6] =
    (meltxargtab_[4].meltbp_aptr) ? (*(meltxargtab_[4].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.PSLOC__V7*/ meltfptr[6])) !=
	      NULL);


  /*getarg#6 */
  /*^getarg */
  if (meltxargdescr_[5] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.BINDSLIST__V8*/ meltfptr[7] =
    (meltxargtab_[5].meltbp_aptr) ? (*(meltxargtab_[5].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.BINDSLIST__V8*/ meltfptr[7])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8110:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L1*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8110:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8110:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[9];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8110;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normal_exported_patmacro start sym=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.SYM__V2*/ meltfptr[1];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " nmacroxp=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.NMACROXP__V3*/ meltfptr[2];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " npattxp=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.NPATTXP__V4*/ meltfptr[3];
	      /*_.MELT_DEBUG_FUN__V10*/ meltfptr[9] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V9*/ meltfptr[8] =
	      /*_.MELT_DEBUG_FUN__V10*/ meltfptr[9];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8110:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V10*/ meltfptr[9] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V9*/ meltfptr[8] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8110:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V9*/ meltfptr[8] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8112:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.SYM__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SYMBOL */ meltfrout->
					    tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:8112:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V12*/ meltfptr[8] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8112:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check sym"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8112) ? (8112) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V12*/ meltfptr[8] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V11*/ meltfptr[9] = /*_._IFELSE___V12*/ meltfptr[8];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8112:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V12*/ meltfptr[8] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V11*/ meltfptr[9] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8113:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NMACROXP__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_NREP */ meltfrout->
					    tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:8113:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V14*/ meltfptr[13] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8113:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nmacroxp"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8113) ? (8113) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V14*/ meltfptr[13] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V13*/ meltfptr[8] = /*_._IFELSE___V14*/ meltfptr[13];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8113:/ clear");
	     /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V14*/ meltfptr[13] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V13*/ meltfptr[8] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8114:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L5*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V5*/ meltfptr[4]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[3])));;
      MELT_LOCATION ("warmelt-normal.melt:8114:/ cond");
      /*cond */ if ( /*_#IS_A__L5*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V16*/ meltfptr[15] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8114:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8114) ? (8114) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V16*/ meltfptr[15] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V15*/ meltfptr[13] = /*_._IFELSE___V16*/ meltfptr[15];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8114:/ clear");
	     /*clear *//*_#IS_A__L5*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V16*/ meltfptr[15] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V15*/ meltfptr[13] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8115:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L6*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V6*/ meltfptr[5]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[4])));;
      MELT_LOCATION ("warmelt-normal.melt:8115:/ cond");
      /*cond */ if ( /*_#IS_A__L6*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V18*/ meltfptr[17] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8115:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check ncx"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8115) ? (8115) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V18*/ meltfptr[17] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V17*/ meltfptr[15] = /*_._IFELSE___V18*/ meltfptr[17];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8115:/ clear");
	     /*clear *//*_#IS_A__L6*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V18*/ meltfptr[17] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V17*/ meltfptr[15] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8116:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST__L7*/ meltfnum[1] =
	(melt_magic_discr ((melt_ptr_t) ( /*_.BINDSLIST__V8*/ meltfptr[7])) ==
	 MELTOBMAG_LIST);;
      MELT_LOCATION ("warmelt-normal.melt:8116:/ cond");
      /*cond */ if ( /*_#IS_LIST__L7*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V20*/ meltfptr[19] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8116:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check bindslist"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8116) ? (8116) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V20*/ meltfptr[19] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V19*/ meltfptr[17] = /*_._IFELSE___V20*/ meltfptr[19];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8116:/ clear");
	     /*clear *//*_#IS_LIST__L7*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V20*/ meltfptr[19] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V19*/ meltfptr[17] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:8117:/ quasiblock");



    MELT_CHECK_SIGNAL ();
    ;
    /*^apply */
    /*apply */
    {
      /*_.CSYMEXPO__V22*/ meltfptr[21] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!CLONE_SYMBOL */ meltfrout->tabval[5])),
		    (melt_ptr_t) (( /*!konst_6__EXPORTEDPAT_ */ meltfrout->
				   tabval[6])), (""),
		    (union meltparam_un *) 0, "", (union meltparam_un *) 0);
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8118:/ apply");
    /*apply */
    {
      union meltparam_un argtab[2];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V6*/ meltfptr[5];
      /*^apply.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.PSLOC__V7*/ meltfptr[6];
      /*_.SYMDATA__V23*/ meltfptr[22] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMAL_SYMBOL_DATA */ meltfrout->tabval[7])),
		    (melt_ptr_t) ( /*_.SYM__V2*/ meltfptr[1]),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "",
		    (union meltparam_un *) 0);
    }
    ;
    MELT_LOCATION ("warmelt-normal.melt:8119:/ quasiblock");


 /*_.SB__V25*/ meltfptr[24] =
      (melt_ptr_t)
      meltgc_new_strbuf ((meltobject_ptr_t)
			 (( /*!DISCR_STRBUF */ meltfrout->tabval[8])),
			 (const char *) 0);;

    {
      MELT_LOCATION ("warmelt-normal.melt:8120:/ locexp");
      /*add2sbuf_strconst */
	meltgc_add_strbuf ((melt_ptr_t) ( /*_.SB__V25*/ meltfptr[24]),
			   ("norm.exp.pat : "));
    }
    ;
    MELT_LOCATION ("warmelt-normal.melt:8121:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.SYM__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "NAMED_NAME");
  /*_.NAMED_NAME__V26*/ meltfptr[25] = slot;
    };
    ;

    {
      /*^locexp */
      /*add2sbuf_string */
	meltgc_add_strbuf ((melt_ptr_t) ( /*_.SB__V25*/ meltfptr[24]),
			   melt_string_str ((melt_ptr_t)
					    ( /*_.NAMED_NAME__V26*/
					     meltfptr[25])));
    }
    ;
    /*_.LET___V24*/ meltfptr[23] = /*_.SB__V25*/ meltfptr[24];;

    MELT_LOCATION ("warmelt-normal.melt:8119:/ clear");
	   /*clear *//*_.SB__V25*/ meltfptr[24] = 0;
    /*^clear */
	   /*clear *//*_.NAMED_NAME__V26*/ meltfptr[25] = 0;
    /*_.CSBUF__V27*/ meltfptr[24] = /*_.LET___V24*/ meltfptr[23];;

    MELT_CHECK_SIGNAL ();
    ;
    /*^compute */
 /*_.STRBUF2STRING__V28*/ meltfptr[25] =
      (meltgc_new_stringdup
       ((meltobject_ptr_t) (( /*!DISCR_STRING */ meltfrout->tabval[10])),
	melt_strbuf_str ((melt_ptr_t) ( /*_.CSBUF__V27*/ meltfptr[24]))));;
    MELT_LOCATION ("warmelt-normal.melt:8123:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_SOURCE_CURRENT_MODULE_ENVIRONMENT_REFERENCE */ meltfrout->tabval[9])), (3), "CLASS_SOURCE_CURRENT_MODULE_ENVIRONMENT_REFERENCE");
  /*_.INST__V30*/ meltfptr[29] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @LOCA_LOCATION",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V30*/ meltfptr[29])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V30*/ meltfptr[29]), (1),
			  ( /*_.PSLOC__V7*/ meltfptr[6]), "LOCA_LOCATION");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @CMEC_COMMENT",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V30*/ meltfptr[29])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V30*/ meltfptr[29]), (2),
			  ( /*_.STRBUF2STRING__V28*/ meltfptr[25]),
			  "CMEC_COMMENT");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V30*/ meltfptr[29],
				  "newly made instance");
    ;
    /*_.SCURENVBOX__V29*/ meltfptr[28] = /*_.INST__V30*/ meltfptr[29];;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8127:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L8*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8127:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L8*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L9*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8127:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L9*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8127;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normal_exported_patmacro sgetcurenvbox";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.SCURENVBOX__V29*/ meltfptr[28];
	      /*_.MELT_DEBUG_FUN__V32*/ meltfptr[31] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V31*/ meltfptr[30] =
	      /*_.MELT_DEBUG_FUN__V32*/ meltfptr[31];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8127:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L9*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V32*/ meltfptr[31] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V31*/ meltfptr[30] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8127:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L8*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V31*/ meltfptr[30] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8128:/ quasiblock");


    /*^multimsend */
    /*multimsend */
    {
      union meltparam_un argtab[3];
      union meltparam_un restab[1];
      memset (&argtab, 0, sizeof (argtab));
      memset (&restab, 0, sizeof (restab));
      /*^multimsend.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.ENV__V5*/ meltfptr[4];	/*^multimsend.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V6*/ meltfptr[5];	/*^multimsend.arg */
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.PSLOC__V7*/ meltfptr[6];
      /*^multimsend.xres */
      restab[0].meltbp_aptr = (melt_ptr_t *) & /*_.CURENVBINDS__V35*/ meltfptr[34];	/*^multimsend.send */
      /*_.NCURENVBOX__V34*/ meltfptr[30] =
	meltgc_send ((melt_ptr_t) ( /*_.SCURENVBOX__V29*/ meltfptr[28]),
		     ((melt_ptr_t)
		      (( /*!NORMAL_EXP */ meltfrout->tabval[11]))),
		     (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		     argtab, (MELTBPARSTR_PTR ""), restab);
    }
    ;
    /*^quasiblock */



#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8131:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L10*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8131:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L10*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L11*/ meltfnum[0] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8131:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L11*/ meltfnum[0];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8131;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normal_exported_patmacro ncurenvbox=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NCURENVBOX__V34*/ meltfptr[30];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " curenvbinds=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.CURENVBINDS__V35*/ meltfptr[34];
	      /*_.MELT_DEBUG_FUN__V37*/ meltfptr[36] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V36*/ meltfptr[35] =
	      /*_.MELT_DEBUG_FUN__V37*/ meltfptr[36];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8131:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L11*/ meltfnum[0] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V37*/ meltfptr[36] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V36*/ meltfptr[35] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8131:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L10*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V36*/ meltfptr[35] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
 /*_#IS_LIST__L12*/ meltfnum[0] =
      (melt_magic_discr ((melt_ptr_t) ( /*_.CURENVBINDS__V35*/ meltfptr[34]))
       == MELTOBMAG_LIST);;
    MELT_LOCATION ("warmelt-normal.melt:8133:/ cond");
    /*cond */ if ( /*_#IS_LIST__L12*/ meltfnum[0])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{


	  MELT_CHECK_SIGNAL ();
	  ;
	  /*^apply */
	  /*apply */
	  {
	    union meltparam_un argtab[1];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.CURENVBINDS__V35*/ meltfptr[34];
	    /*_.LIST_APPEND2LIST__V39*/ meltfptr[35] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!LIST_APPEND2LIST */ meltfrout->tabval[12])),
			  (melt_ptr_t) ( /*_.BINDSLIST__V8*/ meltfptr[7]),
			  (MELTBPARSTR_PTR ""), argtab, "",
			  (union meltparam_un *) 0);
	  }
	  ;
	  /*_._IF___V38*/ meltfptr[36] =
	    /*_.LIST_APPEND2LIST__V39*/ meltfptr[35];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:8133:/ clear");
	     /*clear *//*_.LIST_APPEND2LIST__V39*/ meltfptr[35] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

  /*_._IF___V38*/ meltfptr[36] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:8134:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:8135:/ blockmultialloc");
    /*multiallocblock */
    {
      struct meltletrec_1_st
      {
	struct MELT_MULTIPLE_STRUCT (4) rtup_0__TUPLREC__x20;
	long meltletrec_1_endgap;
      } *meltletrec_1_ptr = 0;
      meltletrec_1_ptr =
	(struct meltletrec_1_st *)
	meltgc_allocate (sizeof (struct meltletrec_1_st), 0);
      /*^blockmultialloc.initfill */
      /*inimult rtup_0__TUPLREC__x20 */
 /*_.TUPLREC___V42*/ meltfptr[41] =
	(melt_ptr_t) & meltletrec_1_ptr->rtup_0__TUPLREC__x20;
      meltletrec_1_ptr->rtup_0__TUPLREC__x20.discr =
	(meltobject_ptr_t) (((melt_ptr_t) (MELT_PREDEF (DISCR_MULTIPLE))));
      meltletrec_1_ptr->rtup_0__TUPLREC__x20.nbval = 4;


      /*^putuple */
      /*putupl#55 */
      melt_assertmsg ("putupl [:8135] #55 checktup",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.TUPLREC___V42*/ meltfptr[41]))
		      == MELTOBMAG_MULTIPLE);
      melt_assertmsg ("putupl [:8135] #55 checkoff",
		      (0 >= 0
		       && 0 <
		       melt_multiple_length ((melt_ptr_t)
					     ( /*_.TUPLREC___V42*/
					      meltfptr[41]))));
      ((meltmultiple_ptr_t) ( /*_.TUPLREC___V42*/ meltfptr[41]))->tabval[0] =
	(melt_ptr_t) ( /*_.SYMDATA__V23*/ meltfptr[22]);
      ;
      /*^putuple */
      /*putupl#56 */
      melt_assertmsg ("putupl [:8135] #56 checktup",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.TUPLREC___V42*/ meltfptr[41]))
		      == MELTOBMAG_MULTIPLE);
      melt_assertmsg ("putupl [:8135] #56 checkoff",
		      (1 >= 0
		       && 1 <
		       melt_multiple_length ((melt_ptr_t)
					     ( /*_.TUPLREC___V42*/
					      meltfptr[41]))));
      ((meltmultiple_ptr_t) ( /*_.TUPLREC___V42*/ meltfptr[41]))->tabval[1] =
	(melt_ptr_t) ( /*_.NMACROXP__V3*/ meltfptr[2]);
      ;
      /*^putuple */
      /*putupl#57 */
      melt_assertmsg ("putupl [:8135] #57 checktup",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.TUPLREC___V42*/ meltfptr[41]))
		      == MELTOBMAG_MULTIPLE);
      melt_assertmsg ("putupl [:8135] #57 checkoff",
		      (2 >= 0
		       && 2 <
		       melt_multiple_length ((melt_ptr_t)
					     ( /*_.TUPLREC___V42*/
					      meltfptr[41]))));
      ((meltmultiple_ptr_t) ( /*_.TUPLREC___V42*/ meltfptr[41]))->tabval[2] =
	(melt_ptr_t) ( /*_.NPATTXP__V4*/ meltfptr[3]);
      ;
      /*^putuple */
      /*putupl#58 */
      melt_assertmsg ("putupl [:8135] #58 checktup",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.TUPLREC___V42*/ meltfptr[41]))
		      == MELTOBMAG_MULTIPLE);
      melt_assertmsg ("putupl [:8135] #58 checkoff",
		      (3 >= 0
		       && 3 <
		       melt_multiple_length ((melt_ptr_t)
					     ( /*_.TUPLREC___V42*/
					      meltfptr[41]))));
      ((meltmultiple_ptr_t) ( /*_.TUPLREC___V42*/ meltfptr[41]))->tabval[3] =
	(melt_ptr_t) ( /*_.NCURENVBOX__V34*/ meltfptr[30]);
      ;
      /*^touch */
      meltgc_touch ( /*_.TUPLREC___V42*/ meltfptr[41]);
      ;
      /*_.ARGTUP__V41*/ meltfptr[40] = /*_.TUPLREC___V42*/ meltfptr[41];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8135:/ clear");
	    /*clear *//*_.TUPLREC___V42*/ meltfptr[41] = 0;
      /*^clear */
	    /*clear *//*_.TUPLREC___V42*/ meltfptr[41] = 0;
    }				/*end multiallocblock */
    ;

    MELT_CHECK_SIGNAL ();
    ;

    MELT_CHECK_SIGNAL ();
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8145:/ apply");
    /*apply */
    {
      union meltparam_un argtab[3];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V6*/ meltfptr[5];
      /*^apply.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.PSLOC__V7*/ meltfptr[6];
      /*^apply.arg */
      argtab[2].meltbp_cstring = "hook_patmacro_exporter";
      /*_.NORMAL_PREDEF__V43*/ meltfptr[41] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMAL_PREDEF */ meltfrout->tabval[17])),
		    (melt_ptr_t) (( /*!HOOK_PATMACRO_EXPORTER */ meltfrout->
				   tabval[18])),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING ""),
		    argtab, "", (union meltparam_un *) 0);
    }
    ;
    MELT_LOCATION ("warmelt-normal.melt:8147:/ blockmultialloc");
    /*multiallocblock */
    {
      struct meltletrec_2_st
      {
	struct MELT_MULTIPLE_STRUCT (0) rtup_0__TUPLREC__x21;
	long meltletrec_2_endgap;
      } *meltletrec_2_ptr = 0;
      meltletrec_2_ptr =
	(struct meltletrec_2_st *)
	meltgc_allocate (sizeof (struct meltletrec_2_st), 0);
      /*^blockmultialloc.initfill */
      /*inimult rtup_0__TUPLREC__x21 */
 /*_.TUPLREC___V45*/ meltfptr[44] =
	(melt_ptr_t) & meltletrec_2_ptr->rtup_0__TUPLREC__x21;
      meltletrec_2_ptr->rtup_0__TUPLREC__x21.discr =
	(meltobject_ptr_t) (((melt_ptr_t) (MELT_PREDEF (DISCR_MULTIPLE))));
      meltletrec_2_ptr->rtup_0__TUPLREC__x21.nbval = 0;


      /*^touch */
      meltgc_touch ( /*_.TUPLREC___V45*/ meltfptr[44]);
      ;
      /*_.TUPLE___V44*/ meltfptr[43] = /*_.TUPLREC___V45*/ meltfptr[44];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8147:/ clear");
	    /*clear *//*_.TUPLREC___V45*/ meltfptr[44] = 0;
      /*^clear */
	    /*clear *//*_.TUPLREC___V45*/ meltfptr[44] = 0;
    }				/*end multiallocblock */
    ;
 /*_.HOOK_DATA__V46*/ meltfptr[44] =
      melt_hook_data ((melt_ptr_t)
		      ( /*!HOOK_PATMACRO_EXPORTER */ meltfrout->tabval[18]));;
    MELT_LOCATION ("warmelt-normal.melt:8141:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NREP_HOOK_CALL */
					     meltfrout->tabval[15])), (7),
			      "CLASS_NREP_HOOK_CALL");
  /*_.INST__V48*/ meltfptr[47] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NEXPR_CTYP",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V48*/ meltfptr[47])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V48*/ meltfptr[47]), (1),
			  (( /*!CTYPE_VOID */ meltfrout->tabval[14])),
			  "NEXPR_CTYP");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NHOOK_NAME",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V48*/ meltfptr[47])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V48*/ meltfptr[47]), (3),
			  (( /*!konst_16 */ meltfrout->tabval[16])),
			  "NHOOK_NAME");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NEXPR_ARGS",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V48*/ meltfptr[47])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V48*/ meltfptr[47]), (2),
			  ( /*_.ARGTUP__V41*/ meltfptr[40]), "NEXPR_ARGS");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NHOOK_CALLED",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V48*/ meltfptr[47])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V48*/ meltfptr[47]), (4),
			  ( /*_.NORMAL_PREDEF__V43*/ meltfptr[41]),
			  "NHOOK_CALLED");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NHOOK_OUTS",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V48*/ meltfptr[47])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V48*/ meltfptr[47]), (5),
			  ( /*_.TUPLE___V44*/ meltfptr[43]), "NHOOK_OUTS");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NHOOK_DESCR",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V48*/ meltfptr[47])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V48*/ meltfptr[47]), (6),
			  ( /*_.HOOK_DATA__V46*/ meltfptr[44]),
			  "NHOOK_DESCR");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V48*/ meltfptr[47],
				  "newly made instance");
    ;
    /*_.INST___V47*/ meltfptr[46] = /*_.INST__V48*/ meltfptr[47];;
    MELT_LOCATION ("warmelt-normal.melt:8136:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NORMAL_LET_BINDING */
					     meltfrout->tabval[13])), (4),
			      "CLASS_NORMAL_LET_BINDING");
  /*_.INST__V50*/ meltfptr[49] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @LETBIND_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V50*/ meltfptr[49])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V50*/ meltfptr[49]), (3),
			  ( /*_.PSLOC__V7*/ meltfptr[6]), "LETBIND_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @BINDER",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V50*/ meltfptr[49])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V50*/ meltfptr[49]), (0),
			  ( /*_.CSYMEXPO__V22*/ meltfptr[21]), "BINDER");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @LETBIND_TYPE",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V50*/ meltfptr[49])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V50*/ meltfptr[49]), (1),
			  (( /*!CTYPE_VOID */ meltfrout->tabval[14])),
			  "LETBIND_TYPE");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @LETBIND_EXPR",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V50*/ meltfptr[49])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V50*/ meltfptr[49]), (2),
			  ( /*_.INST___V47*/ meltfptr[46]), "LETBIND_EXPR");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V50*/ meltfptr[49],
				  "newly made instance");
    ;
    /*_.CBIND__V49*/ meltfptr[48] = /*_.INST__V50*/ meltfptr[49];;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8150:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NREP_LOCSYMOCC */
					     meltfrout->tabval[19])), (4),
			      "CLASS_NREP_LOCSYMOCC");
  /*_.INST__V52*/ meltfptr[51] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V52*/ meltfptr[51])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V52*/ meltfptr[51]), (0),
			  ( /*_.PSLOC__V7*/ meltfptr[6]), "NREP_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NOCC_CTYP",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V52*/ meltfptr[51])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V52*/ meltfptr[51]), (2),
			  (( /*!CTYPE_VOID */ meltfrout->tabval[14])),
			  "NOCC_CTYP");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NOCC_SYMB",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V52*/ meltfptr[51])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V52*/ meltfptr[51]), (1),
			  ( /*_.CSYMEXPO__V22*/ meltfptr[21]), "NOCC_SYMB");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NOCC_BIND",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V52*/ meltfptr[51])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V52*/ meltfptr[51]), (3),
			  ( /*_.CBIND__V49*/ meltfptr[48]), "NOCC_BIND");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V52*/ meltfptr[51],
				  "newly made instance");
    ;
    /*_.SYOCC__V51*/ meltfptr[50] = /*_.INST__V52*/ meltfptr[51];;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8156:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L13*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8156:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L13*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L14*/ meltfnum[13] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8156:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L14*/ meltfnum[13];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8156;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normal_exported_patmacro cbind=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CBIND__V49*/ meltfptr[48];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " return syocc=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.SYOCC__V51*/ meltfptr[50];
	      /*_.MELT_DEBUG_FUN__V54*/ meltfptr[53] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V53*/ meltfptr[52] =
	      /*_.MELT_DEBUG_FUN__V54*/ meltfptr[53];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8156:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L14*/ meltfnum[13] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V54*/ meltfptr[53] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V53*/ meltfptr[52] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8156:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L13*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V53*/ meltfptr[52] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:8157:/ locexp");
      meltgc_append_list ((melt_ptr_t) ( /*_.BINDSLIST__V8*/ meltfptr[7]),
			  (melt_ptr_t) ( /*_.CBIND__V49*/ meltfptr[48]));
    }
    ;
    /*_.LET___V40*/ meltfptr[35] = /*_.SYOCC__V51*/ meltfptr[50];;

    MELT_LOCATION ("warmelt-normal.melt:8134:/ clear");
	   /*clear *//*_.ARGTUP__V41*/ meltfptr[40] = 0;
    /*^clear */
	   /*clear *//*_.NORMAL_PREDEF__V43*/ meltfptr[41] = 0;
    /*^clear */
	   /*clear *//*_.TUPLE___V44*/ meltfptr[43] = 0;
    /*^clear */
	   /*clear *//*_.HOOK_DATA__V46*/ meltfptr[44] = 0;
    /*^clear */
	   /*clear *//*_.INST___V47*/ meltfptr[46] = 0;
    /*^clear */
	   /*clear *//*_.CBIND__V49*/ meltfptr[48] = 0;
    /*^clear */
	   /*clear *//*_.SYOCC__V51*/ meltfptr[50] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    /*_.MULTI___V33*/ meltfptr[31] = /*_.LET___V40*/ meltfptr[35];;

    MELT_LOCATION ("warmelt-normal.melt:8128:/ clear");
	   /*clear *//*_#IS_LIST__L12*/ meltfnum[0] = 0;
    /*^clear */
	   /*clear *//*_._IF___V38*/ meltfptr[36] = 0;
    /*^clear */
	   /*clear *//*_.LET___V40*/ meltfptr[35] = 0;

    /*^clear */
	   /*clear *//*_.CURENVBINDS__V35*/ meltfptr[34] = 0;
    /*_.LET___V21*/ meltfptr[19] = /*_.MULTI___V33*/ meltfptr[31];;

    MELT_LOCATION ("warmelt-normal.melt:8117:/ clear");
	   /*clear *//*_.CSYMEXPO__V22*/ meltfptr[21] = 0;
    /*^clear */
	   /*clear *//*_.SYMDATA__V23*/ meltfptr[22] = 0;
    /*^clear */
	   /*clear *//*_.LET___V24*/ meltfptr[23] = 0;
    /*^clear */
	   /*clear *//*_.CSBUF__V27*/ meltfptr[24] = 0;
    /*^clear */
	   /*clear *//*_.STRBUF2STRING__V28*/ meltfptr[25] = 0;
    /*^clear */
	   /*clear *//*_.SCURENVBOX__V29*/ meltfptr[28] = 0;
    /*^clear */
	   /*clear *//*_.MULTI___V33*/ meltfptr[31] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8109:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V21*/ meltfptr[19];;

    {
      MELT_LOCATION ("warmelt-normal.melt:8109:/ locexp");
      /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
      if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
      ;
    }
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*epilog */

    /*^clear */
	   /*clear *//*_.IFCPP___V11*/ meltfptr[9] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V13*/ meltfptr[8] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V15*/ meltfptr[13] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V17*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V19*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.LET___V21*/ meltfptr[19] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMAL_EXPORTED_PATMACRO", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_155_WARMELTmiNORMAL_NORMAL_EXPORTED_PATMACRO_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_155_WARMELTmiNORMAL_NORMAL_EXPORTED_PATMACRO */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_156_WARMELTmiNORMAL_NORMEXP_EXPORT_PATMACRO (meltclosure_ptr_t
						      meltclosp_,
						      melt_ptr_t
						      meltfirstargp_,
						      const
						      melt_argdescr_cell_t
						      meltxargdescr_[],
						      union meltparam_un *
						      meltxargtab_,
						      const
						      melt_argdescr_cell_t
						      meltxresdescr_[],
						      union meltparam_un *
						      meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_156_WARMELTmiNORMAL_NORMEXP_EXPORT_PATMACRO_melt
    = melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_156_WARMELTmiNORMAL_NORMEXP_EXPORT_PATMACRO_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 44
    melt_ptr_t mcfr_varptr[44];
#define MELTFRAM_NBVARNUM 16
    long mcfr_varnum[16];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_156_WARMELTmiNORMAL_NORMEXP_EXPORT_PATMACRO is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct
	 meltframe_meltrout_156_WARMELTmiNORMAL_NORMEXP_EXPORT_PATMACRO_st *)
	meltfirstargp_;
      /* use arguments meltrout_156_WARMELTmiNORMAL_NORMEXP_EXPORT_PATMACRO output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 44; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_156_WARMELTmiNORMAL_NORMEXP_EXPORT_PATMACRO nbval 44*/
  meltfram__.mcfr_nbvar = 44 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMEXP_EXPORT_PATMACRO", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:8164:/ getarg");
 /*_.RECV__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2])) != NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3])) != NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.PSLOC__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.PSLOC__V5*/ meltfptr[4])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8165:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L1*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8165:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8165:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8165;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp export_patmacro recv=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V6*/ meltfptr[5] =
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8165:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V6*/ meltfptr[5] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8165:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V6*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8166:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_EXPORT_PATMACRO */ meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:8166:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[5] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8166:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check export_patmacro recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8166) ? (8166) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8166:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8167:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:8167:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8167:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8167) ? (8167) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V10*/ meltfptr[5] = /*_._IFELSE___V11*/ meltfptr[10];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8167:/ clear");
	     /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8168:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L5*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[3])));;
      MELT_LOCATION ("warmelt-normal.melt:8168:/ cond");
      /*cond */ if ( /*_#IS_A__L5*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V13*/ meltfptr[12] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8168:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8168) ? (8168) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V12*/ meltfptr[10] = /*_._IFELSE___V13*/ meltfptr[12];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8168:/ clear");
	     /*clear *//*_#IS_A__L5*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V12*/ meltfptr[10] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:8169:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:8170:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.SLOC__V15*/ meltfptr[14] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8171:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "SEXPMAC_MNAME");
  /*_.MNAME__V16*/ meltfptr[15] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8172:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 3, "SEXPMAC_MVAL");
  /*_.MVALEXP__V17*/ meltfptr[16] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8173:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 5, "SEXPPAT_PVAL");
  /*_.MPATEXP__V18*/ meltfptr[17] = slot;
    };
    ;
 /*_.BINDSLIST__V19*/ meltfptr[18] =
      (meltgc_new_list
       ((meltobject_ptr_t) (( /*!DISCR_LIST */ meltfrout->tabval[4]))));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8175:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NREP_NIL */ meltfrout->
					     tabval[5])), (1),
			      "CLASS_NREP_NIL");
  /*_.INST__V21*/ meltfptr[20] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V21*/ meltfptr[20])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V21*/ meltfptr[20]), (0),
			  ( /*_.SLOC__V15*/ meltfptr[14]), "NREP_LOC");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V21*/ meltfptr[20],
				  "newly made instance");
    ;
    /*_.NREPNIL__V20*/ meltfptr[19] = /*_.INST__V21*/ meltfptr[20];;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8177:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L6*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8177:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L6*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L7*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8177:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L7*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8177;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp export_patmacro mname=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.MNAME__V16*/ meltfptr[15];
	      /*_.MELT_DEBUG_FUN__V23*/ meltfptr[22] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V22*/ meltfptr[21] =
	      /*_.MELT_DEBUG_FUN__V23*/ meltfptr[22];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8177:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L7*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V23*/ meltfptr[22] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V22*/ meltfptr[21] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8177:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L6*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V22*/ meltfptr[21] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8178:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L8*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.MNAME__V16*/ meltfptr[15]),
			     (melt_ptr_t) (( /*!CLASS_SYMBOL */ meltfrout->
					    tabval[6])));;
      MELT_LOCATION ("warmelt-normal.melt:8178:/ cond");
      /*cond */ if ( /*_#IS_A__L8*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V25*/ meltfptr[21] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8178:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check mname"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8178) ? (8178) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V25*/ meltfptr[21] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V24*/ meltfptr[22] = /*_._IFELSE___V25*/ meltfptr[21];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8178:/ clear");
	     /*clear *//*_#IS_A__L8*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V25*/ meltfptr[21] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V24*/ meltfptr[22] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8179:/ quasiblock");


    /*^multimsend */
    /*multimsend */
    {
      union meltparam_un argtab[3];
      union meltparam_un restab[1];
      memset (&argtab, 0, sizeof (argtab));
      memset (&restab, 0, sizeof (restab));
      /*^multimsend.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.ENV__V3*/ meltfptr[2];	/*^multimsend.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];	/*^multimsend.arg */
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V15*/ meltfptr[14];
      /*^multimsend.xres */
      restab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NBINDMS__V28*/ meltfptr[27];	/*^multimsend.send */
      /*_.NEXPMAC__V27*/ meltfptr[26] =
	meltgc_send ((melt_ptr_t) ( /*_.MVALEXP__V17*/ meltfptr[16]),
		     ((melt_ptr_t)
		      (( /*!NORMAL_EXP */ meltfrout->tabval[7]))),
		     (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		     argtab, (MELTBPARSTR_PTR ""), restab);
    }
    ;
    /*^quasiblock */



    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8182:/ apply");
    /*apply */
    {
      union meltparam_un argtab[1];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr =
	(melt_ptr_t *) & /*_.NBINDMS__V28*/ meltfptr[27];
      /*_.LIST_APPEND2LIST__V29*/ meltfptr[28] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!LIST_APPEND2LIST */ meltfrout->tabval[8])),
		    (melt_ptr_t) ( /*_.BINDSLIST__V19*/ meltfptr[18]),
		    (MELTBPARSTR_PTR ""), argtab, "",
		    (union meltparam_un *) 0);
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8183:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L9*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8183:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L9*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L10*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8183:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L10*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8183;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_export_patmacro nexpmac";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NEXPMAC__V27*/ meltfptr[26];
	      /*_.MELT_DEBUG_FUN__V31*/ meltfptr[30] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V30*/ meltfptr[29] =
	      /*_.MELT_DEBUG_FUN__V31*/ meltfptr[30];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8183:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L10*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V31*/ meltfptr[30] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V30*/ meltfptr[29] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8183:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L9*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V30*/ meltfptr[29] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8184:/ quasiblock");


    /*^multimsend */
    /*multimsend */
    {
      union meltparam_un argtab[3];
      union meltparam_un restab[1];
      memset (&argtab, 0, sizeof (argtab));
      memset (&restab, 0, sizeof (restab));
      /*^multimsend.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.ENV__V3*/ meltfptr[2];	/*^multimsend.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];	/*^multimsend.arg */
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V15*/ meltfptr[14];
      /*^multimsend.xres */
      restab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NBINDPS__V34*/ meltfptr[33];	/*^multimsend.send */
      /*_.NEXPPAT__V33*/ meltfptr[29] =
	meltgc_send ((melt_ptr_t) ( /*_.MPATEXP__V18*/ meltfptr[17]),
		     ((melt_ptr_t)
		      (( /*!NORMAL_EXP */ meltfrout->tabval[7]))),
		     (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		     argtab, (MELTBPARSTR_PTR ""), restab);
    }
    ;
    /*^quasiblock */



    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8187:/ apply");
    /*apply */
    {
      union meltparam_un argtab[1];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr =
	(melt_ptr_t *) & /*_.NBINDPS__V34*/ meltfptr[33];
      /*_.LIST_APPEND2LIST__V35*/ meltfptr[34] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!LIST_APPEND2LIST */ meltfrout->tabval[8])),
		    (melt_ptr_t) ( /*_.BINDSLIST__V19*/ meltfptr[18]),
		    (MELTBPARSTR_PTR ""), argtab, "",
		    (union meltparam_un *) 0);
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8188:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L11*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8188:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L11*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L12*/ meltfnum[0] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8188:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L12*/ meltfnum[0];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8188;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_export_patmacro nexppat";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NEXPMAC__V27*/ meltfptr[26];
	      /*_.MELT_DEBUG_FUN__V37*/ meltfptr[36] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V36*/ meltfptr[35] =
	      /*_.MELT_DEBUG_FUN__V37*/ meltfptr[36];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8188:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L12*/ meltfnum[0] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V37*/ meltfptr[36] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V36*/ meltfptr[35] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8188:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L11*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V36*/ meltfptr[35] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:8189:/ quasiblock");



    MELT_CHECK_SIGNAL ();
    ;
    /*^apply */
    /*apply */
    {
      union meltparam_un argtab[6];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr =
	(melt_ptr_t *) & /*_.NEXPMAC__V27*/ meltfptr[26];
      /*^apply.arg */
      argtab[1].meltbp_aptr =
	(melt_ptr_t *) & /*_.NEXPPAT__V33*/ meltfptr[29];
      /*^apply.arg */
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.ENV__V3*/ meltfptr[2];
      /*^apply.arg */
      argtab[3].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
      /*^apply.arg */
      argtab[4].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V15*/ meltfptr[14];
      /*^apply.arg */
      argtab[5].meltbp_aptr =
	(melt_ptr_t *) & /*_.BINDSLIST__V19*/ meltfptr[18];
      /*_.NEXPM__V39*/ meltfptr[35] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMAL_EXPORTED_PATMACRO */ meltfrout->tabval[9])),
		    (melt_ptr_t) ( /*_.MNAME__V16*/ meltfptr[15]),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR
		     MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		    argtab, "", (union meltparam_un *) 0);
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8190:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L13*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8190:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L13*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L14*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8190:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L14*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8190;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_export_patmacro nexpm=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NEXPM__V39*/ meltfptr[35];
	      /*_.MELT_DEBUG_FUN__V41*/ meltfptr[40] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V40*/ meltfptr[39] =
	      /*_.MELT_DEBUG_FUN__V41*/ meltfptr[40];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8190:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L14*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V41*/ meltfptr[40] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V40*/ meltfptr[39] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8190:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L13*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V40*/ meltfptr[39] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8191:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L15*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8191:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L15*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L16*/ meltfnum[0] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8191:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L16*/ meltfnum[0];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8191;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_export_patmacro final nrepnil=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NREPNIL__V20*/ meltfptr[19];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " bindslist=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.BINDSLIST__V19*/ meltfptr[18];
	      /*_.MELT_DEBUG_FUN__V43*/ meltfptr[39] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V42*/ meltfptr[40] =
	      /*_.MELT_DEBUG_FUN__V43*/ meltfptr[39];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8191:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L16*/ meltfnum[0] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V43*/ meltfptr[39] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V42*/ meltfptr[40] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8191:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L15*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V42*/ meltfptr[40] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8192:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.NREPNIL__V20*/ meltfptr[19];;
    MELT_LOCATION ("warmelt-normal.melt:8192:/ putxtraresult");
    if (!meltxrestab_ || !meltxresdescr_)
      goto meltlabend_rout;
    if (meltxresdescr_[0] != MELTBPAR_PTR)
      goto meltlabend_rout;
    if (meltxrestab_[0].meltbp_aptr)
      *(meltxrestab_[0].meltbp_aptr) =
	(melt_ptr_t) ( /*_.BINDSLIST__V19*/ meltfptr[18]);
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*_.LET___V38*/ meltfptr[36] = /*_.RETURN___V44*/ meltfptr[39];;

    MELT_LOCATION ("warmelt-normal.melt:8189:/ clear");
	   /*clear *//*_.NEXPM__V39*/ meltfptr[35] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V44*/ meltfptr[39] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    /*_.MULTI___V32*/ meltfptr[30] = /*_.LET___V38*/ meltfptr[36];;

    MELT_LOCATION ("warmelt-normal.melt:8184:/ clear");
	   /*clear *//*_.LIST_APPEND2LIST__V35*/ meltfptr[34] = 0;
    /*^clear */
	   /*clear *//*_.LET___V38*/ meltfptr[36] = 0;

    /*^clear */
	   /*clear *//*_.NBINDPS__V34*/ meltfptr[33] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    /*_.MULTI___V26*/ meltfptr[21] = /*_.MULTI___V32*/ meltfptr[30];;

    MELT_LOCATION ("warmelt-normal.melt:8179:/ clear");
	   /*clear *//*_.LIST_APPEND2LIST__V29*/ meltfptr[28] = 0;
    /*^clear */
	   /*clear *//*_.MULTI___V32*/ meltfptr[30] = 0;

    /*^clear */
	   /*clear *//*_.NBINDMS__V28*/ meltfptr[27] = 0;
    /*_.LET___V14*/ meltfptr[12] = /*_.MULTI___V26*/ meltfptr[21];;

    MELT_LOCATION ("warmelt-normal.melt:8169:/ clear");
	   /*clear *//*_.SLOC__V15*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.MNAME__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.MVALEXP__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.MPATEXP__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.BINDSLIST__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.NREPNIL__V20*/ meltfptr[19] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V24*/ meltfptr[22] = 0;
    /*^clear */
	   /*clear *//*_.MULTI___V26*/ meltfptr[21] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8164:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V14*/ meltfptr[12];;

    {
      MELT_LOCATION ("warmelt-normal.melt:8164:/ locexp");
      /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
      if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
      ;
    }
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*epilog */

    /*^clear */
	   /*clear *//*_.IFCPP___V8*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V10*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V12*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.LET___V14*/ meltfptr[12] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMEXP_EXPORT_PATMACRO", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_156_WARMELTmiNORMAL_NORMEXP_EXPORT_PATMACRO_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_156_WARMELTmiNORMAL_NORMEXP_EXPORT_PATMACRO */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_157_WARMELTmiNORMAL_NORMEXP_CURRENT_MODULE_ENVIRONMENT_REFERENCE
  (meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_,
   const melt_argdescr_cell_t meltxargdescr_[],
   union meltparam_un * meltxargtab_,
   const melt_argdescr_cell_t meltxresdescr_[],
   union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_157_WARMELTmiNORMAL_NORMEXP_CURRENT_MODULE_ENVIRONMENT_REFERENCE_melt
    = melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_157_WARMELTmiNORMAL_NORMEXP_CURRENT_MODULE_ENVIRONMENT_REFERENCE_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 30
    melt_ptr_t mcfr_varptr[30];
#define MELTFRAM_NBVARNUM 10
    long mcfr_varnum[10];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_157_WARMELTmiNORMAL_NORMEXP_CURRENT_MODULE_ENVIRONMENT_REFERENCE is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct
	 meltframe_meltrout_157_WARMELTmiNORMAL_NORMEXP_CURRENT_MODULE_ENVIRONMENT_REFERENCE_st
	 *) meltfirstargp_;
      /* use arguments meltrout_157_WARMELTmiNORMAL_NORMEXP_CURRENT_MODULE_ENVIRONMENT_REFERENCE output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 30; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_157_WARMELTmiNORMAL_NORMEXP_CURRENT_MODULE_ENVIRONMENT_REFERENCE nbval 30*/
  meltfram__.mcfr_nbvar = 30 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMEXP_CURRENT_MODULE_ENVIRONMENT_REFERENCE",
		    meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:8200:/ getarg");
 /*_.RECV__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2])) != NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3])) != NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.PSLOC__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.PSLOC__V5*/ meltfptr[4])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8201:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L1*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8201:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8201:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8201;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_current_module_environment_reference recv=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V6*/ meltfptr[5] =
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8201:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V6*/ meltfptr[5] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8201:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V6*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8202:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_CURRENT_MODULE_ENVIRONMENT_REFERENCE */ meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:8202:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[5] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8202:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check current_module_environment_reference recv"), ("warmelt-normal.melt") ? ("warmelt-normal.melt") : __FILE__, (8202) ? (8202) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8202:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8203:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:8203:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8203:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8203) ? (8203) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V10*/ meltfptr[5] = /*_._IFELSE___V11*/ meltfptr[10];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8203:/ clear");
	     /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8204:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L5*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[3])));;
      MELT_LOCATION ("warmelt-normal.melt:8204:/ cond");
      /*cond */ if ( /*_#IS_A__L5*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V13*/ meltfptr[12] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8204:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8204) ? (8204) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V12*/ meltfptr[10] = /*_._IFELSE___V13*/ meltfptr[12];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8204:/ clear");
	     /*clear *//*_#IS_A__L5*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V12*/ meltfptr[10] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:8205:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:8206:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.SLOC__V15*/ meltfptr[14] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8207:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "CMEC_COMMENT");
  /*_.SCOMM__V16*/ meltfptr[15] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8208:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 14, "NCTX_PROCURMODENVLIST");
  /*_.NCURMODENVLIST__V17*/ meltfptr[16] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8209:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 10, "NCTX_CURPROC");
  /*_.CURPROC__V18*/ meltfptr[17] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8210:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 12, "NCTX_QDATCURMODENVBOX");
  /*_.QDATCUR__V19*/ meltfptr[18] = slot;
    };
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8211:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NREP_QUASICONST_CURRENT_MODULE_ENVIRONMENT_REFERENCE */ meltfrout->tabval[4])), (5), "CLASS_NREP_QUASICONST_CURRENT_MODULE_ENVIRONMENT_REFERENCE");
  /*_.INST__V21*/ meltfptr[20] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V21*/ meltfptr[20])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V21*/ meltfptr[20]), (0),
			  ( /*_.SLOC__V15*/ meltfptr[14]), "NREP_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NCONST_SVAL",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V21*/ meltfptr[20])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V21*/ meltfptr[20]), (1),
			  ( /*_.RECV__V2*/ meltfptr[1]), "NCONST_SVAL");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NCONST_PROC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V21*/ meltfptr[20])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V21*/ meltfptr[20]), (2),
			  ( /*_.CURPROC__V18*/ meltfptr[17]), "NCONST_PROC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NCONST_DATA",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V21*/ meltfptr[20])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V21*/ meltfptr[20]), (3),
			  ( /*_.QDATCUR__V19*/ meltfptr[18]), "NCONST_DATA");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NQCMEC_COMMENT",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V21*/ meltfptr[20])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V21*/ meltfptr[20]), (4),
			  ( /*_.SCOMM__V16*/ meltfptr[15]), "NQCMEC_COMMENT");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V21*/ meltfptr[20],
				  "newly made instance");
    ;
    /*_.NQUASI__V20*/ meltfptr[19] = /*_.INST__V21*/ meltfptr[20];;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8219:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L6*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.QDATCUR__V19*/ meltfptr[18]),
			     (melt_ptr_t) (( /*!CLASS_NREP_QUASIDATA_CURRENT_MODULE_ENVIRONMENT_REFERENCE */ meltfrout->tabval[5])));;
      MELT_LOCATION ("warmelt-normal.melt:8219:/ cond");
      /*cond */ if ( /*_#IS_A__L6*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V23*/ meltfptr[22] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8219:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check qdatcur"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8219) ? (8219) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V23*/ meltfptr[22] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V22*/ meltfptr[21] = /*_._IFELSE___V23*/ meltfptr[22];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8219:/ clear");
	     /*clear *//*_#IS_A__L6*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V23*/ meltfptr[22] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V22*/ meltfptr[21] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    /*^compute */
 /*_#IS_A__L7*/ meltfnum[1] =
      melt_is_instance_of ((melt_ptr_t) ( /*_.CURPROC__V18*/ meltfptr[17]),
			   (melt_ptr_t) (( /*!CLASS_NREP_HOOKPROC */
					  meltfrout->tabval[6])));;
    MELT_LOCATION ("warmelt-normal.melt:8220:/ cond");
    /*cond */ if ( /*_#IS_A__L7*/ meltfnum[1])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{


	  {
	    MELT_LOCATION ("warmelt-normal.melt:8221:/ locexp");
	    /* error_plain */
	      melt_error_str ((melt_ptr_t) ( /*_.SLOC__V15*/ meltfptr[14]),
			      ("(CURRENT_MODULE_ENVIRONMENT_REFERENCE) cannot be used within hooks"),
			      (melt_ptr_t) 0);
	  }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:8222:/ quasiblock");


   /*_._RETVAL___V1*/ meltfptr[0] = NULL;;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:8222:/ locexp");
	    /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
	    if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	      melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
	    ;
	  }
	  ;
	  /*^finalreturn */
	  ;
	  /*finalret */ goto meltlabend_rout;
	  MELT_LOCATION ("warmelt-normal.melt:8220:/ quasiblock");


	  /*_.PROGN___V26*/ meltfptr[25] = /*_.RETURN___V25*/ meltfptr[24];;
	  /*^compute */
	  /*_._IF___V24*/ meltfptr[22] = /*_.PROGN___V26*/ meltfptr[25];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:8220:/ clear");
	     /*clear *//*_.RETURN___V25*/ meltfptr[24] = 0;
	  /*^clear */
	     /*clear *//*_.PROGN___V26*/ meltfptr[25] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

  /*_._IF___V24*/ meltfptr[22] = NULL;;
      }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    /*^compute */
 /*_#IS_A__L8*/ meltfnum[0] =
      melt_is_instance_of ((melt_ptr_t) ( /*_.CURPROC__V18*/ meltfptr[17]),
			   (melt_ptr_t) (( /*!CLASS_NREP_ROUTPROC */
					  meltfrout->tabval[7])));;
    MELT_LOCATION ("warmelt-normal.melt:8223:/ cond");
    /*cond */ if ( /*_#IS_A__L8*/ meltfnum[0])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  MELT_LOCATION ("warmelt-normal.melt:8224:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.CURPROC__V18*/ meltfptr[17]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 5, "NRPRO_CONST");
    /*_.NRPRO_CONST__V27*/ meltfptr[24] = slot;
	  };
	  ;

	  {
	    /*^locexp */
	    meltgc_append_list ((melt_ptr_t)
				( /*_.NRPRO_CONST__V27*/ meltfptr[24]),
				(melt_ptr_t) ( /*_.QDATCUR__V19*/
					      meltfptr[18]));
	  }
	  ;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:8225:/ locexp");
	    meltgc_append_list ((melt_ptr_t)
				( /*_.NCURMODENVLIST__V17*/ meltfptr[16]),
				(melt_ptr_t) ( /*_.CURPROC__V18*/
					      meltfptr[17]));
	  }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:8223:/ quasiblock");


	  /*epilog */

	  /*^clear */
	     /*clear *//*_.NRPRO_CONST__V27*/ meltfptr[24] = 0;
	}
	;
      }				/*noelse */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8227:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L9*/ meltfnum[8] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8227:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L9*/ meltfnum[8])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L10*/ meltfnum[9] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8227:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L10*/ meltfnum[9];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8227;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_current_module_environment_reference nquasi";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NQUASI__V20*/ meltfptr[19];
	      /*_.MELT_DEBUG_FUN__V29*/ meltfptr[24] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V28*/ meltfptr[25] =
	      /*_.MELT_DEBUG_FUN__V29*/ meltfptr[24];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8227:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L10*/ meltfnum[9] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V29*/ meltfptr[24] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V28*/ meltfptr[25] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8227:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L9*/ meltfnum[8] = 0;
      /*^clear */
	     /*clear *//*_._IF___V28*/ meltfptr[25] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8228:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.NQUASI__V20*/ meltfptr[19];;
    MELT_LOCATION ("warmelt-normal.melt:8228:/ putxtraresult");
    if (!meltxrestab_ || !meltxresdescr_)
      goto meltlabend_rout;
    if (meltxresdescr_[0] != MELTBPAR_PTR)
      goto meltlabend_rout;
    if (meltxrestab_[0].meltbp_aptr)
      *(meltxrestab_[0].meltbp_aptr) = (melt_ptr_t) (( /*nil */ NULL));
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*_.LET___V14*/ meltfptr[12] = /*_.RETURN___V30*/ meltfptr[24];;

    MELT_LOCATION ("warmelt-normal.melt:8205:/ clear");
	   /*clear *//*_.SLOC__V15*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.SCOMM__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.NCURMODENVLIST__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.CURPROC__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.QDATCUR__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.NQUASI__V20*/ meltfptr[19] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V22*/ meltfptr[21] = 0;
    /*^clear */
	   /*clear *//*_#IS_A__L7*/ meltfnum[1] = 0;
    /*^clear */
	   /*clear *//*_._IF___V24*/ meltfptr[22] = 0;
    /*^clear */
	   /*clear *//*_#IS_A__L8*/ meltfnum[0] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V30*/ meltfptr[24] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8200:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V14*/ meltfptr[12];;

    {
      MELT_LOCATION ("warmelt-normal.melt:8200:/ locexp");
      /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
      if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
      ;
    }
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*epilog */

    /*^clear */
	   /*clear *//*_.IFCPP___V8*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V10*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V12*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.LET___V14*/ meltfptr[12] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMEXP_CURRENT_MODULE_ENVIRONMENT_REFERENCE",
		  meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_157_WARMELTmiNORMAL_NORMEXP_CURRENT_MODULE_ENVIRONMENT_REFERENCE_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_157_WARMELTmiNORMAL_NORMEXP_CURRENT_MODULE_ENVIRONMENT_REFERENCE */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_158_WARMELTmiNORMAL_NORMEXP_PARENT_MODULE_ENVIRONMENT
  (meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_,
   const melt_argdescr_cell_t meltxargdescr_[],
   union meltparam_un * meltxargtab_,
   const melt_argdescr_cell_t meltxresdescr_[],
   union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_158_WARMELTmiNORMAL_NORMEXP_PARENT_MODULE_ENVIRONMENT_melt
    = melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_158_WARMELTmiNORMAL_NORMEXP_PARENT_MODULE_ENVIRONMENT_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 28
    melt_ptr_t mcfr_varptr[28];
#define MELTFRAM_NBVARNUM 10
    long mcfr_varnum[10];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_158_WARMELTmiNORMAL_NORMEXP_PARENT_MODULE_ENVIRONMENT is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct
	 meltframe_meltrout_158_WARMELTmiNORMAL_NORMEXP_PARENT_MODULE_ENVIRONMENT_st
	 *) meltfirstargp_;
      /* use arguments meltrout_158_WARMELTmiNORMAL_NORMEXP_PARENT_MODULE_ENVIRONMENT output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 28; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_158_WARMELTmiNORMAL_NORMEXP_PARENT_MODULE_ENVIRONMENT nbval 28*/
  meltfram__.mcfr_nbvar = 28 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMEXP_PARENT_MODULE_ENVIRONMENT", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:8234:/ getarg");
 /*_.RECV__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2])) != NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3])) != NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.PSLOC__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.PSLOC__V5*/ meltfptr[4])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8235:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L1*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_PARENT_MODULE_ENVIRONMENT */ meltfrout->tabval[0])));;
      MELT_LOCATION ("warmelt-normal.melt:8235:/ cond");
      /*cond */ if ( /*_#IS_A__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V7*/ meltfptr[6] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8235:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check parent_module_environment recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8235) ? (8235) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V7*/ meltfptr[6] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V6*/ meltfptr[5] = /*_._IFELSE___V7*/ meltfptr[6];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8235:/ clear");
	     /*clear *//*_#IS_A__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V7*/ meltfptr[6] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V6*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8236:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L2*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:8236:/ cond");
      /*cond */ if ( /*_#IS_A__L2*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[8] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8236:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8236) ? (8236) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[8] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[8];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8236:/ clear");
	     /*clear *//*_#IS_A__L2*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[8] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8237:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:8237:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8237:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8237) ? (8237) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V10*/ meltfptr[8] = /*_._IFELSE___V11*/ meltfptr[10];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8237:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[8] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8238:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L4*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8238:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L5*/ meltfnum[4] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8238:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L5*/ meltfnum[4];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8238;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_parent_module_environment  recv";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V13*/ meltfptr[12] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V12*/ meltfptr[10] =
	      /*_.MELT_DEBUG_FUN__V13*/ meltfptr[12];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8238:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L5*/ meltfnum[4] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V13*/ meltfptr[12] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V12*/ meltfptr[10] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8238:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V12*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:8239:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:8240:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.SLOC__V15*/ meltfptr[10] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8241:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 10, "NCTX_CURPROC");
  /*_.CURPROC__V16*/ meltfptr[15] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8242:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 13, "NCTX_QDATPARMODENV");
  /*_.QDATPAR__V17*/ meltfptr[16] = slot;
    };
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8243:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NREP_QUASICONST_PARENT_MODULE_ENVIRONMENT */ meltfrout->tabval[4])), (4), "CLASS_NREP_QUASICONST_PARENT_MODULE_ENVIRONMENT");
  /*_.INST__V19*/ meltfptr[18] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V19*/ meltfptr[18])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V19*/ meltfptr[18]), (0),
			  ( /*_.SLOC__V15*/ meltfptr[10]), "NREP_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NCONST_SVAL",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V19*/ meltfptr[18])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V19*/ meltfptr[18]), (1),
			  ( /*_.RECV__V2*/ meltfptr[1]), "NCONST_SVAL");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NCONST_PROC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V19*/ meltfptr[18])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V19*/ meltfptr[18]), (2),
			  ( /*_.CURPROC__V16*/ meltfptr[15]), "NCONST_PROC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NCONST_DATA",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V19*/ meltfptr[18])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V19*/ meltfptr[18]), (3),
			  ( /*_.QDATPAR__V17*/ meltfptr[16]), "NCONST_DATA");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V19*/ meltfptr[18],
				  "newly made instance");
    ;
    /*_.NQUASI__V18*/ meltfptr[17] = /*_.INST__V19*/ meltfptr[18];;

    MELT_CHECK_SIGNAL ();
    ;
    /*^compute */
 /*_#IS_A__L6*/ meltfnum[4] =
      melt_is_instance_of ((melt_ptr_t) ( /*_.CURPROC__V16*/ meltfptr[15]),
			   (melt_ptr_t) (( /*!CLASS_NREP_HOOKPROC */
					  meltfrout->tabval[5])));;
    MELT_LOCATION ("warmelt-normal.melt:8250:/ cond");
    /*cond */ if ( /*_#IS_A__L6*/ meltfnum[4])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{


	  {
	    MELT_LOCATION ("warmelt-normal.melt:8251:/ locexp");
	    /* error_plain */
	      melt_error_str ((melt_ptr_t) ( /*_.SLOC__V15*/ meltfptr[10]),
			      ("(PARENT_MODULE_ENVIRONMENT) cannot be used within hooks"),
			      (melt_ptr_t) 0);
	  }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:8252:/ quasiblock");


   /*_._RETVAL___V1*/ meltfptr[0] = NULL;;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:8252:/ locexp");
	    /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
	    if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	      melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
	    ;
	  }
	  ;
	  /*^finalreturn */
	  ;
	  /*finalret */ goto meltlabend_rout;
	  MELT_LOCATION ("warmelt-normal.melt:8250:/ quasiblock");


	  /*_.PROGN___V22*/ meltfptr[21] = /*_.RETURN___V21*/ meltfptr[20];;
	  /*^compute */
	  /*_._IF___V20*/ meltfptr[19] = /*_.PROGN___V22*/ meltfptr[21];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:8250:/ clear");
	     /*clear *//*_.RETURN___V21*/ meltfptr[20] = 0;
	  /*^clear */
	     /*clear *//*_.PROGN___V22*/ meltfptr[21] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

  /*_._IF___V20*/ meltfptr[19] = NULL;;
      }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8253:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L7*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.QDATPAR__V17*/ meltfptr[16]),
			     (melt_ptr_t) (( /*!CLASS_NREP_QUASIDATA_PARENT_MODULE_ENVIRONMENT */ meltfrout->tabval[6])));;
      MELT_LOCATION ("warmelt-normal.melt:8253:/ cond");
      /*cond */ if ( /*_#IS_A__L7*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V24*/ meltfptr[21] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8253:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check qdatpar"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8253) ? (8253) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V24*/ meltfptr[21] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V23*/ meltfptr[20] = /*_._IFELSE___V24*/ meltfptr[21];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8253:/ clear");
	     /*clear *//*_#IS_A__L7*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V24*/ meltfptr[21] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V23*/ meltfptr[20] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    /*^compute */
 /*_#IS_A__L8*/ meltfnum[0] =
      melt_is_instance_of ((melt_ptr_t) ( /*_.CURPROC__V16*/ meltfptr[15]),
			   (melt_ptr_t) (( /*!CLASS_NREP_ROUTPROC */
					  meltfrout->tabval[7])));;
    MELT_LOCATION ("warmelt-normal.melt:8254:/ cond");
    /*cond */ if ( /*_#IS_A__L8*/ meltfnum[0])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  MELT_LOCATION ("warmelt-normal.melt:8255:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.CURPROC__V16*/ meltfptr[15]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 5, "NRPRO_CONST");
    /*_.NRPRO_CONST__V25*/ meltfptr[21] = slot;
	  };
	  ;

	  {
	    /*^locexp */
	    meltgc_append_list ((melt_ptr_t)
				( /*_.NRPRO_CONST__V25*/ meltfptr[21]),
				(melt_ptr_t) ( /*_.QDATPAR__V17*/
					      meltfptr[16]));
	  }
	  ;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:8254:/ clear");
	     /*clear *//*_.NRPRO_CONST__V25*/ meltfptr[21] = 0;
	}
	;
      }				/*noelse */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8256:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L9*/ meltfnum[8] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8256:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L9*/ meltfnum[8])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L10*/ meltfnum[9] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8256:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L10*/ meltfnum[9];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8256;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_parent_module_environment nquasi";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NQUASI__V18*/ meltfptr[17];
	      /*_.MELT_DEBUG_FUN__V27*/ meltfptr[26] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V26*/ meltfptr[21] =
	      /*_.MELT_DEBUG_FUN__V27*/ meltfptr[26];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8256:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L10*/ meltfnum[9] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V27*/ meltfptr[26] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V26*/ meltfptr[21] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8256:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L9*/ meltfnum[8] = 0;
      /*^clear */
	     /*clear *//*_._IF___V26*/ meltfptr[21] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8257:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.NQUASI__V18*/ meltfptr[17];;
    MELT_LOCATION ("warmelt-normal.melt:8257:/ putxtraresult");
    if (!meltxrestab_ || !meltxresdescr_)
      goto meltlabend_rout;
    if (meltxresdescr_[0] != MELTBPAR_PTR)
      goto meltlabend_rout;
    if (meltxrestab_[0].meltbp_aptr)
      *(meltxrestab_[0].meltbp_aptr) = (melt_ptr_t) (( /*nil */ NULL));
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*_.LET___V14*/ meltfptr[12] = /*_.RETURN___V28*/ meltfptr[26];;

    MELT_LOCATION ("warmelt-normal.melt:8239:/ clear");
	   /*clear *//*_.SLOC__V15*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.CURPROC__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.QDATPAR__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.NQUASI__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_#IS_A__L6*/ meltfnum[4] = 0;
    /*^clear */
	   /*clear *//*_._IF___V20*/ meltfptr[19] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V23*/ meltfptr[20] = 0;
    /*^clear */
	   /*clear *//*_#IS_A__L8*/ meltfnum[0] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V28*/ meltfptr[26] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8234:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V14*/ meltfptr[12];;

    {
      MELT_LOCATION ("warmelt-normal.melt:8234:/ locexp");
      /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
      if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
      ;
    }
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*epilog */

    /*^clear */
	   /*clear *//*_.IFCPP___V6*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V8*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V10*/ meltfptr[8] = 0;
    /*^clear */
	   /*clear *//*_.LET___V14*/ meltfptr[12] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMEXP_PARENT_MODULE_ENVIRONMENT", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_158_WARMELTmiNORMAL_NORMEXP_PARENT_MODULE_ENVIRONMENT_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_158_WARMELTmiNORMAL_NORMEXP_PARENT_MODULE_ENVIRONMENT */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_159_WARMELTmiNORMAL_NORMEXP_UPDATE_CURRENT_MODULE_ENVIRONMENT_REFERENCE
  (meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_,
   const melt_argdescr_cell_t meltxargdescr_[],
   union meltparam_un * meltxargtab_,
   const melt_argdescr_cell_t meltxresdescr_[],
   union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_159_WARMELTmiNORMAL_NORMEXP_UPDATE_CURRENT_MODULE_ENVIRONMENT_REFERENCE_melt
    = melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_159_WARMELTmiNORMAL_NORMEXP_UPDATE_CURRENT_MODULE_ENVIRONMENT_REFERENCE_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 77
    melt_ptr_t mcfr_varptr[77];
#define MELTFRAM_NBVARNUM 15
    long mcfr_varnum[15];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_159_WARMELTmiNORMAL_NORMEXP_UPDATE_CURRENT_MODULE_ENVIRONMENT_REFERENCE is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct
	 meltframe_meltrout_159_WARMELTmiNORMAL_NORMEXP_UPDATE_CURRENT_MODULE_ENVIRONMENT_REFERENCE_st
	 *) meltfirstargp_;
      /* use arguments meltrout_159_WARMELTmiNORMAL_NORMEXP_UPDATE_CURRENT_MODULE_ENVIRONMENT_REFERENCE output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 77; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_159_WARMELTmiNORMAL_NORMEXP_UPDATE_CURRENT_MODULE_ENVIRONMENT_REFERENCE nbval 77*/
  meltfram__.mcfr_nbvar = 77 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMEXP_UPDATE_CURRENT_MODULE_ENVIRONMENT_REFERENCE",
		    meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:8263:/ getarg");
 /*_.RECV__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2])) != NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3])) != NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.PSLOC__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.PSLOC__V5*/ meltfptr[4])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8264:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L1*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_UPDATE_CURRENT_MODULE_ENVIRONMENT_REFERENCE */ meltfrout->tabval[0])));;
      MELT_LOCATION ("warmelt-normal.melt:8264:/ cond");
      /*cond */ if ( /*_#IS_A__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V7*/ meltfptr[6] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8264:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check update_current_module_environment_reference recv"), ("warmelt-normal.melt") ? ("warmelt-normal.melt") : __FILE__, (8264) ? (8264) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V7*/ meltfptr[6] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V6*/ meltfptr[5] = /*_._IFELSE___V7*/ meltfptr[6];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8264:/ clear");
	     /*clear *//*_#IS_A__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V7*/ meltfptr[6] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V6*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8265:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L2*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:8265:/ cond");
      /*cond */ if ( /*_#IS_A__L2*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[8] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8265:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8265) ? (8265) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[8] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[8];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8265:/ clear");
	     /*clear *//*_#IS_A__L2*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[8] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8266:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:8266:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8266:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8266) ? (8266) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V10*/ meltfptr[8] = /*_._IFELSE___V11*/ meltfptr[10];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8266:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[8] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8267:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L4*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8267:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L5*/ meltfnum[4] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8267:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[9];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L5*/ meltfnum[4];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8267;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_update_current_module_environment_reference recv=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = "\n env=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.ENV__V3*/ meltfptr[2];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = "\n ncx=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
	      /*_.MELT_DEBUG_FUN__V13*/ meltfptr[12] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V12*/ meltfptr[10] =
	      /*_.MELT_DEBUG_FUN__V13*/ meltfptr[12];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8267:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L5*/ meltfnum[4] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V13*/ meltfptr[12] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V12*/ meltfptr[10] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8267:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V12*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:8270:/ locexp");

#if MELT_HAVE_DEBUG
      if (melt_need_debug (0))
	melt_dbgshortbacktrace (("normexp_update_current_module_environment_reference"), (15));
#endif
      ;
    }
    ;
    MELT_LOCATION ("warmelt-normal.melt:8271:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:8272:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.SLOC__V15*/ meltfptr[10] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8273:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "SUCME_COMMENT");
  /*_.SCOMM__V16*/ meltfptr[15] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8274:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 10, "NCTX_CURPROC");
  /*_.CURPROC__V17*/ meltfptr[16] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8275:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 0, "NCTX_INITPROC");
  /*_.INIPROC__V18*/ meltfptr[17] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8276:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 11, "NCTX_MODULCONTEXT");
  /*_.MODCTX__V19*/ meltfptr[18] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8277:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.MODCTX__V19*/ meltfptr[18]),
					(melt_ptr_t) (( /*!CLASS_ANY_MODULE_CONTEXT */ meltfrout->tabval[4])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.MODCTX__V19*/ meltfptr[18]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 0, "MOCX_MODULENAME");
   /*_.MODNAM__V20*/ meltfptr[19] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.MODNAM__V20*/ meltfptr[19] = NULL;;
      }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    /*^compute */
 /*_#exeq__L6*/ meltfnum[4] =
      (( /*_.CURPROC__V17*/ meltfptr[16]) !=
       ( /*_.INIPROC__V18*/ meltfptr[17]));;
    MELT_LOCATION ("warmelt-normal.melt:8279:/ cond");
    /*cond */ if ( /*_#exeq__L6*/ meltfnum[4])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{


	  {
	    MELT_LOCATION ("warmelt-normal.melt:8281:/ locexp");
	    /* error_plain */
	      melt_error_str ((melt_ptr_t) ( /*_.SLOC__V15*/ meltfptr[10]),
			      ("(UPDATE_CURRENT_MODULE_ENVIRONMENT_REFERENCE) not at toplevel"),
			      (melt_ptr_t) 0);
	  }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:8282:/ quasiblock");


   /*_._RETVAL___V1*/ meltfptr[0] = NULL;;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:8282:/ locexp");
	    /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
	    if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	      melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
	    ;
	  }
	  ;
	  /*^finalreturn */
	  ;
	  /*finalret */ goto meltlabend_rout;
	  MELT_LOCATION ("warmelt-normal.melt:8280:/ quasiblock");


	  /*_.PROGN___V23*/ meltfptr[22] = /*_.RETURN___V22*/ meltfptr[21];;
	  /*^compute */
	  /*_._IF___V21*/ meltfptr[20] = /*_.PROGN___V23*/ meltfptr[22];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:8279:/ clear");
	     /*clear *//*_.RETURN___V22*/ meltfptr[21] = 0;
	  /*^clear */
	     /*clear *//*_.PROGN___V23*/ meltfptr[22] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

  /*_._IF___V21*/ meltfptr[20] = NULL;;
      }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8283:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L7*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8283:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L7*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L8*/ meltfnum[7] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8283:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L8*/ meltfnum[7];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8283;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_update_current_module_environment_reference modctx=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.MODCTX__V19*/ meltfptr[18];
	      /*_.MELT_DEBUG_FUN__V25*/ meltfptr[22] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V24*/ meltfptr[21] =
	      /*_.MELT_DEBUG_FUN__V25*/ meltfptr[22];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8283:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L8*/ meltfnum[7] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V25*/ meltfptr[22] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V24*/ meltfptr[21] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8283:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L7*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V24*/ meltfptr[21] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
 /*_#IS_A__L9*/ meltfnum[7] =
      melt_is_instance_of ((melt_ptr_t) ( /*_.MODCTX__V19*/ meltfptr[18]),
			   (melt_ptr_t) (( /*!CLASS_RUNNING_EXTENSION_MODULE_CONTEXT */ meltfrout->tabval[5])));;
    MELT_LOCATION ("warmelt-normal.melt:8284:/ cond");
    /*cond */ if ( /*_#IS_A__L9*/ meltfnum[7])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  MELT_LOCATION ("warmelt-normal.melt:8285:/ quasiblock");



	  MELT_CHECK_SIGNAL ();
	  ;
	  /*^quasiblock */


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_NREP_CHECK_RUNNING_MODULE_ENVIRONMENT_CONTAINER */ meltfrout->tabval[6])), (2), "CLASS_NREP_CHECK_RUNNING_MODULE_ENVIRONMENT_CONTAINER");
    /*_.INST__V29*/ meltfptr[28] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V29*/ meltfptr[28]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V29*/ meltfptr[28]), (0),
				( /*_.SLOC__V15*/ meltfptr[10]), "NREP_LOC");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NCHRUMOD_COMMENT",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V29*/ meltfptr[28]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V29*/ meltfptr[28]), (1),
				( /*_.SCOMM__V16*/ meltfptr[15]),
				"NCHRUMOD_COMMENT");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V29*/ meltfptr[28],
					"newly made instance");
	  ;
	  /*_.NCHK__V28*/ meltfptr[27] = /*_.INST__V29*/ meltfptr[28];;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:8289:/ apply");
	  /*apply */
	  {
	    /*_.CSYM__V30*/ meltfptr[29] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!CLONE_SYMBOL */ meltfrout->tabval[7])),
			  (melt_ptr_t) (( /*!konst_8_CHECKRUNMODENVBOX_ */
					 meltfrout->tabval[8])), (""),
			  (union meltparam_un *) 0, "",
			  (union meltparam_un *) 0);
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:8290:/ quasiblock");


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_NORMAL_LET_BINDING */ meltfrout->tabval[9])), (4), "CLASS_NORMAL_LET_BINDING");
    /*_.INST__V32*/ meltfptr[31] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @LETBIND_LOC",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V32*/ meltfptr[31]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V32*/ meltfptr[31]), (3),
				( /*_.SLOC__V15*/ meltfptr[10]),
				"LETBIND_LOC");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @BINDER",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V32*/ meltfptr[31]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V32*/ meltfptr[31]), (0),
				( /*_.CSYM__V30*/ meltfptr[29]), "BINDER");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @LETBIND_TYPE",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V32*/ meltfptr[31]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V32*/ meltfptr[31]), (1),
				(( /*!CTYPE_VOID */ meltfrout->tabval[10])),
				"LETBIND_TYPE");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @LETBIND_EXPR",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V32*/ meltfptr[31]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V32*/ meltfptr[31]), (2),
				( /*_.NCHK__V28*/ meltfptr[27]),
				"LETBIND_EXPR");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V32*/ meltfptr[31],
					"newly made instance");
	  ;
	  /*_.CBIND__V31*/ meltfptr[30] = /*_.INST__V32*/ meltfptr[31];;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:8297:/ quasiblock");


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_NREP_LOCSYMOCC */
						   meltfrout->tabval[11])),
				    (4), "CLASS_NREP_LOCSYMOCC");
    /*_.INST__V34*/ meltfptr[33] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V34*/ meltfptr[33]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V34*/ meltfptr[33]), (0),
				( /*_.SLOC__V15*/ meltfptr[10]), "NREP_LOC");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NOCC_CTYP",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V34*/ meltfptr[33]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V34*/ meltfptr[33]), (2),
				(( /*!CTYPE_VOID */ meltfrout->tabval[10])),
				"NOCC_CTYP");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NOCC_SYMB",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V34*/ meltfptr[33]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V34*/ meltfptr[33]), (1),
				( /*_.CSYM__V30*/ meltfptr[29]), "NOCC_SYMB");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NOCC_BIND",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V34*/ meltfptr[33]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V34*/ meltfptr[33]), (3),
				( /*_.CBIND__V31*/ meltfptr[30]),
				"NOCC_BIND");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V34*/ meltfptr[33],
					"newly made instance");
	  ;
	  /*_.CLOCC__V33*/ meltfptr[32] = /*_.INST__V34*/ meltfptr[33];;
	  MELT_LOCATION ("warmelt-normal.melt:8303:/ blockmultialloc");
	  /*multiallocblock */
	  {
	    struct meltletrec_1_st
	    {
	      struct meltpair_st rpair_0__CBIND_x4;
	      struct meltlist_st rlist_1__LIST_;
	      long meltletrec_1_endgap;
	    } *meltletrec_1_ptr = 0;
	    meltletrec_1_ptr =
	      (struct meltletrec_1_st *)
	      meltgc_allocate (sizeof (struct meltletrec_1_st), 0);
	    /*^blockmultialloc.initfill */
	    /*inipair rpair_0__CBIND_x4 */
     /*_.CBIND__V36*/ meltfptr[35] =
	      (melt_ptr_t) & meltletrec_1_ptr->rpair_0__CBIND_x4;
	    meltletrec_1_ptr->rpair_0__CBIND_x4.discr =
	      (meltobject_ptr_t) (((melt_ptr_t) (MELT_PREDEF (DISCR_PAIR))));

	    /*inilist rlist_1__LIST_ */
     /*_.LIST___V37*/ meltfptr[36] =
	      (melt_ptr_t) & meltletrec_1_ptr->rlist_1__LIST_;
	    meltletrec_1_ptr->rlist_1__LIST_.discr =
	      (meltobject_ptr_t) (((melt_ptr_t) (MELT_PREDEF (DISCR_LIST))));



	    /*^putpairhead */
	    /*putpairhead */
	    melt_assertmsg ("putpairhead /f checkpair",
			    melt_magic_discr ((melt_ptr_t)
					      ( /*_.CBIND__V36*/
					       meltfptr[35])) ==
			    MELTOBMAG_PAIR);
	    ((meltpair_ptr_t) ( /*_.CBIND__V36*/ meltfptr[35]))->hd =
	      (melt_ptr_t) ( /*_.CBIND__V31*/ meltfptr[30]);
	    ;
	    /*^touch */
	    meltgc_touch ( /*_.CBIND__V36*/ meltfptr[35]);
	    ;
	    /*^putlist */
	    /*putlist */
	    melt_assertmsg ("putlist checklist",
			    melt_magic_discr ((melt_ptr_t)
					      ( /*_.LIST___V37*/
					       meltfptr[36])) ==
			    MELTOBMAG_LIST);
	    ((meltlist_ptr_t) ( /*_.LIST___V37*/ meltfptr[36]))->first =
	      (meltpair_ptr_t) ( /*_.CBIND__V36*/ meltfptr[35]);
	    ((meltlist_ptr_t) ( /*_.LIST___V37*/ meltfptr[36]))->last =
	      (meltpair_ptr_t) ( /*_.CBIND__V36*/ meltfptr[35]);
	    ;
	    /*^touch */
	    meltgc_touch ( /*_.LIST___V37*/ meltfptr[36]);
	    ;
	    /*_.BINDLIST__V35*/ meltfptr[34] = /*_.LIST___V37*/ meltfptr[36];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8303:/ clear");
	      /*clear *//*_.CBIND__V36*/ meltfptr[35] = 0;
	    /*^clear */
	      /*clear *//*_.LIST___V37*/ meltfptr[36] = 0;
	    /*^clear */
	      /*clear *//*_.CBIND__V36*/ meltfptr[35] = 0;
	    /*^clear */
	      /*clear *//*_.LIST___V37*/ meltfptr[36] = 0;
	  }			/*end multiallocblock */
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:8305:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    {
	      /*^locexp */
	      /*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	      melt_dbgcounter++;
#endif
	      ;
	    }
	    ;

	    MELT_CHECK_SIGNAL ();
	    ;
     /*_#MELT_NEED_DBG__L10*/ meltfnum[0] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:8305:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L10*/ meltfnum[0])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

       /*_#MELT_CALLCOUNT__L11*/ meltfnum[10] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:8305:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[9];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L11*/ meltfnum[10];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 8305;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normexp_update_current_module_environment_reference gives nchk=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.NCHK__V28*/ meltfptr[27];
		    /*^apply.arg */
		    argtab[5].meltbp_cstring = " clocc=";
		    /*^apply.arg */
		    argtab[6].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CLOCC__V33*/ meltfptr[32];
		    /*^apply.arg */
		    argtab[7].meltbp_cstring = " bindlist=";
		    /*^apply.arg */
		    argtab[8].meltbp_aptr =
		      (melt_ptr_t *) & /*_.BINDLIST__V35*/ meltfptr[34];
		    /*_.MELT_DEBUG_FUN__V39*/ meltfptr[36] =
		      melt_apply ((meltclosure_ptr_t)
				  (( /*!MELT_DEBUG_FUN */ meltfrout->
				    tabval[3])),
				  (melt_ptr_t) (( /*nil */ NULL)),
				  (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR ""), argtab, "",
				  (union meltparam_un *) 0);
		  }
		  ;
		  /*_._IF___V38*/ meltfptr[35] =
		    /*_.MELT_DEBUG_FUN__V39*/ meltfptr[36];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:8305:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L11*/ meltfnum[10] = 0;
		  /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V39*/ meltfptr[36] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

      /*_._IF___V38*/ meltfptr[35] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:8305:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	       /*clear *//*_#MELT_NEED_DBG__L10*/ meltfnum[0] = 0;
	    /*^clear */
	       /*clear *//*_._IF___V38*/ meltfptr[35] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*^block */
	  /*anyblock */
	  {


	    {
	      /*^locexp */
	      /*void */ (void) 0;
	    }
	    ;
	    /*epilog */
	  }

#endif /*MELT_HAVE_DEBUG */
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:8307:/ quasiblock");


	  /*_._RETVAL___V1*/ meltfptr[0] = /*_.CLOCC__V33*/ meltfptr[32];;
	  MELT_LOCATION ("warmelt-normal.melt:8307:/ putxtraresult");
	  if (!meltxrestab_ || !meltxresdescr_)
	    goto meltlabend_rout;
	  if (meltxresdescr_[0] != MELTBPAR_PTR)
	    goto meltlabend_rout;
	  if (meltxrestab_[0].meltbp_aptr)
	    *(meltxrestab_[0].meltbp_aptr) =
	      (melt_ptr_t) ( /*_.BINDLIST__V35*/ meltfptr[34]);
	  ;
	  /*^finalreturn */
	  ;
	  /*finalret */ goto meltlabend_rout;
	  /*_.LET___V27*/ meltfptr[21] = /*_.RETURN___V40*/ meltfptr[36];;

	  MELT_LOCATION ("warmelt-normal.melt:8285:/ clear");
	     /*clear *//*_.NCHK__V28*/ meltfptr[27] = 0;
	  /*^clear */
	     /*clear *//*_.CSYM__V30*/ meltfptr[29] = 0;
	  /*^clear */
	     /*clear *//*_.CBIND__V31*/ meltfptr[30] = 0;
	  /*^clear */
	     /*clear *//*_.CLOCC__V33*/ meltfptr[32] = 0;
	  /*^clear */
	     /*clear *//*_.BINDLIST__V35*/ meltfptr[34] = 0;
	  /*^clear */
	     /*clear *//*_.RETURN___V40*/ meltfptr[36] = 0;
	  /*_._IFELSE___V26*/ meltfptr[22] = /*_.LET___V27*/ meltfptr[21];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:8284:/ clear");
	     /*clear *//*_.LET___V27*/ meltfptr[21] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

	/*^block */
	/*anyblock */
	{


	  MELT_CHECK_SIGNAL ();
	  ;
   /*_#IS_A__L12*/ meltfnum[10] =
	    melt_is_instance_of ((melt_ptr_t)
				 ( /*_.MODCTX__V19*/ meltfptr[18]),
				 (melt_ptr_t) (( /*!CLASS_ANY_MODULE_CONTEXT */ meltfrout->tabval[4])));;
	  MELT_LOCATION ("warmelt-normal.melt:8309:/ cond");
	  /*cond */ if ( /*_#IS_A__L12*/ meltfnum[10])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {


#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:8310:/ cppif.then");
		/*^block */
		/*anyblock */
		{


		  MELT_CHECK_SIGNAL ();
		  ;
       /*_#IS_NOT_A__L13*/ meltfnum[0] =
		    !melt_is_instance_of ((melt_ptr_t)
					  ( /*_.MODCTX__V19*/ meltfptr[18]),
					  (melt_ptr_t) (( /*!CLASS_RUNNING_EXTENSION_MODULE_CONTEXT */ meltfrout->tabval[5])));;
		  MELT_LOCATION ("warmelt-normal.melt:8310:/ cond");
		  /*cond */ if ( /*_#IS_NOT_A__L13*/ meltfnum[0])	/*then */
		    {
		      /*^cond.then */
		      /*_._IFELSE___V43*/ meltfptr[29] = ( /*nil */ NULL);;
		    }
		  else
		    {
		      MELT_LOCATION ("warmelt-normal.melt:8310:/ cond.else");

		      /*^block */
		      /*anyblock */
		      {




			{
			  /*^locexp */
			  melt_assert_failed (("check modctx not running"),
					      ("warmelt-normal.melt")
					      ? ("warmelt-normal.melt") :
					      __FILE__,
					      (8310) ? (8310) : __LINE__,
					      __FUNCTION__);
			  ;
			}
			;
		   /*clear *//*_._IFELSE___V43*/ meltfptr[29] = 0;
			/*epilog */
		      }
		      ;
		    }
		  ;
		  /*^compute */
		  /*_.IFCPP___V42*/ meltfptr[27] =
		    /*_._IFELSE___V43*/ meltfptr[29];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:8310:/ clear");
		 /*clear *//*_#IS_NOT_A__L13*/ meltfnum[0] = 0;
		  /*^clear */
		 /*clear *//*_._IFELSE___V43*/ meltfptr[29] = 0;
		}

#else /*MELT_HAVE_DEBUG */
		/*^cppif.else */
		/*_.IFCPP___V42*/ meltfptr[27] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
		;
		MELT_LOCATION ("warmelt-normal.melt:8311:/ quasiblock");



		MELT_CHECK_SIGNAL ();
		;
		/*^quasiblock */


		/*^rawallocobj */
		/*rawallocobj */
		{
		  melt_ptr_t newobj = 0;
		  melt_raw_object_create (newobj,
					  (melt_ptr_t) (( /*!CLASS_NREP_UPDATE_CURRENT_MODULE_ENVIRONMENT_REFERENCE */ meltfrout->tabval[12])), (3), "CLASS_NREP_UPDATE_CURRENT_MODULE_ENVIRONMENT_REFERENCE");
      /*_.INST__V46*/ meltfptr[34] =
		    newobj;
		};
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V46*/
						   meltfptr[34])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V46*/ meltfptr[34]), (0),
				      ( /*_.SLOC__V15*/ meltfptr[10]),
				      "NREP_LOC");
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @NCUMEB_COMMENT",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V46*/
						   meltfptr[34])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V46*/ meltfptr[34]), (2),
				      ( /*_.SCOMM__V16*/ meltfptr[15]),
				      "NCUMEB_COMMENT");
		;
		/*^touchobj */

		melt_dbgtrace_written_object ( /*_.INST__V46*/ meltfptr[34],
					      "newly made instance");
		;
		/*_.NUP__V45*/ meltfptr[32] = /*_.INST__V46*/ meltfptr[34];;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:8316:/ apply");
		/*apply */
		{
		  /*_.CSYM__V47*/ meltfptr[36] =
		    melt_apply ((meltclosure_ptr_t)
				(( /*!CLONE_SYMBOL */ meltfrout->tabval[7])),
				(melt_ptr_t) (( /*!konst_13_UPDATCURMODENVBOX_ */ meltfrout->tabval[13])), (""), (union meltparam_un *) 0, "", (union meltparam_un *) 0);
		}
		;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:8317:/ quasiblock");


		/*^rawallocobj */
		/*rawallocobj */
		{
		  melt_ptr_t newobj = 0;
		  melt_raw_object_create (newobj,
					  (melt_ptr_t) (( /*!CLASS_NORMAL_LET_BINDING */ meltfrout->tabval[9])), (4), "CLASS_NORMAL_LET_BINDING");
      /*_.INST__V49*/ meltfptr[29] =
		    newobj;
		};
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @LETBIND_LOC",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V49*/
						   meltfptr[29])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V49*/ meltfptr[29]), (3),
				      ( /*_.SLOC__V15*/ meltfptr[10]),
				      "LETBIND_LOC");
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @BINDER",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V49*/
						   meltfptr[29])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V49*/ meltfptr[29]), (0),
				      ( /*_.CSYM__V47*/ meltfptr[36]),
				      "BINDER");
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @LETBIND_TYPE",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V49*/
						   meltfptr[29])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V49*/ meltfptr[29]), (1),
				      (( /*!CTYPE_VOID */ meltfrout->
					tabval[10])), "LETBIND_TYPE");
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @LETBIND_EXPR",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V49*/
						   meltfptr[29])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V49*/ meltfptr[29]), (2),
				      ( /*_.NUP__V45*/ meltfptr[32]),
				      "LETBIND_EXPR");
		;
		/*^touchobj */

		melt_dbgtrace_written_object ( /*_.INST__V49*/ meltfptr[29],
					      "newly made instance");
		;
		/*_.CBIND__V48*/ meltfptr[21] = /*_.INST__V49*/ meltfptr[29];;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:8324:/ quasiblock");


		/*^rawallocobj */
		/*rawallocobj */
		{
		  melt_ptr_t newobj = 0;
		  melt_raw_object_create (newobj,
					  (melt_ptr_t) (( /*!CLASS_NREP_LOCSYMOCC */ meltfrout->tabval[11])), (4), "CLASS_NREP_LOCSYMOCC");
      /*_.INST__V51*/ meltfptr[50] =
		    newobj;
		};
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V51*/
						   meltfptr[50])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V51*/ meltfptr[50]), (0),
				      ( /*_.SLOC__V15*/ meltfptr[10]),
				      "NREP_LOC");
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @NOCC_CTYP",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V51*/
						   meltfptr[50])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V51*/ meltfptr[50]), (2),
				      (( /*!CTYPE_VOID */ meltfrout->
					tabval[10])), "NOCC_CTYP");
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @NOCC_SYMB",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V51*/
						   meltfptr[50])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V51*/ meltfptr[50]), (1),
				      ( /*_.CSYM__V47*/ meltfptr[36]),
				      "NOCC_SYMB");
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @NOCC_BIND",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V51*/
						   meltfptr[50])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V51*/ meltfptr[50]), (3),
				      ( /*_.CBIND__V48*/ meltfptr[21]),
				      "NOCC_BIND");
		;
		/*^touchobj */

		melt_dbgtrace_written_object ( /*_.INST__V51*/ meltfptr[50],
					      "newly made instance");
		;
		/*_.CLOCC__V50*/ meltfptr[49] = /*_.INST__V51*/ meltfptr[50];;
		MELT_LOCATION ("warmelt-normal.melt:8330:/ quasiblock");


     /*_.SB__V53*/ meltfptr[52] =
		  (melt_ptr_t)
		  meltgc_new_strbuf ((meltobject_ptr_t)
				     (( /*!DISCR_STRBUF */ meltfrout->
				       tabval[14])), (const char *) 0);;

		{
		  MELT_LOCATION ("warmelt-normal.melt:8331:/ locexp");
		  /*add2sbuf_strconst */
		    meltgc_add_strbuf ((melt_ptr_t)
				       ( /*_.SB__V53*/ meltfptr[52]),
				       ("cur.mod.env.cont : "));
		}
		;

		{
		  MELT_LOCATION ("warmelt-normal.melt:8332:/ locexp");
		  /*add2sbuf_string */
		    meltgc_add_strbuf ((melt_ptr_t)
				       ( /*_.SB__V53*/ meltfptr[52]),
				       melt_string_str ((melt_ptr_t)
							( /*_.SCOMM__V16*/
							 meltfptr[15])));
		}
		;
		/*_.LET___V52*/ meltfptr[51] = /*_.SB__V53*/ meltfptr[52];;

		MELT_LOCATION ("warmelt-normal.melt:8330:/ clear");
	       /*clear *//*_.SB__V53*/ meltfptr[52] = 0;
		/*_.CSBUF__V54*/ meltfptr[52] = /*_.LET___V52*/ meltfptr[51];;

		MELT_CHECK_SIGNAL ();
		;
		/*^compute */
     /*_.STRBUF2STRING__V55*/ meltfptr[54] =
		  (meltgc_new_stringdup
		   ((meltobject_ptr_t)
		    (( /*!DISCR_STRING */ meltfrout->tabval[16])),
		    melt_strbuf_str ((melt_ptr_t)
				     ( /*_.CSBUF__V54*/ meltfptr[52]))));;
		MELT_LOCATION ("warmelt-normal.melt:8334:/ quasiblock");


		/*^rawallocobj */
		/*rawallocobj */
		{
		  melt_ptr_t newobj = 0;
		  melt_raw_object_create (newobj,
					  (melt_ptr_t) (( /*!CLASS_SOURCE_CURRENT_MODULE_ENVIRONMENT_REFERENCE */ meltfrout->tabval[15])), (3), "CLASS_SOURCE_CURRENT_MODULE_ENVIRONMENT_REFERENCE");
      /*_.INST__V57*/ meltfptr[56] =
		    newobj;
		};
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @LOCA_LOCATION",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V57*/
						   meltfptr[56])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V57*/ meltfptr[56]), (1),
				      ( /*_.SLOC__V15*/ meltfptr[10]),
				      "LOCA_LOCATION");
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @CMEC_COMMENT",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V57*/
						   meltfptr[56])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V57*/ meltfptr[56]), (2),
				      ( /*_.STRBUF2STRING__V55*/
				       meltfptr[54]), "CMEC_COMMENT");
		;
		/*^touchobj */

		melt_dbgtrace_written_object ( /*_.INST__V57*/ meltfptr[56],
					      "newly made instance");
		;
		/*_.SCURENVBOX__V56*/ meltfptr[55] =
		  /*_.INST__V57*/ meltfptr[56];;

		MELT_CHECK_SIGNAL ();
		;

		MELT_CHECK_SIGNAL ();
		;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:8349:/ quasiblock");


		/*^rawallocobj */
		/*rawallocobj */
		{
		  melt_ptr_t newobj = 0;
		  melt_raw_object_create (newobj,
					  (melt_ptr_t) (( /*!CLASS_SOURCE_PARENT_MODULE_ENVIRONMENT */ meltfrout->tabval[20])), (2), "CLASS_SOURCE_PARENT_MODULE_ENVIRONMENT");
      /*_.INST__V59*/ meltfptr[58] =
		    newobj;
		};
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @LOCA_LOCATION",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V59*/
						   meltfptr[58])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V59*/ meltfptr[58]), (1),
				      ( /*_.PSLOC__V5*/ meltfptr[4]),
				      "LOCA_LOCATION");
		;
		/*^touchobj */

		melt_dbgtrace_written_object ( /*_.INST__V59*/ meltfptr[58],
					      "newly made instance");
		;
		/*_.INST___V58*/ meltfptr[57] = /*_.INST__V59*/ meltfptr[58];;
		MELT_LOCATION ("warmelt-normal.melt:8348:/ blockmultialloc");
		/*multiallocblock */
		{
		  struct meltletrec_2_st
		  {
		    struct MELT_MULTIPLE_STRUCT (2) rtup_0__TUPLREC__x23;
		    long meltletrec_2_endgap;
		  } *meltletrec_2_ptr = 0;
		  meltletrec_2_ptr =
		    (struct meltletrec_2_st *)
		    meltgc_allocate (sizeof (struct meltletrec_2_st), 0);
		  /*^blockmultialloc.initfill */
		  /*inimult rtup_0__TUPLREC__x23 */
 /*_.TUPLREC___V61*/ meltfptr[60] =
		    (melt_ptr_t) & meltletrec_2_ptr->rtup_0__TUPLREC__x23;
		  meltletrec_2_ptr->rtup_0__TUPLREC__x23.discr =
		    (meltobject_ptr_t) (((melt_ptr_t)
					 (MELT_PREDEF (DISCR_MULTIPLE))));
		  meltletrec_2_ptr->rtup_0__TUPLREC__x23.nbval = 2;


		  /*^putuple */
		  /*putupl#59 */
		  melt_assertmsg ("putupl [:8348] #59 checktup",
				  melt_magic_discr ((melt_ptr_t)
						    ( /*_.TUPLREC___V61*/
						     meltfptr[60])) ==
				  MELTOBMAG_MULTIPLE);
		  melt_assertmsg ("putupl [:8348] #59 checkoff",
				  (0 >= 0
				   && 0 <
				   melt_multiple_length ((melt_ptr_t)
							 ( /*_.TUPLREC___V61*/
							  meltfptr[60]))));
		  ((meltmultiple_ptr_t) ( /*_.TUPLREC___V61*/ meltfptr[60]))->
		    tabval[0] = (melt_ptr_t) ( /*_.INST___V58*/ meltfptr[57]);
		  ;
		  /*^putuple */
		  /*putupl#60 */
		  melt_assertmsg ("putupl [:8348] #60 checktup",
				  melt_magic_discr ((melt_ptr_t)
						    ( /*_.TUPLREC___V61*/
						     meltfptr[60])) ==
				  MELTOBMAG_MULTIPLE);
		  melt_assertmsg ("putupl [:8348] #60 checkoff",
				  (1 >= 0
				   && 1 <
				   melt_multiple_length ((melt_ptr_t)
							 ( /*_.TUPLREC___V61*/
							  meltfptr[60]))));
		  ((meltmultiple_ptr_t) ( /*_.TUPLREC___V61*/ meltfptr[60]))->
		    tabval[1] =
		    (melt_ptr_t) ( /*_.MODNAM__V20*/ meltfptr[19]);
		  ;
		  /*^touch */
		  meltgc_touch ( /*_.TUPLREC___V61*/ meltfptr[60]);
		  ;
		  /*_.TUPLE___V60*/ meltfptr[59] =
		    /*_.TUPLREC___V61*/ meltfptr[60];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:8348:/ clear");
		/*clear *//*_.TUPLREC___V61*/ meltfptr[60] = 0;
		  /*^clear */
		/*clear *//*_.TUPLREC___V61*/ meltfptr[60] = 0;
		}		/*end multiallocblock */
		;
		MELT_LOCATION ("warmelt-normal.melt:8344:/ quasiblock");


		/*^rawallocobj */
		/*rawallocobj */
		{
		  melt_ptr_t newobj = 0;
		  melt_raw_object_create (newobj,
					  (melt_ptr_t) (( /*!CLASS_SOURCE_HOOK_CALL */ meltfrout->tabval[18])), (4), "CLASS_SOURCE_HOOK_CALL");
      /*_.INST__V63*/ meltfptr[62] =
		    newobj;
		};
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @LOCA_LOCATION",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V63*/
						   meltfptr[62])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V63*/ meltfptr[62]), (1),
				      ( /*_.PSLOC__V5*/ meltfptr[4]),
				      "LOCA_LOCATION");
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @SHOOK_CALLED",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V63*/
						   meltfptr[62])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V63*/ meltfptr[62]), (3),
				      (( /*!HOOK_FRESH_ENVIRONMENT_REFERENCE_MAKER */ meltfrout->tabval[19])), "SHOOK_CALLED");
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @SARGOP_ARGS",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V63*/
						   meltfptr[62])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V63*/ meltfptr[62]), (2),
				      ( /*_.TUPLE___V60*/ meltfptr[59]),
				      "SARGOP_ARGS");
		;
		/*^touchobj */

		melt_dbgtrace_written_object ( /*_.INST__V63*/ meltfptr[62],
					      "newly made instance");
		;
		/*_.INST___V62*/ meltfptr[60] = /*_.INST__V63*/ meltfptr[62];;
		MELT_LOCATION ("warmelt-normal.melt:8342:/ blockmultialloc");
		/*multiallocblock */
		{
		  struct meltletrec_3_st
		  {
		    struct MELT_MULTIPLE_STRUCT (2) rtup_0__TUPLREC__x22;
		    long meltletrec_3_endgap;
		  } *meltletrec_3_ptr = 0;
		  meltletrec_3_ptr =
		    (struct meltletrec_3_st *)
		    meltgc_allocate (sizeof (struct meltletrec_3_st), 0);
		  /*^blockmultialloc.initfill */
		  /*inimult rtup_0__TUPLREC__x22 */
 /*_.TUPLREC___V65*/ meltfptr[64] =
		    (melt_ptr_t) & meltletrec_3_ptr->rtup_0__TUPLREC__x22;
		  meltletrec_3_ptr->rtup_0__TUPLREC__x22.discr =
		    (meltobject_ptr_t) (((melt_ptr_t)
					 (MELT_PREDEF (DISCR_MULTIPLE))));
		  meltletrec_3_ptr->rtup_0__TUPLREC__x22.nbval = 2;


		  /*^putuple */
		  /*putupl#61 */
		  melt_assertmsg ("putupl [:8342] #61 checktup",
				  melt_magic_discr ((melt_ptr_t)
						    ( /*_.TUPLREC___V65*/
						     meltfptr[64])) ==
				  MELTOBMAG_MULTIPLE);
		  melt_assertmsg ("putupl [:8342] #61 checkoff",
				  (0 >= 0
				   && 0 <
				   melt_multiple_length ((melt_ptr_t)
							 ( /*_.TUPLREC___V65*/
							  meltfptr[64]))));
		  ((meltmultiple_ptr_t) ( /*_.TUPLREC___V65*/ meltfptr[64]))->
		    tabval[0] =
		    (melt_ptr_t) ( /*_.SCURENVBOX__V56*/ meltfptr[55]);
		  ;
		  /*^putuple */
		  /*putupl#62 */
		  melt_assertmsg ("putupl [:8342] #62 checktup",
				  melt_magic_discr ((melt_ptr_t)
						    ( /*_.TUPLREC___V65*/
						     meltfptr[64])) ==
				  MELTOBMAG_MULTIPLE);
		  melt_assertmsg ("putupl [:8342] #62 checkoff",
				  (1 >= 0
				   && 1 <
				   melt_multiple_length ((melt_ptr_t)
							 ( /*_.TUPLREC___V65*/
							  meltfptr[64]))));
		  ((meltmultiple_ptr_t) ( /*_.TUPLREC___V65*/ meltfptr[64]))->
		    tabval[1] = (melt_ptr_t) ( /*_.INST___V62*/ meltfptr[60]);
		  ;
		  /*^touch */
		  meltgc_touch ( /*_.TUPLREC___V65*/ meltfptr[64]);
		  ;
		  /*_.TUPLE___V64*/ meltfptr[63] =
		    /*_.TUPLREC___V65*/ meltfptr[64];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:8342:/ clear");
		/*clear *//*_.TUPLREC___V65*/ meltfptr[64] = 0;
		  /*^clear */
		/*clear *//*_.TUPLREC___V65*/ meltfptr[64] = 0;
		}		/*end multiallocblock */
		;
		MELT_LOCATION ("warmelt-normal.melt:8338:/ quasiblock");


		/*^rawallocobj */
		/*rawallocobj */
		{
		  melt_ptr_t newobj = 0;
		  melt_raw_object_create (newobj,
					  (melt_ptr_t) (( /*!CLASS_SOURCE_OR */ meltfrout->tabval[17])), (3), "CLASS_SOURCE_OR");
      /*_.INST__V67*/ meltfptr[66] =
		    newobj;
		};
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @LOCA_LOCATION",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V67*/
						   meltfptr[66])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V67*/ meltfptr[66]), (1),
				      ( /*_.PSLOC__V5*/ meltfptr[4]),
				      "LOCA_LOCATION");
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @SOR_DISJ",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V67*/
						   meltfptr[66])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V67*/ meltfptr[66]), (2),
				      ( /*_.TUPLE___V64*/ meltfptr[63]),
				      "SOR_DISJ");
		;
		/*^touchobj */

		melt_dbgtrace_written_object ( /*_.INST__V67*/ meltfptr[66],
					      "newly made instance");
		;
		/*_.SGETCURENVBOX__V66*/ meltfptr[64] =
		  /*_.INST__V67*/ meltfptr[66];;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:8355:/ quasiblock");


		/*^multimsend */
		/*multimsend */
		{
		  union meltparam_un argtab[3];
		  union meltparam_un restab[1];
		  memset (&argtab, 0, sizeof (argtab));
		  memset (&restab, 0, sizeof (restab));
		  /*^multimsend.arg */
		  argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.ENV__V3*/ meltfptr[2];	/*^multimsend.arg */
		  argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];	/*^multimsend.arg */
		  argtab[2].meltbp_aptr =
		    (melt_ptr_t *) & /*_.SLOC__V15*/ meltfptr[10];
		  /*^multimsend.xres */
		  restab[0].meltbp_aptr = (melt_ptr_t *) & /*_.BINDLIST__V70*/ meltfptr[69];	/*^multimsend.send */
		  /*_.NCURENVBOX__V69*/ meltfptr[68] =
		    meltgc_send ((melt_ptr_t)
				 ( /*_.SGETCURENVBOX__V66*/ meltfptr[64]),
				 ((melt_ptr_t)
				  (( /*!NORMAL_EXP */ meltfrout->
				    tabval[21]))),
				 (MELTBPARSTR_PTR MELTBPARSTR_PTR
				  MELTBPARSTR_PTR ""), argtab,
				 (MELTBPARSTR_PTR ""), restab);
		}
		;
		/*^quasiblock */



		{
		  MELT_LOCATION ("warmelt-normal.melt:8358:/ locexp");
		  meltgc_append_list ((melt_ptr_t)
				      ( /*_.BINDLIST__V70*/ meltfptr[69]),
				      (melt_ptr_t) ( /*_.CBIND__V48*/
						    meltfptr[21]));
		}
		;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:8359:/ quasiblock");


		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @NUCMEB_EXPR",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.NUP__V45*/
						   meltfptr[32])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.NUP__V45*/ meltfptr[32]), (1),
				      ( /*_.NCURENVBOX__V69*/ meltfptr[68]),
				      "NUCMEB_EXPR");
		;
		/*^touch */
		meltgc_touch ( /*_.NUP__V45*/ meltfptr[32]);
		;
		/*^touchobj */

		melt_dbgtrace_written_object ( /*_.NUP__V45*/ meltfptr[32],
					      "put-fields");
		;


#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:8360:/ cppif.then");
		/*^block */
		/*anyblock */
		{


		  {
		    /*^locexp */
		    /*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
		    melt_dbgcounter++;
#endif
		    ;
		  }
		  ;

		  MELT_CHECK_SIGNAL ();
		  ;
       /*_#MELT_NEED_DBG__L14*/ meltfnum[0] =
		    /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
		    ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
		    0		/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
		    ;;
		  MELT_LOCATION ("warmelt-normal.melt:8360:/ cond");
		  /*cond */ if ( /*_#MELT_NEED_DBG__L14*/ meltfnum[0])	/*then */
		    {
		      /*^cond.then */
		      /*^block */
		      /*anyblock */
		      {

	 /*_#MELT_CALLCOUNT__L15*/ meltfnum[14] =
			  /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
			  meltcallcount	/* melt_callcount debugging */
#else
			  0L	/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
			  ;;

			MELT_CHECK_SIGNAL ();
			;
			MELT_LOCATION ("warmelt-normal.melt:8360:/ apply");
			/*apply */
			{
			  union meltparam_un argtab[7];
			  memset (&argtab, 0, sizeof (argtab));
			  /*^apply.arg */
			  argtab[0].meltbp_long =
			    /*_#MELT_CALLCOUNT__L15*/ meltfnum[14];
			  /*^apply.arg */
			  argtab[1].meltbp_cstring = "warmelt-normal.melt";
			  /*^apply.arg */
			  argtab[2].meltbp_long = 8360;
			  /*^apply.arg */
			  argtab[3].meltbp_cstring =
			    "normexp_update_current_module_environment_reference result bindlist=";
			  /*^apply.arg */
			  argtab[4].meltbp_aptr =
			    (melt_ptr_t *) & /*_.BINDLIST__V70*/ meltfptr[69];
			  /*^apply.arg */
			  argtab[5].meltbp_cstring = " clocc=";
			  /*^apply.arg */
			  argtab[6].meltbp_aptr =
			    (melt_ptr_t *) & /*_.CLOCC__V50*/ meltfptr[49];
			  /*_.MELT_DEBUG_FUN__V72*/ meltfptr[71] =
			    melt_apply ((meltclosure_ptr_t)
					(( /*!MELT_DEBUG_FUN */ meltfrout->
					  tabval[3])),
					(melt_ptr_t) (( /*nil */ NULL)),
					(MELTBPARSTR_LONG MELTBPARSTR_CSTRING
					 MELTBPARSTR_LONG MELTBPARSTR_CSTRING
					 MELTBPARSTR_PTR MELTBPARSTR_CSTRING
					 MELTBPARSTR_PTR ""), argtab, "",
					(union meltparam_un *) 0);
			}
			;
			/*_._IF___V71*/ meltfptr[70] =
			  /*_.MELT_DEBUG_FUN__V72*/ meltfptr[71];;
			/*epilog */

			MELT_LOCATION ("warmelt-normal.melt:8360:/ clear");
		   /*clear *//*_#MELT_CALLCOUNT__L15*/ meltfnum[14] = 0;
			/*^clear */
		   /*clear *//*_.MELT_DEBUG_FUN__V72*/ meltfptr[71] = 0;
		      }
		      ;
		    }
		  else
		    {		/*^cond.else */

	/*_._IF___V71*/ meltfptr[70] = NULL;;
		    }
		  ;

		  {
		    MELT_LOCATION ("warmelt-normal.melt:8360:/ locexp");
		    /*void */ (void) 0;
		  }
		  ;
		  /*^quasiblock */


		  /*epilog */

		  /*^clear */
		 /*clear *//*_#MELT_NEED_DBG__L14*/ meltfnum[0] = 0;
		  /*^clear */
		 /*clear *//*_._IF___V71*/ meltfptr[70] = 0;
		}

#else /*MELT_HAVE_DEBUG */
		/*^cppif.else */
		/*^block */
		/*anyblock */
		{


		  {
		    /*^locexp */
		    /*void */ (void) 0;
		  }
		  ;
		  /*epilog */
		}

#endif /*MELT_HAVE_DEBUG */
		;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:8361:/ quasiblock");


		/*_._RETVAL___V1*/ meltfptr[0] =
		  /*_.CLOCC__V50*/ meltfptr[49];;
		MELT_LOCATION ("warmelt-normal.melt:8361:/ putxtraresult");
		if (!meltxrestab_ || !meltxresdescr_)
		  goto meltlabend_rout;
		if (meltxresdescr_[0] != MELTBPAR_PTR)
		  goto meltlabend_rout;
		if (meltxrestab_[0].meltbp_aptr)
		  *(meltxrestab_[0].meltbp_aptr) =
		    (melt_ptr_t) ( /*_.BINDLIST__V70*/ meltfptr[69]);
		;
		/*^finalreturn */
		;
		/*finalret */ goto meltlabend_rout;

		MELT_CHECK_SIGNAL ();
		;
		/*_.MULTI___V68*/ meltfptr[67] =
		  /*_.RETURN___V73*/ meltfptr[71];;

		MELT_LOCATION ("warmelt-normal.melt:8355:/ clear");
	       /*clear *//*_.RETURN___V73*/ meltfptr[71] = 0;

		/*^clear */
	       /*clear *//*_.BINDLIST__V70*/ meltfptr[69] = 0;
		/*_.LET___V44*/ meltfptr[30] =
		  /*_.MULTI___V68*/ meltfptr[67];;

		MELT_LOCATION ("warmelt-normal.melt:8311:/ clear");
	       /*clear *//*_.NUP__V45*/ meltfptr[32] = 0;
		/*^clear */
	       /*clear *//*_.CSYM__V47*/ meltfptr[36] = 0;
		/*^clear */
	       /*clear *//*_.CBIND__V48*/ meltfptr[21] = 0;
		/*^clear */
	       /*clear *//*_.CLOCC__V50*/ meltfptr[49] = 0;
		/*^clear */
	       /*clear *//*_.LET___V52*/ meltfptr[51] = 0;
		/*^clear */
	       /*clear *//*_.CSBUF__V54*/ meltfptr[52] = 0;
		/*^clear */
	       /*clear *//*_.STRBUF2STRING__V55*/ meltfptr[54] = 0;
		/*^clear */
	       /*clear *//*_.SCURENVBOX__V56*/ meltfptr[55] = 0;
		/*^clear */
	       /*clear *//*_.INST___V58*/ meltfptr[57] = 0;
		/*^clear */
	       /*clear *//*_.TUPLE___V60*/ meltfptr[59] = 0;
		/*^clear */
	       /*clear *//*_.INST___V62*/ meltfptr[60] = 0;
		/*^clear */
	       /*clear *//*_.TUPLE___V64*/ meltfptr[63] = 0;
		/*^clear */
	       /*clear *//*_.SGETCURENVBOX__V66*/ meltfptr[64] = 0;
		/*^clear */
	       /*clear *//*_.MULTI___V68*/ meltfptr[67] = 0;
		MELT_LOCATION ("warmelt-normal.melt:8309:/ quasiblock");


		/*_.PROGN___V74*/ meltfptr[70] =
		  /*_.LET___V44*/ meltfptr[30];;
		/*^compute */
		/*_._IFELSE___V41*/ meltfptr[35] =
		  /*_.PROGN___V74*/ meltfptr[70];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:8309:/ clear");
	       /*clear *//*_.IFCPP___V42*/ meltfptr[27] = 0;
		/*^clear */
	       /*clear *//*_.LET___V44*/ meltfptr[30] = 0;
		/*^clear */
	       /*clear *//*_.PROGN___V74*/ meltfptr[70] = 0;
	      }
	      ;
	    }
	  else
	    {			/*^cond.else */

	      /*^block */
	      /*anyblock */
	      {


#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:8365:/ cppif.then");
		/*^block */
		/*anyblock */
		{


		  MELT_CHECK_SIGNAL ();
		  ;
		  /*^cond */
		  /*cond */ if (( /*nil */ NULL))	/*then */
		    {
		      /*^cond.then */
		      /*_._IFELSE___V76*/ meltfptr[68] = ( /*nil */ NULL);;
		    }
		  else
		    {
		      MELT_LOCATION ("warmelt-normal.melt:8365:/ cond.else");

		      /*^block */
		      /*anyblock */
		      {




			{
			  /*^locexp */
			  melt_assert_failed (("normexp_update_current_module_environment_reference unexpected module\
 context"), ("warmelt-normal.melt") ? ("warmelt-normal.melt") : __FILE__,
					      (8365) ? (8365) : __LINE__, __FUNCTION__);
			  ;
			}
			;
		   /*clear *//*_._IFELSE___V76*/ meltfptr[68] = 0;
			/*epilog */
		      }
		      ;
		    }
		  ;
		  /*^compute */
		  /*_.IFCPP___V75*/ meltfptr[71] =
		    /*_._IFELSE___V76*/ meltfptr[68];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:8365:/ clear");
		 /*clear *//*_._IFELSE___V76*/ meltfptr[68] = 0;
		}

#else /*MELT_HAVE_DEBUG */
		/*^cppif.else */
		/*_.IFCPP___V75*/ meltfptr[71] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
		;
		MELT_LOCATION ("warmelt-normal.melt:8364:/ quasiblock");


		/*_.PROGN___V77*/ meltfptr[69] =
		  /*_.IFCPP___V75*/ meltfptr[71];;
		/*^compute */
		/*_._IFELSE___V41*/ meltfptr[35] =
		  /*_.PROGN___V77*/ meltfptr[69];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:8309:/ clear");
	       /*clear *//*_.IFCPP___V75*/ meltfptr[71] = 0;
		/*^clear */
	       /*clear *//*_.PROGN___V77*/ meltfptr[69] = 0;
	      }
	      ;
	    }
	  ;
	  /*_._IFELSE___V26*/ meltfptr[22] =
	    /*_._IFELSE___V41*/ meltfptr[35];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:8284:/ clear");
	     /*clear *//*_#IS_A__L12*/ meltfnum[10] = 0;
	  /*^clear */
	     /*clear *//*_._IFELSE___V41*/ meltfptr[35] = 0;
	}
	;
      }
    ;
    /*_.LET___V14*/ meltfptr[12] = /*_._IFELSE___V26*/ meltfptr[22];;

    MELT_LOCATION ("warmelt-normal.melt:8271:/ clear");
	   /*clear *//*_.SLOC__V15*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.SCOMM__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.CURPROC__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.INIPROC__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.MODCTX__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.MODNAM__V20*/ meltfptr[19] = 0;
    /*^clear */
	   /*clear *//*_#exeq__L6*/ meltfnum[4] = 0;
    /*^clear */
	   /*clear *//*_._IF___V21*/ meltfptr[20] = 0;
    /*^clear */
	   /*clear *//*_#IS_A__L9*/ meltfnum[7] = 0;
    /*^clear */
	   /*clear *//*_._IFELSE___V26*/ meltfptr[22] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8263:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V14*/ meltfptr[12];;

    {
      MELT_LOCATION ("warmelt-normal.melt:8263:/ locexp");
      /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
      if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
      ;
    }
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*epilog */

    /*^clear */
	   /*clear *//*_.IFCPP___V6*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V8*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V10*/ meltfptr[8] = 0;
    /*^clear */
	   /*clear *//*_.LET___V14*/ meltfptr[12] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMEXP_UPDATE_CURRENT_MODULE_ENVIRONMENT_REFERENCE",
		  meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_159_WARMELTmiNORMAL_NORMEXP_UPDATE_CURRENT_MODULE_ENVIRONMENT_REFERENCE_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_159_WARMELTmiNORMAL_NORMEXP_UPDATE_CURRENT_MODULE_ENVIRONMENT_REFERENCE */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_160_WARMELTmiNORMAL_NORMEXP_FETCH_PREDEFINED (meltclosure_ptr_t
						       meltclosp_,
						       melt_ptr_t
						       meltfirstargp_,
						       const
						       melt_argdescr_cell_t
						       meltxargdescr_[],
						       union meltparam_un *
						       meltxargtab_,
						       const
						       melt_argdescr_cell_t
						       meltxresdescr_[],
						       union meltparam_un *
						       meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_160_WARMELTmiNORMAL_NORMEXP_FETCH_PREDEFINED_melt
    = melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_160_WARMELTmiNORMAL_NORMEXP_FETCH_PREDEFINED_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 35
    melt_ptr_t mcfr_varptr[35];
#define MELTFRAM_NBVARNUM 15
    long mcfr_varnum[15];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_160_WARMELTmiNORMAL_NORMEXP_FETCH_PREDEFINED is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct
	 meltframe_meltrout_160_WARMELTmiNORMAL_NORMEXP_FETCH_PREDEFINED_st *)
	meltfirstargp_;
      /* use arguments meltrout_160_WARMELTmiNORMAL_NORMEXP_FETCH_PREDEFINED output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 35; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_160_WARMELTmiNORMAL_NORMEXP_FETCH_PREDEFINED nbval 35*/
  meltfram__.mcfr_nbvar = 35 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMEXP_FETCH_PREDEFINED", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:8372:/ getarg");
 /*_.RECV__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2])) != NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3])) != NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.PSLOC__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.PSLOC__V5*/ meltfptr[4])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8373:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L1*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_FETCH_PREDEFINED */ meltfrout->tabval[0])));;
      MELT_LOCATION ("warmelt-normal.melt:8373:/ cond");
      /*cond */ if ( /*_#IS_A__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V7*/ meltfptr[6] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8373:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check fetch_predefined recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8373) ? (8373) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V7*/ meltfptr[6] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V6*/ meltfptr[5] = /*_._IFELSE___V7*/ meltfptr[6];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8373:/ clear");
	     /*clear *//*_#IS_A__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V7*/ meltfptr[6] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V6*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8374:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L2*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:8374:/ cond");
      /*cond */ if ( /*_#IS_A__L2*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[8] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8374:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8374) ? (8374) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[8] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[8];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8374:/ clear");
	     /*clear *//*_#IS_A__L2*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[8] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8375:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:8375:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8375:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8375) ? (8375) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V10*/ meltfptr[8] = /*_._IFELSE___V11*/ meltfptr[10];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8375:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[8] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8376:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L4*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8376:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L5*/ meltfnum[4] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8376:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L5*/ meltfnum[4];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8376;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_fetch_predefined recv";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V13*/ meltfptr[12] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V12*/ meltfptr[10] =
	      /*_.MELT_DEBUG_FUN__V13*/ meltfptr[12];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8376:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L5*/ meltfnum[4] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V13*/ meltfptr[12] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V12*/ meltfptr[10] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8376:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V12*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:8377:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:8378:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.SLOC__V15*/ meltfptr[10] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8379:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "SFEPD_PREDEF");
  /*_.SPRED__V16*/ meltfptr[15] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8380:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 7, "NCTX_PREDEFMAP");
  /*_.PREDEFMAP__V17*/ meltfptr[16] = slot;
    };
    ;

    MELT_CHECK_SIGNAL ();
    ;
 /*_#IS_A__L6*/ meltfnum[4] =
      melt_is_instance_of ((melt_ptr_t) ( /*_.SPRED__V16*/ meltfptr[15]),
			   (melt_ptr_t) (( /*!CLASS_SYMBOL */ meltfrout->
					  tabval[4])));;
    MELT_LOCATION ("warmelt-normal.melt:8382:/ cond");
    /*cond */ if ( /*_#IS_A__L6*/ meltfnum[4])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  MELT_LOCATION ("warmelt-normal.melt:8384:/ quasiblock");



	  MELT_CHECK_SIGNAL ();
	  ;
	  /*^quasiblock */


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_REFERENCE */
						   meltfrout->tabval[5])),
				    (1), "CLASS_REFERENCE");
    /*_.INST__V20*/ meltfptr[19] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @REFERENCED_VALUE",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V20*/ meltfptr[19]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V20*/ meltfptr[19]), (0),
				(( /*nil */ NULL)), "REFERENCED_VALUE");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V20*/ meltfptr[19],
					"newly made instance");
	  ;
	  /*_.CONTK__V19*/ meltfptr[18] = /*_.INST__V20*/ meltfptr[19];;
	  MELT_LOCATION ("warmelt-normal.melt:8387:/ quasiblock");


	  /*^newclosure */
		   /*newclosure *//*_.LAMBDA___V22*/ meltfptr[21] =
	    (melt_ptr_t)
	    meltgc_new_closure ((meltobject_ptr_t)
				(((melt_ptr_t)
				  (MELT_PREDEF (DISCR_CLOSURE)))),
				(meltroutine_ptr_t) (( /*!konst_8 */
						      meltfrout->tabval[8])),
				(2));
	  ;
	  /*^putclosedv */
	  /*putclosv */
	  melt_assertmsg ("putclosv checkclo",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.LAMBDA___V22*/
					     meltfptr[21])) ==
			  MELTOBMAG_CLOSURE);
	  melt_assertmsg ("putclosv checkoff", 0 >= 0
			  && 0 <
			  melt_closure_size ((melt_ptr_t)
					     ( /*_.LAMBDA___V22*/
					      meltfptr[21])));
	  ((meltclosure_ptr_t) /*_.LAMBDA___V22*/ meltfptr[21])->tabval[0] =
	    (melt_ptr_t) ( /*_.SPRED__V16*/ meltfptr[15]);
	  ;
	  /*^putclosedv */
	  /*putclosv */
	  melt_assertmsg ("putclosv checkclo",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.LAMBDA___V22*/
					     meltfptr[21])) ==
			  MELTOBMAG_CLOSURE);
	  melt_assertmsg ("putclosv checkoff", 1 >= 0
			  && 1 <
			  melt_closure_size ((melt_ptr_t)
					     ( /*_.LAMBDA___V22*/
					      meltfptr[21])));
	  ((meltclosure_ptr_t) /*_.LAMBDA___V22*/ meltfptr[21])->tabval[1] =
	    (melt_ptr_t) ( /*_.CONTK__V19*/ meltfptr[18]);
	  ;
	  /*_.LAMBDA___V21*/ meltfptr[20] = /*_.LAMBDA___V22*/ meltfptr[21];;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:8386:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[1];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.LAMBDA___V21*/ meltfptr[20];
	    /*_.MAPOBJECT_EVERY__V23*/ meltfptr[22] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!MAPOBJECT_EVERY */ meltfrout->tabval[6])),
			  (melt_ptr_t) ( /*_.PREDEFMAP__V17*/ meltfptr[16]),
			  (MELTBPARSTR_PTR ""), argtab, "",
			  (union meltparam_un *) 0);
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:8389:/ cond");
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.CONTK__V19*/
					       meltfptr[18]),
					      (melt_ptr_t) (( /*!CLASS_REFERENCE */ meltfrout->tabval[5])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^getslot */
	      {
		melt_ptr_t slot = NULL, obj = NULL;
		obj = (melt_ptr_t) ( /*_.CONTK__V19*/ meltfptr[18]) /*=obj*/ ;
		melt_object_get_field (slot, obj, 0, "REFERENCED_VALUE");
     /*_.REFERENCED_VALUE__V24*/ meltfptr[23] = slot;
	      };
	      ;
	    }
	  else
	    {			/*^cond.else */

    /*_.REFERENCED_VALUE__V24*/ meltfptr[23] = NULL;;
	    }
	  ;
	  /*^compute */
   /*_#NULL__L7*/ meltfnum[0] =
	    (( /*_.REFERENCED_VALUE__V24*/ meltfptr[23]) == NULL);;
	  MELT_LOCATION ("warmelt-normal.melt:8389:/ cond");
	  /*cond */ if ( /*_#NULL__L7*/ meltfnum[0])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		MELT_LOCATION ("warmelt-normal.melt:8391:/ getslot");
		{
		  melt_ptr_t slot = NULL, obj = NULL;
		  obj =
		    (melt_ptr_t) ( /*_.SPRED__V16*/ meltfptr[15]) /*=obj*/ ;
		  melt_object_get_field (slot, obj, 1, "NAMED_NAME");
      /*_.NAMED_NAME__V25*/ meltfptr[24] = slot;
		};
		;

		{
		  MELT_LOCATION ("warmelt-normal.melt:8390:/ locexp");
		  melt_warning_str (0,
				    (melt_ptr_t) ( /*_.SLOC__V15*/
						  meltfptr[10]),
				    ("FETCH_PREDEFINED unknown predef name"),
				    (melt_ptr_t) ( /*_.NAMED_NAME__V25*/
						  meltfptr[24]));
		}
		;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:8389:/ clear");
	       /*clear *//*_.NAMED_NAME__V25*/ meltfptr[24] = 0;
	      }
	      ;
	    }			/*noelse */
	  ;
	  /*_._IFELSE___V18*/ meltfptr[17] =
	    /*_.MAPOBJECT_EVERY__V23*/ meltfptr[22];;

	  MELT_LOCATION ("warmelt-normal.melt:8384:/ clear");
	     /*clear *//*_.CONTK__V19*/ meltfptr[18] = 0;
	  /*^clear */
	     /*clear *//*_.LAMBDA___V21*/ meltfptr[20] = 0;
	  /*^clear */
	     /*clear *//*_.MAPOBJECT_EVERY__V23*/ meltfptr[22] = 0;
	  /*^clear */
	     /*clear *//*_.REFERENCED_VALUE__V24*/ meltfptr[23] = 0;
	  /*^clear */
	     /*clear *//*_#NULL__L7*/ meltfnum[0] = 0;
	  /*epilog */
	}
	;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:8382:/ cond.else");

	/*^block */
	/*anyblock */
	{


	  MELT_CHECK_SIGNAL ();
	  ;
   /*_#IS_INTEGERBOX__L8*/ meltfnum[0] =
	    (melt_magic_discr ((melt_ptr_t) ( /*_.SPRED__V16*/ meltfptr[15]))
	     == MELTOBMAG_INT);;
	  MELT_LOCATION ("warmelt-normal.melt:8394:/ cond");
	  /*cond */ if ( /*_#IS_INTEGERBOX__L8*/ meltfnum[0])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		MELT_LOCATION ("warmelt-normal.melt:8396:/ quasiblock");


     /*_#PREDRK__L9*/ meltfnum[8] =
		  (melt_get_int
		   ((melt_ptr_t) ( /*_.SPRED__V16*/ meltfptr[15])));;

		MELT_CHECK_SIGNAL ();
		;
		/*^compute */
     /*_#lteqI__L10*/ meltfnum[9] =
		  (( /*_#PREDRK__L9*/ meltfnum[8]) <= (0));;
		MELT_LOCATION ("warmelt-normal.melt:8397:/ cond");
		/*cond */ if ( /*_#lteqI__L10*/ meltfnum[9])	/*then */
		  {
		    /*^cond.then */
		    /*_#OR___L11*/ meltfnum[10] =
		      /*_#lteqI__L10*/ meltfnum[9];;
		  }
		else
		  {
		    MELT_LOCATION ("warmelt-normal.melt:8397:/ cond.else");

		    /*^block */
		    /*anyblock */
		    {

       /*_#LAST_GLOBPREDEF_INDEX__L12*/ meltfnum[11] =
			BGLOB__LASTGLOB;;
		      /*^compute */
       /*_#gteqI__L13*/ meltfnum[12] =
			(( /*_#PREDRK__L9*/ meltfnum[8]) >=
			 ( /*_#LAST_GLOBPREDEF_INDEX__L12*/ meltfnum[11]));;
		      /*^compute */
		      /*_#OR___L11*/ meltfnum[10] =
			/*_#gteqI__L13*/ meltfnum[12];;
		      /*epilog */

		      MELT_LOCATION ("warmelt-normal.melt:8397:/ clear");
		 /*clear *//*_#LAST_GLOBPREDEF_INDEX__L12*/ meltfnum[11]
			= 0;
		      /*^clear */
		 /*clear *//*_#gteqI__L13*/ meltfnum[12] = 0;
		    }
		    ;
		  }
		;
		/*^cond */
		/*cond */ if ( /*_#OR___L11*/ meltfnum[10])	/*then */
		  {
		    /*^cond.then */
		    /*^block */
		    /*anyblock */
		    {




		      {
			MELT_LOCATION ("warmelt-normal.melt:8398:/ locexp");
			melt_warning_str (0,
					  (melt_ptr_t) ( /*_.SLOC__V15*/
							meltfptr[10]),
					  ("FETCH_PREDEFINED invalid predef rank"),
					  (melt_ptr_t) 0);
		      }
		      ;
		 /*clear *//*_._IFELSE___V26*/ meltfptr[24] = 0;
		      /*epilog */
		    }
		    ;
		  }
		else
		  {
		    MELT_LOCATION ("warmelt-normal.melt:8397:/ cond.else");

      /*_._IFELSE___V26*/ meltfptr[24] = NULL;;
		  }
		;

		MELT_LOCATION ("warmelt-normal.melt:8396:/ clear");
	       /*clear *//*_#PREDRK__L9*/ meltfnum[8] = 0;
		/*^clear */
	       /*clear *//*_#lteqI__L10*/ meltfnum[9] = 0;
		/*^clear */
	       /*clear *//*_#OR___L11*/ meltfnum[10] = 0;
		/*epilog */
	      }
	      ;
	    }
	  else
	    {
	      MELT_LOCATION ("warmelt-normal.melt:8394:/ cond.else");

	      /*^block */
	      /*anyblock */
	      {


#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:8402:/ cppif.then");
		/*^block */
		/*anyblock */
		{


		  MELT_CHECK_SIGNAL ();
		  ;
		  /*^cond */
		  /*cond */ if (( /*nil */ NULL))	/*then */
		    {
		      /*^cond.then */
		      /*_._IFELSE___V28*/ meltfptr[20] = ( /*nil */ NULL);;
		    }
		  else
		    {
		      MELT_LOCATION ("warmelt-normal.melt:8402:/ cond.else");

		      /*^block */
		      /*anyblock */
		      {




			{
			  /*^locexp */
			  melt_assert_failed (("FETCH_PREDEFINED bad predef"),
					      ("warmelt-normal.melt")
					      ? ("warmelt-normal.melt") :
					      __FILE__,
					      (8402) ? (8402) : __LINE__,
					      __FUNCTION__);
			  ;
			}
			;
		   /*clear *//*_._IFELSE___V28*/ meltfptr[20] = 0;
			/*epilog */
		      }
		      ;
		    }
		  ;
		  /*^compute */
		  /*_.IFCPP___V27*/ meltfptr[18] =
		    /*_._IFELSE___V28*/ meltfptr[20];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:8402:/ clear");
		 /*clear *//*_._IFELSE___V28*/ meltfptr[20] = 0;
		}

#else /*MELT_HAVE_DEBUG */
		/*^cppif.else */
		/*_.IFCPP___V27*/ meltfptr[18] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
		;
		MELT_LOCATION ("warmelt-normal.melt:8401:/ quasiblock");


		/*_.PROGN___V29*/ meltfptr[22] =
		  /*_.IFCPP___V27*/ meltfptr[18];;
		/*^compute */
		/*_._IFELSE___V26*/ meltfptr[24] =
		  /*_.PROGN___V29*/ meltfptr[22];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:8394:/ clear");
	       /*clear *//*_.IFCPP___V27*/ meltfptr[18] = 0;
		/*^clear */
	       /*clear *//*_.PROGN___V29*/ meltfptr[22] = 0;
	      }
	      ;
	    }
	  ;
	  /*_._IFELSE___V18*/ meltfptr[17] =
	    /*_._IFELSE___V26*/ meltfptr[24];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:8382:/ clear");
	     /*clear *//*_#IS_INTEGERBOX__L8*/ meltfnum[0] = 0;
	  /*^clear */
	     /*clear *//*_._IFELSE___V26*/ meltfptr[24] = 0;
	}
	;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:8404:/ quasiblock");



    MELT_CHECK_SIGNAL ();
    ;
    /*^quasiblock */


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NREP_PREDEF */
					     meltfrout->tabval[9])), (2),
			      "CLASS_NREP_PREDEF");
  /*_.INST__V32*/ meltfptr[18] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V32*/ meltfptr[18])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V32*/ meltfptr[18]), (0),
			  ( /*_.SLOC__V15*/ meltfptr[10]), "NREP_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NRPREDEF",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V32*/ meltfptr[18])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V32*/ meltfptr[18]), (1),
			  ( /*_.SPRED__V16*/ meltfptr[15]), "NRPREDEF");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V32*/ meltfptr[18],
				  "newly made instance");
    ;
    /*_.NPRE__V31*/ meltfptr[20] = /*_.INST__V32*/ meltfptr[18];;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8409:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L14*/ meltfnum[11] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8409:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L14*/ meltfnum[11])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L15*/ meltfnum[12] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8409:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L15*/ meltfnum[12];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8409;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_fetch_predefined result npre";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NPRE__V31*/ meltfptr[20];
	      /*_.MELT_DEBUG_FUN__V34*/ meltfptr[24] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V33*/ meltfptr[22] =
	      /*_.MELT_DEBUG_FUN__V34*/ meltfptr[24];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8409:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L15*/ meltfnum[12] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V34*/ meltfptr[24] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V33*/ meltfptr[22] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8409:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L14*/ meltfnum[11] = 0;
      /*^clear */
	     /*clear *//*_._IF___V33*/ meltfptr[22] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8410:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.NPRE__V31*/ meltfptr[20];;
    MELT_LOCATION ("warmelt-normal.melt:8410:/ putxtraresult");
    if (!meltxrestab_ || !meltxresdescr_)
      goto meltlabend_rout;
    if (meltxresdescr_[0] != MELTBPAR_PTR)
      goto meltlabend_rout;
    if (meltxrestab_[0].meltbp_aptr)
      *(meltxrestab_[0].meltbp_aptr) = (melt_ptr_t) (( /*nil */ NULL));
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*_.LET___V30*/ meltfptr[23] = /*_.RETURN___V35*/ meltfptr[24];;

    MELT_LOCATION ("warmelt-normal.melt:8404:/ clear");
	   /*clear *//*_.NPRE__V31*/ meltfptr[20] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V35*/ meltfptr[24] = 0;
    /*_.LET___V14*/ meltfptr[12] = /*_.LET___V30*/ meltfptr[23];;

    MELT_LOCATION ("warmelt-normal.melt:8377:/ clear");
	   /*clear *//*_.SLOC__V15*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.SPRED__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.PREDEFMAP__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_#IS_A__L6*/ meltfnum[4] = 0;
    /*^clear */
	   /*clear *//*_._IFELSE___V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.LET___V30*/ meltfptr[23] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8372:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V14*/ meltfptr[12];;

    {
      MELT_LOCATION ("warmelt-normal.melt:8372:/ locexp");
      /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
      if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
      ;
    }
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*epilog */

    /*^clear */
	   /*clear *//*_.IFCPP___V6*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V8*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V10*/ meltfptr[8] = 0;
    /*^clear */
	   /*clear *//*_.LET___V14*/ meltfptr[12] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMEXP_FETCH_PREDEFINED", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_160_WARMELTmiNORMAL_NORMEXP_FETCH_PREDEFINED_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_160_WARMELTmiNORMAL_NORMEXP_FETCH_PREDEFINED */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_161_WARMELTmiNORMAL_LAMBDA_cl47 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un * meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_161_WARMELTmiNORMAL_LAMBDA_cl47_melt =
    melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_161_WARMELTmiNORMAL_LAMBDA_cl47_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 3
    melt_ptr_t mcfr_varptr[3];
#define MELTFRAM_NBVARNUM 1
    long mcfr_varnum[1];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_161_WARMELTmiNORMAL_LAMBDA_cl47 is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_161_WARMELTmiNORMAL_LAMBDA_cl47_st *)
	meltfirstargp_;
      /* use arguments meltrout_161_WARMELTmiNORMAL_LAMBDA_cl47 output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 3; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_161_WARMELTmiNORMAL_LAMBDA_cl47 nbval 3*/
  meltfram__.mcfr_nbvar = 3 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("LAMBDA_cl47", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:8387:/ getarg");
 /*_.KEY__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.VAL__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.VAL__V3*/ meltfptr[2])) != NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


    MELT_CHECK_SIGNAL ();
    ;
 /*_#eqeq__L1*/ meltfnum[0] =
      (( /*_.VAL__V3*/ meltfptr[2]) ==
       (( /*~SPRED */ meltfclos->tabval[0])));;
    MELT_LOCATION ("warmelt-normal.melt:8388:/ cond");
    /*cond */ if ( /*_#eqeq__L1*/ meltfnum[0])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{


	  MELT_CHECK_SIGNAL ();
	  ;
	  /*^cond */
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      (( /*~CONTK */ meltfclos->
						tabval[1])),
					      (melt_ptr_t) (( /*!CLASS_REFERENCE */ meltfrout->tabval[0])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @REFERENCED_VALUE",
				melt_magic_discr ((melt_ptr_t)
						  (( /*~CONTK */ meltfclos->
						    tabval[1]))) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object ((( /*~CONTK */ meltfclos->tabval[1])),
				      (0), ( /*_.KEY__V2*/ meltfptr[1]),
				      "REFERENCED_VALUE");
		;
		/*^touch */
		meltgc_touch (( /*~CONTK */ meltfclos->tabval[1]));
		;
		/*^touchobj */

		melt_dbgtrace_written_object (( /*~CONTK */ meltfclos->
					       tabval[1]), "put-fields");
		;
		/*epilog */
	      }
	      ;
	    }			/*noelse */
	  ;
	  /*epilog */
	}
	;
      }				/*noelse */
    ;
    /*epilog */

    MELT_LOCATION ("warmelt-normal.melt:8387:/ clear");
	   /*clear *//*_#eqeq__L1*/ meltfnum[0] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("LAMBDA_cl47", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_161_WARMELTmiNORMAL_LAMBDA_cl47_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*noretval */ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_161_WARMELTmiNORMAL_LAMBDA_cl47 */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_162_WARMELTmiNORMAL_NORMEXP_STORE_PREDEFINED (meltclosure_ptr_t
						       meltclosp_,
						       melt_ptr_t
						       meltfirstargp_,
						       const
						       melt_argdescr_cell_t
						       meltxargdescr_[],
						       union meltparam_un *
						       meltxargtab_,
						       const
						       melt_argdescr_cell_t
						       meltxresdescr_[],
						       union meltparam_un *
						       meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_162_WARMELTmiNORMAL_NORMEXP_STORE_PREDEFINED_melt
    = melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_162_WARMELTmiNORMAL_NORMEXP_STORE_PREDEFINED_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 47
    melt_ptr_t mcfr_varptr[47];
#define MELTFRAM_NBVARNUM 16
    long mcfr_varnum[16];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_162_WARMELTmiNORMAL_NORMEXP_STORE_PREDEFINED is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct
	 meltframe_meltrout_162_WARMELTmiNORMAL_NORMEXP_STORE_PREDEFINED_st *)
	meltfirstargp_;
      /* use arguments meltrout_162_WARMELTmiNORMAL_NORMEXP_STORE_PREDEFINED output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 47; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_162_WARMELTmiNORMAL_NORMEXP_STORE_PREDEFINED nbval 47*/
  meltfram__.mcfr_nbvar = 47 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMEXP_STORE_PREDEFINED", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:8418:/ getarg");
 /*_.RECV__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2])) != NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3])) != NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.PSLOC__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.PSLOC__V5*/ meltfptr[4])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8419:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L1*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_STORE_PREDEFINED */ meltfrout->tabval[0])));;
      MELT_LOCATION ("warmelt-normal.melt:8419:/ cond");
      /*cond */ if ( /*_#IS_A__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V7*/ meltfptr[6] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8419:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check store_predefined recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8419) ? (8419) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V7*/ meltfptr[6] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V6*/ meltfptr[5] = /*_._IFELSE___V7*/ meltfptr[6];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8419:/ clear");
	     /*clear *//*_#IS_A__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V7*/ meltfptr[6] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V6*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8420:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L2*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:8420:/ cond");
      /*cond */ if ( /*_#IS_A__L2*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[8] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8420:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8420) ? (8420) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[8] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[8];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8420:/ clear");
	     /*clear *//*_#IS_A__L2*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[8] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8421:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:8421:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8421:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8421) ? (8421) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V10*/ meltfptr[8] = /*_._IFELSE___V11*/ meltfptr[10];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8421:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[8] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8422:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L4*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8422:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L5*/ meltfnum[4] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8422:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L5*/ meltfnum[4];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8422;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_store_predefined recv";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V13*/ meltfptr[12] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V12*/ meltfptr[10] =
	      /*_.MELT_DEBUG_FUN__V13*/ meltfptr[12];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8422:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L5*/ meltfnum[4] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V13*/ meltfptr[12] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V12*/ meltfptr[10] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8422:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V12*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:8423:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:8424:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.SLOC__V15*/ meltfptr[10] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8425:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "SSTPD_PREDEF");
  /*_.SPRED__V16*/ meltfptr[15] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8426:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 3, "SSTPD_VALUE");
  /*_.SVAL__V17*/ meltfptr[16] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8427:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 7, "NCTX_PREDEFMAP");
  /*_.PREDEFMAP__V18*/ meltfptr[17] = slot;
    };
    ;

    MELT_CHECK_SIGNAL ();
    ;
 /*_#IS_A__L6*/ meltfnum[4] =
      melt_is_instance_of ((melt_ptr_t) ( /*_.SPRED__V16*/ meltfptr[15]),
			   (melt_ptr_t) (( /*!CLASS_SYMBOL */ meltfrout->
					  tabval[4])));;
    MELT_LOCATION ("warmelt-normal.melt:8429:/ cond");
    /*cond */ if ( /*_#IS_A__L6*/ meltfnum[4])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  MELT_LOCATION ("warmelt-normal.melt:8431:/ quasiblock");



	  MELT_CHECK_SIGNAL ();
	  ;
	  /*^quasiblock */


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_REFERENCE */
						   meltfrout->tabval[5])),
				    (1), "CLASS_REFERENCE");
    /*_.INST__V21*/ meltfptr[20] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @REFERENCED_VALUE",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V21*/ meltfptr[20]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V21*/ meltfptr[20]), (0),
				(( /*nil */ NULL)), "REFERENCED_VALUE");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V21*/ meltfptr[20],
					"newly made instance");
	  ;
	  /*_.CONTK__V20*/ meltfptr[19] = /*_.INST__V21*/ meltfptr[20];;
	  MELT_LOCATION ("warmelt-normal.melt:8434:/ quasiblock");


	  /*^newclosure */
		   /*newclosure *//*_.LAMBDA___V23*/ meltfptr[22] =
	    (melt_ptr_t)
	    meltgc_new_closure ((meltobject_ptr_t)
				(((melt_ptr_t)
				  (MELT_PREDEF (DISCR_CLOSURE)))),
				(meltroutine_ptr_t) (( /*!konst_8 */
						      meltfrout->tabval[8])),
				(2));
	  ;
	  /*^putclosedv */
	  /*putclosv */
	  melt_assertmsg ("putclosv checkclo",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.LAMBDA___V23*/
					     meltfptr[22])) ==
			  MELTOBMAG_CLOSURE);
	  melt_assertmsg ("putclosv checkoff", 0 >= 0
			  && 0 <
			  melt_closure_size ((melt_ptr_t)
					     ( /*_.LAMBDA___V23*/
					      meltfptr[22])));
	  ((meltclosure_ptr_t) /*_.LAMBDA___V23*/ meltfptr[22])->tabval[0] =
	    (melt_ptr_t) ( /*_.SPRED__V16*/ meltfptr[15]);
	  ;
	  /*^putclosedv */
	  /*putclosv */
	  melt_assertmsg ("putclosv checkclo",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.LAMBDA___V23*/
					     meltfptr[22])) ==
			  MELTOBMAG_CLOSURE);
	  melt_assertmsg ("putclosv checkoff", 1 >= 0
			  && 1 <
			  melt_closure_size ((melt_ptr_t)
					     ( /*_.LAMBDA___V23*/
					      meltfptr[22])));
	  ((meltclosure_ptr_t) /*_.LAMBDA___V23*/ meltfptr[22])->tabval[1] =
	    (melt_ptr_t) ( /*_.CONTK__V20*/ meltfptr[19]);
	  ;
	  /*_.LAMBDA___V22*/ meltfptr[21] = /*_.LAMBDA___V23*/ meltfptr[22];;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:8433:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[1];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.LAMBDA___V22*/ meltfptr[21];
	    /*_.MAPOBJECT_EVERY__V24*/ meltfptr[23] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!MAPOBJECT_EVERY */ meltfrout->tabval[6])),
			  (melt_ptr_t) ( /*_.PREDEFMAP__V18*/ meltfptr[17]),
			  (MELTBPARSTR_PTR ""), argtab, "",
			  (union meltparam_un *) 0);
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:8436:/ cond");
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.CONTK__V20*/
					       meltfptr[19]),
					      (melt_ptr_t) (( /*!CLASS_REFERENCE */ meltfrout->tabval[5])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^getslot */
	      {
		melt_ptr_t slot = NULL, obj = NULL;
		obj = (melt_ptr_t) ( /*_.CONTK__V20*/ meltfptr[19]) /*=obj*/ ;
		melt_object_get_field (slot, obj, 0, "REFERENCED_VALUE");
     /*_.REFERENCED_VALUE__V25*/ meltfptr[24] = slot;
	      };
	      ;
	    }
	  else
	    {			/*^cond.else */

    /*_.REFERENCED_VALUE__V25*/ meltfptr[24] = NULL;;
	    }
	  ;
	  /*^compute */
   /*_#NULL__L7*/ meltfnum[0] =
	    (( /*_.REFERENCED_VALUE__V25*/ meltfptr[24]) == NULL);;
	  MELT_LOCATION ("warmelt-normal.melt:8436:/ cond");
	  /*cond */ if ( /*_#NULL__L7*/ meltfnum[0])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		MELT_LOCATION ("warmelt-normal.melt:8438:/ getslot");
		{
		  melt_ptr_t slot = NULL, obj = NULL;
		  obj =
		    (melt_ptr_t) ( /*_.SPRED__V16*/ meltfptr[15]) /*=obj*/ ;
		  melt_object_get_field (slot, obj, 1, "NAMED_NAME");
      /*_.NAMED_NAME__V26*/ meltfptr[25] = slot;
		};
		;

		{
		  MELT_LOCATION ("warmelt-normal.melt:8437:/ locexp");
		  melt_warning_str (0,
				    (melt_ptr_t) ( /*_.SLOC__V15*/
						  meltfptr[10]),
				    ("STORE_PREDEFINED unknown predef name"),
				    (melt_ptr_t) ( /*_.NAMED_NAME__V26*/
						  meltfptr[25]));
		}
		;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:8436:/ clear");
	       /*clear *//*_.NAMED_NAME__V26*/ meltfptr[25] = 0;
	      }
	      ;
	    }			/*noelse */
	  ;
	  /*_._IFELSE___V19*/ meltfptr[18] =
	    /*_.MAPOBJECT_EVERY__V24*/ meltfptr[23];;

	  MELT_LOCATION ("warmelt-normal.melt:8431:/ clear");
	     /*clear *//*_.CONTK__V20*/ meltfptr[19] = 0;
	  /*^clear */
	     /*clear *//*_.LAMBDA___V22*/ meltfptr[21] = 0;
	  /*^clear */
	     /*clear *//*_.MAPOBJECT_EVERY__V24*/ meltfptr[23] = 0;
	  /*^clear */
	     /*clear *//*_.REFERENCED_VALUE__V25*/ meltfptr[24] = 0;
	  /*^clear */
	     /*clear *//*_#NULL__L7*/ meltfnum[0] = 0;
	  /*epilog */
	}
	;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:8429:/ cond.else");

	/*^block */
	/*anyblock */
	{


	  MELT_CHECK_SIGNAL ();
	  ;
   /*_#IS_INTEGERBOX__L8*/ meltfnum[0] =
	    (melt_magic_discr ((melt_ptr_t) ( /*_.SPRED__V16*/ meltfptr[15]))
	     == MELTOBMAG_INT);;
	  MELT_LOCATION ("warmelt-normal.melt:8441:/ cond");
	  /*cond */ if ( /*_#IS_INTEGERBOX__L8*/ meltfnum[0])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		MELT_LOCATION ("warmelt-normal.melt:8443:/ quasiblock");


     /*_#PREDRK__L9*/ meltfnum[8] =
		  (melt_get_int
		   ((melt_ptr_t) ( /*_.SPRED__V16*/ meltfptr[15])));;

		MELT_CHECK_SIGNAL ();
		;
		/*^compute */
     /*_#lteqI__L10*/ meltfnum[9] =
		  (( /*_#PREDRK__L9*/ meltfnum[8]) <= (0));;
		MELT_LOCATION ("warmelt-normal.melt:8444:/ cond");
		/*cond */ if ( /*_#lteqI__L10*/ meltfnum[9])	/*then */
		  {
		    /*^cond.then */
		    /*_#OR___L11*/ meltfnum[10] =
		      /*_#lteqI__L10*/ meltfnum[9];;
		  }
		else
		  {
		    MELT_LOCATION ("warmelt-normal.melt:8444:/ cond.else");

		    /*^block */
		    /*anyblock */
		    {

       /*_#LAST_GLOBPREDEF_INDEX__L12*/ meltfnum[11] =
			BGLOB__LASTGLOB;;
		      /*^compute */
       /*_#gteqI__L13*/ meltfnum[12] =
			(( /*_#PREDRK__L9*/ meltfnum[8]) >=
			 ( /*_#LAST_GLOBPREDEF_INDEX__L12*/ meltfnum[11]));;
		      /*^compute */
		      /*_#OR___L11*/ meltfnum[10] =
			/*_#gteqI__L13*/ meltfnum[12];;
		      /*epilog */

		      MELT_LOCATION ("warmelt-normal.melt:8444:/ clear");
		 /*clear *//*_#LAST_GLOBPREDEF_INDEX__L12*/ meltfnum[11]
			= 0;
		      /*^clear */
		 /*clear *//*_#gteqI__L13*/ meltfnum[12] = 0;
		    }
		    ;
		  }
		;
		/*^cond */
		/*cond */ if ( /*_#OR___L11*/ meltfnum[10])	/*then */
		  {
		    /*^cond.then */
		    /*^block */
		    /*anyblock */
		    {




		      {
			MELT_LOCATION ("warmelt-normal.melt:8445:/ locexp");
			melt_warning_str (0,
					  (melt_ptr_t) ( /*_.SLOC__V15*/
							meltfptr[10]),
					  ("STORE_PREDEFINED invalid predef rank"),
					  (melt_ptr_t) 0);
		      }
		      ;
		 /*clear *//*_._IFELSE___V27*/ meltfptr[25] = 0;
		      /*epilog */
		    }
		    ;
		  }
		else
		  {
		    MELT_LOCATION ("warmelt-normal.melt:8444:/ cond.else");

      /*_._IFELSE___V27*/ meltfptr[25] = NULL;;
		  }
		;

		MELT_LOCATION ("warmelt-normal.melt:8443:/ clear");
	       /*clear *//*_#PREDRK__L9*/ meltfnum[8] = 0;
		/*^clear */
	       /*clear *//*_#lteqI__L10*/ meltfnum[9] = 0;
		/*^clear */
	       /*clear *//*_#OR___L11*/ meltfnum[10] = 0;
		/*epilog */
	      }
	      ;
	    }
	  else
	    {
	      MELT_LOCATION ("warmelt-normal.melt:8441:/ cond.else");

	      /*^block */
	      /*anyblock */
	      {


#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:8449:/ cppif.then");
		/*^block */
		/*anyblock */
		{


		  MELT_CHECK_SIGNAL ();
		  ;
		  /*^cond */
		  /*cond */ if (( /*nil */ NULL))	/*then */
		    {
		      /*^cond.then */
		      /*_._IFELSE___V29*/ meltfptr[21] = ( /*nil */ NULL);;
		    }
		  else
		    {
		      MELT_LOCATION ("warmelt-normal.melt:8449:/ cond.else");

		      /*^block */
		      /*anyblock */
		      {




			{
			  /*^locexp */
			  melt_assert_failed (("STORE_PREDEFINED bad predef"),
					      ("warmelt-normal.melt")
					      ? ("warmelt-normal.melt") :
					      __FILE__,
					      (8449) ? (8449) : __LINE__,
					      __FUNCTION__);
			  ;
			}
			;
		   /*clear *//*_._IFELSE___V29*/ meltfptr[21] = 0;
			/*epilog */
		      }
		      ;
		    }
		  ;
		  /*^compute */
		  /*_.IFCPP___V28*/ meltfptr[19] =
		    /*_._IFELSE___V29*/ meltfptr[21];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:8449:/ clear");
		 /*clear *//*_._IFELSE___V29*/ meltfptr[21] = 0;
		}

#else /*MELT_HAVE_DEBUG */
		/*^cppif.else */
		/*_.IFCPP___V28*/ meltfptr[19] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
		;
		MELT_LOCATION ("warmelt-normal.melt:8448:/ quasiblock");


		/*_.PROGN___V30*/ meltfptr[23] =
		  /*_.IFCPP___V28*/ meltfptr[19];;
		/*^compute */
		/*_._IFELSE___V27*/ meltfptr[25] =
		  /*_.PROGN___V30*/ meltfptr[23];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:8441:/ clear");
	       /*clear *//*_.IFCPP___V28*/ meltfptr[19] = 0;
		/*^clear */
	       /*clear *//*_.PROGN___V30*/ meltfptr[23] = 0;
	      }
	      ;
	    }
	  ;
	  /*_._IFELSE___V19*/ meltfptr[18] =
	    /*_._IFELSE___V27*/ meltfptr[25];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:8429:/ clear");
	     /*clear *//*_#IS_INTEGERBOX__L8*/ meltfnum[0] = 0;
	  /*^clear */
	     /*clear *//*_._IFELSE___V27*/ meltfptr[25] = 0;
	}
	;
      }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8451:/ quasiblock");


    /*^multimsend */
    /*multimsend */
    {
      union meltparam_un argtab[3];
      union meltparam_un restab[1];
      memset (&argtab, 0, sizeof (argtab));
      memset (&restab, 0, sizeof (restab));
      /*^multimsend.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.ENV__V3*/ meltfptr[2];	/*^multimsend.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];	/*^multimsend.arg */
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V15*/ meltfptr[10];
      /*^multimsend.xres */
      restab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NBINDS__V33*/ meltfptr[19];	/*^multimsend.send */
      /*_.NVAL__V32*/ meltfptr[21] =
	meltgc_send ((melt_ptr_t) ( /*_.SVAL__V17*/ meltfptr[16]),
		     ((melt_ptr_t)
		      (( /*!NORMAL_EXP */ meltfrout->tabval[9]))),
		     (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		     argtab, (MELTBPARSTR_PTR ""), restab);
    }
    ;
    /*^quasiblock */



    MELT_CHECK_SIGNAL ();
    ;
 /*_#NULL__L14*/ meltfnum[11] =
      (( /*_.NBINDS__V33*/ meltfptr[19]) == NULL);;
    MELT_LOCATION ("warmelt-normal.melt:8454:/ cond");
    /*cond */ if ( /*_#NULL__L14*/ meltfnum[11])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

   /*_.MAKE_LIST__V35*/ meltfptr[25] =
	    (meltgc_new_list
	     ((meltobject_ptr_t)
	      (( /*!DISCR_LIST */ meltfrout->tabval[10]))));;
	  MELT_LOCATION ("warmelt-normal.melt:8455:/ compute");
	  /*_.NBINDS__V33*/ meltfptr[19] = /*_.SETQ___V36*/ meltfptr[35] =
	    /*_.MAKE_LIST__V35*/ meltfptr[25];;
	  /*_._IF___V34*/ meltfptr[23] = /*_.SETQ___V36*/ meltfptr[35];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:8454:/ clear");
	     /*clear *//*_.MAKE_LIST__V35*/ meltfptr[25] = 0;
	  /*^clear */
	     /*clear *//*_.SETQ___V36*/ meltfptr[35] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

  /*_._IF___V34*/ meltfptr[23] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:8456:/ quasiblock");



    MELT_CHECK_SIGNAL ();
    ;
    /*^apply */
    /*apply */
    {
      /*_.CSYM__V38*/ meltfptr[35] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!CLONE_SYMBOL */ meltfrout->tabval[11])),
		    (melt_ptr_t) (( /*!konst_12__STOREPREDEF_ */ meltfrout->
				   tabval[12])), (""),
		    (union meltparam_un *) 0, "", (union meltparam_un *) 0);
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8457:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NREP_STORE_PREDEFINED */ meltfrout->tabval[13])), (3), "CLASS_NREP_STORE_PREDEFINED");
  /*_.INST__V40*/ meltfptr[39] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V40*/ meltfptr[39])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V40*/ meltfptr[39]), (0),
			  ( /*_.SLOC__V15*/ meltfptr[10]), "NREP_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NSTPD_PREDEF",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V40*/ meltfptr[39])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V40*/ meltfptr[39]), (1),
			  ( /*_.SPRED__V16*/ meltfptr[15]), "NSTPD_PREDEF");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NSTPD_VALUE",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V40*/ meltfptr[39])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V40*/ meltfptr[39]), (2),
			  ( /*_.NVAL__V32*/ meltfptr[21]), "NSTPD_VALUE");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V40*/ meltfptr[39],
				  "newly made instance");
    ;
    /*_.NFPRE__V39*/ meltfptr[38] = /*_.INST__V40*/ meltfptr[39];;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8461:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NORMAL_LET_BINDING */
					     meltfrout->tabval[14])), (4),
			      "CLASS_NORMAL_LET_BINDING");
  /*_.INST__V42*/ meltfptr[41] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @BINDER",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V42*/ meltfptr[41])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V42*/ meltfptr[41]), (0),
			  ( /*_.CSYM__V38*/ meltfptr[35]), "BINDER");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @LETBIND_TYPE",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V42*/ meltfptr[41])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V42*/ meltfptr[41]), (1),
			  (( /*!CTYPE_VALUE */ meltfrout->tabval[15])),
			  "LETBIND_TYPE");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @LETBIND_EXPR",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V42*/ meltfptr[41])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V42*/ meltfptr[41]), (2),
			  ( /*_.NFPRE__V39*/ meltfptr[38]), "LETBIND_EXPR");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V42*/ meltfptr[41],
				  "newly made instance");
    ;
    /*_.CBIND__V41*/ meltfptr[40] = /*_.INST__V42*/ meltfptr[41];;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8465:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NREP_LOCSYMOCC */
					     meltfrout->tabval[16])), (4),
			      "CLASS_NREP_LOCSYMOCC");
  /*_.INST__V44*/ meltfptr[43] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V44*/ meltfptr[43])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V44*/ meltfptr[43]), (0),
			  ( /*_.SLOC__V15*/ meltfptr[10]), "NREP_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NOCC_CTYP",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V44*/ meltfptr[43])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V44*/ meltfptr[43]), (2),
			  (( /*!CTYPE_VALUE */ meltfrout->tabval[15])),
			  "NOCC_CTYP");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NOCC_SYMB",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V44*/ meltfptr[43])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V44*/ meltfptr[43]), (1),
			  ( /*_.CSYM__V38*/ meltfptr[35]), "NOCC_SYMB");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NOCC_BIND",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V44*/ meltfptr[43])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V44*/ meltfptr[43]), (3),
			  ( /*_.CBIND__V41*/ meltfptr[40]), "NOCC_BIND");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V44*/ meltfptr[43],
				  "newly made instance");
    ;
    /*_.SYOCC__V43*/ meltfptr[42] = /*_.INST__V44*/ meltfptr[43];;

    {
      MELT_LOCATION ("warmelt-normal.melt:8471:/ locexp");
      meltgc_append_list ((melt_ptr_t) ( /*_.NBINDS__V33*/ meltfptr[19]),
			  (melt_ptr_t) ( /*_.CBIND__V41*/ meltfptr[40]));
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8472:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L15*/ meltfnum[12] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8472:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L15*/ meltfnum[12])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L16*/ meltfnum[8] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8472:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L16*/ meltfnum[8];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8472;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_store_predefined result nbinds=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NBINDS__V33*/ meltfptr[19];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " syocc=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.SYOCC__V43*/ meltfptr[42];
	      /*_.MELT_DEBUG_FUN__V46*/ meltfptr[45] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V45*/ meltfptr[44] =
	      /*_.MELT_DEBUG_FUN__V46*/ meltfptr[45];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8472:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L16*/ meltfnum[8] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V46*/ meltfptr[45] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V45*/ meltfptr[44] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8472:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L15*/ meltfnum[12] = 0;
      /*^clear */
	     /*clear *//*_._IF___V45*/ meltfptr[44] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8473:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.SYOCC__V43*/ meltfptr[42];;
    MELT_LOCATION ("warmelt-normal.melt:8473:/ putxtraresult");
    if (!meltxrestab_ || !meltxresdescr_)
      goto meltlabend_rout;
    if (meltxresdescr_[0] != MELTBPAR_PTR)
      goto meltlabend_rout;
    if (meltxrestab_[0].meltbp_aptr)
      *(meltxrestab_[0].meltbp_aptr) =
	(melt_ptr_t) ( /*_.NBINDS__V33*/ meltfptr[19]);
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*_.LET___V37*/ meltfptr[25] = /*_.RETURN___V47*/ meltfptr[45];;

    MELT_LOCATION ("warmelt-normal.melt:8456:/ clear");
	   /*clear *//*_.CSYM__V38*/ meltfptr[35] = 0;
    /*^clear */
	   /*clear *//*_.NFPRE__V39*/ meltfptr[38] = 0;
    /*^clear */
	   /*clear *//*_.CBIND__V41*/ meltfptr[40] = 0;
    /*^clear */
	   /*clear *//*_.SYOCC__V43*/ meltfptr[42] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V47*/ meltfptr[45] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    /*_.MULTI___V31*/ meltfptr[24] = /*_.LET___V37*/ meltfptr[25];;

    MELT_LOCATION ("warmelt-normal.melt:8451:/ clear");
	   /*clear *//*_#NULL__L14*/ meltfnum[11] = 0;
    /*^clear */
	   /*clear *//*_._IF___V34*/ meltfptr[23] = 0;
    /*^clear */
	   /*clear *//*_.LET___V37*/ meltfptr[25] = 0;

    /*^clear */
	   /*clear *//*_.NBINDS__V33*/ meltfptr[19] = 0;
    /*_.LET___V14*/ meltfptr[12] = /*_.MULTI___V31*/ meltfptr[24];;

    MELT_LOCATION ("warmelt-normal.melt:8423:/ clear");
	   /*clear *//*_.SLOC__V15*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.SPRED__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.SVAL__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.PREDEFMAP__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_#IS_A__L6*/ meltfnum[4] = 0;
    /*^clear */
	   /*clear *//*_._IFELSE___V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.MULTI___V31*/ meltfptr[24] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8418:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V14*/ meltfptr[12];;

    {
      MELT_LOCATION ("warmelt-normal.melt:8418:/ locexp");
      /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
      if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
      ;
    }
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*epilog */

    /*^clear */
	   /*clear *//*_.IFCPP___V6*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V8*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V10*/ meltfptr[8] = 0;
    /*^clear */
	   /*clear *//*_.LET___V14*/ meltfptr[12] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMEXP_STORE_PREDEFINED", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_162_WARMELTmiNORMAL_NORMEXP_STORE_PREDEFINED_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_162_WARMELTmiNORMAL_NORMEXP_STORE_PREDEFINED */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_163_WARMELTmiNORMAL_LAMBDA_cl48 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un * meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_163_WARMELTmiNORMAL_LAMBDA_cl48_melt =
    melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_163_WARMELTmiNORMAL_LAMBDA_cl48_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 3
    melt_ptr_t mcfr_varptr[3];
#define MELTFRAM_NBVARNUM 1
    long mcfr_varnum[1];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_163_WARMELTmiNORMAL_LAMBDA_cl48 is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_163_WARMELTmiNORMAL_LAMBDA_cl48_st *)
	meltfirstargp_;
      /* use arguments meltrout_163_WARMELTmiNORMAL_LAMBDA_cl48 output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 3; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_163_WARMELTmiNORMAL_LAMBDA_cl48 nbval 3*/
  meltfram__.mcfr_nbvar = 3 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("LAMBDA_cl48", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:8434:/ getarg");
 /*_.KEY__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.VAL__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.VAL__V3*/ meltfptr[2])) != NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


    MELT_CHECK_SIGNAL ();
    ;
 /*_#eqeq__L1*/ meltfnum[0] =
      (( /*_.VAL__V3*/ meltfptr[2]) ==
       (( /*~SPRED */ meltfclos->tabval[0])));;
    MELT_LOCATION ("warmelt-normal.melt:8435:/ cond");
    /*cond */ if ( /*_#eqeq__L1*/ meltfnum[0])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{


	  MELT_CHECK_SIGNAL ();
	  ;
	  /*^cond */
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      (( /*~CONTK */ meltfclos->
						tabval[1])),
					      (melt_ptr_t) (( /*!CLASS_REFERENCE */ meltfrout->tabval[0])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @REFERENCED_VALUE",
				melt_magic_discr ((melt_ptr_t)
						  (( /*~CONTK */ meltfclos->
						    tabval[1]))) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object ((( /*~CONTK */ meltfclos->tabval[1])),
				      (0), ( /*_.KEY__V2*/ meltfptr[1]),
				      "REFERENCED_VALUE");
		;
		/*^touch */
		meltgc_touch (( /*~CONTK */ meltfclos->tabval[1]));
		;
		/*^touchobj */

		melt_dbgtrace_written_object (( /*~CONTK */ meltfclos->
					       tabval[1]), "put-fields");
		;
		/*epilog */
	      }
	      ;
	    }			/*noelse */
	  ;
	  /*epilog */
	}
	;
      }				/*noelse */
    ;
    /*epilog */

    MELT_LOCATION ("warmelt-normal.melt:8434:/ clear");
	   /*clear *//*_#eqeq__L1*/ meltfnum[0] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("LAMBDA_cl48", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_163_WARMELTmiNORMAL_LAMBDA_cl48_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*noretval */ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_163_WARMELTmiNORMAL_LAMBDA_cl48 */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_164_WARMELTmiNORMAL_NORMEXP_CHEADER (meltclosure_ptr_t meltclosp_,
					      melt_ptr_t meltfirstargp_,
					      const melt_argdescr_cell_t
					      meltxargdescr_[],
					      union meltparam_un *
					      meltxargtab_,
					      const melt_argdescr_cell_t
					      meltxresdescr_[],
					      union meltparam_un *
					      meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_164_WARMELTmiNORMAL_NORMEXP_CHEADER_melt
    = melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_164_WARMELTmiNORMAL_NORMEXP_CHEADER_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 26
    melt_ptr_t mcfr_varptr[26];
#define MELTFRAM_NBVARNUM 11
    long mcfr_varnum[11];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_164_WARMELTmiNORMAL_NORMEXP_CHEADER is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_164_WARMELTmiNORMAL_NORMEXP_CHEADER_st *)
	meltfirstargp_;
      /* use arguments meltrout_164_WARMELTmiNORMAL_NORMEXP_CHEADER output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 26; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_164_WARMELTmiNORMAL_NORMEXP_CHEADER nbval 26*/
  meltfram__.mcfr_nbvar = 26 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMEXP_CHEADER", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:8480:/ getarg");
 /*_.RECV__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2])) != NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3])) != NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.PSLOC__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.PSLOC__V5*/ meltfptr[4])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8481:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L1*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8481:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8481:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8481;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_cheader recv=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = "\n* ncx=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V6*/ meltfptr[5] =
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8481:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V6*/ meltfptr[5] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8481:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V6*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8482:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_CHEADER */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:8482:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[5] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8482:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check cheader recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8482) ? (8482) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8482:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8483:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:8483:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8483:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8483) ? (8483) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V10*/ meltfptr[5] = /*_._IFELSE___V11*/ meltfptr[10];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8483:/ clear");
	     /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8484:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L5*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[3])));;
      MELT_LOCATION ("warmelt-normal.melt:8484:/ cond");
      /*cond */ if ( /*_#IS_A__L5*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V13*/ meltfptr[12] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8484:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8484) ? (8484) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V12*/ meltfptr[10] = /*_._IFELSE___V13*/ meltfptr[12];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8484:/ clear");
	     /*clear *//*_#IS_A__L5*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V12*/ meltfptr[10] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:8485:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:8486:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.SLOC__V15*/ meltfptr[14] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8487:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.NCX__V4*/ meltfptr[3]),
					(melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */ meltfrout->tabval[3])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 11, "NCTX_MODULCONTEXT");
   /*_.MODCTX__V16*/ meltfptr[15] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.MODCTX__V16*/ meltfptr[15] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:8488:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.MODCTX__V16*/ meltfptr[15]),
					(melt_ptr_t) (( /*!CLASS_ANY_MODULE_CONTEXT */ meltfrout->tabval[4])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.MODCTX__V16*/ meltfptr[15]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 8, "MOCX_CHEADERLIST");
   /*_.MCHEADLIST__V17*/ meltfptr[16] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.MCHEADLIST__V17*/ meltfptr[16] = NULL;;
      }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8490:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L6*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8490:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L6*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L7*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8490:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L7*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8490;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_cheader modctx=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.MODCTX__V16*/ meltfptr[15];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = "\n mcheadlist=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.MCHEADLIST__V17*/ meltfptr[16];
	      /*_.MELT_DEBUG_FUN__V19*/ meltfptr[18] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V18*/ meltfptr[17] =
	      /*_.MELT_DEBUG_FUN__V19*/ meltfptr[18];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8490:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L7*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V19*/ meltfptr[18] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V18*/ meltfptr[17] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8490:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L6*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V18*/ meltfptr[17] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8491:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L8*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.MODCTX__V16*/ meltfptr[15]),
			     (melt_ptr_t) (( /*!CLASS_ANY_MODULE_CONTEXT */
					    meltfrout->tabval[4])));;
      MELT_LOCATION ("warmelt-normal.melt:8491:/ cond");
      /*cond */ if ( /*_#IS_A__L8*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V21*/ meltfptr[17] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8491:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check modctx"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8491) ? (8491) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V21*/ meltfptr[17] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V20*/ meltfptr[18] = /*_._IFELSE___V21*/ meltfptr[17];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8491:/ clear");
	     /*clear *//*_#IS_A__L8*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V21*/ meltfptr[17] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V20*/ meltfptr[18] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8492:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST__L9*/ meltfnum[0] =
	(melt_magic_discr ((melt_ptr_t) ( /*_.MCHEADLIST__V17*/ meltfptr[16]))
	 == MELTOBMAG_LIST);;
      MELT_LOCATION ("warmelt-normal.melt:8492:/ cond");
      /*cond */ if ( /*_#IS_LIST__L9*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V23*/ meltfptr[22] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8492:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check mcheadlist"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8492) ? (8492) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V23*/ meltfptr[22] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V22*/ meltfptr[17] = /*_._IFELSE___V23*/ meltfptr[22];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8492:/ clear");
	     /*clear *//*_#IS_LIST__L9*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V23*/ meltfptr[22] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V22*/ meltfptr[17] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:8493:/ locexp");
      meltgc_append_list ((melt_ptr_t) ( /*_.MCHEADLIST__V17*/ meltfptr[16]),
			  (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]));
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8494:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L10*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8494:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L10*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L11*/ meltfnum[0] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8494:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[8];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L11*/ meltfnum[0];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8494;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_cheader updated mcheadlist=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.MCHEADLIST__V17*/ meltfptr[16];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = "\n modctx=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.MODCTX__V16*/ meltfptr[15];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = "\n";
	      /*_.MELT_DEBUG_FUN__V25*/ meltfptr[24] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING ""), argtab,
			    "", (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V24*/ meltfptr[22] =
	      /*_.MELT_DEBUG_FUN__V25*/ meltfptr[24];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8494:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L11*/ meltfnum[0] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V25*/ meltfptr[24] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V24*/ meltfptr[22] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8494:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L10*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V24*/ meltfptr[22] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:8495:/ quasiblock");


 /*_._RETVAL___V1*/ meltfptr[0] = NULL;;

    {
      MELT_LOCATION ("warmelt-normal.melt:8495:/ locexp");
      /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
      if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
      ;
    }
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*_.LET___V14*/ meltfptr[12] = /*_.RETURN___V26*/ meltfptr[24];;

    MELT_LOCATION ("warmelt-normal.melt:8485:/ clear");
	   /*clear *//*_.SLOC__V15*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.MODCTX__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.MCHEADLIST__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V20*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V22*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V26*/ meltfptr[24] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8480:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V14*/ meltfptr[12];;

    {
      MELT_LOCATION ("warmelt-normal.melt:8480:/ locexp");
      /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
      if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
      ;
    }
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*epilog */

    /*^clear */
	   /*clear *//*_.IFCPP___V8*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V10*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V12*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.LET___V14*/ meltfptr[12] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMEXP_CHEADER", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_164_WARMELTmiNORMAL_NORMEXP_CHEADER_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_164_WARMELTmiNORMAL_NORMEXP_CHEADER */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_165_WARMELTmiNORMAL_NORMEXP_CIMPLEMENT (meltclosure_ptr_t meltclosp_,
						 melt_ptr_t meltfirstargp_,
						 const melt_argdescr_cell_t
						 meltxargdescr_[],
						 union meltparam_un *
						 meltxargtab_,
						 const melt_argdescr_cell_t
						 meltxresdescr_[],
						 union meltparam_un *
						 meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_165_WARMELTmiNORMAL_NORMEXP_CIMPLEMENT_melt
    = melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_165_WARMELTmiNORMAL_NORMEXP_CIMPLEMENT_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 26
    melt_ptr_t mcfr_varptr[26];
#define MELTFRAM_NBVARNUM 11
    long mcfr_varnum[11];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_165_WARMELTmiNORMAL_NORMEXP_CIMPLEMENT is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_165_WARMELTmiNORMAL_NORMEXP_CIMPLEMENT_st
	 *) meltfirstargp_;
      /* use arguments meltrout_165_WARMELTmiNORMAL_NORMEXP_CIMPLEMENT output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 26; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_165_WARMELTmiNORMAL_NORMEXP_CIMPLEMENT nbval 26*/
  meltfram__.mcfr_nbvar = 26 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMEXP_CIMPLEMENT", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:8501:/ getarg");
 /*_.RECV__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2])) != NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3])) != NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.PSLOC__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.PSLOC__V5*/ meltfptr[4])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8502:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L1*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8502:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8502:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8502;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_cimplement recv=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = "\n* ncx=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V6*/ meltfptr[5] =
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8502:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V6*/ meltfptr[5] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8502:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V6*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8503:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_CIMPLEMENT */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:8503:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[5] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8503:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check cimplement recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8503) ? (8503) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8503:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8504:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:8504:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8504:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8504) ? (8504) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V10*/ meltfptr[5] = /*_._IFELSE___V11*/ meltfptr[10];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8504:/ clear");
	     /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8505:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L5*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[3])));;
      MELT_LOCATION ("warmelt-normal.melt:8505:/ cond");
      /*cond */ if ( /*_#IS_A__L5*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V13*/ meltfptr[12] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8505:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8505) ? (8505) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V12*/ meltfptr[10] = /*_._IFELSE___V13*/ meltfptr[12];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8505:/ clear");
	     /*clear *//*_#IS_A__L5*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V12*/ meltfptr[10] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:8506:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:8507:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.SLOC__V15*/ meltfptr[14] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8508:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.NCX__V4*/ meltfptr[3]),
					(melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */ meltfrout->tabval[3])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 11, "NCTX_MODULCONTEXT");
   /*_.MODCTX__V16*/ meltfptr[15] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.MODCTX__V16*/ meltfptr[15] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:8509:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.MODCTX__V16*/ meltfptr[15]),
					(melt_ptr_t) (( /*!CLASS_ANY_MODULE_CONTEXT */ meltfrout->tabval[4])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.MODCTX__V16*/ meltfptr[15]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 9, "MOCX_CIMPLEMENTLIST");
   /*_.MCIMPLEMLIST__V17*/ meltfptr[16] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.MCIMPLEMLIST__V17*/ meltfptr[16] = NULL;;
      }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8511:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L6*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8511:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L6*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L7*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8511:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L7*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8511;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_cimplement modctx=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.MODCTX__V16*/ meltfptr[15];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = "\n mcimplemlist=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.MCIMPLEMLIST__V17*/ meltfptr[16];
	      /*_.MELT_DEBUG_FUN__V19*/ meltfptr[18] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V18*/ meltfptr[17] =
	      /*_.MELT_DEBUG_FUN__V19*/ meltfptr[18];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8511:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L7*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V19*/ meltfptr[18] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V18*/ meltfptr[17] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8511:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L6*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V18*/ meltfptr[17] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8512:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L8*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.MODCTX__V16*/ meltfptr[15]),
			     (melt_ptr_t) (( /*!CLASS_ANY_MODULE_CONTEXT */
					    meltfrout->tabval[4])));;
      MELT_LOCATION ("warmelt-normal.melt:8512:/ cond");
      /*cond */ if ( /*_#IS_A__L8*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V21*/ meltfptr[17] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8512:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check modctx"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8512) ? (8512) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V21*/ meltfptr[17] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V20*/ meltfptr[18] = /*_._IFELSE___V21*/ meltfptr[17];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8512:/ clear");
	     /*clear *//*_#IS_A__L8*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V21*/ meltfptr[17] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V20*/ meltfptr[18] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8513:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST__L9*/ meltfnum[0] =
	(melt_magic_discr
	 ((melt_ptr_t) ( /*_.MCIMPLEMLIST__V17*/ meltfptr[16])) ==
	 MELTOBMAG_LIST);;
      MELT_LOCATION ("warmelt-normal.melt:8513:/ cond");
      /*cond */ if ( /*_#IS_LIST__L9*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V23*/ meltfptr[22] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8513:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check mcimplemlist"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8513) ? (8513) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V23*/ meltfptr[22] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V22*/ meltfptr[17] = /*_._IFELSE___V23*/ meltfptr[22];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8513:/ clear");
	     /*clear *//*_#IS_LIST__L9*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V23*/ meltfptr[22] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V22*/ meltfptr[17] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:8514:/ locexp");
      meltgc_append_list ((melt_ptr_t)
			  ( /*_.MCIMPLEMLIST__V17*/ meltfptr[16]),
			  (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]));
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8515:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L10*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8515:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L10*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L11*/ meltfnum[0] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8515:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[8];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L11*/ meltfnum[0];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8515;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_cimplement updated mcimplemlist=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.MCIMPLEMLIST__V17*/ meltfptr[16];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = "\n modctx=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.MODCTX__V16*/ meltfptr[15];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = "\n";
	      /*_.MELT_DEBUG_FUN__V25*/ meltfptr[24] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING ""), argtab,
			    "", (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V24*/ meltfptr[22] =
	      /*_.MELT_DEBUG_FUN__V25*/ meltfptr[24];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8515:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L11*/ meltfnum[0] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V25*/ meltfptr[24] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V24*/ meltfptr[22] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8515:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L10*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V24*/ meltfptr[22] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:8516:/ quasiblock");


 /*_._RETVAL___V1*/ meltfptr[0] = NULL;;

    {
      MELT_LOCATION ("warmelt-normal.melt:8516:/ locexp");
      /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
      if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
      ;
    }
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*_.LET___V14*/ meltfptr[12] = /*_.RETURN___V26*/ meltfptr[24];;

    MELT_LOCATION ("warmelt-normal.melt:8506:/ clear");
	   /*clear *//*_.SLOC__V15*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.MODCTX__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.MCIMPLEMLIST__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V20*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V22*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V26*/ meltfptr[24] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:8501:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V14*/ meltfptr[12];;

    {
      MELT_LOCATION ("warmelt-normal.melt:8501:/ locexp");
      /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
      if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
      ;
    }
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*epilog */

    /*^clear */
	   /*clear *//*_.IFCPP___V8*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V10*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V12*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.LET___V14*/ meltfptr[12] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMEXP_CIMPLEMENT", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_165_WARMELTmiNORMAL_NORMEXP_CIMPLEMENT_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_165_WARMELTmiNORMAL_NORMEXP_CIMPLEMENT */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_166_WARMELTmiNORMAL_NORMEXP_USE_PACKAGE_FROM_PKG_CONFIG
  (meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_,
   const melt_argdescr_cell_t meltxargdescr_[],
   union meltparam_un * meltxargtab_,
   const melt_argdescr_cell_t meltxresdescr_[],
   union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_166_WARMELTmiNORMAL_NORMEXP_USE_PACKAGE_FROM_PKG_CONFIG_melt
    = melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_166_WARMELTmiNORMAL_NORMEXP_USE_PACKAGE_FROM_PKG_CONFIG_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 37
    melt_ptr_t mcfr_varptr[37];
#define MELTFRAM_NBVARNUM 18
    long mcfr_varnum[18];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_166_WARMELTmiNORMAL_NORMEXP_USE_PACKAGE_FROM_PKG_CONFIG is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct
	 meltframe_meltrout_166_WARMELTmiNORMAL_NORMEXP_USE_PACKAGE_FROM_PKG_CONFIG_st
	 *) meltfirstargp_;
      /* use arguments meltrout_166_WARMELTmiNORMAL_NORMEXP_USE_PACKAGE_FROM_PKG_CONFIG output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 37; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_166_WARMELTmiNORMAL_NORMEXP_USE_PACKAGE_FROM_PKG_CONFIG nbval 37*/
  meltfram__.mcfr_nbvar = 37 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMEXP_USE_PACKAGE_FROM_PKG_CONFIG", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:8524:/ getarg");
 /*_.RECV__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2])) != NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3])) != NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.PSLOC__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.PSLOC__V5*/ meltfptr[4])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8525:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L1*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8525:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8525:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8525;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_use_package_from_pkg_config recv=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = "\n* ncx=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V6*/ meltfptr[5] =
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8525:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V6*/ meltfptr[5] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8525:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V6*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8526:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_USE_PACKAGE_FROM_PKG_CONFIG */ meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:8526:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[5] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8526:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check cheader recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8526) ? (8526) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8526:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8527:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:8527:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8527:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8527) ? (8527) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V10*/ meltfptr[5] = /*_._IFELSE___V11*/ meltfptr[10];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8527:/ clear");
	     /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8528:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L5*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[3])));;
      MELT_LOCATION ("warmelt-normal.melt:8528:/ cond");
      /*cond */ if ( /*_#IS_A__L5*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V13*/ meltfptr[12] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8528:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8528) ? (8528) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V12*/ meltfptr[10] = /*_._IFELSE___V13*/ meltfptr[12];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8528:/ clear");
	     /*clear *//*_#IS_A__L5*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V12*/ meltfptr[10] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:8529:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:8530:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.SLOC__V14*/ meltfptr[12] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:8531:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.RECV__V2*/ meltfptr[1]),
					(melt_ptr_t) (( /*!CLASS_SOURCE_USE_PACKAGE_FROM_PKG_CONFIG */ meltfrout->tabval[1])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 2, "SUSEPACKAGE_PKGTUPLE");
   /*_.PKGTUP__V15*/ meltfptr[14] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.PKGTUP__V15*/ meltfptr[14] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:8532:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.NCX__V4*/ meltfptr[3]),
					(melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */ meltfrout->tabval[3])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 11, "NCTX_MODULCONTEXT");
   /*_.MODCTX__V16*/ meltfptr[15] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.MODCTX__V16*/ meltfptr[15] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:8533:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.MODCTX__V16*/ meltfptr[15]),
					(melt_ptr_t) (( /*!CLASS_ANY_MODULE_CONTEXT */ meltfrout->tabval[4])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.MODCTX__V16*/ meltfptr[15]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 12, "MOCX_PACKAGEPCLIST");
   /*_.MCPACKAGELIST__V17*/ meltfptr[16] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.MCPACKAGELIST__V17*/ meltfptr[16] = NULL;;
      }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8535:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L6*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8535:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L6*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L7*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8535:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L7*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8535;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_use_package_from_pkg_config initial mcpackagelist=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.MCPACKAGELIST__V17*/ meltfptr[16];
	      /*_.MELT_DEBUG_FUN__V19*/ meltfptr[18] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V18*/ meltfptr[17] =
	      /*_.MELT_DEBUG_FUN__V19*/ meltfptr[18];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8535:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L7*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V19*/ meltfptr[18] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V18*/ meltfptr[17] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8535:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L6*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V18*/ meltfptr[17] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8536:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L8*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.MODCTX__V16*/ meltfptr[15]),
			     (melt_ptr_t) (( /*!CLASS_ANY_MODULE_CONTEXT */
					    meltfrout->tabval[4])));;
      MELT_LOCATION ("warmelt-normal.melt:8536:/ cond");
      /*cond */ if ( /*_#IS_A__L8*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V21*/ meltfptr[17] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8536:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check modctx"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8536) ? (8536) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V21*/ meltfptr[17] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V20*/ meltfptr[18] = /*_._IFELSE___V21*/ meltfptr[17];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8536:/ clear");
	     /*clear *//*_#IS_A__L8*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V21*/ meltfptr[17] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V20*/ meltfptr[18] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8537:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST__L9*/ meltfnum[0] =
	(melt_magic_discr
	 ((melt_ptr_t) ( /*_.MCPACKAGELIST__V17*/ meltfptr[16])) ==
	 MELTOBMAG_LIST);;
      MELT_LOCATION ("warmelt-normal.melt:8537:/ cond");
      /*cond */ if ( /*_#IS_LIST__L9*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V23*/ meltfptr[22] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:8537:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check mcpackagelist"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (8537) ? (8537) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V23*/ meltfptr[22] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V22*/ meltfptr[17] = /*_._IFELSE___V23*/ meltfptr[22];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:8537:/ clear");
	     /*clear *//*_#IS_LIST__L9*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V23*/ meltfptr[22] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V22*/ meltfptr[17] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    /*citerblock FOREACH_IN_MULTIPLE */
    {
      /* start foreach_in_multiple meltcit1__EACHTUP */
      long meltcit1__EACHTUP_ln =
	melt_multiple_length ((melt_ptr_t) /*_.PKGTUP__V15*/ meltfptr[14]);
      for ( /*_#PKGIX__L10*/ meltfnum[1] = 0;
	   ( /*_#PKGIX__L10*/ meltfnum[1] >= 0)
	   && ( /*_#PKGIX__L10*/ meltfnum[1] < meltcit1__EACHTUP_ln);
	/*_#PKGIX__L10*/ meltfnum[1]++)
	{
	  /*_.CURPKGNAME__V24*/ meltfptr[22] =
	    melt_multiple_nth ((melt_ptr_t) ( /*_.PKGTUP__V15*/ meltfptr[14]),
			       /*_#PKGIX__L10*/ meltfnum[1]);




#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:8542:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    {
	      /*^locexp */
	      /*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	      melt_dbgcounter++;
#endif
	      ;
	    }
	    ;

	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#MELT_NEED_DBG__L11*/ meltfnum[0] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:8542:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L11*/ meltfnum[0])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

      /*_#MELT_CALLCOUNT__L12*/ meltfnum[11] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:8542:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[5];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L12*/ meltfnum[11];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 8542;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normexp_use_package_from_pkg_config curpkgname=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURPKGNAME__V24*/ meltfptr[22];
		    /*_.MELT_DEBUG_FUN__V26*/ meltfptr[25] =
		      melt_apply ((meltclosure_ptr_t)
				  (( /*!MELT_DEBUG_FUN */ meltfrout->
				    tabval[0])),
				  (melt_ptr_t) (( /*nil */ NULL)),
				  (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR ""), argtab, "",
				  (union meltparam_un *) 0);
		  }
		  ;
		  /*_._IF___V25*/ meltfptr[24] =
		    /*_.MELT_DEBUG_FUN__V26*/ meltfptr[25];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:8542:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L12*/ meltfnum[11] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V26*/ meltfptr[25] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V25*/ meltfptr[24] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:8542:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L11*/ meltfnum[0] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V25*/ meltfptr[24] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*^block */
	  /*anyblock */
	  {


	    {
	      /*^locexp */
	      /*void */ (void) 0;
	    }
	    ;
	    /*epilog */
	  }

#endif /*MELT_HAVE_DEBUG */
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:8543:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#IS_STRING__L13*/ meltfnum[11] =
	      (melt_magic_discr
	       ((melt_ptr_t) ( /*_.CURPKGNAME__V24*/ meltfptr[22])) ==
	       MELTOBMAG_STRING);;
	    MELT_LOCATION ("warmelt-normal.melt:8543:/ cond");
	    /*cond */ if ( /*_#IS_STRING__L13*/ meltfnum[11])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V28*/ meltfptr[24] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:8543:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check curpkgname"),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(8543) ? (8543) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V28*/ meltfptr[24] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V27*/ meltfptr[25] =
	      /*_._IFELSE___V28*/ meltfptr[24];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8543:/ clear");
	      /*clear *//*_#IS_STRING__L13*/ meltfnum[11] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V28*/ meltfptr[24] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V27*/ meltfptr[25] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:8544:/ quasiblock");


  /*_#FOUND__L14*/ meltfnum[0] = 0;;
	  /*citerblock FOREACH_IN_LIST */
	  {
	    /* start foreach_in_list meltcit2__EACHLIST */
	    for ( /*_.CURPAIR__V30*/ meltfptr[29] =
		 melt_list_first ((melt_ptr_t) /*_.MCPACKAGELIST__V17*/
				  meltfptr[16]);
		 melt_magic_discr ((melt_ptr_t) /*_.CURPAIR__V30*/
				   meltfptr[29]) == MELTOBMAG_PAIR;
		 /*_.CURPAIR__V30*/ meltfptr[29] =
		 melt_pair_tail ((melt_ptr_t) /*_.CURPAIR__V30*/
				 meltfptr[29]))
	      {
		/*_.OLDPKGNAME__V31*/ meltfptr[30] =
		  melt_pair_head ((melt_ptr_t) /*_.CURPAIR__V30*/
				  meltfptr[29]);



		MELT_CHECK_SIGNAL ();
		;
   /*_#eqeqS__L15*/ meltfnum[11] =
		  melt_string_same ((melt_ptr_t)
				    ( /*_.OLDPKGNAME__V31*/ meltfptr[30]),
				    (melt_ptr_t) ( /*_.CURPKGNAME__V24*/
						  meltfptr[22]));;
		MELT_LOCATION ("warmelt-normal.melt:8549:/ cond");
		/*cond */ if ( /*_#eqeqS__L15*/ meltfnum[11])	/*then */
		  {
		    /*^cond.then */
		    /*^block */
		    /*anyblock */
		    {

		      MELT_LOCATION ("warmelt-normal.melt:8550:/ compute");
		      /*_#FOUND__L14*/ meltfnum[0] =
			/*_#SETQ___L16*/ meltfnum[15] = 1;;
		      MELT_LOCATION ("warmelt-normal.melt:8551:/ compute");
		      /*_.CURPAIR__V30*/ meltfptr[29] =
			/*_.SETQ___V33*/ meltfptr[32] = ( /*nil */ NULL);;
		      MELT_LOCATION ("warmelt-normal.melt:8549:/ quasiblock");


		      /*_.PROGN___V34*/ meltfptr[33] =
			/*_.SETQ___V33*/ meltfptr[32];;
		      /*^compute */
		      /*_._IF___V32*/ meltfptr[31] =
			/*_.PROGN___V34*/ meltfptr[33];;
		      /*epilog */

		      MELT_LOCATION ("warmelt-normal.melt:8549:/ clear");
	       /*clear *//*_#SETQ___L16*/ meltfnum[15] = 0;
		      /*^clear */
	       /*clear *//*_.SETQ___V33*/ meltfptr[32] = 0;
		      /*^clear */
	       /*clear *//*_.PROGN___V34*/ meltfptr[33] = 0;
		    }
		    ;
		  }
		else
		  {		/*^cond.else */

    /*_._IF___V32*/ meltfptr[31] = NULL;;
		  }
		;
	      }			/* end foreach_in_list meltcit2__EACHLIST */
     /*_.CURPAIR__V30*/ meltfptr[29] = NULL;
     /*_.OLDPKGNAME__V31*/ meltfptr[30] = NULL;


	    /*citerepilog */

	    MELT_LOCATION ("warmelt-normal.melt:8546:/ clear");
	     /*clear *//*_.CURPAIR__V30*/ meltfptr[29] = 0;
	    /*^clear */
	     /*clear *//*_.OLDPKGNAME__V31*/ meltfptr[30] = 0;
	    /*^clear */
	     /*clear *//*_#eqeqS__L15*/ meltfnum[11] = 0;
	    /*^clear */
	     /*clear *//*_._IF___V32*/ meltfptr[31] = 0;
	  }			/*endciterblock FOREACH_IN_LIST */
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:8552:/ cond");
	  /*cond */ if ( /*_#FOUND__L14*/ meltfnum[0])	/*then */
	    {
	      /*^cond.then */
	      /*_._IFELSE___V35*/ meltfptr[32] = ( /*nil */ NULL);;
	    }
	  else
	    {
	      MELT_LOCATION ("warmelt-normal.melt:8552:/ cond.else");

	      /*^block */
	      /*anyblock */
	      {


		{
		  MELT_LOCATION ("warmelt-normal.melt:8553:/ locexp");
		  meltgc_append_list ((melt_ptr_t)
				      ( /*_.MCPACKAGELIST__V17*/
				       meltfptr[16]),
				      (melt_ptr_t) ( /*_.CURPKGNAME__V24*/
						    meltfptr[22]));
		}
		;
		MELT_LOCATION ("warmelt-normal.melt:8552:/ quasiblock");


		/*epilog */
	      }
	      ;
	    }
	  ;
	  /*_.LET___V29*/ meltfptr[24] = /*_._IFELSE___V35*/ meltfptr[32];;

	  MELT_LOCATION ("warmelt-normal.melt:8544:/ clear");
	    /*clear *//*_#FOUND__L14*/ meltfnum[0] = 0;
	  /*^clear */
	    /*clear *//*_._IFELSE___V35*/ meltfptr[32] = 0;
	  if ( /*_#PKGIX__L10*/ meltfnum[1] < 0)
	    break;
	}			/* end  foreach_in_multiple meltcit1__EACHTUP */

      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:8539:/ clear");
	    /*clear *//*_.CURPKGNAME__V24*/ meltfptr[22] = 0;
      /*^clear */
	    /*clear *//*_#PKGIX__L10*/ meltfnum[1] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V27*/ meltfptr[25] = 0;
      /*^clear */
	    /*clear *//*_.LET___V29*/ meltfptr[24] = 0;
    }				/*endciterblock FOREACH_IN_MULTIPLE */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:8557:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L17*/ meltfnum[15] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:8557:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L17*/ meltfnum[15])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L18*/ meltfnum[0] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:8557:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L18*/ meltfnum[0];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 8557;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_use_package_from_pkg_config final mcpackagelist=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.MCPACKAGELIST__V17*/ meltfptr[16];
	      /*_.MELT_DEBUG_FUN__V37*/ meltfptr[32] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V36*/ meltfptr[33] =
	      /*_.MELT_DEBUG_FUN__V37*/ meltfptr[32];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:8557:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L18*/ meltfnum[0] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V37*/ meltfptr[32] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V36*/ meltfptr[33] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:8557:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L17*/ meltfnum[15] = 0;
      /*^clear */
	     /*clear *//*_._IF___V36*/ meltfptr[33] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_LOCATION ("warmelt-normal.melt:8529:/ clear");
	   /*clear *//*_.SLOC__V14*/ meltfptr[12] = 0;
    /*^clear */
	   /*clear *//*_.PKGTUP__V15*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.MODCTX__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.MCPACKAGELIST__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V20*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V22*/ meltfptr[17] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    /*epilog */

    MELT_LOCATION ("warmelt-normal.melt:8524:/ clear");
	   /*clear *//*_.IFCPP___V8*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V10*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V12*/ meltfptr[10] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMEXP_USE_PACKAGE_FROM_PKG_CONFIG", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_166_WARMELTmiNORMAL_NORMEXP_USE_PACKAGE_FROM_PKG_CONFIG_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*noretval */ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_166_WARMELTmiNORMAL_NORMEXP_USE_PACKAGE_FROM_PKG_CONFIG */



/**** end of warmelt-normal+06.c ****/
