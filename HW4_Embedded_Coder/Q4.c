/*
 * File: Q4.c
 *
 * Code generated for Simulink model 'Q4'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Jun  3 13:15:13 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Q4.h"
#include "rtwtypes.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Q4_IN_D                        ((uint8_T)1U)
#define Q4_IN_D1                       ((uint8_T)1U)
#define Q4_IN_D2                       ((uint8_T)2U)
#define Q4_IN_G                        ((uint8_T)2U)
#define Q4_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define Q4_IN_one                      ((uint8_T)1U)
#define Q4_IN_two                      ((uint8_T)2U)

/* Block states (default storage) */
DW_Q4_T Q4_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Q4_T Q4_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Q4_T Q4_Y;

/* Real-time model */
static RT_MODEL_Q4_T Q4_M_;
RT_MODEL_Q4_T *const Q4_M = &Q4_M_;

/* Model step function */
void Q4_step(void)
{
  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/Input'
   *  Inport: '<Root>/Input1'
   *  Inport: '<Root>/Input2'
   *  Inport: '<Root>/Input3'
   */
  if (Q4_DW.is_active_c3_Q4 == 0U) {
    Q4_DW.is_active_c3_Q4 = 1U;
    Q4_DW.is_B = Q4_IN_one;

    /* Outport: '<Root>/Output3' */
    Q4_Y.Output3 = 1.0;
    Q4_DW.is_C = Q4_IN_G;

    /* Outport: '<Root>/Output2' */
    Q4_Y.Output2 = 1.0;
  } else {
    if (Q4_DW.is_B == Q4_IN_one) {
      if (Q4_DW.c != 0.0) {
        /* Outport: '<Root>/Output3' */
        Q4_Y.Output3 = 0.0;
        Q4_DW.is_B = Q4_IN_two;

        /* Outport: '<Root>/Output4' */
        Q4_Y.Output4 = 1.0;
      }

      /* case IN_two: */
    } else if ((Q4_U.Input1 != 0.0) && (Q4_DW.is_D == Q4_IN_D2)) {
      /* Outport: '<Root>/Output4' */
      Q4_Y.Output4 = 0.0;
      Q4_DW.is_B = Q4_IN_one;

      /* Outport: '<Root>/Output3' */
      Q4_Y.Output3 = 1.0;
    }

    if (Q4_DW.is_C == Q4_IN_D) {
      if (Q4_U.Input2 != 0.0) {
        /* Outport: '<Root>/Output' */
        Q4_Y.Output = 0.0;

        /* Outport: '<Root>/Output1' */
        Q4_Y.Output1 = 0.0;
        Q4_DW.is_D = Q4_IN_NO_ACTIVE_CHILD;
        Q4_DW.is_C = Q4_IN_G;

        /* Outport: '<Root>/Output2' */
        Q4_Y.Output2 = 1.0;
      } else if (Q4_DW.is_D == Q4_IN_D1) {
        if (Q4_U.Input3 != 0.0) {
          /* Outport: '<Root>/Output' */
          Q4_Y.Output = 0.0;
          Q4_DW.is_D = Q4_IN_D2;

          /* Outport: '<Root>/Output1' */
          Q4_Y.Output1 = 1.0;
        }

        /* case IN_D2: */
      } else if (Q4_U.Input3 != 0.0) {
        Q4_DW.is_B = Q4_IN_one;

        /* Outport: '<Root>/Output3' */
        Q4_Y.Output3 = 1.0;
        Q4_DW.is_D = Q4_IN_D2;

        /* Outport: '<Root>/Output1' */
        Q4_Y.Output1 = 1.0;
      }

      /* case IN_G: */
    } else if (Q4_U.Input != 0.0) {
      Q4_DW.c = 1.0;

      /* Outport: '<Root>/Output2' */
      Q4_Y.Output2 = 1.0;
      Q4_DW.is_C = Q4_IN_D;
      Q4_DW.is_D = Q4_IN_D1;

      /* Outport: '<Root>/Output' */
      Q4_Y.Output = 1.0;
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void Q4_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Q4_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
