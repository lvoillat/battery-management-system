/*
 * BSC_sid.h
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
 *
 * SOURCES: BSC_sf.c
 */

/* statically allocated instance data for model: BSC */
{
  extern P_BSC_T BSC_DefaultP;

  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_BSC_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_BSC_T));
    }

    /* model parameters */
    ssSetLocalDefaultParam(rts, (real_T *) &BSC_DefaultP);

    /* previous zero-crossing states */
    {
      int_T i;
      static PrevZCX_BSC_T BSC_PrevZCX;
      ZCSigState *zc = (ZCSigState *) &BSC_PrevZCX;
      _ssSetPrevZCSigState(rts, zc);
      for (i = 0; i < 3; i++) {
        zc[i] = UNINITIALIZED_ZCSIG;
      }
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 1024548517U);
    ssSetChecksumVal(rts, 1, 3942385062U);
    ssSetChecksumVal(rts, 2, 3119300415U);
    ssSetChecksumVal(rts, 3, 1975729462U);
  }
}
