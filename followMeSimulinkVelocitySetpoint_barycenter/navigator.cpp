/*
 * File: navigator.cpp
 *
 * Code generated for Simulink model 'navigator'.
 *
 * Model version                  : 1.50
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Thu Apr 23 16:23:26 2015
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
  real_T rtb_DataTypeConversion1[21];
  real_T rtb_Px_h;
  real_T rtb_Sum1_n;
  real_T rtb_SinCos_o1;
  real_T rtb_Gain;
  real_T rtb_dEast;
  real_T rtb_UnitConversion;
  real_T rtb_Px;
  real_T rtb_xcos;
  real_T rtb_xsin;
  real_T rtb_Sqrt_m;
  real_T rtb_Sum5;
  real_T rtb_Py_a;
  int16_T i;
  real_T rtb_Switch;
  real_T rtb_UnitConversion_n_idx;
  real_T rtb_UnitConversion_n_idx_0;
  real32_T rtb_VxVyVz_idx;
  real32_T rtb_VxVyVz_idx_0;

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/In'
   */
  for (i = 0; i < 21; i++) {
    rtb_DataTypeConversion1[i] = navigator_U.In[i];
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion1' */

  /* Math: '<S13>/Math Function1' incorporates:
   *  Constant: '<S13>/Constant5'
   */
  rtb_Px_h = rt_remd_snf(rtb_DataTypeConversion1[0], navigator_P.Constant5_Value);

  /* Product: '<S13>/Product2' incorporates:
   *  Constant: '<S13>/Constant4'
   */
  rtb_UnitConversion_n_idx = rtb_Px_h / navigator_P.Constant4_Value;

  /* Rounding: '<S13>/Rounding Function1' */
  if (rtb_UnitConversion_n_idx < 0.0) {
    rtb_UnitConversion_n_idx = ceil(rtb_UnitConversion_n_idx);
  } else {
    rtb_UnitConversion_n_idx = floor(rtb_UnitConversion_n_idx);
  }

  /* Sum: '<S13>/Sum1' incorporates:
   *  Gain: '<S13>/Gain3'
   *  Rounding: '<S13>/Rounding Function1'
   */
  rtb_Px_h -= navigator_P.Gain3_Gain * rtb_UnitConversion_n_idx;

  /* Product: '<S13>/Product' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  rtb_Sum1_n = rtb_Px_h / navigator_P.Constant1_Value_h;

  /* Rounding: '<S13>/Rounding Function' */
  if (rtb_Sum1_n < 0.0) {
    rtb_UnitConversion_n_idx = ceil(rtb_Sum1_n);
  } else {
    rtb_UnitConversion_n_idx = floor(rtb_Sum1_n);
  }

  /* Gain: '<S13>/Gain1' */
  rtb_Sum1_n *= navigator_P.Gain1_Gain;

  /* Product: '<S13>/Product1' */
  rtb_Sum1_n *= rtb_Sum1_n;

  /* Sqrt: '<S13>/sqrt' */
  rtb_Sum1_n = sqrt(rtb_Sum1_n);

  /* Rounding: '<S13>/Rounding Function2' */
  if (rtb_Sum1_n < 0.0) {
    rtb_Sum1_n = ceil(rtb_Sum1_n);
  } else {
    rtb_Sum1_n = floor(rtb_Sum1_n);
  }

  /* End of Rounding: '<S13>/Rounding Function2' */

  /* Gain: '<S13>/Gain2' */
  rtb_Sum1_n *= navigator_P.Gain2_Gain;

  /* Sum: '<S13>/Sum2' incorporates:
   *  Constant: '<S13>/Constant3'
   *  Gain: '<S13>/Gain'
   *  Math: '<S13>/Math Function2'
   *  Product: '<S13>/Product3'
   *  Rounding: '<S13>/Rounding Function'
   */
  rtb_Px_h = (rtb_Px_h - navigator_P.Gain_Gain_f * rtb_UnitConversion_n_idx) -
    rtb_Sum1_n * rt_remd_snf(rtb_Px_h, navigator_P.Constant3_Value);

  /* Math: '<S14>/Math Function2' incorporates:
   *  Constant: '<S14>/Constant2'
   *  DataTypeConversion: '<S13>/Data Type Conversion'
   *  Gain: '<S13>/Gain4'
   *  Logic: '<S13>/Logical Operator1'
   *  Sum: '<S13>/Sum3'
   */
  rtb_SinCos_o1 = rt_remd_snf((real_T)(rtb_Sum1_n != 0.0) *
    navigator_P.Gain4_Gain + rtb_DataTypeConversion1[1],
    navigator_P.Constant2_Value);

  /* Product: '<S14>/Product' incorporates:
   *  Constant: '<S14>/Constant'
   */
  rtb_UnitConversion_n_idx = rtb_SinCos_o1 / navigator_P.Constant_Value;

  /* Rounding: '<S14>/Rounding Function' */
  if (rtb_UnitConversion_n_idx < 0.0) {
    rtb_UnitConversion_n_idx = ceil(rtb_UnitConversion_n_idx);
  } else {
    rtb_UnitConversion_n_idx = floor(rtb_UnitConversion_n_idx);
  }

  /* Sum: '<S14>/Sum2' incorporates:
   *  Gain: '<S14>/Gain'
   *  Rounding: '<S14>/Rounding Function'
   */
  rtb_SinCos_o1 -= navigator_P.Gain_Gain_h * rtb_UnitConversion_n_idx;

  /* Gain: '<S16>/Unit Conversion' incorporates:
   *  Constant: '<S12>/initial_pos'
   *  Sum: '<S12>/Sum1'
   */
  rtb_UnitConversion_n_idx = (rtb_Px_h - navigator_P.initial_pos_Value[0]) *
    navigator_P.UnitConversion_Gain;
  rtb_UnitConversion_n_idx_0 = (rtb_SinCos_o1 - navigator_P.initial_pos_Value[1])
    * navigator_P.UnitConversion_Gain;

  /* Sum: '<S21>/Sum' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S21>/f'
   */
  rtb_SinCos_o1 = navigator_P.f_Value - navigator_P.Constant_Value_om;

  /* Sqrt: '<S22>/sqrt' incorporates:
   *  Constant: '<S22>/Constant'
   *  Product: '<S22>/Product1'
   *  Sum: '<S22>/Sum1'
   */
  rtb_SinCos_o1 = sqrt(navigator_P.Constant_Value_o - rtb_SinCos_o1 *
                       rtb_SinCos_o1);

  /* Gain: '<S19>/Unit Conversion' incorporates:
   *  Constant: '<S12>/initial_latg'
   */
  rtb_Sum1_n = navigator_P.UnitConversion_Gain_o *
    navigator_P.initial_latg_Value;

  /* Trigonometry: '<S20>/Trigonometric Function1' */
  rtb_Px_h = sin(rtb_Sum1_n);

  /* Sum: '<S20>/Sum1' incorporates:
   *  Constant: '<S20>/Constant'
   *  Product: '<S20>/Product1'
   */
  rtb_Px_h = navigator_P.Constant_Value_e - rtb_SinCos_o1 * rtb_SinCos_o1 *
    rtb_Px_h * rtb_Px_h;

  /* Product: '<S17>/Product1' incorporates:
   *  Constant: '<S17>/Constant1'
   *  Sqrt: '<S17>/sqrt'
   */
  rtb_dEast = navigator_P.Constant1_Value_b / sqrt(rtb_Px_h);

  /* Product: '<S15>/dNorth' incorporates:
   *  Constant: '<S17>/Constant'
   *  Constant: '<S17>/Constant2'
   *  Product: '<S17>/Product2'
   *  Product: '<S17>/Product3'
   *  Sum: '<S17>/Sum1'
   *  Trigonometry: '<S17>/Trigonometric Function1'
   */
  rtb_SinCos_o1 = rtb_UnitConversion_n_idx / rt_atan2d_snf
    (navigator_P.Constant2_Value_o, (navigator_P.Constant_Value_b -
      rtb_SinCos_o1 * rtb_SinCos_o1) * rtb_dEast / rtb_Px_h);

  /* Gain: '<S18>/Unit Conversion' incorporates:
   *  Constant: '<S15>/ref_pos'
   */
  rtb_UnitConversion = navigator_P.UnitConversion_Gain_b *
    navigator_P.ref_pos_Value;

  /* Trigonometry: '<S15>/SinCos' */
  rtb_Px_h = sin(rtb_UnitConversion);
  rtb_Px = cos(rtb_UnitConversion);

  /* Product: '<S15>/x*cos' */
  rtb_xcos = rtb_SinCos_o1 * rtb_Px;

  /* Product: '<S15>/dEast' incorporates:
   *  Constant: '<S17>/Constant3'
   *  Product: '<S17>/Product4'
   *  Trigonometry: '<S17>/Trigonometric Function'
   *  Trigonometry: '<S17>/Trigonometric Function2'
   */
  rtb_dEast = 1.0 / rt_atan2d_snf(navigator_P.Constant3_Value_j, rtb_dEast * cos
                                  (rtb_Sum1_n)) * rtb_UnitConversion_n_idx_0;

  /* Product: '<S15>/y*sin' */
  rtb_UnitConversion = rtb_dEast * rtb_Px_h;

  /* Product: '<S15>/x*sin' */
  rtb_xsin = rtb_SinCos_o1 * rtb_Px_h;

  /* Math: '<S24>/Math Function1' incorporates:
   *  Constant: '<S24>/Constant5'
   */
  rtb_SinCos_o1 = rt_remd_snf(rtb_DataTypeConversion1[9],
    navigator_P.Constant5_Value_b);

  /* Product: '<S24>/Product2' incorporates:
   *  Constant: '<S24>/Constant4'
   */
  rtb_UnitConversion_n_idx = rtb_SinCos_o1 / navigator_P.Constant4_Value_g;

  /* Rounding: '<S24>/Rounding Function1' */
  if (rtb_UnitConversion_n_idx < 0.0) {
    rtb_UnitConversion_n_idx = ceil(rtb_UnitConversion_n_idx);
  } else {
    rtb_UnitConversion_n_idx = floor(rtb_UnitConversion_n_idx);
  }

  /* Sum: '<S24>/Sum1' incorporates:
   *  Gain: '<S24>/Gain3'
   *  Rounding: '<S24>/Rounding Function1'
   */
  rtb_SinCos_o1 -= navigator_P.Gain3_Gain_o * rtb_UnitConversion_n_idx;

  /* Product: '<S24>/Product' incorporates:
   *  Constant: '<S24>/Constant1'
   */
  rtb_Px_h = rtb_SinCos_o1 / navigator_P.Constant1_Value_d1;

  /* Rounding: '<S24>/Rounding Function' */
  if (rtb_Px_h < 0.0) {
    rtb_UnitConversion_n_idx = ceil(rtb_Px_h);
  } else {
    rtb_UnitConversion_n_idx = floor(rtb_Px_h);
  }

  /* Gain: '<S24>/Gain1' */
  rtb_Px_h *= navigator_P.Gain1_Gain_i;

  /* Product: '<S24>/Product1' */
  rtb_Px_h *= rtb_Px_h;

  /* Sqrt: '<S24>/sqrt' */
  rtb_Px_h = sqrt(rtb_Px_h);

  /* Rounding: '<S24>/Rounding Function2' */
  if (rtb_Px_h < 0.0) {
    rtb_Px_h = ceil(rtb_Px_h);
  } else {
    rtb_Px_h = floor(rtb_Px_h);
  }

  /* End of Rounding: '<S24>/Rounding Function2' */

  /* Gain: '<S24>/Gain2' */
  rtb_Px_h *= navigator_P.Gain2_Gain_k;

  /* Sum: '<S24>/Sum2' incorporates:
   *  Constant: '<S24>/Constant3'
   *  Gain: '<S24>/Gain'
   *  Math: '<S24>/Math Function2'
   *  Product: '<S24>/Product3'
   *  Rounding: '<S24>/Rounding Function'
   */
  rtb_SinCos_o1 = (rtb_SinCos_o1 - navigator_P.Gain_Gain_k *
                   rtb_UnitConversion_n_idx) - rtb_Px_h * rt_remd_snf
    (rtb_SinCos_o1, navigator_P.Constant3_Value_c);

  /* Math: '<S25>/Math Function2' incorporates:
   *  Constant: '<S25>/Constant2'
   *  DataTypeConversion: '<S24>/Data Type Conversion'
   *  Gain: '<S24>/Gain4'
   *  Logic: '<S24>/Logical Operator1'
   *  Sum: '<S24>/Sum3'
   */
  rtb_Sqrt_m = rt_remd_snf((real_T)(rtb_Px_h != 0.0) * navigator_P.Gain4_Gain_i
    + rtb_DataTypeConversion1[10], navigator_P.Constant2_Value_h);

  /* Product: '<S25>/Product' incorporates:
   *  Constant: '<S25>/Constant'
   */
  rtb_UnitConversion_n_idx = rtb_Sqrt_m / navigator_P.Constant_Value_k;

  /* Rounding: '<S25>/Rounding Function' */
  if (rtb_UnitConversion_n_idx < 0.0) {
    rtb_UnitConversion_n_idx = ceil(rtb_UnitConversion_n_idx);
  } else {
    rtb_UnitConversion_n_idx = floor(rtb_UnitConversion_n_idx);
  }

  /* Sum: '<S25>/Sum2' incorporates:
   *  Gain: '<S25>/Gain'
   *  Rounding: '<S25>/Rounding Function'
   */
  rtb_Sqrt_m -= navigator_P.Gain_Gain_kt * rtb_UnitConversion_n_idx;

  /* Gain: '<S27>/Unit Conversion' incorporates:
   *  Constant: '<S23>/initial_pos'
   *  Sum: '<S23>/Sum1'
   */
  rtb_UnitConversion_n_idx = (rtb_SinCos_o1 - navigator_P.initial_pos_Value_h[0])
    * navigator_P.UnitConversion_Gain_g;
  rtb_UnitConversion_n_idx_0 = (rtb_Sqrt_m - navigator_P.initial_pos_Value_h[1])
    * navigator_P.UnitConversion_Gain_g;

  /* Sum: '<S32>/Sum' incorporates:
   *  Constant: '<S32>/Constant'
   *  Constant: '<S32>/f'
   */
  rtb_Sqrt_m = navigator_P.f_Value_j - navigator_P.Constant_Value_n;

  /* Sqrt: '<S33>/sqrt' incorporates:
   *  Constant: '<S33>/Constant'
   *  Product: '<S33>/Product1'
   *  Sum: '<S33>/Sum1'
   */
  rtb_Sqrt_m = sqrt(navigator_P.Constant_Value_m - rtb_Sqrt_m * rtb_Sqrt_m);

  /* Gain: '<S30>/Unit Conversion' incorporates:
   *  Constant: '<S23>/initial_latg'
   */
  rtb_SinCos_o1 = navigator_P.UnitConversion_Gain_i *
    navigator_P.initial_latg_Value_i;

  /* Trigonometry: '<S31>/Trigonometric Function1' */
  rtb_Px_h = sin(rtb_SinCos_o1);

  /* Sum: '<S31>/Sum1' incorporates:
   *  Constant: '<S31>/Constant'
   *  Product: '<S31>/Product1'
   */
  rtb_Px_h = navigator_P.Constant_Value_ks - rtb_Sqrt_m * rtb_Sqrt_m * rtb_Px_h *
    rtb_Px_h;

  /* Product: '<S28>/Product1' incorporates:
   *  Constant: '<S28>/Constant1'
   *  Sqrt: '<S28>/sqrt'
   */
  rtb_Sum5 = navigator_P.Constant1_Value_o / sqrt(rtb_Px_h);

  /* Product: '<S26>/dNorth' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S28>/Constant2'
   *  Product: '<S28>/Product2'
   *  Product: '<S28>/Product3'
   *  Sum: '<S28>/Sum1'
   *  Trigonometry: '<S28>/Trigonometric Function1'
   */
  rtb_Sqrt_m = rtb_UnitConversion_n_idx / rt_atan2d_snf
    (navigator_P.Constant2_Value_n, (navigator_P.Constant_Value_f - rtb_Sqrt_m *
      rtb_Sqrt_m) * rtb_Sum5 / rtb_Px_h);

  /* Gain: '<S29>/Unit Conversion' incorporates:
   *  Constant: '<S26>/ref_pos'
   */
  rtb_Gain = navigator_P.UnitConversion_Gain_c * navigator_P.ref_pos_Value_c;

  /* Trigonometry: '<S26>/SinCos' */
  rtb_Px_h = sin(rtb_Gain);
  rtb_Py_a = cos(rtb_Gain);

  /* Product: '<S26>/dEast' incorporates:
   *  Constant: '<S28>/Constant3'
   *  Product: '<S28>/Product4'
   *  Trigonometry: '<S28>/Trigonometric Function'
   *  Trigonometry: '<S28>/Trigonometric Function2'
   */
  rtb_Sum5 = 1.0 / rt_atan2d_snf(navigator_P.Constant3_Value_o, rtb_Sum5 * cos
    (rtb_SinCos_o1)) * rtb_UnitConversion_n_idx_0;

  /* Sum: '<S1>/Sum2' incorporates:
   *  Product: '<S15>/y*cos'
   *  Product: '<S26>/x*cos'
   *  Product: '<S26>/x*sin'
   *  Product: '<S26>/y*cos'
   *  Product: '<S26>/y*sin'
   *  Sum: '<S15>/Sum2'
   *  Sum: '<S15>/Sum3'
   *  Sum: '<S26>/Sum2'
   *  Sum: '<S26>/Sum3'
   */
  rtb_UnitConversion_n_idx = (rtb_xcos + rtb_UnitConversion) - (rtb_Sqrt_m *
    rtb_Py_a + rtb_Sum5 * rtb_Px_h);
  rtb_UnitConversion_n_idx_0 = (rtb_dEast * rtb_Px - rtb_xsin) - (rtb_Sum5 *
    rtb_Py_a - rtb_Sqrt_m * rtb_Px_h);

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S5>/Constant'
   *  Constant: '<S6>/Constant'
   *  DotProduct: '<S3>/Dot Product'
   *  Product: '<S10>/Divide'
   *  Product: '<S10>/Product'
   *  Sqrt: '<S3>/Sqrt'
   *  Sum: '<S12>/Sum'
   *  Sum: '<S1>/Sum2'
   *  Sum: '<S23>/Sum'
   *  UnaryMinus: '<S12>/Ze2height'
   *  UnaryMinus: '<S23>/Ze2height'
   */
  if (sqrt(rtb_UnitConversion_n_idx * rtb_UnitConversion_n_idx +
           rtb_UnitConversion_n_idx_0 * rtb_UnitConversion_n_idx_0) >=
      navigator_P.Switch_Threshold) {
    /* Sqrt: '<S10>/Sqrt' incorporates:
     *  DotProduct: '<S10>/Dot Product'
     */
    rtb_Gain = sqrt(rtb_UnitConversion_n_idx * rtb_UnitConversion_n_idx +
                    rtb_UnitConversion_n_idx_0 * rtb_UnitConversion_n_idx_0);

    /* Saturate: '<S10>/Saturation' */
    if (rtb_Gain >= navigator_P.Saturation_UpperSat) {
      rtb_UnitConversion = navigator_P.Saturation_UpperSat;
    } else if (rtb_Gain <= navigator_P.Saturation_LowerSat) {
      rtb_UnitConversion = navigator_P.Saturation_LowerSat;
    } else {
      rtb_UnitConversion = rtb_Gain;
    }

    /* End of Saturate: '<S10>/Saturation' */
    rtb_xcos = rtb_UnitConversion_n_idx / rtb_Gain * rtb_UnitConversion;
    rtb_UnitConversion_n_idx = rtb_UnitConversion_n_idx_0 / rtb_Gain *
      rtb_UnitConversion;
    rtb_UnitConversion_n_idx_0 = -(rtb_DataTypeConversion1[2] +
      navigator_P.Constant_Value_f1) - (-(rtb_DataTypeConversion1[11] +
      navigator_P.Constant_Value_kn));
  } else {
    rtb_xcos = navigator_P.Constant1_Value[0];
    rtb_UnitConversion_n_idx = navigator_P.Constant1_Value[1];
    rtb_UnitConversion_n_idx_0 = navigator_P.Constant1_Value[2];
  }

  /* End of Switch: '<S3>/Switch' */

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S1>/Vz1'
   */
  rtb_xcos += rtb_DataTypeConversion1[5];
  rtb_UnitConversion_n_idx += rtb_DataTypeConversion1[6];
  rtb_Switch = navigator_P.Vz1_Value + rtb_UnitConversion_n_idx_0;

  /* DataTypeConversion: '<S1>/Data Type Conversion2' */
  rtb_VxVyVz_idx = (real32_T)rtb_xcos;
  rtb_VxVyVz_idx_0 = (real32_T)rtb_UnitConversion_n_idx;

  /* Math: '<S46>/Math Function1' incorporates:
   *  Constant: '<S46>/Constant5'
   */
  rtb_Py_a = rt_remd_snf(rtb_DataTypeConversion1[7],
    navigator_P.Constant5_Value_k);

  /* Product: '<S46>/Product2' incorporates:
   *  Constant: '<S46>/Constant4'
   */
  rtb_UnitConversion_n_idx = rtb_Py_a / navigator_P.Constant4_Value_d;

  /* Rounding: '<S46>/Rounding Function1' */
  if (rtb_UnitConversion_n_idx < 0.0) {
    rtb_UnitConversion_n_idx = ceil(rtb_UnitConversion_n_idx);
  } else {
    rtb_UnitConversion_n_idx = floor(rtb_UnitConversion_n_idx);
  }

  /* Sum: '<S46>/Sum1' incorporates:
   *  Gain: '<S46>/Gain3'
   *  Rounding: '<S46>/Rounding Function1'
   */
  rtb_Py_a -= navigator_P.Gain3_Gain_c * rtb_UnitConversion_n_idx;

  /* Product: '<S46>/Product' incorporates:
   *  Constant: '<S46>/Constant1'
   */
  rtb_Sum5 = rtb_Py_a / navigator_P.Constant1_Value_j;

  /* Rounding: '<S46>/Rounding Function' */
  if (rtb_Sum5 < 0.0) {
    rtb_UnitConversion_n_idx = ceil(rtb_Sum5);
  } else {
    rtb_UnitConversion_n_idx = floor(rtb_Sum5);
  }

  /* Gain: '<S46>/Gain1' */
  rtb_Sum5 *= navigator_P.Gain1_Gain_o;

  /* Product: '<S46>/Product1' */
  rtb_Sum5 *= rtb_Sum5;

  /* Sqrt: '<S46>/sqrt' */
  rtb_Sum5 = sqrt(rtb_Sum5);

  /* Rounding: '<S46>/Rounding Function2' */
  if (rtb_Sum5 < 0.0) {
    rtb_Sum5 = ceil(rtb_Sum5);
  } else {
    rtb_Sum5 = floor(rtb_Sum5);
  }

  /* End of Rounding: '<S46>/Rounding Function2' */

  /* Gain: '<S46>/Gain2' */
  rtb_Sum5 *= navigator_P.Gain2_Gain_p;

  /* Sum: '<S46>/Sum2' incorporates:
   *  Constant: '<S46>/Constant3'
   *  Gain: '<S46>/Gain'
   *  Math: '<S46>/Math Function2'
   *  Product: '<S46>/Product3'
   *  Rounding: '<S46>/Rounding Function'
   */
  rtb_Py_a = (rtb_Py_a - navigator_P.Gain_Gain_n * rtb_UnitConversion_n_idx) -
    rtb_Sum5 * rt_remd_snf(rtb_Py_a, navigator_P.Constant3_Value_e);

  /* Math: '<S47>/Math Function2' incorporates:
   *  Constant: '<S47>/Constant2'
   *  DataTypeConversion: '<S46>/Data Type Conversion'
   *  Gain: '<S46>/Gain4'
   *  Logic: '<S46>/Logical Operator1'
   *  Sum: '<S46>/Sum3'
   */
  rtb_Sum5 = rt_remd_snf((real_T)(rtb_Sum5 != 0.0) * navigator_P.Gain4_Gain_id +
    rtb_DataTypeConversion1[8], navigator_P.Constant2_Value_l);

  /* Product: '<S47>/Product' incorporates:
   *  Constant: '<S47>/Constant'
   */
  rtb_UnitConversion_n_idx = rtb_Sum5 / navigator_P.Constant_Value_m5;

  /* Rounding: '<S47>/Rounding Function' */
  if (rtb_UnitConversion_n_idx < 0.0) {
    rtb_UnitConversion_n_idx = ceil(rtb_UnitConversion_n_idx);
  } else {
    rtb_UnitConversion_n_idx = floor(rtb_UnitConversion_n_idx);
  }

  /* Sum: '<S47>/Sum2' incorporates:
   *  Gain: '<S47>/Gain'
   *  Rounding: '<S47>/Rounding Function'
   */
  rtb_Sum5 -= navigator_P.Gain_Gain_m * rtb_UnitConversion_n_idx;

  /* Gain: '<S49>/Unit Conversion' incorporates:
   *  Constant: '<S45>/initial_pos'
   *  Sum: '<S45>/Sum1'
   */
  rtb_UnitConversion_n_idx = (rtb_Py_a - navigator_P.initial_pos_Value_j[0]) *
    navigator_P.UnitConversion_Gain_on;
  rtb_UnitConversion_n_idx_0 = (rtb_Sum5 - navigator_P.initial_pos_Value_j[1]) *
    navigator_P.UnitConversion_Gain_on;

  /* Sum: '<S54>/Sum' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/f'
   */
  rtb_Py_a = navigator_P.f_Value_a - navigator_P.Constant_Value_nm;

  /* Sqrt: '<S55>/sqrt' incorporates:
   *  Constant: '<S55>/Constant'
   *  Product: '<S55>/Product1'
   *  Sum: '<S55>/Sum1'
   */
  rtb_Py_a = sqrt(navigator_P.Constant_Value_f5 - rtb_Py_a * rtb_Py_a);

  /* Gain: '<S52>/Unit Conversion' incorporates:
   *  Constant: '<S45>/initial_latg'
   */
  rtb_Sum5 = navigator_P.UnitConversion_Gain_gr *
    navigator_P.initial_latg_Value_h;

  /* Trigonometry: '<S53>/Trigonometric Function1' */
  rtb_Sqrt_m = sin(rtb_Sum5);

  /* Sum: '<S53>/Sum1' incorporates:
   *  Constant: '<S53>/Constant'
   *  Product: '<S53>/Product1'
   */
  rtb_Sqrt_m = navigator_P.Constant_Value_b3 - rtb_Py_a * rtb_Py_a * rtb_Sqrt_m *
    rtb_Sqrt_m;

  /* Product: '<S50>/Product1' incorporates:
   *  Constant: '<S50>/Constant1'
   *  Sqrt: '<S50>/sqrt'
   */
  rtb_Px = navigator_P.Constant1_Value_k / sqrt(rtb_Sqrt_m);

  /* Product: '<S48>/dNorth' incorporates:
   *  Constant: '<S50>/Constant'
   *  Constant: '<S50>/Constant2'
   *  Product: '<S50>/Product2'
   *  Product: '<S50>/Product3'
   *  Sum: '<S50>/Sum1'
   *  Trigonometry: '<S50>/Trigonometric Function1'
   */
  rtb_Py_a = rtb_UnitConversion_n_idx / rt_atan2d_snf
    (navigator_P.Constant2_Value_a, (navigator_P.Constant_Value_c - rtb_Py_a *
      rtb_Py_a) * rtb_Px / rtb_Sqrt_m);

  /* Gain: '<S51>/Unit Conversion' incorporates:
   *  Constant: '<S48>/ref_pos'
   */
  rtb_Gain = navigator_P.UnitConversion_Gain_a * navigator_P.ref_pos_Value_d;

  /* Trigonometry: '<S48>/SinCos' */
  rtb_Sqrt_m = sin(rtb_Gain);
  rtb_dEast = cos(rtb_Gain);

  /* Product: '<S48>/dEast' incorporates:
   *  Constant: '<S50>/Constant3'
   *  Product: '<S50>/Product4'
   *  Trigonometry: '<S50>/Trigonometric Function'
   *  Trigonometry: '<S50>/Trigonometric Function2'
   */
  rtb_Sum5 = 1.0 / rt_atan2d_snf(navigator_P.Constant3_Value_p, rtb_Px * cos
    (rtb_Sum5)) * rtb_UnitConversion_n_idx_0;

  /* Sum: '<S48>/Sum2' incorporates:
   *  Product: '<S48>/x*cos'
   *  Product: '<S48>/y*sin'
   */
  rtb_Px = rtb_Py_a * rtb_dEast + rtb_Sum5 * rtb_Sqrt_m;

  /* Gain: '<S9>/Gain1' */
  rtb_SinCos_o1 = navigator_P.Gain1_Gain_os * rtb_DataTypeConversion1[14];

  /* Sum: '<S2>/Sum1' incorporates:
   *  Constant: '<S1>/Distance'
   *  Product: '<S2>/Product'
   *  Trigonometry: '<S2>/Trigonometric Function2'
   */
  rtb_Sum1_n = rtb_Px - cos(rtb_SinCos_o1) * navigator_P.Distance_Value;

  /* Sum: '<S48>/Sum3' incorporates:
   *  Product: '<S48>/x*sin'
   *  Product: '<S48>/y*cos'
   */
  rtb_Py_a = rtb_Sum5 * rtb_dEast - rtb_Py_a * rtb_Sqrt_m;

  /* Sum: '<S2>/Sum5' incorporates:
   *  Constant: '<S1>/Distance'
   *  Product: '<S2>/Product1'
   *  Trigonometry: '<S2>/Trigonometric Function1'
   */
  rtb_Sum5 = rtb_Py_a - navigator_P.Distance_Value * sin(rtb_SinCos_o1);

  /* Math: '<S35>/Math Function1' incorporates:
   *  Constant: '<S35>/Constant5'
   */
  rtb_Sqrt_m = rt_remd_snf(rtb_DataTypeConversion1[16],
    navigator_P.Constant5_Value_c);

  /* Product: '<S35>/Product2' incorporates:
   *  Constant: '<S35>/Constant4'
   */
  rtb_UnitConversion_n_idx = rtb_Sqrt_m / navigator_P.Constant4_Value_a;

  /* Rounding: '<S35>/Rounding Function1' */
  if (rtb_UnitConversion_n_idx < 0.0) {
    rtb_UnitConversion_n_idx = ceil(rtb_UnitConversion_n_idx);
  } else {
    rtb_UnitConversion_n_idx = floor(rtb_UnitConversion_n_idx);
  }

  /* Sum: '<S35>/Sum1' incorporates:
   *  Gain: '<S35>/Gain3'
   *  Rounding: '<S35>/Rounding Function1'
   */
  rtb_Sqrt_m -= navigator_P.Gain3_Gain_g * rtb_UnitConversion_n_idx;

  /* Product: '<S35>/Product' incorporates:
   *  Constant: '<S35>/Constant1'
   */
  rtb_dEast = rtb_Sqrt_m / navigator_P.Constant1_Value_f;

  /* Rounding: '<S35>/Rounding Function' */
  if (rtb_dEast < 0.0) {
    rtb_UnitConversion_n_idx = ceil(rtb_dEast);
  } else {
    rtb_UnitConversion_n_idx = floor(rtb_dEast);
  }

  /* Gain: '<S35>/Gain1' */
  rtb_dEast *= navigator_P.Gain1_Gain_c;

  /* Product: '<S35>/Product1' */
  rtb_dEast *= rtb_dEast;

  /* Sqrt: '<S35>/sqrt' */
  rtb_dEast = sqrt(rtb_dEast);

  /* Rounding: '<S35>/Rounding Function2' */
  if (rtb_dEast < 0.0) {
    rtb_dEast = ceil(rtb_dEast);
  } else {
    rtb_dEast = floor(rtb_dEast);
  }

  /* End of Rounding: '<S35>/Rounding Function2' */

  /* Gain: '<S35>/Gain2' */
  rtb_dEast *= navigator_P.Gain2_Gain_b;

  /* Sum: '<S35>/Sum2' incorporates:
   *  Constant: '<S35>/Constant3'
   *  Gain: '<S35>/Gain'
   *  Math: '<S35>/Math Function2'
   *  Product: '<S35>/Product3'
   *  Rounding: '<S35>/Rounding Function'
   */
  rtb_Sqrt_m = (rtb_Sqrt_m - navigator_P.Gain_Gain_o * rtb_UnitConversion_n_idx)
    - rtb_dEast * rt_remd_snf(rtb_Sqrt_m, navigator_P.Constant3_Value_f);

  /* Math: '<S36>/Math Function2' incorporates:
   *  Constant: '<S36>/Constant2'
   *  DataTypeConversion: '<S35>/Data Type Conversion'
   *  Gain: '<S35>/Gain4'
   *  Logic: '<S35>/Logical Operator1'
   *  Sum: '<S35>/Sum3'
   */
  rtb_dEast = rt_remd_snf((real_T)(rtb_dEast != 0.0) * navigator_P.Gain4_Gain_c
    + rtb_DataTypeConversion1[17], navigator_P.Constant2_Value_b);

  /* Product: '<S36>/Product' incorporates:
   *  Constant: '<S36>/Constant'
   */
  rtb_UnitConversion_n_idx = rtb_dEast / navigator_P.Constant_Value_bl;

  /* Rounding: '<S36>/Rounding Function' */
  if (rtb_UnitConversion_n_idx < 0.0) {
    rtb_UnitConversion_n_idx = ceil(rtb_UnitConversion_n_idx);
  } else {
    rtb_UnitConversion_n_idx = floor(rtb_UnitConversion_n_idx);
  }

  /* Sum: '<S36>/Sum2' incorporates:
   *  Gain: '<S36>/Gain'
   *  Rounding: '<S36>/Rounding Function'
   */
  rtb_dEast -= navigator_P.Gain_Gain_g * rtb_UnitConversion_n_idx;

  /* Gain: '<S38>/Unit Conversion' incorporates:
   *  Constant: '<S34>/initial_pos'
   *  Sum: '<S34>/Sum1'
   */
  rtb_UnitConversion_n_idx = (rtb_Sqrt_m - navigator_P.initial_pos_Value_g[0]) *
    navigator_P.UnitConversion_Gain_bh;
  rtb_UnitConversion_n_idx_0 = (rtb_dEast - navigator_P.initial_pos_Value_g[1]) *
    navigator_P.UnitConversion_Gain_bh;

  /* Sum: '<S43>/Sum' incorporates:
   *  Constant: '<S43>/Constant'
   *  Constant: '<S43>/f'
   */
  rtb_Sqrt_m = navigator_P.f_Value_e - navigator_P.Constant_Value_l;

  /* Sqrt: '<S44>/sqrt' incorporates:
   *  Constant: '<S44>/Constant'
   *  Product: '<S44>/Product1'
   *  Sum: '<S44>/Sum1'
   */
  rtb_Sqrt_m = sqrt(navigator_P.Constant_Value_h - rtb_Sqrt_m * rtb_Sqrt_m);

  /* Gain: '<S41>/Unit Conversion' incorporates:
   *  Constant: '<S34>/initial_latg'
   */
  rtb_dEast = navigator_P.UnitConversion_Gain_bj *
    navigator_P.initial_latg_Value_ii;

  /* Trigonometry: '<S42>/Trigonometric Function1' */
  rtb_SinCos_o1 = sin(rtb_dEast);

  /* Sum: '<S42>/Sum1' incorporates:
   *  Constant: '<S42>/Constant'
   *  Product: '<S42>/Product1'
   */
  rtb_SinCos_o1 = navigator_P.Constant_Value_a - rtb_Sqrt_m * rtb_Sqrt_m *
    rtb_SinCos_o1 * rtb_SinCos_o1;

  /* Product: '<S39>/Product1' incorporates:
   *  Constant: '<S39>/Constant1'
   *  Sqrt: '<S39>/sqrt'
   */
  rtb_Px_h = navigator_P.Constant1_Value_g / sqrt(rtb_SinCos_o1);

  /* Product: '<S37>/dNorth' incorporates:
   *  Constant: '<S39>/Constant'
   *  Constant: '<S39>/Constant2'
   *  Product: '<S39>/Product2'
   *  Product: '<S39>/Product3'
   *  Sum: '<S39>/Sum1'
   *  Trigonometry: '<S39>/Trigonometric Function1'
   */
  rtb_Sqrt_m = rtb_UnitConversion_n_idx / rt_atan2d_snf
    (navigator_P.Constant2_Value_hi, (navigator_P.Constant_Value_kl - rtb_Sqrt_m
      * rtb_Sqrt_m) * rtb_Px_h / rtb_SinCos_o1);

  /* Gain: '<S40>/Unit Conversion' incorporates:
   *  Constant: '<S37>/ref_pos'
   */
  rtb_Gain = navigator_P.UnitConversion_Gain_a3 * navigator_P.ref_pos_Value_n;

  /* Trigonometry: '<S37>/SinCos' */
  rtb_SinCos_o1 = sin(rtb_Gain);
  rtb_xsin = cos(rtb_Gain);

  /* Product: '<S37>/dEast' incorporates:
   *  Constant: '<S39>/Constant3'
   *  Product: '<S39>/Product4'
   *  Trigonometry: '<S39>/Trigonometric Function'
   *  Trigonometry: '<S39>/Trigonometric Function2'
   */
  rtb_dEast = 1.0 / rt_atan2d_snf(navigator_P.Constant3_Value_k, rtb_Px_h * cos
    (rtb_dEast)) * rtb_UnitConversion_n_idx_0;

  /* Sum: '<S37>/Sum2' incorporates:
   *  Product: '<S37>/x*cos'
   *  Product: '<S37>/y*sin'
   */
  rtb_Px_h = rtb_Sqrt_m * rtb_xsin + rtb_dEast * rtb_SinCos_o1;

  /* Sum: '<S37>/Sum3' incorporates:
   *  Product: '<S37>/x*sin'
   *  Product: '<S37>/y*cos'
   */
  rtb_xsin = rtb_dEast * rtb_xsin - rtb_Sqrt_m * rtb_SinCos_o1;

  /* Sum: '<S1>/Sum3' */
  rtb_UnitConversion_n_idx = rtb_Sum1_n - rtb_Px_h;
  rtb_UnitConversion_n_idx_0 = rtb_Sum5 - rtb_xsin;

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S7>/Constant'
   *  DotProduct: '<S4>/Dot Product'
   *  Product: '<S11>/Divide'
   *  Product: '<S11>/Product'
   *  Sqrt: '<S4>/Sqrt'
   *  Sum: '<S1>/Sum3'
   *  Sum: '<S34>/Sum'
   *  UnaryMinus: '<S34>/Ze2height'
   */
  if (sqrt(rtb_UnitConversion_n_idx * rtb_UnitConversion_n_idx +
           rtb_UnitConversion_n_idx_0 * rtb_UnitConversion_n_idx_0) >=
      navigator_P.Switch_Threshold_k) {
    /* Gain: '<S4>/Gain' */
    rtb_UnitConversion_n_idx *= navigator_P.Gain_Gain;
    rtb_UnitConversion_n_idx_0 *= navigator_P.Gain_Gain;

    /* Sqrt: '<S11>/Sqrt' incorporates:
     *  DotProduct: '<S11>/Dot Product'
     */
    rtb_Gain = sqrt(rtb_UnitConversion_n_idx * rtb_UnitConversion_n_idx +
                    rtb_UnitConversion_n_idx_0 * rtb_UnitConversion_n_idx_0);

    /* Saturate: '<S11>/Saturation' */
    if (rtb_Gain >= navigator_P.Saturation_UpperSat_l) {
      rtb_UnitConversion = navigator_P.Saturation_UpperSat_l;
    } else if (rtb_Gain <= navigator_P.Saturation_LowerSat_d) {
      rtb_UnitConversion = navigator_P.Saturation_LowerSat_d;
    } else {
      rtb_UnitConversion = rtb_Gain;
    }

    /* End of Saturate: '<S11>/Saturation' */
    rtb_xcos = rtb_UnitConversion_n_idx / rtb_Gain * rtb_UnitConversion;
    rtb_UnitConversion_n_idx = rtb_UnitConversion_n_idx_0 / rtb_Gain *
      rtb_UnitConversion;
    rtb_UnitConversion_n_idx_0 = rtb_DataTypeConversion1[18] -
      (-(rtb_DataTypeConversion1[18] + navigator_P.Constant_Value_d));
  } else {
    rtb_xcos = navigator_P.Constant1_Value_d[0];
    rtb_UnitConversion_n_idx = navigator_P.Constant1_Value_d[1];
    rtb_UnitConversion_n_idx_0 = navigator_P.Constant1_Value_d[2];
  }

  /* End of Switch: '<S4>/Switch' */

  /* Outport: '<Root>/Out' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   *  DataTypeConversion: '<S1>/Data Type Conversion4'
   */
  navigator_Y.Out[0] = (real32_T)rtb_DataTypeConversion1[11];
  navigator_Y.Out[1] = (real32_T)rtb_DataTypeConversion1[18];
  navigator_Y.Out[2] = rtb_VxVyVz_idx;
  navigator_Y.Out[3] = rtb_VxVyVz_idx_0;
  navigator_Y.Out[4] = (real32_T)rtb_Switch;
  navigator_Y.Out[5] = (real32_T)rtb_xcos;
  navigator_Y.Out[6] = (real32_T)rtb_UnitConversion_n_idx;
  navigator_Y.Out[7] = (real32_T)rtb_UnitConversion_n_idx_0;
  navigator_Y.Out[8] = (real32_T)rtb_Px;
  navigator_Y.Out[9] = (real32_T)rtb_Py_a;
  navigator_Y.Out[10] = (real32_T)rtb_Px_h;
  navigator_Y.Out[11] = (real32_T)rtb_xsin;
  navigator_Y.Out[12] = (real32_T)rtb_Sum1_n;
  navigator_Y.Out[13] = (real32_T)rtb_Sum5;
  navigator_Y.Out[14] = (real32_T)rtb_DataTypeConversion1[18];
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
                21U*sizeof(real32_T));

  /* external outputs */
  (void) memset(&navigator_Y.Out[0], 0,
                15U*sizeof(real32_T));
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
