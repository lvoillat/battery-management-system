/*
 * BMO_sf.c
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
 */

#include <math.h>
#include "BMO_sf.h"
#include "BMO_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"

/* Named constants for Chart: '<S1>/Chart' */
#define BMO_IN_Charging                ((uint8_T)1U)
#define BMO_IN_Charging_Sleep          ((uint8_T)1U)
#define BMO_IN_Closing_Contactors      ((uint8_T)2U)
#define BMO_IN_Closing_MainContactors  ((uint8_T)3U)
#define BMO_IN_Discharging             ((uint8_T)2U)
#define BMO_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define BMO_IN_Opening_Contactors      ((uint8_T)4U)
#define BMO_IN_Power_Closed            ((uint8_T)5U)
#define BMO_IN_Power_Closed_Default    ((uint8_T)3U)
#define BMO_IN_Power_OFF               ((uint8_T)6U)
#define BMO_IN_Power_ON                ((uint8_T)7U)
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *BMO_malloc(SimStruct *S);

#endif

#ifndef __RTW_UTFREE__
#if defined (MATLAB_MEX_FILE)

extern void * utMalloc(size_t);
extern void utFree(void *);

#endif
#endif                                 /* #ifndef __RTW_UTFREE__ */

#if defined(MATLAB_MEX_FILE)
#include "rt_nonfinite.c"
#endif

static const char_T *RT_MEMORY_ALLOCATION_ERROR =
  "memory allocation error in generated S-Function";

/* Initial conditions for root system: '<Root>' */
#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  B_BMO_T *_rtB;
  _rtB = ((B_BMO_T *) ssGetLocalBlockIO(S));

  /* InitializeConditions for Atomic SubSystem: '<Root>/BMO' */
  /* InitializeConditions for Chart: '<S1>/Chart' */
  ((uint8_T *)ssGetDWork(S, 1))[0] = BMO_IN_NO_ACTIVE_CHILD;
  ((uint8_T *)ssGetDWork(S, 2))[0] = 0U;
  ((uint8_T *)ssGetDWork(S, 0))[0] = BMO_IN_NO_ACTIVE_CHILD;
  _rtB->battery_mode = 0U;

  /* End of InitializeConditions for SubSystem: '<Root>/BMO' */
}

/* Start for root system: '<Root>' */
#define MDL_START

