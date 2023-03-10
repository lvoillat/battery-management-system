/*
 * BMO_sf_data.c
 *
 * Code generation for model "BMO_sf".
 *
 * Model version              : 1.57
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed May 27 09:55:10 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BMO_sf.h"
#include "BMO_sf_private.h"

/* Block parameters (auto storage) */
P_BMO_T BMO_DefaultP = {
  1.0,                                 /* Variable: BMOk_BatteryCurrentThresh
                                        * Referenced by: '<S1>/Chart'
                                        */
  2U,                                  /* Variable: BMOk_CcClosing
                                        * Referenced by: '<S1>/Chart'
                                        */
  4U,                                  /* Variable: BMOk_CcOpening
                                        * Referenced by: '<S1>/Chart'
                                        */
  5U,                                  /* Variable: BMOk_Charging
                                        * Referenced by:
                                        *   '<S1>/Chart'
                                        *   '<S3>/Constant'
                                        */
  6U,                                  /* Variable: BMOk_ChargingSleep
                                        * Referenced by: '<S1>/Chart'
                                        */
  7U,                                  /* Variable: BMOk_Discharging
                                        * Referenced by:
                                        *   '<S1>/Chart'
                                        *   '<S4>/Constant'
                                        */
  0U,                                  /* Variable: BMOk_Off
                                        * Referenced by: '<S1>/Chart'
                                        */
  1U,                                  /* Variable: BMOk_On
                                        * Referenced by: '<S1>/Chart'
                                        */
  3U,                                  /* Variable: BMOk_PowerClosed
                                        * Referenced by: '<S1>/Chart'
                                        */
  0U,                                  /* Variable: BMOk_PowerOff
                                        * Referenced by: '<S1>/Chart'
                                        */
  1U                                   /* Variable: BMOk_PowerOn
                                        * Referenced by: '<S1>/Chart'
                                        */
};
