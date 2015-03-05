/*
 * File: navigator.h
 *
 * Code generated for Simulink model 'navigator'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Thu Mar 05 10:30:34 2015
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
  real_T initial_pos_Value[2];         /* Expression: LL0
                                        * Referenced by: '<S3>/initial_pos'
                                        */
  real_T initial_pos_Value_l[2];       /* Expression: LL0
                                        * Referenced by: '<S15>/initial_pos'
                                        */
  real_T Constant5_Value;              /* Expression: 360
                                        * Referenced by: '<S16>/Constant5'
                                        */
  real_T Constant4_Value;              /* Expression: 180
                                        * Referenced by: '<S16>/Constant4'
                                        */
  real_T Gain3_Gain;                   /* Expression: 360
                                        * Referenced by: '<S16>/Gain3'
                                        */
  real_T Constant1_Value;              /* Expression: 180
                                        * Referenced by: '<S16>/Constant1'
                                        */
  real_T Gain_Gain;                    /* Expression: 180
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S16>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 2
                                        * Referenced by: '<S16>/Gain2'
                                        */
  real_T Constant3_Value;              /* Expression: 90
                                        * Referenced by: '<S16>/Constant3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 180
                                        * Referenced by: '<S16>/Gain4'
                                        */
  real_T Constant2_Value;              /* Expression: 360
                                        * Referenced by: '<S17>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: 180
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 360
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T UnitConversion_Gain;          /* Expression: slope
                                        * Referenced by: '<S19>/Unit Conversion'
                                        */
  real_T Constant2_Value_o;            /* Expression: 1
                                        * Referenced by: '<S20>/Constant2'
                                        */
  real_T Constant1_Value_b;            /* Expression: R
                                        * Referenced by: '<S20>/Constant1'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T Constant_Value_om;            /* Expression: F
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T f_Value;                      /* Expression: 1
                                        * Referenced by: '<S24>/f'
                                        */
  real_T initial_latg_Value;           /* Expression: LL0(1)
                                        * Referenced by: '<S15>/initial_latg'
                                        */
  real_T UnitConversion_Gain_o;        /* Expression: slope
                                        * Referenced by: '<S22>/Unit Conversion'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T ref_pos_Value;                /* Expression: psi
                                        * Referenced by: '<S18>/ref_pos'
                                        */
  real_T UnitConversion_Gain_b;        /* Expression: slope
                                        * Referenced by: '<S21>/Unit Conversion'
                                        */
  real_T Constant3_Value_j;            /* Expression: 1
                                        * Referenced by: '<S20>/Constant3'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: pi/180
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T dt_Value;                     /* Expression: 0.5
                                        * Referenced by: '<S1>/dt'
                                        */
  real_T ref_pos_Value_n;              /* Expression: psi
                                        * Referenced by: '<S6>/ref_pos'
                                        */
  real_T UnitConversion_Gain_f;        /* Expression: slope
                                        * Referenced by: '<S10>/Unit Conversion'
                                        */
  real_T dt1_Value;                    /* Expression: 0.5
                                        * Referenced by: '<S1>/dt1'
                                        */
  real_T Constant2_Value_f;            /* Expression: 1
                                        * Referenced by: '<S9>/Constant2'
                                        */
  real_T Constant1_Value_f;            /* Expression: R
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T Constant_Value_kd;            /* Expression: 1
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: F
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T f_Value_b;                    /* Expression: 1
                                        * Referenced by: '<S13>/f'
                                        */
  real_T initial_latg_Value_n;         /* Expression: LL0(1)
                                        * Referenced by: '<S3>/initial_latg'
                                        */
  real_T UnitConversion_Gain_h;        /* Expression: slope
                                        * Referenced by: '<S11>/Unit Conversion'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant3_Value_jt;           /* Expression: 1
                                        * Referenced by: '<S9>/Constant3'
                                        */
  real_T UnitConversion_Gain_g;        /* Expression: slope
                                        * Referenced by: '<S8>/Unit Conversion'
                                        */
  real_T Constant5_Value_e;            /* Expression: 360
                                        * Referenced by: '<S5>/Constant5'
                                        */
  real_T Constant4_Value_g;            /* Expression: 180
                                        * Referenced by: '<S5>/Constant4'
                                        */
  real_T Gain3_Gain_l;                 /* Expression: 360
                                        * Referenced by: '<S5>/Gain3'
                                        */
  real_T Constant1_Value_g;            /* Expression: 180
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 180
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: 2
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Gain2_Gain_p;                 /* Expression: 2
                                        * Referenced by: '<S5>/Gain2'
                                        */
  real_T Constant3_Value_h;            /* Expression: 90
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T Gain4_Gain_j;                 /* Expression: 180
                                        * Referenced by: '<S5>/Gain4'
                                        */
  real_T Constant2_Value_e;            /* Expression: 360
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T Constant_Value_d;             /* Expression: 180
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 360
                                        * Referenced by: '<S7>/Gain'
                                        */
  real32_T Constant_Value_ci;          /* Computed Parameter: Constant_Value_ci
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T Constant_Value_f;           /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S4>/Constant'
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
 * '<S2>'   : 'navigator/navigation_law/Degrees to Radians'
 * '<S3>'   : 'navigator/navigation_law/Flat Earth to LLA'
 * '<S4>'   : 'navigator/navigation_law/LLA_TO_earthFlat'
 * '<S5>'   : 'navigator/navigation_law/Flat Earth to LLA/Latitude  Between  +//- 90'
 * '<S6>'   : 'navigator/navigation_law/Flat Earth to LLA/LongLat_offset'
 * '<S7>'   : 'navigator/navigation_law/Flat Earth to LLA/Longitude Between +//-180'
 * '<S8>'   : 'navigator/navigation_law/Flat Earth to LLA/pos_deg'
 * '<S9>'   : 'navigator/navigation_law/Flat Earth to LLA/LongLat_offset/Find Radian//Distance'
 * '<S10>'  : 'navigator/navigation_law/Flat Earth to LLA/LongLat_offset/pos_deg'
 * '<S11>'  : 'navigator/navigation_law/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Angle Conversion2'
 * '<S12>'  : 'navigator/navigation_law/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom'
 * '<S13>'  : 'navigator/navigation_law/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e'
 * '<S14>'  : 'navigator/navigation_law/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4'
 * '<S15>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth'
 * '<S16>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Latitude  Between  +//- 90'
 * '<S17>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Longitude Between +//-180'
 * '<S18>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem'
 * '<S19>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/pos_rad'
 * '<S20>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance'
 * '<S21>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/pos_deg'
 * '<S22>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
 * '<S23>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
 * '<S24>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
 * '<S25>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
 */
#endif                                 /* RTW_HEADER_navigator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