static void mdlStart(SimStruct *S)
{
  /* instance underlying S-Function data */
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  if defined(MATLAB_MEX_FILE)

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

#  endif

  BMO_malloc(S);
  if (ssGetErrorStatus(S) != (NULL) ) {
    return;
  }

#endif

  {
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  uint8_T rtb_DataTypeConversion1;
  boolean_T rtb_LogicalOperator;
  B_BMO_T *_rtB;
  P_BMO_T *_rtP;
  _rtP = ((P_BMO_T *) ssGetLocalDefaultParam(S));
  _rtB = ((B_BMO_T *) ssGetLocalBlockIO(S));

  /* Outputs for Atomic SubSystem: '<Root>/BMO' */
  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/charger_button'
   *  Inport: '<Root>/key'
   *  Logic: '<S1>/Logical Operator1'
   */
  rtb_DataTypeConversion1 = (uint8_T)((*((const uint8_T **)
    ssGetInputPortSignalPtrs(S, 3))[0] != 0) || (*((const uint8_T **)
    ssGetInputPortSignalPtrs(S, 4))[0] != 0));

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Inport: '<Root>/charger_cc'
   *  Inport: '<Root>/main_chrg_cc'
   */
  rtb_LogicalOperator = ((*((const boolean_T **)ssGetInputPortSignalPtrs(S, 6))
    [0]) || (*((const boolean_T **)ssGetInputPortSignalPtrs(S, 7))[0]));

  /* Chart: '<S1>/Chart' incorporates:
   *  Inport: '<Root>/bmon_pack_current'
   *  Inport: '<Root>/pre_charge_cc'
   *  Inport: '<Root>/sleep_status'
   */
  /* Gateway: BMO/Chart */
  /* During: BMO/Chart */
  if (((uint8_T *)ssGetDWork(S, 2))[0] == 0U) {
    /* Entry: BMO/Chart */
    ((uint8_T *)ssGetDWork(S, 2))[0] = 1U;

    /* Entry Internal: BMO/Chart */
    /* Transition: '<S2>:8' */
    ((uint8_T *)ssGetDWork(S, 0))[0] = BMO_IN_Power_OFF;

    /* Entry 'Power_OFF': '<S2>:2' */
    _rtB->battery_mode = _rtP->BMOk_PowerOff;
  } else {
    switch (((uint8_T *)ssGetDWork(S, 0))[0]) {
     case BMO_IN_Charging_Sleep:
      /* During 'Charging_Sleep': '<S2>:80' */
      if (!*((const boolean_T **)ssGetInputPortSignalPtrs(S, 8))[0]) {
        /* Transition: '<S2>:79' */
        ((uint8_T *)ssGetDWork(S, 0))[0] = BMO_IN_Power_ON;

        /* Entry 'Power_ON': '<S2>:1' */
        _rtB->battery_mode = _rtP->BMOk_PowerOn;
      }
      break;

     case BMO_IN_Closing_Contactors:
      /* During 'Closing_Contactors': '<S2>:3' */
      if (rtb_LogicalOperator == _rtP->BMOk_On) {
        /* Transition: '<S2>:12' */
        ((uint8_T *)ssGetDWork(S, 0))[0] = BMO_IN_Power_Closed;

        /* Entry Internal 'Power_Closed': '<S2>:5' */
        /* Transition: '<S2>:29' */
        ((uint8_T *)ssGetDWork(S, 1))[0] = BMO_IN_Power_Closed_Default;

        /* Entry 'Power_Closed_Default': '<S2>:27' */
        _rtB->battery_mode = _rtP->BMOk_PowerClosed;
      }
      break;

     case BMO_IN_Closing_MainContactors:
      /* During 'Closing_MainContactors': '<S2>:82' */
      /* Transition: '<S2>:83' */
      ((uint8_T *)ssGetDWork(S, 0))[0] = BMO_IN_Power_Closed;

      /* Entry Internal 'Power_Closed': '<S2>:5' */
      /* Transition: '<S2>:29' */
      ((uint8_T *)ssGetDWork(S, 1))[0] = BMO_IN_Power_Closed_Default;

      /* Entry 'Power_Closed_Default': '<S2>:27' */
      _rtB->battery_mode = _rtP->BMOk_PowerClosed;
      break;

     case BMO_IN_Opening_Contactors:
      /* During 'Opening_Contactors': '<S2>:4' */
      if (rtb_DataTypeConversion1 == _rtP->BMOk_Off) {
        /* Transition: '<S2>:17' */
        ((uint8_T *)ssGetDWork(S, 0))[0] = BMO_IN_Power_OFF;

        /* Entry 'Power_OFF': '<S2>:2' */
        _rtB->battery_mode = _rtP->BMOk_PowerOff;
      } else {
        if (rtb_LogicalOperator == _rtP->BMOk_Off) {
          /* Transition: '<S2>:47' */
          ((uint8_T *)ssGetDWork(S, 0))[0] = BMO_IN_Power_ON;

          /* Entry 'Power_ON': '<S2>:1' */
          _rtB->battery_mode = _rtP->BMOk_PowerOn;
        }
      }
      break;

     case BMO_IN_Power_Closed:
      /* During 'Power_Closed': '<S2>:5' */
      /* Transition: '<S2>:45' */
      if (rtb_LogicalOperator == _rtP->BMOk_Off) {
        /* Transition: '<S2>:46' */
        /* Exit Internal 'Power_Closed': '<S2>:5' */
        ((uint8_T *)ssGetDWork(S, 1))[0] = BMO_IN_NO_ACTIVE_CHILD;
        ((uint8_T *)ssGetDWork(S, 0))[0] = BMO_IN_Opening_Contactors;

        /* Entry 'Opening_Contactors': '<S2>:4' */
        _rtB->battery_mode = _rtP->BMOk_CcOpening;
      } else {
        switch (((uint8_T *)ssGetDWork(S, 1))[0]) {
         case BMO_IN_Charging:
          /* During 'Charging': '<S2>:6' */
          /* Transition: '<S2>:78' */
          if (*((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0] < -(*(real_T
                *)(mxGetData(BMOk_BatteryCurrentThresh(S))))) {
            /* Transition: '<S2>:36' */
            ((uint8_T *)ssGetDWork(S, 1))[0] = BMO_IN_Discharging;

            /* Entry 'Discharging': '<S2>:7' */
            _rtB->battery_mode = _rtP->BMOk_Discharging;
          } else if (*((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0] >
                     (*(real_T *)(mxGetData(BMOk_BatteryCurrentThresh(S))))) {
            /* Transition: '<S2>:37' */
            ((uint8_T *)ssGetDWork(S, 1))[0] = BMO_IN_Charging;

            /* Entry 'Charging': '<S2>:6' */
            _rtB->battery_mode = _rtP->BMOk_Charging;
          } else {
            /* Transition: '<S2>:39' */
            ((uint8_T *)ssGetDWork(S, 1))[0] = BMO_IN_Power_Closed_Default;

            /* Entry 'Power_Closed_Default': '<S2>:27' */
            _rtB->battery_mode = _rtP->BMOk_PowerClosed;
          }
          break;

         case BMO_IN_Discharging:
          /* During 'Discharging': '<S2>:7' */
          /* Transition: '<S2>:32' */
          if (*((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0] < -(*(real_T
                *)(mxGetData(BMOk_BatteryCurrentThresh(S))))) {
            /* Transition: '<S2>:36' */
            ((uint8_T *)ssGetDWork(S, 1))[0] = BMO_IN_Discharging;

            /* Entry 'Discharging': '<S2>:7' */
            _rtB->battery_mode = _rtP->BMOk_Discharging;
          } else if (*((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0] >
                     (*(real_T *)(mxGetData(BMOk_BatteryCurrentThresh(S))))) {
            /* Transition: '<S2>:37' */
            ((uint8_T *)ssGetDWork(S, 1))[0] = BMO_IN_Charging;

            /* Entry 'Charging': '<S2>:6' */
            _rtB->battery_mode = _rtP->BMOk_Charging;
          } else {
            /* Transition: '<S2>:39' */
            ((uint8_T *)ssGetDWork(S, 1))[0] = BMO_IN_Power_Closed_Default;

            /* Entry 'Power_Closed_Default': '<S2>:27' */
            _rtB->battery_mode = _rtP->BMOk_PowerClosed;
          }
          break;

         default:
          /* During 'Power_Closed_Default': '<S2>:27' */
          /* Transition: '<S2>:31' */
          if (*((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0] < -(*(real_T
                *)(mxGetData(BMOk_BatteryCurrentThresh(S))))) {
            /* Transition: '<S2>:36' */
            ((uint8_T *)ssGetDWork(S, 1))[0] = BMO_IN_Discharging;

            /* Entry 'Discharging': '<S2>:7' */
            _rtB->battery_mode = _rtP->BMOk_Discharging;
          } else if (*((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0] >
                     (*(real_T *)(mxGetData(BMOk_BatteryCurrentThresh(S))))) {
            /* Transition: '<S2>:37' */
            ((uint8_T *)ssGetDWork(S, 1))[0] = BMO_IN_Charging;

            /* Entry 'Charging': '<S2>:6' */
            _rtB->battery_mode = _rtP->BMOk_Charging;
          } else {
            /* Transition: '<S2>:39' */
            ((uint8_T *)ssGetDWork(S, 1))[0] = BMO_IN_Power_Closed_Default;

            /* Entry 'Power_Closed_Default': '<S2>:27' */
            _rtB->battery_mode = _rtP->BMOk_PowerClosed;
          }
          break;
        }
      }
      break;

     case BMO_IN_Power_OFF:
      /* During 'Power_OFF': '<S2>:2' */
      if (rtb_DataTypeConversion1 == _rtP->BMOk_On) {
        /* Transition: '<S2>:10' */
        ((uint8_T *)ssGetDWork(S, 0))[0] = BMO_IN_Power_ON;

        /* Entry 'Power_ON': '<S2>:1' */
        _rtB->battery_mode = _rtP->BMOk_PowerOn;
      }
      break;

     default:
      /* During 'Power_ON': '<S2>:1' */
      if (*((const boolean_T **)ssGetInputPortSignalPtrs(S, 5))[0] ==
          _rtP->BMOk_On) {
        /* Transition: '<S2>:11' */
        ((uint8_T *)ssGetDWork(S, 0))[0] = BMO_IN_Closing_Contactors;

        /* Entry 'Closing_Contactors': '<S2>:3' */
        _rtB->battery_mode = _rtP->BMOk_CcClosing;
      } else if (rtb_DataTypeConversion1 == _rtP->BMOk_Off) {
        /* Transition: '<S2>:67' */
        ((uint8_T *)ssGetDWork(S, 0))[0] = BMO_IN_Power_OFF;

        /* Entry 'Power_OFF': '<S2>:2' */
        _rtB->battery_mode = _rtP->BMOk_PowerOff;
      } else if (rtb_LogicalOperator == _rtP->BMOk_On) {
        /* Transition: '<S2>:71' */
        ((uint8_T *)ssGetDWork(S, 0))[0] = BMO_IN_Closing_MainContactors;

        /* Entry 'Closing_MainContactors': '<S2>:82' */
        _rtB->battery_mode = _rtP->BMOk_CcClosing;
      } else {
        if (*((const boolean_T **)ssGetInputPortSignalPtrs(S, 8))[0]) {
          /* Transition: '<S2>:81' */
          ((uint8_T *)ssGetDWork(S, 0))[0] = BMO_IN_Charging_Sleep;

          /* Entry 'Charging_Sleep': '<S2>:80' */
          _rtB->battery_mode = _rtP->BMOk_ChargingSleep;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */
  /* End of Outputs for SubSystem: '<Root>/BMO' */

  /* Outport: '<Root>/bat_mode' */
  ((uint8_T *)ssGetOutputPortSignal(S, 0))[0] = _rtB->battery_mode;

  /* Outputs for Atomic SubSystem: '<Root>/BMO' */
  /* Outport: '<Root>/charging_status' incorporates:
   *  Constant: '<S3>/Constant'
   *  RelationalOperator: '<S3>/Compare'
   */
  ((boolean_T *)ssGetOutputPortSignal(S, 1))[0] = (_rtB->battery_mode ==
    _rtP->BMOk_Charging);

  /* Outport: '<Root>/discharging_status' incorporates:
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   */
  ((boolean_T *)ssGetOutputPortSignal(S, 2))[0] = (_rtB->battery_mode ==
    _rtP->BMOk_Discharging);

  /* End of Outputs for SubSystem: '<Root>/BMO' */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  UNUSED_PARAMETER(tid);
}

/* Termination for root system: '<Root>' */
static void mdlTerminate(SimStruct *S)
{

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

  if (ssGetUserData(S) != (NULL) ) {
    rt_FREE(ssGetLocalBlockIO(S));
  }

  rt_FREE(ssGetUserData(S));

#endif

}

/* This function checks the attributes of tunable parameters. */
#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)

static void mdlCheckParameters(SimStruct *S)
{
  /* Parameter check for 'BMOk_BatteryCurrentThresh' */
  if (mxIsComplex(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,
                     "Parameter 'BMOk_BatteryCurrentThresh' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,
                     "Parameter 'BMOk_BatteryCurrentThresh' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 0)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'BMOk_BatteryCurrentThresh' has to be a [1x1] array.");
    return;
  }
}

#endif                                 /* MDL_CHECK_PARAMETERS */

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "BMO_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 1);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 3))
    return;

  /* outport number: 0 */
  if (!ssSetOutputPortVectorDimension(S, 0, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 0, SS_UINT8);
  }

  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* outport number: 1 */
  if (!ssSetOutputPortVectorDimension(S, 1, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 1, SS_BOOLEAN);
  }

  ssSetOutputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

  /* outport number: 2 */
  if (!ssSetOutputPortVectorDimension(S, 2, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 2, SS_BOOLEAN);
  }

  ssSetOutputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 9))
    return;

  /* inport number: 0 */
  {
    if (!ssSetInputPortVectorDimension(S, 0, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 0, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortOverWritable(S, 0, 0);
    ssSetInputPortOptimOpts(S, 0, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 1 */
  {
    if (!ssSetInputPortVectorDimension(S, 1, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 1, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortOverWritable(S, 1, 0);
    ssSetInputPortOptimOpts(S, 1, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 2 */
  {
    if (!ssSetInputPortVectorDimension(S, 2, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 2, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 2, 1);
    ssSetInputPortOverWritable(S, 2, 0);
    ssSetInputPortOptimOpts(S, 2, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 3 */
  {
    if (!ssSetInputPortVectorDimension(S, 3, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 3, SS_UINT8);
    }

    ssSetInputPortDirectFeedThrough(S, 3, 1);
    ssSetInputPortOverWritable(S, 3, 0);
    ssSetInputPortOptimOpts(S, 3, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 4 */
  {
    if (!ssSetInputPortVectorDimension(S, 4, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 4, SS_UINT8);
    }

    ssSetInputPortDirectFeedThrough(S, 4, 1);
    ssSetInputPortOverWritable(S, 4, 0);
    ssSetInputPortOptimOpts(S, 4, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 5 */
  {
    if (!ssSetInputPortVectorDimension(S, 5, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 5, SS_BOOLEAN);
    }

    ssSetInputPortDirectFeedThrough(S, 5, 1);
    ssSetInputPortOverWritable(S, 5, 0);
    ssSetInputPortOptimOpts(S, 5, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 6 */
  {
    if (!ssSetInputPortVectorDimension(S, 6, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 6, SS_BOOLEAN);
    }

    ssSetInputPortDirectFeedThrough(S, 6, 1);
    ssSetInputPortOverWritable(S, 6, 0);
    ssSetInputPortOptimOpts(S, 6, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 7 */
  {
    if (!ssSetInputPortVectorDimension(S, 7, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 7, SS_BOOLEAN);
    }

    ssSetInputPortDirectFeedThrough(S, 7, 1);
    ssSetInputPortOverWritable(S, 7, 0);
    ssSetInputPortOptimOpts(S, 7, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 8 */
  {
    if (!ssSetInputPortVectorDimension(S, 8, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 8, SS_BOOLEAN);
    }

    ssSetInputPortDirectFeedThrough(S, 8, 1);
    ssSetInputPortOverWritable(S, 8, 0);
    ssSetInputPortOptimOpts(S, 8, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 3)) {
    return;
  }

  /* '<S1>/Chart': DWORK2 */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 1);
  ssSetDWorkDataType(S, 0, SS_UINT8);

  /* '<S1>/Chart': DWORK3 */
  ssSetDWorkName(S, 1, "DWORK1");
  ssSetDWorkWidth(S, 1, 1);
  ssSetDWorkDataType(S, 1, SS_UINT8);

  /* '<S1>/Chart': DWORK1 */
  ssSetDWorkName(S, 2, "DWORK2");
  ssSetDWorkWidth(S, 2, 1);
  ssSetDWorkDataType(S, 2, SS_UINT8);

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 1);

  /* Number of expected parameters */
#if defined(MATLAB_MEX_FILE)

  if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {

#if defined(MDL_CHECK_PARAMETERS)

    mdlCheckParameters(S);

#endif                                 /* MDL_CHECK_PARAMETERS */

    if (ssGetErrorStatus(S) != (NULL) ) {
      return;
    }
  } else {
    return;                            /* Parameter mismatch will be reported by Simulink */
  }

#endif                                 /* MATLAB_MEX_FILE */

  /* Options */
  ssSetOptions(S, (SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE |
                   SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME ));

#if SS_SFCN_FOR_SIM

  {
    ssSupportsMultipleExecInstances(S, true);
    ssHasStateInsideForEachSS(S, false);
    ssSetModelReferenceSampleTimeInheritanceRule(S,
      USE_DEFAULT_FOR_DISCRETE_INHERITANCE);
  }

#endif

}

/* Function to initialize sample times. */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
  ssSetOffsetTime(S, 0, 0.0);
}

#if defined(MATLAB_MEX_FILE)
# include "fixedpoint.c"
# include "simulink.c"
#else
# undef S_FUNCTION_NAME
# define S_FUNCTION_NAME               BMO_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
