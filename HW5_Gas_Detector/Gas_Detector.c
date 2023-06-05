/*
 * File: Gas_Detector.c
 *
 * Code generated for Simulink model 'Gas_Detector'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Jun  3 23:20:10 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Gas_Detector.h"
#include "rtwtypes.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Gas_Detector_IN_Danger         ((uint8_T)1U)
#define Gas_Detector_IN_Normal         ((uint8_T)2U)

/* Block states (default storage) */
DW_Gas_Detector_T Gas_Detector_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Gas_Detector_T Gas_Detector_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Gas_Detector_T Gas_Detector_Y;

/* Real-time model */
static RT_MODEL_Gas_Detector_T Gas_Detector_M_;
RT_MODEL_Gas_Detector_T *const Gas_Detector_M = &Gas_Detector_M_;

/* Model step function */
void Gas_Detector_step(void)
{
  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/distance'
   *  Inport: '<Root>/gas'
   */
  if (Gas_Detector_DW.is_active_c3_Gas_Detector == 0U) {
    Gas_Detector_DW.is_active_c3_Gas_Detector = 1U;
    Gas_Detector_DW.is_c3_Gas_Detector = Gas_Detector_IN_Normal;
  } else if (Gas_Detector_DW.is_c3_Gas_Detector == Gas_Detector_IN_Danger) {
    if ((Gas_Detector_U.distance > 100.0) || (Gas_Detector_U.gas < 45.0)) {
      /* Outport: '<Root>/fan' */
      Gas_Detector_Y.fan = 1.0;

      /* Outport: '<Root>/wheels' */
      Gas_Detector_Y.wheels = 1.0;
      Gas_Detector_DW.is_c3_Gas_Detector = Gas_Detector_IN_Normal;
    }

    /* case IN_Normal: */
  } else if ((Gas_Detector_U.distance < 95.0) || (Gas_Detector_U.gas > 55.0)) {
    /* Outport: '<Root>/fan' */
    Gas_Detector_Y.fan = 0.0;

    /* Outport: '<Root>/wheels' */
    Gas_Detector_Y.wheels = -1.0;
    Gas_Detector_DW.is_c3_Gas_Detector = Gas_Detector_IN_Danger;
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void Gas_Detector_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Gas_Detector_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
