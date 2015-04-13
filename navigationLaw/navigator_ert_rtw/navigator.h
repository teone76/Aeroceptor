/*
 * File: navigator.h
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

#ifndef RTW_HEADER_navigator_h_
#define RTW_HEADER_navigator_h_
#ifndef navigator_COMMON_INCLUDES_
# define navigator_COMMON_INCLUDES_
#include <math.h>
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
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
  real32_T In[15];                     /* '<Root>/In' */
} ExtU_navigator_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real32_T Out[6];                     /* '<Root>/Out' */
} ExtY_navigator_T;

/* Parameters (auto storage) */
struct P_navigator_T_ {
  real_T Constant1_Value[3];           /* Expression: [0 0 0]
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: k_sat
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T initial_pos_Value[2];         /* Expression: LL0
                                        * Referenced by: '<S3>/initial_pos'
                                        */
  real_T initial_pos_Value_l[2];       /* Expression: LL0
                                        * Referenced by: '<S18>/initial_pos'
                                        */
  real_T Constant5_Value;              /* Expression: 360
                                        * Referenced by: '<S19>/Constant5'
                                        */
  real_T Constant4_Value;              /* Expression: 180
                                        * Referenced by: '<S19>/Constant4'
                                        */
  real_T Gain3_Gain;                   /* Expression: 360
                                        * Referenced by: '<S19>/Gain3'
                                        */
  real_T Constant1_Value_h;            /* Expression: 180
                                        * Referenced by: '<S19>/Constant1'
                                        */
  real_T Gain_Gain;                    /* Expression: 180
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S19>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 2
                                        * Referenced by: '<S19>/Gain2'
                                        */
  real_T Constant3_Value;              /* Expression: 90
                                        * Referenced by: '<S19>/Constant3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 180
                                        * Referenced by: '<S19>/Gain4'
                                        */
  real_T Constant2_Value;              /* Expression: 360
                                        * Referenced by: '<S20>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: 180
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 360
                                        * Referenced by: '<S20>/Gain'
                                        */
  real_T UnitConversion_Gain;          /* Expression: slope
                                        * Referenced by: '<S22>/Unit Conversion'
                                        */
  real_T Constant2_Value_o;            /* Expression: 1
                                        * Referenced by: '<S23>/Constant2'
                                        */
  real_T Constant1_Value_b;            /* Expression: R
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S26>/Constant'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S28>/Constant'
                                        */
  real_T Constant_Value_om;            /* Expression: F
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T f_Value;                      /* Expression: 1
                                        * Referenced by: '<S27>/f'
                                        */
  real_T initial_latg_Value;           /* Expression: LL0(1)
                                        * Referenced by: '<S18>/initial_latg'
                                        */
  real_T UnitConversion_Gain_o;        /* Expression: slope
                                        * Referenced by: '<S25>/Unit Conversion'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T ref_pos_Value;                /* Expression: psi
                                        * Referenced by: '<S21>/ref_pos'
                                        */
  real_T UnitConversion_Gain_b;        /* Expression: slope
                                        * Referenced by: '<S24>/Unit Conversion'
                                        */
  real_T Constant3_Value_j;            /* Expression: 1
                                        * Referenced by: '<S23>/Constant3'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: pi/180
                                        * Referenced by: '<S40>/Gain1'
                                        */
  real_T dt_Value;                     /* Expression: 0.5
                                        * Referenced by: '<S6>/dt'
                                        */
  real_T ref_pos_Value_n;              /* Expression: psi
                                        * Referenced by: '<S9>/ref_pos'
                                        */
  real_T UnitConversion_Gain_f;        /* Expression: slope
                                        * Referenced by: '<S13>/Unit Conversion'
                                        */
  real_T dt1_Value;                    /* Expression: 0.5
                                        * Referenced by: '<S6>/dt1'
                                        */
  real_T Constant2_Value_f;            /* Expression: 1
                                        * Referenced by: '<S12>/Constant2'
                                        */
  real_T Constant1_Value_f;            /* Expression: R
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Constant_Value_kd;            /* Expression: 1
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: F
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T f_Value_b;                    /* Expression: 1
                                        * Referenced by: '<S16>/f'
                                        */
  real_T initial_latg_Value_n;         /* Expression: LL0(1)
                                        * Referenced by: '<S3>/initial_latg'
                                        */
  real_T UnitConversion_Gain_h;        /* Expression: slope
                                        * Referenced by: '<S14>/Unit Conversion'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T Constant3_Value_jt;           /* Expression: 1
                                        * Referenced by: '<S12>/Constant3'
                                        */
  real_T UnitConversion_Gain_g;        /* Expression: slope
                                        * Referenced by: '<S11>/Unit Conversion'
                                        */
  real_T Constant5_Value_e;            /* Expression: 360
                                        * Referenced by: '<S8>/Constant5'
                                        */
  real_T Constant4_Value_g;            /* Expression: 180
                                        * Referenced by: '<S8>/Constant4'
                                        */
  real_T Gain3_Gain_l;                 /* Expression: 360
                                        * Referenced by: '<S8>/Gain3'
                                        */
  real_T Constant1_Value_g;            /* Expression: 180
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 180
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: 2
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Gain2_Gain_p;                 /* Expression: 2
                                        * Referenced by: '<S8>/Gain2'
                                        */
  real_T Constant3_Value_h;            /* Expression: 90
                                        * Referenced by: '<S8>/Constant3'
                                        */
  real_T Gain4_Gain_j;                 /* Expression: 180
                                        * Referenced by: '<S8>/Gain4'
                                        */
  real_T Constant2_Value_e;            /* Expression: 360
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T Constant_Value_d;             /* Expression: 180
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 360
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T initial_pos_Value_h[2];       /* Expression: LL0
                                        * Referenced by: '<S29>/initial_pos'
                                        */
  real_T Constant5_Value_b;            /* Expression: 360
                                        * Referenced by: '<S30>/Constant5'
                                        */
  real_T Constant4_Value_g4;           /* Expression: 180
                                        * Referenced by: '<S30>/Constant4'
                                        */
  real_T Gain3_Gain_o;                 /* Expression: 360
                                        * Referenced by: '<S30>/Gain3'
                                        */
  real_T Constant1_Value_d;            /* Expression: 180
                                        * Referenced by: '<S30>/Constant1'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 180
                                        * Referenced by: '<S30>/Gain'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: 2
                                        * Referenced by: '<S30>/Gain1'
                                        */
  real_T Gain2_Gain_k;                 /* Expression: 2
                                        * Referenced by: '<S30>/Gain2'
                                        */
  real_T Constant3_Value_c;            /* Expression: 90
                                        * Referenced by: '<S30>/Constant3'
                                        */
  real_T Gain4_Gain_i;                 /* Expression: 180
                                        * Referenced by: '<S30>/Gain4'
                                        */
  real_T Constant2_Value_h;            /* Expression: 360
                                        * Referenced by: '<S31>/Constant2'
                                        */
  real_T Constant_Value_kc;            /* Expression: 180
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T Gain_Gain_kt;                 /* Expression: 360
                                        * Referenced by: '<S31>/Gain'
                                        */
  real_T UnitConversion_Gain_gs;       /* Expression: slope
                                        * Referenced by: '<S33>/Unit Conversion'
                                        */
  real_T Constant2_Value_n;            /* Expression: 1
                                        * Referenced by: '<S34>/Constant2'
                                        */
  real_T Constant1_Value_o;            /* Expression: R
                                        * Referenced by: '<S34>/Constant1'
                                        */
  real_T Constant_Value_ks;            /* Expression: 1
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T Constant_Value_m;             /* Expression: 1
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: F
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T f_Value_j;                    /* Expression: 1
                                        * Referenced by: '<S38>/f'
                                        */
  real_T initial_latg_Value_i;         /* Expression: LL0(1)
                                        * Referenced by: '<S29>/initial_latg'
                                        */
  real_T UnitConversion_Gain_i;        /* Expression: slope
                                        * Referenced by: '<S36>/Unit Conversion'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S34>/Constant'
                                        */
  real_T ref_pos_Value_c;              /* Expression: psi
                                        * Referenced by: '<S32>/ref_pos'
                                        */
  real_T UnitConversion_Gain_c;        /* Expression: slope
                                        * Referenced by: '<S35>/Unit Conversion'
                                        */
  real_T Constant3_Value_o;            /* Expression: 1
                                        * Referenced by: '<S34>/Constant3'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S2>/Switch'
                                        */
  real32_T Constant_Value_f1;          /* Computed Parameter: Constant_Value_f1
                                        * Referenced by: '<S4>/Constant'
                                        */
  real32_T Constant_Value_kn;          /* Computed Parameter: Constant_Value_kn
                                        * Referenced by: '<S5>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_navigator_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern P_navigator_T navigator_P;

#ifdef __cplusplus

}
#endif

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
 * '<S2>'   : 'navigator/navigation_law/CalcVelocitySetpoint'
 * '<S3>'   : 'navigator/navigation_law/Flat Earth to LLA'
 * '<S4>'   : 'navigator/navigation_law/LLA_TO_earthFlat'
 * '<S5>'   : 'navigator/navigation_law/LLA_TO_earthFlat1'
 * '<S6>'   : 'navigator/navigation_law/Predictor'
 * '<S7>'   : 'navigator/navigation_law/CalcVelocitySetpoint/sat  '
 * '<S8>'   : 'navigator/navigation_law/Flat Earth to LLA/Latitude  Between  +//- 90'
 * '<S9>'   : 'navigator/navigation_law/Flat Earth to LLA/LongLat_offset'
 * '<S10>'  : 'navigator/navigation_law/Flat Earth to LLA/Longitude Between +//-180'
 * '<S11>'  : 'navigator/navigation_law/Flat Earth to LLA/pos_deg'
 * '<S12>'  : 'navigator/navigation_law/Flat Earth to LLA/LongLat_offset/Find Radian//Distance'
 * '<S13>'  : 'navigator/navigation_law/Flat Earth to LLA/LongLat_offset/pos_deg'
 * '<S14>'  : 'navigator/navigation_law/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Angle Conversion2'
 * '<S15>'  : 'navigator/navigation_law/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom'
 * '<S16>'  : 'navigator/navigation_law/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e'
 * '<S17>'  : 'navigator/navigation_law/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4'
 * '<S18>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth'
 * '<S19>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Latitude  Between  +//- 90'
 * '<S20>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Longitude Between +//-180'
 * '<S21>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem'
 * '<S22>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/pos_rad'
 * '<S23>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance'
 * '<S24>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/pos_deg'
 * '<S25>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
 * '<S26>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
 * '<S27>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
 * '<S28>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
 * '<S29>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth'
 * '<S30>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Latitude  Between  +//- 90'
 * '<S31>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Longitude Between +//-180'
 * '<S32>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem'
 * '<S33>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/pos_rad'
 * '<S34>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance'
 * '<S35>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/pos_deg'
 * '<S36>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
 * '<S37>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
 * '<S38>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
 * '<S39>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
 * '<S40>'  : 'navigator/navigation_law/Predictor/Degrees to Radians'
 */
#endif                                 /* RTW_HEADER_navigator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
