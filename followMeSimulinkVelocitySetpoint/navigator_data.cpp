/*
 * File: navigator_data.cpp
 *
 * Code generated for Simulink model 'navigator'.
 *
 * Model version                  : 1.31
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Mon Apr 13 11:18:35 2015
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
  /*  Expression: [0 0 0]
   * Referenced by: '<S2>/Constant1'
   */
  { 0.0, 0.0, 0.0 },
  0.5,                                 /* Expression: k_sat
                                        * Referenced by: '<S7>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Saturation'
                                        */

  /*  Expression: LL0
   * Referenced by: '<S3>/initial_pos'
   */
  { 44.2018928, 12.0625658 },

  /*  Expression: LL0
   * Referenced by: '<S18>/initial_pos'
   */
  { 44.2018928, 12.0625658 },
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S19>/Constant5'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S19>/Constant4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S19>/Gain3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S19>/Constant1'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S19>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S19>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S19>/Gain2'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S19>/Constant3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S19>/Gain4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S20>/Constant2'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S20>/Constant'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S20>/Gain'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S22>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S23>/Constant2'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S23>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S26>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S28>/Constant'
                                        */
  0.0033528106647474805,               /* Expression: F
                                        * Referenced by: '<S27>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S27>/f'
                                        */
  44.2018928,                          /* Expression: LL0(1)
                                        * Referenced by: '<S18>/initial_latg'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S25>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S23>/Constant'
                                        */
  0.0,                                 /* Expression: psi
                                        * Referenced by: '<S21>/ref_pos'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S24>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S23>/Constant3'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S40>/Gain1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S6>/dt'
                                        */
  0.0,                                 /* Expression: psi
                                        * Referenced by: '<S9>/ref_pos'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S13>/Unit Conversion'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S6>/dt1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S12>/Constant2'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S12>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S17>/Constant'
                                        */
  0.0033528106647474805,               /* Expression: F
                                        * Referenced by: '<S16>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S16>/f'
                                        */
  44.2018928,                          /* Expression: LL0(1)
                                        * Referenced by: '<S3>/initial_latg'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S14>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S12>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S12>/Constant3'
                                        */
  57.295779513082323,                  /* Expression: slope
                                        * Referenced by: '<S11>/Unit Conversion'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S8>/Constant5'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S8>/Constant4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S8>/Gain3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S8>/Constant1'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S8>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S8>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S8>/Gain2'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S8>/Constant3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S8>/Gain4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S10>/Constant2'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S10>/Constant'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S10>/Gain'
                                        */

  /*  Expression: LL0
   * Referenced by: '<S29>/initial_pos'
   */
  { 44.2018928, 12.0625658 },
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S30>/Constant5'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S30>/Constant4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S30>/Gain3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S30>/Constant1'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S30>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S30>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S30>/Gain2'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S30>/Constant3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S30>/Gain4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S31>/Constant2'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S31>/Constant'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S31>/Gain'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S33>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S34>/Constant2'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S34>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S37>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S39>/Constant'
                                        */
  0.0033528106647474805,               /* Expression: F
                                        * Referenced by: '<S38>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S38>/f'
                                        */
  44.2018928,                          /* Expression: LL0(1)
                                        * Referenced by: '<S29>/initial_latg'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S36>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S34>/Constant'
                                        */
  0.0,                                 /* Expression: psi
                                        * Referenced by: '<S32>/ref_pos'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S35>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S34>/Constant3'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S2>/Switch'
                                        */
  0.0F,                                /* Computed Parameter: Constant_Value_f1
                                        * Referenced by: '<S4>/Constant'
                                        */
  0.0F                                 /* Computed Parameter: Constant_Value_kn
                                        * Referenced by: '<S5>/Constant'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
