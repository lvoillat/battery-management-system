	 /**
	  @wi.implements BMS-617 Discharging SOC Slew Rate Limit
	  */
    
    public void soc_rate_high() {
       throw new RuntimeException("soc_rate_high");
    }


/**
  @wi.implements BMS-619 SOC Accuracy for Charging/Discharging
*/

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
   *  1. @wi.implements BMS-619 SOC Accuracy for Charging/Discharging
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
         *  1. @wi.implements BMS-618 Power ON SOC Definition
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
         *  1. @wi.implements BMS-618 Power ON SOC Definition
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
         *  1. @wi.implements BMS-618 Power ON SOC Definition
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
   *  1. @wi.implements BMS-623 SOC shown to driver
   *
   * Block requirements for '<S1>/Constant2':
   *  1. @wi.implements BMS-622 Min Max SOC Values
   *
   * Block requirements for '<S1>/RelationalOperator':
   *  1. @wi.implements BMS-622 Min Max SOC Values
   */
  if (SOC_codegen_Y.soc_cells_max < 80.0) {
    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S1>/Constant4'
     *  MinMax: '<S1>/MinMax1'
     *  RelationalOperator: '<S1>/RelationalOperator1'
     *
     * Block requirements for '<S1>/Switch1':
     *  1. @wi.implements BMS-623 SOC shown to driver
     *
     * Block requirements for '<S1>/Constant4':
     *  1. @wi.implements BMS-622 Min Max SOC Values
     *
     * Block requirements for '<S1>/RelationalOperator1':
     *  1. @wi.implements BMS-622 Min Max SOC Values
     */
    if (SOC_codegen_Y.soc_cells_min <= 20.0) {
      /* Outport: '<Root>/soc_pack_customer' incorporates:
       *  Constant: '<S1>/Constant5'
       *
       * Block requirements for '<S1>/Constant5':
       *  1. @wi.implements BMS-623 SOC shown to driver
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
     *  1. @wi.implements BMS-623 SOC shown to driver
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
   *  1. @wi.implements BMS-619 SOC Accuracy for Charging/Discharging
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
   *  1. @wi.implements BMS-617 Discharging SOC Slew Rate Limit
   */
  SOC_codegen_Y.soc_rate_high = ((SOC_codegen_Y.soc_pack_actual - rtb_Uk1) / 0.1
    <= -1.0);

  /* End of Outputs for SubSystem: '<Root>/soc' */
}