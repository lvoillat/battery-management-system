/*
 * Cell0_sf_data.c
 *
 * Code generation for model "Cell0_sf".
 *
 * Model version              : 1.35
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed May 27 11:18:31 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Cell0_sf.h"
#include "Cell0_sf_private.h"

/* Block parameters (auto storage) */
P_Cell0_T Cell0_DefaultP = {
  5.0,                                 /* Variable: cblc_battChargingMode
                                        * Referenced by: '<S1>/Constant1'
                                        */
  0.1,                                 /* Variable: cblc_deltaSocThreshBalance
                                        * Referenced by: '<S1>/Constant2'
                                        */
  50.0                                 /* Variable: cblc_socThreshBalance
                                        * Referenced by: '<S1>/Constant6'
                                        */
};
