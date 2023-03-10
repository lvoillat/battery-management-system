/*
 * BTC_sf.c
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

#include <math.h>
#include "BTC_sf.h"
#include "BTC_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *BTC_malloc(SimStruct *S);

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
  /* InitializeConditions for Atomic SubSystem: '<Root>/BTC' */
  /* InitializeConditions for Delay: '<S3>/Delay' */
  ((real_T *)ssGetDWork(S, 0))[0] = 26.0;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  ((real_T *)ssGetDWork(S, 1))[0] = 0.0;

  /* InitializeConditions for Delay: '<S3>/Delay1' */
  ((boolean_T *)ssGetDWork(S, 2))[0] = false;
  ((boolean_T *)ssGetDWork(S, 2))[1] = false;

  /* End of InitializeConditions for SubSystem: '<Root>/BTC' */
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

  BTC_malloc(S);
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
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_DataTypeConversion;
  boolean_T rtb_LogicalOperator4;
  boolean_T rtb_RelationalOperator2;
  real_T rtb_Subtract;
  real_T rtb_Switch2;
  int32_T i;
  B_BTC_T *_rtB;
  _rtB = ((B_BTC_T *) ssGetLocalBlockIO(S));

  /* Outputs for Atomic SubSystem: '<Root>/BTC' */
  /* MinMax: '<S3>/MinMax1' incorporates:
   *  Inport: '<Root>/cell temperature'
   */
  rtb_Switch2 = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0];

  /* MinMax: '<S3>/MinMax2' incorporates:
   *  Inport: '<Root>/cell SOC'
   */
  rtb_Subtract = *((const real_T **)ssGetInputPortSignalPtrs(S, 1))[0];
  for (i = 0; i < 39; i++) {
    /* MinMax: '<S3>/MinMax1' incorporates:
     *  Inport: '<Root>/cell temperature'
     */
    if (!((rtb_Switch2 >= *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[i +
           1]) || rtIsNaN(*((const real_T **)ssGetInputPortSignalPtrs(S, 0))[i +
                          1]))) {
      rtb_Switch2 = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[i + 1];
    }

    /* MinMax: '<S3>/MinMax2' incorporates:
     *  Inport: '<Root>/cell SOC'
     */
    if (!((rtb_Subtract <= *((const real_T **)ssGetInputPortSignalPtrs(S, 1))[i
           + 1]) || rtIsNaN(*((const real_T **)ssGetInputPortSignalPtrs(S, 1))[i
          + 1]))) {
      rtb_Subtract = *((const real_T **)ssGetInputPortSignalPtrs(S, 1))[i + 1];
    }
  }

  /* RelationalOperator: '<S3>/Relational Operator3' incorporates:
   *  Constant: '<S3>/Constant7'
   *  MinMax: '<S3>/MinMax2'
   */
  rtb_DataTypeConversion = (rtb_Subtract >= (*(real_T *)(mxGetData(btcc_full_soc
    (S)))));

  /* Logic: '<S3>/Logical Operator4' incorporates:
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant9'
   *  Inport: '<Root>/ambient temperature'
   *  Inport: '<Root>/charging status'
   *  Logic: '<S3>/Logical Operator2'
   *  MinMax: '<S3>/MinMax1'
   *  RelationalOperator: '<S3>/Relational Operator1'
   *  RelationalOperator: '<S3>/Relational Operator5'
   */
  rtb_LogicalOperator4 = ((rtb_Switch2 >= (*(real_T *)(mxGetData
    (btcc_max_temp_highth(S))))) || (rtb_DataTypeConversion && (*((const
    boolean_T **)ssGetInputPortSignalPtrs(S, 2))[0]) && (*((const real_T **)
    ssGetInputPortSignalPtrs(S, 3))[0] <= (*(real_T *)(mxGetData
    (btcc_ambient_temp_lowth(S)))))));

  /* MinMax: '<S3>/MinMax' incorporates:
   *  Inport: '<Root>/cell temperature'
   */
  rtb_Subtract = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0];
  for (i = 0; i < 39; i++) {
    if (!((rtb_Subtract <= *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[i
           + 1]) || rtIsNaN(*((const real_T **)ssGetInputPortSignalPtrs(S, 0))[i
          + 1]))) {
      rtb_Subtract = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[i + 1];
    }
  }

  /* Logic: '<S3>/Logical Operator3' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant8'
   *  Inport: '<Root>/ambient temperature'
   *  Inport: '<Root>/charging status'
   *  Logic: '<S3>/Logical Operator1'
   *  MinMax: '<S3>/MinMax'
   *  RelationalOperator: '<S3>/Relational Operator'
   *  RelationalOperator: '<S3>/Relational Operator4'
   */
  rtb_DataTypeConversion = ((rtb_Subtract <= (*(real_T *)(mxGetData
    (btcc_min_temp_lowth(S))))) || (rtb_DataTypeConversion && (*((const
    boolean_T **)ssGetInputPortSignalPtrs(S, 2))[0]) && (*((const real_T **)
    ssGetInputPortSignalPtrs(S, 3))[0] >= (*(real_T *)(mxGetData
    (btcc_ambient_temp_highth(S)))))));

  /* RelationalOperator: '<S3>/Relational Operator2' incorporates:
   *  Constant: '<S3>/Constant4'
   *  MinMax: '<S3>/MinMax'
   *  MinMax: '<S3>/MinMax1'
   *  Sum: '<S3>/Add'
   */
  rtb_RelationalOperator2 = (rtb_Switch2 - rtb_Subtract >= (*(real_T *)
    (mxGetData(btcc_cell_temp_diffth(S)))));

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S3>/Constant3'
   *  Switch: '<S3>/Switch'
   *  Switch: '<S3>/Switch2'
   */
  if (rtb_LogicalOperator4) {
    _rtB->Switch1 = (*(real_T *)(mxGetData(btcc_max_temp_lowth(S))));
  } else {
    if (rtb_DataTypeConversion) {
      /* Switch: '<S3>/Switch' incorporates:
       *  Constant: '<S3>/Constant1'
       */
      rtb_Switch2 = (*(real_T *)(mxGetData(btcc_min_temp_highth(S))));
    } else if (rtb_RelationalOperator2) {
      /* Sum: '<S3>/Sum of Elements1' incorporates:
       *  Inport: '<Root>/cell temperature'
       *  Switch: '<S3>/Switch'
       *  Switch: '<S3>/Switch2'
       */
      rtb_Switch2 = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0];
      for (i = 0; i < 39; i++) {
        rtb_Switch2 += *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[i + 1];
      }

      /* End of Sum: '<S3>/Sum of Elements1' */

      /* Switch: '<S3>/Switch2' incorporates:
       *  Constant: '<S3>/Constant5'
       *  Constant: '<S3>/Constant6'
       *  Product: '<S3>/Divide'
       *  Product: '<S3>/Divide1'
       *  Switch: '<S3>/Switch'
       */
      rtb_Switch2 = rtb_Switch2 / (*(real_T *)(mxGetData(btcc_pack_in_parallel(S))))
        / (*(real_T *)(mxGetData(btcc_number_in_series(S))));
    } else {
      /* Switch: '<S3>/Switch2' incorporates:
       *  Delay: '<S3>/Delay'
       *  Switch: '<S3>/Switch'
       */
      rtb_Switch2 = ((real_T *)ssGetDWork(S, 0))[0];
    }

    _rtB->Switch1 = rtb_Switch2;
  }

  /* End of Switch: '<S3>/Switch1' */

  /* MinMax: '<S2>/MinMax' incorporates:
   *  Inport: '<Root>/cell temperature'
   */
  rtb_Switch2 = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0];
  for (i = 0; i < 39; i++) {
    if (!((rtb_Switch2 <= *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[i +
           1]) || rtIsNaN(*((const real_T **)ssGetInputPortSignalPtrs(S, 0))[i +
                          1]))) {
      rtb_Switch2 = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[i + 1];
    }
  }

  /* Switch: '<S2>/Switch1' incorporates:
   *  Constant: '<S2>/Constant9'
   *  MinMax: '<S2>/MinMax'
   *  RelationalOperator: '<S2>/Relational Operator4'
   */
  if (!(rtb_Switch2 <= (*(real_T *)(mxGetData(btcc_min_temp_lowth(S)))))) {
    /* MinMax: '<S2>/MinMax1' incorporates:
     *  Inport: '<Root>/cell temperature'
     */
    rtb_Switch2 = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0];
    for (i = 0; i < 39; i++) {
      if (!((rtb_Switch2 >= *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[i
             + 1]) || rtIsNaN(*((const real_T **)ssGetInputPortSignalPtrs(S, 0))
                              [i + 1]))) {
        rtb_Switch2 = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[i + 1];
      }
    }

    /* End of MinMax: '<S2>/MinMax1' */
  }

  /* End of Switch: '<S2>/Switch1' */

  /* Sum: '<S1>/Subtract' */
  rtb_Subtract = _rtB->Switch1 - rtb_Switch2;

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   *  Inport: '<Root>/cell temp high fault'
   *  Inport: '<Root>/cell temp low fault'
   *  Inport: '<Root>/coolant inlet temp fault'
   *  Inport: '<Root>/coolant outlet temp fault'
   */
  rtb_LogicalOperator = ((*((const boolean_T **)ssGetInputPortSignalPtrs(S, 5))
    [0]) || (*((const boolean_T **)ssGetInputPortSignalPtrs(S, 6))[0]) || (*((
    const uint8_T **)ssGetInputPortSignalPtrs(S, 7))[0] != 0) || (*((const
    uint8_T **)ssGetInputPortSignalPtrs(S, 8))[0] != 0));

  /* Logic: '<S3>/Logical Operator' */
  _rtB->LogicalOperator = (rtb_DataTypeConversion || rtb_RelationalOperator2 ||
    rtb_LogicalOperator4);

  /* Product: '<S4>/mul1' incorporates:
   *  Constant: '<S4>/Constant5'
   *  Gain: '<S4>/BTC_Ki'
   */
  _rtB->mul1 = (*(real_T *)(mxGetData(btcc_Ki(S)))) * rtb_Subtract * (*(real_T *)
    (mxGetData(btck_stepSize(S))));

  /* Switch: '<S1>/Switch1' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Delay: '<S3>/Delay1'
   *  Inport: '<Root>/charging status'
   *  Inport: '<Root>/discharging contactor status'
   *  Logic: '<S1>/Logical Operator1'
   *  Logic: '<S1>/Logical Operator2'
   *  Switch: '<S1>/Switch2'
   */
  if (rtb_LogicalOperator) {
    rtb_Subtract = 50.0;
  } else if (((boolean_T *)ssGetDWork(S, 2))[0] && ((*((const boolean_T **)
                ssGetInputPortSignalPtrs(S, 2))[0]) || (*((const boolean_T **)
                ssGetInputPortSignalPtrs(S, 4))[0]))) {
    /* Sum: '<S4>/Sum' incorporates:
     *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
     *  Gain: '<S4>/BTC_Kp'
     *  Switch: '<S1>/Switch2'
     */
    rtb_Subtract = (*(real_T *)(mxGetData(btcc_Kp(S)))) * rtb_Subtract +
      ((real_T *)ssGetDWork(S, 1))[0];

    /* Saturate: '<S4>/Saturation' incorporates:
     *  Switch: '<S1>/Switch2'
     */
    if (rtb_Subtract > 100.0) {
      rtb_Subtract = 100.0;
    } else {
      if (rtb_Subtract < -100.0) {
        rtb_Subtract = -100.0;
      }
    }

    /* Switch: '<S1>/Switch2' incorporates:
     *  Abs: '<S1>/Abs'
     *  Saturate: '<S4>/Saturation'
     */
    rtb_Subtract = fabs(rtb_Subtract);
  } else {
    /* Switch: '<S1>/Switch2' incorporates:
     *  Constant: '<S1>/Constant'
     */
    rtb_Subtract = 0.0;
  }

  /* End of Switch: '<S1>/Switch1' */
  /* End of Outputs for SubSystem: '<Root>/BTC' */

  /* Outport: '<Root>/coolant_flow_percentage' */
  ((real_T *)ssGetOutputPortSignal(S, 0))[0] = rtb_Subtract;

  /* Outport: '<Root>/battery_target_temperature' */
  ((real_T *)ssGetOutputPortSignal(S, 1))[0] = _rtB->Switch1;

  /* Outport: '<Root>/battery_actual_temperature' */
  ((real_T *)ssGetOutputPortSignal(S, 2))[0] = rtb_Switch2;

  /* Outputs for Atomic SubSystem: '<Root>/BTC' */
  /* Outport: '<Root>/battery_reqest_status' incorporates:
   *  Delay: '<S3>/Delay1'
   */
  ((boolean_T *)ssGetOutputPortSignal(S, 3))[0] = ((boolean_T *)ssGetDWork(S, 2))
    [0];

  /* End of Outputs for SubSystem: '<Root>/BTC' */

  /* Outport: '<Root>/battery_thermal_condition' */
  ((boolean_T *)ssGetOutputPortSignal(S, 4))[0] = rtb_LogicalOperator;
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  B_BTC_T *_rtB;
  _rtB = ((B_BTC_T *) ssGetLocalBlockIO(S));

  /* Update for Atomic SubSystem: '<Root>/BTC' */
  /* Update for Delay: '<S3>/Delay' */
  ((real_T *)ssGetDWork(S, 0))[0] = _rtB->Switch1;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  ((real_T *)ssGetDWork(S, 1))[0] = ((real_T *)ssGetDWork(S, 1))[0] + _rtB->mul1;

  /* Update for Delay: '<S3>/Delay1' */
  ((boolean_T *)ssGetDWork(S, 2))[0] = ((boolean_T *)ssGetDWork(S, 2))[1];
  ((boolean_T *)ssGetDWork(S, 2))[1] = _rtB->LogicalOperator;

  /* End of Update for SubSystem: '<Root>/BTC' */
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
  /* Parameter check for 'btcc_Ki' */
  if (mxIsComplex(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,"Parameter 'btcc_Ki' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,"Parameter 'btcc_Ki' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 0)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'btcc_Ki' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'btcc_Kp' */
  if (mxIsComplex(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,"Parameter 'btcc_Kp' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,"Parameter 'btcc_Kp' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 1)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'btcc_Kp' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'btcc_ambient_temp_highth' */
  if (mxIsComplex(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_ambient_temp_highth' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_ambient_temp_highth' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 2)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_ambient_temp_highth' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'btcc_ambient_temp_lowth' */
  if (mxIsComplex(ssGetSFcnParam(S, 3))) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_ambient_temp_lowth' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 3))) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_ambient_temp_lowth' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 3)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 3))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 3))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_ambient_temp_lowth' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'btcc_cell_temp_diffth' */
  if (mxIsComplex(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_cell_temp_diffth' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_cell_temp_diffth' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 4)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_cell_temp_diffth' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'btcc_full_soc' */
  if (mxIsComplex(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_full_soc' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,"Parameter 'btcc_full_soc' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 5)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'btcc_full_soc' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'btcc_max_temp_highth' */
  if (mxIsComplex(ssGetSFcnParam(S, 6))) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_max_temp_highth' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 6))) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_max_temp_highth' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 6)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 6))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 6))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_max_temp_highth' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'btcc_max_temp_lowth' */
  if (mxIsComplex(ssGetSFcnParam(S, 7))) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_max_temp_lowth' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 7))) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_max_temp_lowth' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 7)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 7))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 7))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_max_temp_lowth' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'btcc_min_temp_highth' */
  if (mxIsComplex(ssGetSFcnParam(S, 8))) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_min_temp_highth' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 8))) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_min_temp_highth' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 8)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 8))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 8))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_min_temp_highth' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'btcc_min_temp_lowth' */
  if (mxIsComplex(ssGetSFcnParam(S, 9))) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_min_temp_lowth' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 9))) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_min_temp_lowth' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 9)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 9))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 9))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_min_temp_lowth' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'btcc_number_in_series' */
  if (mxIsComplex(ssGetSFcnParam(S, 10))) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_number_in_series' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 10))) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_number_in_series' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 10)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 10))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 10))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_number_in_series' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'btcc_pack_in_parallel' */
  if (mxIsComplex(ssGetSFcnParam(S, 11))) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_pack_in_parallel' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 11))) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_pack_in_parallel' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 11)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 11))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 11))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'btcc_pack_in_parallel' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'btck_stepSize' */
  if (mxIsComplex(ssGetSFcnParam(S, 12))) {
    ssSetErrorStatus(S,
                     "Parameter 'btck_stepSize' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 12))) {
    ssSetErrorStatus(S,"Parameter 'btck_stepSize' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 12)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 12))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 12))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'btck_stepSize' has to be a [1x1] array.");
    return;
  }
}

