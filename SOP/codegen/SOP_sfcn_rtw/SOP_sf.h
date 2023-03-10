/*
 * SOP_sf.h
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

#ifndef RTW_HEADER_SOP_sf_h_
#define RTW_HEADER_SOP_sf_h_
#include <string.h>
#include <stddef.h>
#ifndef SOP_sf_COMMON_INCLUDES_
# define SOP_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                SOP_sf
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if !defined(MATLAB_MEX_FILE)
#include "rt_matrx.h"
#endif

#if !defined(RTW_SFUNCTION_DEFINES)
#define RTW_SFUNCTION_DEFINES

typedef struct {
  void *blockIO;
  void *defaultParam;
  void *nonContDerivSig;
} LocalS;

#define ssSetLocalBlockIO(S, io)       ((LocalS *)ssGetUserData(S))->blockIO = ((void *)(io))
#define ssGetLocalBlockIO(S)           ((LocalS *)ssGetUserData(S))->blockIO
#define ssSetLocalDefaultParam(S, paramVector) ((LocalS *)ssGetUserData(S))->defaultParam = (paramVector)
#define ssGetLocalDefaultParam(S)      ((LocalS *)ssGetUserData(S))->defaultParam
#define ssSetLocalNonContDerivSig(S, pSig) ((LocalS *)ssGetUserData(S))->nonContDerivSig = (pSig)
#define ssGetLocalNonContDerivSig(S)   ((LocalS *)ssGetUserData(S))->nonContDerivSig
#endif
#endif                                 /* SOP_sf_COMMON_INCLUDES_ */

#include "SOP_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rtGetInf.h"
#include "rt_defines.h"

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S1>/chg_internal_resistance_table'
   *   '<S1>/dischg_internal_resistance_table'
   */
  uint32_T pooled3[2];
} ConstP_SOP_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *cell_temp[40];               /* '<Root>/cell_temp' */
  real_T *cell_SOC[40];                /* '<Root>/cell_SOC' */
  boolean_T *charging_status;          /* '<Root>/charging_status' */
  boolean_T *discharging_status;       /* '<Root>/discharging_status' */
  uint8_T *cellTmepHighFault;          /* '<Root>/cellTmepHighFault' */
  uint8_T *pack_current_fault;         /* '<Root>/pack_current_fault' */
  uint8_T *pack_voltage_fault;         /* '<Root>/pack_voltage_fault' */
  uint8_T *low_fault;                  /* '<Root>/low_fault' */
  real_T *Internal_Resis_Scaling_Factor[40];/* '<Root>/Internal_Resis_Scaling_Factor' */
} ExternalUPtrs_SOP_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *discharge_power_limit;       /* '<Root>/discharge_power_limit' */
  real_T *discharge_current_limit;     /* '<Root>/discharge_current_limit' */
  real_T *charge_power_limit;          /* '<Root>/charge_power_limit' */
  real_T *charge_current_limit;        /* '<Root>/charge_current_limit' */
} ExtY_SOP_T;

/* Parameters (auto storage) */
struct P_SOP_T_ {
  real_T bmsc_CellMaxVolt;             /* Variable: bmsc_CellMaxVolt
                                        * Referenced by:
                                        *   '<S1>/Constant3'
                                        *   '<S1>/Constant8'
                                        *   '<S1>/Constant9'
                                        */
  real_T bmsc_CellMinVolt;             /* Variable: bmsc_CellMinVolt
                                        * Referenced by:
                                        *   '<S1>/Constant1'
                                        *   '<S1>/Constant4'
                                        *   '<S1>/Constant5'
                                        */
  real_T bmsc_InternalChgResistX[3];   /* Variable: bmsc_InternalChgResistX
                                        * Referenced by: '<S1>/chg_internal_resistance_table'
                                        */
  real_T bmsc_InternalChgResistY[101]; /* Variable: bmsc_InternalChgResistY
                                        * Referenced by: '<S1>/chg_internal_resistance_table'
                                        */
  real_T bmsc_InternalChgResistZ[303]; /* Variable: bmsc_InternalChgResistZ
                                        * Referenced by: '<S1>/chg_internal_resistance_table'
                                        */
  real_T bmsc_InternalDischgResistX[3];/* Variable: bmsc_InternalDischgResistX
                                        * Referenced by: '<S1>/dischg_internal_resistance_table'
                                        */
  real_T bmsc_InternalDischgResistY[101];/* Variable: bmsc_InternalDischgResistY
                                          * Referenced by: '<S1>/dischg_internal_resistance_table'
                                          */
  real_T bmsc_InternalDischgResistZ[303];/* Variable: bmsc_InternalDischgResistZ
                                          * Referenced by: '<S1>/dischg_internal_resistance_table'
                                          */
  real_T bmsc_NumberInPara;            /* Variable: bmsc_NumberInPara
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S1>/Constant11'
                                        *   '<S1>/Constant2'
                                        *   '<S1>/Constant7'
                                        */
  real_T bmsc_NumberInSeries;          /* Variable: bmsc_NumberInSeries
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S1>/Constant10'
                                        *   '<S1>/Constant2'
                                        *   '<S1>/Constant6'
                                        */
  real_T sopc_ChargeDerate;            /* Variable: sopc_ChargeDerate
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T sopc_ChgFaultDerate;          /* Variable: sopc_ChgFaultDerate
                                        * Referenced by: '<S1>/Constant15'
                                        */
  real_T sopc_DischargeDerate;         /* Variable: sopc_DischargeDerate
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T sopc_DischgFaultDerate;       /* Variable: sopc_DischgFaultDerate
                                        * Referenced by: '<S1>/Constant13'
                                        */
  real_T sopc_SOCVsOCVX[101];          /* Variable: sopc_SOCVsOCVX
                                        * Referenced by: '<S1>/SOC versus OCV table'
                                        */
  real_T sopc_SOCVsOCVY[101];          /* Variable: sopc_SOCVsOCVY
                                        * Referenced by: '<S1>/SOC versus OCV table'
                                        */
};

extern P_SOP_T SOP_DefaultP;

/* Constant parameters (auto storage) */
extern const ConstP_SOP_T SOP_ConstP;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('sop_codegen/SOP')    - opens subsystem sop_codegen/SOP
 * hilite_system('sop_codegen/SOP/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'sop_codegen'
 * '<S1>'   : 'sop_codegen/SOP'
 */
#endif                                 /* RTW_HEADER_SOP_sf_h_ */
