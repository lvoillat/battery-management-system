/*
 * SOC_codegen.c
 *
 * Code generation for model "SOC_codegen".
 *
 * Model version              : 13.10
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Fri Jan 28 16:04:26 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SOC_codegen.h"
#include "SOC_codegen_private.h"

/* Named constants for Chart: '<S1>/Chart' */
#define SOC_codegen_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define SOC_codegen_IN_coulomb_counting ((uint8_T)1U)
#define SOC_codegen_IN_dataStore       ((uint8_T)2U)
#define SOC_codegen_IN_end             ((uint8_T)3U)
#define SOC_codegen_IN_init            ((uint8_T)4U)
#define SOC_codegen_IN_key_ON          ((uint8_T)5U)

/* Block signals (default storage) */
B_SOC_codegen_T SOC_codegen_B;

/* Block states (default storage) */
DW_SOC_codegen_T SOC_codegen_DW;

/* External inputs (root inport signals with default storage) */
ExtU_SOC_codegen_T SOC_codegen_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_SOC_codegen_T SOC_codegen_Y;

/* Real-time model */
static RT_MODEL_SOC_codegen_T SOC_codegen_M_;
RT_MODEL_SOC_codegen_T *const SOC_codegen_M = &SOC_codegen_M_;
uint32_T plook_evenc(real_T u, real_T bp0, real_T bpSpace, uint32_T maxIndex,
                     real_T *fraction)
{
  real_T fbpIndex;
  real_T invSpc;
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'even'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp0) {
    bpIndex = 0U;
    *fraction = 0.0;
  } else {
    invSpc = 1.0 / bpSpace;
    fbpIndex = (u - bp0) * invSpc;
    if (fbpIndex < maxIndex) {
      bpIndex = (uint32_T)fbpIndex;
      *fraction = (u - ((real_T)(uint32_T)fbpIndex * bpSpace + bp0)) * invSpc;
    } else {
      bpIndex = maxIndex - 1U;
      *fraction = 1.0;
    }
  }

  return bpIndex;
}

real_T intrp1d_l_pw(uint32_T bpIndex, real_T frac, const real_T table[])
{
  real_T yL_0d0;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[bpIndex];
  return (table[bpIndex + 1U] - yL_0d0) * frac + yL_0d0;
}

real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
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

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

/* Output and update for function-call system: '<S1>/Init' */
void SOC_codegen_Init(const real_T rtu_cell_voltages[40], real_T
                      rty_soc_cells_pct[40], real_T *rty_cc_integration_reset)
{
  real_T frac;
  int32_T iU;
  uint32_T bpIdx;

  /* Lookup_n-D: '<S6>/OCV - SOC Lookup' */
  for (iU = 0; iU < 40; iU++) {
    bpIdx = plook_evenc(rtu_cell_voltages[iU], 2.7, 0.0099999999999997868, 150U,
                        &frac);
    rty_soc_cells_pct[iU] = intrp1d_l_pw(bpIdx, frac,
      SOC_codegen_ConstInitP.pooled1);
  }

  /* End of Lookup_n-D: '<S6>/OCV - SOC Lookup' */

  /* SignalConversion generated from: '<S6>/cc_integration_reset' incorporates:
   *  Constant: '<S6>/Constant'
   */
  *rty_cc_integration_reset = 0.0;
}

/* System initialize for function-call system: '<S8>/Subsystem' */
void SOC_codegen_Subsystem_Init(B_Subsystem_SOC_codegen_T *localB)
{
  /* SystemInitialize for Switch: '<S11>/Switch1' incorporates:
   *  Outport: '<S11>/cc_integration_reset'
   */
  localB->Switch1 = 0.0;

  /* SystemInitialize for Switch: '<S11>/Switch' incorporates:
   *  Outport: '<S11>/soc_cells_pct'
   */
  memset(&localB->Switch[0], 0, 40U * sizeof(real_T));

  /* SystemInitialize for Lookup_n-D: '<S11>/OCV - SOC Lookup' incorporates:
   *  Outport: '<S11>/keyON_ocvsoc'
   */
  memset(&localB->OCVSOCLookup[0], 0, 40U * sizeof(real_T));
}

