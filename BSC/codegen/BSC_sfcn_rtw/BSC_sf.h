/*
 * BSC_sf.h
 *
 * Code generation for model "BSC_sf".
 *
 * Model version              : 1.222
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Fri Jun 12 17:13:53 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BSC_sf_h_
#define RTW_HEADER_BSC_sf_h_
#include <string.h>
#include <stddef.h>
#ifndef BSC_sf_COMMON_INCLUDES_
# define BSC_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                BSC_sf
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if !defined(MATLAB_MEX_FILE)
#include "rt_matrx.h"
#endif

#if !defined(RTW_SFUNCTION_DEFINES)
#define RTW_SFUNCTION_DEFINES

typedef struct {
  void *blockIO;
  void *defaultParam;
  void *nonContDerivSig;
} LocalS;

#define ssSetLocalBlockIO(S, io)       ((LocalS *)ssGetUserData(S))->blockIO = ((void *)(io))
#define ssGetLocalBlockIO(S)           ((LocalS *)ssGetUserData(S))->blockIO
#define ssSetLocalDefaultParam(S, paramVector) ((LocalS *)ssGetUserData(S))->defaultParam = (paramVector)
#define ssGetLocalDefaultParam(S)      ((LocalS *)ssGetUserData(S))->defaultParam
#define ssSetLocalNonContDerivSig(S, pSig) ((LocalS *)ssGetUserData(S))->nonContDerivSig = (pSig)
#define ssGetLocalNonContDerivSig(S)   ((LocalS *)ssGetUserData(S))->nonContDerivSig
#endif
#endif                                 /* BSC_sf_COMMON_INCLUDES_ */

#include "BSC_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Block signals for system '<S1>/check_type' */
typedef struct {
  uint8_T type_of_fault;               /* '<S5>/check_faults' */
} B_check_type_BSC_T;

/* Block signals for system '<S1>/key_cycle' */
typedef struct {
  uint8_T key_cycle;                   /* '<S6>/key_cycle_chart' */
} B_key_cycle_BSC_T;

/* Zero-crossing (trigger) state for system '<S1>/key_cycle' */
typedef struct {
  ZCSigState key_cycle_chart_Trig_ZCE[2];/* '<S6>/key_cycle_chart' */
} ZCE_key_cycle_BSC_T;

/* Block signals (auto storage) */
typedef struct {
  uint8_T Add;                         /* '<S7>/Add' */
  uint8_T Merge;                       /* '<S14>/Merge' */
  uint8_T MinMax;                      /* '<S3>/MinMax' */
  uint8_T MinMax1;                     /* '<S3>/MinMax1' */
  uint8_T MinMax2;                     /* '<S3>/MinMax2' */
  boolean_T LogicalOperator16;         /* '<S4>/Logical Operator16' */
  boolean_T LogicalOperator2;          /* '<S4>/Logical Operator2' */
  boolean_T LogicalOperator3;          /* '<S8>/Logical Operator3' */
  B_key_cycle_BSC_T key_cycle;         /* '<S1>/key_cycle' */
  B_check_type_BSC_T check_type;       /* '<S1>/check_type' */
} B_BSC_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S7>/Triggered Subsystem' */
  ZCE_key_cycle_BSC_T key_cycle;       /* '<S1>/key_cycle' */
} PrevZCX_BSC_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  uint8_T *VehiclePSR;                 /* '<Root>/Vehicle PSR' */
  uint8_T *ChargerPSR;                 /* '<Root>/Charger PSR' */
  uint8_T *key;                        /* '<Root>/key' */
  real_T *SOC;                         /* '<Root>/SOC' */
  uint8_T *highlevelfaultType1;        /* '<Root>/high level fault[Type1]' */
  uint8_T *mediumlevelfaultType2;      /* '<Root>/medium level fault[Type2]' */
  uint8_T *lowlevelfaultType3;         /* '<Root>/low level fault[Type3]' */
  uint8_T *vitm_CellsTemperatureLowFaultTy;/* '<Root>/vitm_CellsTemperatureLowFault[Type4]' */
  uint8_T *vitm_CellsTemperatureHighFaultT;/* '<Root>/vitm_CellsTemperatureHighFault[Type5]' */
  uint8_T *vitm_CellsVoltageLowFaultType6;/* '<Root>/vitm_CellsVoltageLowFault[Type6]' */
  uint8_T *vitm_CellsVoltageHightFaultType;/* '<Root>/vitm_CellsVoltageHightFault[Type7]' */
  uint8_T *vitm_PackVoltageFaultType8; /* '<Root>/vitm_PackVoltageFault[Type8]' */
  uint8_T *vitm_PackCurrentFaultType9; /* '<Root>/vitm_PackCurrentFault[Type9]' */
  uint8_T *vitm_HVILFaultType10;       /* '<Root>/vitm_HVILFault[Type10]' */
  uint8_T *cc_PrechargeFaultType11;    /* '<Root>/cc_PrechargeFault[Type11]' */
} ExternalUPtrs_BSC_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  boolean_T *CVTNsupplysignal;         /* '<Root>/CVTN supply signal' */
  boolean_T *MainContactorCmd;         /* '<Root>/Main Contactor Cmd' */
  boolean_T *ChargerContactorCmd;      /* '<Root>/Charger Contactor Cmd' */
  boolean_T *SleepMode;                /* '<Root>/Sleep Mode' */
  uint8_T *ReasontoopencontactortoCAN; /* '<Root>/Reason to open contactor to CAN' */
  uint8_T *SevereMediumFault;          /* '<Root>/Severe//Medium Fault' */
  uint8_T *LowFault;                   /* '<Root>/Low Fault' */
  uint8_T *FaultType;                  /* '<Root>/Fault Type' */
} ExtY_BSC_T;

