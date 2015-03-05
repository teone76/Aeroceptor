/*
 * File: navigator.cpp
 *
 * Code generated for Simulink model 'navigator'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Thu Mar 05 10:00:58 2015
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

/* External inputs (root inport signals with auto storage) */
ExtU_navigator_T navigator_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_navigator_T navigator_Y;

/* Real-time model */
RT_MODEL_navigator_T navigator_M_;
RT_MODEL_navigator_T *const navigator_M = &navigator_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u;
  if (u1 < 0.0) {
    u = ceil(u1);
  } else {
    u = floor(u1);
  }

  if ((u1 != 0.0) && (u1 != u) && ((!rtIsNaN(u0)) && (!rtIsInf(u0)) &&
       ((!rtIsNaN(u1)) && (!rtIsInf(u1))))) {
    u = u0 / u1;
    if (fabs(u - rt_roundd_snf(u)) <= DBL_EPSILON * fabs(u)) {
      y = 0.0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int16_T u;
  int16_T u_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u = 1;
    } else {
      u = -1;
    }

    if (u1 > 0.0) {
      u_0 = 1;
    } else {
      u_0 = -1;
    }

    y = atan2((real_T)u, (real_T)u_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void navigator_step(void)
{
  real_T rtb_DataTypeConversion1[15];
  real_T rtb_Rn;
  real_T rtb_Sum1_j;
  real_T rtb_UnitConversion_eg;
  real_T rtb_radlat;
  real_T rtb_Sum1_g;
  real_T rtb_Sum1_o1;
  real_T rtb_Sum2;
  real_T rtb_Sum2_g;
  int16_T i;
  real_T rtb_Sum_o_idx;
  real_T rtb_Sum_o_idx_0;
  real32_T rtb_DataTypeConversion_idx;

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/In'
   */
  for (i = 0; i < 15; i++) {
    rtb_DataTypeConversion1[i] = navigator_U.In[i];
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion1' */

  /* Math: '<S16>/Math Function1' incorporates:
   *  Constant: '<S16>/Constant5'
   */
  rtb_Rn = rt_remd_snf(rtb_DataTypeConversion1[0], navigator_P.Constant5_Value);

  /* Product: '<S16>/Product2' incorporates:
   *  Constant: '<S16>/Constant4'
   */
  rtb_Sum_o_idx = rtb_Rn / navigator_P.Constant4_Value;

  /* Rounding: '<S16>/Rounding Function1' */
  if (rtb_Sum_o_idx < 0.0) {
    rtb_Sum_o_idx = ceil(rtb_Sum_o_idx);
  } else {
    rtb_Sum_o_idx = floor(rtb_Sum_o_idx);
  }

  /* Sum: '<S16>/Sum1' incorporates:
   *  Gain: '<S16>/Gain3'
   *  Rounding: '<S16>/Rounding Function1'
   */
  rtb_Rn -= navigator_P.Gain3_Gain * rtb_Sum_o_idx;

  /* Product: '<S16>/Product' incorporates:
   *  Constant: '<S16>/Constant1'
   */
  rtb_Sum1_j = rtb_Rn / navigator_P.Constant1_Value;

  /* Rounding: '<S16>/Rounding Function' */
  if (rtb_Sum1_j < 0.0) {
    rtb_Sum_o_idx = ceil(rtb_Sum1_j);
  } else {
    rtb_Sum_o_idx = floor(rtb_Sum1_j);
  }

  /* Gain: '<S16>/Gain1' */
  rtb_Sum1_j *= navigator_P.Gain1_Gain;

  /* Product: '<S16>/Product1' */
  rtb_Sum1_j *= rtb_Sum1_j;

  /* Sqrt: '<S16>/sqrt' */
  rtb_Sum1_j = sqrt(rtb_Sum1_j);

  /* Rounding: '<S16>/Rounding Function2' */
  if (rtb_Sum1_j < 0.0) {
    rtb_Sum1_j = ceil(rtb_Sum1_j);
  } else {
    rtb_Sum1_j = floor(rtb_Sum1_j);
  }

  /* End of Rounding: '<S16>/Rounding Function2' */

  /* Gain: '<S16>/Gain2' */
  rtb_Sum1_j *= navigator_P.Gain2_Gain;

  /* Sum: '<S16>/Sum2' incorporates:
   *  Constant: '<S16>/Constant3'
   *  Gain: '<S16>/Gain'
   *  Math: '<S16>/Math Function2'
   *  Product: '<S16>/Product3'
   *  Rounding: '<S16>/Rounding Function'
   */
  rtb_Rn = (rtb_Rn - navigator_P.Gain_Gain * rtb_Sum_o_idx) - rtb_Sum1_j *
    rt_remd_snf(rtb_Rn, navigator_P.Constant3_Value);

  /* Math: '<S17>/Math Function2' incorporates:
   *  Constant: '<S17>/Constant2'
   *  DataTypeConversion: '<S16>/Data Type Conversion'
   *  Gain: '<S16>/Gain4'
   *  Logic: '<S16>/Logical Operator1'
   *  Sum: '<S16>/Sum3'
   */
  rtb_UnitConversion_eg = rt_remd_snf((real_T)(rtb_Sum1_j != 0.0) *
    navigator_P.Gain4_Gain + rtb_DataTypeConversion1[1],
    navigator_P.Constant2_Value);

  /* Product: '<S17>/Product' incorporates:
   *  Constant: '<S17>/Constant'
   */
  rtb_Sum_o_idx = rtb_UnitConversion_eg / navigator_P.Constant_Value;

  /* Rounding: '<S17>/Rounding Function' */
  if (rtb_Sum_o_idx < 0.0) {
    rtb_Sum_o_idx = ceil(rtb_Sum_o_idx);
  } else {
    rtb_Sum_o_idx = floor(rtb_Sum_o_idx);
  }

  /* Sum: '<S17>/Sum2' incorporates:
   *  Gain: '<S17>/Gain'
   *  Rounding: '<S17>/Rounding Function'
   */
  rtb_UnitConversion_eg -= navigator_P.Gain_Gain_h * rtb_Sum_o_idx;

  /* Gain: '<S19>/Unit Conversion' incorporates:
   *  Constant: '<S15>/initial_pos'
   *  Sum: '<S15>/Sum1'
   */
  rtb_Sum_o_idx = (rtb_Rn - navigator_P.initial_pos_Value_l[0]) *
    navigator_P.UnitConversion_Gain;
  rtb_Sum_o_idx_0 = (rtb_UnitConversion_eg - navigator_P.initial_pos_Value_l[1])
    * navigator_P.UnitConversion_Gain;

  /* Sum: '<S24>/Sum' incorporates:
   *  Constant: '<S24>/Constant'
   *  Constant: '<S24>/f'
   */
  rtb_UnitConversion_eg = navigator_P.f_Value - navigator_P.Constant_Value_om;

  /* Sqrt: '<S25>/sqrt' incorporates:
   *  Constant: '<S25>/Constant'
   *  Product: '<S25>/Product1'
   *  Sum: '<S25>/Sum1'
   */
  rtb_UnitConversion_eg = sqrt(navigator_P.Constant_Value_o -
    rtb_UnitConversion_eg * rtb_UnitConversion_eg);

  /* Gain: '<S22>/Unit Conversion' incorporates:
   *  Constant: '<S15>/initial_latg'
   */
  rtb_Sum1_j = navigator_P.UnitConversion_Gain_o *
    navigator_P.initial_latg_Value;

  /* Trigonometry: '<S23>/Trigonometric Function1' */
  rtb_Rn = sin(rtb_Sum1_j);

  /* Sum: '<S23>/Sum1' incorporates:
   *  Constant: '<S23>/Constant'
   *  Product: '<S23>/Product1'
   */
  rtb_Rn = navigator_P.Constant_Value_e - rtb_UnitConversion_eg *
    rtb_UnitConversion_eg * rtb_Rn * rtb_Rn;

  /* Product: '<S20>/Product1' incorporates:
   *  Constant: '<S20>/Constant1'
   *  Sqrt: '<S20>/sqrt'
   */
  rtb_radlat = navigator_P.Constant1_Value_b / sqrt(rtb_Rn);

  /* Product: '<S18>/dNorth' incorporates:
   *  Constant: '<S20>/Constant'
   *  Constant: '<S20>/Constant2'
   *  Product: '<S20>/Product2'
   *  Product: '<S20>/Product3'
   *  Sum: '<S20>/Sum1'
   *  Trigonometry: '<S20>/Trigonometric Function1'
   */
  rtb_UnitConversion_eg = rtb_Sum_o_idx / rt_atan2d_snf
    (navigator_P.Constant2_Value_o, (navigator_P.Constant_Value_b -
      rtb_UnitConversion_eg * rtb_UnitConversion_eg) * rtb_radlat / rtb_Rn);

  /* Gain: '<S21>/Unit Conversion' incorporates:
   *  Constant: '<S18>/ref_pos'
   */
  rtb_Sum_o_idx = navigator_P.UnitConversion_Gain_b * navigator_P.ref_pos_Value;

  /* Trigonometry: '<S18>/SinCos' */
  rtb_Rn = sin(rtb_Sum_o_idx);
  rtb_Sum1_g = cos(rtb_Sum_o_idx);

  /* Product: '<S18>/dEast' incorporates:
   *  Constant: '<S20>/Constant3'
   *  Product: '<S20>/Product4'
   *  Trigonometry: '<S20>/Trigonometric Function'
   *  Trigonometry: '<S20>/Trigonometric Function2'
   */
  rtb_radlat = 1.0 / rt_atan2d_snf(navigator_P.Constant3_Value_j, rtb_radlat *
    cos(rtb_Sum1_j)) * rtb_Sum_o_idx_0;

  /* Gain: '<S2>/Gain1' */
  rtb_Sum1_j = navigator_P.Gain1_Gain_m * rtb_DataTypeConversion1[4];

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/dt'
   *  Product: '<S18>/x*cos'
   *  Product: '<S18>/y*sin'
   *  Product: '<S1>/Product'
   *  Product: '<S1>/Product2'
   *  Sum: '<S18>/Sum2'
   *  Trigonometry: '<S1>/Trigonometric Function'
   */
  rtb_Sum1_o1 = (rtb_UnitConversion_eg * rtb_Sum1_g + rtb_radlat * rtb_Rn) +
    rtb_DataTypeConversion1[3] * cos(rtb_Sum1_j) * navigator_P.dt_Value;

  /* Gain: '<S10>/Unit Conversion' incorporates:
   *  Constant: '<S6>/ref_pos'
   */
  rtb_Sum_o_idx = navigator_P.UnitConversion_Gain_f *
    navigator_P.ref_pos_Value_n;

  /* Trigonometry: '<S6>/SinCos' */
  rtb_Sum2_g = sin(rtb_Sum_o_idx);
  rtb_Sum2 = cos(rtb_Sum_o_idx);

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S1>/dt1'
   *  Product: '<S18>/x*sin'
   *  Product: '<S18>/y*cos'
   *  Product: '<S1>/Product1'
   *  Product: '<S1>/Product3'
   *  Sum: '<S18>/Sum3'
   *  Trigonometry: '<S1>/Trigonometric Function1'
   */
  rtb_Sum1_g = (rtb_radlat * rtb_Sum1_g - rtb_UnitConversion_eg * rtb_Rn) +
    rtb_DataTypeConversion1[3] * sin(rtb_Sum1_j) * navigator_P.dt1_Value;

  /* Sum: '<S13>/Sum' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S13>/f'
   */
  rtb_radlat = navigator_P.f_Value_b - navigator_P.Constant_Value_p;

  /* Sqrt: '<S14>/sqrt' incorporates:
   *  Constant: '<S14>/Constant'
   *  Product: '<S14>/Product1'
   *  Sum: '<S14>/Sum1'
   */
  rtb_radlat = sqrt(navigator_P.Constant_Value_kd - rtb_radlat * rtb_radlat);

  /* Gain: '<S11>/Unit Conversion' incorporates:
   *  Constant: '<S3>/initial_latg'
   */
  rtb_UnitConversion_eg = navigator_P.UnitConversion_Gain_h *
    navigator_P.initial_latg_Value_n;

  /* Trigonometry: '<S12>/Trigonometric Function1' */
  rtb_Sum1_j = sin(rtb_UnitConversion_eg);

  /* Sum: '<S12>/Sum1' incorporates:
   *  Constant: '<S12>/Constant'
   *  Product: '<S12>/Product1'
   */
  rtb_Sum1_j = navigator_P.Constant_Value_k - rtb_radlat * rtb_radlat *
    rtb_Sum1_j * rtb_Sum1_j;

  /* Product: '<S9>/Product1' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Sqrt: '<S9>/sqrt'
   */
  rtb_Rn = navigator_P.Constant1_Value_f / sqrt(rtb_Sum1_j);

  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<S3>/initial_pos'
   *  Constant: '<S9>/Constant3'
   *  Gain: '<S8>/Unit Conversion'
   *  Product: '<S6>/rad long '
   *  Product: '<S6>/x*sin'
   *  Product: '<S6>/y*cos'
   *  Product: '<S9>/Product4'
   *  Sum: '<S6>/Sum1'
   *  Trigonometry: '<S9>/Trigonometric Function'
   *  Trigonometry: '<S9>/Trigonometric Function2'
   */
  rtb_Sum_o_idx_0 = (rtb_Sum1_o1 * rtb_Sum2_g + rtb_Sum1_g * rtb_Sum2) *
    rt_atan2d_snf(navigator_P.Constant3_Value_jt, rtb_Rn * cos
                  (rtb_UnitConversion_eg)) * navigator_P.UnitConversion_Gain_g +
    navigator_P.initial_pos_Value[1];

  /* Math: '<S5>/Math Function1' incorporates:
   *  Constant: '<S3>/initial_pos'
   *  Constant: '<S5>/Constant5'
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant2'
   *  Gain: '<S8>/Unit Conversion'
   *  Product: '<S6>/rad lat'
   *  Product: '<S6>/x*cos'
   *  Product: '<S6>/y*sin'
   *  Product: '<S9>/Product2'
   *  Product: '<S9>/Product3'
   *  Sum: '<S3>/Sum'
   *  Sum: '<S6>/Sum'
   *  Sum: '<S9>/Sum1'
   *  Trigonometry: '<S9>/Trigonometric Function1'
   */
  rtb_Sum2 = rt_remd_snf(rt_atan2d_snf(navigator_P.Constant2_Value_f,
    (navigator_P.Constant_Value_c - rtb_radlat * rtb_radlat) * rtb_Rn /
    rtb_Sum1_j) * (rtb_Sum1_o1 * rtb_Sum2 - rtb_Sum1_g * rtb_Sum2_g) *
    navigator_P.UnitConversion_Gain_g + navigator_P.initial_pos_Value[0],
    navigator_P.Constant5_Value_e);

  /* Product: '<S5>/Product2' incorporates:
   *  Constant: '<S5>/Constant4'
   */
  rtb_Sum_o_idx = rtb_Sum2 / navigator_P.Constant4_Value_g;

  /* Rounding: '<S5>/Rounding Function1' */
  if (rtb_Sum_o_idx < 0.0) {
    rtb_Sum_o_idx = ceil(rtb_Sum_o_idx);
  } else {
    rtb_Sum_o_idx = floor(rtb_Sum_o_idx);
  }

  /* Sum: '<S5>/Sum1' incorporates:
   *  Gain: '<S5>/Gain3'
   *  Rounding: '<S5>/Rounding Function1'
   */
  rtb_Sum2 -= navigator_P.Gain3_Gain_l * rtb_Sum_o_idx;

  /* Product: '<S5>/Product' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  rtb_Sum2_g = rtb_Sum2 / navigator_P.Constant1_Value_g;

  /* Rounding: '<S5>/Rounding Function' */
  if (rtb_Sum2_g < 0.0) {
    rtb_Sum_o_idx = ceil(rtb_Sum2_g);
  } else {
    rtb_Sum_o_idx = floor(rtb_Sum2_g);
  }

  /* Gain: '<S5>/Gain1' */
  rtb_Sum2_g *= navigator_P.Gain1_Gain_d;

  /* Product: '<S5>/Product1' */
  rtb_Sum2_g *= rtb_Sum2_g;

  /* Sqrt: '<S5>/sqrt' */
  rtb_Sum2_g = sqrt(rtb_Sum2_g);

  /* Rounding: '<S5>/Rounding Function2' */
  if (rtb_Sum2_g < 0.0) {
    rtb_Sum2_g = ceil(rtb_Sum2_g);
  } else {
    rtb_Sum2_g = floor(rtb_Sum2_g);
  }

  /* End of Rounding: '<S5>/Rounding Function2' */

  /* Gain: '<S5>/Gain2' */
  rtb_Sum2_g *= navigator_P.Gain2_Gain_p;

  /* Sum: '<S5>/Sum2' incorporates:
   *  Constant: '<S5>/Constant3'
   *  Gain: '<S5>/Gain'
   *  Math: '<S5>/Math Function2'
   *  Product: '<S5>/Product3'
   *  Rounding: '<S5>/Rounding Function'
   */
  rtb_Sum2 = (rtb_Sum2 - navigator_P.Gain_Gain_c * rtb_Sum_o_idx) - rtb_Sum2_g *
    rt_remd_snf(rtb_Sum2, navigator_P.Constant3_Value_h);

  /* Math: '<S7>/Math Function2' incorporates:
   *  Constant: '<S7>/Constant2'
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  Gain: '<S5>/Gain4'
   *  Logic: '<S5>/Logical Operator1'
   *  Sum: '<S5>/Sum3'
   */
  rtb_Sum2_g = rt_remd_snf((real_T)(rtb_Sum2_g != 0.0) *
    navigator_P.Gain4_Gain_j + rtb_Sum_o_idx_0, navigator_P.Constant2_Value_e);

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S7>/Constant'
   */
  rtb_Sum_o_idx = rtb_Sum2_g / navigator_P.Constant_Value_d;

  /* Rounding: '<S7>/Rounding Function' */
  if (rtb_Sum_o_idx < 0.0) {
    rtb_Sum_o_idx = ceil(rtb_Sum_o_idx);
  } else {
    rtb_Sum_o_idx = floor(rtb_Sum_o_idx);
  }

  /* Sum: '<S7>/Sum2' incorporates:
   *  Gain: '<S7>/Gain'
   *  Rounding: '<S7>/Rounding Function'
   */
  rtb_Sum2_g -= navigator_P.Gain_Gain_j * rtb_Sum_o_idx;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S4>/Constant'
   *  Sum: '<S15>/Sum'
   *  Sum: '<S3>/Sum1'
   *  UnaryMinus: '<S15>/Ze2height'
   *  UnaryMinus: '<S3>/Ze2height'
   */
  rtb_DataTypeConversion_idx = (real32_T)(-(-(rtb_DataTypeConversion1[2] +
    navigator_P.Constant_Value_f)) - navigator_P.Constant_Value_ci);

  /* Outport: '<Root>/Out' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  navigator_Y.Out[0] = (real32_T)rtb_Sum2;
  navigator_Y.Out[1] = (real32_T)rtb_Sum2_g;
  navigator_Y.Out[2] = rtb_DataTypeConversion_idx;
  navigator_Y.Out[3] = (real32_T)rtb_Sum2;
  navigator_Y.Out[4] = (real32_T)rtb_Sum2_g;
  navigator_Y.Out[5] = rtb_DataTypeConversion_idx;
}

/* Model initialize function */
void navigator_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(navigator_M, (NULL));

  /* external inputs */
  (void) memset(navigator_U.In, 0,
                15U*sizeof(real32_T));

  /* external outputs */
  (void) memset(&navigator_Y.Out[0], 0,
                6U*sizeof(real32_T));
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