/* Output and update for function-call system: '<S8>/Subsystem' */
void SOC_codegen_Subsystem(const real_T rtu_cell_voltages[40], const real_T
  rtd_CCounting_soc_store[40], B_Subsystem_SOC_codegen_T *localB)
{
  real_T rtb_Abs[40];
  real_T frac;
  real_T u1;
  int32_T i;
  uint32_T bpIdx;
  boolean_T rtb_RelationalOperator3;

  /* Lookup_n-D: '<S11>/OCV - SOC Lookup' */
  for (i = 0; i < 40; i++) {
    bpIdx = plook_evenc(rtu_cell_voltages[i], 2.7, 0.0099999999999997868, 150U,
                        &frac);
    localB->OCVSOCLookup[i] = intrp1d_l_pw(bpIdx, frac,
      SOC_codegen_ConstInitP.pooled1);
  }

  /* End of Lookup_n-D: '<S11>/OCV - SOC Lookup' */

  /* Abs: '<S11>/Abs' incorporates:
   *  DataStoreRead: '<S11>/Data Store Read'
   *  Sum: '<S11>/Subtract'
   */
  for (i = 0; i < 40; i++) {
    rtb_Abs[i] = fabs(localB->OCVSOCLookup[i] - rtd_CCounting_soc_store[i]);
  }

  /* End of Abs: '<S11>/Abs' */

  /* MinMax: '<S11>/max' */
  frac = rtb_Abs[0];
  for (i = 0; i < 39; i++) {
    u1 = rtb_Abs[i + 1];
    if ((!(frac >= u1)) && (!rtIsNaN(u1))) {
      frac = u1;
    }
  }

  /* RelationalOperator: '<S11>/Relational Operator3' incorporates:
   *  Constant: '<S11>/soc_diff_threshold'
   *  MinMax: '<S11>/max'
   */
  rtb_RelationalOperator3 = (frac >= 1.0);

  /* Switch: '<S11>/Switch' */
  if (rtb_RelationalOperator3) {
    /* Switch: '<S11>/Switch' */
    memcpy(&localB->Switch[0], &localB->OCVSOCLookup[0], 40U * sizeof(real_T));
  } else {
    /* Switch: '<S11>/Switch' incorporates:
     *  DataStoreRead: '<S11>/Data Store Read'
     */
    memcpy(&localB->Switch[0], &rtd_CCounting_soc_store[0], 40U * sizeof(real_T));
  }

  /* End of Switch: '<S11>/Switch' */

  /* Switch: '<S11>/Switch1' */
  if (rtb_RelationalOperator3) {
    /* Switch: '<S11>/Switch1' */
    localB->Switch1 = 1.0;
  } else {
    /* Switch: '<S11>/Switch1' incorporates:
     *  Constant: '<S11>/Constant'
     */
    localB->Switch1 = 0.0;
  }

  /* End of Switch: '<S11>/Switch1' */
}

/* System initialize for function-call system: '<S8>/CdegradeCalc' */
void SOC_codegen_CdegradeCalc_Init(B_CdegradeCalc_SOC_codegen_T *localB,
  DW_CdegradeCalc_SOC_codegen_T *localDW)
{
  int32_T i;

  /* InitializeConditions for Delay: '<S9>/Delay' */
  localDW->icLoad = true;
  for (i = 0; i < 40; i++) {
    /* SystemInitialize for Sum: '<S9>/Sum' incorporates:
     *  Outport: '<S9>/Out1'
     */
    localB->Sum[i] = 1.0;
  }
}

/* Output and update for function-call system: '<S8>/CdegradeCalc' */
void SOC_codegen_CdegradeCalc(const real_T rtu_keyON_ocvsoc[40], const real_T
  rtu_lastChgInitsoc[40], const real_T rtu_lastChgCCsoc[40], const real_T
  rtu_soh_C_factors[40], B_CdegradeCalc_SOC_codegen_T *localB,
  DW_CdegradeCalc_SOC_codegen_T *localDW)
{
  int32_T i;
  for (i = 0; i < 40; i++) {
    /* Delay: '<S9>/Delay' */
    if (localDW->icLoad) {
      localDW->Delay_DSTATE[i] = 1.0;
    }

    /* Sum: '<S9>/Sum' incorporates:
     *  Delay: '<S9>/Delay'
     *  Gain: '<S9>/Gain1'
     *  Product: '<S9>/Divide'
     *  Product: '<S9>/Mul'
     *  Sum: '<S9>/Subtract'
     *  Sum: '<S9>/Subtract1'
     */
    localB->Sum[i] = (rtu_lastChgCCsoc[i] - rtu_lastChgInitsoc[i]) /
      (rtu_keyON_ocvsoc[i] - rtu_lastChgInitsoc[i]) * rtu_soh_C_factors[i] + 0.0
      * localDW->Delay_DSTATE[i];

    /* Update for Delay: '<S9>/Delay' */
    localDW->Delay_DSTATE[i] = localB->Sum[i];
  }

  /* Update for Delay: '<S9>/Delay' */
  localDW->icLoad = false;
}

