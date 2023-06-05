/*
 * File: Gas_Detector.h
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

#ifndef RTW_HEADER_Gas_Detector_h_
#define RTW_HEADER_Gas_Detector_h_
#ifndef Gas_Detector_COMMON_INCLUDES_
#define Gas_Detector_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Gas_Detector_COMMON_INCLUDES_ */

#include "Gas_Detector_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_Gas_Detector;   /* '<Root>/Chart' */
  uint8_T is_c3_Gas_Detector;          /* '<Root>/Chart' */
} DW_Gas_Detector_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T gas;                          /* '<Root>/gas' */
  real_T distance;                     /* '<Root>/distance' */
} ExtU_Gas_Detector_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T fan;                          /* '<Root>/fan' */
  real_T wheels;                       /* '<Root>/wheels' */
} ExtY_Gas_Detector_T;

/* Real-time Model Data Structure */
struct tag_RTM_Gas_Detector_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Gas_Detector_T Gas_Detector_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Gas_Detector_T Gas_Detector_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Gas_Detector_T Gas_Detector_Y;

/* Model entry point functions */
extern void Gas_Detector_initialize(void);
extern void Gas_Detector_step(void);
extern void Gas_Detector_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Gas_Detector_T *const Gas_Detector_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Gas_Detector'
 * '<S1>'   : 'Gas_Detector/Chart'
 */
#endif                                 /* RTW_HEADER_Gas_Detector_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
