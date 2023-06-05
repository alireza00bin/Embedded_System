/*
 * File: Q4.h
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

#ifndef RTW_HEADER_Q4_h_
#define RTW_HEADER_Q4_h_
#ifndef Q4_COMMON_INCLUDES_
#define Q4_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Q4_COMMON_INCLUDES_ */

#include "Q4_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T c;                            /* '<Root>/Chart' */
  uint8_T is_active_c3_Q4;             /* '<Root>/Chart' */
  uint8_T is_B;                        /* '<Root>/Chart' */
  uint8_T is_C;                        /* '<Root>/Chart' */
  uint8_T is_D;                        /* '<Root>/Chart' */
} DW_Q4_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Input;                        /* '<Root>/Input' */
  real_T Input1;                       /* '<Root>/Input1' */
  real_T Input2;                       /* '<Root>/Input2' */
  real_T Input3;                       /* '<Root>/Input3' */
} ExtU_Q4_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Output;                       /* '<Root>/Output' */
  real_T Output1;                      /* '<Root>/Output1' */
  real_T Output2;                      /* '<Root>/Output2' */
  real_T Output3;                      /* '<Root>/Output3' */
  real_T Output4;                      /* '<Root>/Output4' */
} ExtY_Q4_T;

/* Real-time Model Data Structure */
struct tag_RTM_Q4_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Q4_T Q4_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Q4_T Q4_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Q4_T Q4_Y;

/* Model entry point functions */
extern void Q4_initialize(void);
extern void Q4_step(void);
extern void Q4_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Q4_T *const Q4_M;

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
 * '<Root>' : 'Q4'
 * '<S1>'   : 'Q4/Chart'
 */
#endif                                 /* RTW_HEADER_Q4_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