/* Output and update for function-call system: '<S8>/saveChgInitSoc' */
void SOC_codegen_saveChgInitSoc(const real_T rtu_keyON_ocvsoc[40], real_T
  rtd_charging_initial_soc[40])
{
  /* DataStoreWrite: '<S13>/Data Store Write' */
  memcpy(&rtd_charging_initial_soc[0], &rtu_keyON_ocvsoc[0], 40U * sizeof(real_T));
}

/* Output and update for function-call system: '<S8>/lastCycleUpdate' */
void SOC_codegen_lastCycleUpdate(boolean_T rtu_chargingC, real_T
  *rtd_last_cycle_charging)
{
  /* DataStoreWrite: '<S12>/Data Store Write' incorporates:
   *  Switch: '<S12>/Switch'
   */
  *rtd_last_cycle_charging = rtu_chargingC;
}

/* System initialize for function-call system: '<S1>/key_on' */
void SOC_codegen_key_on_Init(B_key_on_SOC_codegen_T *localB,
  DW_key_on_SOC_codegen_T *localDW)
{
  int32_T i;
  localDW->is_active_c1_SOC_codegen = 0U;

  /* SystemInitialize for Chart: '<S8>/Chart' incorporates:
   *  SubSystem: '<S8>/Subsystem'
   */
  SOC_codegen_Subsystem_Init(&localB->Subsystem);

  /* SystemInitialize for Chart: '<S8>/Chart' incorporates:
   *  SubSystem: '<S8>/CdegradeCalc'
   */
  SOC_codegen_CdegradeCalc_Init(&localB->CdegradeCalc, &localDW->CdegradeCalc);
  for (i = 0; i < 40; i++) {
    /* SystemInitialize for SignalConversion generated from: '<S8>/capacity_degrade_factor' incorporates:
     *  Outport: '<S8>/capacity_degrade_factor'
     */
    localB->OutportBufferForcapacity_degrad[i] = 1.0;
  }
}

/* Output and update for function-call system: '<S1>/key_on' */
void SOC_codegen_key_on(const real_T rtu_cell_voltages[40], boolean_T rtu_chg_c,
  real_T rty_soc_cells_pct[40], real_T *rty_cc_integration_reset, const real_T
  rtd_CCounting_soc_store[40], real_T rtd_charging_initial_soc[40], real_T
  *rtd_last_cycle_charging, const real_T rtd_memStore_Cfactors[40],
  B_key_on_SOC_codegen_T *localB, DW_key_on_SOC_codegen_T *localDW)
{
  /* DataStoreRead: '<S8>/Data Store Read2' */
  memcpy(&localB->DataStoreRead2[0], &rtd_charging_initial_soc[0], 40U * sizeof
         (real_T));

  /* DataStoreRead: '<S8>/Data Store Read1' */
  memcpy(&localB->DataStoreRead1[0], &rtd_CCounting_soc_store[0], 40U * sizeof
         (real_T));

  /* DataStoreRead: '<S8>/Data Store Read3' */
  memcpy(&localB->DataStoreRead3[0], &rtd_memStore_Cfactors[0], 40U * sizeof
         (real_T));

  /* Chart: '<S8>/Chart' */
  if (localDW->is_active_c1_SOC_codegen == 0U) {
    localDW->is_active_c1_SOC_codegen = 1U;

    /* Outputs for Function Call SubSystem: '<S8>/Subsystem' */
    SOC_codegen_Subsystem(rtu_cell_voltages, rtd_CCounting_soc_store,
                          &localB->Subsystem);

    /* End of Outputs for SubSystem: '<S8>/Subsystem' */
    if (*rtd_last_cycle_charging == 1.0) {
      /* Outputs for Function Call SubSystem: '<S8>/CdegradeCalc' */
      SOC_codegen_CdegradeCalc(localB->Subsystem.OCVSOCLookup,
        localB->DataStoreRead2, localB->DataStoreRead1, localB->DataStoreRead3,
        &localB->CdegradeCalc, &localDW->CdegradeCalc);

      /* End of Outputs for SubSystem: '<S8>/CdegradeCalc' */
    }

    if (rtu_chg_c) {
      /* Outputs for Function Call SubSystem: '<S8>/saveChgInitSoc' */
      SOC_codegen_saveChgInitSoc(localB->Subsystem.OCVSOCLookup,
        rtd_charging_initial_soc);

      /* End of Outputs for SubSystem: '<S8>/saveChgInitSoc' */
    }

    /* Outputs for Function Call SubSystem: '<S8>/lastCycleUpdate' */
    SOC_codegen_lastCycleUpdate(rtu_chg_c, rtd_last_cycle_charging);

    /* End of Outputs for SubSystem: '<S8>/lastCycleUpdate' */
  } else {
    /* Outputs for Function Call SubSystem: '<S8>/Subsystem' */
    SOC_codegen_Subsystem(rtu_cell_voltages, rtd_CCounting_soc_store,
                          &localB->Subsystem);

    /* End of Outputs for SubSystem: '<S8>/Subsystem' */
    if (*rtd_last_cycle_charging == 1.0) {
      /* Outputs for Function Call SubSystem: '<S8>/CdegradeCalc' */
      SOC_codegen_CdegradeCalc(localB->Subsystem.OCVSOCLookup,
        localB->DataStoreRead2, localB->DataStoreRead1, localB->DataStoreRead3,
        &localB->CdegradeCalc, &localDW->CdegradeCalc);

      /* End of Outputs for SubSystem: '<S8>/CdegradeCalc' */
    }

    if (rtu_chg_c) {
      /* Outputs for Function Call SubSystem: '<S8>/saveChgInitSoc' */
      SOC_codegen_saveChgInitSoc(localB->Subsystem.OCVSOCLookup,
        rtd_charging_initial_soc);

      /* End of Outputs for SubSystem: '<S8>/saveChgInitSoc' */
    }

    /* Outputs for Function Call SubSystem: '<S8>/lastCycleUpdate' */
    SOC_codegen_lastCycleUpdate(rtu_chg_c, rtd_last_cycle_charging);

    /* End of Outputs for SubSystem: '<S8>/lastCycleUpdate' */
  }

  /* End of Chart: '<S8>/Chart' */

  /* SignalConversion generated from: '<S8>/capacity_degrade_factor' */
  memcpy(&localB->OutportBufferForcapacity_degrad[0], &localB->CdegradeCalc.Sum
         [0], 40U * sizeof(real_T));

  /* SignalConversion generated from: '<S8>/cc_integration_reset' */
  *rty_cc_integration_reset = localB->Subsystem.Switch1;

  /* SignalConversion generated from: '<S8>/soc_cells_pct' */
  memcpy(&rty_soc_cells_pct[0], &localB->Subsystem.Switch[0], 40U * sizeof
         (real_T));
}

