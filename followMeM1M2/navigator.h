/*
 * File: navigator.h
 *
 * Code generated for Simulink model 'navigator'.
 *
 * Model version                  : 1.54
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Fri Jun 05 10:43:44 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. Safety precaution
 *    3. ROM efficiency
 *    4. RAM efficiency
 * Validation result: Passed (10), Warnings (5), Error (1)
 */

#ifndef RTW_HEADER_navigator_h_
#define RTW_HEADER_navigator_h_
#ifndef navigator_COMMON_INCLUDES_
# define navigator_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* navigator_COMMON_INCLUDES_ */

#include "navigator_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real32_T In[21];                     /* '<Root>/In' */
} ExtU_navigator_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real32_T Out[15];                    /* '<Root>/Out' */
} ExtY_navigator_T;

/* Real-time Model Data Structure */
struct tag_RTM_navigator_T {
  const char_T * volatile errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

  /* External inputs (root inport signals with auto storage) */
  extern ExtU_navigator_T navigator_U;

  /* External outputs (root outports fed by signals with auto storage) */
  extern ExtY_navigator_T navigator_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void navigator_initialize(void);
  extern void navigator_step(void);
  extern void navigator_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_navigator_T *const navigator_M;

#ifdef __cplusplus

}
#endif

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
 * '<Root>' : 'navigator'
 * '<S1>'   : 'navigator/navigation_law'
 * '<S2>'   : 'navigator/navigation_law/CalcSetpoints'
 * '<S3>'   : 'navigator/navigation_law/CalcVelocitySetpoints'
 * '<S4>'   : 'navigator/navigation_law/LLA_TO_earthFlat1'
 * '<S5>'   : 'navigator/navigation_law/LLA_TO_earthFlat2'
 * '<S6>'   : 'navigator/navigation_law/CalcSetpoints/Degrees to Radians'
 * '<S7>'   : 'navigator/navigation_law/CalcVelocitySetpoints/sat  '
 * '<S8>'   : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth'
 * '<S9>'   : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Latitude  Between  +//- 90'
 * '<S10>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Longitude Between +//-180'
 * '<S11>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem'
 * '<S12>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/pos_rad'
 * '<S13>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance'
 * '<S14>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/pos_deg'
 * '<S15>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
 * '<S16>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
 * '<S17>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
 * '<S18>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
 * '<S19>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth'
 * '<S20>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Latitude  Between  +//- 90'
 * '<S21>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Longitude Between +//-180'
 * '<S22>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem'
 * '<S23>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/pos_rad'
 * '<S24>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem/Find Radian//Distance'
 * '<S25>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem/pos_deg'
 * '<S26>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
 * '<S27>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
 * '<S28>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
 * '<S29>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
 */
#endif                                 /* RTW_HEADER_navigator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
