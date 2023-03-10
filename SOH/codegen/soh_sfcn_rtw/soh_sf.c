/*
 * soh_sf.c
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

#include <math.h>
#include "soh_sf.h"
#include "soh_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"

/* Named constants for Chart: '<S1>/Chart' */
#define soh_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define soh_IN_dataStore               ((uint8_T)1U)
#define soh_IN_end                     ((uint8_T)2U)
#define soh_IN_key_ON                  ((uint8_T)3U)
#define soh_IN_sohr                    ((uint8_T)4U)
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *soh_malloc(SimStruct *S);

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
real_T soh_look2_binlx(real_T u0, real_T u1, const real_T bp0[], const real_T
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

/* Output and update for function-call system: '<S1>/init' */
void soh_init(const real_T rtu_soc_C_factors_init[40], B_init_soh_T *localB,
              real_T rtd_memStore_Rfactors[40])
{
  /* DataStoreRead: '<S6>/Data Store Read1' incorporates:
   *  Inport: '<S6>/soc_C_factors_init'
   */
  memcpy(&localB->DataStoreRead1[0], &rtd_memStore_Rfactors[0], 40U * sizeof
         (real_T));

  /* Inport: '<S6>/soc_C_factors_init' incorporates:
   *  DataStoreRead: '<S6>/Data Store Read1'
   */
  memcpy(&localB->soc_C_factors_init[0], &rtu_soc_C_factors_init[0], 40U *
         sizeof(real_T));
}

/* Termination for function-call system: '<S1>/init' */
void soh_init_Term(SimStruct *const S)
{
}

/* Initial conditions for function-call system: '<S1>/deltaCalc' */
void soh_deltaCalc_Init(SimStruct * const S)
{
  int32_T i;
  for (i = 0; i < 40; i++) {
    /* InitializeConditions for Delay: '<S5>/Delay2' */
    ((real_T *)ssGetDWork(S, 7))[i] = 0.0;

    /* InitializeConditions for Delay: '<S5>/Delay3' */
    ((real_T *)ssGetDWork(S, 8))[i] = 0.0;
  }
}

/* Output and update for function-call system: '<S1>/deltaCalc' */
void soh_deltaCalc(SimStruct * const S, real_T rtu_PackCurrent, const real_T
                   rtu_CellVoltages[40], const real_T rtu_CellSOC[40], const
                   real_T rtu_CellTemp[40], const boolean_T rtu_cb_cmds[40],
                   B_deltaCalc_soh_T *localB)
{
  int32_T i;
  real_T rtb_Sum;
  for (i = 0; i < 40; i++) {
    /* Sum: '<S5>/Sum' incorporates:
     *  Constant: '<S5>/Constant4'
     *  DataTypeConversion: '<S5>/Data Type Conversion'
     *  Product: '<S5>/Divide1'
     *  Product: '<S5>/Divide2'
     *  Product: '<S5>/Divide4'
     */
    rtb_Sum = rtu_PackCurrent - rtu_CellVoltages[i] * (real_T)rtu_cb_cmds[i] / (*
      (real_T *)(mxGetData(sohk_CellBalancingResistor(S))));

    /* Sum: '<S5>/Subtract' incorporates:
     *  Delay: '<S5>/Delay2'
     */
    localB->Subtract[i] = rtb_Sum - ((real_T *)ssGetDWork(S, 7))[i];

    /* Sum: '<S5>/Subtract1' incorporates:
     *  Delay: '<S5>/Delay3'
     */
    localB->Subtract1[i] = rtu_CellVoltages[i] - ((real_T *)ssGetDWork(S, 8))[i];

    /* Lookup_n-D: '<S5>/2-D Lookup Table1' */
    localB->uDLookupTable1[i] = soh_look2_binlx(rtu_CellTemp[i], rtu_CellSOC[i],
      ((real_T *)mxGetData(bmsc_InternalDischgResistX(S))), ((real_T *)mxGetData
      (bmsc_InternalDischgResistY(S))), ((real_T *)mxGetData
      (bmsc_InternalDischgResistZ(S))), soh_ConstP.uDLookupTable1_maxIndex, 3U);

    /* Update for Delay: '<S5>/Delay2' */
    ((real_T *)ssGetDWork(S, 7))[i] = rtb_Sum;

    /* Update for Delay: '<S5>/Delay3' */
    ((real_T *)ssGetDWork(S, 8))[i] = rtu_CellVoltages[i];
  }
}

/* Termination for function-call system: '<S1>/deltaCalc' */
void soh_deltaCalc_Term(SimStruct *const S)
{
}

/* Initial conditions for function-call system: '<S1>/key_on' */
void soh_key_on_Init(SimStruct * const S)
{
  /* InitializeConditions for Delay: '<S7>/Delay1' incorporates:
   *  InitializeConditions for Delay: '<S7>/Delay3'
   */
  memcpy(&((real_T *)ssGetDWork(S, 1))[0], ((real_T *)mxGetData
          (sohv_factoryInit_sohc(S))), 40U * sizeof(real_T));

  /* InitializeConditions for Delay: '<S7>/Delay3' incorporates:
   *  InitializeConditions for Delay: '<S7>/Delay1'
   */
  memcpy(&((real_T *)ssGetDWork(S, 2))[0], ((real_T *)mxGetData
          (sohv_factoryInit_sohr(S))), 40U * sizeof(real_T));
}

/* Output and update for function-call system: '<S1>/key_on' */
void soh_key_on(SimStruct * const S)
{
  real_T minV;
  real_T minV_0;
  real_T rtb_Sum2[40];
  real_T rtb_Sum1[40];
  int32_T i;
  B_soh_T *_rtB;
  _rtB = ((B_soh_T *) ssGetLocalBlockIO(S));

  /* Sum: '<S7>/Sum2' incorporates:
   *  Delay: '<S7>/Delay3'
   *  Gain: '<S7>/Gain6'
   *  Gain: '<S7>/Gain7'
   */
  for (i = 0; i < 40; i++) {
    rtb_Sum2[i] = (1.0 - (*(real_T *)(mxGetData(sohc_customer_filter_coeff(S)))))
      * _rtB->init.DataStoreRead1[i] + (*(real_T *)(mxGetData
      (sohc_customer_filter_coeff(S)))) * ((real_T *)ssGetDWork(S, 2))[i];
  }

  /* End of Sum: '<S7>/Sum2' */

  /* MinMax: '<S7>/MinMax' */
  minV = rtb_Sum2[0];
  for (i = 0; i < 39; i++) {
    if (!((minV <= rtb_Sum2[i + 1]) || rtIsNaN(rtb_Sum2[i + 1]))) {
      minV = rtb_Sum2[i + 1];
    }
  }

  /* Sum: '<S7>/Sum1' incorporates:
   *  Delay: '<S7>/Delay1'
   *  Gain: '<S7>/Gain1'
   *  Gain: '<S7>/Gain2'
   */
  for (i = 0; i < 40; i++) {
    rtb_Sum1[i] = (1.0 - (*(real_T *)(mxGetData(sohc_customer_filter_coeff(S)))))
      * _rtB->init.soc_C_factors_init[i] + (*(real_T *)(mxGetData
      (sohc_customer_filter_coeff(S)))) * ((real_T *)ssGetDWork(S, 1))[i];
  }

  /* End of Sum: '<S7>/Sum1' */

  /* MinMax: '<S7>/MinMax1' */
  minV_0 = rtb_Sum1[0];
  for (i = 0; i < 39; i++) {
    if (!((minV_0 <= rtb_Sum1[i + 1]) || rtIsNaN(rtb_Sum1[i + 1]))) {
      minV_0 = rtb_Sum1[i + 1];
    }
  }

  /* MinMax: '<S7>/MinMax2' incorporates:
   *  MinMax: '<S7>/MinMax'
   *  MinMax: '<S7>/MinMax1'
   */
  if ((minV <= minV_0) || rtIsNaN(minV_0)) {
    minV_0 = minV;
  }

  /* Gain: '<S7>/Gain' incorporates:
   *  MinMax: '<S7>/MinMax2'
   */
  _rtB->Gain_c = 100.0 * minV_0;

  /* Outport: '<S7>/soh_customer_index' */
  ((real_T *)ssGetOutputPortSignal(S, 4))[0] = _rtB->Gain_c;

  /* Update for Delay: '<S7>/Delay1' incorporates:
   *  Update for Delay: '<S7>/Delay3'
   */
  memcpy(&((real_T *)ssGetDWork(S, 1))[0], &rtb_Sum1[0], 40U * sizeof(real_T));

  /* Update for Delay: '<S7>/Delay3' incorporates:
   *  Update for Delay: '<S7>/Delay1'
   */
  memcpy(&((real_T *)ssGetDWork(S, 2))[0], &rtb_Sum2[0], 40U * sizeof(real_T));
}

/* Termination for function-call system: '<S1>/key_on' */
void soh_key_on_Term(SimStruct *const S)
{
}

/* Start for function-call system: '<S1>/SOH' */
void soh_SOH_Start(SimStruct * const S)
{
  /* InitializeConditions for Enabled SubSystem: '<S4>/SOHRcalc' */
  /* InitializeConditions for Delay: '<S8>/Delay3' */
  ((uint8_T *)ssGetDWork(S, 4))[0] = 1U;

  /* End of InitializeConditions for SubSystem: '<S4>/SOHRcalc' */
}

/* Output and update for function-call system: '<S1>/SOH' */
void soh_SOH(SimStruct * const S)
{
  real_T y;
  boolean_T rtb_RelationalOperator3[40];
  boolean_T rtb_LogicalOperator1[40];
  boolean_T rtb_LogicalOperator5[40];
  real_T rtb_Switch2[40];
  int32_T i;
  real_T rtb_Divide4;
  real_T rtb_Switch;
  real_T rtb_Switch2_o;
  B_soh_T *_rtB;
  PrevZCX_soh_T *_rtZCE;
  _rtZCE = ((PrevZCX_soh_T *) _ssGetPrevZCSigState(S));
  _rtB = ((B_soh_T *) ssGetLocalBlockIO(S));
  for (i = 0; i < 40; i++) {
    /* RelationalOperator: '<S9>/Relational Operator3' incorporates:
     *  Constant: '<S9>/Constant3'
     */
    rtb_RelationalOperator3[i] = (_rtB->deltaCalc.Subtract[i] > 0.0);

    /* RelationalOperator: '<S9>/Relational Operator1' incorporates:
     *  Constant: '<S9>/Constant1'
     */
    rtb_LogicalOperator1[i] = (_rtB->deltaCalc.Subtract1[i] > 0.0);
  }

  /* Logic: '<S9>/Logical Operator5' */
  for (i = 0; i < 40; i++) {
    rtb_LogicalOperator5[i] = (rtb_RelationalOperator3[i] &&
      rtb_LogicalOperator1[0] && rtb_LogicalOperator1[1] &&
      rtb_LogicalOperator1[2] && rtb_LogicalOperator1[3] &&
      rtb_LogicalOperator1[4] && rtb_LogicalOperator1[5] &&
      rtb_LogicalOperator1[6] && rtb_LogicalOperator1[7] &&
      rtb_LogicalOperator1[8] && rtb_LogicalOperator1[9] &&
      rtb_LogicalOperator1[10] && rtb_LogicalOperator1[11] &&
      rtb_LogicalOperator1[12] && rtb_LogicalOperator1[13] &&
      rtb_LogicalOperator1[14] && rtb_LogicalOperator1[15] &&
      rtb_LogicalOperator1[16] && rtb_LogicalOperator1[17] &&
      rtb_LogicalOperator1[18] && rtb_LogicalOperator1[19] &&
      rtb_LogicalOperator1[20] && rtb_LogicalOperator1[21] &&
      rtb_LogicalOperator1[22] && rtb_LogicalOperator1[23] &&
      rtb_LogicalOperator1[24] && rtb_LogicalOperator1[25] &&
      rtb_LogicalOperator1[26] && rtb_LogicalOperator1[27] &&
      rtb_LogicalOperator1[28] && rtb_LogicalOperator1[29] &&
      rtb_LogicalOperator1[30] && rtb_LogicalOperator1[31] &&
      rtb_LogicalOperator1[32] && rtb_LogicalOperator1[33] &&
      rtb_LogicalOperator1[34] && rtb_LogicalOperator1[35] &&
      rtb_LogicalOperator1[36] && rtb_LogicalOperator1[37] &&
      rtb_LogicalOperator1[38] && rtb_LogicalOperator1[39]);
  }

  /* End of Logic: '<S9>/Logical Operator5' */

  /* Logic: '<S9>/Logical Operator1' */
  for (i = 0; i < 40; i++) {
    rtb_LogicalOperator1[i] = !rtb_LogicalOperator1[i];
  }

  /* End of Logic: '<S9>/Logical Operator1' */

  /* Logic: '<S9>/Logical Operator4' incorporates:
   *  Abs: '<S9>/Abs'
   *  Constant: '<S9>/Constant2'
   *  Logic: '<S9>/Logical Operator3'
   *  Logic: '<S9>/Logical Operator6'
   *  Logic: '<S9>/Logical Operator7'
   *  RelationalOperator: '<S9>/Relational Operator2'
   */
  for (i = 0; i < 40; i++) {
    rtb_LogicalOperator5[i] = ((fabs(_rtB->deltaCalc.Subtract[i]) >= (*(real_T *)
      (mxGetData(sohc_current_threshold(S))))) && (rtb_LogicalOperator5[i] || ((
      !rtb_RelationalOperator3[i]) && rtb_LogicalOperator1[0] &&
      rtb_LogicalOperator1[1] && rtb_LogicalOperator1[2] &&
      rtb_LogicalOperator1[3] && rtb_LogicalOperator1[4] &&
      rtb_LogicalOperator1[5] && rtb_LogicalOperator1[6] &&
      rtb_LogicalOperator1[7] && rtb_LogicalOperator1[8] &&
      rtb_LogicalOperator1[9] && rtb_LogicalOperator1[10] &&
      rtb_LogicalOperator1[11] && rtb_LogicalOperator1[12] &&
      rtb_LogicalOperator1[13] && rtb_LogicalOperator1[14] &&
      rtb_LogicalOperator1[15] && rtb_LogicalOperator1[16] &&
      rtb_LogicalOperator1[17] && rtb_LogicalOperator1[18] &&
      rtb_LogicalOperator1[19] && rtb_LogicalOperator1[20] &&
      rtb_LogicalOperator1[21] && rtb_LogicalOperator1[22] &&
      rtb_LogicalOperator1[23] && rtb_LogicalOperator1[24] &&
      rtb_LogicalOperator1[25] && rtb_LogicalOperator1[26] &&
      rtb_LogicalOperator1[27] && rtb_LogicalOperator1[28] &&
      rtb_LogicalOperator1[29] && rtb_LogicalOperator1[30] &&
      rtb_LogicalOperator1[31] && rtb_LogicalOperator1[32] &&
      rtb_LogicalOperator1[33] && rtb_LogicalOperator1[34] &&
      rtb_LogicalOperator1[35] && rtb_LogicalOperator1[36] &&
      rtb_LogicalOperator1[37] && rtb_LogicalOperator1[38] &&
      rtb_LogicalOperator1[39])));
  }

  /* End of Logic: '<S9>/Logical Operator4' */

  /* Outputs for Enabled SubSystem: '<S4>/SOHRcalc' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (rtb_LogicalOperator5[0] || rtb_LogicalOperator5[1] ||
      rtb_LogicalOperator5[2] || rtb_LogicalOperator5[3] ||
      rtb_LogicalOperator5[4] || rtb_LogicalOperator5[5] ||
      rtb_LogicalOperator5[6] || rtb_LogicalOperator5[7] ||
      rtb_LogicalOperator5[8] || rtb_LogicalOperator5[9] ||
      rtb_LogicalOperator5[10] || rtb_LogicalOperator5[11] ||
      rtb_LogicalOperator5[12] || rtb_LogicalOperator5[13] ||
      rtb_LogicalOperator5[14] || rtb_LogicalOperator5[15] ||
      rtb_LogicalOperator5[16] || rtb_LogicalOperator5[17] ||
      rtb_LogicalOperator5[18] || rtb_LogicalOperator5[19] ||
      rtb_LogicalOperator5[20] || rtb_LogicalOperator5[21] ||
      rtb_LogicalOperator5[22] || rtb_LogicalOperator5[23] ||
      rtb_LogicalOperator5[24] || rtb_LogicalOperator5[25] ||
      rtb_LogicalOperator5[26] || rtb_LogicalOperator5[27] ||
      rtb_LogicalOperator5[28] || rtb_LogicalOperator5[29] ||
      rtb_LogicalOperator5[30] || rtb_LogicalOperator5[31] ||
      rtb_LogicalOperator5[32] || rtb_LogicalOperator5[33] ||
      rtb_LogicalOperator5[34] || rtb_LogicalOperator5[35] ||
      rtb_LogicalOperator5[36] || rtb_LogicalOperator5[37] ||
      rtb_LogicalOperator5[38] || rtb_LogicalOperator5[39]) {
    /* Delay: '<S8>/Delay3' */
    if (rt_ZCFcn(RISING_ZERO_CROSSING,&_rtZCE->Delay3_Reset_ZCE,
                 (_rtB->init_keyon_reset)) != NO_ZCEVENT) {
      ((uint8_T *)ssGetDWork(S, 4))[0] = 1U;
    }

    /* Gain: '<S8>/Gain8' */
    y = (*(real_T *)(mxGetData(sohc_pct_R_limit(S)))) / 100.0;
    for (i = 0; i < 40; i++) {
      /* Delay: '<S8>/Delay3' */
      if (((uint8_T *)ssGetDWork(S, 4))[0] != 0) {
        ((real_T *)ssGetDWork(S, 0))[i] = _rtB->init.DataStoreRead1[i];
      }

      /* Product: '<S8>/Divide4' incorporates:
       *  Product: '<S8>/Divide'
       */
      rtb_Divide4 = _rtB->deltaCalc.uDLookupTable1[i] /
        (_rtB->deltaCalc.Subtract1[i] / _rtB->deltaCalc.Subtract[i]);

      /* Gain: '<S8>/Gain8' incorporates:
       *  Delay: '<S8>/Delay3'
       */
      rtb_Switch = y * ((real_T *)ssGetDWork(S, 0))[i];

      /* Sum: '<S8>/Sum4' incorporates:
       *  Delay: '<S8>/Delay3'
       */
      rtb_Switch2_o = rtb_Switch + ((real_T *)ssGetDWork(S, 0))[i];

      /* Sum: '<S8>/Sum3' incorporates:
       *  Delay: '<S8>/Delay3'
       */
      rtb_Switch = ((real_T *)ssGetDWork(S, 0))[i] - rtb_Switch;

      /* Switch: '<S10>/Switch' incorporates:
       *  RelationalOperator: '<S10>/UpperRelop'
       */
      if (!(rtb_Divide4 < rtb_Switch)) {
        rtb_Switch = rtb_Divide4;
      }

      /* End of Switch: '<S10>/Switch' */

      /* Switch: '<S10>/Switch2' incorporates:
       *  RelationalOperator: '<S10>/LowerRelop1'
       */
      if (!(rtb_Divide4 > rtb_Switch2_o)) {
        rtb_Switch2_o = rtb_Switch;
      }

      /* End of Switch: '<S10>/Switch2' */

      /* Sum: '<S8>/Sum2' incorporates:
       *  Delay: '<S8>/Delay3'
       *  Gain: '<S8>/Gain6'
       *  Gain: '<S8>/Gain7'
       */
      rtb_Switch2_o = (1.0 - (*(real_T *)(mxGetData(sohc_filter_coeff(S))))) *
        rtb_Switch2_o + (*(real_T *)(mxGetData(sohc_filter_coeff(S)))) *
        ((real_T *)ssGetDWork(S, 0))[i];

      /* Saturate: '<S8>/Saturation' */
      if (rtb_Switch2_o > 1.0) {
        _rtB->Saturation[i] = 1.0;
      } else if (rtb_Switch2_o < 0.0) {
        _rtB->Saturation[i] = 0.0;
      } else {
        _rtB->Saturation[i] = rtb_Switch2_o;
      }

      /* End of Saturate: '<S8>/Saturation' */

      /* Sum: '<S8>/Sum4' */
      rtb_Switch2[i] = rtb_Switch2_o;
    }

    /* MinMax: '<S8>/MinMax' */
    y = _rtB->Saturation[0];
    for (i = 0; i < 39; i++) {
      if (!((y <= _rtB->Saturation[i + 1]) || rtIsNaN(_rtB->Saturation[i + 1])))
      {
        y = _rtB->Saturation[i + 1];
      }
    }

    /* Gain: '<S8>/Gain3' incorporates:
     *  MinMax: '<S8>/MinMax'
     */
    _rtB->Gain3_p = 100.0 * y;
  }

  /* End of Outputs for SubSystem: '<S4>/SOHRcalc' */

  /* Gain: '<S4>/Gain' incorporates:
   *  Inport: '<Root>/soc_C_factors'
   */
  memcpy(&_rtB->Gain[0], ((const real_T **)ssGetInputPortSignalPtrs(S, 6))[0],
         40U * sizeof(real_T));

  /* MinMax: '<S4>/MinMax' */
  y = _rtB->Gain[0];
  for (i = 0; i < 39; i++) {
    if (!((y <= _rtB->Gain[i + 1]) || rtIsNaN(_rtB->Gain[i + 1]))) {
      y = _rtB->Gain[i + 1];
    }
  }

  /* Saturate: '<S4>/Saturation' incorporates:
   *  MinMax: '<S4>/MinMax'
   */
  if (y > 1.0) {
    y = 1.0;
  } else {
    if (y < 0.0) {
      y = 0.0;
    }
  }

  /* Gain: '<S4>/Gain3' incorporates:
   *  Saturate: '<S4>/Saturation'
   */
  _rtB->Gain3 = 100.0 * y;

  /* Outport: '<Root>/soh_R_index' incorporates:
   *  Outport: '<S4>/soh_R_index'
   */
  ((real_T *)ssGetOutputPortSignal(S, 0))[0] = _rtB->Gain3_p;

  /* Outport: '<S4>/soh_C_index' */
  ((real_T *)ssGetOutputPortSignal(S, 2))[0] = _rtB->Gain3;

  /* Outport: '<Root>/soh_R_factors' incorporates:
   *  Outport: '<S4>/soh_C_factors'
   *  Outport: '<S4>/soh_R_factor'
   */
  memcpy(&((real_T *)ssGetOutputPortSignal(S, 1))[0], &_rtB->Saturation[0], 40U *
         sizeof(real_T));

  /* Outport: '<S4>/soh_C_factors' incorporates:
   *  Outport: '<Root>/soh_R_factors'
   *  Outport: '<S4>/soh_R_factor'
   */
  memcpy(&((real_T *)ssGetOutputPortSignal(S, 3))[0], &_rtB->Gain[0], 40U *
         sizeof(real_T));

  /* Update for Enabled SubSystem: '<S4>/SOHRcalc' incorporates:
   *  Update for EnablePort: '<S8>/Enable'
   */
  if (rtb_LogicalOperator5[0] || rtb_LogicalOperator5[1] ||
      rtb_LogicalOperator5[2] || rtb_LogicalOperator5[3] ||
      rtb_LogicalOperator5[4] || rtb_LogicalOperator5[5] ||
      rtb_LogicalOperator5[6] || rtb_LogicalOperator5[7] ||
      rtb_LogicalOperator5[8] || rtb_LogicalOperator5[9] ||
      rtb_LogicalOperator5[10] || rtb_LogicalOperator5[11] ||
      rtb_LogicalOperator5[12] || rtb_LogicalOperator5[13] ||
      rtb_LogicalOperator5[14] || rtb_LogicalOperator5[15] ||
      rtb_LogicalOperator5[16] || rtb_LogicalOperator5[17] ||
      rtb_LogicalOperator5[18] || rtb_LogicalOperator5[19] ||
      rtb_LogicalOperator5[20] || rtb_LogicalOperator5[21] ||
      rtb_LogicalOperator5[22] || rtb_LogicalOperator5[23] ||
      rtb_LogicalOperator5[24] || rtb_LogicalOperator5[25] ||
      rtb_LogicalOperator5[26] || rtb_LogicalOperator5[27] ||
      rtb_LogicalOperator5[28] || rtb_LogicalOperator5[29] ||
      rtb_LogicalOperator5[30] || rtb_LogicalOperator5[31] ||
      rtb_LogicalOperator5[32] || rtb_LogicalOperator5[33] ||
      rtb_LogicalOperator5[34] || rtb_LogicalOperator5[35] ||
      rtb_LogicalOperator5[36] || rtb_LogicalOperator5[37] ||
      rtb_LogicalOperator5[38] || rtb_LogicalOperator5[39]) {
    /* Update for Delay: '<S8>/Delay3' */
    ((uint8_T *)ssGetDWork(S, 4))[0] = 0U;
    memcpy(&((real_T *)ssGetDWork(S, 0))[0], &rtb_Switch2[0], 40U * sizeof
           (real_T));
  }

  /* End of Update for SubSystem: '<S4>/SOHRcalc' */
}

