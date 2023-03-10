/*
 * BSC_sf_data.c
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

#include "BSC_sf.h"
#include "BSC_sf_private.h"

/* Block parameters (auto storage) */
P_BSC_T BSC_DefaultP = {
  /*  Variable: bscv_LowFaultType
   * Referenced by: '<S11>/Constant'
   */
  { 3U, 4U, 5U, 6U, 7U, 8U, 9U },

  /*  Variable: bscv_MediumFaultType
   * Referenced by: '<S10>/Constant'
   */
  { 2U, 10U, 11U },
  1U                                   /* Variable: bscv_SevereFaultType
                                        * Referenced by: '<S9>/Constant'
                                        */
};
