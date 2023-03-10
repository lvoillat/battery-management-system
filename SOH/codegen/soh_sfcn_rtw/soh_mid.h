/*
 * soh_mid.h
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

#include "simstruc.h"
#include "soh_sf.h"
#if defined(MATLAB_MEX_FILE) || defined(RT_MALLOC)

static int_T RegNumInputPorts(SimStruct *S, int_T nInputPorts)
{
  _ssSetNumInputPorts(S,nInputPorts);
  return true;
}

static int_T RegNumOutputPorts(SimStruct *S, int_T nOutputPorts)
{
  _ssSetNumOutputPorts(S,nOutputPorts);
  return true;
}

static int_T FcnSetErrorStatus(const SimStruct *S, DTypeId arg2)
{
  static char msg[256];
  if (strlen(ssGetModelName(S)) < 128) {
    sprintf(msg,
            "S-function %s does not have a tlc file. It cannot use macros that access regDataType field in simstruct.",
            ssGetModelName(S));
  } else {
    sprintf(msg,
            "A S-function does not have a tlc file. It cannot use macros that access regDataType field in simstruct.");
  }

  ssSetErrorStatus(S, msg);
  UNUSED_PARAMETER(arg2);
  return 0;
}

#endif

/* Instance data for model: soh */
void *soh_malloc(SimStruct *rts)
{
  /* Local SimStruct for the generated S-Function */
  LocalS *lS = (LocalS *) malloc(sizeof(LocalS));
  ss_VALIDATE_MEMORY(rts,lS);
  (void) memset((char *) lS, 0,
                sizeof(LocalS));
  ssSetUserData(rts, lS);

  /* block I/O */
  {
    void *b = malloc(sizeof(B_soh_T));
    ss_VALIDATE_MEMORY(rts,b);
    ssSetLocalBlockIO(rts, b);
    (void) memset(b, 0,
                  sizeof(B_soh_T));
  }

  /* model parameters */
  ssSetLocalDefaultParam(rts, (real_T *) &soh_DefaultP);

  /* previous zero-crossing states */
  {
    int_T i;
    ZCSigState *zc = (ZCSigState *) malloc(sizeof(PrevZCX_soh_T));
    ss_VALIDATE_MEMORY(rts,zc);
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
  return (NULL);
}