/* Termination for function-call system: '<S1>/SOH' */
void soh_SOH_Term(SimStruct *const S)
{
}

/* Initial conditions for root system: '<Root>' */
#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  /* InitializeConditions for Atomic SubSystem: '<Root>/soh' */
  /* InitializeConditions for Chart: '<S1>/Chart' */
  ((uint8_T *)ssGetDWork(S, 6))[0] = 0U;
  ((uint8_T *)ssGetDWork(S, 5))[0] = soh_IN_NO_ACTIVE_CHILD;
  if (ssIsFirstInitCond(S)) {
    /* InitializeConditions for Function Call SubSystem: '<S1>/deltaCalc' */
    soh_deltaCalc_Init(S);

    /* End of InitializeConditions for SubSystem: '<S1>/deltaCalc' */

    /* InitializeConditions for Function Call SubSystem: '<S1>/key_on' */
    soh_key_on_Init(S);

    /* End of InitializeConditions for SubSystem: '<S1>/key_on' */
  }

  /* End of InitializeConditions for Chart: '<S1>/Chart' */
  /* End of InitializeConditions for SubSystem: '<Root>/soh' */
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

  soh_malloc(S);
  if (ssGetErrorStatus(S) != (NULL) ) {
    return;
  }

#endif

  {
    /* Start for Atomic SubSystem: '<Root>/soh' */
    /* Start for Chart: '<S1>/Chart' incorporates:
     *  Start for SubSystem: '<S1>/SOH'
     */
    soh_SOH_Start(S);

    /* Start for DataStoreMemory: '<S1>/Data Store Memory1' */
    memcpy(&((real_T *)ssGetDWork(S, 3))[0], ((real_T *)mxGetData
            (sohv_factoryInit_sohr(S))), 40U * sizeof(real_T));

    /* End of Start for SubSystem: '<Root>/soh' */

    /* Previous zero-crossing state intialization */
    {
      PrevZCX_soh_T *_rtZCE;
      _rtZCE = ((PrevZCX_soh_T *) _ssGetPrevZCSigState(S));
      _rtZCE->Delay3_Reset_ZCE = UNINITIALIZED_ZCSIG;
    }
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  boolean_T rtb_LogicalOperator;
  B_soh_T *_rtB;
  _rtB = ((B_soh_T *) ssGetLocalBlockIO(S));

  /* Outputs for Atomic SubSystem: '<Root>/soh' */
  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Inport: '<Root>/charger_contactor'
   *  Inport: '<Root>/main_contactor'
   */
  rtb_LogicalOperator = ((*((const boolean_T **)ssGetInputPortSignalPtrs(S, 7))
    [0]) || (*((const boolean_T **)ssGetInputPortSignalPtrs(S, 8))[0]));

  /* Chart: '<S1>/Chart' incorporates:
   *  Inport: '<Root>/Cell SOC'
   *  Inport: '<Root>/Cell Temp'
   *  Inport: '<Root>/Cell Voltages'
   *  Inport: '<Root>/Pack Current'
   *  Inport: '<Root>/cb_cmds'
   *  Inport: '<Root>/pre_chg_contactor'
   *  Inport: '<Root>/soc_C_factors'
   */
  /* Gateway: soh/Chart */
  /* During: soh/Chart */
  if (((uint8_T *)ssGetDWork(S, 6))[0] == 0U) {
    /* Entry: soh/Chart */
    ((uint8_T *)ssGetDWork(S, 6))[0] = 1U;

    /* Entry Internal: soh/Chart */
    /* Transition: '<S2>:68' */
    ((uint8_T *)ssGetDWork(S, 5))[0] = soh_IN_key_ON;

    /* Entry 'key_ON': '<S2>:14' */
    _rtB->init_keyon_reset = 1.0;

    /* Outputs for Function Call SubSystem: '<S1>/init' */

    /* Entry Internal 'key_ON': '<S2>:14' */
    /* Transition: '<S2>:64' */
    /* Transition: '<S2>:63' */
    /* Event: '<S2>:50' */
    soh_init(((const real_T **)ssGetInputPortSignalPtrs(S, 6))[0], &_rtB->init,
             &((real_T *)ssGetDWork(S, 3))[0]);

    /* End of Outputs for SubSystem: '<S1>/init' */

    /* Outputs for Function Call SubSystem: '<S1>/key_on' */

    /* Transition: '<S2>:32' */
    /* Event: '<S2>:52' */
    soh_key_on(S);

    /* End of Outputs for SubSystem: '<S1>/key_on' */

    /* Outputs for Function Call SubSystem: '<S1>/deltaCalc' */

    /* Transition: '<S2>:38' */
    /* Event: '<S2>:51' */
    soh_deltaCalc(S, *((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0], ((
      const real_T **)ssGetInputPortSignalPtrs(S, 3))[0], ((const real_T **)
      ssGetInputPortSignalPtrs(S, 4))[0], ((const real_T **)
      ssGetInputPortSignalPtrs(S, 5))[0], ((const boolean_T **)
      ssGetInputPortSignalPtrs(S, 10))[0], &_rtB->deltaCalc);

    /* End of Outputs for SubSystem: '<S1>/deltaCalc' */

    /* Outputs for Function Call SubSystem: '<S1>/SOH' */

    /* Transition: '<S2>:62' */
    /* Event: '<S2>:53' */
    soh_SOH(S);

    /* End of Outputs for SubSystem: '<S1>/SOH' */
  } else {
    switch (((uint8_T *)ssGetDWork(S, 5))[0]) {
     case soh_IN_dataStore:
      /* During 'dataStore': '<S2>:16' */
      /* Transition: '<S2>:70' */
      ((uint8_T *)ssGetDWork(S, 5))[0] = soh_IN_end;

      /* Entry 'end': '<S2>:69' */
      break;

     case soh_IN_end:
      /* During 'end': '<S2>:69' */
      if ((*((const boolean_T **)ssGetInputPortSignalPtrs(S, 9))[0]) ||
          rtb_LogicalOperator) {
        /* Transition: '<S2>:26' */
        ((uint8_T *)ssGetDWork(S, 5))[0] = soh_IN_key_ON;

        /* Entry 'key_ON': '<S2>:14' */
        _rtB->init_keyon_reset = 1.0;

        /* Outputs for Function Call SubSystem: '<S1>/init' */

        /* Entry Internal 'key_ON': '<S2>:14' */
        /* Transition: '<S2>:64' */
        /* Transition: '<S2>:63' */
        /* Event: '<S2>:50' */
        soh_init(((const real_T **)ssGetInputPortSignalPtrs(S, 6))[0],
                 &_rtB->init, &((real_T *)ssGetDWork(S, 3))[0]);

        /* End of Outputs for SubSystem: '<S1>/init' */

        /* Outputs for Function Call SubSystem: '<S1>/key_on' */

        /* Transition: '<S2>:32' */
        /* Event: '<S2>:52' */
        soh_key_on(S);

        /* End of Outputs for SubSystem: '<S1>/key_on' */

        /* Outputs for Function Call SubSystem: '<S1>/deltaCalc' */

        /* Transition: '<S2>:38' */
        /* Event: '<S2>:51' */
        soh_deltaCalc(S, *((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0],
                      ((const real_T **)ssGetInputPortSignalPtrs(S, 3))[0], ((
          const real_T **)ssGetInputPortSignalPtrs(S, 4))[0], ((const real_T **)
          ssGetInputPortSignalPtrs(S, 5))[0], ((const boolean_T **)
          ssGetInputPortSignalPtrs(S, 10))[0], &_rtB->deltaCalc);

        /* End of Outputs for SubSystem: '<S1>/deltaCalc' */

        /* Outputs for Function Call SubSystem: '<S1>/SOH' */

        /* Transition: '<S2>:62' */
        /* Event: '<S2>:53' */
        soh_SOH(S);

        /* End of Outputs for SubSystem: '<S1>/SOH' */
      }
      break;

     case soh_IN_key_ON:
      /* During 'key_ON': '<S2>:14' */
      if ((*((const boolean_T **)ssGetInputPortSignalPtrs(S, 9))[0]) ||
          rtb_LogicalOperator) {
        /* Transition: '<S2>:9' */
        ((uint8_T *)ssGetDWork(S, 5))[0] = soh_IN_sohr;

        /* Entry 'sohr': '<S2>:7' */
        _rtB->init_keyon_reset = 0.0;

        /* Outputs for Function Call SubSystem: '<S1>/deltaCalc' */

        /* Entry Internal 'sohr': '<S2>:7' */
        /* Transition: '<S2>:19' */
        /* Transition: '<S2>:15' */
        /* Event: '<S2>:51' */
        soh_deltaCalc(S, *((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0],
                      ((const real_T **)ssGetInputPortSignalPtrs(S, 3))[0], ((
          const real_T **)ssGetInputPortSignalPtrs(S, 4))[0], ((const real_T **)
          ssGetInputPortSignalPtrs(S, 5))[0], ((const boolean_T **)
          ssGetInputPortSignalPtrs(S, 10))[0], &_rtB->deltaCalc);

        /* End of Outputs for SubSystem: '<S1>/deltaCalc' */

        /* Outputs for Function Call SubSystem: '<S1>/SOH' */

        /* Transition: '<S2>:40' */
        /* Event: '<S2>:53' */
        soh_SOH(S);

        /* End of Outputs for SubSystem: '<S1>/SOH' */
      } else {
        /* Outputs for Function Call SubSystem: '<S1>/init' */

        /* Transition: '<S2>:64' */
        /* Transition: '<S2>:63' */
        /* Event: '<S2>:50' */
        soh_init(((const real_T **)ssGetInputPortSignalPtrs(S, 6))[0],
                 &_rtB->init, &((real_T *)ssGetDWork(S, 3))[0]);

        /* End of Outputs for SubSystem: '<S1>/init' */

        /* Outputs for Function Call SubSystem: '<S1>/key_on' */

        /* Transition: '<S2>:32' */
        /* Event: '<S2>:52' */
        soh_key_on(S);

        /* End of Outputs for SubSystem: '<S1>/key_on' */

        /* Outputs for Function Call SubSystem: '<S1>/deltaCalc' */

        /* Transition: '<S2>:38' */
        /* Event: '<S2>:51' */
        soh_deltaCalc(S, *((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0],
                      ((const real_T **)ssGetInputPortSignalPtrs(S, 3))[0], ((
          const real_T **)ssGetInputPortSignalPtrs(S, 4))[0], ((const real_T **)
          ssGetInputPortSignalPtrs(S, 5))[0], ((const boolean_T **)
          ssGetInputPortSignalPtrs(S, 10))[0], &_rtB->deltaCalc);

        /* End of Outputs for SubSystem: '<S1>/deltaCalc' */

        /* Outputs for Function Call SubSystem: '<S1>/SOH' */

        /* Transition: '<S2>:62' */
        /* Event: '<S2>:53' */
        soh_SOH(S);

        /* End of Outputs for SubSystem: '<S1>/SOH' */
      }
      break;

     default:
      /* During 'sohr': '<S2>:7' */
      if ((!rtb_LogicalOperator) && (!*((const boolean_T **)
            ssGetInputPortSignalPtrs(S, 9))[0])) {
        /* Transition: '<S2>:34' */
        ((uint8_T *)ssGetDWork(S, 5))[0] = soh_IN_dataStore;

        /* Entry 'dataStore': '<S2>:16' */
        _rtB->init_keyon_reset = 0.0;

        /* Outputs for Function Call SubSystem: '<S1>/DataStore' */
        /* DataStoreWrite: '<S3>/Data Store Write1' */
        /* Entry Internal 'dataStore': '<S2>:16' */
        /* Transition: '<S2>:43' */
        /* Transition: '<S2>:44' */
        /* Event: '<S2>:54' */
        memcpy(&((real_T *)ssGetDWork(S, 3))[0], &_rtB->Saturation[0], 40U *
               sizeof(real_T));

        /* End of Outputs for SubSystem: '<S1>/DataStore' */
      } else {
        /* Outputs for Function Call SubSystem: '<S1>/deltaCalc' */

        /* Transition: '<S2>:19' */
        /* Transition: '<S2>:15' */
        /* Event: '<S2>:51' */
        soh_deltaCalc(S, *((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0],
                      ((const real_T **)ssGetInputPortSignalPtrs(S, 3))[0], ((
          const real_T **)ssGetInputPortSignalPtrs(S, 4))[0], ((const real_T **)
          ssGetInputPortSignalPtrs(S, 5))[0], ((const boolean_T **)
          ssGetInputPortSignalPtrs(S, 10))[0], &_rtB->deltaCalc);

        /* End of Outputs for SubSystem: '<S1>/deltaCalc' */

        /* Outputs for Function Call SubSystem: '<S1>/SOH' */

        /* Transition: '<S2>:40' */
        /* Event: '<S2>:53' */
        soh_SOH(S);

        /* End of Outputs for SubSystem: '<S1>/SOH' */
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */
  /* End of Outputs for SubSystem: '<Root>/soh' */

  /* Outport: '<Root>/soh_R_index' */
  ((real_T *)ssGetOutputPortSignal(S, 0))[0] = _rtB->Gain3_p;

  /* Outport: '<Root>/soh_R_factors' */
  memcpy(&((real_T *)ssGetOutputPortSignal(S, 1))[0], &_rtB->Saturation[0], 40U *
         sizeof(real_T));
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
  /* Parameter check for 'bmsc_InternalDischgResistX' */
  if (mxIsComplex(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalDischgResistX' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalDischgResistX' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 0)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[1] != 3) ) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalDischgResistX' has to be a [1x3] array.");
    return;
  }

  /* Parameter check for 'bmsc_InternalDischgResistY' */
  if (mxIsComplex(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalDischgResistY' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalDischgResistY' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 1)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[1] != 101) ) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalDischgResistY' has to be a [1x101] array.");
    return;
  }

  /* Parameter check for 'bmsc_InternalDischgResistZ' */
  if (mxIsComplex(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalDischgResistZ' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalDischgResistZ' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 2)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[0] != 3) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[1] != 101) ) {
    ssSetErrorStatus(S,
                     "Parameter 'bmsc_InternalDischgResistZ' has to be a [3x101] array.");
    return;
  }

  /* Parameter check for 'sohc_current_threshold' */
  if (mxIsComplex(ssGetSFcnParam(S, 3))) {
    ssSetErrorStatus(S,
                     "Parameter 'sohc_current_threshold' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 3))) {
    ssSetErrorStatus(S,
                     "Parameter 'sohc_current_threshold' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 3)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 3))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 3))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'sohc_current_threshold' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'sohc_customer_filter_coeff' */
  if (mxIsComplex(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,
                     "Parameter 'sohc_customer_filter_coeff' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,
                     "Parameter 'sohc_customer_filter_coeff' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 4)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'sohc_customer_filter_coeff' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'sohc_filter_coeff' */
  if (mxIsComplex(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,
                     "Parameter 'sohc_filter_coeff' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,"Parameter 'sohc_filter_coeff' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 5)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'sohc_filter_coeff' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'sohc_pct_R_limit' */
  if (mxIsComplex(ssGetSFcnParam(S, 6))) {
    ssSetErrorStatus(S,
                     "Parameter 'sohc_pct_R_limit' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 6))) {
    ssSetErrorStatus(S,"Parameter 'sohc_pct_R_limit' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 6)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 6))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 6))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'sohc_pct_R_limit' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'sohk_CellBalancingResistor' */
  if (mxIsComplex(ssGetSFcnParam(S, 7))) {
    ssSetErrorStatus(S,
                     "Parameter 'sohk_CellBalancingResistor' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 7))) {
    ssSetErrorStatus(S,
                     "Parameter 'sohk_CellBalancingResistor' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 7)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 7))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 7))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'sohk_CellBalancingResistor' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'sohv_factoryInit_sohc' */
  if (mxIsComplex(ssGetSFcnParam(S, 8))) {
    ssSetErrorStatus(S,
                     "Parameter 'sohv_factoryInit_sohc' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 8))) {
    ssSetErrorStatus(S,
                     "Parameter 'sohv_factoryInit_sohc' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 8)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 8))[0] != 40) ||
      (mxGetDimensions(ssGetSFcnParam(S, 8))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'sohv_factoryInit_sohc' has to be a [40x1] array.");
    return;
  }

  /* Parameter check for 'sohv_factoryInit_sohr' */
  if (mxIsComplex(ssGetSFcnParam(S, 9))) {
    ssSetErrorStatus(S,
                     "Parameter 'sohv_factoryInit_sohr' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 9))) {
    ssSetErrorStatus(S,
                     "Parameter 'sohv_factoryInit_sohr' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 9)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 9))[0] != 40) ||
      (mxGetDimensions(ssGetSFcnParam(S, 9))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'sohv_factoryInit_sohr' has to be a [40x1] array.");
    return;
  }
}

#endif                                 /* MDL_CHECK_PARAMETERS */

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "soh_mid.h"
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
  if (!ssSetOutputPortVectorDimension(S, 1, 40))
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
  if (!ssSetOutputPortVectorDimension(S, 3, 40))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 3, SS_DOUBLE);
  }

  ssSetOutputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);

  /* outport number: 4 */
  if (!ssSetOutputPortVectorDimension(S, 4, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 4, SS_DOUBLE);
  }

  ssSetOutputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 11))
    return;

  /* inport number: 0 */
  {
    if (!ssSetInputPortVectorDimension(S, 0, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 0, SS_BOOLEAN);
    }

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
    if (!ssSetInputPortVectorDimension(S, 3, 40))
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
    if (!ssSetInputPortVectorDimension(S, 4, 40))
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
    if (!ssSetInputPortVectorDimension(S, 5, 40))
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
      ssSetInputPortDataType(S, 7, SS_BOOLEAN);
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
      ssSetInputPortDataType(S, 8, SS_BOOLEAN);
    }

    ssSetInputPortDirectFeedThrough(S, 8, 1);
    ssSetInputPortOverWritable(S, 8, 0);
    ssSetInputPortOptimOpts(S, 8, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 9 */
  {
    if (!ssSetInputPortVectorDimension(S, 9, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 9, SS_BOOLEAN);
    }

    ssSetInputPortDirectFeedThrough(S, 9, 1);
    ssSetInputPortOverWritable(S, 9, 0);
    ssSetInputPortOptimOpts(S, 9, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 10 */
  {
    if (!ssSetInputPortVectorDimension(S, 10, 40))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 10, SS_BOOLEAN);
    }

    ssSetInputPortDirectFeedThrough(S, 10, 1);
    ssSetInputPortOverWritable(S, 10, 0);
    ssSetInputPortOptimOpts(S, 10, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 9)) {
    return;
  }

  /* '<S8>/Delay3': DSTATE */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 40);
  ssSetDWorkUsedAsDState(S, 0, 1);

  /* '<S7>/Delay1': DSTATE */
  ssSetDWorkName(S, 1, "DWORK1");
  ssSetDWorkWidth(S, 1, 40);
  ssSetDWorkUsedAsDState(S, 1, 1);

  /* '<S7>/Delay3': DSTATE */
  ssSetDWorkName(S, 2, "DWORK2");
  ssSetDWorkWidth(S, 2, 40);
  ssSetDWorkUsedAsDState(S, 2, 1);

  /* '<S1>/Data Store Memory1': dsmMem */
  ssSetDWorkName(S, 3, "DWORK3");
  ssSetDWorkWidth(S, 3, 40);

  /* '<S8>/Delay3': icLoad */
  ssSetDWorkName(S, 4, "DWORK4");
  ssSetDWorkWidth(S, 4, 1);
  ssSetDWorkDataType(S, 4, SS_UINT8);

  /* '<S1>/Chart': DWORK2 */
  ssSetDWorkName(S, 5, "DWORK5");
  ssSetDWorkWidth(S, 5, 1);
  ssSetDWorkDataType(S, 5, SS_UINT8);

  /* '<S1>/Chart': DWORK1 */
  ssSetDWorkName(S, 6, "DWORK6");
  ssSetDWorkWidth(S, 6, 1);
  ssSetDWorkDataType(S, 6, SS_UINT8);

  /* '<S5>/Delay2': DSTATE */
  ssSetDWorkName(S, 7, "DWORK7");
  ssSetDWorkWidth(S, 7, 40);
  ssSetDWorkUsedAsDState(S, 7, 1);

  /* '<S5>/Delay3': DSTATE */
  ssSetDWorkName(S, 8, "DWORK8");
  ssSetDWorkWidth(S, 8, 40);
  ssSetDWorkUsedAsDState(S, 8, 1);

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 10);

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
      "<diag_root><diag id=\"Simulink:blocks:BlockDoesNotSupportMultiExecInstances\"><arguments><arg type=\"encoded\">cwBvAGgALwBzAG8AaAAvAGkAbgBpAHQALwBEAGEAdABhACAAUwB0AG8AcgBlACAAUgBlAGEAZAAxAAAA</arg><arg type=\"encoded\">PABfAF8AaQBpAFMAUwBfAF8APgA8AC8AXwBfAGkAaQBTAFMAXwBfAD4AAAA=</arg><arg type=\"encoded\">PABfAF8AaQB0AGUAcgBCAGwAawBfAF8APgA8AC8AXwBfAGkAdABlAHIAQgBsAGsAXwBfAD4AAAA=</arg></arguments></diag>\n</diag_root>");
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
# define S_FUNCTION_NAME               soh_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
