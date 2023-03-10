/*
 * BSC_sf.c
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
 */

#include <math.h>
#include "BSC_sf.h"
#include "BSC_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"

/* Named constants for Chart: '<S6>/key_cycle_chart' */
#define BSC_IN_Key_OFF                 ((uint8_T)1U)
#define BSC_IN_Key_ON                  ((uint8_T)2U)
#define BSC_IN_NO_ACTIVE_CHILD_f       ((uint8_T)0U)
#define BSC_IN_inital_key_off_fault    ((uint8_T)3U)
#define BSC_event_fault_change         (1)
#define BSC_event_key_change           (0)

/* Named constants for Chart: '<S1>/Chart2' */
#define BSC_IN_NO_ACTIVE_CHILD_p       ((uint8_T)0U)
#define BSC_IN_main                    ((uint8_T)1U)
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *BSC_malloc(SimStruct *S);

#endif

#ifndef __RTW_UTFREE__
#if defined (MATLAB_MEX_FILE)

extern void * utMalloc(size_t);
extern void utFree(void *);

#endif
#endif                                 /* #ifndef __RTW_UTFREE__ */

/* Forward declaration for local functions */
static void BSC_enter_internal_Key_ON(uint8_T rtu_med_fault, SimStruct * const S,
  B_key_cycle_BSC_T *localB);
static void BSC_enter_internal_Key_OFF(uint8_T rtu_med_fault, SimStruct * const
  S, B_key_cycle_BSC_T *localB);
static void BSC_chartstep_c1_BSC(uint8_T rtu_med_fault, SimStruct * const S,
  B_key_cycle_BSC_T *localB);

#if defined(MATLAB_MEX_FILE)
#include "rt_nonfinite.c"
#endif

static const char_T *RT_MEMORY_ALLOCATION_ERROR =
  "memory allocation error in generated S-Function";

/* Initial conditions for function-call system: '<S1>/check_type' */
void BSC_check_type_Init(B_check_type_BSC_T *localB)
{
  /* InitializeConditions for Chart: '<S5>/check_faults' */
  localB->type_of_fault = 0U;
}

