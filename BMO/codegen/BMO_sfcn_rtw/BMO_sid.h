/*
 * BMO_sid.h
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
 *
 * SOURCES: BMO_sf.c
 */

/* statically allocated instance data for model: BMO */
{
  extern P_BMO_T BMO_DefaultP;

  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_BMO_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_BMO_T));
    }

    /* model parameters */
    ssSetLocalDefaultParam(rts, (real_T *) &BMO_DefaultP);

    /* model checksums */
    ssSetChecksumVal(rts, 0, 2140266800U);
    ssSetChecksumVal(rts, 1, 1385541025U);
    ssSetChecksumVal(rts, 2, 102416638U);
    ssSetChecksumVal(rts, 3, 1741191447U);
  }
}
