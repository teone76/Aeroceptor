/*
 * File: navigator.h
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
  real32_T In[21];                     /* '<Root>/In' */
} ExtU_navigator_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real32_T Out[15];                    /* '<Root>/Out' */
} ExtY_navigator_T;

/* Parameters (auto storage) */
struct P_navigator_T_ {
  real_T Constant_Value[2];            /* Expression: [0 0]
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant_Value_a[2];          /* Expression: [0 0]
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.45
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Vz1_Value;                    /* Expression: 0
                                        * Referenced by: '<S1>/Vz1'
                                        */
  real_T initial_pos_Value[2];         /* Expression: LL0
                                        * Referenced by: '<S12>/initial_pos'
                                        */
  real_T Constant5_Value;              /* Expression: 360
                                        * Referenced by: '<S13>/Constant5'
                                        */
  real_T Constant4_Value;              /* Expression: 180
                                        * Referenced by: '<S13>/Constant4'
                                        */
  real_T Gain3_Gain;                   /* Expression: 360
                                        * Referenced by: '<S13>/Gain3'
                                        */
  real_T Constant1_Value;              /* Expression: 180
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 180
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S13>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 2
                                        * Referenced by: '<S13>/Gain2'
                                        */
  real_T Constant3_Value;              /* Expression: 90
                                        * Referenced by: '<S13>/Constant3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 180
                                        * Referenced by: '<S13>/Gain4'
                                        */
  real_T Constant2_Value;              /* Expression: 360
                                        * Referenced by: '<S14>/Constant2'
                                        */
  real_T Constant_Value_c;             /* Expression: 180
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 360
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T UnitConversion_Gain;          /* Expression: slope
                                        * Referenced by: '<S16>/Unit Conversion'
                                        */
  real_T Constant2_Value_o;            /* Expression: 1
                                        * Referenced by: '<S17>/Constant2'
                                        */
  real_T Constant1_Value_b;            /* Expression: R
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Constant_Value_om;            /* Expression: F
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T f_Value;                      /* Expression: 1
                                        * Referenced by: '<S21>/f'
                                        */
  real_T initial_latg_Value;           /* Expression: LL0(1)
                                        * Referenced by: '<S12>/initial_latg'
                                        */
  real_T UnitConversion_Gain_o;        /* Expression: slope
                                        * Referenced by: '<S19>/Unit Conversion'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T ref_pos_Value;                /* Expression: psi
                                        * Referenced by: '<S15>/ref_pos'
                                        */
  real_T UnitConversion_Gain_b;        /* Expression: slope
                                        * Referenced by: '<S18>/Unit Conversion'
                                        */
  real_T Constant3_Value_j;            /* Expression: 1
                                        * Referenced by: '<S17>/Constant3'
                                        */
  real_T initial_pos_Value_h[2];       /* Expression: LL0
                                        * Referenced by: '<S23>/initial_pos'
                                        */
  real_T Constant5_Value_b;            /* Expression: 360
                                        * Referenced by: '<S24>/Constant5'
                                        */
  real_T Constant4_Value_g;            /* Expression: 180
                                        * Referenced by: '<S24>/Constant4'
                                        */
  real_T Gain3_Gain_o;                 /* Expression: 360
                                        * Referenced by: '<S24>/Gain3'
                                        */
  real_T Constant1_Value_d;            /* Expression: 180
                                        * Referenced by: '<S24>/Constant1'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 180
                                        * Referenced by: '<S24>/Gain'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: 2
                                        * Referenced by: '<S24>/Gain1'
                                        */
  real_T Gain2_Gain_k;                 /* Expression: 2
                                        * Referenced by: '<S24>/Gain2'
                                        */
  real_T Constant3_Value_c;            /* Expression: 90
                                        * Referenced by: '<S24>/Constant3'
                                        */
  real_T Gain4_Gain_i;                 /* Expression: 180
                                        * Referenced by: '<S24>/Gain4'
                                        */
  real_T Constant2_Value_h;            /* Expression: 360
                                        * Referenced by: '<S25>/Constant2'
                                        */
  real_T Constant_Value_k;             /* Expression: 180
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T Gain_Gain_kt;                 /* Expression: 360
                                        * Referenced by: '<S25>/Gain'
                                        */
  real_T UnitConversion_Gain_g;        /* Expression: slope
                                        * Referenced by: '<S27>/Unit Conversion'
                                        */
  real_T Constant2_Value_n;            /* Expression: 1
                                        * Referenced by: '<S28>/Constant2'
                                        */
  real_T Constant1_Value_o;            /* Expression: R
                                        * Referenced by: '<S28>/Constant1'
                                        */
  real_T Constant_Value_ks;            /* Expression: 1
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T Constant_Value_m;             /* Expression: 1
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: F
                                        * Referenced by: '<S32>/Constant'
                                        */
  real_T f_Value_j;                    /* Expression: 1
                                        * Referenced by: '<S32>/f'
                                        */
  real_T initial_latg_Value_i;         /* Expression: LL0(1)
                                        * Referenced by: '<S23>/initial_latg'
                                        */
  real_T UnitConversion_Gain_i;        /* Expression: slope
                                        * Referenced by: '<S30>/Unit Conversion'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S28>/Constant'
                                        */
  real_T ref_pos_Value_c;              /* Expression: psi
                                        * Referenced by: '<S26>/ref_pos'
                                        */
  real_T UnitConversion_Gain_c;        /* Expression: slope
                                        * Referenced by: '<S29>/Unit Conversion'
                                        */
  real_T Constant3_Value_o;            /* Expression: 1
                                        * Referenced by: '<S28>/Constant3'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 0.5
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: k_sat
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T initial_pos_Value_j[2];       /* Expression: LL0
                                        * Referenced by: '<S45>/initial_pos'
                                        */
  real_T Constant5_Value_k;            /* Expression: 360
                                        * Referenced by: '<S46>/Constant5'
                                        */
  real_T Constant4_Value_d;            /* Expression: 180
                                        * Referenced by: '<S46>/Constant4'
                                        */
  real_T Gain3_Gain_c;                 /* Expression: 360
                                        * Referenced by: '<S46>/Gain3'
                                        */
  real_T Constant1_Value_j;            /* Expression: 180
                                        * Referenced by: '<S46>/Constant1'
                                        */
  real_T Gain_Gain_nn;                 /* Expression: 180
                                        * Referenced by: '<S46>/Gain'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: 2
                                        * Referenced by: '<S46>/Gain1'
                                        */
  real_T Gain2_Gain_p;                 /* Expression: 2
                                        * Referenced by: '<S46>/Gain2'
                                        */
  real_T Constant3_Value_e;            /* Expression: 90
                                        * Referenced by: '<S46>/Constant3'
                                        */
  real_T Gain4_Gain_id;                /* Expression: 180
                                        * Referenced by: '<S46>/Gain4'
                                        */
  real_T Constant2_Value_l;            /* Expression: 360
                                        * Referenced by: '<S47>/Constant2'
                                        */
  real_T Constant_Value_m5;            /* Expression: 180
                                        * Referenced by: '<S47>/Constant'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 360
                                        * Referenced by: '<S47>/Gain'
                                        */
  real_T UnitConversion_Gain_on;       /* Expression: slope
                                        * Referenced by: '<S49>/Unit Conversion'
                                        */
  real_T Constant2_Value_a;            /* Expression: 1
                                        * Referenced by: '<S50>/Constant2'
                                        */
  real_T Constant1_Value_k;            /* Expression: R
                                        * Referenced by: '<S50>/Constant1'
                                        */
  real_T Constant_Value_b3;            /* Expression: 1
                                        * Referenced by: '<S53>/Constant'
                                        */
  real_T Constant_Value_f5;            /* Expression: 1
                                        * Referenced by: '<S55>/Constant'
                                        */
  real_T Constant_Value_nm;            /* Expression: F
                                        * Referenced by: '<S54>/Constant'
                                        */
  real_T f_Value_a;                    /* Expression: 1
                                        * Referenced by: '<S54>/f'
                                        */
  real_T initial_latg_Value_h;         /* Expression: LL0(1)
                                        * Referenced by: '<S45>/initial_latg'
                                        */
  real_T UnitConversion_Gain_gr;       /* Expression: slope
                                        * Referenced by: '<S52>/Unit Conversion'
                                        */
  real_T Constant_Value_c4;            /* Expression: 1
                                        * Referenced by: '<S50>/Constant'
                                        */
  real_T ref_pos_Value_d;              /* Expression: psi
                                        * Referenced by: '<S48>/ref_pos'
                                        */
  real_T UnitConversion_Gain_a;        /* Expression: slope
                                        * Referenced by: '<S51>/Unit Conversion'
                                        */
  real_T Constant3_Value_p;            /* Expression: 1
                                        * Referenced by: '<S50>/Constant3'
                                        */
  real_T Gain1_Gain_os;                /* Expression: pi/180
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T Distance_Value;               /* Expression: 8
                                        * Referenced by: '<S1>/Distance'
                                        */
  real_T initial_pos_Value_g[2];       /* Expression: LL0
                                        * Referenced by: '<S34>/initial_pos'
                                        */
  real_T Constant5_Value_c;            /* Expression: 360
                                        * Referenced by: '<S35>/Constant5'
                                        */
  real_T Constant4_Value_a;            /* Expression: 180
                                        * Referenced by: '<S35>/Constant4'
                                        */
  real_T Gain3_Gain_g;                 /* Expression: 360
                                        * Referenced by: '<S35>/Gain3'
                                        */
  real_T Constant1_Value_f;            /* Expression: 180
                                        * Referenced by: '<S35>/Constant1'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 180
                                        * Referenced by: '<S35>/Gain'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: 2
                                        * Referenced by: '<S35>/Gain1'
                                        */
  real_T Gain2_Gain_b;                 /* Expression: 2
                                        * Referenced by: '<S35>/Gain2'
                                        */
  real_T Constant3_Value_f;            /* Expression: 90
                                        * Referenced by: '<S35>/Constant3'
                                        */
  real_T Gain4_Gain_c;                 /* Expression: 180
                                        * Referenced by: '<S35>/Gain4'
                                        */
  real_T Constant2_Value_b;            /* Expression: 360
                                        * Referenced by: '<S36>/Constant2'
                                        */
  real_T Constant_Value_bl;            /* Expression: 180
                                        * Referenced by: '<S36>/Constant'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 360
                                        * Referenced by: '<S36>/Gain'
                                        */
  real_T UnitConversion_Gain_bh;       /* Expression: slope
                                        * Referenced by: '<S38>/Unit Conversion'
                                        */
  real_T Constant2_Value_hi;           /* Expression: 1
                                        * Referenced by: '<S39>/Constant2'
                                        */
  real_T Constant1_Value_g;            /* Expression: R
                                        * Referenced by: '<S39>/Constant1'
                                        */
  real_T Constant_Value_a2;            /* Expression: 1
                                        * Referenced by: '<S42>/Constant'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S44>/Constant'
                                        */
  real_T Constant_Value_l;             /* Expression: F
                                        * Referenced by: '<S43>/Constant'
                                        */
  real_T f_Value_e;                    /* Expression: 1
                                        * Referenced by: '<S43>/f'
                                        */
  real_T initial_latg_Value_ii;        /* Expression: LL0(1)
                                        * Referenced by: '<S34>/initial_latg'
                                        */
  real_T UnitConversion_Gain_bj;       /* Expression: slope
                                        * Referenced by: '<S41>/Unit Conversion'
                                        */
  real_T Constant_Value_kl;            /* Expression: 1
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T ref_pos_Value_n;              /* Expression: psi
                                        * Referenced by: '<S37>/ref_pos'
                                        */
  real_T UnitConversion_Gain_a3;       /* Expression: slope
                                        * Referenced by: '<S40>/Unit Conversion'
                                        */
  real_T Constant3_Value_k;            /* Expression: 1
                                        * Referenced by: '<S39>/Constant3'
                                        */
  real_T Gain_Gain_gl;                 /* Expression: 0.3
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: k_sat
                                        * Referenced by: '<S11>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: 0
                                        * Referenced by: '<S11>/Saturation'
                                        */
  real32_T Constant_Value_f1;          /* Computed Parameter: Constant_Value_f1
                                        * Referenced by: '<S5>/Constant'
                                        */
  real32_T Constant_Value_kn;          /* Computed Parameter: Constant_Value_kn
                                        * Referenced by: '<S6>/Constant'
                                        */
  real32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
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
 * '<S8>'   : 'navigator/navigation_law/LLA_TO_earthFlat3'
 * '<S9>'   : 'navigator/navigation_law/CalcSetpoints/Degrees to Radians'
 * '<S10>'  : 'navigator/navigation_law/CalcVelocitySetpoint/sat  '
 * '<S11>'  : 'navigator/navigation_law/CalcVelocitySetpoint1/sat  '
 * '<S12>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth'
 * '<S13>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Latitude  Between  +//- 90'
 * '<S14>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Longitude Between +//-180'
 * '<S15>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem'
 * '<S16>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/pos_rad'
 * '<S17>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance'
 * '<S18>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/pos_deg'
 * '<S19>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
 * '<S20>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
 * '<S21>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
 * '<S22>'  : 'navigator/navigation_law/LLA_TO_earthFlat/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
 * '<S23>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth'
 * '<S24>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Latitude  Between  +//- 90'
 * '<S25>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Longitude Between +//-180'
 * '<S26>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem'
 * '<S27>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/pos_rad'
 * '<S28>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance'
 * '<S29>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/pos_deg'
 * '<S30>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
 * '<S31>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
 * '<S32>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
 * '<S33>'  : 'navigator/navigation_law/LLA_TO_earthFlat1/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
 * '<S34>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth'
 * '<S35>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Latitude  Between  +//- 90'
 * '<S36>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Longitude Between +//-180'
 * '<S37>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem'
 * '<S38>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/pos_rad'
 * '<S39>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem/Find Radian//Distance'
 * '<S40>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem/pos_deg'
 * '<S41>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
 * '<S42>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
 * '<S43>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
 * '<S44>'  : 'navigator/navigation_law/LLA_TO_earthFlat2/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
 * '<S45>'  : 'navigator/navigation_law/LLA_TO_earthFlat3/LLA to Flat Earth'
 * '<S46>'  : 'navigator/navigation_law/LLA_TO_earthFlat3/LLA to Flat Earth/Latitude  Between  +//- 90'
 * '<S47>'  : 'navigator/navigation_law/LLA_TO_earthFlat3/LLA to Flat Earth/Longitude Between +//-180'
 * '<S48>'  : 'navigator/navigation_law/LLA_TO_earthFlat3/LLA to Flat Earth/Subsystem'
 * '<S49>'  : 'navigator/navigation_law/LLA_TO_earthFlat3/LLA to Flat Earth/pos_rad'
 * '<S50>'  : 'navigator/navigation_law/LLA_TO_earthFlat3/LLA to Flat Earth/Subsystem/Find Radian//Distance'
 * '<S51>'  : 'navigator/navigation_law/LLA_TO_earthFlat3/LLA to Flat Earth/Subsystem/pos_deg'
 * '<S52>'  : 'navigator/navigation_law/LLA_TO_earthFlat3/LLA to Flat Earth/Subsystem/Find Radian//Distance/Angle Conversion2'
 * '<S53>'  : 'navigator/navigation_law/LLA_TO_earthFlat3/LLA to Flat Earth/Subsystem/Find Radian//Distance/denom'
 * '<S54>'  : 'navigator/navigation_law/LLA_TO_earthFlat3/LLA to Flat Earth/Subsystem/Find Radian//Distance/e'
 * '<S55>'  : 'navigator/navigation_law/LLA_TO_earthFlat3/LLA to Flat Earth/Subsystem/Find Radian//Distance/e^4'
 */
#endif                                 /* RTW_HEADER_navigator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
