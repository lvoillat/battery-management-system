/*
 * VITM_sf.c
 *
 * Code generation for model "VITM_sf".
 *
 * Model version              : 1.125
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed May 27 10:18:24 2020
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
#include "VITM_sf.h"
#include "VITM_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *VITM_malloc(SimStruct *S);

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
  int32_T i;

  /* InitializeConditions for Atomic SubSystem: '<Root>/VITM' */
  /* InitializeConditions for Delay: '<S11>/Delay1' */
  ((real_T *)ssGetDWork(S, 0))[0] = 0.0;

  /* InitializeConditions for Delay: '<S7>/Resettable Delay3' */
  ((real_T *)ssGetDWork(S, 1))[0] = 0.0;

  /* InitializeConditions for Delay: '<S12>/Delay1' */
  ((real_T *)ssGetDWork(S, 2))[0] = 0.0;

  /* InitializeConditions for Delay: '<S8>/Resettable Delay3' */
  ((real_T *)ssGetDWork(S, 3))[0] = 0.0;

  /* InitializeConditions for Delay: '<S5>/Resettable Delay' */
  ((real_T *)ssGetDWork(S, 5))[0] = 0.0;

  /* InitializeConditions for Delay: '<S5>/Resettable Delay1' */
  ((real_T *)ssGetDWork(S, 6))[0] = 0.0;

  /* InitializeConditions for Delay: '<S3>/Delay' */
  ((real_T *)ssGetDWork(S, 8))[0] = 0.0;

  /* InitializeConditions for Delay: '<S6>/Resettable Delay' */
  ((real_T *)ssGetDWork(S, 9))[0] = 0.0;

  /* InitializeConditions for Delay: '<S6>/Resettable Delay1' */
  ((real_T *)ssGetDWork(S, 10))[0] = 0.0;

  /* InitializeConditions for Delay: '<S15>/Delay' */
  ((real_T *)ssGetDWork(S, 11))[0] = 0.0;
  for (i = 0; i < 40; i++) {
    /* InitializeConditions for Delay: '<S10>/Delay1' */
    ((real_T *)ssGetDWork(S, 4))[i] = 0.0;

    /* InitializeConditions for Delay: '<S2>/Delay' */
    ((real_T *)ssGetDWork(S, 7))[i] = 0.0;

    /* InitializeConditions for Delay: '<S15>/Delay1' */
    ((real_T *)ssGetDWork(S, 12))[i] = 0.0;
  }

  /* InitializeConditions for Delay: '<S15>/Resettable Delay2' */
  ((real_T *)ssGetDWork(S, 13))[0] = 0.0;

  /* InitializeConditions for Delay: '<S9>/Delay1' */
  ((real_T *)ssGetDWork(S, 14))[0] = 0.0;

  /* InitializeConditions for Delay: '<S14>/Resettable Delay3' */
  ((real_T *)ssGetDWork(S, 15))[0] = 0.0;

  /* InitializeConditions for Delay: '<S13>/Resettable Delay3' */
  ((real_T *)ssGetDWork(S, 16))[0] = 0.0;

  /* InitializeConditions for Delay: '<S4>/Delay' */
  ((real_T *)ssGetDWork(S, 17))[0] = 0.0;

  /* End of InitializeConditions for SubSystem: '<Root>/VITM' */
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

  VITM_malloc(S);
  if (ssGetErrorStatus(S) != (NULL) ) {
    return;
  }

