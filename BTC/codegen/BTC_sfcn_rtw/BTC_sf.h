/*
 * BTC_sf.h
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

#ifndef RTW_HEADER_BTC_sf_h_
#define RTW_HEADER_BTC_sf_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef BTC_sf_COMMON_INCLUDES_
# define BTC_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                BTC_sf
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
#endif                                 /* BTC_sf_COMMON_INCLUDES_ */

#include "BTC_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rtGetInf.h"
#include "rt_defines.h"

/* Block signals (auto storage) */
typedef struct {
  real_T Switch1;                      /* '<S3>/Switch1' */
  real_T mul1;                         /* '<S4>/mul1' */
  boolean_T LogicalOperator;           /* '<S3>/Logical Operator' */
} B_BTC_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *celltemperature[40];         /* '<Root>/cell temperature' */
  real_T *cellSOC[40];                 /* '<Root>/cell SOC' */
  boolean_T *chargingstatus;           /* '<Root>/charging status' */
  real_T *ambienttemperature;          /* '<Root>/ambient temperature' */
  boolean_T *dischargingcontactorstatus;/* '<Root>/discharging contactor status' */
  boolean_T *coolantinlettempfault;    /* '<Root>/coolant inlet temp fault' */
  boolean_T *coolantoutlettempfault;   /* '<Root>/coolant outlet temp fault' */
  uint8_T *celltemphighfault;          /* '<Root>/cell temp high fault' */
  uint8_T *celltemplowfault;           /* '<Root>/cell temp low fault' */
} ExternalUPtrs_BTC_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *coolant_flow_percentage;     /* '<Root>/coolant_flow_percentage' */
  real_T *battery_target_temperature;  /* '<Root>/battery_target_temperature' */
  real_T *battery_actual_temperature;  /* '<Root>/battery_actual_temperature' */
  boolean_T *battery_reqest_status;    /* '<Root>/battery_reqest_status' */
  boolean_T *battery_thermal_condition;/* '<Root>/battery_thermal_condition' */
} ExtY_BTC_T;

/* Parameters (auto storage) */
struct P_BTC_T_ {
  real_T btcc_Ki;                      /* Variable: btcc_Ki
                                        * Referenced by: '<S4>/BTC_Ki'
                                        */
  real_T btcc_Kp;                      /* Variable: btcc_Kp
                                        * Referenced by: '<S4>/BTC_Kp'
                                        */
  real_T btcc_ambient_temp_highth;     /* Variable: btcc_ambient_temp_highth
                                        * Referenced by: '<S3>/Constant8'
                                        */
  real_T btcc_ambient_temp_lowth;      /* Variable: btcc_ambient_temp_lowth
                                        * Referenced by: '<S3>/Constant9'
                                        */
  real_T btcc_cell_temp_diffth;        /* Variable: btcc_cell_temp_diffth
                                        * Referenced by: '<S3>/Constant4'
                                        */
  real_T btcc_full_soc;                /* Variable: btcc_full_soc
                                        * Referenced by: '<S3>/Constant7'
                                        */
  real_T btcc_max_temp_highth;         /* Variable: btcc_max_temp_highth
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T btcc_max_temp_lowth;          /* Variable: btcc_max_temp_lowth
                                        * Referenced by: '<S3>/Constant3'
                                        */
  real_T btcc_min_temp_highth;         /* Variable: btcc_min_temp_highth
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T btcc_min_temp_lowth;          /* Variable: btcc_min_temp_lowth
                                        * Referenced by:
                                        *   '<S2>/Constant9'
                                        *   '<S3>/Constant'
                                        */
  real_T btcc_number_in_series;        /* Variable: btcc_number_in_series
                                        * Referenced by: '<S3>/Constant6'
                                        */
  real_T btcc_pack_in_parallel;        /* Variable: btcc_pack_in_parallel
                                        * Referenced by: '<S3>/Constant5'
                                        */
  real_T btck_stepSize;                /* Variable: btck_stepSize
                                        * Referenced by: '<S4>/Constant5'
                                        */
};

extern P_BTC_T BTC_DefaultP;

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
 * hilite_system('BTC_codegen/BTC')    - opens subsystem BTC_codegen/BTC
 * hilite_system('BTC_codegen/BTC/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BTC_codegen'
 * '<S1>'   : 'BTC_codegen/BTC'
 * '<S2>'   : 'BTC_codegen/BTC/Actual Battery Temperature Calculation'
 * '<S3>'   : 'BTC_codegen/BTC/Battery target temperature determination'
 * '<S4>'   : 'BTC_codegen/BTC/Discrete PI'
 */
#endif                                 /* RTW_HEADER_BTC_sf_h_ */
