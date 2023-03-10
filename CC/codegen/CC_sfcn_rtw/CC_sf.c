/*
 * CC_sf.c
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

#include <math.h>
#include "CC_sf.h"
#include "CC_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *CC_malloc(SimStruct *S);

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

/* Initial conditions for root system: '<Root>' */
#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  /* InitializeConditions for Atomic SubSystem: '<Root>/CC' */
  /* InitializeConditions for Delay: '<S1>/Delay2' */
  ((boolean_T *)ssGetDWork(S, 2))[0] = false;

  /* InitializeConditions for Delay: '<S1>/Resettable Delay' */
  ((uint8_T *)ssGetDWork(S, 5))[0] = 1U;

  /* InitializeConditions for Delay: '<S1>/Delay1' */
  ((boolean_T *)ssGetDWork(S, 3))[0] = false;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  ((boolean_T *)ssGetDWork(S, 4))[0] = false;

  /* End of InitializeConditions for SubSystem: '<Root>/CC' */
}

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

  CC_malloc(S);
  if (ssGetErrorStatus(S) != (NULL) ) {
    return;
  }

#endif

  {
    B_CC_T *_rtB;
    _rtB = ((B_CC_T *) ssGetLocalBlockIO(S));

    /* Previous zero-crossing state intialization */
    {
      PrevZCX_CC_T *_rtZCE;
      _rtZCE = ((PrevZCX_CC_T *) _ssGetPrevZCSigState(S));
      _rtZCE->ResettableDelay_Reset_ZCE = UNINITIALIZED_ZCSIG;
    }
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  boolean_T rtb_RelationalOperator5;
  int32_T tmp;
  B_CC_T *_rtB;
  PrevZCX_CC_T *_rtZCE;
  _rtZCE = ((PrevZCX_CC_T *) _ssGetPrevZCSigState(S));
  _rtB = ((B_CC_T *) ssGetLocalBlockIO(S));

  /* Outputs for Atomic SubSystem: '<Root>/CC' */
  /* RelationalOperator: '<S1>/Relational Operator5' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/Battery Voltage'
   *  Inport: '<Root>/Vehicle Load Voltage'
   *  Sum: '<S1>/Subtract'
   */
  rtb_RelationalOperator5 = (*((const real_T **)ssGetInputPortSignalPtrs(S, 3))
    [0] >= *((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0] - 2.0);

  /* Delay: '<S1>/Resettable Delay' incorporates:
   *  Constant: '<S1>/Constant10'
   *  Inport: '<Root>/Precharge Fault Counter Reset'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,&_rtZCE->ResettableDelay_Reset_ZCE,
               (*((const real_T **)ssGetInputPortSignalPtrs(S, 4))[0])) !=
      NO_ZCEVENT) {
    ((uint8_T *)ssGetDWork(S, 5))[0] = 1U;
  }

  if (((uint8_T *)ssGetDWork(S, 5))[0] != 0) {
    ((real_T *)ssGetDWork(S, 0))[0] = 0.0;
  }

  /* Switch: '<S1>/Switch1' incorporates:
   *  Constant: '<S1>/Constant6'
   *  Delay: '<S1>/Delay2'
   *  Logic: '<S1>/Logical Operator9'
   */
  if (((boolean_T *)ssGetDWork(S, 2))[0]) {
    tmp = !rtb_RelationalOperator5;
  } else {
    tmp = 0;
  }

  /* End of Switch: '<S1>/Switch1' */

  /* Sum: '<S1>/Add' incorporates:
   *  Delay: '<S1>/Resettable Delay'
   */
  _rtB->Add = (uint16_T)((uint32_T)tmp + (uint16_T)((real_T *)ssGetDWork(S, 0))
    [0]);

  /* Logic: '<S1>/Logical Operator2' incorporates:
   *  Inport: '<Root>/Charger Contactor Control Command'
   *  Inport: '<Root>/Main Contactor Control Command'
   *  Logic: '<S1>/Logical Operator3'
   *  Logic: '<S1>/Logical Operator6'
   */
  _rtB->LogicalOperator2 = (((*((const boolean_T **)ssGetInputPortSignalPtrs(S,
    0))[0]) || (*((const boolean_T **)ssGetInputPortSignalPtrs(S, 1))[0])) &&
    (!rtb_RelationalOperator5));

  /* RelationalOperator: '<S1>/Relational Operator4' incorporates:
   *  Constant: '<S1>/Constant8'
   */
  _rtB->RelationalOperator4 = (_rtB->Add >= 1.0 / (*(real_T *)(mxGetData
    (CCOk_stepSize(S)))));

  /* Outport: '<Root>/Contactor Negative Side Relay ' incorporates:
   *  Delay: '<S1>/Delay1'
   *  Inport: '<Root>/Charger Contactor Control Command'
   *  Inport: '<Root>/Main Contactor Control Command'
   *  Logic: '<S1>/Logical O perator7'
   *  Logic: '<S1>/Logical Operator'
   *  Logic: '<S1>/Logical Operator8'
   */
  ((boolean_T *)ssGetOutputPortSignal(S, 0))[0] = (((*((const boolean_T **)
    ssGetInputPortSignalPtrs(S, 0))[0]) || (*((const boolean_T **)
    ssGetInputPortSignalPtrs(S, 1))[0])) && (!((boolean_T *)ssGetDWork(S, 3))[0]));

  /* Outport: '<Root>/Main Contactor Relay Control ' incorporates:
   *  Inport: '<Root>/Main Contactor Control Command'
   *  Logic: '<S1>/Logical Operator1'
   */
  ((boolean_T *)ssGetOutputPortSignal(S, 1))[0] = ((*((const boolean_T **)
    ssGetInputPortSignalPtrs(S, 0))[0]) && rtb_RelationalOperator5);

  /* Outport: '<Root>/Charger Contactor Relay Control' incorporates:
   *  Inport: '<Root>/Charger Contactor Control Command'
   *  Logic: '<S1>/Logical Operator5'
   */
  ((boolean_T *)ssGetOutputPortSignal(S, 2))[0] = ((*((const boolean_T **)
    ssGetInputPortSignalPtrs(S, 1))[0]) && rtb_RelationalOperator5);

  /* Outport: '<Root>/Precharger Contactor Relay Control ' incorporates:
   *  Delay: '<S1>/Delay'
   */
  ((boolean_T *)ssGetOutputPortSignal(S, 3))[0] = ((boolean_T *)ssGetDWork(S, 4))
    [0];

  /* Outport: '<Root>/precharge_fault' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  Delay: '<S1>/Delay1'
   */
  ((uint8_T *)ssGetOutputPortSignal(S, 4))[0] = ((boolean_T *)ssGetDWork(S, 3))
    [0];

  /* End of Outputs for SubSystem: '<Root>/CC' */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  B_CC_T *_rtB;
  _rtB = ((B_CC_T *) ssGetLocalBlockIO(S));

  /* Update for Atomic SubSystem: '<Root>/CC' */
  /* Update for Delay: '<S1>/Delay2' */
  ((boolean_T *)ssGetDWork(S, 2))[0] = _rtB->LogicalOperator2;

  /* Update for Delay: '<S1>/Resettable Delay' */
  ((uint8_T *)ssGetDWork(S, 5))[0] = 0U;
  ((real_T *)ssGetDWork(S, 0))[0] = _rtB->Add;

  /* Update for Delay: '<S1>/Delay1' */
  ((boolean_T *)ssGetDWork(S, 3))[0] = _rtB->RelationalOperator4;

  /* Update for Delay: '<S1>/Delay' */
  ((boolean_T *)ssGetDWork(S, 4))[0] = _rtB->LogicalOperator2;

  /* End of Update for SubSystem: '<Root>/CC' */
  UNUSED_PARAMETER(tid);
}

/* Termination for root system: '<Root>' */
static void mdlTerminate(SimStruct *S)
{

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

  if (ssGetUserData(S) != (NULL) ) {
    rt_FREE(ssGetLocalBlockIO(S));
    rt_FREE(_ssGetPrevZCSigState(S));
  }

  rt_FREE(ssGetUserData(S));

#endif

}

/* This function checks the attributes of tunable parameters. */
#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)

static void mdlCheckParameters(SimStruct *S)
{
  /* Parameter check for 'CCOk_stepSize' */
  if (mxIsComplex(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,
                     "Parameter 'CCOk_stepSize' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,"Parameter 'CCOk_stepSize' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 0)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'CCOk_stepSize' has to be a [1x1] array.");
    return;
  }
}

#endif                                 /* MDL_CHECK_PARAMETERS */

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "CC_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 1);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 5))
    return;

  /* outport number: 0 */
  if (!ssSetOutputPortVectorDimension(S, 0, 1))
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

  /* outport number: 2 */
  if (!ssSetOutputPortVectorDimension(S, 2, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 2, SS_BOOLEAN);
  }

  ssSetOutputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);

  /* outport number: 3 */
  if (!ssSetOutputPortVectorDimension(S, 3, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 3, SS_BOOLEAN);
  }

  ssSetOutputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);

  /* outport number: 4 */
  if (!ssSetOutputPortVectorDimension(S, 4, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 4, SS_UINT8);
  }

  ssSetOutputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 5))
    return;

  /* inport number: 0 */
  {
    if (!ssSetInputPortVectorDimension(S, 0, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 0, SS_BOOLEAN);
    }

    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortOverWritable(S, 0, 0);
    ssSetInputPortOptimOpts(S, 0, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 1 */
  {
    if (!ssSetInputPortVectorDimension(S, 1, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 1, SS_BOOLEAN);
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
      ssSetInputPortDataType(S, 2, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 2, 1);
    ssSetInputPortOverWritable(S, 2, 0);
    ssSetInputPortOptimOpts(S, 2, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 3 */
  {
    if (!ssSetInputPortVectorDimension(S, 3, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 3, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 3, 1);
    ssSetInputPortOverWritable(S, 3, 0);
    ssSetInputPortOptimOpts(S, 3, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 4 */
  {
    if (!ssSetInputPortVectorDimension(S, 4, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 4, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 4, 1);
    ssSetInputPortOverWritable(S, 4, 0);
    ssSetInputPortOptimOpts(S, 4, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 6)) {
    return;
  }

  /* '<S1>/Resettable Delay': DSTATE */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 1);
  ssSetDWorkUsedAsDState(S, 0, 1);

  /* '<S1>/Scope3': PWORK */
  ssSetDWorkName(S, 1, "DWORK1");
  ssSetDWorkWidth(S, 1, 1);
  ssSetDWorkDataType(S, 1, SS_POINTER);

  /* '<S1>/Delay2': DSTATE */
  ssSetDWorkName(S, 2, "DWORK2");
  ssSetDWorkWidth(S, 2, 1);
  ssSetDWorkDataType(S, 2, SS_BOOLEAN);
  ssSetDWorkUsedAsDState(S, 2, 1);

  /* '<S1>/Delay1': DSTATE */
  ssSetDWorkName(S, 3, "DWORK3");
  ssSetDWorkWidth(S, 3, 1);
  ssSetDWorkDataType(S, 3, SS_BOOLEAN);
  ssSetDWorkUsedAsDState(S, 3, 1);

  /* '<S1>/Delay': DSTATE */
  ssSetDWorkName(S, 4, "DWORK4");
  ssSetDWorkWidth(S, 4, 1);
  ssSetDWorkDataType(S, 4, SS_BOOLEAN);
  ssSetDWorkUsedAsDState(S, 4, 1);

  /* '<S1>/Resettable Delay': icLoad */
  ssSetDWorkName(S, 5, "DWORK5");
  ssSetDWorkWidth(S, 5, 1);
  ssSetDWorkDataType(S, 5, SS_UINT8);

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 1);

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
    ssSupportsMultipleExecInstances(S, false);
    ssRegisterMsgForNotSupportingMultiExecInst(S,
      "<diag_root><diag id=\"Simulink:blocks:BlockDoesNotSupportMultiExecInstances\"><arguments><arg type=\"encoded\">QwBDAC8AQwBDAC8AUwBjAG8AcABlADMAAAA=</arg><arg type=\"encoded\">PABfAF8AaQBpAFMAUwBfAF8APgA8AC8AXwBfAGkAaQBTAFMAXwBfAD4AAAA=</arg><arg type=\"encoded\">PABfAF8AaQB0AGUAcgBCAGwAawBfAF8APgA8AC8AXwBfAGkAdABlAHIAQgBsAGsAXwBfAD4AAAA=</arg></arguments></diag>\n</diag_root>");
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
# define S_FUNCTION_NAME               CC_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
