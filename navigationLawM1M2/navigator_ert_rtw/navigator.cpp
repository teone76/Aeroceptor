/*
 * File: navigator.cpp
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

#include "navigator.h"
#include "navigator_private.h"

/* External inputs (root inport signals with auto storage) */
ExtU_navigator_T navigator_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_navigator_T navigator_Y;

/* Real-time model */
RT_MODEL_navigator_T navigator_M_;
RT_MODEL_navigator_T *const navigator_M = &navigator_M_;

/* Model step function */
void navigator_step(void)
{
  int16_T i;

  /* Outport: '<Root>/Out' */
  for (i = 0; i < 15; i++) {
    navigator_Y.Out[i] = 0.0F;
  }

  /* End of Outport: '<Root>/Out' */
}

/* Model initialize function */
void navigator_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(navigator_M, (NULL));

  /* external inputs */
  (void) memset(navigator_U.In, 0,
                21U*sizeof(real32_T));

  /* external outputs */
  (void) memset(&navigator_Y.Out[0], 0,
                15U*sizeof(real32_T));
}

/* Model terminate function */
void navigator_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
