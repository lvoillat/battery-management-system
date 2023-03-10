/*
 * CC_sid.h
 *
 * Code generation for model "CC_sf".
 *
 * Model version              : 1.109
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Tue May 26 21:06:25 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: CC_sf.c
 */

/* statically allocated instance data for model: CC */
{
  extern P_CC_T CC_DefaultP;

  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_CC_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_CC_T));
    }

    /* model parameters */
    ssSetLocalDefaultParam(rts, (real_T *) &CC_DefaultP);

    /* previous zero-crossing states */
    {
      int_T i;
      static PrevZCX_CC_T CC_PrevZCX;
      ZCSigState *zc = (ZCSigState *) &CC_PrevZCX;
      _ssSetPrevZCSigState(rts, zc);
      for (i = 0; i < 1; i++) {
        zc[i] = UNINITIALIZED_ZCSIG;
      }
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 2323400953U);
    ssSetChecksumVal(rts, 1, 1423465098U);
    ssSetChecksumVal(rts, 2, 3251607318U);
    ssSetChecksumVal(rts, 3, 3849565157U);
  }
}
