/*
 * File:  SOC_codegen.h
 *
 * Code generated for Simulink model 'SOC_codegen'.
 *
 * Model version                  : 13.10
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Feb  1 14:13:53 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SOC_codegen_h_
#define RTW_HEADER_SOC_codegen_h_
#include <math.h>
#include <string.h>
#ifndef SOC_codegen_COMMON_INCLUDES_
#define SOC_codegen_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SOC_codegen_COMMON_INCLUDES_ */

#include "SOC_codegen_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S8>/CdegradeCalc' */
typedef struct {
  real_T Delay_DSTATE[40];             /* '<S9>/Delay' */
  boolean_T icLoad;                    /* '<S9>/Delay' */
} DW_CdegradeCalc_SOC_codegen_T;

/* Block signals for system '<S1>/key_on' */
typedef struct {
  real_T Sum[40];                      /* '<S9>/Sum' */
  real_T OCVSOCLookup[40];             /* '<S11>/OCV - SOC Lookup' */
} B_key_on_SOC_codegen_T;

/* Block states (default storage) for system '<S1>/key_on' */
typedef struct {
  uint8_T is_active_c1_SOC_codegen;    /* '<S8>/Chart' */
  DW_CdegradeCalc_SOC_codegen_T CdegradeCalc;/* '<S8>/CdegradeCalc' */
} DW_key_on_SOC_codegen_T;

/* Block states (default storage) for system '<S1>/CC_counting' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE[40];/* '<S3>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S3>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S3>/Discrete-Time Integrator' */
} DW_CC_counting_SOC_codegen_T;

/* Block signals (default storage) */
typedef struct {
  real_T Merge2[40];                   /* '<S1>/Merge2' */
  real_T Merge1;                       /* '<S1>/Merge1' */
  B_key_on_SOC_codegen_T key_on;       /* '<S1>/key_on' */
} B_SOC_codegen_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[40];             /* '<S1>/Delay' */
  real_T Delay1_DSTATE;                /* '<S1>/Delay1' */
  real_T UD_DSTATE;                    /* '<S5>/UD' */
  real_T CCounting_soc_store[40];      /* '<S1>/Data Store Memory' */
  real_T charging_initial_soc[40];     /* '<S1>/Data Store Memory1' */
  real_T last_cycle_charging;          /* '<S1>/Data Store Memory2' */
  real_T memStore_Cfactors[40];        /* '<S1>/Data Store Memory3' */
  uint8_T is_active_c3_SOC_codegen;    /* '<S1>/Chart' */
  uint8_T is_c3_SOC_codegen;           /* '<S1>/Chart' */
  DW_CC_counting_SOC_codegen_T CC_counting;/* '<S1>/CC_counting' */
  DW_key_on_SOC_codegen_T key_on;      /* '<S1>/key_on' */
} DW_SOC_codegen_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [0 100]
   * Referenced by: '<S1>/Customer interpolation'
   */
  real_T Customerinterpolation_tableData[2];

  /* Expression: [SOCk_SocMinPercentage SOCk_SocMaxPercentage]
   * Referenced by: '<S1>/Customer interpolation'
   */
  real_T Customerinterpolation_bp01Data[2];
} ConstP_SOC_codegen_T;

/* Constant parameters with dynamic initialization (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: C_SocTable)
   * Referenced by:
   *   '<S6>/OCV - SOC Lookup'
   *   '<S11>/OCV - SOC Lookup'
   */
  real_T pooled1[151];
} ConstInitP_SOC_codegen_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T vitm_pack_current;            /* '<Root>/vitm_pack_current' */
  real_T vitm_cell_voltages[40];       /* '<Root>/vitm_cell_voltages' */
  boolean_T cc_main_contactor;         /* '<Root>/cc_main_contactor' */
  boolean_T cc_chg_contactor;          /* '<Root>/cc_chg_contactor' */
  boolean_T cc_pre_chg_contactor;      /* '<Root>/cc_pre_chg_contactor' */
  real_T soh_C_factors[40];            /* '<Root>/soh_C_factors' */
  boolean_T bsc_chg_cc_cmd;            /* '<Root>/bsc_chg_cc_cmd' */
  boolean_T cb_cmds[40];               /* '<Root>/cb_cmds' */
} ExtU_SOC_codegen_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T soc_cells_pct[40];            /* '<Root>/soc_cells_pct' */
  real_T soc_pack_customer;            /* '<Root>/soc_pack_customer' */
  real_T soc_cells_max;                /* '<Root>/soc_cells_max' */
  real_T soc_cells_min;                /* '<Root>/soc_cells_min' */
  real_T soc_pack_actual;              /* '<Root>/soc_pack_actual' */
  boolean_T soc_rate_high;             /* '<Root>/soc_rate_high' */
  real_T soc_C_factor[40];             /* '<Root>/soc_C_factor' */
} ExtY_SOC_codegen_T;

/* Real-time Model Data Structure */
struct tag_RTM_SOC_codegen_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_SOC_codegen_T SOC_codegen_B;

/* Block states (default storage) */
extern DW_SOC_codegen_T SOC_codegen_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_SOC_codegen_T SOC_codegen_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_SOC_codegen_T SOC_codegen_Y;

/* Constant parameters (default storage) */
extern const ConstP_SOC_codegen_T SOC_codegen_ConstP;

/* Constant parameters with dynamic initialization (default storage) */
extern ConstInitP_SOC_codegen_T SOC_codegen_ConstInitP;/* constant parameters */

/* Model entry point functions */
extern void SOC_codegen_initialize(void);
extern void SOC_codegen_step(void);
extern void SOC_codegen_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SOC_codegen_T *const SOC_codegen_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S9>/Gain' : Eliminated nontunable gain of 1
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SOC_codegen'
 * '<S1>'   : 'SOC_codegen/soc'
 * '<S2>'   : 'SOC_codegen/soc/1% per second only while discharging'
 * '<S3>'   : 'SOC_codegen/soc/CC_counting'
 * '<S4>'   : 'SOC_codegen/soc/Chart'
 * '<S5>'   : 'SOC_codegen/soc/Difference'
 * '<S6>'   : 'SOC_codegen/soc/Init'
 * '<S7>'   : 'SOC_codegen/soc/dataStore'
 * '<S8>'   : 'SOC_codegen/soc/key_on'
 * '<S9>'   : 'SOC_codegen/soc/key_on/CdegradeCalc'
 * '<S10>'  : 'SOC_codegen/soc/key_on/Chart'
 * '<S11>'  : 'SOC_codegen/soc/key_on/Subsystem'
 * '<S12>'  : 'SOC_codegen/soc/key_on/lastCycleUpdate'
 * '<S13>'  : 'SOC_codegen/soc/key_on/saveChgInitSoc'
 */

/*-
 * Requirements for '<Root>': SOC_codegen
 *
 * Inherited requirements for '<Root>/soc':
 *  1. @wi BMS-619 SOC Accuracy for Charging/Discharging
 *
 * Inherited requirements for '<S1>/key_on':
 *  1. @wi BMS-618 Power ON SOC Definition

 */
#endif                                 /* RTW_HEADER_SOC_codegen_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