#endif                                 /* MDL_CHECK_PARAMETERS */

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "BTC_mid.h"
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
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
  }

  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* outport number: 1 */
  if (!ssSetOutputPortVectorDimension(S, 1, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
  }

  ssSetOutputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

  /* outport number: 2 */
  if (!ssSetOutputPortVectorDimension(S, 2, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 2, SS_DOUBLE);
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
    ssSetOutputPortDataType(S, 4, SS_BOOLEAN);
  }

  ssSetOutputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 9))
    return;

  /* inport number: 0 */
  {
    if (!ssSetInputPortVectorDimension(S, 0, 40))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 0, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 0, 1);
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
      ssSetInputPortDataType(S, 2, SS_BOOLEAN);
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
      ssSetInputPortDataType(S, 4, SS_BOOLEAN);
    }

    ssSetInputPortDirectFeedThrough(S, 4, 1);
    ssSetInputPortOverWritable(S, 4, 0);
    ssSetInputPortOptimOpts(S, 4, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 5 */
  {
    if (!ssSetInputPortVectorDimension(S, 5, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 5, SS_BOOLEAN);
    }

    ssSetInputPortDirectFeedThrough(S, 5, 1);
    ssSetInputPortOverWritable(S, 5, 0);
    ssSetInputPortOptimOpts(S, 5, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 6 */
  {
    if (!ssSetInputPortVectorDimension(S, 6, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 6, SS_BOOLEAN);
    }

    ssSetInputPortDirectFeedThrough(S, 6, 1);
    ssSetInputPortOverWritable(S, 6, 0);
    ssSetInputPortOptimOpts(S, 6, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 7 */
  {
    if (!ssSetInputPortVectorDimension(S, 7, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 7, SS_UINT8);
    }

    ssSetInputPortDirectFeedThrough(S, 7, 1);
    ssSetInputPortOverWritable(S, 7, 0);
    ssSetInputPortOptimOpts(S, 7, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 8 */
  {
    if (!ssSetInputPortVectorDimension(S, 8, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 8, SS_UINT8);
    }

    ssSetInputPortDirectFeedThrough(S, 8, 1);
    ssSetInputPortOverWritable(S, 8, 0);
    ssSetInputPortOptimOpts(S, 8, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 3)) {
    return;
  }

  /* '<S3>/Delay': DSTATE */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 1);
  ssSetDWorkUsedAsDState(S, 0, 1);

  /* '<S4>/Discrete-Time Integrator': DSTATE */
  ssSetDWorkName(S, 1, "DWORK1");
  ssSetDWorkWidth(S, 1, 1);
  ssSetDWorkUsedAsDState(S, 1, 1);

  /* '<S3>/Delay1': DSTATE */
  ssSetDWorkName(S, 2, "DWORK2");
  ssSetDWorkWidth(S, 2, 2);
  ssSetDWorkDataType(S, 2, SS_BOOLEAN);
  ssSetDWorkUsedAsDState(S, 2, 1);

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 13);

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
# define S_FUNCTION_NAME               BTC_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
