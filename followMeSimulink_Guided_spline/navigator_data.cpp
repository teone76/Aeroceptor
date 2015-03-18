/*
 * File: navigator_data.cpp
 *
 * Code generated for Simulink model 'navigator'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Wed Mar 18 16:57:44 2015
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
  { 44.2018928, 12.0625658 },

  /*  Expression: LL0
   * Referenced by: '<S17>/initial_pos'
   */
  { 44.2018928, 12.0625658 },
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S18>/Constant5'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S18>/Constant4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S18>/Gain3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S18>/Constant1'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S18>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S18>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S18>/Gain2'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S18>/Constant3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S18>/Gain4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S19>/Constant2'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S19>/Constant'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S19>/Gain'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S21>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S22>/Constant2'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S22>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S25>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S27>/Constant'
                                        */
  0.0033528106647474805,               /* Expression: F
                                        * Referenced by: '<S26>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S26>/f'
                                        */
  44.2018928,                          /* Expression: LL0(1)
                                        * Referenced by: '<S17>/initial_latg'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S24>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S22>/Constant'
                                        */
  0.0,                                 /* Expression: psi
                                        * Referenced by: '<S20>/ref_pos'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S23>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S22>/Constant3'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S2>/Gain1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S1>/dt'
                                        */
  0.0,                                 /* Expression: psi
                                        * Referenced by: '<S8>/ref_pos'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S12>/Unit Conversion'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S1>/dt1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S11>/Constant2'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S11>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S14>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S16>/Constant'
                                        */
  0.0033528106647474805,               /* Expression: F
                                        * Referenced by: '<S15>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/f'
                                        */
  44.2018928,                          /* Expression: LL0(1)
                                        * Referenced by: '<S3>/initial_latg'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S13>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S11>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S11>/Constant3'
                                        */
  57.295779513082323,                  /* Expression: slope
                                        * Referenced by: '<S10>/Unit Conversion'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S7>/Constant5'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S7>/Constant4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S7>/Gain3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S7>/Constant1'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S7>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S7>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S7>/Gain2'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S7>/Constant3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S7>/Gain4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S9>/Constant2'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S9>/Constant'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S9>/Gain'
                                        */

  /*  Expression: LL0
   * Referenced by: '<S28>/initial_pos'
   */
  { 44.2018928, 12.0625658 },
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S29>/Constant5'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S29>/Constant4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S29>/Gain3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S29>/Constant1'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S29>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S29>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S29>/Gain2'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S29>/Constant3'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S29>/Gain4'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S30>/Constant2'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S30>/Constant'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<S30>/Gain'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S32>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S33>/Constant2'
                                        */
  6.378137E+6,                         /* Expression: R
                                        * Referenced by: '<S33>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S36>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S38>/Constant'
                                        */
  0.0033528106647474805,               /* Expression: F
                                        * Referenced by: '<S37>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S37>/f'
                                        */
  44.2018928,                          /* Expression: LL0(1)
                                        * Referenced by: '<S28>/initial_latg'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S35>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S33>/Constant'
                                        */
  0.0,                                 /* Expression: psi
                                        * Referenced by: '<S31>/ref_pos'
                                        */
  0.017453292519943295,                /* Expression: slope
                                        * Referenced by: '<S34>/Unit Conversion'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S33>/Constant3'
                                        */
  1.0,                                 /* Expression: k_sat
                                        * Referenced by: '<S6>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Saturation'
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
