/*
 * Cell0_sid.h
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
 *
 * SOURCES: Cell0_sf.c
 */

/* statically allocated instance data for model: Cell0 */
{
  extern P_Cell0_T Cell0_DefaultP;

  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* model parameters */
    ssSetLocalDefaultParam(rts, (real_T *) &Cell0_DefaultP);

    /* model checksums */
    ssSetChecksumVal(rts, 0, 4188228307U);
    ssSetChecksumVal(rts, 1, 1016634633U);
    ssSetChecksumVal(rts, 2, 2976067392U);
    ssSetChecksumVal(rts, 3, 2329952992U);
  }
}