#endif

  {
    /* Previous zero-crossing state intialization */
    {
      PrevZCX_VITM_T *_rtZCE;
      _rtZCE = ((PrevZCX_VITM_T *) _ssGetPrevZCSigState(S));
      _rtZCE->ResettableDelay3_Reset_ZCE = UNINITIALIZED_ZCSIG;
      _rtZCE->ResettableDelay3_Reset_ZCE_g = UNINITIALIZED_ZCSIG;
      _rtZCE->ResettableDelay_Reset_ZCE = UNINITIALIZED_ZCSIG;
      _rtZCE->ResettableDelay1_Reset_ZCE = UNINITIALIZED_ZCSIG;
      _rtZCE->ResettableDelay_Reset_ZCE_a = UNINITIALIZED_ZCSIG;
      _rtZCE->ResettableDelay1_Reset_ZCE_n = UNINITIALIZED_ZCSIG;
      _rtZCE->ResettableDelay2_Reset_ZCE = UNINITIALIZED_ZCSIG;
      _rtZCE->ResettableDelay3_Reset_ZCE_i = UNINITIALIZED_ZCSIG;
      _rtZCE->ResettableDelay3_Reset_ZCE_f = UNINITIALIZED_ZCSIG;
    }
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  real_T minV;
  real_T maxV;
  real_T minV_0;
  real_T maxV_0;
  real_T rtb_Add1;
  real_T rtb_Add1_p;
  real_T rtb_Add1_h[40];
  real_T rtb_Add;
  real_T rtb_Switch6;
  real_T rtb_Divide;
  real_T rtb_Divide_m;
  int32_T i;
  B_VITM_T *_rtB;
  PrevZCX_VITM_T *_rtZCE;
  _rtZCE = ((PrevZCX_VITM_T *) _ssGetPrevZCSigState(S));
  _rtB = ((B_VITM_T *) ssGetLocalBlockIO(S));

  /* Outputs for Atomic SubSystem: '<Root>/VITM' */
  /* Sum: '<S11>/Add1' incorporates:
   *  Delay: '<S11>/Delay1'
   *  Gain: '<S11>/Gain'
   *  Inport: '<Root>/CoolantInletT'
   */
  rtb_Add1 = (*(real_T *)(mxGetData(vitc_CoolantTFilterC(S)))) * *((const real_T
    **)ssGetInputPortSignalPtrs(S, 4))[0] + ((real_T *)ssGetDWork(S, 0))[0];

  /* Delay: '<S7>/Resettable Delay3' incorporates:
   *  Constant: '<S7>/Constant22'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,&_rtZCE->ResettableDelay3_Reset_ZCE,
               ((*(real_T *)(mxGetData(vitc_CoolantInletTFaultReset(S)))))) !=
      NO_ZCEVENT) {
    ((real_T *)ssGetDWork(S, 1))[0] = 0.0;
  }

  /* Sum: '<S7>/Add3' incorporates:
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/Constant3'
   *  Delay: '<S7>/Resettable Delay3'
   *  Logic: '<S7>/Logical Operator'
   *  RelationalOperator: '<S7>/Relational Operator1'
   *  RelationalOperator: '<S7>/Relational Operator2'
   */
  _rtB->Add3 = (real_T)((rtb_Add1 >= (*(real_T *)(mxGetData
    (vitc_CoolantInletTUpperLim(S))))) || (rtb_Add1 <= (*(real_T *)(mxGetData
    (vitc_CoolantInletTLowerLim(S)))))) + ((real_T *)ssGetDWork(S, 1))[0];

  /* Sum: '<S12>/Add1' incorporates:
   *  Delay: '<S12>/Delay1'
   *  Gain: '<S12>/Gain'
   *  Inport: '<Root>/CoolantOutletT'
   */
  rtb_Add1_p = (*(real_T *)(mxGetData(vitc_CoolantTFilterC(S)))) * *((const
    real_T **)ssGetInputPortSignalPtrs(S, 5))[0] + ((real_T *)ssGetDWork(S, 2))
    [0];

  /* Delay: '<S8>/Resettable Delay3' incorporates:
   *  Constant: '<S8>/Constant22'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,&_rtZCE->ResettableDelay3_Reset_ZCE_g,
               ((*(real_T *)(mxGetData(vitc_CoolantOutletTFaultReset(S)))))) !=
      NO_ZCEVENT) {
    ((real_T *)ssGetDWork(S, 3))[0] = 0.0;
  }

  /* Sum: '<S8>/Add3' incorporates:
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S8>/Constant3'
   *  Delay: '<S8>/Resettable Delay3'
   *  Logic: '<S8>/Logical Operator'
   *  RelationalOperator: '<S8>/Relational Operator1'
   *  RelationalOperator: '<S8>/Relational Operator2'
   */
  _rtB->Add3_c = (real_T)((rtb_Add1_p >= (*(real_T *)(mxGetData
    (vitc_CoolantOutletTUpperLim(S))))) || (rtb_Add1_p <= (*(real_T *)(mxGetData
    (vitc_CoolantOutletTLowerLim(S)))))) + ((real_T *)ssGetDWork(S, 3))[0];

  /* Gain: '<S11>/Gain1' */
  _rtB->Gain1 = (1.0 - (*(real_T *)(mxGetData(vitc_CoolantTFilterC(S))))) *
    rtb_Add1;

  /* Gain: '<S12>/Gain3' */
  _rtB->Gain3 = (1.0 - (*(real_T *)(mxGetData(vitc_CoolantTFilterC(S))))) *
    rtb_Add1_p;

  /* Sum: '<S10>/Add1' incorporates:
   *  Delay: '<S10>/Delay1'
   *  Gain: '<S10>/Gain2'
   *  Inport: '<Root>/CellsTemperature'
   */
  for (i = 0; i < 40; i++) {
    rtb_Add1_h[i] = (*(real_T *)(mxGetData(vitc_CellTempFilterC(S)))) * *((const
      real_T **)ssGetInputPortSignalPtrs(S, 6))[i] + ((real_T *)ssGetDWork(S, 4))
      [i];
  }

  /* End of Sum: '<S10>/Add1' */

  /* MinMax: '<S5>/MinMax' */
  minV = rtb_Add1_h[0];
  for (i = 0; i < 39; i++) {
    if (!((minV <= rtb_Add1_h[i + 1]) || rtIsNaN(rtb_Add1_h[i + 1]))) {
      minV = rtb_Add1_h[i + 1];
    }
  }

  /* Delay: '<S5>/Resettable Delay' incorporates:
   *  Constant: '<S5>/Constant4'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,&_rtZCE->ResettableDelay_Reset_ZCE,
               ((*(real_T *)(mxGetData(vitc_CellTempLowFaultReset(S)))))) !=
      NO_ZCEVENT) {
    ((real_T *)ssGetDWork(S, 5))[0] = 0.0;
  }

  /* Sum: '<S5>/Add' incorporates:
   *  Constant: '<S5>/Constant'
   *  Delay: '<S5>/Resettable Delay'
   *  MinMax: '<S5>/MinMax'
   *  RelationalOperator: '<S5>/Relational Operator'
   */
  _rtB->Add = (real_T)(minV <= (*(real_T *)(mxGetData(vitc_CellTempMin(S))))) +
    ((real_T *)ssGetDWork(S, 5))[0];

  /* MinMax: '<S5>/MinMax1' */
  maxV = rtb_Add1_h[0];
  for (i = 0; i < 39; i++) {
    if (!((maxV >= rtb_Add1_h[i + 1]) || rtIsNaN(rtb_Add1_h[i + 1]))) {
      maxV = rtb_Add1_h[i + 1];
    }
  }

  /* Delay: '<S5>/Resettable Delay1' incorporates:
   *  Constant: '<S5>/Constant10'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,&_rtZCE->ResettableDelay1_Reset_ZCE,
               ((*(real_T *)(mxGetData(vitc_CellTempHighFaultReset(S)))))) !=
      NO_ZCEVENT) {
    ((real_T *)ssGetDWork(S, 6))[0] = 0.0;
  }

  /* Sum: '<S5>/Add1' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Delay: '<S5>/Resettable Delay1'
   *  MinMax: '<S5>/MinMax1'
   *  RelationalOperator: '<S5>/Relational Operator1'
   */
  _rtB->Add1 = (real_T)(maxV >= (*(real_T *)(mxGetData(vitc_CellTempMax(S))))) +
    ((real_T *)ssGetDWork(S, 6))[0];

  /* Sum: '<S5>/Sum of Elements' */
  rtb_Switch6 = rtb_Add1_h[0];
  for (i = 0; i < 39; i++) {
    rtb_Switch6 += rtb_Add1_h[i + 1];
  }

  /* End of Sum: '<S5>/Sum of Elements' */

  /* Product: '<S5>/Divide' incorporates:
   *  Constant: '<S5>/Constant14'
   */
  rtb_Divide = rtb_Switch6 / (*(real_T *)(mxGetData(vitk_NumberInSeries(S))));

  /* MinMax: '<S5>/MinMax2' */
  minV = rtb_Add1_h[0];

  /* MinMax: '<S5>/MinMax3' */
  maxV = rtb_Add1_h[0];
  for (i = 0; i < 39; i++) {
    /* MinMax: '<S5>/MinMax2' */
    if (!((minV <= rtb_Add1_h[i + 1]) || rtIsNaN(rtb_Add1_h[i + 1]))) {
      minV = rtb_Add1_h[i + 1];
    }

    /* MinMax: '<S5>/MinMax3' */
    if (!((maxV >= rtb_Add1_h[i + 1]) || rtIsNaN(rtb_Add1_h[i + 1]))) {
      maxV = rtb_Add1_h[i + 1];
    }
  }

  for (i = 0; i < 40; i++) {
    /* Gain: '<S10>/Gain3' */
    _rtB->Gain3_n[i] = (1.0 - (*(real_T *)(mxGetData(vitc_CellTempFilterC(S)))))
      * rtb_Add1_h[i];

    /* Sum: '<S2>/Add' incorporates:
     *  Delay: '<S2>/Delay'
     *  Gain: '<S2>/Gain'
     *  Inport: '<Root>/CellVoltages'
     */
    _rtB->Add_n[i] = (*(real_T *)(mxGetData(vitc_CellVolFilterC(S)))) * *((const
      real_T **)ssGetInputPortSignalPtrs(S, 0))[i] + ((real_T *)ssGetDWork(S, 7))
      [i];

    /* Gain: '<S2>/Gain1' */
    _rtB->Gain1_b[i] = (1.0 - (*(real_T *)(mxGetData(vitc_CellVolFilterC(S))))) *
      _rtB->Add_n[i];
  }

  /* Sum: '<S3>/Add' incorporates:
   *  Delay: '<S3>/Delay'
   *  Gain: '<S3>/Gain'
   *  Inport: '<Root>/PackVoltage'
   */
  _rtB->Add_f = (*(real_T *)(mxGetData(vitc_PackVolFilterC(S)))) * *((const
    real_T **)ssGetInputPortSignalPtrs(S, 1))[0] + ((real_T *)ssGetDWork(S, 8))
    [0];

  /* Gain: '<S3>/Gain1' */
  _rtB->Gain1_d = (1.0 - (*(real_T *)(mxGetData(vitc_PackVolFilterC(S))))) *
    _rtB->Add_f;

  /* MinMax: '<S6>/MinMax' */
  minV_0 = _rtB->Add_n[0];
  for (i = 0; i < 39; i++) {
    if (!((minV_0 <= _rtB->Add_n[i + 1]) || rtIsNaN(_rtB->Add_n[i + 1]))) {
      minV_0 = _rtB->Add_n[i + 1];
    }
  }

  /* Delay: '<S6>/Resettable Delay' incorporates:
   *  Constant: '<S6>/Constant4'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,&_rtZCE->ResettableDelay_Reset_ZCE_a,
               ((*(real_T *)(mxGetData(vitc_CellVoltageLowFaultReset(S)))))) !=
      NO_ZCEVENT) {
    ((real_T *)ssGetDWork(S, 9))[0] = 0.0;
  }

  /* Sum: '<S6>/Add' incorporates:
   *  Constant: '<S6>/Constant'
   *  Delay: '<S6>/Resettable Delay'
   *  MinMax: '<S6>/MinMax'
   *  RelationalOperator: '<S6>/Relational Operator'
   */
  _rtB->Add_o = (real_T)(minV_0 <= (*(real_T *)(mxGetData(vitc_CellVoltageMin(S)))))
    + ((real_T *)ssGetDWork(S, 9))[0];

  /* MinMax: '<S6>/MinMax1' */
  maxV_0 = _rtB->Add_n[0];
  for (i = 0; i < 39; i++) {
    if (!((maxV_0 >= _rtB->Add_n[i + 1]) || rtIsNaN(_rtB->Add_n[i + 1]))) {
      maxV_0 = _rtB->Add_n[i + 1];
    }
  }

  /* Delay: '<S6>/Resettable Delay1' incorporates:
   *  Constant: '<S6>/Constant10'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,&_rtZCE->ResettableDelay1_Reset_ZCE_n,
               ((*(real_T *)(mxGetData(vitc_CellVoltageHighFaultReset(S)))))) !=
      NO_ZCEVENT) {
    ((real_T *)ssGetDWork(S, 10))[0] = 0.0;
  }

  /* Sum: '<S6>/Add1' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Delay: '<S6>/Resettable Delay1'
   *  MinMax: '<S6>/MinMax1'
   *  RelationalOperator: '<S6>/Relational Operator1'
   */
  _rtB->Add1_i = (real_T)(maxV_0 >= (*(real_T *)(mxGetData(vitc_CellVoltageMax(S)))))
    + ((real_T *)ssGetDWork(S, 10))[0];

  /* Sum: '<S6>/Sum of Elements' */
  rtb_Switch6 = _rtB->Add_n[0];
  for (i = 0; i < 39; i++) {
    rtb_Switch6 += _rtB->Add_n[i + 1];
  }

  /* End of Sum: '<S6>/Sum of Elements' */

  /* Product: '<S6>/Divide' incorporates:
   *  Constant: '<S6>/Constant15'
   */
  rtb_Divide_m = rtb_Switch6 / (*(real_T *)(mxGetData(vitk_NumberInPara(S))));

  /* MinMax: '<S6>/MinMax2' */
  minV_0 = _rtB->Add_n[0];

  /* MinMax: '<S6>/MinMax3' */
  maxV_0 = _rtB->Add_n[0];

  /* Sum: '<S15>/Sum of Elements' incorporates:
   *  Delay: '<S15>/Delay1'
   */
  rtb_Switch6 = ((real_T *)ssGetDWork(S, 12))[0];
  for (i = 0; i < 39; i++) {
    /* MinMax: '<S6>/MinMax2' */
    if (!((minV_0 <= _rtB->Add_n[i + 1]) || rtIsNaN(_rtB->Add_n[i + 1]))) {
      minV_0 = _rtB->Add_n[i + 1];
    }

    /* MinMax: '<S6>/MinMax3' */
    if (!((maxV_0 >= _rtB->Add_n[i + 1]) || rtIsNaN(_rtB->Add_n[i + 1]))) {
      maxV_0 = _rtB->Add_n[i + 1];
    }

    /* Sum: '<S15>/Sum of Elements' incorporates:
     *  Delay: '<S15>/Delay1'
     */
    rtb_Switch6 += ((real_T *)ssGetDWork(S, 12))[i + 1];
  }

  /* Sum: '<S15>/Subtract' incorporates:
   *  Delay: '<S15>/Delay'
   */
  rtb_Switch6 = ((real_T *)ssGetDWork(S, 11))[0] - rtb_Switch6;

  /* Abs: '<S15>/Abs' */
  rtb_Switch6 = fabs(rtb_Switch6);

  /* Delay: '<S15>/Resettable Delay2' incorporates:
   *  Constant: '<S15>/Constant15'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,&_rtZCE->ResettableDelay2_Reset_ZCE,
               ((*(real_T *)(mxGetData(vitc_PackVoltageFaultReset(S)))))) !=
      NO_ZCEVENT) {
    ((real_T *)ssGetDWork(S, 13))[0] = 0.0;
  }

  /* Sum: '<S15>/Add2' incorporates:
   *  Constant: '<S15>/Constant14'
   *  Delay: '<S15>/Resettable Delay2'
   *  RelationalOperator: '<S15>/Relational Operator4'
   */
  _rtB->Add2 = (real_T)(rtb_Switch6 >= (*(real_T *)(mxGetData
    (vitc_CellPackVolTol(S))))) + ((real_T *)ssGetDWork(S, 13))[0];

  /* Sum: '<S9>/Add1' incorporates:
   *  Delay: '<S9>/Delay1'
   *  Gain: '<S9>/Gain2'
   *  Inport: '<Root>/PackCurrent'
   */
  rtb_Switch6 = (*(real_T *)(mxGetData(vitc_PackCurFilterC(S)))) * *((const
    real_T **)ssGetInputPortSignalPtrs(S, 3))[0] + ((real_T *)ssGetDWork(S, 14))
    [0];

  /* Gain: '<S9>/Gain3' */
  _rtB->Gain3_nj = (1.0 - (*(real_T *)(mxGetData(vitc_PackCurFilterC(S))))) *
    rtb_Switch6;

  /* Delay: '<S14>/Resettable Delay3' incorporates:
   *  Constant: '<S14>/Constant22'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,&_rtZCE->ResettableDelay3_Reset_ZCE_i,
               ((*(real_T *)(mxGetData(vitc_PackCurrentFaultReset(S)))))) !=
      NO_ZCEVENT) {
    ((real_T *)ssGetDWork(S, 15))[0] = 0.0;
  }

  /* Switch: '<S14>/Switch6' incorporates:
   *  Abs: '<S14>/Abs'
   *  Constant: '<S14>/Constant21'
   *  Constant: '<S14>/Constant26'
   *  Constant: '<S14>/Constant27'
   *  RelationalOperator: '<S14>/Relational Operator6'
   */
  if (fabs(rtb_Switch6) >= (*(real_T *)(mxGetData(vitc_PackCurrentLimit(S))))) {
    i = 1;
  } else {
    i = 0;
  }

  /* End of Switch: '<S14>/Switch6' */

  /* Sum: '<S14>/Add3' incorporates:
   *  Delay: '<S14>/Resettable Delay3'
   */
  _rtB->Add3_m = (real_T)i + ((real_T *)ssGetDWork(S, 15))[0];

  /* Delay: '<S13>/Resettable Delay3' incorporates:
   *  Constant: '<S13>/Constant22'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,&_rtZCE->ResettableDelay3_Reset_ZCE_f,
               ((*(real_T *)(mxGetData(vitc_HVILFaultReset(S)))))) != NO_ZCEVENT)
  {
    ((real_T *)ssGetDWork(S, 16))[0] = 0.0;
  }

  /* Sum: '<S13>/Add3' incorporates:
   *  Constant: '<S13>/Constant'
   *  Delay: '<S13>/Resettable Delay3'
   *  Inport: '<Root>/HVILReturn'
   *  RelationalOperator: '<S13>/Relational Operator'
   */
  _rtB->Add3_j = (real_T)(*((const real_T **)ssGetInputPortSignalPtrs(S, 7))[0] <
    1.0) + ((real_T *)ssGetDWork(S, 16))[0];

  /* Sum: '<S4>/Add' incorporates:
   *  Delay: '<S4>/Delay'
   *  Gain: '<S4>/Gain'
   *  Inport: '<Root>/VehSideVoltage'
   */
  rtb_Add = (*(real_T *)(mxGetData(vitc_VehVolFilterC(S)))) * *((const real_T **)
    ssGetInputPortSignalPtrs(S, 2))[0] + ((real_T *)ssGetDWork(S, 17))[0];

  /* Gain: '<S4>/Gain1' */
  _rtB->Gain1_l = (1.0 - (*(real_T *)(mxGetData(vitc_VehVolFilterC(S))))) *
    rtb_Add;

  /* Outport: '<Root>/vitm_CellsMaxTemperature' incorporates:
   *  MinMax: '<S5>/MinMax3'
   */
  ((real_T *)ssGetOutputPortSignal(S, 0))[0] = maxV;

  /* Outport: '<Root>/vitm_CellsMinTemperature' incorporates:
   *  MinMax: '<S5>/MinMax2'
   */
  ((real_T *)ssGetOutputPortSignal(S, 1))[0] = minV;

  /* Outport: '<Root>/vitm_CellsAvgTemperature' incorporates:
   *  Constant: '<S5>/Constant15'
   *  Product: '<S5>/Divide1'
   */
  ((real_T *)ssGetOutputPortSignal(S, 2))[0] = rtb_Divide / (*(real_T *)
    (mxGetData(vitk_NumberInPara(S))));

  /* Outport: '<Root>/vitm_CellsTemperatureLowFault' incorporates:
   *  Constant: '<S5>/Constant5'
   *  RelationalOperator: '<S5>/Relational Operator2'
   */
  ((uint8_T *)ssGetOutputPortSignal(S, 3))[0] = (uint8_T)(_rtB->Add >= (*(real_T
    *)(mxGetData(vitc_CellTempFaultTimer(S)))) / (*(real_T *)(mxGetData
    (vitk_stepSize(S)))));

  /* Outport: '<Root>/vitm_CellsTemperatureHighFault' incorporates:
   *  Constant: '<S5>/Constant11'
   *  RelationalOperator: '<S5>/Relational Operator3'
   */
  ((uint8_T *)ssGetOutputPortSignal(S, 4))[0] = (uint8_T)(_rtB->Add1 >=
    (*(real_T *)(mxGetData(vitc_CellTempFaultTimer(S)))) / (*(real_T *)
    (mxGetData(vitk_stepSize(S)))));

  /* Outport: '<Root>/vitm_CellsVoltageLowFault' incorporates:
   *  Constant: '<S6>/Constant5'
   *  RelationalOperator: '<S6>/Relational Operator2'
   */
  ((uint8_T *)ssGetOutputPortSignal(S, 5))[0] = (uint8_T)(_rtB->Add_o >=
    (*(real_T *)(mxGetData(vitc_CellVoltageFaultTimer(S)))) / (*(real_T *)
    (mxGetData(vitk_stepSize(S)))));

  /* Outport: '<Root>/vitm_CellsVoltageHighFault' incorporates:
   *  Constant: '<S6>/Constant11'
   *  RelationalOperator: '<S6>/Relational Operator3'
   */
  ((uint8_T *)ssGetOutputPortSignal(S, 6))[0] = (uint8_T)(_rtB->Add1_i >=
    (*(real_T *)(mxGetData(vitc_CellVoltageFaultTimer(S)))) / (*(real_T *)
    (mxGetData(vitk_stepSize(S)))));

  /* Outport: '<Root>/vitm_PackVoltageFault' incorporates:
   *  Constant: '<S15>/Constant16'
   *  RelationalOperator: '<S15>/Relational Operator5'
   */
  ((uint8_T *)ssGetOutputPortSignal(S, 7))[0] = (uint8_T)(_rtB->Add2 >=
    (*(real_T *)(mxGetData(vitc_PackVoltageFaultTimer(S)))) / (*(real_T *)
    (mxGetData(vitk_stepSize(S)))));

  /* Outport: '<Root>/vitm_CellsMinVoltage' incorporates:
   *  MinMax: '<S6>/MinMax2'
   */
  ((real_T *)ssGetOutputPortSignal(S, 8))[0] = minV_0;

  /* Outport: '<Root>/vitm_CellsMaxVoltage' incorporates:
   *  MinMax: '<S6>/MinMax3'
   */
  ((real_T *)ssGetOutputPortSignal(S, 9))[0] = maxV_0;

  /* Outport: '<Root>/vitm_CellsAvgVoltage' incorporates:
   *  Constant: '<S6>/Constant14'
   *  Product: '<S6>/Divide1'
   */
  ((real_T *)ssGetOutputPortSignal(S, 10))[0] = rtb_Divide_m / (*(real_T *)
    (mxGetData(vitk_NumberInSeries(S))));

  /* End of Outputs for SubSystem: '<Root>/VITM' */

  /* Outport: '<Root>/vitm_PackVoltageFiltered' */
  ((real_T *)ssGetOutputPortSignal(S, 11))[0] = _rtB->Add_f;

  /* Outport: '<Root>/vitm_PackCurrentFiltered' */
  ((real_T *)ssGetOutputPortSignal(S, 12))[0] = rtb_Switch6;

  /* Outputs for Atomic SubSystem: '<Root>/VITM' */
  /* Outport: '<Root>/vitm_PackCurrentFault' incorporates:
   *  Constant: '<S14>/Constant23'
   *  RelationalOperator: '<S14>/Relational Operator7'
   */
  ((uint8_T *)ssGetOutputPortSignal(S, 13))[0] = (uint8_T)(_rtB->Add3_m >=
    (*(real_T *)(mxGetData(vitc_PackCurrentFaultTimer(S)))) / (*(real_T *)
    (mxGetData(vitk_stepSize(S)))));

  /* Outport: '<Root>/vitm_CoolantDeltaTemp' incorporates:
   *  Sum: '<S1>/Sum'
   */
  ((real_T *)ssGetOutputPortSignal(S, 14))[0] = rtb_Add1 - rtb_Add1_p;

  /* Outport: '<Root>/vitm_CoolantInletTempFault' incorporates:
   *  Constant: '<S7>/Constant23'
   *  RelationalOperator: '<S7>/Relational Operator7'
   */
  ((uint8_T *)ssGetOutputPortSignal(S, 15))[0] = (uint8_T)(_rtB->Add3 >=
    (*(real_T *)(mxGetData(vitc_CoolantTempFaultCounter(S)))) / (*(real_T *)
    (mxGetData(vitk_stepSize(S)))));

  /* Outport: '<Root>/vitm_CoolantOutlletTempFault' incorporates:
   *  Constant: '<S8>/Constant23'
   *  RelationalOperator: '<S8>/Relational Operator7'
   */
  ((uint8_T *)ssGetOutputPortSignal(S, 16))[0] = (uint8_T)(_rtB->Add3_c >=
    (*(real_T *)(mxGetData(vitc_CoolantTempFaultCounter(S)))) / (*(real_T *)
    (mxGetData(vitk_stepSize(S)))));

  /* End of Outputs for SubSystem: '<Root>/VITM' */

  /* Outport: '<Root>/vitm_CoolantInletTFiltered' */
  ((real_T *)ssGetOutputPortSignal(S, 17))[0] = rtb_Add1;

  /* Outport: '<Root>/vitm_CoolantOutletTFiltered' */
  ((real_T *)ssGetOutputPortSignal(S, 18))[0] = rtb_Add1_p;

  /* Outputs for Atomic SubSystem: '<Root>/VITM' */
  /* Outport: '<Root>/vitm_HVILFault' incorporates:
   *  Constant: '<S13>/Constant23'
   *  RelationalOperator: '<S13>/Relational Operator7'
   */
  ((uint8_T *)ssGetOutputPortSignal(S, 19))[0] = (uint8_T)(_rtB->Add3_j >=
    (*(real_T *)(mxGetData(vitc_HVILFaultCounter(S)))) / (*(real_T *)(mxGetData
    (vitk_stepSize(S)))));

  /* End of Outputs for SubSystem: '<Root>/VITM' */

  /* Outport: '<Root>/vitm_CellsTemperatureFiltered' incorporates:
   *  Outport: '<Root>/vitm_CellsVoltageFiltered'
   */
  memcpy(&((real_T *)ssGetOutputPortSignal(S, 20))[0], &rtb_Add1_h[0], 40U *
         sizeof(real_T));

  /* Outport: '<Root>/vitm_CellsVoltageFiltered' incorporates:
   *  Outport: '<Root>/vitm_CellsTemperatureFiltered'
   */
  memcpy(&((real_T *)ssGetOutputPortSignal(S, 21))[0], &_rtB->Add_n[0], 40U *
         sizeof(real_T));

  /* Outport: '<Root>/vitm_VehSideVoltageFiltered' */
  ((real_T *)ssGetOutputPortSignal(S, 22))[0] = rtb_Add;
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  B_VITM_T *_rtB;
  _rtB = ((B_VITM_T *) ssGetLocalBlockIO(S));

  /* Update for Atomic SubSystem: '<Root>/VITM' */
  /* Update for Delay: '<S11>/Delay1' */
  ((real_T *)ssGetDWork(S, 0))[0] = _rtB->Gain1;

  /* Update for Delay: '<S7>/Resettable Delay3' */
  ((real_T *)ssGetDWork(S, 1))[0] = _rtB->Add3;

  /* Update for Delay: '<S12>/Delay1' */
  ((real_T *)ssGetDWork(S, 2))[0] = _rtB->Gain3;

  /* Update for Delay: '<S8>/Resettable Delay3' */
  ((real_T *)ssGetDWork(S, 3))[0] = _rtB->Add3_c;

  /* Update for Delay: '<S5>/Resettable Delay' */
  ((real_T *)ssGetDWork(S, 5))[0] = _rtB->Add;

  /* Update for Delay: '<S5>/Resettable Delay1' */
  ((real_T *)ssGetDWork(S, 6))[0] = _rtB->Add1;

  /* Update for Delay: '<S3>/Delay' */
  ((real_T *)ssGetDWork(S, 8))[0] = _rtB->Gain1_d;

  /* Update for Delay: '<S6>/Resettable Delay' */
  ((real_T *)ssGetDWork(S, 9))[0] = _rtB->Add_o;

  /* Update for Delay: '<S6>/Resettable Delay1' */
  ((real_T *)ssGetDWork(S, 10))[0] = _rtB->Add1_i;

  /* Update for Delay: '<S15>/Delay' */
  ((real_T *)ssGetDWork(S, 11))[0] = _rtB->Add_f;

  /* Update for Delay: '<S10>/Delay1' incorporates:
   *  Update for Delay: '<S15>/Delay1'
   *  Update for Delay: '<S2>/Delay'
   */
  memcpy(&((real_T *)ssGetDWork(S, 4))[0], &_rtB->Gain3_n[0], 40U * sizeof
         (real_T));

  /* Update for Delay: '<S2>/Delay' incorporates:
   *  Update for Delay: '<S10>/Delay1'
   *  Update for Delay: '<S15>/Delay1'
   */
  memcpy(&((real_T *)ssGetDWork(S, 7))[0], &_rtB->Gain1_b[0], 40U * sizeof
         (real_T));

  /* Update for Delay: '<S15>/Delay1' incorporates:
   *  Update for Delay: '<S10>/Delay1'
   *  Update for Delay: '<S2>/Delay'
   */
  memcpy(&((real_T *)ssGetDWork(S, 12))[0], &_rtB->Add_n[0], 40U * sizeof(real_T));

  /* Update for Delay: '<S15>/Resettable Delay2' */
  ((real_T *)ssGetDWork(S, 13))[0] = _rtB->Add2;

  /* Update for Delay: '<S9>/Delay1' */
  ((real_T *)ssGetDWork(S, 14))[0] = _rtB->Gain3_nj;

  /* Update for Delay: '<S14>/Resettable Delay3' */
  ((real_T *)ssGetDWork(S, 15))[0] = _rtB->Add3_m;

  /* Update for Delay: '<S13>/Resettable Delay3' */
  ((real_T *)ssGetDWork(S, 16))[0] = _rtB->Add3_j;

  /* Update for Delay: '<S4>/Delay' */
  ((real_T *)ssGetDWork(S, 17))[0] = _rtB->Gain1_l;

  /* End of Update for SubSystem: '<Root>/VITM' */
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
  /* Parameter check for 'vitc_CellPackVolTol' */
  if (mxIsComplex(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellPackVolTol' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellPackVolTol' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 0)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellPackVolTol' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CellTempFaultTimer' */
  if (mxIsComplex(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellTempFaultTimer' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellTempFaultTimer' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 1)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellTempFaultTimer' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CellTempFilterC' */
  if (mxIsComplex(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellTempFilterC' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellTempFilterC' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 2)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellTempFilterC' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CellTempHighFaultReset' */
  if (mxIsComplex(ssGetSFcnParam(S, 3))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellTempHighFaultReset' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 3))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellTempHighFaultReset' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 3)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 3))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 3))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellTempHighFaultReset' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CellTempLowFaultReset' */
  if (mxIsComplex(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellTempLowFaultReset' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellTempLowFaultReset' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 4)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellTempLowFaultReset' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CellTempMax' */
  if (mxIsComplex(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellTempMax' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,"Parameter 'vitc_CellTempMax' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 5)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'vitc_CellTempMax' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CellTempMin' */
  if (mxIsComplex(ssGetSFcnParam(S, 6))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellTempMin' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 6))) {
    ssSetErrorStatus(S,"Parameter 'vitc_CellTempMin' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 6)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 6))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 6))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'vitc_CellTempMin' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CellVolFilterC' */
  if (mxIsComplex(ssGetSFcnParam(S, 7))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellVolFilterC' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 7))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellVolFilterC' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 7)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 7))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 7))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellVolFilterC' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CellVoltageFaultTimer' */
  if (mxIsComplex(ssGetSFcnParam(S, 8))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellVoltageFaultTimer' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 8))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellVoltageFaultTimer' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 8)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 8))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 8))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellVoltageFaultTimer' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CellVoltageHighFaultReset' */
  if (mxIsComplex(ssGetSFcnParam(S, 9))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellVoltageHighFaultReset' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 9))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellVoltageHighFaultReset' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 9)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 9))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 9))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellVoltageHighFaultReset' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CellVoltageLowFaultReset' */
  if (mxIsComplex(ssGetSFcnParam(S, 10))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellVoltageLowFaultReset' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 10))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellVoltageLowFaultReset' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 10)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 10))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 10))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellVoltageLowFaultReset' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CellVoltageMax' */
  if (mxIsComplex(ssGetSFcnParam(S, 11))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellVoltageMax' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 11))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellVoltageMax' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 11)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 11))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 11))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellVoltageMax' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CellVoltageMin' */
  if (mxIsComplex(ssGetSFcnParam(S, 12))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellVoltageMin' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 12))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellVoltageMin' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 12)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 12))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 12))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CellVoltageMin' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CoolantInletTFaultReset' */
  if (mxIsComplex(ssGetSFcnParam(S, 13))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantInletTFaultReset' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 13))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantInletTFaultReset' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 13)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 13))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 13))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantInletTFaultReset' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CoolantInletTLowerLim' */
  if (mxIsComplex(ssGetSFcnParam(S, 14))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantInletTLowerLim' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 14))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantInletTLowerLim' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 14)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 14))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 14))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantInletTLowerLim' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CoolantInletTUpperLim' */
  if (mxIsComplex(ssGetSFcnParam(S, 15))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantInletTUpperLim' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 15))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantInletTUpperLim' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 15)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 15))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 15))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantInletTUpperLim' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CoolantOutletTFaultReset' */
  if (mxIsComplex(ssGetSFcnParam(S, 16))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantOutletTFaultReset' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 16))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantOutletTFaultReset' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 16)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 16))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 16))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantOutletTFaultReset' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CoolantOutletTLowerLim' */
  if (mxIsComplex(ssGetSFcnParam(S, 17))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantOutletTLowerLim' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 17))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantOutletTLowerLim' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 17)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 17))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 17))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantOutletTLowerLim' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CoolantOutletTUpperLim' */
  if (mxIsComplex(ssGetSFcnParam(S, 18))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantOutletTUpperLim' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 18))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantOutletTUpperLim' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 18)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 18))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 18))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantOutletTUpperLim' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CoolantTFilterC' */
  if (mxIsComplex(ssGetSFcnParam(S, 19))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantTFilterC' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 19))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantTFilterC' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 19)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 19))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 19))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantTFilterC' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_CoolantTempFaultCounter' */
  if (mxIsComplex(ssGetSFcnParam(S, 20))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantTempFaultCounter' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 20))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantTempFaultCounter' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 20)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 20))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 20))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_CoolantTempFaultCounter' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_HVILFaultCounter' */
  if (mxIsComplex(ssGetSFcnParam(S, 21))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_HVILFaultCounter' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 21))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_HVILFaultCounter' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 21)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 21))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 21))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_HVILFaultCounter' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_HVILFaultReset' */
  if (mxIsComplex(ssGetSFcnParam(S, 22))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_HVILFaultReset' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 22))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_HVILFaultReset' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 22)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 22))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 22))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_HVILFaultReset' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_PackCurFilterC' */
  if (mxIsComplex(ssGetSFcnParam(S, 23))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackCurFilterC' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 23))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackCurFilterC' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 23)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 23))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 23))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackCurFilterC' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_PackCurrentFaultReset' */
  if (mxIsComplex(ssGetSFcnParam(S, 24))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackCurrentFaultReset' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 24))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackCurrentFaultReset' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 24)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 24))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 24))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackCurrentFaultReset' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_PackCurrentFaultTimer' */
  if (mxIsComplex(ssGetSFcnParam(S, 25))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackCurrentFaultTimer' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 25))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackCurrentFaultTimer' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 25)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 25))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 25))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackCurrentFaultTimer' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_PackCurrentLimit' */
  if (mxIsComplex(ssGetSFcnParam(S, 26))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackCurrentLimit' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 26))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackCurrentLimit' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 26)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 26))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 26))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackCurrentLimit' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_PackVolFilterC' */
  if (mxIsComplex(ssGetSFcnParam(S, 27))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackVolFilterC' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 27))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackVolFilterC' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 27)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 27))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 27))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackVolFilterC' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_PackVoltageFaultReset' */
  if (mxIsComplex(ssGetSFcnParam(S, 28))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackVoltageFaultReset' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 28))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackVoltageFaultReset' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 28)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 28))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 28))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackVoltageFaultReset' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_PackVoltageFaultTimer' */
  if (mxIsComplex(ssGetSFcnParam(S, 29))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackVoltageFaultTimer' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 29))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackVoltageFaultTimer' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 29)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 29))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 29))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_PackVoltageFaultTimer' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitc_VehVolFilterC' */
  if (mxIsComplex(ssGetSFcnParam(S, 30))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_VehVolFilterC' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 30))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitc_VehVolFilterC' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 30)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 30))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 30))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'vitc_VehVolFilterC' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitk_NumberInPara' */
  if (mxIsComplex(ssGetSFcnParam(S, 31))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitk_NumberInPara' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 31))) {
    ssSetErrorStatus(S,"Parameter 'vitk_NumberInPara' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 31)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 31))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 31))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'vitk_NumberInPara' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitk_NumberInSeries' */
  if (mxIsComplex(ssGetSFcnParam(S, 32))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitk_NumberInSeries' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 32))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitk_NumberInSeries' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 32)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 32))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 32))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'vitk_NumberInSeries' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'vitk_stepSize' */
  if (mxIsComplex(ssGetSFcnParam(S, 33))) {
    ssSetErrorStatus(S,
                     "Parameter 'vitk_stepSize' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 33))) {
    ssSetErrorStatus(S,"Parameter 'vitk_stepSize' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 33)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 33))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 33))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'vitk_stepSize' has to be a [1x1] array.");
    return;
  }
}

