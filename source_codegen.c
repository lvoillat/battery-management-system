/
  /* Test revision
		Prelookup - Index and Fraction
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

/* Output and update for function-call system: '<S8>/Subsystem' */
void SOC_codegen_Subsystem(const real_T rtu_cell_voltages[40], real_T
  rty_soc_cells_pct[40], real_T *rty_cc_integration_reset, real_T
  rty_keyON_ocvsoc[40], const real_T rtd_CCounting_soc_store[40])
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
    rty_keyON_ocvsoc[i] = intrp1d_l_pw(bpIdx, frac,
      SOC_codegen_ConstInitP.pooled1);
  }

  /* End of Lookup_n-D: '<S11>/OCV - SOC Lookup' */

  /* Abs: '<S11>/Abs' incorporates:
   *  DataStoreRead: '<S11>/Data Store Read'
   *  Sum: '<S11>/Subtract'
   */
  for (i = 0; i < 40; i++) {
    rtb_Abs[i] = fabs(rty_keyON_ocvsoc[i] - rtd_CCounting_soc_store[i]);
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

  /* Switch: '<S11>/Switch' incorporates:
   *  DataStoreRead: '<S11>/Data Store Read'
   */
  if (rtb_RelationalOperator3) {
    memcpy(&rty_soc_cells_pct[0], &rty_keyON_ocvsoc[0], 40U * sizeof(real_T));
  } else {
    memcpy(&rty_soc_cells_pct[0], &rtd_CCounting_soc_store[0], 40U * sizeof
           (real_T));
  }

  /* End of Switch: '<S11>/Switch' */

  /* Switch: '<S11>/Switch1' incorporates:
   *  Constant: '<S11>/Constant'
   */
  if (rtb_RelationalOperator3) {
    *rty_cc_integration_reset = 1.0;
  } else {
    *rty_cc_integration_reset = 0.0;
  }

  /* End of Switch: '<S11>/Switch1' */
}

/* System initialize for function-call system: '<S8>/CdegradeCalc' */
void SOC_codegen_CdegradeCalc_Init(real_T rty_Out1[40],
  DW_CdegradeCalc_SOC_codegen_T *localDW)
{
  int32_T i;

  /* InitializeConditions for Delay: '<S9>/Delay' */
  localDW->icLoad = true;

  /* SystemInitialize for Outport: '<S9>/Out1' */
  for (i = 0; i < 40; i++) {
    rty_Out1[i] = 1.0;
  }

  /* End of SystemInitialize for Outport: '<S9>/Out1' */
}

/* Output and update for function-call system: '<S8>/CdegradeCalc' */
void SOC_codegen_CdegradeCalc(const real_T rtu_keyON_ocvsoc[40], const real_T
  rtu_lastChgInitsoc[40], const real_T rtu_lastChgCCsoc[40], const real_T
  rtu_soh_C_factors[40], real_T rty_Out1[40], DW_CdegradeCalc_SOC_codegen_T
  *localDW)
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
    rty_Out1[i] = (rtu_lastChgCCsoc[i] - rtu_lastChgInitsoc[i]) /
      (rtu_keyON_ocvsoc[i] - rtu_lastChgInitsoc[i]) * rtu_soh_C_factors[i] + 0.0
      * localDW->Delay_DSTATE[i];

    /* Update for Delay: '<S9>/Delay' */
    localDW->Delay_DSTATE[i] = rty_Out1[i];
  }

  /* Update for Delay: '<S9>/Delay' */
  localDW->icLoad = false;
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
void SOC_codegen_key_on_Init(real_T rty_capacity_degrade_factor[40],
  B_key_on_SOC_codegen_T *localB, DW_key_on_SOC_codegen_T *localDW)
{
  int32_T i;

  /* SystemInitialize for Chart: '<S8>/Chart' incorporates:
   *  SubSystem: '<S8>/CdegradeCalc'
   */
  SOC_codegen_CdegradeCalc_Init(localB->Sum, &localDW->CdegradeCalc);

  /* SystemInitialize for Outport: '<S8>/capacity_degrade_factor' */
  for (i = 0; i < 40; i++) {
    rty_capacity_degrade_factor[i] = 1.0;
  }

  /* End of SystemInitialize for Outport: '<S8>/capacity_degrade_factor' */
}

