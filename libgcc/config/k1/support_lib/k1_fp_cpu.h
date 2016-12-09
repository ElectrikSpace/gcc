#include <support_lib/registers.h>
#ifndef __k1_fpu_rounding_mode
/**
 * \enum __k1_fpu_rounding_mode
 * \brief Rounding modes supported by K1's FPU.
 */
enum __k1_fpu_rounding_mode {
    _K1_FPU_NEAREST_EVEN      = 0,
    _K1_FPU_TOWARDS_PLUS_INF  = 1,
    _K1_FPU_TOWARDS_MINUS_INF = 2,
    _K1_FPU_TOWARDS_ZERO      = 3
};
#endif

#ifndef __k1_fpu_set_rounding_mode
/**
 * \fn static inline void __k1_fpu_set_rounding_mode(enum __k1_fpu_rounding_mode)
 * \brief Set the FPU rounding mode
 */
static __inline__ void __k1_fpu_set_rounding_mode(enum __k1_fpu_rounding_mode mode)
{
    int offset = __builtin_k1_ctz (_K1_HFX_CS_RM);
    __builtin_k1_hfxb (_K1_SFR_CS, 
		       ((mode << offset) & _K1_HFX_CS_RM) << 16 
		       | _K1_HFX_CS_RM);
    __builtin_k1_barrier ();
}
#endif

#ifndef __k1_fpu_get_rounding_mode
/**
 * \fn static inline enum __k1_fpu_rounding_mode __k1_fpu_get_rounding_mode(void)
 * \brief Get the FPU rounding mode
 */
static __inline__ enum __k1_fpu_rounding_mode __k1_fpu_get_rounding_mode(void)
{
    int offset = __builtin_k1_ctz (_K1_MASK_CS_RM);
    return (enum __k1_fpu_rounding_mode)((__builtin_k1_get (_K1_SFR_CS) & _K1_MASK_CS_RM) >> offset);
}
#endif

#ifndef __k1_fpu_exceptions
/**
 * \enum __k1_fpu_exceptions
 * \brief Exceptions generated by K1's FPU.
 */
enum __k1_fpu_exceptions {
    _K1_FPU_INVALID_OPERATION = _K1_MASK_CS_IO,
    _K1_FPU_DIVIDE_BY_ZERO    = _K1_MASK_CS_DZ,
    _K1_FPU_OVERFLOW          = _K1_MASK_CS_OV,
    _K1_FPU_UNDERFLOW         = _K1_MASK_CS_UN,
    _K1_FPU_INEXACT           = _K1_MASK_CS_IN,
    _K1_FPU_ALL_EXCEPTS       = _K1_MASK_CS_IO|_K1_MASK_CS_DZ|_K1_MASK_CS_OV|_K1_MASK_CS_UN|_K1_MASK_CS_IN
};
#endif


#ifndef __k1_fpu_raise_exceptions
/**
 * \fn static inline void __k1_fpu_raise_exceptions
 * \brief Set the requested FPU excpetion flags (see enum __k1_fpu_exceptions)
 */
static __inline__ void __k1_fpu_raise_exceptions(int excepts)
{
    __builtin_k1_hfxb (_K1_SFR_CS, 
		       (excepts & _K1_FPU_ALL_EXCEPTS) << 16);
}
#endif

#ifndef __k1_fpu_clear_exceptions
/**
 * \fn static inline void __k1_fpu_clear_exceptions
 * \brief Clear the requested FPU excpetion flags (see enum __k1_fpu_exceptions)
 */
static __inline__ void __k1_fpu_clear_exceptions(int excepts)
{
    __builtin_k1_hfxb (_K1_SFR_CS, excepts & _K1_FPU_ALL_EXCEPTS);
}
#endif /* __k1_fpu_clear_exceptions */

#ifndef __k1_fpu_get_exceptions
/**
 * \fn static inline unsigned int __k1_fpu_get_exceptions
 * \brief Get the FPU excpetion flags (see enum __k1_fpu_exceptions)
 */
static __inline__ unsigned int __k1_fpu_get_exceptions(void)
{
    return __builtin_k1_get (_K1_SFR_CS) & _K1_FPU_ALL_EXCEPTS;
}
#endif /* __k1_fpu_get_exceptions */
