/*
 * soh_sf_private.h
 *
 * Code generation for model "soh_sf".
 *
 * Model version              : 1.270
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed May 27 10:32:13 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_soh_sf_private_h_
#define RTW_HEADER_soh_sf_private_h_
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
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_soh_sf)
#define bmsc_InternalDischgResistX(S)  _ssGetSFcnParam(S,0)
#define bmsc_InternalDischgResistY(S)  _ssGetSFcnParam(S,1)
#define bmsc_InternalDischgResistZ(S)  _ssGetSFcnParam(S,2)
#define sohc_current_threshold(S)      _ssGetSFcnParam(S,3)
#define sohc_customer_filter_coeff(S)  _ssGetSFcnParam(S,4)
#define sohc_filter_coeff(S)           _ssGetSFcnParam(S,5)
#define sohc_pct_R_limit(S)            _ssGetSFcnParam(S,6)
#define sohk_CellBalancingResistor(S)  _ssGetSFcnParam(S,7)
#define sohv_factoryInit_sohc(S)       _ssGetSFcnParam(S,8)
#define sohv_factoryInit_sohr(S)       _ssGetSFcnParam(S,9)
#endif                                 /* RTW_GENERATED_SFCN_TUNABLE_PRMS_soh_sf */

extern real_T soh_look2_binlx(real_T u0, real_T u1, const real_T bp0[], const
  real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);
void soh_init(const real_T rtu_soc_C_factors_init[40], B_init_soh_T *localB,
              real_T rtd_memStore_Rfactors[40]);
void soh_deltaCalc_Init(SimStruct * const S);
void soh_deltaCalc(SimStruct * const S, real_T rtu_PackCurrent, const real_T
                   rtu_CellVoltages[40], const real_T rtu_CellSOC[40], const
                   real_T rtu_CellTemp[40], const boolean_T rtu_cb_cmds[40],
                   B_deltaCalc_soh_T *localB);
void soh_key_on_Init(SimStruct * const S);
void soh_key_on(SimStruct * const S);
void soh_SOH_Start(SimStruct * const S);
void soh_SOH(SimStruct * const S);

#endif                                 /* RTW_HEADER_soh_sf_private_h_ */
