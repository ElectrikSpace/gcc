#include <libgccjit.h>

#include <stdlib.h>
#include <stdio.h>

void
create_code (gcc_jit_context *ctxt)
{
  /* Let's try to inject the equivalent of:

      int square (int i)
      {
        return i * i;
      }
  */
  gcc_jit_type *int_type =
    gcc_jit_context_get_type (ctxt, GCC_JIT_TYPE_INT);
  gcc_jit_param *param_i =
    gcc_jit_context_new_param (ctxt, NULL, int_type, "i");
  gcc_jit_function *func =
    gcc_jit_context_new_function (ctxt, NULL,
                                  GCC_JIT_FUNCTION_EXPORTED,
                                  int_type,
                                  "square",
                                  1, &param_i,
                                  0);

  gcc_jit_block *block = gcc_jit_function_new_block (func, NULL);

  gcc_jit_rvalue *expr =
    gcc_jit_context_new_binary_op (
      ctxt, NULL,
      GCC_JIT_BINARY_OP_MULT, int_type,
      gcc_jit_param_as_rvalue (param_i),
      gcc_jit_param_as_rvalue (param_i));

   gcc_jit_block_end_with_return (block, NULL, expr);
}

int
main (int argc, char **argv)
{
  gcc_jit_context *ctxt = NULL;
  gcc_jit_result *result = NULL;

  /* Get a "context" object for working with the library.  */
  ctxt = gcc_jit_context_acquire ();
  if (!ctxt)
    {
      fprintf (stderr, "NULL ctxt");
      goto error;
    }

  /* Set some options on the context.
     Let's see the code being generated, in assembler form.  */
  gcc_jit_context_set_bool_option (
    ctxt,
    GCC_JIT_BOOL_OPTION_DUMP_GENERATED_CODE,
    0);

  /* Populate the context.  */
  create_code (ctxt);

  /* Compile the code.  */
  result = gcc_jit_context_compile (ctxt);
  if (!result)
    {
      fprintf (stderr, "NULL result");
      goto error;
    }

  /* Extract the generated code from "result".  */
  void *fn_ptr = gcc_jit_result_get_code (result, "square");
  if (!fn_ptr)
     {
       fprintf (stderr, "NULL fn_ptr");
       goto error;
     }

  typedef int (*fn_type) (int);
  fn_type square = (fn_type)fn_ptr;
  printf ("result: %d", square (5));

 error:
  gcc_jit_context_release (ctxt);
  gcc_jit_result_release (result);
  return 0;
}
