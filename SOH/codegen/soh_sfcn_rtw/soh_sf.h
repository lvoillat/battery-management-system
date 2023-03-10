/*
 * soh_sf.h
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

#ifndef RTW_HEADER_soh_sf_h_
#define RTW_HEADER_soh_sf_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef soh_sf_COMMON_INCLUDES_
# define soh_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                soh_sf
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
#endif                                 /* soh_sf_COMMON_INCLUDES_ */

#include "soh_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rtGetInf.h"
#include "rt_defines.h"

/* Block signals for system '<S1>/init' */
typedef struct {
  real_T DataStoreRead1[40];           /* '<S6>/Data Store Read1' */
  real_T soc_C_factors_init[40];       /* '<S6>/soc_C_factors_init' */
} B_init_soh_T;

/* Block signals for system '<S1>/deltaCalc' */
typedef struct {
  real_T Subtract[40];                 /* '<S5>/Subtract' */
  real_T Subtract1[40];                /* '<S5>/Subtract1' */
  real_T uDLookupTable1[40];           /* '<S5>/2-D Lookup Table1' */
} B_deltaCalc_soh_T;

/* Block signals (auto storage) */
typedef struct {
  real_T init_keyon_reset;             /* '<S1>/Chart' */
  real_T Gain[40];                     /* '<S4>/Gain' */
  real_T Gain3;                        /* '<S4>/Gain3' */
  real_T Saturation[40];               /* '<S8>/Saturation' */
  real_T Gain3_p;                      /* '<S8>/Gain3' */
  real_T Gain_c;                       /* '<S7>/Gain' */
  B_deltaCalc_soh_T deltaCalc;         /* '<S1>/deltaCalc' */
  B_init_soh_T init;                   /* '<S1>/init' */
} B_soh_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay3_Reset_ZCE;         /* '<S8>/Delay3' */
} PrevZCX_soh_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: uDLookupTable1_maxIndex
   * Referenced by: '<S5>/2-D Lookup Table1'
   */
  uint32_T uDLookupTable1_maxIndex[2];
} ConstP_soh_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  boolean_T *ChargingStatus;           /* '<Root>/Charging Status' */
  boolean_T *DischargingStatus;        /* '<Root>/Discharging Status' */
  real_T *PackCurrent;                 /* '<Root>/Pack Current' */
  real_T *CellVoltages[40];            /* '<Root>/Cell Voltages' */
  real_T *CellSOC[40];                 /* '<Root>/Cell SOC' */
  real_T *CellTemp[40];                /* '<Root>/Cell Temp' */
  real_T *soc_C_factors[40];           /* '<Root>/soc_C_factors' */
  boolean_T *main_contactor;           /* '<Root>/main_contactor' */
  boolean_T *charger_contactor;        /* '<Root>/charger_contactor' */
  boolean_T *pre_chg_contactor;        /* '<Root>/pre_chg_contactor' */
  boolean_T *cb_cmds[40];              /* '<Root>/cb_cmds' */
} ExternalUPtrs_soh_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *soh_R_index;                 /* '<Root>/soh_R_index' */
  real_T *soh_R_factors[40];           /* '<Root>/soh_R_factors' */
  real_T *soh_C_index;                 /* '<Root>/soh_C_index' */
  real_T *soh_C_factors[40];           /* '<Root>/soh_C_factors' */
  real_T *soh_customer_index;          /* '<Root>/soh_customer_index' */
} ExtY_soh_T;

/* Parameters (auto storage) */
struct P_soh_T_ {
  real_T bmsc_InternalDischgResistX[3];/* Variable: bmsc_InternalDischgResistX
                                        * Referenced by: '<S5>/2-D Lookup Table1'
                                        */
  real_T bmsc_InternalDischgResistY[101];/* Variable: bmsc_InternalDischgResistY
                                          * Referenced by: '<S5>/2-D Lookup Table1'
                                          */
  real_T bmsc_InternalDischgResistZ[303];/* Variable: bmsc_InternalDischgResistZ
                                          * Referenced by: '<S5>/2-D Lookup Table1'
                                          */
  real_T sohc_current_threshold;       /* Variable: sohc_current_threshold
                                        * Referenced by: '<S9>/Constant2'
                                        */
  real_T sohc_customer_filter_coeff;   /* Variable: sohc_customer_filter_coeff
                                        * Referenced by:
                                        *   '<S7>/Gain1'
                                        *   '<S7>/Gain2'
                                        *   '<S7>/Gain6'
                                        *   '<S7>/Gain7'
                                        */
  real_T sohc_filter_coeff;            /* Variable: sohc_filter_coeff
                                        * Referenced by:
                                        *   '<S8>/Gain6'
                                        *   '<S8>/Gain7'
                                        */
  real_T sohc_pct_R_limit;             /* Variable: sohc_pct_R_limit
                                        * Referenced by: '<S8>/Gain8'
                                        */
  real_T sohk_CellBalancingResistor;   /* Variable: sohk_CellBalancingResistor
                                        * Referenced by: '<S5>/Constant4'
                                        */
  real_T sohv_factoryInit_sohc[40];    /* Variable: sohv_factoryInit_sohc
                                        * Referenced by: '<S7>/Delay1'
                                        */
  real_T sohv_factoryInit_sohr[40];    /* Variable: sohv_factoryInit_sohr
                                        * Referenced by:
                                        *   '<S1>/Data Store Memory1'
                                        *   '<S7>/Delay3'
                                        */
};

extern P_soh_T soh_DefaultP;

/* Constant parameters (auto storage) */
extern const ConstP_soh_T soh_ConstP;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Data Type Propagation' : Unused code path elimination
 * Block '<S9>/Abs2' : Unused code path elimination
 * Block '<S9>/Abs3' : Unused code path elimination
 * Block '<S9>/Constant5' : Unused code path elimination
 * Block '<S9>/Constant6' : Unused code path elimination
 * Block '<S9>/Logical Operator2' : Unused code path elimination
 * Block '<S9>/Relational Operator4' : Unused code path elimination
 * Block '<S9>/Relational Operator6' : Unused code path elimination
 * Block '<S5>/2-D Lookup Table' : Unused code path elimination
 * Block '<S5>/Delay4' : Unused code path elimination
 * Block '<S5>/Switch1' : Unused code path elimination
 * Block '<S5>/Switch2' : Unused code path elimination
 * Block '<S5>/Switch3' : Unused code path elimination
 */

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
 * hilite_system('soh_codegen/soh')    - opens subsystem soh_codegen/soh
 * hilite_system('soh_codegen/soh/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'soh_codegen'
 * '<S1>'   : 'soh_codegen/soh'
 * '<S2>'   : 'soh_codegen/soh/Chart'
 * '<S3>'   : 'soh_codegen/soh/DataStore'
 * '<S4>'   : 'soh_codegen/soh/SOH'
 * '<S5>'   : 'soh_codegen/soh/deltaCalc'
 * '<S6>'   : 'soh_codegen/soh/init'
 * '<S7>'   : 'soh_codegen/soh/key_on'
 * '<S8>'   : 'soh_codegen/soh/SOH/SOHRcalc'
 * '<S9>'   : 'soh_codegen/soh/SOH/SOHRtrigger'
 * '<S10>'  : 'soh_codegen/soh/SOH/SOHRcalc/Saturation Dynamic'
 */
#endif                                 /* RTW_HEADER_soh_sf_h_ */
