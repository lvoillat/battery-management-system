/*
 * VITM_sid.h
 *
 * Code generation for model "VITM_sf".
 *
 * Model version              : 1.125
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed May 27 10:18:24 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: VITM_sf.c
 */

/* statically allocated instance data for model: VITM */
{
  extern P_VITM_T VITM_DefaultP;

  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_VITM_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_VITM_T));
    }

    /* model parameters */
    ssSetLocalDefaultParam(rts, (real_T *) &VITM_DefaultP);

    /* previous zero-crossing states */
    {
      int_T i;
      static PrevZCX_VITM_T VITM_PrevZCX;
      ZCSigState *zc = (ZCSigState *) &VITM_PrevZCX;
      _ssSetPrevZCSigState(rts, zc);
      for (i = 0; i < 9; i++) {
        zc[i] = UNINITIALIZED_ZCSIG;
      }
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 1146590582U);
    ssSetChecksumVal(rts, 1, 314773117U);
    ssSetChecksumVal(rts, 2, 334333490U);
    ssSetChecksumVal(rts, 3, 3649190524U);
  }
}
