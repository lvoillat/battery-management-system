/*
 * BTC_sf_private.h
 *
 * Code generation for model "BTC_sf".
 *
 * Model version              : 1.56
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed May 27 11:48:01 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BTC_sf_private_h_
#define RTW_HEADER_BTC_sf_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#if !defined(ss_VALIDATE_MEMORY)
#define ss_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
 ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
 }
#endif

#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((ptr));\
 (ptr) = (NULL);\
 }
#else

/* Visual and other windows compilers declare free without const */
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((void *)(ptr));\
 (ptr) = (NULL);\
 }
#endif
#endif

/*
 * Tunable Parameters
 *
 * Note: Tunable parameters with Auto storage class are treated as S-Function
 * parameters in the generated S-Function Target.  The generated
 * s-function will declare them as parameters and verify correct data
 * types/sizes are maintained.  The parameters are propagated to nested
 * non-inlined S-Functions
 *
 */
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_BTC_sf)
#define btcc_Ki(S)                     _ssGetSFcnParam(S,0)
#define btcc_Kp(S)                     _ssGetSFcnParam(S,1)
#define btcc_ambient_temp_highth(S)    _ssGetSFcnParam(S,2)
#define btcc_ambient_temp_lowth(S)     _ssGetSFcnParam(S,3)
#define btcc_cell_temp_diffth(S)       _ssGetSFcnParam(S,4)
#define btcc_full_soc(S)               _ssGetSFcnParam(S,5)
#define btcc_max_temp_highth(S)        _ssGetSFcnParam(S,6)
#define btcc_max_temp_lowth(S)         _ssGetSFcnParam(S,7)
#define btcc_min_temp_highth(S)        _ssGetSFcnParam(S,8)
#define btcc_min_temp_lowth(S)         _ssGetSFcnParam(S,9)
#define btcc_number_in_series(S)       _ssGetSFcnParam(S,10)
#define btcc_pack_in_parallel(S)       _ssGetSFcnParam(S,11)
#define btck_stepSize(S)               _ssGetSFcnParam(S,12)
#endif                                 /* RTW_GENERATED_SFCN_TUNABLE_PRMS_BTC_sf */
#endif                                 /* RTW_HEADER_BTC_sf_private_h_ */
