/*
 * BTC_sid.h
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
 *
 * SOURCES: BTC_sf.c
 */

/* statically allocated instance data for model: BTC */
{
  extern P_BTC_T BTC_DefaultP;

  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_BTC_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_BTC_T));
    }

    /* model parameters */
    ssSetLocalDefaultParam(rts, (real_T *) &BTC_DefaultP);

    /* model checksums */
    ssSetChecksumVal(rts, 0, 3379528791U);
    ssSetChecksumVal(rts, 1, 2610076075U);
    ssSetChecksumVal(rts, 2, 4283593856U);
    ssSetChecksumVal(rts, 3, 1717127276U);
  }
}
