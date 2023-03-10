/*
 * SOP_sf.c
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

#include <math.h>
#include "SOP_sf.h"
#include "SOP_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *SOP_malloc(SimStruct *S);

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
real_T SOP_look2_binlx(real_T u0, real_T u1, const real_T bp0[], const real_T
  bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride)
{
  real_T frac;
  uint32_T bpIndices[2];
  real_T fractions[2];
  real_T yL_1d;
  uint32_T iRght;
  uint32_T bpIdx;
  uint32_T iLeft;

  /* Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U]
      - 1U]);
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = (u1 - bp1[0U]) / (bp1[1U] - bp1[0U]);
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U]
      - 1U]);
  }

  /* Interpolation 2-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_1d = (table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx];
  bpIdx += stride;
  return (((table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx]) -
          yL_1d) * frac + yL_1d;
}

real_T SOP_look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
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

  SOP_malloc(S);
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
  int32_T iU;
  real_T rtb_Product1;
  boolean_T rtb_LogicalOperator;
  real_T rtb_SOCversusOCVtable[40];
  real_T rtb_Divide10[40];
  real_T rtb_Product;
  real_T rtb_Divide10_j;

  /* Outputs for Atomic SubSystem: '<Root>/SOP' */
  for (iU = 0; iU < 40; iU++) {
    /* Lookup_n-D: '<S1>/dischg_internal_resistance_table' incorporates:
     *  Inport: '<Root>/cell_SOC'
     *  Inport: '<Root>/cell_temp'
     */
    rtb_Product1 = SOP_look2_binlx(*((const real_T **)ssGetInputPortSignalPtrs(S,
      0))[iU], *((const real_T **)ssGetInputPortSignalPtrs(S, 1))[iU], ((real_T *)
      mxGetData(bmsc_InternalDischgResistX(S))), ((real_T *)mxGetData
      (bmsc_InternalDischgResistY(S))), ((real_T *)mxGetData
      (bmsc_InternalDischgResistZ(S))), SOP_ConstP.pooled3, 3U);

    /* Product: '<S1>/Divide10' incorporates:
     *  Inport: '<Root>/Internal_Resis_Scaling_Factor'
     */
    rtb_Divide10_j = rtb_Product1 / *((const real_T **)ssGetInputPortSignalPtrs
      (S, 8))[iU];

    /* Lookup_n-D: '<S1>/SOC versus OCV table' incorporates:
     *  Inport: '<Root>/cell_SOC'
     */
    rtb_Product1 = SOP_look1_binlx(*((const real_T **)ssGetInputPortSignalPtrs(S,
      1))[iU], ((real_T *)mxGetData(sopc_SOCVsOCVX(S))), ((real_T *)mxGetData
      (sopc_SOCVsOCVY(S))), 100U);

    /* Product: '<S1>/Divide4' incorporates:
     *  Constant: '<S1>/Constant4'
     *  Sum: '<S1>/Sum'
     */
    rtb_Divide10_j = 1.0 / rtb_Divide10_j * (rtb_Product1 - (*(real_T *)
      (mxGetData(bmsc_CellMinVolt(S)))));

    /* Lookup_n-D: '<S1>/dischg_internal_resistance_table' */
    rtb_SOCversusOCVtable[iU] = rtb_Product1;

    /* Product: '<S1>/Divide10' */
    rtb_Divide10[iU] = rtb_Divide10_j;
  }

  /* MinMax: '<S1>/MinMax' */
  rtb_Product1 = rtb_Divide10[0];
  for (iU = 0; iU < 39; iU++) {
    if (!((rtb_Product1 <= rtb_Divide10[iU + 1]) || rtIsNaN(rtb_Divide10[iU + 1])))
    {
      rtb_Product1 = rtb_Divide10[iU + 1];
    }
  }

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   *  Inport: '<Root>/cellTmepHighFault'
   *  Inport: '<Root>/low_fault'
   *  Inport: '<Root>/pack_current_fault'
   *  Inport: '<Root>/pack_voltage_fault'
   */
  rtb_LogicalOperator = ((*((const uint8_T **)ssGetInputPortSignalPtrs(S, 4))[0]
    != 0) || (*((const uint8_T **)ssGetInputPortSignalPtrs(S, 5))[0] != 0) ||
    (*((const uint8_T **)ssGetInputPortSignalPtrs(S, 6))[0] != 0) || (*((const
    uint8_T **)ssGetInputPortSignalPtrs(S, 7))[0] != 0));

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant12'
   *  Constant: '<S1>/Constant13'
   *  Inport: '<Root>/discharging_status'
   *  Logic: '<S1>/Logical Operator1'
   */
  if ((*((const boolean_T **)ssGetInputPortSignalPtrs(S, 3))[0]) &&
      rtb_LogicalOperator) {
    rtb_Divide10_j = (*(real_T *)(mxGetData(sopc_DischgFaultDerate(S))));
  } else {
    rtb_Divide10_j = 1.0;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Product: '<S1>/Product1' incorporates:
   *  Constant: '<S1>/Constant5'
   *  Constant: '<S1>/Constant6'
   *  Constant: '<S1>/Constant7'
   *  Gain: '<S1>/Gain'
   *  MinMax: '<S1>/MinMax'
   *  Product: '<S1>/Divide5'
   *  Product: '<S1>/Divide6'
   */
  rtb_Product1 = rtb_Product1 * (*(real_T *)(mxGetData(bmsc_CellMinVolt(S)))) *
    (*(real_T *)(mxGetData(bmsc_NumberInSeries(S)))) * (*(real_T *)(mxGetData
    (bmsc_NumberInPara(S)))) * (*(real_T *)(mxGetData(sopc_DischargeDerate(S))))
    * rtb_Divide10_j;
  for (iU = 0; iU < 40; iU++) {
    /* Lookup_n-D: '<S1>/chg_internal_resistance_table' incorporates:
     *  Inport: '<Root>/cell_SOC'
     *  Inport: '<Root>/cell_temp'
     */
    rtb_Divide10_j = SOP_look2_binlx(*((const real_T **)ssGetInputPortSignalPtrs
      (S, 0))[iU], *((const real_T **)ssGetInputPortSignalPtrs(S, 1))[iU],
      ((real_T *)mxGetData(bmsc_InternalChgResistX(S))), ((real_T *)mxGetData
      (bmsc_InternalChgResistY(S))), ((real_T *)mxGetData
      (bmsc_InternalChgResistZ(S))), SOP_ConstP.pooled3, 3U);

    /* Product: '<S1>/Divide7' incorporates:
     *  Constant: '<S1>/Constant8'
     *  Inport: '<Root>/Internal_Resis_Scaling_Factor'
     *  Product: '<S1>/Divide11'
     *  Sum: '<S1>/Sum1'
     */
    rtb_Divide10_j = (rtb_SOCversusOCVtable[iU] - (*(real_T *)(mxGetData
      (bmsc_CellMaxVolt(S))))) / (rtb_Divide10_j / *((const real_T **)
      ssGetInputPortSignalPtrs(S, 8))[iU]);

    /* Lookup_n-D: '<S1>/chg_internal_resistance_table' */
    rtb_Divide10[iU] = rtb_Divide10_j;
  }

  /* MinMax: '<S1>/MinMax1' */
  rtb_Product = rtb_Divide10[0];
  for (iU = 0; iU < 39; iU++) {
    if (!((rtb_Product >= rtb_Divide10[iU + 1]) || rtIsNaN(rtb_Divide10[iU + 1])))
    {
      rtb_Product = rtb_Divide10[iU + 1];
    }
  }

  /* Switch: '<S1>/Switch1' incorporates:
   *  Constant: '<S1>/Constant14'
   *  Constant: '<S1>/Constant15'
   *  Inport: '<Root>/charging_status'
   *  Logic: '<S1>/Logical Operator2'
   */
  if ((*((const boolean_T **)ssGetInputPortSignalPtrs(S, 2))[0]) &&
      rtb_LogicalOperator) {
    rtb_Divide10_j = (*(real_T *)(mxGetData(sopc_ChgFaultDerate(S))));
  } else {
    rtb_Divide10_j = 1.0;
  }

  /* End of Switch: '<S1>/Switch1' */

  /* Product: '<S1>/Product' incorporates:
   *  Constant: '<S1>/Constant10'
   *  Constant: '<S1>/Constant11'
   *  Constant: '<S1>/Constant9'
   *  Gain: '<S1>/Gain1'
   *  MinMax: '<S1>/MinMax1'
   *  Product: '<S1>/Divide8'
   *  Product: '<S1>/Divide9'
   */
  rtb_Product = rtb_Product * (*(real_T *)(mxGetData(bmsc_CellMaxVolt(S)))) *
    (*(real_T *)(mxGetData(bmsc_NumberInSeries(S)))) * (*(real_T *)(mxGetData
    (bmsc_NumberInPara(S)))) * (*(real_T *)(mxGetData(sopc_ChargeDerate(S)))) *
    rtb_Divide10_j;

  /* End of Outputs for SubSystem: '<Root>/SOP' */

  /* Outport: '<Root>/discharge_power_limit' */
  ((real_T *)ssGetOutputPortSignal(S, 0))[0] = rtb_Product1;

  /* Outputs for Atomic SubSystem: '<Root>/SOP' */
  /* Outport: '<Root>/discharge_current_limit' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Product: '<S1>/Divide'
   *  Product: '<S1>/Divide1'
   */
  ((real_T *)ssGetOutputPortSignal(S, 1))[0] = rtb_Product1 / ((*(real_T *)
    (mxGetData(bmsc_NumberInSeries(S)))) * (*(real_T *)(mxGetData
    (bmsc_NumberInPara(S))))) / (*(real_T *)(mxGetData(bmsc_CellMinVolt(S))));

  /* Outport: '<Root>/charge_power_limit' incorporates:
   *  Gain: '<S1>/Gain3'
   */
  ((real_T *)ssGetOutputPortSignal(S, 2))[0] = -rtb_Product;

  /* Outport: '<Root>/charge_current_limit' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   *  Gain: '<S1>/Gain2'
   *  Product: '<S1>/Divide2'
   *  Product: '<S1>/Divide3'
   */
  ((real_T *)ssGetOutputPortSignal(S, 3))[0] = -(rtb_Product / ((*(real_T *)
    (mxGetData(bmsc_NumberInSeries(S)))) * (*(real_T *)(mxGetData
    (bmsc_NumberInPara(S))))) / (*(real_T *)(mxGetData(bmsc_CellMaxVolt(S)))));

  /* End of Outputs for SubSystem: '<Root>/SOP' */
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
  /* Parameter check for 'bmsc_CellMaxVolt' */
  if (mxIsComplex(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_CellMaxVolt' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,"Parameter 'bmsc_CellMaxVolt' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 0)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'bmsc_CellMaxVolt' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'bmsc_CellMinVolt' */
  if (mxIsComplex(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_CellMinVolt' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,"Parameter 'bmsc_CellMinVolt' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 1)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'bmsc_CellMinVolt' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'bmsc_InternalChgResistX' */
  if (mxIsComplex(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalChgResistX' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalChgResistX' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 2)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[1] != 3) ) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalChgResistX' has to be a [1x3] array.");
    return;
  }

  /* Parameter check for 'bmsc_InternalChgResistY' */
  if (mxIsComplex(ssGetSFcnParam(S, 3))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalChgResistY' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 3))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalChgResistY' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 3)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 3))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 3))[1] != 101) ) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalChgResistY' has to be a [1x101] array.");
    return;
  }

  /* Parameter check for 'bmsc_InternalChgResistZ' */
  if (mxIsComplex(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalChgResistZ' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalChgResistZ' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 4)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[0] != 3) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[1] != 101) ) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalChgResistZ' has to be a [3x101] array.");
    return;
  }

  /* Parameter check for 'bmsc_InternalDischgResistX' */
  if (mxIsComplex(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalDischgResistX' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalDischgResistX' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 5)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[1] != 3) ) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalDischgResistX' has to be a [1x3] array.");
    return;
  }

  /* Parameter check for 'bmsc_InternalDischgResistY' */
  if (mxIsComplex(ssGetSFcnParam(S, 6))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalDischgResistY' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 6))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalDischgResistY' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 6)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 6))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 6))[1] != 101) ) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalDischgResistY' has to be a [1x101] array.");
    return;
  }

  /* Parameter check for 'bmsc_InternalDischgResistZ' */
  if (mxIsComplex(ssGetSFcnParam(S, 7))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalDischgResistZ' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 7))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalDischgResistZ' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 7)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 7))[0] != 3) ||
      (mxGetDimensions(ssGetSFcnParam(S, 7))[1] != 101) ) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalDischgResistZ' has to be a [3x101] array.");
    return;
  }

  /* Parameter check for 'bmsc_NumberInPara' */
  if (mxIsComplex(ssGetSFcnParam(S, 8))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_NumberInPara' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 8))) {
    ssSetErrorStatus(S,"Parameter 'bmsc_NumberInPara' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 8)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 8))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 8))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'bmsc_NumberInPara' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'bmsc_NumberInSeries' */
  if (mxIsComplex(ssGetSFcnParam(S, 9))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_NumberInSeries' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 9))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_NumberInSeries' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 9)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 9))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 9))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_NumberInSeries' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'sopc_ChargeDerate' */
  if (mxIsComplex(ssGetSFcnParam(S, 10))) {
    ssSetErrorStatus(S,
                     "Parameter 'sopc_ChargeDerate' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 10))) {
    ssSetErrorStatus(S,"Parameter 'sopc_ChargeDerate' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 10)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 10))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 10))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'sopc_ChargeDerate' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'sopc_ChgFaultDerate' */
  if (mxIsComplex(ssGetSFcnParam(S, 11))) {
    ssSetErrorStatus(S,
                     "Parameter 'sopc_ChgFaultDerate' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 11))) {
    ssSetErrorStatus(S,
                     "Parameter 'sopc_ChgFaultDerate' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 11)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 11))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 11))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'sopc_ChgFaultDerate' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'sopc_DischargeDerate' */
  if (mxIsComplex(ssGetSFcnParam(S, 12))) {
    ssSetErrorStatus(S,
                     "Parameter 'sopc_DischargeDerate' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 12))) {
    ssSetErrorStatus(S,
                     "Parameter 'sopc_DischargeDerate' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 12)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 12))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 12))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'sopc_DischargeDerate' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'sopc_DischgFaultDerate' */
  if (mxIsComplex(ssGetSFcnParam(S, 13))) {
    ssSetErrorStatus(S,
                     "Parameter 'sopc_DischgFaultDerate' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 13))) {
    ssSetErrorStatus(S,
                     "Parameter 'sopc_DischgFaultDerate' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 13)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 13))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 13))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'sopc_DischgFaultDerate' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'sopc_SOCVsOCVX' */
  if (mxIsComplex(ssGetSFcnParam(S, 14))) {
    ssSetErrorStatus(S,
                     "Parameter 'sopc_SOCVsOCVX' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 14))) {
    ssSetErrorStatus(S,"Parameter 'sopc_SOCVsOCVX' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 14)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 14))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 14))[1] != 101) ) {
    ssSetErrorStatus(S,"Parameter 'sopc_SOCVsOCVX' has to be a [1x101] array.");
    return;
  }

  /* Parameter check for 'sopc_SOCVsOCVY' */
  if (mxIsComplex(ssGetSFcnParam(S, 15))) {
    ssSetErrorStatus(S,
                     "Parameter 'sopc_SOCVsOCVY' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 15))) {
    ssSetErrorStatus(S,"Parameter 'sopc_SOCVsOCVY' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 15)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 15))[0] != 101) ||
      (mxGetDimensions(ssGetSFcnParam(S, 15))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'sopc_SOCVsOCVY' has to be a [101x1] array.");
    return;
  }
}

#endif                                 /* MDL_CHECK_PARAMETERS */

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "SOP_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 1);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 4))
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
    ssSetOutputPortDataType(S, 3, SS_DOUBLE);
  }

  ssSetOutputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);

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
      ssSetInputPortDataType(S, 3, SS_BOOLEAN);
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
      ssSetInputPortDataType(S, 4, SS_UINT8);
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
      ssSetInputPortDataType(S, 5, SS_UINT8);
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
      ssSetInputPortDataType(S, 6, SS_UINT8);
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
    if (!ssSetInputPortVectorDimension(S, 8, 40))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 8, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 8, 1);
    ssSetInputPortOverWritable(S, 8, 0);
    ssSetInputPortOptimOpts(S, 8, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 16);

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
  ssSetOptions(S, (SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE ));

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
# define S_FUNCTION_NAME               SOP_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