/* System initialize for function-call system: '<S1>/CC_counting' */
void SOC_codegen_CC_counting_Init(DW_CC_counting_SOC_codegen_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_PrevRese = 2;
  localDW->DiscreteTimeIntegrator_IC_LOADI = 1U;
}

/* Output and update for function-call system: '<S1>/CC_counting' */
void SOC_codegen_CC_counting(real_T rtu_pack_current, const real_T
  rtu_soh_C_factor[40], const real_T rtu_cell_voltages[40], const boolean_T
  rtu_cb_cmds[40], const real_T rtu_integration_initial_soc[40], real_T
  rtu_integration_reset, real_T rty_soc_cells_pct[40], real_T
  *rty_cc_integration_reset, DW_CC_counting_SOC_codegen_T *localDW)
{
  real_T rtb_mul1[40];
  real_T rtb_mul1_m;
  int32_T i;

  /* Product: '<S3>/mul1' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant4'
   *  Constant: '<S3>/Constant5'
   *  Constant: '<S3>/Constant7'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Product: '<S3>/Divide'
   *  Product: '<S3>/Divide1'
   *  Product: '<S3>/Divide2'
   *  Product: '<S3>/Divide3'
   *  Product: '<S3>/Divide4'
   *  Product: '<S3>/mul'
   *  Sum: '<S3>/Sum'
   */
  for (i = 0; i < 40; i++) {
    rtb_mul1[i] = (rtu_pack_current - rtu_cell_voltages[i] * (real_T)
                   rtu_cb_cmds[i] / 1.1) / (8.0 * rtu_soh_C_factor[i]) / 3600.0 *
      0.1;
  }

  /* End of Product: '<S3>/mul1' */

  /* DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  if (localDW->DiscreteTimeIntegrator_IC_LOADI != 0) {
    memcpy(&localDW->DiscreteTimeIntegrator_DSTATE[0],
           &rtu_integration_initial_soc[0], 40U * sizeof(real_T));
  }

  /* SignalConversion generated from: '<S3>/cc_integration_reset' incorporates:
   *  Constant: '<S3>/Constant2'
   */
  *rty_cc_integration_reset = 0.0;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_IC_LOADI = 0U;
  for (i = 0; i < 40; i++) {
    /* DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
    rtb_mul1_m = rtb_mul1[i];
    if ((rtu_integration_reset > 0.0) &&
        (localDW->DiscreteTimeIntegrator_PrevRese <= 0)) {
      localDW->DiscreteTimeIntegrator_DSTATE[i] = rtu_integration_initial_soc[i];
    }

    /* DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_DSTATE[i] += 0.5 * rtb_mul1_m;

    /* Product: '<S3>/Product' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    rty_soc_cells_pct[i] = localDW->DiscreteTimeIntegrator_DSTATE[i] * 100.0;

    /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_DSTATE[i] += 0.5 * rtb_mul1_m;
  }

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  if (rtu_integration_reset > 0.0) {
    localDW->DiscreteTimeIntegrator_PrevRese = 1;
  } else if (rtu_integration_reset < 0.0) {
    localDW->DiscreteTimeIntegrator_PrevRese = -1;
  } else if (rtu_integration_reset == 0.0) {
    localDW->DiscreteTimeIntegrator_PrevRese = 0;
  } else {
    localDW->DiscreteTimeIntegrator_PrevRese = 2;
  }
}

/* Model step function */
void SOC_codegen_step(void)
{
  __m128d tmp;
  real_T rtb_Uk1;
  real_T u1_tmp;
  int32_T i;
  boolean_T rtb_LogicalOperator;

  /* Outputs for Atomic SubSystem: '<Root>/soc' */
  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Inport: '<Root>/cc_chg_contactor'
   *  Inport: '<Root>/cc_main_contactor'
   */
  rtb_LogicalOperator = (SOC_codegen_U.cc_main_contactor ||
    SOC_codegen_U.cc_chg_contactor);

  /* Delay: '<S1>/Delay' */
  memcpy(&SOC_codegen_B.Delay[0], &SOC_codegen_DW.Delay_DSTATE[0], 40U * sizeof
         (real_T));

  /* Delay: '<S1>/Delay1' */
  SOC_codegen_B.Delay1 = SOC_codegen_DW.Delay1_DSTATE;

  /* Chart: '<S1>/Chart' incorporates:
   *  Inport: '<Root>/bsc_chg_cc_cmd'
   *  Inport: '<Root>/cb_cmds'
   *  Inport: '<Root>/cc_pre_chg_contactor'
   *  Inport: '<Root>/soh_C_factors'
   *  Inport: '<Root>/vitm_cell_voltages'
   *  Inport: '<Root>/vitm_pack_current'
   */
  if (SOC_codegen_DW.is_active_c3_SOC_codegen == 0U) {
    SOC_codegen_DW.is_active_c3_SOC_codegen = 1U;
    SOC_codegen_DW.is_c3_SOC_codegen = SOC_codegen_IN_init;

    /* Outputs for Function Call SubSystem: '<S1>/Init' */
    SOC_codegen_Init(SOC_codegen_U.vitm_cell_voltages, SOC_codegen_B.Merge2,
                     &SOC_codegen_B.Merge1);

    /* End of Outputs for SubSystem: '<S1>/Init' */
  } else {
    switch (SOC_codegen_DW.is_c3_SOC_codegen) {
     case SOC_codegen_IN_coulomb_counting:
      if ((!rtb_LogicalOperator) && (!SOC_codegen_U.cc_pre_chg_contactor)) {
        SOC_codegen_DW.is_c3_SOC_codegen = SOC_codegen_IN_dataStore;

        /* Outputs for Function Call SubSystem: '<S1>/dataStore' */
        /* DataStoreWrite: '<S7>/Data Store Write' incorporates:
         *  Inport: '<Root>/soh_C_factors'
         */
        memcpy(&SOC_codegen_DW.memStore_Cfactors[0],
               &SOC_codegen_U.soh_C_factors[0], 40U * sizeof(real_T));

        /* End of Outputs for SubSystem: '<S1>/dataStore' */
      } else {
        /* Outputs for Function Call SubSystem: '<S1>/CC_counting' */
        SOC_codegen_CC_counting(SOC_codegen_U.vitm_pack_current,
          SOC_codegen_U.soh_C_factors, SOC_codegen_U.vitm_cell_voltages,
          SOC_codegen_U.cb_cmds, SOC_codegen_B.Delay, SOC_codegen_B.Delay1,
          SOC_codegen_B.Merge2, &SOC_codegen_B.Merge1,
          &SOC_codegen_DW.CC_counting);

        /* End of Outputs for SubSystem: '<S1>/CC_counting' */
      }
      break;

     case SOC_codegen_IN_dataStore:
      SOC_codegen_DW.is_c3_SOC_codegen = SOC_codegen_IN_end;
      break;

     case SOC_codegen_IN_end:
      if (SOC_codegen_U.cc_pre_chg_contactor || rtb_LogicalOperator) {
        SOC_codegen_DW.is_c3_SOC_codegen = SOC_codegen_IN_key_ON;

        /* Outputs for Function Call SubSystem: '<S1>/key_on' */
        SOC_codegen_key_on(SOC_codegen_U.vitm_cell_voltages,
                           SOC_codegen_U.bsc_chg_cc_cmd, SOC_codegen_B.Merge2,
                           &SOC_codegen_B.Merge1,
                           SOC_codegen_DW.CCounting_soc_store,
                           SOC_codegen_DW.charging_initial_soc,
                           &SOC_codegen_DW.last_cycle_charging,
                           SOC_codegen_DW.memStore_Cfactors,
                           &SOC_codegen_B.key_on, &SOC_codegen_DW.key_on);

        /* End of Outputs for SubSystem: '<S1>/key_on' */
      }
      break;

     case SOC_codegen_IN_init:
      if (SOC_codegen_U.cc_pre_chg_contactor || rtb_LogicalOperator) {
        SOC_codegen_DW.is_c3_SOC_codegen = SOC_codegen_IN_key_ON;

        /* Outputs for Function Call SubSystem: '<S1>/key_on' */
        SOC_codegen_key_on(SOC_codegen_U.vitm_cell_voltages,
                           SOC_codegen_U.bsc_chg_cc_cmd, SOC_codegen_B.Merge2,
                           &SOC_codegen_B.Merge1,
                           SOC_codegen_DW.CCounting_soc_store,
                           SOC_codegen_DW.charging_initial_soc,
                           &SOC_codegen_DW.last_cycle_charging,
                           SOC_codegen_DW.memStore_Cfactors,
                           &SOC_codegen_B.key_on, &SOC_codegen_DW.key_on);

        /* End of Outputs for SubSystem: '<S1>/key_on' */
      } else {
        /* Outputs for Function Call SubSystem: '<S1>/Init' */
        SOC_codegen_Init(SOC_codegen_U.vitm_cell_voltages, SOC_codegen_B.Merge2,
                         &SOC_codegen_B.Merge1);

        /* End of Outputs for SubSystem: '<S1>/Init' */
      }
      break;

     default:
      /* case IN_key_ON: */
      if (SOC_codegen_U.cc_pre_chg_contactor || rtb_LogicalOperator) {
        SOC_codegen_DW.is_c3_SOC_codegen = SOC_codegen_IN_coulomb_counting;

        /* Outputs for Function Call SubSystem: '<S1>/CC_counting' */
        SOC_codegen_CC_counting(SOC_codegen_U.vitm_pack_current,
          SOC_codegen_U.soh_C_factors, SOC_codegen_U.vitm_cell_voltages,
          SOC_codegen_U.cb_cmds, SOC_codegen_B.Delay, SOC_codegen_B.Delay1,
          SOC_codegen_B.Merge2, &SOC_codegen_B.Merge1,
          &SOC_codegen_DW.CC_counting);

        /* End of Outputs for SubSystem: '<S1>/CC_counting' */
      } else {
        /* Outputs for Function Call SubSystem: '<S1>/key_on' */
        SOC_codegen_key_on(SOC_codegen_U.vitm_cell_voltages,
                           SOC_codegen_U.bsc_chg_cc_cmd, SOC_codegen_B.Merge2,
                           &SOC_codegen_B.Merge1,
                           SOC_codegen_DW.CCounting_soc_store,
                           SOC_codegen_DW.charging_initial_soc,
                           &SOC_codegen_DW.last_cycle_charging,
                           SOC_codegen_DW.memStore_Cfactors,
                           &SOC_codegen_B.key_on, &SOC_codegen_DW.key_on);

        /* End of Outputs for SubSystem: '<S1>/key_on' */
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* Sum: '<S1>/Sum of Elements' */
  rtb_Uk1 = -0.0;
  for (i = 0; i < 40; i++) {
    /* DataStoreWrite: '<S1>/Data Store Write' */
    SOC_codegen_DW.CCounting_soc_store[i] = SOC_codegen_B.Merge2[i];

    /* Sum: '<S1>/Sum of Elements' */
    rtb_Uk1 += SOC_codegen_B.Merge2[i];
  }

  /* Product: '<S1>/Divide1' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Sum: '<S1>/Sum of Elements'
   */
  SOC_codegen_Y.soc_pack_actual = rtb_Uk1 / 40.0;

  /* UnitDelay: '<S5>/UD' */
  rtb_Uk1 = SOC_codegen_DW.UD_DSTATE;

  /* MinMax: '<S1>/MinMax' */
  SOC_codegen_Y.soc_cells_max = SOC_codegen_B.Merge2[0];

  /* MinMax: '<S1>/MinMax1' */
  SOC_codegen_Y.soc_cells_min = SOC_codegen_B.Merge2[0];
  for (i = 0; i < 39; i++) {
    /* MinMax: '<S1>/MinMax' incorporates:
     *  MinMax: '<S1>/MinMax1'
     */
    u1_tmp = SOC_codegen_B.Merge2[i + 1];
    rtb_LogicalOperator = !rtIsNaN(u1_tmp);
    if ((!(SOC_codegen_Y.soc_cells_max >= u1_tmp)) && rtb_LogicalOperator) {
      SOC_codegen_Y.soc_cells_max = u1_tmp;
    }

    /* MinMax: '<S1>/MinMax1' */
    if ((!(SOC_codegen_Y.soc_cells_min <= u1_tmp)) && rtb_LogicalOperator) {
      SOC_codegen_Y.soc_cells_min = u1_tmp;
    }
  }

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant2'
   *  MinMax: '<S1>/MinMax'
   *  RelationalOperator: '<S1>/RelationalOperator'
   */
  if (SOC_codegen_Y.soc_cells_max < 80.0) {
    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S1>/Constant4'
     *  MinMax: '<S1>/MinMax1'
     *  RelationalOperator: '<S1>/RelationalOperator1'
     */
    if (SOC_codegen_Y.soc_cells_min <= 20.0) {
      /* Outport: '<Root>/soc_pack_customer' incorporates:
       *  Constant: '<S1>/Constant5'
       */
      SOC_codegen_Y.soc_pack_customer = 0.0;
    } else {
      /* Outport: '<Root>/soc_pack_customer' incorporates:
       *  Lookup_n-D: '<S1>/Customer interpolation'
       *  Product: '<S1>/Divide1'
       */
      SOC_codegen_Y.soc_pack_customer = look1_binlxpw
        (SOC_codegen_Y.soc_pack_actual,
         SOC_codegen_ConstP.Customerinterpolation_bp01Data,
         SOC_codegen_ConstP.Customerinterpolation_tableData, 1U);
    }

    /* End of Switch: '<S1>/Switch1' */
  } else {
    /* Outport: '<Root>/soc_pack_customer' incorporates:
     *  Constant: '<S1>/Constant6'
     */
    SOC_codegen_Y.soc_pack_customer = 100.0;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Update for Delay: '<S1>/Delay1' */
  SOC_codegen_DW.Delay1_DSTATE = SOC_codegen_B.Merge1;

  /* Update for UnitDelay: '<S5>/UD' */
  SOC_codegen_DW.UD_DSTATE = SOC_codegen_Y.soc_pack_actual;

  /* End of Outputs for SubSystem: '<Root>/soc' */
  for (i = 0; i <= 38; i += 2) {
    /* Outputs for Atomic SubSystem: '<Root>/soc' */
    /* Gain: '<S1>/Gain' incorporates:
     *  Delay: '<S1>/Delay'
     */
    tmp = _mm_loadu_pd(&SOC_codegen_B.Merge2[i]);

    /* Update for Delay: '<S1>/Delay' incorporates:
     *  Gain: '<S1>/Gain'
     */
    _mm_storeu_pd(&SOC_codegen_DW.Delay_DSTATE[i], _mm_mul_pd(_mm_set1_pd(0.01),
      tmp));

    /* Gain: '<S1>/Gain' incorporates:
     *  Delay: '<S1>/Delay'
     */
    tmp = _mm_loadu_pd(&SOC_codegen_B.Merge2[i]);

    /* Outport: '<Root>/soc_cells_pct' incorporates:
     *  Delay: '<S1>/Delay'
     */
    _mm_storeu_pd(&SOC_codegen_Y.soc_cells_pct[i], tmp);

    /* End of Outputs for SubSystem: '<Root>/soc' */
  }

  /* Outputs for Atomic SubSystem: '<Root>/soc' */
  /* Outport: '<Root>/soc_rate_high' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S2>/Constant'
   *  Product: '<S1>/Divide2'
   *  RelationalOperator: '<S2>/Compare'
   *  Sum: '<S5>/Diff'
   */
  SOC_codegen_Y.soc_rate_high = ((SOC_codegen_Y.soc_pack_actual - rtb_Uk1) / 0.1
    <= -1.0);

  /* End of Outputs for SubSystem: '<Root>/soc' */

  /* Outport: '<Root>/soc_C_factor' */
  memcpy(&SOC_codegen_Y.soc_C_factor[0],
         &SOC_codegen_B.key_on.OutportBufferForcapacity_degrad[0], 40U * sizeof
         (real_T));

  /* Matfile logging */
  rt_UpdateTXYLogVars(SOC_codegen_M->rtwLogInfo,
                      (&SOC_codegen_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(SOC_codegen_M)!=-1) &&
        !((rtmGetTFinal(SOC_codegen_M)-SOC_codegen_M->Timing.taskTime0) >
          SOC_codegen_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(SOC_codegen_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++SOC_codegen_M->Timing.clockTick0)) {
    ++SOC_codegen_M->Timing.clockTickH0;
  }

  SOC_codegen_M->Timing.taskTime0 = SOC_codegen_M->Timing.clockTick0 *
    SOC_codegen_M->Timing.stepSize0 + SOC_codegen_M->Timing.clockTickH0 *
    SOC_codegen_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void SOC_codegen_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  SOC_codegen_ConstInitP.pooled1[0] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[1] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[2] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[3] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[4] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[5] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[6] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[7] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[8] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[9] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[10] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[11] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[12] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[13] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[14] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[15] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[16] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[17] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[18] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[19] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[20] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[21] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[22] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[149] = rtNaN;
  SOC_codegen_ConstInitP.pooled1[150] = rtNaN;

  /* initialize real-time model */
  (void) memset((void *)SOC_codegen_M, 0,
                sizeof(RT_MODEL_SOC_codegen_T));
  rtmSetTFinal(SOC_codegen_M, 10.0);
  SOC_codegen_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    SOC_codegen_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(SOC_codegen_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(SOC_codegen_M->rtwLogInfo, (NULL));
    rtliSetLogT(SOC_codegen_M->rtwLogInfo, "tout");
    rtliSetLogX(SOC_codegen_M->rtwLogInfo, "");
    rtliSetLogXFinal(SOC_codegen_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(SOC_codegen_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(SOC_codegen_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(SOC_codegen_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(SOC_codegen_M->rtwLogInfo, 1);
    rtliSetLogY(SOC_codegen_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(SOC_codegen_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(SOC_codegen_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &SOC_codegen_B), 0,
                sizeof(B_SOC_codegen_T));

  /* states (dwork) */
  (void) memset((void *)&SOC_codegen_DW, 0,
                sizeof(DW_SOC_codegen_T));

  /* external inputs */
  (void)memset(&SOC_codegen_U, 0, sizeof(ExtU_SOC_codegen_T));

  /* external outputs */
  (void)memset(&SOC_codegen_Y, 0, sizeof(ExtY_SOC_codegen_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(SOC_codegen_M->rtwLogInfo, 0.0, rtmGetTFinal
    (SOC_codegen_M), SOC_codegen_M->Timing.stepSize0, (&rtmGetErrorStatus
    (SOC_codegen_M)));

  {
    int32_T i;

    /* SystemInitialize for Atomic SubSystem: '<Root>/soc' */
    /* Start for DataStoreMemory: '<S1>/Data Store Memory2' */
    SOC_codegen_DW.last_cycle_charging = 0.0;
    for (i = 0; i < 40; i++) {
      /* Start for DataStoreMemory: '<S1>/Data Store Memory' */
      SOC_codegen_DW.CCounting_soc_store[i] = 0.0;

      /* Start for DataStoreMemory: '<S1>/Data Store Memory1' */
      SOC_codegen_DW.charging_initial_soc[i] = 0.0;

      /* Start for DataStoreMemory: '<S1>/Data Store Memory3' */
      SOC_codegen_DW.memStore_Cfactors[i] = 1.0;

      /* InitializeConditions for Delay: '<S1>/Delay' */
      SOC_codegen_DW.Delay_DSTATE[i] = 0.0;
    }

    /* InitializeConditions for Delay: '<S1>/Delay1' */
    SOC_codegen_DW.Delay1_DSTATE = 0.0;

    /* InitializeConditions for UnitDelay: '<S5>/UD' */
    SOC_codegen_DW.UD_DSTATE = 0.0;
    SOC_codegen_DW.is_active_c3_SOC_codegen = 0U;
    SOC_codegen_DW.is_c3_SOC_codegen = SOC_codegen_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<S1>/Chart' incorporates:
     *  SubSystem: '<S1>/key_on'
     */
    SOC_codegen_key_on_Init(&SOC_codegen_B.key_on, &SOC_codegen_DW.key_on);

    /* SystemInitialize for Chart: '<S1>/Chart' incorporates:
     *  SubSystem: '<S1>/CC_counting'
     */
    SOC_codegen_CC_counting_Init(&SOC_codegen_DW.CC_counting);

    /* SystemInitialize for Merge: '<S1>/Merge2' */
    memset(&SOC_codegen_B.Merge2[0], 0, 40U * sizeof(real_T));

    /* SystemInitialize for Merge: '<S1>/Merge1' */
    SOC_codegen_B.Merge1 = 0.0;

    /* End of SystemInitialize for SubSystem: '<Root>/soc' */
  }
}

/* Model terminate function */
void SOC_codegen_terminate(void)
{
  /* (no terminate code required) */
}