/* Output and update for function-call system: '<S1>/check_type' */
void BSC_check_type(SimStruct * const S, uint8_T rtu_In1, uint8_T rtu_In2,
                    uint8_T rtu_In3, uint8_T rtu_In4, uint8_T rtu_In5, uint8_T
                    rtu_In6, uint8_T rtu_In7, uint8_T rtu_In8, uint8_T rtu_In9,
                    uint8_T rtu_In10, uint8_T rtu_In11, B_check_type_BSC_T
                    *localB)
{
  /* Chart: '<S5>/check_faults' */
  /* Gateway: BSC/check_type/check_faults */
  /* During: BSC/check_type/check_faults */
  /* Entry Internal: BSC/check_type/check_faults */
  /* Transition: '<S12>:170' */
  if (rtu_In1 != 0) {
    /* Transition: '<S12>:75' */
    /* Transition: '<S12>:77' */
    localB->type_of_fault = 1U;

    /* Transition: '<S12>:142' */
    /* Transition: '<S12>:139' */
    /* Transition: '<S12>:146' */
    /* Transition: '<S12>:151' */
    /* Transition: '<S12>:156' */
    /* Transition: '<S12>:157' */
    /* Transition: '<S12>:136' */
    /* Transition: '<S12>:135' */
    /* Transition: '<S12>:177' */
    /* Transition: '<S12>:190' */
    /* Transition: '<S12>:189' */
  } else {
    /* Transition: '<S12>:76' */
    if (rtu_In2 != 0) {
      /* Transition: '<S12>:78' */
      /* Transition: '<S12>:126' */
      localB->type_of_fault = 2U;

      /* Transition: '<S12>:139' */
      /* Transition: '<S12>:146' */
      /* Transition: '<S12>:151' */
      /* Transition: '<S12>:156' */
      /* Transition: '<S12>:157' */
      /* Transition: '<S12>:136' */
      /* Transition: '<S12>:135' */
      /* Transition: '<S12>:177' */
      /* Transition: '<S12>:190' */
      /* Transition: '<S12>:189' */
    } else {
      /* Transition: '<S12>:79' */
      if (rtu_In3 != 0) {
        /* Transition: '<S12>:81' */
        /* Transition: '<S12>:127' */
        localB->type_of_fault = 3U;

        /* Transition: '<S12>:146' */
        /* Transition: '<S12>:151' */
        /* Transition: '<S12>:156' */
        /* Transition: '<S12>:157' */
        /* Transition: '<S12>:136' */
        /* Transition: '<S12>:135' */
        /* Transition: '<S12>:177' */
        /* Transition: '<S12>:190' */
        /* Transition: '<S12>:189' */
      } else {
        /* Transition: '<S12>:108' */
        if (rtu_In4 != 0) {
          /* Transition: '<S12>:101' */
          /* Transition: '<S12>:128' */
          localB->type_of_fault = 4U;

          /* Transition: '<S12>:151' */
          /* Transition: '<S12>:156' */
          /* Transition: '<S12>:157' */
          /* Transition: '<S12>:136' */
          /* Transition: '<S12>:135' */
          /* Transition: '<S12>:177' */
          /* Transition: '<S12>:190' */
          /* Transition: '<S12>:189' */
        } else {
          /* Transition: '<S12>:109' */
          if (rtu_In5 != 0) {
            /* Transition: '<S12>:105' */
            /* Transition: '<S12>:129' */
            localB->type_of_fault = 5U;

            /* Transition: '<S12>:156' */
            /* Transition: '<S12>:157' */
            /* Transition: '<S12>:136' */
            /* Transition: '<S12>:135' */
            /* Transition: '<S12>:177' */
            /* Transition: '<S12>:190' */
            /* Transition: '<S12>:189' */
          } else {
            /* Transition: '<S12>:122' */
            if (rtu_In6 != 0) {
              /* Transition: '<S12>:111' */
              /* Transition: '<S12>:130' */
              localB->type_of_fault = 6U;

              /* Transition: '<S12>:157' */
              /* Transition: '<S12>:136' */
              /* Transition: '<S12>:135' */
              /* Transition: '<S12>:177' */
              /* Transition: '<S12>:190' */
              /* Transition: '<S12>:189' */
            } else {
              /* Transition: '<S12>:123' */
              if (rtu_In7 != 0) {
                /* Transition: '<S12>:114' */
                /* Transition: '<S12>:131' */
                localB->type_of_fault = 7U;

                /* Transition: '<S12>:136' */
                /* Transition: '<S12>:135' */
                /* Transition: '<S12>:177' */
                /* Transition: '<S12>:190' */
                /* Transition: '<S12>:189' */
              } else {
                /* Transition: '<S12>:124' */
                if (rtu_In8 != 0) {
                  /* Transition: '<S12>:118' */
                  /* Transition: '<S12>:132' */
                  localB->type_of_fault = 8U;

                  /* Transition: '<S12>:135' */
                  /* Transition: '<S12>:177' */
                  /* Transition: '<S12>:190' */
                  /* Transition: '<S12>:189' */
                } else {
                  /* Transition: '<S12>:125' */
                  if (rtu_In9 != 0) {
                    /* Transition: '<S12>:121' */
                    /* Transition: '<S12>:133' */
                    localB->type_of_fault = 9U;

                    /* Transition: '<S12>:177' */
                    /* Transition: '<S12>:190' */
                    /* Transition: '<S12>:189' */
                  } else {
                    /* Transition: '<S12>:174' */
                    if (rtu_In10 != 0) {
                      /* Transition: '<S12>:176' */
                      /* Transition: '<S12>:175' */
                      localB->type_of_fault = 10U;

                      /* Transition: '<S12>:190' */
                      /* Transition: '<S12>:189' */
                    } else {
                      /* Transition: '<S12>:187' */
                      if (rtu_In11 != 0) {
                        /* Transition: '<S12>:185' */
                        /* Transition: '<S12>:186' */
                        localB->type_of_fault = 11U;

                        /* Transition: '<S12>:189' */
                      } else {
                        /* Transition: '<S12>:188' */
                        /* Transition: '<S12>:165' */
                        localB->type_of_fault = 0U;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  /* End of Chart: '<S5>/check_faults' */

  /* Outport: '<Root>/Fault Type' incorporates:
   *  Outport: '<S5>/Out1'
   */
  /* Transition: '<S12>:181' */
  ((uint8_T *)ssGetOutputPortSignal(S, 7))[0] = localB->type_of_fault;
}

/* Termination for function-call system: '<S1>/check_type' */
void BSC_check_type_Term(SimStruct *const S)
{
}

/* Output and update for function-call system: '<S1>/Fault_level' */
void BSC_Fault_level(SimStruct * const S)
{
  int8_T rtb_Compare_j[7];
  int32_T i;
  uint8_T rtb_Compare_c_idx_0;
  B_BSC_T *_rtB;
  P_BSC_T *_rtP;
  _rtP = ((P_BSC_T *) ssGetLocalDefaultParam(S));
  _rtB = ((B_BSC_T *) ssGetLocalBlockIO(S));

  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Constant: '<S10>/Constant'
   */
  rtb_Compare_c_idx_0 = (uint8_T)(_rtB->check_type.type_of_fault ==
    _rtP->bscv_MediumFaultType[0]);

  /* RelationalOperator: '<S11>/Compare' incorporates:
   *  Constant: '<S11>/Constant'
   */
  for (i = 0; i < 7; i++) {
    rtb_Compare_j[i] = (int8_T)(_rtB->check_type.type_of_fault ==
      _rtP->bscv_LowFaultType[i]);
  }

  /* End of RelationalOperator: '<S11>/Compare' */

  /* MinMax: '<S3>/MinMax' incorporates:
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S9>/Compare'
   */
  _rtB->MinMax = (uint8_T)(_rtB->check_type.type_of_fault ==
    _rtP->bscv_SevereFaultType);

  /* MinMax: '<S3>/MinMax1' incorporates:
   *  Constant: '<S10>/Constant'
   *  RelationalOperator: '<S10>/Compare'
   */
  if (!(rtb_Compare_c_idx_0 >= (_rtB->check_type.type_of_fault ==
        _rtP->bscv_MediumFaultType[1]))) {
    rtb_Compare_c_idx_0 = 1U;
  }

  if (!(rtb_Compare_c_idx_0 >= (_rtB->check_type.type_of_fault ==
        _rtP->bscv_MediumFaultType[2]))) {
    rtb_Compare_c_idx_0 = 1U;
  }

  _rtB->MinMax1 = rtb_Compare_c_idx_0;

  /* End of MinMax: '<S3>/MinMax1' */

  /* MinMax: '<S3>/MinMax2' */
  rtb_Compare_c_idx_0 = (uint8_T)rtb_Compare_j[0];
  for (i = 0; i < 6; i++) {
    if (!(rtb_Compare_c_idx_0 >= (uint8_T)rtb_Compare_j[i + 1])) {
      rtb_Compare_c_idx_0 = 1U;
    }
  }

  _rtB->MinMax2 = rtb_Compare_c_idx_0;

  /* End of MinMax: '<S3>/MinMax2' */

  /* Outport: '<S3>/low level fault' */
  ((uint8_T *)ssGetOutputPortSignal(S, 6))[0] = _rtB->MinMax2;
}

/* Termination for function-call system: '<S1>/Fault_level' */
void BSC_Fault_level_Term(SimStruct *const S)
{
}

/* Function for Chart: '<S6>/key_cycle_chart' */
static void BSC_enter_internal_Key_ON(uint8_T rtu_med_fault, SimStruct * const S,
  B_key_cycle_BSC_T *localB)
{
  int32_T tmp;

  /* Entry Internal 'Key_ON': '<S13>:17' */
  /* Transition: '<S13>:123' */
  if ((((int32_T *)ssGetDWork(S, 2))[0] == BSC_event_key_change) && (((uint8_T *)
        ssGetDWork(S, 5))[0] == 0)) {
    /* Transition: '<S13>:124' */
    /* Transition: '<S13>:119' */
    tmp = ((uint8_T *)ssGetDWork(S, 4))[0] + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    ((uint8_T *)ssGetDWork(S, 4))[0] = (uint8_T)tmp;

    /* Transition: '<S13>:129' */
  } else {
    /* Transition: '<S13>:120' */
  }

  /* Transition: '<S13>:115' */
  if (((uint8_T *)ssGetDWork(S, 4))[0] > 1) {
    /* Transition: '<S13>:131' */
    /* Transition: '<S13>:130' */
    ((uint8_T *)ssGetDWork(S, 4))[0] = 1U;

    /* Transition: '<S13>:132' */
  } else {
    /* Transition: '<S13>:133' */
  }

  /* Transition: '<S13>:139' */
  /* Transition: '<S13>:140' */
  if (rtu_med_fault == 1) {
    /* Transition: '<S13>:105' */
    /* Transition: '<S13>:102' */
    localB->key_cycle = 0U;
    ((uint8_T *)ssGetDWork(S, 4))[0] = 0U;
    ((uint8_T *)ssGetDWork(S, 3))[0] = 0U;
    ((uint8_T *)ssGetDWork(S, 6))[0] = 1U;

    /* Transition: '<S13>:103' */
  } else {
    /* Transition: '<S13>:110' */
    if (((uint8_T *)ssGetDWork(S, 4))[0] == 1) {
      /* Transition: '<S13>:117' */
      /* Transition: '<S13>:126' */
      localB->key_cycle = 1U;

      /* Transition: '<S13>:125' */
    } else {
      /* Transition: '<S13>:114' */
    }

    /* Transition: '<S13>:111' */
  }

  /* Transition: '<S13>:108' */
}

/* Function for Chart: '<S6>/key_cycle_chart' */
static void BSC_enter_internal_Key_OFF(uint8_T rtu_med_fault, SimStruct * const
  S, B_key_cycle_BSC_T *localB)
{
  int32_T tmp;

  /* Entry Internal 'Key_OFF': '<S13>:14' */
  /* Transition: '<S13>:85' */
  if ((((int32_T *)ssGetDWork(S, 2))[0] == BSC_event_key_change) && (((uint8_T *)
        ssGetDWork(S, 6))[0] == 0)) {
    /* Transition: '<S13>:80' */
    /* Transition: '<S13>:79' */
    tmp = ((uint8_T *)ssGetDWork(S, 3))[0] + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    ((uint8_T *)ssGetDWork(S, 3))[0] = (uint8_T)tmp;

    /* Transition: '<S13>:81' */
  } else {
    /* Transition: '<S13>:82' */
  }

  /* Transition: '<S13>:88' */
  if (((uint8_T *)ssGetDWork(S, 3))[0] > 1) {
    /* Transition: '<S13>:68' */
    /* Transition: '<S13>:70' */
    ((uint8_T *)ssGetDWork(S, 3))[0] = 1U;

    /* Transition: '<S13>:71' */
  } else {
    /* Transition: '<S13>:69' */
  }

  /* Transition: '<S13>:72' */
  /* Transition: '<S13>:78' */
  if (rtu_med_fault == 1) {
    /* Transition: '<S13>:35' */
    /* Transition: '<S13>:37' */
    localB->key_cycle = 0U;
    ((uint8_T *)ssGetDWork(S, 3))[0] = 0U;
    ((uint8_T *)ssGetDWork(S, 4))[0] = 0U;
    ((uint8_T *)ssGetDWork(S, 5))[0] = 1U;

    /* Transition: '<S13>:38' */
  } else {
    /* Transition: '<S13>:99' */
    if (((uint8_T *)ssGetDWork(S, 3))[0] == 1) {
      /* Transition: '<S13>:97' */
      /* Transition: '<S13>:92' */
      localB->key_cycle = 1U;

      /* Transition: '<S13>:98' */
    } else {
      /* Transition: '<S13>:93' */
    }

    /* Transition: '<S13>:100' */
  }

  /* Transition: '<S13>:39' */
}

/* Function for Chart: '<S6>/key_cycle_chart' */
static void BSC_chartstep_c1_BSC(uint8_T rtu_med_fault, SimStruct * const S,
  B_key_cycle_BSC_T *localB)
{
  /* During: BSC/key_cycle/key_cycle_chart */
  if (((uint8_T *)ssGetDWork(S, 8))[0] == 0U) {
    /* Entry: BSC/key_cycle/key_cycle_chart */
    ((uint8_T *)ssGetDWork(S, 8))[0] = 1U;

    /* Entry Internal: BSC/key_cycle/key_cycle_chart */
    if (((int32_T *)ssGetDWork(S, 2))[0] == BSC_event_key_change) {
      /* Transition: '<S13>:59' */
      ((uint8_T *)ssGetDWork(S, 7))[0] = BSC_IN_Key_ON;

      /* Chart: '<S6>/key_cycle_chart' incorporates:
       *  TriggerPort: '<S13>/input events'
       */
      /* Entry 'Key_ON': '<S13>:17' */
      BSC_enter_internal_Key_ON(rtu_med_fault, S, localB);
    } else {
      /* Transition: '<S13>:63' */
      ((uint8_T *)ssGetDWork(S, 7))[0] = BSC_IN_inital_key_off_fault;

      /* Entry 'inital_key_off_fault': '<S13>:62' */
      localB->key_cycle = 0U;
      ((uint8_T *)ssGetDWork(S, 5))[0] = 1U;
    }
  } else {
    switch (((uint8_T *)ssGetDWork(S, 7))[0]) {
     case BSC_IN_Key_OFF:
      /* During 'Key_OFF': '<S13>:14' */
      if (((int32_T *)ssGetDWork(S, 2))[0] == BSC_event_key_change) {
        /* Transition: '<S13>:15' */
        /* Exit 'Key_OFF': '<S13>:14' */
        ((uint8_T *)ssGetDWork(S, 6))[0] = 0U;
        ((uint8_T *)ssGetDWork(S, 7))[0] = BSC_IN_Key_ON;

        /* Chart: '<S6>/key_cycle_chart' incorporates:
         *  TriggerPort: '<S13>/input events'
         */
        /* Entry 'Key_ON': '<S13>:17' */
        BSC_enter_internal_Key_ON(rtu_med_fault, S, localB);
      } else {
        if (((int32_T *)ssGetDWork(S, 2))[0] == BSC_event_fault_change) {
          /* Transition: '<S13>:65' */
          /* Exit 'Key_OFF': '<S13>:14' */
          ((uint8_T *)ssGetDWork(S, 6))[0] = 0U;
          ((uint8_T *)ssGetDWork(S, 7))[0] = BSC_IN_Key_OFF;

          /* Chart: '<S6>/key_cycle_chart' incorporates:
           *  TriggerPort: '<S13>/input events'
           */
          /* Entry 'Key_OFF': '<S13>:14' */
          BSC_enter_internal_Key_OFF(rtu_med_fault, S, localB);
        }
      }
      break;

     case BSC_IN_Key_ON:
      /* During 'Key_ON': '<S13>:17' */
      if (((int32_T *)ssGetDWork(S, 2))[0] == BSC_event_key_change) {
        /* Transition: '<S13>:11' */
        /* Exit 'Key_ON': '<S13>:17' */
        ((uint8_T *)ssGetDWork(S, 5))[0] = 0U;
        ((uint8_T *)ssGetDWork(S, 7))[0] = BSC_IN_Key_OFF;

        /* Chart: '<S6>/key_cycle_chart' incorporates:
         *  TriggerPort: '<S13>/input events'
         */
        /* Entry 'Key_OFF': '<S13>:14' */
        BSC_enter_internal_Key_OFF(rtu_med_fault, S, localB);
      } else {
        if (((int32_T *)ssGetDWork(S, 2))[0] == BSC_event_fault_change) {
          /* Transition: '<S13>:66' */
          /* Exit 'Key_ON': '<S13>:17' */
          ((uint8_T *)ssGetDWork(S, 5))[0] = 0U;
          ((uint8_T *)ssGetDWork(S, 7))[0] = BSC_IN_Key_ON;

          /* Chart: '<S6>/key_cycle_chart' incorporates:
           *  TriggerPort: '<S13>/input events'
           */
          /* Entry 'Key_ON': '<S13>:17' */
          BSC_enter_internal_Key_ON(rtu_med_fault, S, localB);
        }
      }
      break;

     default:
      /* During 'inital_key_off_fault': '<S13>:62' */
      if (((int32_T *)ssGetDWork(S, 2))[0] == BSC_event_key_change) {
        /* Transition: '<S13>:64' */
        ((uint8_T *)ssGetDWork(S, 7))[0] = BSC_IN_Key_ON;

        /* Chart: '<S6>/key_cycle_chart' incorporates:
         *  TriggerPort: '<S13>/input events'
         */
        /* Entry 'Key_ON': '<S13>:17' */
        BSC_enter_internal_Key_ON(rtu_med_fault, S, localB);
      }
      break;
    }
  }
}

/* Initial conditions for function-call system: '<S1>/key_cycle' */
void BSC_key_cycle_Init(SimStruct * const S, B_key_cycle_BSC_T *localB)
{
  /* InitializeConditions for Chart: '<S6>/key_cycle_chart' */
  ((uint8_T *)ssGetDWork(S, 8))[0] = 0U;
  ((uint8_T *)ssGetDWork(S, 7))[0] = BSC_IN_NO_ACTIVE_CHILD_f;
  ((uint8_T *)ssGetDWork(S, 3))[0] = 0U;
  ((uint8_T *)ssGetDWork(S, 4))[0] = 0U;
  ((uint8_T *)ssGetDWork(S, 5))[0] = 0U;
  ((uint8_T *)ssGetDWork(S, 6))[0] = 0U;
  localB->key_cycle = 1U;
}

/* Output and update for function-call system: '<S1>/key_cycle' */
void BSC_key_cycle(SimStruct * const S, uint8_T rtu_med_fault, uint8_T rtu_key,
                   B_key_cycle_BSC_T *localB, ZCE_key_cycle_BSC_T *localZCE)
{
  boolean_T zcEvent_idx_0;
  boolean_T zcEvent_idx_1;

  /* Chart: '<S6>/key_cycle_chart' incorporates:
   *  TriggerPort: '<S13>/input events'
   */
  zcEvent_idx_0 = (((rtu_key > 0) != (localZCE->key_cycle_chart_Trig_ZCE[0] ==
    POS_ZCSIG)) && (localZCE->key_cycle_chart_Trig_ZCE[0] != UNINITIALIZED_ZCSIG));
  zcEvent_idx_1 = (((rtu_med_fault > 0) != (localZCE->key_cycle_chart_Trig_ZCE[1]
    == POS_ZCSIG)) && (localZCE->key_cycle_chart_Trig_ZCE[1] !=
                       UNINITIALIZED_ZCSIG));
  if (zcEvent_idx_0 || zcEvent_idx_1) {
    /* Gateway: BSC/key_cycle/key_cycle_chart */
    if ((int8_T)(zcEvent_idx_0 ? rtu_key > 0 ? RISING_ZCEVENT : FALLING_ZCEVENT :
                 NO_ZCEVENT) != 0) {
      /* Event: '<S13>:8' */
      ((int32_T *)ssGetDWork(S, 2))[0] = BSC_event_key_change;
      BSC_chartstep_c1_BSC(rtu_med_fault, S, localB);
    }

    if ((int8_T)(zcEvent_idx_1 ? rtu_med_fault > 0 ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      /* Event: '<S13>:56' */
      ((int32_T *)ssGetDWork(S, 2))[0] = BSC_event_fault_change;
      BSC_chartstep_c1_BSC(rtu_med_fault, S, localB);
    }
  }

  localZCE->key_cycle_chart_Trig_ZCE[0] = (uint8_T)(rtu_key > 0);
  localZCE->key_cycle_chart_Trig_ZCE[1] = (uint8_T)(rtu_med_fault > 0);
}

/* Termination for function-call system: '<S1>/key_cycle' */
void BSC_key_cycle_Term(SimStruct *const S)
{
}

/* Output and update for function-call system: '<S1>/sleepCheck' */
void BSC_sleepCheck(SimStruct * const S)
{
  /* Logic: '<S8>/Logical Operator3' incorporates:
   *  Constant: '<S17>/Constant'
   *  Inport: '<Root>/Charger PSR'
   *  Inport: '<Root>/SOC'
   *  RelationalOperator: '<S17>/Compare'
   */
  ((B_BSC_T *) ssGetLocalBlockIO(S))->LogicalOperator3 = ((*((const uint8_T **)
    ssGetInputPortSignalPtrs(S, 1))[0] != 0) && (*((const real_T **)
    ssGetInputPortSignalPtrs(S, 3))[0] >= 95.0));

  /* Outport: '<S8>/Sleep Mode' */
  ((boolean_T *)ssGetOutputPortSignal(S, 3))[0] = ((B_BSC_T *) ssGetLocalBlockIO
    (S))->LogicalOperator3;
}

/* Termination for function-call system: '<S1>/sleepCheck' */
void BSC_sleepCheck_Term(SimStruct *const S)
{
}

/* Output and update for function-call system: '<S1>/cc_c  md' */
void BSC_cc_cmd(SimStruct * const S)
{
  B_BSC_T *_rtB;
  _rtB = ((B_BSC_T *) ssGetLocalBlockIO(S));

  /* Logic: '<S4>/Logical Operator16' incorporates:
   *  Inport: '<Root>/Charger PSR'
   *  Logic: '<S4>/Logical Operator1'
   *  Logic: '<S4>/Logical Operator7'
   */
  ((B_BSC_T *) ssGetLocalBlockIO(S))->LogicalOperator16 = ((*((const uint8_T **)
    ssGetInputPortSignalPtrs(S, 1))[0] != 0) && (_rtB->key_cycle.key_cycle != 0)
    && (!((B_BSC_T *) ssGetLocalBlockIO(S))->LogicalOperator3) &&
    (!(_rtB->MinMax != 0)));

  /* Logic: '<S4>/Logical Operator2' incorporates:
   *  Inport: '<Root>/Vehicle PSR'
   *  Logic: '<S4>/Logical Operator8'
   */
  ((B_BSC_T *) ssGetLocalBlockIO(S))->LogicalOperator2 = ((*((const uint8_T **)
    ssGetInputPortSignalPtrs(S, 0))[0] != 0) && (_rtB->key_cycle.key_cycle != 0)
    && (!(_rtB->MinMax != 0)));

  /* Outport: '<S4>/main_cc_cmd' */
  ((boolean_T *)ssGetOutputPortSignal(S, 1))[0] = ((B_BSC_T *) ssGetLocalBlockIO
    (S))->LogicalOperator2;

  /* Outport: '<S4>/chg_cc_cmd' */
  ((boolean_T *)ssGetOutputPortSignal(S, 2))[0] = ((B_BSC_T *) ssGetLocalBlockIO
    (S))->LogicalOperator16;
}

/* Termination for function-call system: '<S1>/cc_c  md' */
void BSC_cc_cmd_Term(SimStruct *const S)
{
}

/* Output and update for function-call system: '<S1>/rsnToOpenCC' */
void BSC_rsnToOpenCC(SimStruct * const S)
{
  B_BSC_T *_rtB;
  PrevZCX_BSC_T *_rtZCE;
  _rtZCE = ((PrevZCX_BSC_T *) _ssGetPrevZCSigState(S));
  _rtB = ((B_BSC_T *) ssGetLocalBlockIO(S));

  /* Sum: '<S7>/Add' */
  _rtB->Add = (uint8_T)((uint32_T)_rtB->MinMax + _rtB->MinMax1);

  /* Outputs for Triggered SubSystem: '<S7>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S14>/Trigger'
   */
  if (((_rtB->key_cycle.key_cycle > 0) != (_rtZCE->TriggeredSubsystem_Trig_ZCE ==
        POS_ZCSIG)) && (_rtZCE->TriggeredSubsystem_Trig_ZCE !=
                        UNINITIALIZED_ZCSIG)) {
    /* If: '<S14>/If' incorporates:
     *  Constant: '<S14>/Constant'
     *  Inport: '<S15>/In1'
     *  Inport: '<S16>/In1'
     */
    if (_rtB->Add > 0) {
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      _rtB->Merge = _rtB->check_type.type_of_fault;

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      _rtB->Merge = 0U;

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem1' */
      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem' */
    }

    /* End of If: '<S14>/If' */
  }

  _rtZCE->TriggeredSubsystem_Trig_ZCE = (uint8_T)(_rtB->key_cycle.key_cycle > 0);

  /* End of Outputs for SubSystem: '<S7>/Triggered Subsystem' */

  /* Outport: '<Root>/Reason to open contactor to CAN' incorporates:
   *  Outport: '<S7>/reason_to_open_contactor'
   */
  ((uint8_T *)ssGetOutputPortSignal(S, 4))[0] = _rtB->Merge;

  /* Outport: '<S7>/severe//med fault' */
  ((uint8_T *)ssGetOutputPortSignal(S, 5))[0] = _rtB->Add;
}

/* Termination for function-call system: '<S1>/rsnToOpenCC' */
void BSC_rsnToOpenCC_Term(SimStruct *const S)
{
}

/* Initial conditions for root system: '<Root>' */
#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  B_BSC_T *_rtB;
  _rtB = ((B_BSC_T *) ssGetLocalBlockIO(S));

  /* InitializeConditions for Atomic SubSystem: '<Root>/BSC' */
  /* InitializeConditions for Chart: '<S1>/Chart2' */
  ((uint8_T *)ssGetDWork(S, 0))[0] = 0U;
  ((uint8_T *)ssGetDWork(S, 1))[0] = BSC_IN_NO_ACTIVE_CHILD_p;
  if (ssIsFirstInitCond(S)) {
    /* InitializeConditions for Function Call SubSystem: '<S1>/check_type' */
    BSC_check_type_Init(&_rtB->check_type);

    /* End of InitializeConditions for SubSystem: '<S1>/check_type' */

    /* InitializeConditions for Function Call SubSystem: '<S1>/key_cycle' */
    BSC_key_cycle_Init(S, &_rtB->key_cycle);

    /* End of InitializeConditions for SubSystem: '<S1>/key_cycle' */
  }

  /* End of InitializeConditions for Chart: '<S1>/Chart2' */
  /* End of InitializeConditions for SubSystem: '<Root>/BSC' */
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

  BSC_malloc(S);
  if (ssGetErrorStatus(S) != (NULL) ) {
    return;
  }

#endif

  {
    /* Previous zero-crossing state intialization */
    {
      PrevZCX_BSC_T *_rtZCE;
      _rtZCE = ((PrevZCX_BSC_T *) _ssGetPrevZCSigState(S));
      _rtZCE->TriggeredSubsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;
      _rtZCE->key_cycle.key_cycle_chart_Trig_ZCE[0] = UNINITIALIZED_ZCSIG;
      _rtZCE->key_cycle.key_cycle_chart_Trig_ZCE[1] = UNINITIALIZED_ZCSIG;
    }
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  B_BSC_T *_rtB;
  PrevZCX_BSC_T *_rtZCE;
  _rtZCE = ((PrevZCX_BSC_T *) _ssGetPrevZCSigState(S));
  _rtB = ((B_BSC_T *) ssGetLocalBlockIO(S));

  /* Outputs for Atomic SubSystem: '<Root>/BSC' */
  /* Chart: '<S1>/Chart2' incorporates:
   *  Inport: '<Root>/cc_PrechargeFault[Type11]'
   *  Inport: '<Root>/high level fault[Type1]'
   *  Inport: '<Root>/key'
   *  Inport: '<Root>/low level fault[Type3]'
   *  Inport: '<Root>/medium level fault[Type2]'
   *  Inport: '<Root>/vitm_CellsTemperatureHighFault[Type5]'
   *  Inport: '<Root>/vitm_CellsTemperatureLowFault[Type4]'
   *  Inport: '<Root>/vitm_CellsVoltageHightFault[Type7]'
   *  Inport: '<Root>/vitm_CellsVoltageLowFault[Type6]'
   *  Inport: '<Root>/vitm_HVILFault[Type10]'
   *  Inport: '<Root>/vitm_PackCurrentFault[Type9]'
   *  Inport: '<Root>/vitm_PackVoltageFault[Type8]'
   */
  /* Gateway: BSC/Chart2 */
  /* During: BSC/Chart2 */
  if (((uint8_T *)ssGetDWork(S, 0))[0] == 0U) {
    /* Entry: BSC/Chart2 */
    ((uint8_T *)ssGetDWork(S, 0))[0] = 1U;

    /* Entry Internal: BSC/Chart2 */
    ((uint8_T *)ssGetDWork(S, 1))[0] = BSC_IN_main;

    /* Outputs for Function Call SubSystem: '<S1>/check_type' */

    /* Entry Internal 'main': '<S2>:2' */
    /* Transition: '<S2>:12' */
    /* Transition: '<S2>:4' */
    /* Event: '<S2>:43' */
    BSC_check_type(S, *((const uint8_T **)ssGetInputPortSignalPtrs(S, 4))[0],
                   *((const uint8_T **)ssGetInputPortSignalPtrs(S, 5))[0], *((
      const uint8_T **)ssGetInputPortSignalPtrs(S, 6))[0], *((const uint8_T **)
      ssGetInputPortSignalPtrs(S, 7))[0], *((const uint8_T **)
      ssGetInputPortSignalPtrs(S, 8))[0], *((const uint8_T **)
      ssGetInputPortSignalPtrs(S, 9))[0], *((const uint8_T **)
      ssGetInputPortSignalPtrs(S, 10))[0], *((const uint8_T **)
      ssGetInputPortSignalPtrs(S, 11))[0], *((const uint8_T **)
      ssGetInputPortSignalPtrs(S, 12))[0], *((const uint8_T **)
      ssGetInputPortSignalPtrs(S, 13))[0], *((const uint8_T **)
      ssGetInputPortSignalPtrs(S, 14))[0], &_rtB->check_type);

    /* End of Outputs for SubSystem: '<S1>/check_type' */

    /* Outputs for Function Call SubSystem: '<S1>/Fault_level' */

    /* Transition: '<S2>:15' */
    /* Event: '<S2>:37' */
    BSC_Fault_level(S);

    /* End of Outputs for SubSystem: '<S1>/Fault_level' */

    /* Outputs for Function Call SubSystem: '<S1>/key_cycle' */

    /* Transition: '<S2>:30' */
    /* Event: '<S2>:39' */
    BSC_key_cycle(S, _rtB->MinMax1, *((const uint8_T **)ssGetInputPortSignalPtrs
      (S, 2))[0], &_rtB->key_cycle, &_rtZCE->key_cycle);

    /* End of Outputs for SubSystem: '<S1>/key_cycle' */

    /* Outputs for Function Call SubSystem: '<S1>/sleepCheck' */

    /* Transition: '<S2>:33' */
    /* Event: '<S2>:41' */
    BSC_sleepCheck(S);

    /* End of Outputs for SubSystem: '<S1>/sleepCheck' */

    /* Outputs for Function Call SubSystem: '<S1>/cc_c  md' */

    /* Transition: '<S2>:8' */
    /* Event: '<S2>:40' */
    BSC_cc_cmd(S);

    /* End of Outputs for SubSystem: '<S1>/cc_c  md' */

    /* Outputs for Function Call SubSystem: '<S1>/rsnToOpenCC' */

    /* Transition: '<S2>:10' */
    /* Event: '<S2>:38' */
    BSC_rsnToOpenCC(S);

    /* End of Outputs for SubSystem: '<S1>/rsnToOpenCC' */
  } else {
    /* Outputs for Function Call SubSystem: '<S1>/check_type' */

    /* During 'main': '<S2>:2' */
    /* Transition: '<S2>:12' */
    /* Transition: '<S2>:4' */
    /* Event: '<S2>:43' */
    BSC_check_type(S, *((const uint8_T **)ssGetInputPortSignalPtrs(S, 4))[0],
                   *((const uint8_T **)ssGetInputPortSignalPtrs(S, 5))[0], *((
      const uint8_T **)ssGetInputPortSignalPtrs(S, 6))[0], *((const uint8_T **)
      ssGetInputPortSignalPtrs(S, 7))[0], *((const uint8_T **)
      ssGetInputPortSignalPtrs(S, 8))[0], *((const uint8_T **)
      ssGetInputPortSignalPtrs(S, 9))[0], *((const uint8_T **)
      ssGetInputPortSignalPtrs(S, 10))[0], *((const uint8_T **)
      ssGetInputPortSignalPtrs(S, 11))[0], *((const uint8_T **)
      ssGetInputPortSignalPtrs(S, 12))[0], *((const uint8_T **)
      ssGetInputPortSignalPtrs(S, 13))[0], *((const uint8_T **)
      ssGetInputPortSignalPtrs(S, 14))[0], &_rtB->check_type);

    /* End of Outputs for SubSystem: '<S1>/check_type' */

    /* Outputs for Function Call SubSystem: '<S1>/Fault_level' */

    /* Transition: '<S2>:15' */
    /* Event: '<S2>:37' */
    BSC_Fault_level(S);

    /* End of Outputs for SubSystem: '<S1>/Fault_level' */

    /* Outputs for Function Call SubSystem: '<S1>/key_cycle' */

    /* Transition: '<S2>:30' */
    /* Event: '<S2>:39' */
    BSC_key_cycle(S, _rtB->MinMax1, *((const uint8_T **)ssGetInputPortSignalPtrs
      (S, 2))[0], &_rtB->key_cycle, &_rtZCE->key_cycle);

    /* End of Outputs for SubSystem: '<S1>/key_cycle' */

    /* Outputs for Function Call SubSystem: '<S1>/sleepCheck' */

    /* Transition: '<S2>:33' */
    /* Event: '<S2>:41' */
    BSC_sleepCheck(S);

    /* End of Outputs for SubSystem: '<S1>/sleepCheck' */

    /* Outputs for Function Call SubSystem: '<S1>/cc_c  md' */

    /* Transition: '<S2>:8' */
    /* Event: '<S2>:40' */
    BSC_cc_cmd(S);

    /* End of Outputs for SubSystem: '<S1>/cc_c  md' */

    /* Outputs for Function Call SubSystem: '<S1>/rsnToOpenCC' */

    /* Transition: '<S2>:10' */
    /* Event: '<S2>:38' */
    BSC_rsnToOpenCC(S);

    /* End of Outputs for SubSystem: '<S1>/rsnToOpenCC' */
  }

  /* End of Chart: '<S1>/Chart2' */

  /* Outport: '<Root>/CVTN supply signal' incorporates:
   *  Inport: '<Root>/Charger PSR'
   *  Inport: '<Root>/Vehicle PSR'
   *  Logic: '<S1>/Logical Operator5'
   */
  ((boolean_T *)ssGetOutputPortSignal(S, 0))[0] = ((*((const uint8_T **)
    ssGetInputPortSignalPtrs(S, 0))[0] != 0) || (*((const uint8_T **)
    ssGetInputPortSignalPtrs(S, 1))[0] != 0));

  /* End of Outputs for SubSystem: '<Root>/BSC' */

  /* Outport: '<Root>/Reason to open contactor to CAN' */
  ((uint8_T *)ssGetOutputPortSignal(S, 4))[0] = _rtB->Merge;

  /* Outport: '<Root>/Fault Type' */
  ((uint8_T *)ssGetOutputPortSignal(S, 7))[0] = _rtB->check_type.type_of_fault;
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
    rt_FREE(_ssGetPrevZCSigState(S));
  }

  rt_FREE(ssGetUserData(S));

#endif

}

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "BSC_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 1);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 8))
    return;

  /* outport number: 0 */
  if (!ssSetOutputPortVectorDimension(S, 0, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 0, SS_BOOLEAN);
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

  /* outport number: 3 */
  if (!ssSetOutputPortVectorDimension(S, 3, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 3, SS_BOOLEAN);
  }

  ssSetOutputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);

  /* outport number: 4 */
  if (!ssSetOutputPortVectorDimension(S, 4, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 4, SS_UINT8);
  }

  ssSetOutputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);

  /* outport number: 5 */
  if (!ssSetOutputPortVectorDimension(S, 5, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 5, SS_UINT8);
  }

  ssSetOutputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);

  /* outport number: 6 */
  if (!ssSetOutputPortVectorDimension(S, 6, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 6, SS_UINT8);
  }

  ssSetOutputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);

  /* outport number: 7 */
  if (!ssSetOutputPortVectorDimension(S, 7, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 7, SS_UINT8);
  }

  ssSetOutputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 15))
    return;

  /* inport number: 0 */
  {
    if (!ssSetInputPortVectorDimension(S, 0, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 0, SS_UINT8);
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
      ssSetInputPortDataType(S, 1, SS_UINT8);
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
      ssSetInputPortDataType(S, 2, SS_UINT8);
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
      ssSetInputPortDataType(S, 3, SS_DOUBLE);
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
      ssSetInputPortDataType(S, 5, SS_UINT8);
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
      ssSetInputPortDataType(S, 6, SS_UINT8);
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
      ssSetInputPortDataType(S, 7, SS_UINT8);
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
      ssSetInputPortDataType(S, 8, SS_UINT8);
    }

    ssSetInputPortDirectFeedThrough(S, 8, 1);
    ssSetInputPortOverWritable(S, 8, 0);
    ssSetInputPortOptimOpts(S, 8, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 9 */
  {
    if (!ssSetInputPortVectorDimension(S, 9, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 9, SS_UINT8);
    }

    ssSetInputPortDirectFeedThrough(S, 9, 1);
    ssSetInputPortOverWritable(S, 9, 0);
    ssSetInputPortOptimOpts(S, 9, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 10 */
  {
    if (!ssSetInputPortVectorDimension(S, 10, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 10, SS_UINT8);
    }

    ssSetInputPortDirectFeedThrough(S, 10, 1);
    ssSetInputPortOverWritable(S, 10, 0);
    ssSetInputPortOptimOpts(S, 10, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 11 */
  {
    if (!ssSetInputPortVectorDimension(S, 11, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 11, SS_UINT8);
    }

    ssSetInputPortDirectFeedThrough(S, 11, 1);
    ssSetInputPortOverWritable(S, 11, 0);
    ssSetInputPortOptimOpts(S, 11, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 12 */
  {
    if (!ssSetInputPortVectorDimension(S, 12, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 12, SS_UINT8);
    }

    ssSetInputPortDirectFeedThrough(S, 12, 1);
    ssSetInputPortOverWritable(S, 12, 0);
    ssSetInputPortOptimOpts(S, 12, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 13 */
  {
    if (!ssSetInputPortVectorDimension(S, 13, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 13, SS_UINT8);
    }

    ssSetInputPortDirectFeedThrough(S, 13, 1);
    ssSetInputPortOverWritable(S, 13, 0);
    ssSetInputPortOptimOpts(S, 13, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 14 */
  {
    if (!ssSetInputPortVectorDimension(S, 14, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 14, SS_UINT8);
    }

    ssSetInputPortDirectFeedThrough(S, 14, 1);
    ssSetInputPortOverWritable(S, 14, 0);
    ssSetInputPortOptimOpts(S, 14, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 9)) {
    return;
  }

  /* '<S1>/Chart2': DWORK1 */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 1);
  ssSetDWorkDataType(S, 0, SS_UINT8);

  /* '<S1>/Chart2': DWORK2 */
  ssSetDWorkName(S, 1, "DWORK1");
  ssSetDWorkWidth(S, 1, 1);
  ssSetDWorkDataType(S, 1, SS_UINT8);

  /* '<S6>/key_cycle_chart': DWORK1 */
  ssSetDWorkName(S, 2, "DWORK2");
  ssSetDWorkWidth(S, 2, 1);
  ssSetDWorkDataType(S, 2, SS_INT32);

  /* '<S6>/key_cycle_chart': DWORK4 */
  ssSetDWorkName(S, 3, "DWORK3");
  ssSetDWorkWidth(S, 3, 1);
  ssSetDWorkDataType(S, 3, SS_UINT8);

  /* '<S6>/key_cycle_chart': DWORK5 */
  ssSetDWorkName(S, 4, "DWORK4");
  ssSetDWorkWidth(S, 4, 1);
  ssSetDWorkDataType(S, 4, SS_UINT8);

  /* '<S6>/key_cycle_chart': DWORK6 */
  ssSetDWorkName(S, 5, "DWORK5");
  ssSetDWorkWidth(S, 5, 1);
  ssSetDWorkDataType(S, 5, SS_UINT8);

  /* '<S6>/key_cycle_chart': DWORK7 */
  ssSetDWorkName(S, 6, "DWORK6");
  ssSetDWorkWidth(S, 6, 1);
  ssSetDWorkDataType(S, 6, SS_UINT8);

  /* '<S6>/key_cycle_chart': DWORK3 */
  ssSetDWorkName(S, 7, "DWORK7");
  ssSetDWorkWidth(S, 7, 1);
  ssSetDWorkDataType(S, 7, SS_UINT8);

  /* '<S6>/key_cycle_chart': DWORK2 */
  ssSetDWorkName(S, 8, "DWORK8");
  ssSetDWorkWidth(S, 8, 1);
  ssSetDWorkDataType(S, 8, SS_UINT8);

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 0);

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
# define S_FUNCTION_NAME               BSC_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
