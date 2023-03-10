/*
 * VITM_sf.h
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

#ifndef RTW_HEADER_VITM_sf_h_
#define RTW_HEADER_VITM_sf_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef VITM_sf_COMMON_INCLUDES_
# define VITM_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                VITM_sf
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
#endif                                 /* VITM_sf_COMMON_INCLUDES_ */

#include "VITM_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rtGetInf.h"
#include "rt_defines.h"

/* Block signals (auto storage) */
typedef struct {
  real_T Add3;                         /* '<S7>/Add3' */
  real_T Add3_c;                       /* '<S8>/Add3' */
  real_T Gain1;                        /* '<S11>/Gain1' */
  real_T Gain3;                        /* '<S12>/Gain3' */
  real_T Add;                          /* '<S5>/Add' */
  real_T Add1;                         /* '<S5>/Add1' */
  real_T Gain3_n[40];                  /* '<S10>/Gain3' */
  real_T Add_n[40];                    /* '<S2>/Add' */
  real_T Gain1_b[40];                  /* '<S2>/Gain1' */
  real_T Add_f;                        /* '<S3>/Add' */
  real_T Gain1_d;                      /* '<S3>/Gain1' */
  real_T Add_o;                        /* '<S6>/Add' */
  real_T Add1_i;                       /* '<S6>/Add1' */
  real_T Add2;                         /* '<S15>/Add2' */
  real_T Gain3_nj;                     /* '<S9>/Gain3' */
  real_T Add3_m;                       /* '<S14>/Add3' */
  real_T Add3_j;                       /* '<S13>/Add3' */
  real_T Gain1_l;                      /* '<S4>/Gain1' */
} B_VITM_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState ResettableDelay3_Reset_ZCE;/* '<S7>/Resettable Delay3' */
  ZCSigState ResettableDelay3_Reset_ZCE_g;/* '<S8>/Resettable Delay3' */
  ZCSigState ResettableDelay_Reset_ZCE;/* '<S5>/Resettable Delay' */
  ZCSigState ResettableDelay1_Reset_ZCE;/* '<S5>/Resettable Delay1' */
  ZCSigState ResettableDelay_Reset_ZCE_a;/* '<S6>/Resettable Delay' */
  ZCSigState ResettableDelay1_Reset_ZCE_n;/* '<S6>/Resettable Delay1' */
  ZCSigState ResettableDelay2_Reset_ZCE;/* '<S15>/Resettable Delay2' */
  ZCSigState ResettableDelay3_Reset_ZCE_i;/* '<S14>/Resettable Delay3' */
  ZCSigState ResettableDelay3_Reset_ZCE_f;/* '<S13>/Resettable Delay3' */
} PrevZCX_VITM_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *CellVoltages[40];            /* '<Root>/CellVoltages' */
  real_T *PackVoltage;                 /* '<Root>/PackVoltage' */
  real_T *VehSideVoltage;              /* '<Root>/VehSideVoltage' */
  real_T *PackCurrent;                 /* '<Root>/PackCurrent' */
  real_T *CoolantInletT;               /* '<Root>/CoolantInletT' */
  real_T *CoolantOutletT;              /* '<Root>/CoolantOutletT' */
  real_T *CellsTemperature[40];        /* '<Root>/CellsTemperature' */
  real_T *HVILReturn;                  /* '<Root>/HVILReturn' */
} ExternalUPtrs_VITM_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *vitm_CellsMaxTemperature;    /* '<Root>/vitm_CellsMaxTemperature' */
  real_T *vitm_CellsMinTemperature;    /* '<Root>/vitm_CellsMinTemperature' */
  real_T *vitm_CellsAvgTemperature;    /* '<Root>/vitm_CellsAvgTemperature' */
  uint8_T *vitm_CellsTemperatureLowFault;/* '<Root>/vitm_CellsTemperatureLowFault' */
  uint8_T *vitm_CellsTemperatureHighFault;/* '<Root>/vitm_CellsTemperatureHighFault' */
  uint8_T *vitm_CellsVoltageLowFault;  /* '<Root>/vitm_CellsVoltageLowFault' */
  uint8_T *vitm_CellsVoltageHighFault; /* '<Root>/vitm_CellsVoltageHighFault' */
  uint8_T *vitm_PackVoltageFault;      /* '<Root>/vitm_PackVoltageFault' */
  real_T *vitm_CellsMinVoltage;        /* '<Root>/vitm_CellsMinVoltage' */
  real_T *vitm_CellsMaxVoltage;        /* '<Root>/vitm_CellsMaxVoltage' */
  real_T *vitm_CellsAvgVoltage;        /* '<Root>/vitm_CellsAvgVoltage' */
  real_T *vitm_PackVoltageFiltered;    /* '<Root>/vitm_PackVoltageFiltered' */
  real_T *vitm_PackCurrentFiltered;    /* '<Root>/vitm_PackCurrentFiltered' */
  uint8_T *vitm_PackCurrentFault;      /* '<Root>/vitm_PackCurrentFault' */
  real_T *vitm_CoolantDeltaTemp;       /* '<Root>/vitm_CoolantDeltaTemp' */
  uint8_T *vitm_CoolantInletTempFault; /* '<Root>/vitm_CoolantInletTempFault' */
  uint8_T *vitm_CoolantOutlletTempFault;/* '<Root>/vitm_CoolantOutlletTempFault' */
  real_T *vitm_CoolantInletTFiltered;  /* '<Root>/vitm_CoolantInletTFiltered' */
  real_T *vitm_CoolantOutletTFiltered; /* '<Root>/vitm_CoolantOutletTFiltered' */
  uint8_T *vitm_HVILFault;             /* '<Root>/vitm_HVILFault' */
  real_T *vitm_CellsTemperatureFiltered[40];/* '<Root>/vitm_CellsTemperatureFiltered' */
  real_T *vitm_CellsVoltageFiltered[40];/* '<Root>/vitm_CellsVoltageFiltered' */
  real_T *vitm_VehSideVoltageFiltered; /* '<Root>/vitm_VehSideVoltageFiltered' */
} ExtY_VITM_T;

