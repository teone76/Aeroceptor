/*
 * File: navigator_data.cpp
 *
 * Code generated for Simulink model 'navigator'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Tue Mar 03 17:11:32 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. Safety precaution
 *    3. ROM efficiency
 *    4. RAM efficiency
 * Validation result: Passed (11), Warnings (4), Error (1)
 */

#include "navigator.h"
#include "navigator_private.h"

/* Block parameters (auto storage) */
P_navigator_T navigator_P = {
  /*  Expression: LL0
   * Referenced by: '<S3>/initial_pos'
   */
  { 44.0, 12.0 },

  /*  Expression: LL0
   * Referenced by: '<S15>/initial_pos'
   */
  { 44.2018928, 12.0625658 },
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S16>/Constant5'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S16>/Constant4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S16>/Gain3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S16>/Constant1'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S16>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S16>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S16>/Gain2'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S16>/Constant3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S16>/Gain4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S17>/Constant2'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S17>/Constant'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S17>/Gain'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S19>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S20>/Constant2'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S20>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S23>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S25>/Constant'
                                        */
  0.0033528106647474805,               /* Expression: F
                                        * Referenced by: '<S24>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S24>/f'
                                        */
  44.2018928,                          /* Expression: LL0(1)
                                        * Referenced by: '<S15>/initial_latg'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S22>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S20>/Constant'
                                        */
  0.0,                                 /* Expression: psi
                                        * Referenced by: '<S18>/ref_pos'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S21>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S20>/Constant3'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S2>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/dt'
                                        */
  0.0,                                 /* Expression: psi
                                        * Referenced by: '<S6>/ref_pos'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S10>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/dt1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Constant2'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S9>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S12>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S14>/Constant'
                                        */
  0.0033528106647474805,               /* Expression: F
                                        * Referenced by: '<S13>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S13>/f'
                                        */
  44.0,                                /* Expression: LL0(1)
                                        * Referenced by: '<S3>/initial_latg'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S11>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Constant3'
                                        */
  57.295779513082323,                  /* Expression: slope
                                        * Referenced by: '<S8>/Unit Conversion'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S5>/Constant5'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S5>/Constant4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S5>/Gain3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S5>/Constant1'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S5>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S5>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S5>/Gain2'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S5>/Constant3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S5>/Gain4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S7>/Constant2'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S7>/Constant'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S7>/Gain'
                                        */
  0.0F,                                /* Computed Parameter: Constant_Value_ci
                                        * Referenced by: '<S1>/Constant'
                                        */
  0.0F                                 /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S4>/Constant'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
