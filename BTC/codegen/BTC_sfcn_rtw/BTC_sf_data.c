/*
 * BTC_sf_data.c
 *
 * Code generation for model "BTC_sf".
 *
 * Model version              : 1.56
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed May 27 11:48:01 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BTC_sf.h"
#include "BTC_sf_private.h"

/* Block parameters (auto storage) */
P_BTC_T BTC_DefaultP = {
  0.5,                                 /* Variable: btcc_Ki
                                        * Referenced by: '<S4>/BTC_Ki'
                                        */
  2.0,                                 /* Variable: btcc_Kp
                                        * Referenced by: '<S4>/BTC_Kp'
                                        */
  45.0,                                /* Variable: btcc_ambient_temp_highth
                                        * Referenced by: '<S3>/Constant8'
                                        */
  -30.0,                               /* Variable: btcc_ambient_temp_lowth
                                        * Referenced by: '<S3>/Constant9'
                                        */
  5.0,                                 /* Variable: btcc_cell_temp_diffth
                                        * Referenced by: '<S3>/Constant4'
                                        */
  95.0,                                /* Variable: btcc_full_soc
                                        * Referenced by: '<S3>/Constant7'
                                        */
  40.0,                                /* Variable: btcc_max_temp_highth
                                        * Referenced by: '<S3>/Constant2'
                                        */
  35.0,                                /* Variable: btcc_max_temp_lowth
                                        * Referenced by: '<S3>/Constant3'
                                        */
  25.0,                                /* Variable: btcc_min_temp_highth
                                        * Referenced by: '<S3>/Constant1'
                                        */
  20.0,                                /* Variable: btcc_min_temp_lowth
                                        * Referenced by:
                                        *   '<S2>/Constant9'
                                        *   '<S3>/Constant'
                                        */
  40.0,                                /* Variable: btcc_number_in_series
                                        * Referenced by: '<S3>/Constant6'
                                        */
  1.0,                                 /* Variable: btcc_pack_in_parallel
                                        * Referenced by: '<S3>/Constant5'
                                        */
  0.1                                  /* Variable: btck_stepSize
                                        * Referenced by: '<S4>/Constant5'
                                        */
};
