/*
 * VITM_sf_data.c
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

#include "VITM_sf.h"
#include "VITM_sf_private.h"

/* Block parameters (auto storage) */
P_VITM_T VITM_DefaultP = {
  12.0,                                /* Variable: vitc_CellPackVolTol
                                        * Referenced by: '<S15>/Constant14'
                                        */
  10.0,                                /* Variable: vitc_CellTempFaultTimer
                                        * Referenced by:
                                        *   '<S5>/Constant11'
                                        *   '<S5>/Constant5'
                                        */
  1.0,                                 /* Variable: vitc_CellTempFilterC
                                        * Referenced by:
                                        *   '<S10>/Gain2'
                                        *   '<S10>/Gain3'
                                        */
  0.0,                                 /* Variable: vitc_CellTempHighFaultReset
                                        * Referenced by: '<S5>/Constant10'
                                        */
  0.0,                                 /* Variable: vitc_CellTempLowFaultReset
                                        * Referenced by: '<S5>/Constant4'
                                        */
  70.0,                                /* Variable: vitc_CellTempMax
                                        * Referenced by: '<S5>/Constant1'
                                        */
  -40.0,                               /* Variable: vitc_CellTempMin
                                        * Referenced by: '<S5>/Constant'
                                        */
  1.0,                                 /* Variable: vitc_CellVolFilterC
                                        * Referenced by:
                                        *   '<S2>/Gain'
                                        *   '<S2>/Gain1'
                                        */
  2.0,                                 /* Variable: vitc_CellVoltageFaultTimer
                                        * Referenced by:
                                        *   '<S6>/Constant11'
                                        *   '<S6>/Constant5'
                                        */
  0.0,                                 /* Variable: vitc_CellVoltageHighFaultReset
                                        * Referenced by: '<S6>/Constant10'
                                        */
  0.0,                                 /* Variable: vitc_CellVoltageLowFaultReset
                                        * Referenced by: '<S6>/Constant4'
                                        */
  4.2,                                 /* Variable: vitc_CellVoltageMax
                                        * Referenced by: '<S6>/Constant1'
                                        */
  2.7,                                 /* Variable: vitc_CellVoltageMin
                                        * Referenced by: '<S6>/Constant'
                                        */
  0.0,                                 /* Variable: vitc_CoolantInletTFaultReset
                                        * Referenced by: '<S7>/Constant22'
                                        */
  -40.0,                               /* Variable: vitc_CoolantInletTLowerLim
                                        * Referenced by: '<S7>/Constant3'
                                        */
  70.0,                                /* Variable: vitc_CoolantInletTUpperLim
                                        * Referenced by: '<S7>/Constant2'
                                        */
  0.0,                                 /* Variable: vitc_CoolantOutletTFaultReset
                                        * Referenced by: '<S8>/Constant22'
                                        */
  -40.0,                               /* Variable: vitc_CoolantOutletTLowerLim
                                        * Referenced by: '<S8>/Constant3'
                                        */
  70.0,                                /* Variable: vitc_CoolantOutletTUpperLim
                                        * Referenced by: '<S8>/Constant2'
                                        */
  0.9,                                 /* Variable: vitc_CoolantTFilterC
                                        * Referenced by:
                                        *   '<S11>/Gain'
                                        *   '<S11>/Gain1'
                                        *   '<S12>/Gain'
                                        *   '<S12>/Gain3'
                                        */
  5.0,                                 /* Variable: vitc_CoolantTempFaultCounter
                                        * Referenced by:
                                        *   '<S7>/Constant23'
                                        *   '<S8>/Constant23'
                                        */
  1.0,                                 /* Variable: vitc_HVILFaultCounter
                                        * Referenced by: '<S13>/Constant23'
                                        */
  0.0,                                 /* Variable: vitc_HVILFaultReset
                                        * Referenced by: '<S13>/Constant22'
                                        */
  1.0,                                 /* Variable: vitc_PackCurFilterC
                                        * Referenced by:
                                        *   '<S9>/Gain2'
                                        *   '<S9>/Gain3'
                                        */
  0.0,                                 /* Variable: vitc_PackCurrentFaultReset
                                        * Referenced by: '<S14>/Constant22'
                                        */
  1.0,                                 /* Variable: vitc_PackCurrentFaultTimer
                                        * Referenced by: '<S14>/Constant23'
                                        */
  300.0,                               /* Variable: vitc_PackCurrentLimit
                                        * Referenced by: '<S14>/Constant21'
                                        */
  1.0,                                 /* Variable: vitc_PackVolFilterC
                                        * Referenced by:
                                        *   '<S3>/Gain'
                                        *   '<S3>/Gain1'
                                        */
  0.0,                                 /* Variable: vitc_PackVoltageFaultReset
                                        * Referenced by: '<S15>/Constant15'
                                        */
  10.0,                                /* Variable: vitc_PackVoltageFaultTimer
                                        * Referenced by: '<S15>/Constant16'
                                        */
  1.0,                                 /* Variable: vitc_VehVolFilterC
                                        * Referenced by:
                                        *   '<S4>/Gain'
                                        *   '<S4>/Gain1'
                                        */
  1.0,                                 /* Variable: vitk_NumberInPara
                                        * Referenced by:
                                        *   '<S5>/Constant15'
                                        *   '<S6>/Constant15'
                                        */
  40.0,                                /* Variable: vitk_NumberInSeries
                                        * Referenced by:
                                        *   '<S5>/Constant14'
                                        *   '<S6>/Constant14'
                                        */
  0.1                                  /* Variable: vitk_stepSize
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
