/*
 * SOP_sid.h
 *
 * Code generation for model "SOP_sf".
 *
 * Model version              : 1.51
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed May 27 11:06:28 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: SOP_sf.c
 */

/* statically allocated instance data for model: SOP */
{
  extern P_SOP_T SOP_DefaultP;

  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* model parameters */
    ssSetLocalDefaultParam(rts, (real_T *) &SOP_DefaultP);

    /* model checksums */
    ssSetChecksumVal(rts, 0, 3528231100U);
    ssSetChecksumVal(rts, 1, 2882528961U);
    ssSetChecksumVal(rts, 2, 1420291852U);
    ssSetChecksumVal(rts, 3, 1868096065U);
  }
}
