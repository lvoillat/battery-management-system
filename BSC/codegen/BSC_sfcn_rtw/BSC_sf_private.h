/*
 * BSC_sf_private.h
 *
 * Code generation for model "BSC_sf".
 *
 * Model version              : 1.222
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Fri Jun 12 17:13:53 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BSC_sf_private_h_
#define RTW_HEADER_BSC_sf_private_h_
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

void BSC_check_type_Init(B_check_type_BSC_T *localB);
void BSC_check_type(SimStruct * const S, uint8_T rtu_In1, uint8_T rtu_In2,
                    uint8_T rtu_In3, uint8_T rtu_In4, uint8_T rtu_In5, uint8_T
                    rtu_In6, uint8_T rtu_In7, uint8_T rtu_In8, uint8_T rtu_In9,
                    uint8_T rtu_In10, uint8_T rtu_In11, B_check_type_BSC_T
                    *localB);
void BSC_key_cycle_Init(SimStruct * const S, B_key_cycle_BSC_T *localB);
void BSC_key_cycle(SimStruct * const S, uint8_T rtu_med_fault, uint8_T rtu_key,
                   B_key_cycle_BSC_T *localB, ZCE_key_cycle_BSC_T *localZCE);
void BSC_Fault_level(SimStruct * const S);
void BSC_sleepCheck(SimStruct * const S);
void BSC_cc_cmd(SimStruct * const S);
void BSC_rsnToOpenCC(SimStruct * const S);

#endif                                 /* RTW_HEADER_BSC_sf_private_h_ */
