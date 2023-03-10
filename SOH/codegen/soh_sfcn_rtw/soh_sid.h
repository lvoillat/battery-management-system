/*
 * soh_sid.h
 *
 * Code generation for model "soh_sf".
 *
 * Model version              : 1.270
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed May 27 10:32:13 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: soh_sf.c
 */

/* statically allocated instance data for model: soh */
{
  extern P_soh_T soh_DefaultP;

  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_soh_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_soh_T));
    }

    /* model parameters */
    ssSetLocalDefaultParam(rts, (real_T *) &soh_DefaultP);

    /* previous zero-crossing states */
    {
      int_T i;
      static PrevZCX_soh_T soh_PrevZCX;
      ZCSigState *zc = (ZCSigState *) &soh_PrevZCX;
      _ssSetPrevZCSigState(rts, zc);
      for (i = 0; i < 1; i++) {
        zc[i] = UNINITIALIZED_ZCSIG;
      }
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 2469900872U);
    ssSetChecksumVal(rts, 1, 3123331729U);
    ssSetChecksumVal(rts, 2, 3802819679U);
    ssSetChecksumVal(rts, 3, 2205412285U);
  }
}