/* Parameters (auto storage) */
struct P_VITM_T_ {
  real_T vitc_CellPackVolTol;          /* Variable: vitc_CellPackVolTol
                                        * Referenced by: '<S15>/Constant14'
                                        */
  real_T vitc_CellTempFaultTimer;      /* Variable: vitc_CellTempFaultTimer
                                        * Referenced by:
                                        *   '<S5>/Constant11'
                                        *   '<S5>/Constant5'
                                        */
  real_T vitc_CellTempFilterC;         /* Variable: vitc_CellTempFilterC
                                        * Referenced by:
                                        *   '<S10>/Gain2'
                                        *   '<S10>/Gain3'
                                        */
  real_T vitc_CellTempHighFaultReset;  /* Variable: vitc_CellTempHighFaultReset
                                        * Referenced by: '<S5>/Constant10'
                                        */
  real_T vitc_CellTempLowFaultReset;   /* Variable: vitc_CellTempLowFaultReset
                                        * Referenced by: '<S5>/Constant4'
                                        */
  real_T vitc_CellTempMax;             /* Variable: vitc_CellTempMax
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T vitc_CellTempMin;             /* Variable: vitc_CellTempMin
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T vitc_CellVolFilterC;          /* Variable: vitc_CellVolFilterC
                                        * Referenced by:
                                        *   '<S2>/Gain'
                                        *   '<S2>/Gain1'
                                        */
  real_T vitc_CellVoltageFaultTimer;   /* Variable: vitc_CellVoltageFaultTimer
                                        * Referenced by:
                                        *   '<S6>/Constant11'
                                        *   '<S6>/Constant5'
                                        */
  real_T vitc_CellVoltageHighFaultReset;/* Variable: vitc_CellVoltageHighFaultReset
                                         * Referenced by: '<S6>/Constant10'
                                         */
  real_T vitc_CellVoltageLowFaultReset;/* Variable: vitc_CellVoltageLowFaultReset
                                        * Referenced by: '<S6>/Constant4'
                                        */
  real_T vitc_CellVoltageMax;          /* Variable: vitc_CellVoltageMax
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T vitc_CellVoltageMin;          /* Variable: vitc_CellVoltageMin
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T vitc_CoolantInletTFaultReset; /* Variable: vitc_CoolantInletTFaultReset
                                        * Referenced by: '<S7>/Constant22'
                                        */
  real_T vitc_CoolantInletTLowerLim;   /* Variable: vitc_CoolantInletTLowerLim
                                        * Referenced by: '<S7>/Constant3'
                                        */
  real_T vitc_CoolantInletTUpperLim;   /* Variable: vitc_CoolantInletTUpperLim
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T vitc_CoolantOutletTFaultReset;/* Variable: vitc_CoolantOutletTFaultReset
                                        * Referenced by: '<S8>/Constant22'
                                        */
  real_T vitc_CoolantOutletTLowerLim;  /* Variable: vitc_CoolantOutletTLowerLim
                                        * Referenced by: '<S8>/Constant3'
                                        */
  real_T vitc_CoolantOutletTUpperLim;  /* Variable: vitc_CoolantOutletTUpperLim
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real_T vitc_CoolantTFilterC;         /* Variable: vitc_CoolantTFilterC
                                        * Referenced by:
                                        *   '<S11>/Gain'
                                        *   '<S11>/Gain1'
                                        *   '<S12>/Gain'
                                        *   '<S12>/Gain3'
                                        */
  real_T vitc_CoolantTempFaultCounter; /* Variable: vitc_CoolantTempFaultCounter
                                        * Referenced by:
                                        *   '<S7>/Constant23'
                                        *   '<S8>/Constant23'
                                        */
  real_T vitc_HVILFaultCounter;        /* Variable: vitc_HVILFaultCounter
                                        * Referenced by: '<S13>/Constant23'
                                        */
  real_T vitc_HVILFaultReset;          /* Variable: vitc_HVILFaultReset
                                        * Referenced by: '<S13>/Constant22'
                                        */
  real_T vitc_PackCurFilterC;          /* Variable: vitc_PackCurFilterC
                                        * Referenced by:
                                        *   '<S9>/Gain2'
                                        *   '<S9>/Gain3'
                                        */
  real_T vitc_PackCurrentFaultReset;   /* Variable: vitc_PackCurrentFaultReset
                                        * Referenced by: '<S14>/Constant22'
                                        */
  real_T vitc_PackCurrentFaultTimer;   /* Variable: vitc_PackCurrentFaultTimer
                                        * Referenced by: '<S14>/Constant23'
                                        */
  real_T vitc_PackCurrentLimit;        /* Variable: vitc_PackCurrentLimit
                                        * Referenced by: '<S14>/Constant21'
                                        */
  real_T vitc_PackVolFilterC;          /* Variable: vitc_PackVolFilterC
                                        * Referenced by:
                                        *   '<S3>/Gain'
                                        *   '<S3>/Gain1'
                                        */
  real_T vitc_PackVoltageFaultReset;   /* Variable: vitc_PackVoltageFaultReset
                                        * Referenced by: '<S15>/Constant15'
                                        */
  real_T vitc_PackVoltageFaultTimer;   /* Variable: vitc_PackVoltageFaultTimer
                                        * Referenced by: '<S15>/Constant16'
                                        */
  real_T vitc_VehVolFilterC;           /* Variable: vitc_VehVolFilterC
                                        * Referenced by:
                                        *   '<S4>/Gain'
                                        *   '<S4>/Gain1'
                                        */
  real_T vitk_NumberInPara;            /* Variable: vitk_NumberInPara
                                        * Referenced by:
                                        *   '<S5>/Constant15'
                                        *   '<S6>/Constant15'
                                        */
  real_T vitk_NumberInSeries;          /* Variable: vitk_NumberInSeries
                                        * Referenced by:
                                        *   '<S5>/Constant14'
                                        *   '<S6>/Constant14'
                                        */
  real_T vitk_stepSize;                /* Variable: vitk_stepSize
                                        * Referenced by:
                                        *   '<S5>/Constant11'
                                        *   '<S5>/Constant5'
                                        *   '<S6>/Constant11'
                                        *   '<S6>/Constant5'
                                        *   '<S7>/Constant23'
                                        *   '<S8>/Constant23'
                                        *   '<S13>/Constant23'
                                        *   '<S14>/Constant23'
                                        *   '<S15>/Constant16'
                                        */
};

