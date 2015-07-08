/*
 * File: navigator_data.cpp
 *
 * Code generated for Simulink model 'navigator'.
 *
 * Model version                  : 1.60
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Fri Jun 12 10:02:39 2015
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
  /*  Expression: [0 0]
   * Referenced by: '<S10>/Constant'
   */
  { 0.0, 0.0 },

  /*  Expression: [0 0]
   * Referenced by: '<S11>/Constant'
   */
  { 0.0, 0.0 },
  0.45,                                /* Expression: 0.45
                                        * Referenced by: '<S1>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Vz1'
                                        */

  /*  Expression: LL0
   * Referenced by: '<S12>/initial_pos'
   */
  { 44.2018928, 12.0625658 },
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S13>/Constant5'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S13>/Constant4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S13>/Gain3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S13>/Constant1'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S13>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S13>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S13>/Gain2'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S13>/Constant3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S13>/Gain4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S14>/Constant2'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S14>/Constant'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S14>/Gain'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S16>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S17>/Constant2'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S17>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S20>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S22>/Constant'
                                        */
  0.0033528106647474805,               /* Expression: F
                                        * Referenced by: '<S21>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S21>/f'
                                        */
  44.2018928,                          /* Expression: LL0(1)
                                        * Referenced by: '<S12>/initial_latg'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S19>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S17>/Constant'
                                        */
  0.0,                                 /* Expression: psi
                                        * Referenced by: '<S15>/ref_pos'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S18>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S17>/Constant3'
                                        */

  /*  Expression: LL0
   * Referenced by: '<S23>/initial_pos'
   */
  { 44.2018928, 12.0625658 },
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S24>/Constant5'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S24>/Constant4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S24>/Gain3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S24>/Constant1'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S24>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S24>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S24>/Gain2'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S24>/Constant3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S24>/Gain4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S25>/Constant2'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S25>/Constant'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S25>/Gain'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S27>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S28>/Constant2'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S28>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S31>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S33>/Constant'
                                        */
  0.0033528106647474805,               /* Expression: F
                                        * Referenced by: '<S32>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S32>/f'
                                        */
  44.2018928,                          /* Expression: LL0(1)
                                        * Referenced by: '<S23>/initial_latg'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S30>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S28>/Constant'
                                        */
  0.0,                                 /* Expression: psi
                                        * Referenced by: '<S26>/ref_pos'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S29>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S28>/Constant3'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S3>/Gain'
                                        */
  2.0,                                 /* Expression: k_sat
                                        * Referenced by: '<S10>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Saturation'
                                        */

  /*  Expression: LL0
   * Referenced by: '<S45>/initial_pos'
   */
  { 44.2018928, 12.0625658 },
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S46>/Constant5'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S46>/Constant4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S46>/Gain3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S46>/Constant1'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S46>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S46>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S46>/Gain2'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S46>/Constant3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S46>/Gain4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S47>/Constant2'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S47>/Constant'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S47>/Gain'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S49>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S50>/Constant2'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S50>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S53>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S55>/Constant'
                                        */
  0.0033528106647474805,               /* Expression: F
                                        * Referenced by: '<S54>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S54>/f'
                                        */
  44.2018928,                          /* Expression: LL0(1)
                                        * Referenced by: '<S45>/initial_latg'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S52>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S50>/Constant'
                                        */
  0.0,                                 /* Expression: psi
                                        * Referenced by: '<S48>/ref_pos'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S51>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S50>/Constant3'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S9>/Gain1'
                                        */
  8.0,                                 /* Expression: 8
                                        * Referenced by: '<S1>/Distance'
                                        */

  /*  Expression: LL0
   * Referenced by: '<S34>/initial_pos'
   */
  { 44.2018928, 12.0625658 },
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S35>/Constant5'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S35>/Constant4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S35>/Gain3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S35>/Constant1'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S35>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S35>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S35>/Gain2'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S35>/Constant3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S35>/Gain4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S36>/Constant2'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S36>/Constant'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S36>/Gain'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S38>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S39>/Constant2'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S39>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S42>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S44>/Constant'
                                        */
  0.0033528106647474805,               /* Expression: F
                                        * Referenced by: '<S43>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S43>/f'
                                        */
  44.2018928,                          /* Expression: LL0(1)
                                        * Referenced by: '<S34>/initial_latg'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S41>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S39>/Constant'
                                        */
  0.0,                                 /* Expression: psi
                                        * Referenced by: '<S37>/ref_pos'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S40>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S39>/Constant3'
                                        */
  0.3,                                 /* Expression: 0.3
                                        * Referenced by: '<S4>/Gain'
                                        */
  3.0,                                 /* Expression: k_sat
                                        * Referenced by: '<S11>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Saturation'
                                        */
  0.0F,                                /* Computed Parameter: Constant_Value_f1
                                        * Referenced by: '<S5>/Constant'
                                        */
  0.0F,                                /* Computed Parameter: Constant_Value_kn
                                        * Referenced by: '<S6>/Constant'
                                        */
  0.0F                                 /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S7>/Constant'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
