/*
 * SOC_codegen_private.h
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

#ifndef RTW_HEADER_SOC_codegen_private_h_
#define RTW_HEADER_SOC_codegen_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "SOC_codegen.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern uint32_T plook_evenc(real_T u, real_T bp0, real_T bpSpace, uint32_T
  maxIndex, real_T *fraction);
extern real_T intrp1d_l_pw(uint32_T bpIndex, real_T frac, const real_T table[]);
extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void SOC_codegen_Init(const real_T rtu_cell_voltages[40], real_T
  rty_soc_cells_pct[40], real_T *rty_cc_integration_reset);
extern void SOC_codegen_Subsystem_Init(B_Subsystem_SOC_codegen_T *localB);
extern void SOC_codegen_Subsystem(const real_T rtu_cell_voltages[40], const
  real_T rtd_CCounting_soc_store[40], B_Subsystem_SOC_codegen_T *localB);
extern void SOC_codegen_CdegradeCalc_Init(B_CdegradeCalc_SOC_codegen_T *localB,
  DW_CdegradeCalc_SOC_codegen_T *localDW);
extern void SOC_codegen_CdegradeCalc(const real_T rtu_keyON_ocvsoc[40], const
  real_T rtu_lastChgInitsoc[40], const real_T rtu_lastChgCCsoc[40], const real_T
  rtu_soh_C_factors[40], B_CdegradeCalc_SOC_codegen_T *localB,
  DW_CdegradeCalc_SOC_codegen_T *localDW);
extern void SOC_codegen_saveChgInitSoc(const real_T rtu_keyON_ocvsoc[40], real_T
  rtd_charging_initial_soc[40]);
extern void SOC_codegen_lastCycleUpdate(boolean_T rtu_chargingC, real_T
  *rtd_last_cycle_charging);
extern void SOC_codegen_key_on_Init(B_key_on_SOC_codegen_T *localB,
  DW_key_on_SOC_codegen_T *localDW);
extern void SOC_codegen_key_on(const real_T rtu_cell_voltages[40], boolean_T
  rtu_chg_c, real_T rty_soc_cells_pct[40], real_T *rty_cc_integration_reset,
  const real_T rtd_CCounting_soc_store[40], real_T rtd_charging_initial_soc[40],
  real_T *rtd_last_cycle_charging, const real_T rtd_memStore_Cfactors[40],
  B_key_on_SOC_codegen_T *localB, DW_key_on_SOC_codegen_T *localDW);
extern void SOC_codegen_CC_counting_Init(DW_CC_counting_SOC_codegen_T *localDW);
extern void SOC_codegen_CC_counting(real_T rtu_pack_current, const real_T
  rtu_soh_C_factor[40], const real_T rtu_cell_voltages[40], const boolean_T
  rtu_cb_cmds[40], const real_T rtu_integration_initial_soc[40], real_T
  rtu_integration_reset, real_T rty_soc_cells_pct[40], real_T
  *rty_cc_integration_reset, DW_CC_counting_SOC_codegen_T *localDW);

#endif                                 /* RTW_HEADER_SOC_codegen_private_h_ */