extern P_VITM_T VITM_DefaultP;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S10>/Constant14' : Unused code path elimination
 * Block '<S10>/Constant15' : Unused code path elimination
 * Block '<S10>/Divide' : Unused code path elimination
 * Block '<S10>/Divide1' : Unused code path elimination
 * Block '<S10>/Sum of Elements' : Unused code path elimination
 */

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
 * hilite_system('VITM_codegen/VITM')    - opens subsystem VITM_codegen/VITM
 * hilite_system('VITM_codegen/VITM/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'VITM_codegen'
 * '<S1>'   : 'VITM_codegen/VITM'
 * '<S2>'   : 'VITM_codegen/VITM/ Filter for Cell Voltages'
 * '<S3>'   : 'VITM_codegen/VITM/ Filter for Pack Voltage'
 * '<S4>'   : 'VITM_codegen/VITM/ Filter for Pack Voltage1'
 * '<S5>'   : 'VITM_codegen/VITM/Cell Temperature Fault Detection'
 * '<S6>'   : 'VITM_codegen/VITM/Cell Voltage Fault Detection'
 * '<S7>'   : 'VITM_codegen/VITM/Coolant  Inlet Temp Fault Detection'
 * '<S8>'   : 'VITM_codegen/VITM/Coolant  Outlet Temp Fault Detection'
 * '<S9>'   : 'VITM_codegen/VITM/Filter  for Pack Current'
 * '<S10>'  : 'VITM_codegen/VITM/Filter for Cell Temperature'
 * '<S11>'  : 'VITM_codegen/VITM/Filter for Coolant Inlet Temperature'
 * '<S12>'  : 'VITM_codegen/VITM/Filter for Coolant outlet Temperature'
 * '<S13>'  : 'VITM_codegen/VITM/HVIL Fault'
 * '<S14>'  : 'VITM_codegen/VITM/Pack Current Fault Detection'
 * '<S15>'  : 'VITM_codegen/VITM/Pack Voltage Fault Detection'
 */
#endif                                 /* RTW_HEADER_VITM_sf_h_ */
