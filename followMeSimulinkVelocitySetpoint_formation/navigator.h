/*
 * File: navigator.h
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
  real32_T In[16];                     /* '<Root>/In' */
} ExtU_navigator_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real32_T Out[8];                     /* '<Root>/Out' */
} ExtY_navigator_T;

/* Parameters (auto storage) */
struct P_navigator_T_ {
  real_T Constant1_Value[3];           /* Expression: [0 0 0]
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: k_sat
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Constant1_Value_g[3];         /* Expression: [0 0 0]
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 0.5
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Saturation_UpperSat_n;        /* Expression: k_sat
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: 0
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T vect_Value[3];                /* Expression: [0 0 0]
                                        * Referenced by: '<S9>/vect'
                                        */
  real_T Gain2_Gain;                   /* Expression: 0.8
                                        * Referenced by: '<S8>/Gain2'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: k_sat
                                        * Referenced by: '<S49>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: 0
                                        * Referenced by: '<S49>/Saturation'
                                        */
  real_T Vz2_Value;                    /* Expression: 0
                                        * Referenced by: '<S9>/Vz2'
                                        */
  real_T vect_Value_a[3];              /* Expression: [0 0 0]
                                        * Referenced by: '<S10>/vect'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 0.8
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Saturation_UpperSat_m;        /* Expression: k_sat
                                        * Referenced by: '<S48>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: 0
                                        * Referenced by: '<S48>/Saturation'
                                        */
  real_T Vz1_Value;                    /* Expression: 0
                                        * Referenced by: '<S10>/Vz1'
                                        */
  real_T initial_pos_Value[2];         /* Expression: LL0
                                        * Referenced by: '<S14>/initial_pos'
                                        */
  real_T Constant5_Value;              /* Expression: 360
                                        * Referenced by: '<S15>/Constant5'
                                        */
  real_T Constant4_Value;              /* Expression: 180
                                        * Referenced by: '<S15>/Constant4'
                                        */
  real_T Gain3_Gain;                   /* Expression: 360
                                        * Referenced by: '<S15>/Gain3'
                                        */
  real_T Constant1_Value_n;            /* Expression: 180
                                        * Referenced by: '<S15>/Constant1'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 180
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 2
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real_T Gain2_Gain_m;                 /* Expression: 2
                                        * Referenced by: '<S15>/Gain2'
                                        */
  real_T Constant3_Value;              /* Expression: 90
                                        * Referenced by: '<S15>/Constant3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 180
                                        * Referenced by: '<S15>/Gain4'
                                        */
  real_T Constant2_Value;              /* Expression: 360
                                        * Referenced by: '<S16>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: 180
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 360
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T UnitConversion_Gain;          /* Expression: slope
                                        * Referenced by: '<S18>/Unit Conversion'
                                        */
  real_T Constant2_Value_h;            /* Expression: 1
                                        * Referenced by: '<S19>/Constant2'
                                        */
  real_T Constant1_Value_j;            /* Expression: R
                                        * Referenced by: '<S19>/Constant1'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T Constant_Value_g;             /* Expression: F
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T f_Value;                      /* Expression: 1
                                        * Referenced by: '<S23>/f'
                                        */
  real_T initial_latg_Value;           /* Expression: LL0(1)
                                        * Referenced by: '<S14>/initial_latg'
                                        */
  real_T UnitConversion_Gain_d;        /* Expression: slope
                                        * Referenced by: '<S21>/Unit Conversion'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T ref_pos_Value;                /* Expression: psi
                                        * Referenced by: '<S17>/ref_pos'
                                        */
  real_T UnitConversion_Gain_m;        /* Expression: slope
                                        * Referenced by: '<S20>/Unit Conversion'
                                        */
  real_T Constant3_Value_k;            /* Expression: 1
                                        * Referenced by: '<S19>/Constant3'
                                        */
  real_T radius_Value;                 /* Expression: 7
                                        * Referenced by: '<S1>/radius'
                                        */
  real_T Gain1_Gain_ex;                /* Expression: pi/180
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T initial_pos_Value_j[2];       /* Expression: LL0
                                        * Referenced by: '<S25>/initial_pos'
                                        */
  real_T Constant5_Value_e;            /* Expression: 360
                                        * Referenced by: '<S26>/Constant5'
                                        */
  real_T Constant4_Value_m;            /* Expression: 180
                                        * Referenced by: '<S26>/Constant4'
                                        */
  real_T Gain3_Gain_i;                 /* Expression: 360
                                        * Referenced by: '<S26>/Gain3'
                                        */
  real_T Constant1_Value_a;            /* Expression: 180
                                        * Referenced by: '<S26>/Constant1'
                                        */
  real_T Gain_Gain_nz;                 /* Expression: 180
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: 2
                                        * Referenced by: '<S26>/Gain1'
                                        */
  real_T Gain2_Gain_p;                 /* Expression: 2
                                        * Referenced by: '<S26>/Gain2'
                                        */
  real_T Constant3_Value_e;            /* Expression: 90
                                        * Referenced by: '<S26>/Constant3'
                                        */
  real_T Gain4_Gain_k;                 /* Expression: 180
                                        * Referenced by: '<S26>/Gain4'
                                        */
  real_T Constant2_Value_i;            /* Expression: 360
                                        * Referenced by: '<S27>/Constant2'
                                        */
  real_T Constant_Value_j;             /* Expression: 180
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 360
                                        * Referenced by: '<S27>/Gain'
                                        */
  real_T UnitConversion_Gain_e;        /* Expression: slope
                                        * Referenced by: '<S29>/Unit Conversion'
                                        */
  real_T Constant2_Value_o;            /* Expression: 1
                                        * Referenced by: '<S30>/Constant2'
                                        */
  real_T Constant1_Value_p;            /* Expression: R
                                        * Referenced by: '<S30>/Constant1'
                                        */
  real_T Constant_Value_i4;            /* Expression: 1
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T Constant_Value_id;            /* Expression: 1
                                        * Referenced by: '<S35>/Constant'
                                        */
  real_T Constant_Value_hn;            /* Expression: F
                                        * Referenced by: '<S34>/Constant'
                                        */
  real_T f_Value_o;                    /* Expression: 1
                                        * Referenced by: '<S34>/f'
                                        */
  real_T initial_latg_Value_k;         /* Expression: LL0(1)
                                        * Referenced by: '<S25>/initial_latg'
                                        */
  real_T UnitConversion_Gain_h;        /* Expression: slope
                                        * Referenced by: '<S32>/Unit Conversion'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T ref_pos_Value_c;              /* Expression: psi
                                        * Referenced by: '<S28>/ref_pos'
                                        */
  real_T UnitConversion_Gain_ec;       /* Expression: slope
                                        * Referenced by: '<S31>/Unit Conversion'
                                        */
  real_T Constant3_Value_n;            /* Expression: 1
                                        * Referenced by: '<S30>/Constant3'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: pi/180
                                        * Referenced by: '<S47>/Gain1'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 2
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Constant_Value_a;             /* Expression: -5
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T initial_pos_Value_i[2];       /* Expression: LL0
                                        * Referenced by: '<S36>/initial_pos'
                                        */
  real_T Constant5_Value_p;            /* Expression: 360
                                        * Referenced by: '<S37>/Constant5'
                                        */
  real_T Constant4_Value_e;            /* Expression: 180
                                        * Referenced by: '<S37>/Constant4'
                                        */
  real_T Gain3_Gain_j;                 /* Expression: 360
                                        * Referenced by: '<S37>/Gain3'
                                        */
  real_T Constant1_Value_c;            /* Expression: 180
                                        * Referenced by: '<S37>/Constant1'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 180
                                        * Referenced by: '<S37>/Gain'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 2
                                        * Referenced by: '<S37>/Gain1'
                                        */
  real_T Gain2_Gain_mq;                /* Expression: 2
                                        * Referenced by: '<S37>/Gain2'
                                        */
  real_T Constant3_Value_g;            /* Expression: 90
                                        * Referenced by: '<S37>/Constant3'
                                        */
  real_T Gain4_Gain_p;                 /* Expression: 180
                                        * Referenced by: '<S37>/Gain4'
                                        */
  real_T Constant2_Value_d;            /* Expression: 360
                                        * Referenced by: '<S38>/Constant2'
                                        */
  real_T Constant_Value_o;             /* Expression: 180
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T Gain_Gain_jy;                 /* Expression: 360
                                        * Referenced by: '<S38>/Gain'
                                        */
  real_T UnitConversion_Gain_b;        /* Expression: slope
                                        * Referenced by: '<S40>/Unit Conversion'
                                        */
  real_T Constant2_Value_l;            /* Expression: 1
                                        * Referenced by: '<S41>/Constant2'
                                        */
  real_T Constant1_Value_i;            /* Expression: R
                                        * Referenced by: '<S41>/Constant1'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S44>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S46>/Constant'
                                        */
  real_T Constant_Value_ns;            /* Expression: F
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T f_Value_p;                    /* Expression: 1
                                        * Referenced by: '<S45>/f'
                                        */
  real_T initial_latg_Value_kz;        /* Expression: LL0(1)
                                        * Referenced by: '<S36>/initial_latg'
                                        */
  real_T UnitConversion_Gain_n;        /* Expression: slope
                                        * Referenced by: '<S43>/Unit Conversion'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S41>/Constant'
                                        */
  real_T ref_pos_Value_cn;             /* Expression: psi
                                        * Referenced by: '<S39>/ref_pos'
                                        */
  real_T UnitConversion_Gain_dd;       /* Expression: slope
                                        * Referenced by: '<S42>/Unit Conversion'
                                        */
  real_T Constant3_Value_p;            /* Expression: 1
                                        * Referenced by: '<S41>/Constant3'
                                        */
  real_T Switch_Threshold_b;           /* Expression: 0.5
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Constant_Value_e;             /* Expression: -5
                                        * Referenced by: '<S9>/Constant'
                                        */
  real32_T Constant_Value_l;           /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S6>/Constant'
                                        */
  real32_T Constant_Value_kw;          /* Computed Parameter: Constant_Value_kw
                                        * Referenced by: '<S7>/Constant'
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
 * '<S2>'   : 'navigator/navigation_law/CalcSetpoints'
 * '<S3>'   : 'navigator/navigation_law/CalcVelocitySetpoint'
 * '<S4>'   : 'navigator/navigation_law/CalcVelocitySetpoint1'
 * '<S5>'   : 'navigator/navigation_law/LLA_TO_earthFlat'
 * '<S6>'   : 'navigator/navigation_law/LLA_TO_earthFlat1'
 * '<S7>'   : 'navigator/navigation_law/LLA_TO_earthFlat2'
 * '<S8>'   : 'navigator/navigation_law/Subsystem'
 * '<S9>'   : 'navigator/navigation_law/Subsystem1'
 * '<S10>'  : 'navigator/navigation_law/Subsystem2'
 * '<S11>'  : 'navigator/navigation_law/CalcSetpoints/Degrees to Radians'
 * '<S12>'  : 'navigator/navigation_law/CalcVelocitySetpoint/sat  '
 * '<S13>'  : 'navigator/navigation_law/CalcVelocitySetpoint1/sat  '
 * '<S14>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth'
 * '<S15>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Latitude  Between  +//- 90'
 * '<S16>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Longitude Between +//-180'
 * '<S17>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem'
 * '<S18>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/pos_rad'
 * '<S19>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance'
 * '<S20>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/pos_deg'
 * '<S21>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
 * '<S22>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
 * '<S23>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
 * '<S24>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
 * '<S25>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth'
 * '<S26>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Latitude  Between  +//- 90'
 * '<S27>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Longitude Between +//-180'
 * '<S28>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem'
 * '<S29>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/pos_rad'
 * '<S30>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance'
 * '<S31>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/pos_deg'
 * '<S32>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
 * '<S33>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
 * '<S34>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
 * '<S35>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
 * '<S36>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth'
 * '<S37>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Latitude  Between  +//- 90'
 * '<S38>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Longitude Between +//-180'
 * '<S39>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem'
 * '<S40>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/pos_rad'
 * '<S41>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem/Find Radian//Distance'
 * '<S42>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem/pos_deg'
 * '<S43>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
 * '<S44>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
 * '<S45>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
 * '<S46>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
 * '<S47>'  : 'navigator/navigation_law/Subsystem/Degrees to Radians'
 * '<S48>'  : 'navigator/navigation_law/Subsystem/sat  '
 * '<S49>'  : 'navigator/navigation_law/Subsystem/sat  1'
 */
#endif                                 /* RTW_HEADER_navigator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
