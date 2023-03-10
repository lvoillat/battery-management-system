/*
 * SOP_sf_private.h
 *
 * Code generation for model "SOP_sf".
 *
 * Model version              : 1.51
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed May 27 11:06:28 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SOP_sf_private_h_
#define RTW_HEADER_SOP_sf_private_h_
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
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_SOP_sf)
#define bmsc_CellMaxVolt(S)            _ssGetSFcnParam(S,0)
#define bmsc_CellMinVolt(S)            _ssGetSFcnParam(S,1)
#define bmsc_InternalChgResistX(S)     _ssGetSFcnParam(S,2)
#define bmsc_InternalChgResistY(S)     _ssGetSFcnParam(S,3)
#define bmsc_InternalChgResistZ(S)     _ssGetSFcnParam(S,4)
#define bmsc_InternalDischgResistX(S)  _ssGetSFcnParam(S,5)
#define bmsc_InternalDischgResistY(S)  _ssGetSFcnParam(S,6)
#define bmsc_InternalDischgResistZ(S)  _ssGetSFcnParam(S,7)
#define bmsc_NumberInPara(S)           _ssGetSFcnParam(S,8)
#define bmsc_NumberInSeries(S)         _ssGetSFcnParam(S,9)
#define sopc_ChargeDerate(S)           _ssGetSFcnParam(S,10)
#define sopc_ChgFaultDerate(S)         _ssGetSFcnParam(S,11)
#define sopc_DischargeDerate(S)        _ssGetSFcnParam(S,12)
#define sopc_DischgFaultDerate(S)      _ssGetSFcnParam(S,13)
#define sopc_SOCVsOCVX(S)              _ssGetSFcnParam(S,14)
#define sopc_SOCVsOCVY(S)              _ssGetSFcnParam(S,15)
#endif                                 /* RTW_GENERATED_SFCN_TUNABLE_PRMS_SOP_sf */

extern real_T SOP_look2_binlx(real_T u0, real_T u1, const real_T bp0[], const
  real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);
extern real_T SOP_look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);

#endif                                 /* RTW_HEADER_SOP_sf_private_h_ */
