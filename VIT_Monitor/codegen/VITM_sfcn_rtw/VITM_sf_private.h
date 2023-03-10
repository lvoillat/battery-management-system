/*
 * VITM_sf_private.h
 *
 * Code generation for model "VITM_sf".
 *
 * Model version              : 1.125
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed May 27 10:18:24 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_VITM_sf_private_h_
#define RTW_HEADER_VITM_sf_private_h_
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
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_VITM_sf)
#define vitc_CellPackVolTol(S)         _ssGetSFcnParam(S,0)
#define vitc_CellTempFaultTimer(S)     _ssGetSFcnParam(S,1)
#define vitc_CellTempFilterC(S)        _ssGetSFcnParam(S,2)
#define vitc_CellTempHighFaultReset(S) _ssGetSFcnParam(S,3)
#define vitc_CellTempLowFaultReset(S)  _ssGetSFcnParam(S,4)
#define vitc_CellTempMax(S)            _ssGetSFcnParam(S,5)
#define vitc_CellTempMin(S)            _ssGetSFcnParam(S,6)
#define vitc_CellVolFilterC(S)         _ssGetSFcnParam(S,7)
#define vitc_CellVoltageFaultTimer(S)  _ssGetSFcnParam(S,8)
#define vitc_CellVoltageHighFaultReset(S) _ssGetSFcnParam(S,9)
#define vitc_CellVoltageLowFaultReset(S) _ssGetSFcnParam(S,10)
#define vitc_CellVoltageMax(S)         _ssGetSFcnParam(S,11)
#define vitc_CellVoltageMin(S)         _ssGetSFcnParam(S,12)
#define vitc_CoolantInletTFaultReset(S) _ssGetSFcnParam(S,13)
#define vitc_CoolantInletTLowerLim(S)  _ssGetSFcnParam(S,14)
#define vitc_CoolantInletTUpperLim(S)  _ssGetSFcnParam(S,15)
#define vitc_CoolantOutletTFaultReset(S) _ssGetSFcnParam(S,16)
#define vitc_CoolantOutletTLowerLim(S) _ssGetSFcnParam(S,17)
#define vitc_CoolantOutletTUpperLim(S) _ssGetSFcnParam(S,18)
#define vitc_CoolantTFilterC(S)        _ssGetSFcnParam(S,19)
#define vitc_CoolantTempFaultCounter(S) _ssGetSFcnParam(S,20)
#define vitc_HVILFaultCounter(S)       _ssGetSFcnParam(S,21)
#define vitc_HVILFaultReset(S)         _ssGetSFcnParam(S,22)
#define vitc_PackCurFilterC(S)         _ssGetSFcnParam(S,23)
#define vitc_PackCurrentFaultReset(S)  _ssGetSFcnParam(S,24)
#define vitc_PackCurrentFaultTimer(S)  _ssGetSFcnParam(S,25)
#define vitc_PackCurrentLimit(S)       _ssGetSFcnParam(S,26)
#define vitc_PackVolFilterC(S)         _ssGetSFcnParam(S,27)
#define vitc_PackVoltageFaultReset(S)  _ssGetSFcnParam(S,28)
#define vitc_PackVoltageFaultTimer(S)  _ssGetSFcnParam(S,29)
#define vitc_VehVolFilterC(S)          _ssGetSFcnParam(S,30)
#define vitk_NumberInPara(S)           _ssGetSFcnParam(S,31)
#define vitk_NumberInSeries(S)         _ssGetSFcnParam(S,32)
#define vitk_stepSize(S)               _ssGetSFcnParam(S,33)
#endif                                 /* RTW_GENERATED_SFCN_TUNABLE_PRMS_VITM_sf */
#endif                                 /* RTW_HEADER_VITM_sf_private_h_ */
