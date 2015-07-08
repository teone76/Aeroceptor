/*
 * File: navigator_data.cpp
 *
 * Code generated for Simulink model 'navigator'.
 *
 * Model version                  : 1.53
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Thu Apr 23 13:41:54 2015
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
   * Referenced by: '<S3>/Constant1'
   */
  { 0.0, 0.0, 0.0 },
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S3>/Gain'
                                        */
  5.0,                                 /* Expression: k_sat
                                        * Referenced by: '<S12>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Saturation'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<S4>/Constant1'
   */
  { 0.0, 0.0, 0.0 },
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S4>/Gain'
                                        */
  5.0,                                 /* Expression: k_sat
                                        * Referenced by: '<S13>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Saturation'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<S9>/vect'
   */
  { 0.0, 0.0, 0.0 },
  0.8,                                 /* Expression: 0.8
                                        * Referenced by: '<S8>/Gain2'
                                        */
  5.0,                                 /* Expression: k_sat
                                        * Referenced by: '<S49>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S49>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Vz2'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<S10>/vect'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S8>/Gain1'
                                        */
  0.8,                                 /* Expression: 0.8
                                        * Referenced by: '<S8>/Gain'
                                        */
  5.0,                                 /* Expression: k_sat
                                        * Referenced by: '<S48>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S48>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Vz1'
                                        */

  /*  Expression: LL0
   * Referenced by: '<S14>/initial_pos'
   */
  { 44.2018928, 12.0625658 },
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S15>/Constant5'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S15>/Constant4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S15>/Gain3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S15>/Constant1'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S15>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S15>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S15>/Gain2'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S15>/Constant3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S15>/Gain4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S16>/Constant2'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S16>/Constant'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S16>/Gain'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S18>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S19>/Constant2'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S19>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S22>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S24>/Constant'
                                        */
  0.0033528106647474805,               /* Expression: F
                                        * Referenced by: '<S23>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S23>/f'
                                        */
  44.2018928,                          /* Expression: LL0(1)
                                        * Referenced by: '<S14>/initial_latg'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S21>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S19>/Constant'
                                        */
  0.0,                                 /* Expression: psi
                                        * Referenced by: '<S17>/ref_pos'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S20>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S19>/Constant3'
                                        */
  7.0,                                 /* Expression: 7
                                        * Referenced by: '<S1>/radius'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S11>/Gain1'
                                        */

  /*  Expression: LL0
   * Referenced by: '<S25>/initial_pos'
   */
  { 44.2018928, 12.0625658 },
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S26>/Constant5'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S26>/Constant4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S26>/Gain3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S26>/Constant1'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S26>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S26>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S26>/Gain2'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S26>/Constant3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S26>/Gain4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S27>/Constant2'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S27>/Constant'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S27>/Gain'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S29>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S30>/Constant2'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S30>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S33>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S35>/Constant'
                                        */
  0.0033528106647474805,               /* Expression: F
                                        * Referenced by: '<S34>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S34>/f'
                                        */
  44.2018928,                          /* Expression: LL0(1)
                                        * Referenced by: '<S25>/initial_latg'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S32>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S30>/Constant'
                                        */
  0.0,                                 /* Expression: psi
                                        * Referenced by: '<S28>/ref_pos'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S31>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S30>/Constant3'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S3>/Switch'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S47>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S1>/Gain'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S10>/Constant'
                                        */

  /*  Expression: LL0
   * Referenced by: '<S36>/initial_pos'
   */
  { 44.2018928, 12.0625658 },
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S37>/Constant5'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S37>/Constant4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S37>/Gain3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S37>/Constant1'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S37>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S37>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S37>/Gain2'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S37>/Constant3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S37>/Gain4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S38>/Constant2'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S38>/Constant'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S38>/Gain'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S40>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S41>/Constant2'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S41>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S44>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S46>/Constant'
                                        */
  0.0033528106647474805,               /* Expression: F
                                        * Referenced by: '<S45>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S45>/f'
                                        */
  44.2018928,                          /* Expression: LL0(1)
                                        * Referenced by: '<S36>/initial_latg'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S43>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S41>/Constant'
                                        */
  0.0,                                 /* Expression: psi
                                        * Referenced by: '<S39>/ref_pos'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S42>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S41>/Constant3'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S4>/Switch'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S9>/Constant'
                                        */
  0.0F,                                /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S6>/Constant'
                                        */
  0.0F                                 /* Computed Parameter: Constant_Value_kw
                                        * Referenced by: '<S7>/Constant'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
