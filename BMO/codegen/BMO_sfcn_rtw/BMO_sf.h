/*
 * BMO_sf.h
 *
 * Code generation for model "BMO_sf".
 *
 * Model version              : 1.57
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed May 27 09:55:10 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BMO_sf_h_
#define RTW_HEADER_BMO_sf_h_
#include <string.h>
#include <stddef.h>
#ifndef BMO_sf_COMMON_INCLUDES_
# define BMO_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                BMO_sf
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
#endif                                 /* BMO_sf_COMMON_INCLUDES_ */

#include "BMO_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Block signals (auto storage) */
typedef struct {
  uint8_T battery_mode;                /* '<S1>/Chart' */
} B_BMO_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *bmon_veh_voltage;            /* '<Root>/bmon_veh_voltage' */
  real_T *bmon_pack_voltage;           /* '<Root>/bmon_pack_voltage' */
  real_T *bmon_pack_current;           /* '<Root>/bmon_pack_current' */
  uint8_T *key;                        /* '<Root>/key' */
  uint8_T *charger_button;             /* '<Root>/charger_button' */
  boolean_T *pre_charge_cc;            /* '<Root>/pre_charge_cc' */
  boolean_T *main_chrg_cc;             /* '<Root>/main_chrg_cc' */
  boolean_T *charger_cc;               /* '<Root>/charger_cc' */
  boolean_T *sleep_status;             /* '<Root>/sleep_status' */
} ExternalUPtrs_BMO_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  uint8_T *bat_mode;                   /* '<Root>/bat_mode' */
  boolean_T *charging_status;          /* '<Root>/charging_status' */
  boolean_T *discharging_status;       /* '<Root>/discharging_status' */
} ExtY_BMO_T;

/* Parameters (auto storage) */
struct P_BMO_T_ {
  real_T BMOk_BatteryCurrentThresh;    /* Variable: BMOk_BatteryCurrentThresh
                                        * Referenced by: '<S1>/Chart'
                                        */
  uint8_T BMOk_CcClosing;              /* Variable: BMOk_CcClosing
                                        * Referenced by: '<S1>/Chart'
                                        */
  uint8_T BMOk_CcOpening;              /* Variable: BMOk_CcOpening
                                        * Referenced by: '<S1>/Chart'
                                        */
  uint8_T BMOk_Charging;               /* Variable: BMOk_Charging
                                        * Referenced by:
                                        *   '<S1>/Chart'
                                        *   '<S3>/Constant'
                                        */
  uint8_T BMOk_ChargingSleep;          /* Variable: BMOk_ChargingSleep
                                        * Referenced by: '<S1>/Chart'
                                        */
  uint8_T BMOk_Discharging;            /* Variable: BMOk_Discharging
                                        * Referenced by:
                                        *   '<S1>/Chart'
                                        *   '<S4>/Constant'
                                        */
  uint8_T BMOk_Off;                    /* Variable: BMOk_Off
                                        * Referenced by: '<S1>/Chart'
                                        */
  uint8_T BMOk_On;                     /* Variable: BMOk_On
                                        * Referenced by: '<S1>/Chart'
                                        */
  uint8_T BMOk_PowerClosed;            /* Variable: BMOk_PowerClosed
                                        * Referenced by: '<S1>/Chart'
                                        */
  uint8_T BMOk_PowerOff;               /* Variable: BMOk_PowerOff
                                        * Referenced by: '<S1>/Chart'
                                        */
  uint8_T BMOk_PowerOn;                /* Variable: BMOk_PowerOn
                                        * Referenced by: '<S1>/Chart'
                                        */
};

extern P_BMO_T BMO_DefaultP;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * hilite_system('BMO_codegen/BMO')    - opens subsystem BMO_codegen/BMO
 * hilite_system('BMO_codegen/BMO/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BMO_codegen'
 * '<S1>'   : 'BMO_codegen/BMO'
 * '<S2>'   : 'BMO_codegen/BMO/Chart'
 * '<S3>'   : 'BMO_codegen/BMO/Compare To Constant'
 * '<S4>'   : 'BMO_codegen/BMO/Compare To Constant1'
 */
#endif                                 /* RTW_HEADER_BMO_sf_h_ */
