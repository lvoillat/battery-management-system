/*
 * BSC_mid.h
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

#include "simstruc.h"
#include "BSC_sf.h"
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

/* Instance data for model: BSC */
void *BSC_malloc(SimStruct *rts)
{
  /* Local SimStruct for the generated S-Function */
  LocalS *lS = (LocalS *) malloc(sizeof(LocalS));
  ss_VALIDATE_MEMORY(rts,lS);
  (void) memset((char *) lS, 0,
                sizeof(LocalS));
  ssSetUserData(rts, lS);

  /* block I/O */
  {
    void *b = malloc(sizeof(B_BSC_T));
    ss_VALIDATE_MEMORY(rts,b);
    ssSetLocalBlockIO(rts, b);
    (void) memset(b, 0,
                  sizeof(B_BSC_T));
  }

  /* model parameters */
  ssSetLocalDefaultParam(rts, (real_T *) &BSC_DefaultP);

  /* previous zero-crossing states */
  {
    int_T i;
    ZCSigState *zc = (ZCSigState *) malloc(sizeof(PrevZCX_BSC_T));
    ss_VALIDATE_MEMORY(rts,zc);
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
  return (NULL);
}