/* Parameters (auto storage) */
struct P_BSC_T_ {
  uint8_T bscv_LowFaultType[7];        /* Variable: bscv_LowFaultType
                                        * Referenced by: '<S11>/Constant'
                                        */
  uint8_T bscv_MediumFaultType[3];     /* Variable: bscv_MediumFaultType
                                        * Referenced by: '<S10>/Constant'
                                        */
  uint8_T bscv_SevereFaultType;        /* Variable: bscv_SevereFaultType
                                        * Referenced by: '<S9>/Constant'
                                        */
};

extern P_BSC_T BSC_DefaultP;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('BSC_codegen/BSC')    - opens subsystem BSC_codegen/BSC
 * hilite_system('BSC_codegen/BSC/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BSC_codegen'
 * '<S1>'   : 'BSC_codegen/BSC'
 * '<S2>'   : 'BSC_codegen/BSC/Chart2'
 * '<S3>'   : 'BSC_codegen/BSC/Fault_level'
 * '<S4>'   : 'BSC_codegen/BSC/cc_c  md'
 * '<S5>'   : 'BSC_codegen/BSC/check_type'
 * '<S6>'   : 'BSC_codegen/BSC/key_cycle'
 * '<S7>'   : 'BSC_codegen/BSC/rsnToOpenCC'
 * '<S8>'   : 'BSC_codegen/BSC/sleepCheck'
 * '<S9>'   : 'BSC_codegen/BSC/Fault_level/Compare To Constant'
 * '<S10>'  : 'BSC_codegen/BSC/Fault_level/Compare To Constant1'
 * '<S11>'  : 'BSC_codegen/BSC/Fault_level/Compare To Constant2'
 * '<S12>'  : 'BSC_codegen/BSC/check_type/check_faults'
 * '<S13>'  : 'BSC_codegen/BSC/key_cycle/key_cycle_chart'
 * '<S14>'  : 'BSC_codegen/BSC/rsnToOpenCC/Triggered Subsystem'
 * '<S15>'  : 'BSC_codegen/BSC/rsnToOpenCC/Triggered Subsystem/If Action Subsystem'
 * '<S16>'  : 'BSC_codegen/BSC/rsnToOpenCC/Triggered Subsystem/If Action Subsystem1'
 * '<S17>'  : 'BSC_codegen/BSC/sleepCheck/Compare To Constant1'
 */
#endif                                 /* RTW_HEADER_BSC_sf_h_ */
