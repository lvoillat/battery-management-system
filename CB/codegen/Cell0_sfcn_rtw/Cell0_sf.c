/*
 * Cell0_sf.c
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

#include <math.h>
#include "Cell0_sf.h"
#include "Cell0_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *Cell0_malloc(SimStruct *S);

#endif

#ifndef __RTW_UTFREE__
#if defined (MATLAB_MEX_FILE)

extern void * utMalloc(size_t);
extern void utFree(void *);

#endif
#endif                                 /* #ifndef __RTW_UTFREE__ */

#if defined(MATLAB_MEX_FILE)
#include "rt_nonfinite.c"
#endif

static const char_T *RT_MEMORY_ALLOCATION_ERROR =
  "memory allocation error in generated S-Function";

/* Start for root system: '<Root>' */
#define MDL_START

static void mdlStart(SimStruct *S)
{
  /* instance underlying S-Function data */
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  if defined(MATLAB_MEX_FILE)

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

#  endif

  Cell0_malloc(S);
  if (ssGetErrorStatus(S) != (NULL) ) {
    return;
  }

#endif

  {
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  real_T minV;
  boolean_T rtb_LogicalOperator[40];
  boolean_T rtb_LogicalOperator2;
  uint32_T tmp;
  int32_T i;

  /* Outputs for Atomic SubSystem: '<Root>/Cell Balancing' */
  /* MinMax: '<S1>/MinMax1' incorporates:
   *  Inport: '<Root>/cell_soc'
   */
  minV = *((const real_T **)ssGetInputPortSignalPtrs(S, 1))[0];
  for (i = 0; i < 39; i++) {
    if (!((minV <= *((const real_T **)ssGetInputPortSignalPtrs(S, 1))[i + 1]) ||
          rtIsNaN(*((const real_T **)ssGetInputPortSignalPtrs(S, 1))[i + 1]))) {
      minV = *((const real_T **)ssGetInputPortSignalPtrs(S, 1))[i + 1];
    }
  }

  /* Logic: '<S1>/LogicalOperator2' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant6'
   *  Inport: '<Root>/battery_mode'
   *  MinMax: '<S1>/MinMax1'
   *  RelationalOperator: '<S1>/RelationalOperator2'
   *  RelationalOperator: '<S1>/RelationalOperator4'
   */
  rtb_LogicalOperator2 = ((*((const uint8_T **)ssGetInputPortSignalPtrs(S, 2))[0]
    == (*(real_T *)(mxGetData(cblc_battChargingMode(S))))) && (minV >= (*(real_T
    *)(mxGetData(cblc_socThreshBalance(S))))));

  /* Logic: '<S1>/LogicalOperator' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Inport: '<Root>/cell_soc'
   *  MinMax: '<S1>/MinMax1'
   *  RelationalOperator: '<S1>/RelationalOperator1'
   *  Sum: '<S1>/Subtract1'
   */
  for (i = 0; i < 40; i++) {
    rtb_LogicalOperator[i] = ((*((const real_T **)ssGetInputPortSignalPtrs(S, 1))
      [i] - minV >= (*(real_T *)(mxGetData(cblc_deltaSocThreshBalance(S))))) &&
      rtb_LogicalOperator2);
  }

  /* End of Logic: '<S1>/LogicalOperator' */

  /* Sum: '<S1>/Sum of Elements' */
  tmp = rtb_LogicalOperator[0];
  for (i = 0; i < 39; i++) {
    tmp += rtb_LogicalOperator[i + 1];
  }

  /* End of Outputs for SubSystem: '<Root>/Cell Balancing' */

  /* Outport: '<Root>/cell_balancing_command' */
  for (i = 0; i < 40; i++) {
    ((boolean_T *)ssGetOutputPortSignal(S, 0))[i] = rtb_LogicalOperator[i];
  }

  /* End of Outport: '<Root>/cell_balancing_command' */

  /* Outputs for Atomic SubSystem: '<Root>/Cell Balancing' */
  /* Outport: '<Root>/cell_balancing_status' incorporates:
   *  Constant: '<S1>/Constant3'
   *  RelationalOperator: '<S1>/RelationalOperator3'
   *  Sum: '<S1>/Sum of Elements'
   */
  ((boolean_T *)ssGetOutputPortSignal(S, 1))[0] = ((uint8_T)tmp >= 0.5);

  /* End of Outputs for SubSystem: '<Root>/Cell Balancing' */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  UNUSED_PARAMETER(tid);
}

/* Termination for root system: '<Root>' */
static void mdlTerminate(SimStruct *S)
{

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

  if (ssGetUserData(S) != (NULL) ) {
    rt_FREE(ssGetLocalBlockIO(S));
  }

  rt_FREE(ssGetUserData(S));

#endif

}

/* This function checks the attributes of tunable parameters. */
#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)

static void mdlCheckParameters(SimStruct *S)
{
  /* Parameter check for 'cblc_battChargingMode' */
  if (mxIsComplex(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,
                     "Parameter 'cblc_battChargingMode' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,
                     "Parameter 'cblc_battChargingMode' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 0)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'cblc_battChargingMode' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'cblc_deltaSocThreshBalance' */
  if (mxIsComplex(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,
                     "Parameter 'cblc_deltaSocThreshBalance' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,
                     "Parameter 'cblc_deltaSocThreshBalance' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 1)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'cblc_deltaSocThreshBalance' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'cblc_socThreshBalance' */
  if (mxIsComplex(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,
                     "Parameter 'cblc_socThreshBalance' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,
                     "Parameter 'cblc_socThreshBalance' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 2)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'cblc_socThreshBalance' has to be a [1x1] array.");
    return;
  }
}

#endif                                 /* MDL_CHECK_PARAMETERS */

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "Cell0_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 1);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 2))
    return;

  /* outport number: 0 */
  if (!ssSetOutputPortVectorDimension(S, 0, 40))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 0, SS_BOOLEAN);
  }

  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* outport number: 1 */
  if (!ssSetOutputPortVectorDimension(S, 1, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 1, SS_BOOLEAN);
  }

  ssSetOutputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 3))
    return;

  /* inport number: 0 */
  {
    if (!ssSetInputPortVectorDimension(S, 0, 40))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 0, SS_DOUBLE);
    }

    ssSetInputPortOverWritable(S, 0, 0);
    ssSetInputPortOptimOpts(S, 0, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 1 */
  {
    if (!ssSetInputPortVectorDimension(S, 1, 40))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 1, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortOverWritable(S, 1, 0);
    ssSetInputPortOptimOpts(S, 1, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 2 */
  {
    if (!ssSetInputPortVectorDimension(S, 2, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 2, SS_UINT8);
    }

    ssSetInputPortDirectFeedThrough(S, 2, 1);
    ssSetInputPortOverWritable(S, 2, 0);
    ssSetInputPortOptimOpts(S, 2, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 0)) {
    return;
  }

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 3);

  /* Number of expected parameters */
#if defined(MATLAB_MEX_FILE)

  if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {

#if defined(MDL_CHECK_PARAMETERS)

    mdlCheckParameters(S);

#endif                                 /* MDL_CHECK_PARAMETERS */

    if (ssGetErrorStatus(S) != (NULL) ) {
      return;
    }
  } else {
    return;                            /* Parameter mismatch will be reported by Simulink */
  }

#endif                                 /* MATLAB_MEX_FILE */

  /* Options */
  ssSetOptions(S, (SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE |
                   SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME ));

#if SS_SFCN_FOR_SIM

  {
    ssSupportsMultipleExecInstances(S, true);
    ssHasStateInsideForEachSS(S, false);
    ssSetModelReferenceSampleTimeInheritanceRule(S,
      USE_DEFAULT_FOR_DISCRETE_INHERITANCE);
  }

#endif

}

/* Function to initialize sample times. */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
  ssSetOffsetTime(S, 0, 0.0);
}

#if defined(MATLAB_MEX_FILE)
# include "fixedpoint.c"
# include "simulink.c"
#else
# undef S_FUNCTION_NAME
# define S_FUNCTION_NAME               Cell0_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