/* Output and update for function-call system: '<S1>/key_on' */
void SOC_codegen_key_on(const real_T rtu_cell_voltages[40], boolean_T rtu_chg_c,
  real_T rty_soc_cells_pct[40], real_T *rty_cc_integration_reset, real_T
  rty_capacity_degrade_factor[40], const real_T rtd_CCounting_soc_store[40],
  real_T rtd_charging_initial_soc[40], real_T *rtd_last_cycle_charging, const
  real_T rtd_memStore_Cfactors[40], B_key_on_SOC_codegen_T *localB,
  DW_key_on_SOC_codegen_T *localDW)
{
  /* Chart: '<S8>/Chart' incorporates:
   *  DataStoreRead: '<S8>/Data Store Read1'
   *  DataStoreRead: '<S8>/Data Store Read2'
   *  DataStoreRead: '<S8>/Data Store Read3'
   */
  if (localDW->is_active_c1_SOC_codegen == 0U) {
    localDW->is_active_c1_SOC_codegen = 1U;

    /* Outputs for Function Call SubSystem: '<S8>/Subsystem' */
    /* SignalConversion generated from: '<S8>/soc_cells_pct' incorporates:
     *  SignalConversion generated from: '<S8>/cc_integration_reset'
     */
    SOC_codegen_Subsystem(rtu_cell_voltages, rty_soc_cells_pct,
                          rty_cc_integration_reset, localB->OCVSOCLookup,
                          rtd_CCounting_soc_store);

    /* End of Outputs for SubSystem: '<S8>/Subsystem' */
    if (*rtd_last_cycle_charging == 1.0) {
      /* Outputs for Function Call SubSystem: '<S8>/CdegradeCalc' */
      SOC_codegen_CdegradeCalc(localB->OCVSOCLookup, rtd_charging_initial_soc,
        rtd_CCounting_soc_store, rtd_memStore_Cfactors, localB->Sum,
        &localDW->CdegradeCalc);

      /* End of Outputs for SubSystem: '<S8>/CdegradeCalc' */
    }

    if (rtu_chg_c) {
      /* Outputs for Function Call SubSystem: '<S8>/saveChgInitSoc' */
      /* DataStoreWrite: '<S13>/Data Store Write' */
      memcpy(&rtd_charging_initial_soc[0], &localB->OCVSOCLookup[0], 40U *
             sizeof(real_T));

      /* End of Outputs for SubSystem: '<S8>/saveChgInitSoc' */
    }

    /* Outputs for Function Call SubSystem: '<S8>/lastCycleUpdate' */
    SOC_codegen_lastCycleUpdate(rtu_chg_c, rtd_last_cycle_charging);

    /* End of Outputs for SubSystem: '<S8>/lastCycleUpdate' */
  } else {
    /* Outputs for Function Call SubSystem: '<S8>/Subsystem' */
    /* SignalConversion generated from: '<S8>/soc_cells_pct' incorporates:
     *  SignalConversion generated from: '<S8>/cc_integration_reset'
     */
    SOC_codegen_Subsystem(rtu_cell_voltages, rty_soc_cells_pct,
                          rty_cc_integration_reset, localB->OCVSOCLookup,
                          rtd_CCounting_soc_store);

    /* End of Outputs for SubSystem: '<S8>/Subsystem' */
    if (*rtd_last_cycle_charging == 1.0) {
      /* Outputs for Function Call SubSystem: '<S8>/CdegradeCalc' */
      SOC_codegen_CdegradeCalc(localB->OCVSOCLookup, rtd_charging_initial_soc,
        rtd_CCounting_soc_store, rtd_memStore_Cfactors, localB->Sum,
        &localDW->CdegradeCalc);

      /* End of Outputs for SubSystem: '<S8>/CdegradeCalc' */
    }

    if (rtu_chg_c) {
      /* Outputs for Function Call SubSystem: '<S8>/saveChgInitSoc' */
      /* DataStoreWrite: '<S13>/Data Store Write' */
      memcpy(&rtd_charging_initial_soc[0], &localB->OCVSOCLookup[0], 40U *
             sizeof(real_T));

      /* End of Outputs for SubSystem: '<S8>/saveChgInitSoc' */
    }

    /* Outputs for Function Call SubSystem: '<S8>/lastCycleUpdate' */
    SOC_codegen_lastCycleUpdate(rtu_chg_c, rtd_last_cycle_charging);

    /* End of Outputs for SubSystem: '<S8>/lastCycleUpdate' */
  }

  /* End of Chart: '<S8>/Chart' */

  /* SignalConversion generated from: '<S8>/capacity_degrade_factor' */
  memcpy(&rty_capacity_degrade_factor[0], &localB->Sum[0], 40U * sizeof(real_T));
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
  real_T rtb_mul1_n;
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
    rtb_mul1_n = rtb_mul1[i];
    if ((rtu_integration_reset > 0.0) &&
        (localDW->DiscreteTimeIntegrator_PrevRese <= 0)) {
      localDW->DiscreteTimeIntegrator_DSTATE[i] = rtu_integration_initial_soc[i];
    }

    /* DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_DSTATE[i] += 0.5 * rtb_mul1_n;

    /* Product: '<S3>/Product' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    rty_soc_cells_pct[i] = localDW->DiscreteTimeIntegrator_DSTATE[i] * 100.0;

    /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_DSTATE[i] += 0.5 * rtb_mul1_n;
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
  real_T rtb_Uk1;
  real_T u1_tmp;
  int32_T i;
  boolean_T rtb_LogicalOperator;

  /* Outputs for Atomic SubSystem: '<Root>/soc'
   *
   * Block requirements for '<Root>/soc':
   *  1. @wi BMS-619 SOC Accuracy for Charging/Discharging
   */
  /*
     @wi.implements BMS-619 SOC Accuracy for Charging/Discharging
   */

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Inport: '<Root>/cc_chg_contactor'
   *  Inport: '<Root>/cc_main_contactor'
   */
  rtb_LogicalOperator = (SOC_codegen_U.cc_main_contactor ||
    SOC_codegen_U.cc_chg_contactor);

  /* Chart: '<S1>/Chart' incorporates:
   *  Delay: '<S1>/Delay1'
   *  Inport: '<Root>/bsc_chg_cc_cmd'
   *  Inport: '<Root>/cb_cmds'
   *  Inport: '<Root>/cc_pre_chg_contactor'
   *  Inport: '<Root>/soh_C_factors'
   *  Inport: '<Root>/vitm_cell_voltages'
   *  Inport: '<Root>/vitm_pack_current'
   *  Outport: '<Root>/soc_C_factor'
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
          SOC_codegen_U.cb_cmds, SOC_codegen_DW.Delay_DSTATE,
          SOC_codegen_DW.Delay1_DSTATE, SOC_codegen_B.Merge2,
          &SOC_codegen_B.Merge1, &SOC_codegen_DW.CC_counting);

        /* End of Outputs for SubSystem: '<S1>/CC_counting' */
      }
      break;

     case SOC_codegen_IN_dataStore:
      SOC_codegen_DW.is_c3_SOC_codegen = SOC_codegen_IN_end;
      break;

     case SOC_codegen_IN_end:
      if (SOC_codegen_U.cc_pre_chg_contactor || rtb_LogicalOperator) {
        SOC_codegen_DW.is_c3_SOC_codegen = SOC_codegen_IN_key_ON;

        /* Outputs for Function Call SubSystem: '<S1>/key_on'
         *
         * Block requirements for '<S1>/key_on':
         *  1. @wi BMS-618 Power ON SOC Definition
         */
        SOC_codegen_key_on(SOC_codegen_U.vitm_cell_voltages,
                           SOC_codegen_U.bsc_chg_cc_cmd, SOC_codegen_B.Merge2,
                           &SOC_codegen_B.Merge1, SOC_codegen_Y.soc_C_factor,
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

        /* Outputs for Function Call SubSystem: '<S1>/key_on'
         *
         * Block requirements for '<S1>/key_on':
         *  1. @wi BMS-618 Power ON SOC Definition
         */
        SOC_codegen_key_on(SOC_codegen_U.vitm_cell_voltages,
                           SOC_codegen_U.bsc_chg_cc_cmd, SOC_codegen_B.Merge2,
                           &SOC_codegen_B.Merge1, SOC_codegen_Y.soc_C_factor,
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
          SOC_codegen_U.cb_cmds, SOC_codegen_DW.Delay_DSTATE,
          SOC_codegen_DW.Delay1_DSTATE, SOC_codegen_B.Merge2,
          &SOC_codegen_B.Merge1, &SOC_codegen_DW.CC_counting);

        /* End of Outputs for SubSystem: '<S1>/CC_counting' */
      } else {
        /* Outputs for Function Call SubSystem: '<S1>/key_on'
         *
         * Block requirements for '<S1>/key_on':
         *  1. @wi BMS-618 Power ON SOC Definition
         */
        SOC_codegen_key_on(SOC_codegen_U.vitm_cell_voltages,
                           SOC_codegen_U.bsc_chg_cc_cmd, SOC_codegen_B.Merge2,
                           &SOC_codegen_B.Merge1, SOC_codegen_Y.soc_C_factor,
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

    /* Gain: '<S1>/Gain' incorporates:
     *  Delay: '<S1>/Delay'
     */
    SOC_codegen_DW.Delay_DSTATE[i] = 0.01 * SOC_codegen_B.Merge2[i];
  }

  /* Product: '<S1>/Divide1' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Sum: '<S1>/Sum of Elements'
   */
  SOC_codegen_Y.soc_pack_actual = rtb_Uk1 / 40.0;

  /* UnitDelay: '<S5>/UD'
   *
   * Block description for '<S5>/UD':
   *
   *  Store in Global RAM
   */
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
   *
   * Block requirements for '<S1>/Switch':
   *  1. @wi BMS-623 SOC shown to driver
   *
   * Block requirements for '<S1>/Constant2':
   *  1. @wi BMS-622 Min Max SOC Values
   *
   * Block requirements for '<S1>/RelationalOperator':
   *  1. @wi BMS-622 Min Max SOC Values
   */
  if (SOC_codegen_Y.soc_cells_max < 80.0) {
    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S1>/Constant4'
     *  MinMax: '<S1>/MinMax1'
     *  RelationalOperator: '<S1>/RelationalOperator1'
     *
     * Block requirements for '<S1>/Switch1':
     *  1. @wi BMS-623 SOC shown to driver
     *
     * Block requirements for '<S1>/Constant4':
     *  1. @wi BMS-622 Min Max SOC Values
     *
     * Block requirements for '<S1>/RelationalOperator1':
     *  1. @wi BMS-622 Min Max SOC Values
     */
    if (SOC_codegen_Y.soc_cells_min <= 20.0) {
      /* Outport: '<Root>/soc_pack_customer' incorporates:
       *  Constant: '<S1>/Constant5'
       *
       * Block requirements for '<S1>/Constant5':
       *  1. @wi BMS-623 SOC shown to driver
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
     *
     * Block requirements for '<S1>/Constant6':
     *  1. @wi BMS-623 SOC shown to driver
     */
    SOC_codegen_Y.soc_pack_customer = 100.0;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Update for Delay: '<S1>/Delay1' */
  SOC_codegen_DW.Delay1_DSTATE = SOC_codegen_B.Merge1;

  /* Update for UnitDelay: '<S5>/UD'
   *
   * Block description for '<S5>/UD':
   *
   *  Store in Global RAM
   */
  SOC_codegen_DW.UD_DSTATE = SOC_codegen_Y.soc_pack_actual;

  /* End of Outputs for SubSystem: '<Root>/soc' */

  /* Outport: '<Root>/soc_cells_pct' */
  memcpy(&SOC_codegen_Y.soc_cells_pct[0], &SOC_codegen_B.Merge2[0], 40U * sizeof
         (real_T));

  /* Outputs for Atomic SubSystem: '<Root>/soc'
   *
   * Block requirements for '<Root>/soc':
   *  1. @wi BMS-619 SOC Accuracy for Charging/Discharging
   */
  /* Outport: '<Root>/soc_rate_high' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S2>/Constant'
   *  Product: '<S1>/Divide2'
   *  RelationalOperator: '<S2>/Compare'
   *  Sum: '<S5>/Diff'
   *
   * Block description for '<S5>/Diff':
   *
   *  Add in CPU
   *
   * Block requirements for '<S1>/Constant1':
   *  1. @wi BMS-617 Discharging SOC Slew Rate Limit
   */
  SOC_codegen_Y.soc_rate_high = ((SOC_codegen_Y.soc_pack_actual - rtb_Uk1) / 0.1
    <= -1.0);

  /* End of Outputs for SubSystem: '<Root>/soc' */
}


