/*
 * CC_sf.h
 *
 * Code generation for model "CC_sf".
 *
 * Model version              : 1.109
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Tue May 26 21:06:25 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CC_sf_h_
#define RTW_HEADER_CC_sf_h_
#include <string.h>
#include <stddef.h>
#ifndef CC_sf_COMMON_INCLUDES_
# define CC_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                CC_sf
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
#endif                                 /* CC_sf_COMMON_INCLUDES_ */

#include "CC_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Block signals (auto storage) */
typedef struct {
  real_T Add;                          /* '<S1>/Add' */
  boolean_T LogicalOperator2;          /* '<S1>/Logical Operator2' */
  boolean_T RelationalOperator4;       /* '<S1>/Relational Operator4' */
} B_CC_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState ResettableDelay_Reset_ZCE;/* '<S1>/Resettable Delay' */
} PrevZCX_CC_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  boolean_T *MainContactorControlCommand;/* '<Root>/Main Contactor Control Command' */
  boolean_T *ChargerContactorControlCommand;/* '<Root>/Charger Contactor Control Command' */
  real_T *BatteryVoltage;              /* '<Root>/Battery Voltage' */
  real_T *VehicleLoadVoltage;          /* '<Root>/Vehicle Load Voltage' */
  real_T *PrechargeFaultCounterReset;  /* '<Root>/Precharge Fault Counter Reset' */
} ExternalUPtrs_CC_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  boolean_T *ContactorNegativeSideRelay;/* '<Root>/Contactor Negative Side Relay ' */
  boolean_T *MainContactorRelayControl;/* '<Root>/Main Contactor Relay Control ' */
  boolean_T *ChargerContactorRelayControl;/* '<Root>/Charger Contactor Relay Control' */
  boolean_T *PrechargerContactorRelayControl;/* '<Root>/Precharger Contactor Relay Control ' */
  uint8_T *precharge_fault;            /* '<Root>/precharge_fault' */
} ExtY_CC_T;

/* Parameters (auto storage) */
struct P_CC_T_ {
  real_T CCOk_stepSize;                /* Variable: CCOk_stepSize
                                        * Referenced by: '<S1>/Constant8'
                                        */
};

extern P_CC_T CC_DefaultP;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion5' : Eliminate redundant data type conversion
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
 * hilite_system('CC_codegen/CC')    - opens subsystem CC_codegen/CC
 * hilite_system('CC_codegen/CC/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CC_codegen'
 * '<S1>'   : 'CC_codegen/CC'
 */
#endif                                 /* RTW_HEADER_CC_sf_h_ */
