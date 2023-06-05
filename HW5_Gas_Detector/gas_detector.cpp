/*
 * File: rtwtypes.h
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

#ifndef RTWTYPES_H
#define RTWTYPES_H

/* Logical type definitions */
#if (!defined(__cplusplus))
#ifndef false
#define false                          (0U)
#endif

#ifndef true
#define true                           (1U)
#endif
#endif

/*=======================================================================*
 * Target hardware information
 *   Device type: Intel->x86-64 (Windows64)
 *   Number of bits:     char:   8    short:   16    int:  32
 *                       long:  32
 *                       native word size:  64
 *   Byte ordering: LittleEndian
 *   Signed integer division rounds to: Zero
 *   Shift right on a signed integer as arithmetic shift: on
 *=======================================================================*/

/*=======================================================================*
 * Fixed width word size data types:                                     *
 *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *
 *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *
 *   real32_T, real64_T           - 32 and 64 bit floating point numbers *
 *=======================================================================*/
typedef signed char int8_T;
typedef unsigned char uint8_T;
typedef short int16_T;
typedef unsigned short uint16_T;
typedef int int32_T;
typedef unsigned int uint32_T;
typedef float real32_T;
typedef double real64_T;

/*===========================================================================*
 * Generic type definitions: boolean_T, char_T, byte_T, int_T, uint_T,       *
 *                           real_T, time_T, ulong_T.                        *
 *===========================================================================*/
typedef double real_T;
typedef double time_T;
typedef unsigned char boolean_T;
typedef int int_T;
typedef unsigned int uint_T;
typedef unsigned long ulong_T;
typedef char char_T;
typedef unsigned char uchar_T;
typedef char_T byte_T;

/*===========================================================================*
 * Complex number type definitions                                           *
 *===========================================================================*/
#define CREAL_T

typedef struct {
  real32_T re;
  real32_T im;
} creal32_T;

typedef struct {
  real64_T re;
  real64_T im;
} creal64_T;

typedef struct {
  real_T re;
  real_T im;
} creal_T;

#define CINT8_T

typedef struct {
  int8_T re;
  int8_T im;
} cint8_T;

#define CUINT8_T

typedef struct {
  uint8_T re;
  uint8_T im;
} cuint8_T;

#define CINT16_T

typedef struct {
  int16_T re;
  int16_T im;
} cint16_T;

#define CUINT16_T

typedef struct {
  uint16_T re;
  uint16_T im;
} cuint16_T;

#define CINT32_T

typedef struct {
  int32_T re;
  int32_T im;
} cint32_T;

#define CUINT32_T

typedef struct {
  uint32_T re;
  uint32_T im;
} cuint32_T;

/*=======================================================================*
 * Min and Max:                                                          *
 *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *
 *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *
 *=======================================================================*/
#define MAX_int8_T                     ((int8_T)(127))
#define MIN_int8_T                     ((int8_T)(-128))
#define MAX_uint8_T                    ((uint8_T)(255U))
#define MAX_int16_T                    ((int16_T)(32767))
#define MIN_int16_T                    ((int16_T)(-32768))
#define MAX_uint16_T                   ((uint16_T)(65535U))
#define MAX_int32_T                    ((int32_T)(2147483647))
#define MIN_int32_T                    ((int32_T)(-2147483647-1))
#define MAX_uint32_T                   ((uint32_T)(0xFFFFFFFFU))

/* Block D-Work pointer type */
typedef void * pointer_T;

#endif                                 /* RTWTYPES_H */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
/*
 * File: Gas_Detector_types.h
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

#ifndef RTW_HEADER_Gas_Detector_types_h_
#define RTW_HEADER_Gas_Detector_types_h_

/* Model Code Variants */

/* Forward declaration for rtModel */
typedef struct tag_RTM_Gas_Detector_T RT_MODEL_Gas_Detector_T;

#endif                                 /* RTW_HEADER_Gas_Detector_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
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
//#include "rtwtypes.h"
#endif                                 /* Gas_Detector_COMMON_INCLUDES_ */

//#include "Gas_Detector_types.h"

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

/*#include "Gas_Detector.h"
#include "rtwtypes.h"*/

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
// C++ code
//
#define IN1 13
#define IN2 12
#define motorPin 7
#define TriggerPin A1
#define EchoPin A2

float duration = 0.0;
void setup()
{
	Serial.begin(9600);
	pinMode(IN1, OUTPUT); //L2930 Input 1
	pinMode(IN2, OUTPUT); //L2930 Input 2
	pinMode(motorPin, OUTPUT);
	pinMode(TriggerPin, OUTPUT);
	pinMode(EchoPin, INPUT);
	Gas_Detector_initialize();
}

void loop()
{
	
	//GAS Sensor
	float a = analogRead(A0);
	Gas_Detector_U.gas = map(a, 0, 1023, 0, 255);
	
	//Read Distance
	digitalWrite(TriggerPin, LOW);
	delayMicroseconds(5);        
	digitalWrite(TriggerPin, HIGH);  
	delayMicroseconds(10);      
	digitalWrite(TriggerPin, LOW);
	
	duration = pulseIn(EchoPin, HIGH);
	Gas_Detector_U.distance = (duration*0.034)/2;  
	
	Serial.print("GasPPM: ");
	Serial.print(Gas_Detector_U.gas);
	Serial.print(" ");
	Serial.print("Distance: ");
	Serial.print(Gas_Detector_U.distance);
	Serial.print("\t");
	
	//Write Fan
	if (Gas_Detector_Y.fan == 0.0)
		analogWrite(motorPin, 0);
	else 
		analogWrite(motorPin, 255);
	
	//Write Motor
	if (Gas_Detector_Y.wheels == 1.0){
		digitalWrite(IN1,HIGH);
		digitalWrite(IN2,LOW);
	} else if (Gas_Detector_Y.wheels == -1.0){
		digitalWrite(IN1,LOW);
		digitalWrite(IN2,HIGH);
	} else {
		digitalWrite(IN1,LOW);
		digitalWrite(IN2,LOW);
	}
	
	Serial.print("Fan: ");
	Serial.println(Gas_Detector_Y.fan);
	Serial.print(" ");
	Serial.print("Motor: ");
	Serial.print(Gas_Detector_Y.wheels);
	

	Gas_Detector_step();
	delay(1000);
}