#endif                                 /* MDL_CHECK_PARAMETERS */

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "VITM_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 1);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 23))
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
    ssSetOutputPortDataType(S, 3, SS_UINT8);
  }

  ssSetOutputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);

  /* outport number: 4 */
  if (!ssSetOutputPortVectorDimension(S, 4, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 4, SS_UINT8);
  }

  ssSetOutputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);

  /* outport number: 5 */
  if (!ssSetOutputPortVectorDimension(S, 5, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 5, SS_UINT8);
  }

  ssSetOutputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);

  /* outport number: 6 */
  if (!ssSetOutputPortVectorDimension(S, 6, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 6, SS_UINT8);
  }

  ssSetOutputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);

  /* outport number: 7 */
  if (!ssSetOutputPortVectorDimension(S, 7, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 7, SS_UINT8);
  }

  ssSetOutputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);

  /* outport number: 8 */
  if (!ssSetOutputPortVectorDimension(S, 8, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 8, SS_DOUBLE);
  }

  ssSetOutputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);

  /* outport number: 9 */
  if (!ssSetOutputPortVectorDimension(S, 9, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 9, SS_DOUBLE);
  }

  ssSetOutputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);

  /* outport number: 10 */
  if (!ssSetOutputPortVectorDimension(S, 10, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 10, SS_DOUBLE);
  }

  ssSetOutputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);

  /* outport number: 11 */
  if (!ssSetOutputPortVectorDimension(S, 11, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 11, SS_DOUBLE);
  }

  ssSetOutputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);

  /* outport number: 12 */
  if (!ssSetOutputPortVectorDimension(S, 12, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 12, SS_DOUBLE);
  }

  ssSetOutputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);

  /* outport number: 13 */
  if (!ssSetOutputPortVectorDimension(S, 13, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 13, SS_UINT8);
  }

  ssSetOutputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);

  /* outport number: 14 */
  if (!ssSetOutputPortVectorDimension(S, 14, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 14, SS_DOUBLE);
  }

  ssSetOutputPortOptimOpts(S, 14, SS_REUSABLE_AND_LOCAL);

  /* outport number: 15 */
  if (!ssSetOutputPortVectorDimension(S, 15, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 15, SS_UINT8);
  }

  ssSetOutputPortOptimOpts(S, 15, SS_REUSABLE_AND_LOCAL);

  /* outport number: 16 */
  if (!ssSetOutputPortVectorDimension(S, 16, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 16, SS_UINT8);
  }

  ssSetOutputPortOptimOpts(S, 16, SS_REUSABLE_AND_LOCAL);

  /* outport number: 17 */
  if (!ssSetOutputPortVectorDimension(S, 17, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 17, SS_DOUBLE);
  }

  ssSetOutputPortOptimOpts(S, 17, SS_REUSABLE_AND_LOCAL);

  /* outport number: 18 */
  if (!ssSetOutputPortVectorDimension(S, 18, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 18, SS_DOUBLE);
  }

  ssSetOutputPortOptimOpts(S, 18, SS_REUSABLE_AND_LOCAL);

  /* outport number: 19 */
  if (!ssSetOutputPortVectorDimension(S, 19, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 19, SS_UINT8);
  }

  ssSetOutputPortOptimOpts(S, 19, SS_REUSABLE_AND_LOCAL);

  /* outport number: 20 */
  if (!ssSetOutputPortVectorDimension(S, 20, 40))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 20, SS_DOUBLE);
  }

  ssSetOutputPortOptimOpts(S, 20, SS_REUSABLE_AND_LOCAL);

  /* outport number: 21 */
  if (!ssSetOutputPortVectorDimension(S, 21, 40))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 21, SS_DOUBLE);
  }

  ssSetOutputPortOptimOpts(S, 21, SS_REUSABLE_AND_LOCAL);

  /* outport number: 22 */
  if (!ssSetOutputPortVectorDimension(S, 22, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 22, SS_DOUBLE);
  }

  ssSetOutputPortOptimOpts(S, 22, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 8))
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
    if (!ssSetInputPortVectorDimension(S, 1, 1))
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

  /* inport number: 5 */
  {
    if (!ssSetInputPortVectorDimension(S, 5, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 5, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 5, 1);
    ssSetInputPortOverWritable(S, 5, 0);
    ssSetInputPortOptimOpts(S, 5, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 6 */
  {
    if (!ssSetInputPortVectorDimension(S, 6, 40))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 6, SS_DOUBLE);
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
      ssSetInputPortDataType(S, 7, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 7, 1);
    ssSetInputPortOverWritable(S, 7, 0);
    ssSetInputPortOptimOpts(S, 7, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 18)) {
    return;
  }

  /* '<S11>/Delay1': DSTATE */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 1);
  ssSetDWorkUsedAsDState(S, 0, 1);

  /* '<S7>/Resettable Delay3': DSTATE */
  ssSetDWorkName(S, 1, "DWORK1");
  ssSetDWorkWidth(S, 1, 1);
  ssSetDWorkUsedAsDState(S, 1, 1);

  /* '<S12>/Delay1': DSTATE */
  ssSetDWorkName(S, 2, "DWORK2");
  ssSetDWorkWidth(S, 2, 1);
  ssSetDWorkUsedAsDState(S, 2, 1);

  /* '<S8>/Resettable Delay3': DSTATE */
  ssSetDWorkName(S, 3, "DWORK3");
  ssSetDWorkWidth(S, 3, 1);
  ssSetDWorkUsedAsDState(S, 3, 1);

  /* '<S10>/Delay1': DSTATE */
  ssSetDWorkName(S, 4, "DWORK4");
  ssSetDWorkWidth(S, 4, 40);
  ssSetDWorkUsedAsDState(S, 4, 1);

  /* '<S5>/Resettable Delay': DSTATE */
  ssSetDWorkName(S, 5, "DWORK5");
  ssSetDWorkWidth(S, 5, 1);
  ssSetDWorkUsedAsDState(S, 5, 1);

  /* '<S5>/Resettable Delay1': DSTATE */
  ssSetDWorkName(S, 6, "DWORK6");
  ssSetDWorkWidth(S, 6, 1);
  ssSetDWorkUsedAsDState(S, 6, 1);

  /* '<S2>/Delay': DSTATE */
  ssSetDWorkName(S, 7, "DWORK7");
  ssSetDWorkWidth(S, 7, 40);
  ssSetDWorkUsedAsDState(S, 7, 1);

  /* '<S3>/Delay': DSTATE */
  ssSetDWorkName(S, 8, "DWORK8");
  ssSetDWorkWidth(S, 8, 1);
  ssSetDWorkUsedAsDState(S, 8, 1);

  /* '<S6>/Resettable Delay': DSTATE */
  ssSetDWorkName(S, 9, "DWORK9");
  ssSetDWorkWidth(S, 9, 1);
  ssSetDWorkUsedAsDState(S, 9, 1);

  /* '<S6>/Resettable Delay1': DSTATE */
  ssSetDWorkName(S, 10, "DWORK10");
  ssSetDWorkWidth(S, 10, 1);
  ssSetDWorkUsedAsDState(S, 10, 1);

  /* '<S15>/Delay': DSTATE */
  ssSetDWorkName(S, 11, "DWORK11");
  ssSetDWorkWidth(S, 11, 1);
  ssSetDWorkUsedAsDState(S, 11, 1);

  /* '<S15>/Delay1': DSTATE */
  ssSetDWorkName(S, 12, "DWORK12");
  ssSetDWorkWidth(S, 12, 40);
  ssSetDWorkUsedAsDState(S, 12, 1);

  /* '<S15>/Resettable Delay2': DSTATE */
  ssSetDWorkName(S, 13, "DWORK13");
  ssSetDWorkWidth(S, 13, 1);
  ssSetDWorkUsedAsDState(S, 13, 1);

  /* '<S9>/Delay1': DSTATE */
  ssSetDWorkName(S, 14, "DWORK14");
  ssSetDWorkWidth(S, 14, 1);
  ssSetDWorkUsedAsDState(S, 14, 1);

  /* '<S14>/Resettable Delay3': DSTATE */
  ssSetDWorkName(S, 15, "DWORK15");
  ssSetDWorkWidth(S, 15, 1);
  ssSetDWorkUsedAsDState(S, 15, 1);

  /* '<S13>/Resettable Delay3': DSTATE */
  ssSetDWorkName(S, 16, "DWORK16");
  ssSetDWorkWidth(S, 16, 1);
  ssSetDWorkUsedAsDState(S, 16, 1);

  /* '<S4>/Delay': DSTATE */
  ssSetDWorkName(S, 17, "DWORK17");
  ssSetDWorkWidth(S, 17, 1);
  ssSetDWorkUsedAsDState(S, 17, 1);

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 34);

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
# define S_FUNCTION_NAME               VITM_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
