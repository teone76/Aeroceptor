/*
 * File: navigator.cpp
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
  real_T rtb_DataTypeConversion1[16];
  real_T rtb_SinCos_o1_p;
  real_T rtb_Sum6;
  real_T rtb_Px_c;
  real_T rtb_Gain;
  real_T rtb_UnitConversion;
  real_T rtb_Sum5;
  real_T rtb_Product_b;
  real_T rtb_SinCos_o2;
  real_T rtb_SinCos_o1;
  real_T rtb_Pz;
  real_T rtb_Sum;
  real_T rtb_TrigonometricFunction1_l;
  int16_T i;
  real_T rtb_Switch;
  real_T rtb_PositionError_idx;
  real_T rtb_PositionError_idx_0;
  real_T rtb_Switch_idx;
  real_T rtb_UnitConversion_a_idx;
  real_T rtb_UnitConversion_a_idx_0;
  real_T rtb_Switch_idx_0;
  real32_T rtb_VxVyVz_idx;
  real32_T rtb_VxVyVz_idx_0;

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/In'
   */
  for (i = 0; i < 16; i++) {
    rtb_DataTypeConversion1[i] = navigator_U.In[i];
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion1' */

  /* Math: '<S15>/Math Function1' incorporates:
   *  Constant: '<S15>/Constant5'
   */
  rtb_SinCos_o1_p = rt_remd_snf(rtb_DataTypeConversion1[0],
    navigator_P.Constant5_Value);

  /* Product: '<S15>/Product2' incorporates:
   *  Constant: '<S15>/Constant4'
   */
  rtb_PositionError_idx_0 = rtb_SinCos_o1_p / navigator_P.Constant4_Value;

  /* Rounding: '<S15>/Rounding Function1' */
  if (rtb_PositionError_idx_0 < 0.0) {
    rtb_PositionError_idx_0 = ceil(rtb_PositionError_idx_0);
  } else {
    rtb_PositionError_idx_0 = floor(rtb_PositionError_idx_0);
  }

  /* Sum: '<S15>/Sum1' incorporates:
   *  Gain: '<S15>/Gain3'
   *  Rounding: '<S15>/Rounding Function1'
   */
  rtb_SinCos_o1_p -= navigator_P.Gain3_Gain * rtb_PositionError_idx_0;

  /* Product: '<S15>/Product' incorporates:
   *  Constant: '<S15>/Constant1'
   */
  rtb_Sum6 = rtb_SinCos_o1_p / navigator_P.Constant1_Value_n;

  /* Rounding: '<S15>/Rounding Function' */
  if (rtb_Sum6 < 0.0) {
    rtb_PositionError_idx_0 = ceil(rtb_Sum6);
  } else {
    rtb_PositionError_idx_0 = floor(rtb_Sum6);
  }

  /* Gain: '<S15>/Gain1' */
  rtb_Sum6 *= navigator_P.Gain1_Gain_e;

  /* Product: '<S15>/Product1' */
  rtb_Sum6 *= rtb_Sum6;

  /* Sqrt: '<S15>/sqrt' */
  rtb_Sum6 = sqrt(rtb_Sum6);

  /* Rounding: '<S15>/Rounding Function2' */
  if (rtb_Sum6 < 0.0) {
    rtb_Sum6 = ceil(rtb_Sum6);
  } else {
    rtb_Sum6 = floor(rtb_Sum6);
  }

  /* End of Rounding: '<S15>/Rounding Function2' */

  /* Gain: '<S15>/Gain2' */
  rtb_Sum6 *= navigator_P.Gain2_Gain_m;

  /* Sum: '<S15>/Sum2' incorporates:
   *  Constant: '<S15>/Constant3'
   *  Gain: '<S15>/Gain'
   *  Math: '<S15>/Math Function2'
   *  Product: '<S15>/Product3'
   *  Rounding: '<S15>/Rounding Function'
   */
  rtb_SinCos_o1_p = (rtb_SinCos_o1_p - navigator_P.Gain_Gain_n *
                     rtb_PositionError_idx_0) - rtb_Sum6 * rt_remd_snf
    (rtb_SinCos_o1_p, navigator_P.Constant3_Value);

  /* Math: '<S16>/Math Function2' incorporates:
   *  Constant: '<S16>/Constant2'
   *  DataTypeConversion: '<S15>/Data Type Conversion'
   *  Gain: '<S15>/Gain4'
   *  Logic: '<S15>/Logical Operator1'
   *  Sum: '<S15>/Sum3'
   */
  rtb_Px_c = rt_remd_snf((real_T)(rtb_Sum6 != 0.0) * navigator_P.Gain4_Gain +
    rtb_DataTypeConversion1[1], navigator_P.Constant2_Value);

  /* Product: '<S16>/Product' incorporates:
   *  Constant: '<S16>/Constant'
   */
  rtb_PositionError_idx_0 = rtb_Px_c / navigator_P.Constant_Value;

  /* Rounding: '<S16>/Rounding Function' */
  if (rtb_PositionError_idx_0 < 0.0) {
    rtb_PositionError_idx_0 = ceil(rtb_PositionError_idx_0);
  } else {
    rtb_PositionError_idx_0 = floor(rtb_PositionError_idx_0);
  }

  /* Sum: '<S16>/Sum2' incorporates:
   *  Gain: '<S16>/Gain'
   *  Rounding: '<S16>/Rounding Function'
   */
  rtb_Px_c -= navigator_P.Gain_Gain_i * rtb_PositionError_idx_0;

  /* Gain: '<S18>/Unit Conversion' incorporates:
   *  Constant: '<S14>/initial_pos'
   *  Sum: '<S14>/Sum1'
   */
  rtb_UnitConversion_a_idx = (rtb_SinCos_o1_p - navigator_P.initial_pos_Value[0])
    * navigator_P.UnitConversion_Gain;
  rtb_UnitConversion_a_idx_0 = (rtb_Px_c - navigator_P.initial_pos_Value[1]) *
    navigator_P.UnitConversion_Gain;

  /* Sum: '<S23>/Sum' incorporates:
   *  Constant: '<S23>/Constant'
   *  Constant: '<S23>/f'
   */
  rtb_Px_c = navigator_P.f_Value - navigator_P.Constant_Value_g;

  /* Sqrt: '<S24>/sqrt' incorporates:
   *  Constant: '<S24>/Constant'
   *  Product: '<S24>/Product1'
   *  Sum: '<S24>/Sum1'
   */
  rtb_Px_c = sqrt(navigator_P.Constant_Value_k - rtb_Px_c * rtb_Px_c);

  /* Gain: '<S21>/Unit Conversion' incorporates:
   *  Constant: '<S14>/initial_latg'
   */
  rtb_Sum6 = navigator_P.UnitConversion_Gain_d * navigator_P.initial_latg_Value;

  /* Trigonometry: '<S22>/Trigonometric Function1' */
  rtb_SinCos_o1_p = sin(rtb_Sum6);

  /* Sum: '<S22>/Sum1' incorporates:
   *  Constant: '<S22>/Constant'
   *  Product: '<S22>/Product1'
   */
  rtb_SinCos_o1_p = navigator_P.Constant_Value_i - rtb_Px_c * rtb_Px_c *
    rtb_SinCos_o1_p * rtb_SinCos_o1_p;

  /* Product: '<S19>/Product1' incorporates:
   *  Constant: '<S19>/Constant1'
   *  Sqrt: '<S19>/sqrt'
   */
  rtb_Gain = navigator_P.Constant1_Value_j / sqrt(rtb_SinCos_o1_p);

  /* Product: '<S17>/dNorth' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S19>/Constant2'
   *  Product: '<S19>/Product2'
   *  Product: '<S19>/Product3'
   *  Sum: '<S19>/Sum1'
   *  Trigonometry: '<S19>/Trigonometric Function1'
   */
  rtb_Px_c = rtb_UnitConversion_a_idx / rt_atan2d_snf
    (navigator_P.Constant2_Value_h, (navigator_P.Constant_Value_h - rtb_Px_c *
      rtb_Px_c) * rtb_Gain / rtb_SinCos_o1_p);

  /* Gain: '<S20>/Unit Conversion' incorporates:
   *  Constant: '<S17>/ref_pos'
   */
  rtb_UnitConversion = navigator_P.UnitConversion_Gain_m *
    navigator_P.ref_pos_Value;

  /* Trigonometry: '<S17>/SinCos' */
  rtb_SinCos_o1_p = sin(rtb_UnitConversion);
  rtb_Sum5 = cos(rtb_UnitConversion);

  /* Product: '<S17>/dEast' incorporates:
   *  Constant: '<S19>/Constant3'
   *  Product: '<S19>/Product4'
   *  Trigonometry: '<S19>/Trigonometric Function'
   *  Trigonometry: '<S19>/Trigonometric Function2'
   */
  rtb_Gain = 1.0 / rt_atan2d_snf(navigator_P.Constant3_Value_k, rtb_Gain * cos
    (rtb_Sum6)) * rtb_UnitConversion_a_idx_0;

  /* Sum: '<S17>/Sum2' incorporates:
   *  Product: '<S17>/x*cos'
   *  Product: '<S17>/y*sin'
   */
  rtb_Sum6 = rtb_Px_c * rtb_Sum5 + rtb_Gain * rtb_SinCos_o1_p;

  /* Gain: '<S11>/Gain1' */
  rtb_Product_b = navigator_P.Gain1_Gain_ex * rtb_DataTypeConversion1[3];

  /* Product: '<S2>/Product1' incorporates:
   *  Constant: '<S1>/radius'
   *  Trigonometry: '<S2>/Trigonometric Function1'
   */
  rtb_SinCos_o2 = navigator_P.radius_Value * sin(rtb_Product_b);

  /* Sum: '<S17>/Sum3' incorporates:
   *  Product: '<S17>/x*sin'
   *  Product: '<S17>/y*cos'
   */
  rtb_Sum5 = rtb_Gain * rtb_Sum5 - rtb_Px_c * rtb_SinCos_o1_p;

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<S1>/radius'
   *  Trigonometry: '<S2>/Trigonometric Function2'
   */
  rtb_Product_b = cos(rtb_Product_b) * navigator_P.radius_Value;

  /* Math: '<S26>/Math Function1' incorporates:
   *  Constant: '<S26>/Constant5'
   */
  rtb_Px_c = rt_remd_snf(rtb_DataTypeConversion1[4],
    navigator_P.Constant5_Value_e);

  /* Product: '<S26>/Product2' incorporates:
   *  Constant: '<S26>/Constant4'
   */
  rtb_PositionError_idx_0 = rtb_Px_c / navigator_P.Constant4_Value_m;

  /* Rounding: '<S26>/Rounding Function1' */
  if (rtb_PositionError_idx_0 < 0.0) {
    rtb_PositionError_idx_0 = ceil(rtb_PositionError_idx_0);
  } else {
    rtb_PositionError_idx_0 = floor(rtb_PositionError_idx_0);
  }

  /* Sum: '<S26>/Sum1' incorporates:
   *  Gain: '<S26>/Gain3'
   *  Rounding: '<S26>/Rounding Function1'
   */
  rtb_Px_c -= navigator_P.Gain3_Gain_i * rtb_PositionError_idx_0;

  /* Product: '<S26>/Product' incorporates:
   *  Constant: '<S26>/Constant1'
   */
  rtb_SinCos_o1_p = rtb_Px_c / navigator_P.Constant1_Value_a;

  /* Rounding: '<S26>/Rounding Function' */
  if (rtb_SinCos_o1_p < 0.0) {
    rtb_PositionError_idx_0 = ceil(rtb_SinCos_o1_p);
  } else {
    rtb_PositionError_idx_0 = floor(rtb_SinCos_o1_p);
  }

  /* Gain: '<S26>/Gain1' */
  rtb_SinCos_o1_p *= navigator_P.Gain1_Gain_g;

  /* Product: '<S26>/Product1' */
  rtb_SinCos_o1_p *= rtb_SinCos_o1_p;

  /* Sqrt: '<S26>/sqrt' */
  rtb_SinCos_o1_p = sqrt(rtb_SinCos_o1_p);

  /* Rounding: '<S26>/Rounding Function2' */
  if (rtb_SinCos_o1_p < 0.0) {
    rtb_SinCos_o1_p = ceil(rtb_SinCos_o1_p);
  } else {
    rtb_SinCos_o1_p = floor(rtb_SinCos_o1_p);
  }

  /* End of Rounding: '<S26>/Rounding Function2' */

  /* Gain: '<S26>/Gain2' */
  rtb_SinCos_o1_p *= navigator_P.Gain2_Gain_p;

  /* Sum: '<S26>/Sum2' incorporates:
   *  Constant: '<S26>/Constant3'
   *  Gain: '<S26>/Gain'
   *  Math: '<S26>/Math Function2'
   *  Product: '<S26>/Product3'
   *  Rounding: '<S26>/Rounding Function'
   */
  rtb_Px_c = (rtb_Px_c - navigator_P.Gain_Gain_nz * rtb_PositionError_idx_0) -
    rtb_SinCos_o1_p * rt_remd_snf(rtb_Px_c, navigator_P.Constant3_Value_e);

  /* Math: '<S27>/Math Function2' incorporates:
   *  Constant: '<S27>/Constant2'
   *  DataTypeConversion: '<S26>/Data Type Conversion'
   *  Gain: '<S26>/Gain4'
   *  Logic: '<S26>/Logical Operator1'
   *  Sum: '<S26>/Sum3'
   */
  rtb_SinCos_o1 = rt_remd_snf((real_T)(rtb_SinCos_o1_p != 0.0) *
    navigator_P.Gain4_Gain_k + rtb_DataTypeConversion1[5],
    navigator_P.Constant2_Value_i);

  /* Product: '<S27>/Product' incorporates:
   *  Constant: '<S27>/Constant'
   */
  rtb_PositionError_idx_0 = rtb_SinCos_o1 / navigator_P.Constant_Value_j;

  /* Rounding: '<S27>/Rounding Function' */
  if (rtb_PositionError_idx_0 < 0.0) {
    rtb_PositionError_idx_0 = ceil(rtb_PositionError_idx_0);
  } else {
    rtb_PositionError_idx_0 = floor(rtb_PositionError_idx_0);
  }

  /* Sum: '<S27>/Sum2' incorporates:
   *  Gain: '<S27>/Gain'
   *  Rounding: '<S27>/Rounding Function'
   */
  rtb_SinCos_o1 -= navigator_P.Gain_Gain_o * rtb_PositionError_idx_0;

  /* Gain: '<S29>/Unit Conversion' incorporates:
   *  Constant: '<S25>/initial_pos'
   *  Sum: '<S25>/Sum1'
   */
  rtb_UnitConversion_a_idx = (rtb_Px_c - navigator_P.initial_pos_Value_j[0]) *
    navigator_P.UnitConversion_Gain_e;
  rtb_UnitConversion_a_idx_0 = (rtb_SinCos_o1 - navigator_P.initial_pos_Value_j
    [1]) * navigator_P.UnitConversion_Gain_e;

  /* Sum: '<S34>/Sum' incorporates:
   *  Constant: '<S34>/Constant'
   *  Constant: '<S34>/f'
   */
  rtb_SinCos_o1 = navigator_P.f_Value_o - navigator_P.Constant_Value_hn;

  /* Sqrt: '<S35>/sqrt' incorporates:
   *  Constant: '<S35>/Constant'
   *  Product: '<S35>/Product1'
   *  Sum: '<S35>/Sum1'
   */
  rtb_SinCos_o1 = sqrt(navigator_P.Constant_Value_id - rtb_SinCos_o1 *
                       rtb_SinCos_o1);

  /* Gain: '<S32>/Unit Conversion' incorporates:
   *  Constant: '<S25>/initial_latg'
   */
  rtb_Px_c = navigator_P.UnitConversion_Gain_h *
    navigator_P.initial_latg_Value_k;

  /* Trigonometry: '<S33>/Trigonometric Function1' */
  rtb_SinCos_o1_p = sin(rtb_Px_c);

  /* Sum: '<S33>/Sum1' incorporates:
   *  Constant: '<S33>/Constant'
   *  Product: '<S33>/Product1'
   */
  rtb_SinCos_o1_p = navigator_P.Constant_Value_i4 - rtb_SinCos_o1 *
    rtb_SinCos_o1 * rtb_SinCos_o1_p * rtb_SinCos_o1_p;

  /* Product: '<S30>/Product1' incorporates:
   *  Constant: '<S30>/Constant1'
   *  Sqrt: '<S30>/sqrt'
   */
  rtb_Pz = navigator_P.Constant1_Value_p / sqrt(rtb_SinCos_o1_p);

  /* Product: '<S28>/dNorth' incorporates:
   *  Constant: '<S30>/Constant'
   *  Constant: '<S30>/Constant2'
   *  Product: '<S30>/Product2'
   *  Product: '<S30>/Product3'
   *  Sum: '<S30>/Sum1'
   *  Trigonometry: '<S30>/Trigonometric Function1'
   */
  rtb_SinCos_o1 = rtb_UnitConversion_a_idx / rt_atan2d_snf
    (navigator_P.Constant2_Value_o, (navigator_P.Constant_Value_p -
      rtb_SinCos_o1 * rtb_SinCos_o1) * rtb_Pz / rtb_SinCos_o1_p);

  /* Gain: '<S31>/Unit Conversion' incorporates:
   *  Constant: '<S28>/ref_pos'
   */
  rtb_Gain = navigator_P.UnitConversion_Gain_ec * navigator_P.ref_pos_Value_c;

  /* Trigonometry: '<S28>/SinCos' */
  rtb_SinCos_o1_p = sin(rtb_Gain);
  rtb_Sum = cos(rtb_Gain);

  /* Product: '<S28>/dEast' incorporates:
   *  Constant: '<S30>/Constant3'
   *  Product: '<S30>/Product4'
   *  Trigonometry: '<S30>/Trigonometric Function'
   *  Trigonometry: '<S30>/Trigonometric Function2'
   */
  rtb_Pz = 1.0 / rt_atan2d_snf(navigator_P.Constant3_Value_n, rtb_Pz * cos
    (rtb_Px_c)) * rtb_UnitConversion_a_idx_0;

  /* Sum: '<S1>/Sum2' incorporates:
   *  Product: '<S28>/x*cos'
   *  Product: '<S28>/x*sin'
   *  Product: '<S28>/y*cos'
   *  Product: '<S28>/y*sin'
   *  Sum: '<S28>/Sum2'
   *  Sum: '<S28>/Sum3'
   *  Sum: '<S2>/Sum1'
   *  Sum: '<S2>/Sum4'
   */
  rtb_PositionError_idx = (rtb_Sum6 - rtb_SinCos_o2) - (rtb_SinCos_o1 * rtb_Sum
    + rtb_Pz * rtb_SinCos_o1_p);
  rtb_PositionError_idx_0 = (rtb_Sum5 + rtb_Product_b) - (rtb_Pz * rtb_Sum -
    rtb_SinCos_o1 * rtb_SinCos_o1_p);

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S6>/Constant'
   *  DotProduct: '<S3>/Dot Product'
   *  Product: '<S12>/Divide'
   *  Product: '<S12>/Product'
   *  Sqrt: '<S3>/Sqrt'
   *  Sum: '<S1>/Sum2'
   *  Sum: '<S25>/Sum'
   *  UnaryMinus: '<S25>/Ze2height'
   */
  if (sqrt(rtb_PositionError_idx * rtb_PositionError_idx +
           rtb_PositionError_idx_0 * rtb_PositionError_idx_0) >=
      navigator_P.Switch_Threshold) {
    /* Gain: '<S3>/Gain' */
    rtb_UnitConversion_a_idx = navigator_P.Gain_Gain * rtb_PositionError_idx;
    rtb_UnitConversion_a_idx_0 = navigator_P.Gain_Gain * rtb_PositionError_idx_0;

    /* Sqrt: '<S12>/Sqrt' incorporates:
     *  DotProduct: '<S12>/Dot Product'
     */
    rtb_Gain = sqrt(rtb_UnitConversion_a_idx * rtb_UnitConversion_a_idx +
                    rtb_UnitConversion_a_idx_0 * rtb_UnitConversion_a_idx_0);

    /* Saturate: '<S12>/Saturation' */
    if (rtb_Gain >= navigator_P.Saturation_UpperSat) {
      rtb_UnitConversion = navigator_P.Saturation_UpperSat;
    } else if (rtb_Gain <= navigator_P.Saturation_LowerSat) {
      rtb_UnitConversion = navigator_P.Saturation_LowerSat;
    } else {
      rtb_UnitConversion = rtb_Gain;
    }

    /* End of Saturate: '<S12>/Saturation' */
    rtb_Pz = rtb_UnitConversion_a_idx / rtb_Gain * rtb_UnitConversion;
    rtb_Switch_idx_0 = rtb_UnitConversion_a_idx_0 / rtb_Gain *
      rtb_UnitConversion;
    rtb_Switch_idx = rtb_DataTypeConversion1[6] - (-(rtb_DataTypeConversion1[6]
      + navigator_P.Constant_Value_l));
  } else {
    rtb_Pz = navigator_P.Constant1_Value[0];
    rtb_Switch_idx_0 = navigator_P.Constant1_Value[1];
    rtb_Switch_idx = navigator_P.Constant1_Value[2];
  }

  /* End of Switch: '<S3>/Switch' */

  /* Gain: '<S47>/Gain1' */
  rtb_Sum = navigator_P.Gain1_Gain_m * rtb_DataTypeConversion1[10];

  /* Trigonometry: '<S8>/Trigonometric Function2' */
  rtb_Px_c = cos(rtb_Sum);

  /* Sum: '<S8>/Sum1' incorporates:
   *  Constant: '<S1>/radius'
   *  Gain: '<S1>/Gain'
   */
  rtb_SinCos_o1_p = navigator_P.Gain_Gain_h * navigator_P.radius_Value -
    rtb_DataTypeConversion1[9];

  /* Trigonometry: '<S8>/Trigonometric Function1' */
  rtb_TrigonometricFunction1_l = sin(rtb_Sum);

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Vz1'
   *  Constant: '<S10>/vect'
   *  Product: '<S48>/Divide'
   *  Product: '<S48>/Product'
   *  Sum: '<S10>/Sum'
   */
  if (rtb_DataTypeConversion1[9] + navigator_P.Constant_Value_a != 0.0) {
    /* Gain: '<S8>/Gain1' */
    rtb_Gain = navigator_P.Gain1_Gain * rtb_SinCos_o1_p;

    /* Product: '<S8>/Product2' */
    rtb_UnitConversion = rtb_TrigonometricFunction1_l * rtb_Gain;

    /* Product: '<S8>/Product1' */
    rtb_Gain *= rtb_Px_c;

    /* Gain: '<S8>/Gain' */
    rtb_UnitConversion_a_idx = navigator_P.Gain_Gain_j * rtb_Gain;
    rtb_UnitConversion_a_idx_0 = navigator_P.Gain_Gain_j * rtb_UnitConversion;

    /* Sqrt: '<S48>/Sqrt' incorporates:
     *  DotProduct: '<S48>/Dot Product'
     */
    rtb_UnitConversion = sqrt(rtb_UnitConversion_a_idx *
      rtb_UnitConversion_a_idx + rtb_UnitConversion_a_idx_0 *
      rtb_UnitConversion_a_idx_0);

    /* Saturate: '<S48>/Saturation' */
    if (rtb_UnitConversion >= navigator_P.Saturation_UpperSat_m) {
      rtb_Gain = navigator_P.Saturation_UpperSat_m;
    } else if (rtb_UnitConversion <= navigator_P.Saturation_LowerSat_e) {
      rtb_Gain = navigator_P.Saturation_LowerSat_e;
    } else {
      rtb_Gain = rtb_UnitConversion;
    }

    /* End of Saturate: '<S48>/Saturation' */
    rtb_PositionError_idx_0 = rtb_UnitConversion_a_idx / rtb_UnitConversion *
      rtb_Gain;
    rtb_PositionError_idx = rtb_UnitConversion_a_idx_0 / rtb_UnitConversion *
      rtb_Gain;
    rtb_SinCos_o1 = navigator_P.Vz1_Value;
  } else {
    rtb_PositionError_idx_0 = navigator_P.vect_Value_a[0];
    rtb_PositionError_idx = navigator_P.vect_Value_a[1];
    rtb_SinCos_o1 = navigator_P.vect_Value_a[2];
  }

  /* End of Switch: '<S10>/Switch' */

  /* Sum: '<S1>/Sum' */
  rtb_Pz += rtb_PositionError_idx_0;
  rtb_Switch_idx_0 += rtb_PositionError_idx;
  rtb_Switch = rtb_Switch_idx + rtb_SinCos_o1;

  /* DataTypeConversion: '<S1>/Data Type Conversion2' */
  rtb_VxVyVz_idx = (real32_T)rtb_Pz;
  rtb_VxVyVz_idx_0 = (real32_T)rtb_Switch_idx_0;

  /* Sum: '<S2>/Sum6' */
  rtb_Sum6 += rtb_SinCos_o2;

  /* Sum: '<S2>/Sum5' */
  rtb_Sum5 -= rtb_Product_b;

  /* Math: '<S37>/Math Function1' incorporates:
   *  Constant: '<S37>/Constant5'
   */
  rtb_Sum = rt_remd_snf(rtb_DataTypeConversion1[11],
                        navigator_P.Constant5_Value_p);

  /* Product: '<S37>/Product2' incorporates:
   *  Constant: '<S37>/Constant4'
   */
  rtb_PositionError_idx_0 = rtb_Sum / navigator_P.Constant4_Value_e;

  /* Rounding: '<S37>/Rounding Function1' */
  if (rtb_PositionError_idx_0 < 0.0) {
    rtb_PositionError_idx_0 = ceil(rtb_PositionError_idx_0);
  } else {
    rtb_PositionError_idx_0 = floor(rtb_PositionError_idx_0);
  }

  /* Sum: '<S37>/Sum1' incorporates:
   *  Gain: '<S37>/Gain3'
   *  Rounding: '<S37>/Rounding Function1'
   */
  rtb_Sum -= navigator_P.Gain3_Gain_j * rtb_PositionError_idx_0;

  /* Product: '<S37>/Product' incorporates:
   *  Constant: '<S37>/Constant1'
   */
  rtb_Pz = rtb_Sum / navigator_P.Constant1_Value_c;

  /* Rounding: '<S37>/Rounding Function' */
  if (rtb_Pz < 0.0) {
    rtb_PositionError_idx_0 = ceil(rtb_Pz);
  } else {
    rtb_PositionError_idx_0 = floor(rtb_Pz);
  }

  /* Gain: '<S37>/Gain1' */
  rtb_Pz *= navigator_P.Gain1_Gain_p;

  /* Product: '<S37>/Product1' */
  rtb_Pz *= rtb_Pz;

  /* Sqrt: '<S37>/sqrt' */
  rtb_Pz = sqrt(rtb_Pz);

  /* Rounding: '<S37>/Rounding Function2' */
  if (rtb_Pz < 0.0) {
    rtb_Pz = ceil(rtb_Pz);
  } else {
    rtb_Pz = floor(rtb_Pz);
  }

  /* End of Rounding: '<S37>/Rounding Function2' */

  /* Gain: '<S37>/Gain2' */
  rtb_Pz *= navigator_P.Gain2_Gain_mq;

  /* Sum: '<S37>/Sum2' incorporates:
   *  Constant: '<S37>/Constant3'
   *  Gain: '<S37>/Gain'
   *  Math: '<S37>/Math Function2'
   *  Product: '<S37>/Product3'
   *  Rounding: '<S37>/Rounding Function'
   */
  rtb_Sum = (rtb_Sum - navigator_P.Gain_Gain_p * rtb_PositionError_idx_0) -
    rtb_Pz * rt_remd_snf(rtb_Sum, navigator_P.Constant3_Value_g);

  /* Math: '<S38>/Math Function2' incorporates:
   *  Constant: '<S38>/Constant2'
   *  DataTypeConversion: '<S37>/Data Type Conversion'
   *  Gain: '<S37>/Gain4'
   *  Logic: '<S37>/Logical Operator1'
   *  Sum: '<S37>/Sum3'
   */
  rtb_Pz = rt_remd_snf((real_T)(rtb_Pz != 0.0) * navigator_P.Gain4_Gain_p +
                       rtb_DataTypeConversion1[12],
                       navigator_P.Constant2_Value_d);

  /* Product: '<S38>/Product' incorporates:
   *  Constant: '<S38>/Constant'
   */
  rtb_PositionError_idx_0 = rtb_Pz / navigator_P.Constant_Value_o;

  /* Rounding: '<S38>/Rounding Function' */
  if (rtb_PositionError_idx_0 < 0.0) {
    rtb_PositionError_idx_0 = ceil(rtb_PositionError_idx_0);
  } else {
    rtb_PositionError_idx_0 = floor(rtb_PositionError_idx_0);
  }

  /* Sum: '<S38>/Sum2' incorporates:
   *  Gain: '<S38>/Gain'
   *  Rounding: '<S38>/Rounding Function'
   */
  rtb_Pz -= navigator_P.Gain_Gain_jy * rtb_PositionError_idx_0;

  /* Gain: '<S40>/Unit Conversion' incorporates:
   *  Constant: '<S36>/initial_pos'
   *  Sum: '<S36>/Sum1'
   */
  rtb_UnitConversion_a_idx = (rtb_Sum - navigator_P.initial_pos_Value_i[0]) *
    navigator_P.UnitConversion_Gain_b;
  rtb_UnitConversion_a_idx_0 = (rtb_Pz - navigator_P.initial_pos_Value_i[1]) *
    navigator_P.UnitConversion_Gain_b;

  /* Sum: '<S45>/Sum' incorporates:
   *  Constant: '<S45>/Constant'
   *  Constant: '<S45>/f'
   */
  rtb_Sum = navigator_P.f_Value_p - navigator_P.Constant_Value_ns;

  /* Sqrt: '<S46>/sqrt' incorporates:
   *  Constant: '<S46>/Constant'
   *  Product: '<S46>/Product1'
   *  Sum: '<S46>/Sum1'
   */
  rtb_Sum = sqrt(navigator_P.Constant_Value_n - rtb_Sum * rtb_Sum);

  /* Gain: '<S43>/Unit Conversion' incorporates:
   *  Constant: '<S36>/initial_latg'
   */
  rtb_Pz = navigator_P.UnitConversion_Gain_n * navigator_P.initial_latg_Value_kz;

  /* Trigonometry: '<S44>/Trigonometric Function1' */
  rtb_SinCos_o1 = sin(rtb_Pz);

  /* Sum: '<S44>/Sum1' incorporates:
   *  Constant: '<S44>/Constant'
   *  Product: '<S44>/Product1'
   */
  rtb_SinCos_o1 = navigator_P.Constant_Value_f - rtb_Sum * rtb_Sum *
    rtb_SinCos_o1 * rtb_SinCos_o1;

  /* Product: '<S41>/Product1' incorporates:
   *  Constant: '<S41>/Constant1'
   *  Sqrt: '<S41>/sqrt'
   */
  rtb_UnitConversion = navigator_P.Constant1_Value_i / sqrt(rtb_SinCos_o1);

  /* Product: '<S39>/dNorth' incorporates:
   *  Constant: '<S41>/Constant'
   *  Constant: '<S41>/Constant2'
   *  Product: '<S41>/Product2'
   *  Product: '<S41>/Product3'
   *  Sum: '<S41>/Sum1'
   *  Trigonometry: '<S41>/Trigonometric Function1'
   */
  rtb_Sum = rtb_UnitConversion_a_idx / rt_atan2d_snf
    (navigator_P.Constant2_Value_l, (navigator_P.Constant_Value_c - rtb_Sum *
      rtb_Sum) * rtb_UnitConversion / rtb_SinCos_o1);

  /* Gain: '<S42>/Unit Conversion' incorporates:
   *  Constant: '<S39>/ref_pos'
   */
  rtb_Gain = navigator_P.UnitConversion_Gain_dd * navigator_P.ref_pos_Value_cn;

  /* Trigonometry: '<S39>/SinCos' */
  rtb_SinCos_o1 = sin(rtb_Gain);
  rtb_SinCos_o2 = cos(rtb_Gain);

  /* Product: '<S39>/dEast' incorporates:
   *  Constant: '<S41>/Constant3'
   *  Product: '<S41>/Product4'
   *  Trigonometry: '<S41>/Trigonometric Function'
   *  Trigonometry: '<S41>/Trigonometric Function2'
   */
  rtb_Pz = 1.0 / rt_atan2d_snf(navigator_P.Constant3_Value_p, rtb_UnitConversion
    * cos(rtb_Pz)) * rtb_UnitConversion_a_idx_0;

  /* Sum: '<S1>/Sum3' incorporates:
   *  Product: '<S39>/x*cos'
   *  Product: '<S39>/x*sin'
   *  Product: '<S39>/y*cos'
   *  Product: '<S39>/y*sin'
   *  Sum: '<S39>/Sum2'
   *  Sum: '<S39>/Sum3'
   */
  rtb_PositionError_idx = rtb_Sum6 - (rtb_Sum * rtb_SinCos_o2 + rtb_Pz *
    rtb_SinCos_o1);
  rtb_PositionError_idx_0 = rtb_Sum5 - (rtb_Pz * rtb_SinCos_o2 - rtb_Sum *
    rtb_SinCos_o1);

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S7>/Constant'
   *  DotProduct: '<S4>/Dot Product'
   *  Product: '<S13>/Divide'
   *  Product: '<S13>/Product'
   *  Sqrt: '<S4>/Sqrt'
   *  Sum: '<S1>/Sum3'
   *  Sum: '<S36>/Sum'
   *  UnaryMinus: '<S36>/Ze2height'
   */
  if (sqrt(rtb_PositionError_idx * rtb_PositionError_idx +
           rtb_PositionError_idx_0 * rtb_PositionError_idx_0) >=
      navigator_P.Switch_Threshold_b) {
    /* Gain: '<S4>/Gain' */
    rtb_UnitConversion_a_idx = navigator_P.Gain_Gain_f * rtb_PositionError_idx;
    rtb_UnitConversion_a_idx_0 = navigator_P.Gain_Gain_f *
      rtb_PositionError_idx_0;

    /* Sqrt: '<S13>/Sqrt' incorporates:
     *  DotProduct: '<S13>/Dot Product'
     */
    rtb_Gain = sqrt(rtb_UnitConversion_a_idx * rtb_UnitConversion_a_idx +
                    rtb_UnitConversion_a_idx_0 * rtb_UnitConversion_a_idx_0);

    /* Saturate: '<S13>/Saturation' */
    if (rtb_Gain >= navigator_P.Saturation_UpperSat_n) {
      rtb_UnitConversion = navigator_P.Saturation_UpperSat_n;
    } else if (rtb_Gain <= navigator_P.Saturation_LowerSat_c) {
      rtb_UnitConversion = navigator_P.Saturation_LowerSat_c;
    } else {
      rtb_UnitConversion = rtb_Gain;
    }

    /* End of Saturate: '<S13>/Saturation' */
    rtb_PositionError_idx_0 = rtb_UnitConversion_a_idx / rtb_Gain *
      rtb_UnitConversion;
    rtb_PositionError_idx = rtb_UnitConversion_a_idx_0 / rtb_Gain *
      rtb_UnitConversion;
    rtb_SinCos_o1 = rtb_DataTypeConversion1[13] - (-(rtb_DataTypeConversion1[13]
      + navigator_P.Constant_Value_kw));
  } else {
    rtb_PositionError_idx_0 = navigator_P.Constant1_Value_g[0];
    rtb_PositionError_idx = navigator_P.Constant1_Value_g[1];
    rtb_SinCos_o1 = navigator_P.Constant1_Value_g[2];
  }

  /* End of Switch: '<S4>/Switch' */

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Vz2'
   *  Constant: '<S9>/vect'
   *  Product: '<S49>/Divide'
   *  Product: '<S49>/Product'
   *  Sum: '<S9>/Sum'
   */
  if (rtb_DataTypeConversion1[9] + navigator_P.Constant_Value_e != 0.0) {
    /* Gain: '<S8>/Gain2' incorporates:
     *  Product: '<S8>/Product3'
     *  Product: '<S8>/Product4'
     */
    rtb_UnitConversion_a_idx = rtb_Px_c * rtb_SinCos_o1_p *
      navigator_P.Gain2_Gain;
    rtb_UnitConversion_a_idx_0 = rtb_TrigonometricFunction1_l * rtb_SinCos_o1_p *
      navigator_P.Gain2_Gain;

    /* Sqrt: '<S49>/Sqrt' incorporates:
     *  DotProduct: '<S49>/Dot Product'
     */
    rtb_Gain = sqrt(rtb_UnitConversion_a_idx * rtb_UnitConversion_a_idx +
                    rtb_UnitConversion_a_idx_0 * rtb_UnitConversion_a_idx_0);

    /* Saturate: '<S49>/Saturation' */
    if (rtb_Gain >= navigator_P.Saturation_UpperSat_i) {
      rtb_UnitConversion = navigator_P.Saturation_UpperSat_i;
    } else if (rtb_Gain <= navigator_P.Saturation_LowerSat_b) {
      rtb_UnitConversion = navigator_P.Saturation_LowerSat_b;
    } else {
      rtb_UnitConversion = rtb_Gain;
    }

    /* End of Saturate: '<S49>/Saturation' */
    rtb_Pz = rtb_UnitConversion_a_idx / rtb_Gain * rtb_UnitConversion;
    rtb_Switch_idx_0 = rtb_UnitConversion_a_idx_0 / rtb_Gain *
      rtb_UnitConversion;
    rtb_Switch_idx = navigator_P.Vz2_Value;
  } else {
    rtb_Pz = navigator_P.vect_Value[0];
    rtb_Switch_idx_0 = navigator_P.vect_Value[1];
    rtb_Switch_idx = navigator_P.vect_Value[2];
  }

  /* End of Switch: '<S9>/Switch' */

  /* Sum: '<S1>/Sum1' */
  rtb_PositionError_idx_0 += rtb_Pz;
  rtb_PositionError_idx += rtb_Switch_idx_0;

  /* Outport: '<Root>/Out' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   *  Sum: '<S1>/Sum1'
   */
  navigator_Y.Out[0] = (real32_T)rtb_DataTypeConversion1[6];
  navigator_Y.Out[1] = (real32_T)rtb_DataTypeConversion1[13];
  navigator_Y.Out[2] = rtb_VxVyVz_idx;
  navigator_Y.Out[3] = rtb_VxVyVz_idx_0;
  navigator_Y.Out[4] = (real32_T)rtb_Switch;
  navigator_Y.Out[5] = (real32_T)rtb_PositionError_idx_0;
  navigator_Y.Out[6] = (real32_T)rtb_PositionError_idx;
  navigator_Y.Out[7] = (real32_T)(rtb_SinCos_o1 + rtb_Switch_idx);
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
                16U*sizeof(real32_T));

  /* external outputs */
  (void) memset(&navigator_Y.Out[0], 0,
                8U*sizeof(real32_T));
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
