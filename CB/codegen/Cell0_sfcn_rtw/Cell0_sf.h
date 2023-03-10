/*
 * Cell0_sf.h
 *
 * Code generation for model "Cell0_sf".
 *
 * Model version              : 1.35
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed May 27 11:18:31 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Cell0_sf_h_
#define RTW_HEADER_Cell0_sf_h_
#include <string.h>
#include <stddef.h>
#ifndef Cell0_sf_COMMON_INCLUDES_
# define Cell0_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                Cell0_sf
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
#endif                                 /* Cell0_sf_COMMON_INCLUDES_ */

#include "Cell0_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rtGetInf.h"
#include "rt_defines.h"

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *cell_voltage[40];            /* '<Root>/cell_voltage' */
  real_T *cell_soc[40];                /* '<Root>/cell_soc' */
  uint8_T *battery_mode;               /* '<Root>/battery_mode' */
} ExternalUPtrs_Cell0_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  boolean_T *cell_balancing_command[40];/* '<Root>/cell_balancing_command' */
  boolean_T *cell_balancing_status;    /* '<Root>/cell_balancing_status' */
} ExtY_Cell0_T;

/* Parameters (auto storage) */
struct P_Cell0_T_ {
  real_T cblc_battChargingMode;        /* Variable: cblc_battChargingMode
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T cblc_deltaSocThreshBalance;   /* Variable: cblc_deltaSocThreshBalance
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T cblc_socThreshBalance;        /* Variable: cblc_socThreshBalance
                                        * Referenced by: '<S1>/Constant6'
                                        */
};

extern P_Cell0_T Cell0_DefaultP;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S1>/MinMax' : Unused code path elimination
 * Block '<S1>/RelationalOperator5' : Unused code path elimination
 * Block '<S1>/Subtract' : Unused code path elimination
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
 * hilite_system('CB_codegen/Cell Balancing')    - opens subsystem CB_codegen/Cell Balancing
 * hilite_system('CB_codegen/Cell Balancing/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CB_codegen'
 * '<S1>'   : 'CB_codegen/Cell Balancing'
 */
#endif                                 /* RTW_HEADER_Cell0_sf_h_ */
