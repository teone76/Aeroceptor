/*
 * File: navigator.cpp
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
  real_T rtb_Sum1_j;
  real_T rtb_Px_k;
  real_T rtb_UnitConversion_eg;
  real_T rtb_Gain;
  real_T rtb_SinCos_o2;
  real_T rtb_UnitConversion;
  real_T rtb_Py;
  real_T rtb_Px;
  real_T rtb_SinCos_o1;
  real_T rtb_Py_c;
  real_T rtb_Pz;
  int16_T i;
  real32_T rtb_XYZ_idx;
  real32_T rtb_XYZ_idx_0;
  real_T rtb_PositionError_idx;
  real_T rtb_UnitConversion_g_idx;
  real_T rtb_UnitConversion_g_idx_0;

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/In'
   */
  for (i = 0; i < 15; i++) {
    rtb_DataTypeConversion1[i] = navigator_U.In[i];
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion1' */

  /* Math: '<S19>/Math Function1' incorporates:
   *  Constant: '<S19>/Constant5'
   */
  rtb_Sum1_j = rt_remd_snf(rtb_DataTypeConversion1[0],
    navigator_P.Constant5_Value);

  /* Product: '<S19>/Product2' incorporates:
   *  Constant: '<S19>/Constant4'
   */
  rtb_PositionError_idx = rtb_Sum1_j / navigator_P.Constant4_Value;

  /* Rounding: '<S19>/Rounding Function1' */
  if (rtb_PositionError_idx < 0.0) {
    rtb_PositionError_idx = ceil(rtb_PositionError_idx);
  } else {
    rtb_PositionError_idx = floor(rtb_PositionError_idx);
  }

  /* Sum: '<S19>/Sum1' incorporates:
   *  Gain: '<S19>/Gain3'
   *  Rounding: '<S19>/Rounding Function1'
   */
  rtb_Sum1_j -= navigator_P.Gain3_Gain * rtb_PositionError_idx;

  /* Product: '<S19>/Product' incorporates:
   *  Constant: '<S19>/Constant1'
   */
  rtb_Px_k = rtb_Sum1_j / navigator_P.Constant1_Value_h;

  /* Rounding: '<S19>/Rounding Function' */
  if (rtb_Px_k < 0.0) {
    rtb_PositionError_idx = ceil(rtb_Px_k);
  } else {
    rtb_PositionError_idx = floor(rtb_Px_k);
  }

  /* Gain: '<S19>/Gain1' */
  rtb_Px_k *= navigator_P.Gain1_Gain;

  /* Product: '<S19>/Product1' */
  rtb_Px_k *= rtb_Px_k;

  /* Sqrt: '<S19>/sqrt' */
  rtb_Px_k = sqrt(rtb_Px_k);

  /* Rounding: '<S19>/Rounding Function2' */
  if (rtb_Px_k < 0.0) {
    rtb_Px_k = ceil(rtb_Px_k);
  } else {
    rtb_Px_k = floor(rtb_Px_k);
  }

  /* End of Rounding: '<S19>/Rounding Function2' */

  /* Gain: '<S19>/Gain2' */
  rtb_Px_k *= navigator_P.Gain2_Gain;

  /* Sum: '<S19>/Sum2' incorporates:
   *  Constant: '<S19>/Constant3'
   *  Gain: '<S19>/Gain'
   *  Math: '<S19>/Math Function2'
   *  Product: '<S19>/Product3'
   *  Rounding: '<S19>/Rounding Function'
   */
  rtb_Sum1_j = (rtb_Sum1_j - navigator_P.Gain_Gain * rtb_PositionError_idx) -
    rtb_Px_k * rt_remd_snf(rtb_Sum1_j, navigator_P.Constant3_Value);

  /* Math: '<S20>/Math Function2' incorporates:
   *  Constant: '<S20>/Constant2'
   *  DataTypeConversion: '<S19>/Data Type Conversion'
   *  Gain: '<S19>/Gain4'
   *  Logic: '<S19>/Logical Operator1'
   *  Sum: '<S19>/Sum3'
   */
  rtb_UnitConversion_eg = rt_remd_snf((real_T)(rtb_Px_k != 0.0) *
    navigator_P.Gain4_Gain + rtb_DataTypeConversion1[1],
    navigator_P.Constant2_Value);

  /* Product: '<S20>/Product' incorporates:
   *  Constant: '<S20>/Constant'
   */
  rtb_PositionError_idx = rtb_UnitConversion_eg / navigator_P.Constant_Value;

  /* Rounding: '<S20>/Rounding Function' */
  if (rtb_PositionError_idx < 0.0) {
    rtb_PositionError_idx = ceil(rtb_PositionError_idx);
  } else {
    rtb_PositionError_idx = floor(rtb_PositionError_idx);
  }

  /* Sum: '<S20>/Sum2' incorporates:
   *  Gain: '<S20>/Gain'
   *  Rounding: '<S20>/Rounding Function'
   */
  rtb_UnitConversion_eg -= navigator_P.Gain_Gain_h * rtb_PositionError_idx;

  /* Gain: '<S22>/Unit Conversion' incorporates:
   *  Constant: '<S18>/initial_pos'
   *  Sum: '<S18>/Sum1'
   */
  rtb_UnitConversion_g_idx = (rtb_Sum1_j - navigator_P.initial_pos_Value_l[0]) *
    navigator_P.UnitConversion_Gain;
  rtb_UnitConversion_g_idx_0 = (rtb_UnitConversion_eg -
    navigator_P.initial_pos_Value_l[1]) * navigator_P.UnitConversion_Gain;

  /* Sum: '<S27>/Sum' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S27>/f'
   */
  rtb_UnitConversion_eg = navigator_P.f_Value - navigator_P.Constant_Value_om;

  /* Sqrt: '<S28>/sqrt' incorporates:
   *  Constant: '<S28>/Constant'
   *  Product: '<S28>/Product1'
   *  Sum: '<S28>/Sum1'
   */
  rtb_UnitConversion_eg = sqrt(navigator_P.Constant_Value_o -
    rtb_UnitConversion_eg * rtb_UnitConversion_eg);

  /* Gain: '<S25>/Unit Conversion' incorporates:
   *  Constant: '<S18>/initial_latg'
   */
  rtb_Px_k = navigator_P.UnitConversion_Gain_o * navigator_P.initial_latg_Value;

  /* Trigonometry: '<S26>/Trigonometric Function1' */
  rtb_Sum1_j = sin(rtb_Px_k);

  /* Sum: '<S26>/Sum1' incorporates:
   *  Constant: '<S26>/Constant'
   *  Product: '<S26>/Product1'
   */
  rtb_Sum1_j = navigator_P.Constant_Value_e - rtb_UnitConversion_eg *
    rtb_UnitConversion_eg * rtb_Sum1_j * rtb_Sum1_j;

  /* Product: '<S23>/Product1' incorporates:
   *  Constant: '<S23>/Constant1'
   *  Sqrt: '<S23>/sqrt'
   */
  rtb_SinCos_o2 = navigator_P.Constant1_Value_b / sqrt(rtb_Sum1_j);

  /* Product: '<S21>/dNorth' incorporates:
   *  Constant: '<S23>/Constant'
   *  Constant: '<S23>/Constant2'
   *  Product: '<S23>/Product2'
   *  Product: '<S23>/Product3'
   *  Sum: '<S23>/Sum1'
   *  Trigonometry: '<S23>/Trigonometric Function1'
   */
  rtb_UnitConversion_eg = rtb_UnitConversion_g_idx / rt_atan2d_snf
    (navigator_P.Constant2_Value_o, (navigator_P.Constant_Value_b -
      rtb_UnitConversion_eg * rtb_UnitConversion_eg) * rtb_SinCos_o2 /
     rtb_Sum1_j);

  /* Gain: '<S24>/Unit Conversion' incorporates:
   *  Constant: '<S21>/ref_pos'
   */
  rtb_UnitConversion = navigator_P.UnitConversion_Gain_b *
    navigator_P.ref_pos_Value;

  /* Trigonometry: '<S21>/SinCos' */
  rtb_Sum1_j = sin(rtb_UnitConversion);
  rtb_Py = cos(rtb_UnitConversion);

  /* Product: '<S21>/dEast' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Product: '<S23>/Product4'
   *  Trigonometry: '<S23>/Trigonometric Function'
   *  Trigonometry: '<S23>/Trigonometric Function2'
   */
  rtb_SinCos_o2 = 1.0 / rt_atan2d_snf(navigator_P.Constant3_Value_j,
    rtb_SinCos_o2 * cos(rtb_Px_k)) * rtb_UnitConversion_g_idx_0;

  /* Sum: '<S21>/Sum2' incorporates:
   *  Product: '<S21>/x*cos'
   *  Product: '<S21>/y*sin'
   */
  rtb_Px_k = rtb_UnitConversion_eg * rtb_Py + rtb_SinCos_o2 * rtb_Sum1_j;

  /* Gain: '<S40>/Gain1' */
  rtb_Px = navigator_P.Gain1_Gain_m * rtb_DataTypeConversion1[4];

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S6>/dt'
   *  Product: '<S6>/Product'
   *  Product: '<S6>/Product2'
   *  Trigonometry: '<S6>/Trigonometric Function'
   */
  rtb_SinCos_o1 = rtb_DataTypeConversion1[3] * cos(rtb_Px) *
    navigator_P.dt_Value + rtb_Px_k;

  /* Gain: '<S13>/Unit Conversion' incorporates:
   *  Constant: '<S9>/ref_pos'
   */
  rtb_Gain = navigator_P.UnitConversion_Gain_f * navigator_P.ref_pos_Value_n;

  /* Trigonometry: '<S9>/SinCos' */
  rtb_Pz = sin(rtb_Gain);
  rtb_Py_c = cos(rtb_Gain);

  /* Sum: '<S21>/Sum3' incorporates:
   *  Product: '<S21>/x*sin'
   *  Product: '<S21>/y*cos'
   */
  rtb_Py = rtb_SinCos_o2 * rtb_Py - rtb_UnitConversion_eg * rtb_Sum1_j;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S6>/dt1'
   *  Product: '<S6>/Product1'
   *  Product: '<S6>/Product3'
   *  Trigonometry: '<S6>/Trigonometric Function1'
   */
  rtb_Px = rtb_DataTypeConversion1[3] * sin(rtb_Px) * navigator_P.dt1_Value +
    rtb_Py;

  /* Sum: '<S16>/Sum' incorporates:
   *  Constant: '<S16>/Constant'
   *  Constant: '<S16>/f'
   */
  rtb_SinCos_o2 = navigator_P.f_Value_b - navigator_P.Constant_Value_p;

  /* Sqrt: '<S17>/sqrt' incorporates:
   *  Constant: '<S17>/Constant'
   *  Product: '<S17>/Product1'
   *  Sum: '<S17>/Sum1'
   */
  rtb_SinCos_o2 = sqrt(navigator_P.Constant_Value_kd - rtb_SinCos_o2 *
                       rtb_SinCos_o2);

  /* Gain: '<S14>/Unit Conversion' incorporates:
   *  Constant: '<S3>/initial_latg'
   */
  rtb_UnitConversion_eg = navigator_P.UnitConversion_Gain_h *
    navigator_P.initial_latg_Value_n;

  /* Trigonometry: '<S15>/Trigonometric Function1' */
  rtb_Sum1_j = sin(rtb_UnitConversion_eg);

  /* Sum: '<S15>/Sum1' incorporates:
   *  Constant: '<S15>/Constant'
   *  Product: '<S15>/Product1'
   */
  rtb_Sum1_j = navigator_P.Constant_Value_k - rtb_SinCos_o2 * rtb_SinCos_o2 *
    rtb_Sum1_j * rtb_Sum1_j;

  /* Product: '<S12>/Product1' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Sqrt: '<S12>/sqrt'
   */
  rtb_UnitConversion = navigator_P.Constant1_Value_f / sqrt(rtb_Sum1_j);

  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<S12>/Constant3'
   *  Constant: '<S3>/initial_pos'
   *  Gain: '<S11>/Unit Conversion'
   *  Product: '<S12>/Product4'
   *  Product: '<S9>/rad long '
   *  Product: '<S9>/x*sin'
   *  Product: '<S9>/y*cos'
   *  Sum: '<S9>/Sum1'
   *  Trigonometry: '<S12>/Trigonometric Function'
   *  Trigonometry: '<S12>/Trigonometric Function2'
   */
  rtb_UnitConversion_g_idx_0 = (rtb_SinCos_o1 * rtb_Pz + rtb_Px * rtb_Py_c) *
    rt_atan2d_snf(navigator_P.Constant3_Value_jt, rtb_UnitConversion * cos
                  (rtb_UnitConversion_eg)) * navigator_P.UnitConversion_Gain_g +
    navigator_P.initial_pos_Value[1];

  /* Math: '<S8>/Math Function1' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S12>/Constant2'
   *  Constant: '<S3>/initial_pos'
   *  Constant: '<S8>/Constant5'
   *  Gain: '<S11>/Unit Conversion'
   *  Product: '<S12>/Product2'
   *  Product: '<S12>/Product3'
   *  Product: '<S9>/rad lat'
   *  Product: '<S9>/x*cos'
   *  Product: '<S9>/y*sin'
   *  Sum: '<S12>/Sum1'
   *  Sum: '<S3>/Sum'
   *  Sum: '<S9>/Sum'
   *  Trigonometry: '<S12>/Trigonometric Function1'
   */
  rtb_UnitConversion = rt_remd_snf(rt_atan2d_snf(navigator_P.Constant2_Value_f,
                                    (navigator_P.Constant_Value_c -
    rtb_SinCos_o2 * rtb_SinCos_o2) * rtb_UnitConversion / rtb_Sum1_j) *
    (rtb_SinCos_o1 * rtb_Py_c - rtb_Px * rtb_Pz) *
    navigator_P.UnitConversion_Gain_g + navigator_P.initial_pos_Value[0],
    navigator_P.Constant5_Value_e);

  /* Product: '<S8>/Product2' incorporates:
   *  Constant: '<S8>/Constant4'
   */
  rtb_PositionError_idx = rtb_UnitConversion / navigator_P.Constant4_Value_g;

  /* Rounding: '<S8>/Rounding Function1' */
  if (rtb_PositionError_idx < 0.0) {
    rtb_PositionError_idx = ceil(rtb_PositionError_idx);
  } else {
    rtb_PositionError_idx = floor(rtb_PositionError_idx);
  }

  /* Sum: '<S8>/Sum1' incorporates:
   *  Gain: '<S8>/Gain3'
   *  Rounding: '<S8>/Rounding Function1'
   */
  rtb_UnitConversion -= navigator_P.Gain3_Gain_l * rtb_PositionError_idx;

  /* Product: '<S8>/Product' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  rtb_Py_c = rtb_UnitConversion / navigator_P.Constant1_Value_g;

  /* Rounding: '<S8>/Rounding Function' */
  if (rtb_Py_c < 0.0) {
    rtb_PositionError_idx = ceil(rtb_Py_c);
  } else {
    rtb_PositionError_idx = floor(rtb_Py_c);
  }

  /* Gain: '<S8>/Gain1' */
  rtb_Py_c *= navigator_P.Gain1_Gain_d;

  /* Product: '<S8>/Product1' */
  rtb_Py_c *= rtb_Py_c;

  /* Sqrt: '<S8>/sqrt' */
  rtb_Py_c = sqrt(rtb_Py_c);

  /* Rounding: '<S8>/Rounding Function2' */
  if (rtb_Py_c < 0.0) {
    rtb_Py_c = ceil(rtb_Py_c);
  } else {
    rtb_Py_c = floor(rtb_Py_c);
  }

  /* End of Rounding: '<S8>/Rounding Function2' */

  /* Gain: '<S8>/Gain2' */
  rtb_Py_c *= navigator_P.Gain2_Gain_p;

  /* Sum: '<S8>/Sum2' incorporates:
   *  Constant: '<S8>/Constant3'
   *  Gain: '<S8>/Gain'
   *  Math: '<S8>/Math Function2'
   *  Product: '<S8>/Product3'
   *  Rounding: '<S8>/Rounding Function'
   */
  rtb_UnitConversion = (rtb_UnitConversion - navigator_P.Gain_Gain_c *
                        rtb_PositionError_idx) - rtb_Py_c * rt_remd_snf
    (rtb_UnitConversion, navigator_P.Constant3_Value_h);

  /* Math: '<S10>/Math Function2' incorporates:
   *  Constant: '<S10>/Constant2'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  Gain: '<S8>/Gain4'
   *  Logic: '<S8>/Logical Operator1'
   *  Sum: '<S8>/Sum3'
   */
  rtb_Py_c = rt_remd_snf((real_T)(rtb_Py_c != 0.0) * navigator_P.Gain4_Gain_j +
    rtb_UnitConversion_g_idx_0, navigator_P.Constant2_Value_e);

  /* Product: '<S10>/Product' incorporates:
   *  Constant: '<S10>/Constant'
   */
  rtb_PositionError_idx = rtb_Py_c / navigator_P.Constant_Value_d;

  /* Rounding: '<S10>/Rounding Function' */
  if (rtb_PositionError_idx < 0.0) {
    rtb_PositionError_idx = ceil(rtb_PositionError_idx);
  } else {
    rtb_PositionError_idx = floor(rtb_PositionError_idx);
  }

  /* Sum: '<S10>/Sum2' incorporates:
   *  Gain: '<S10>/Gain'
   *  Rounding: '<S10>/Rounding Function'
   */
  rtb_Py_c -= navigator_P.Gain_Gain_j * rtb_PositionError_idx;

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  rtb_XYZ_idx = (real32_T)rtb_UnitConversion;
  rtb_XYZ_idx_0 = (real32_T)rtb_Py_c;

  /* Math: '<S30>/Math Function1' incorporates:
   *  Constant: '<S30>/Constant5'
   */
  rtb_Py_c = rt_remd_snf(rtb_DataTypeConversion1[5],
    navigator_P.Constant5_Value_b);

  /* Product: '<S30>/Product2' incorporates:
   *  Constant: '<S30>/Constant4'
   */
  rtb_PositionError_idx = rtb_Py_c / navigator_P.Constant4_Value_g4;

  /* Rounding: '<S30>/Rounding Function1' */
  if (rtb_PositionError_idx < 0.0) {
    rtb_PositionError_idx = ceil(rtb_PositionError_idx);
  } else {
    rtb_PositionError_idx = floor(rtb_PositionError_idx);
  }

  /* Sum: '<S30>/Sum1' incorporates:
   *  Gain: '<S30>/Gain3'
   *  Rounding: '<S30>/Rounding Function1'
   */
  rtb_Py_c -= navigator_P.Gain3_Gain_o * rtb_PositionError_idx;

  /* Product: '<S30>/Product' incorporates:
   *  Constant: '<S30>/Constant1'
   */
  rtb_Pz = rtb_Py_c / navigator_P.Constant1_Value_d;

  /* Rounding: '<S30>/Rounding Function' */
  if (rtb_Pz < 0.0) {
    rtb_PositionError_idx = ceil(rtb_Pz);
  } else {
    rtb_PositionError_idx = floor(rtb_Pz);
  }

  /* Gain: '<S30>/Gain1' */
  rtb_Pz *= navigator_P.Gain1_Gain_i;

  /* Product: '<S30>/Product1' */
  rtb_Pz *= rtb_Pz;

  /* Sqrt: '<S30>/sqrt' */
  rtb_Pz = sqrt(rtb_Pz);

  /* Rounding: '<S30>/Rounding Function2' */
  if (rtb_Pz < 0.0) {
    rtb_Pz = ceil(rtb_Pz);
  } else {
    rtb_Pz = floor(rtb_Pz);
  }

  /* End of Rounding: '<S30>/Rounding Function2' */

  /* Gain: '<S30>/Gain2' */
  rtb_Pz *= navigator_P.Gain2_Gain_k;

  /* Sum: '<S30>/Sum2' incorporates:
   *  Constant: '<S30>/Constant3'
   *  Gain: '<S30>/Gain'
   *  Math: '<S30>/Math Function2'
   *  Product: '<S30>/Product3'
   *  Rounding: '<S30>/Rounding Function'
   */
  rtb_Py_c = (rtb_Py_c - navigator_P.Gain_Gain_k * rtb_PositionError_idx) -
    rtb_Pz * rt_remd_snf(rtb_Py_c, navigator_P.Constant3_Value_c);

  /* Math: '<S31>/Math Function2' incorporates:
   *  Constant: '<S31>/Constant2'
   *  DataTypeConversion: '<S30>/Data Type Conversion'
   *  Gain: '<S30>/Gain4'
   *  Logic: '<S30>/Logical Operator1'
   *  Sum: '<S30>/Sum3'
   */
  rtb_Pz = rt_remd_snf((real_T)(rtb_Pz != 0.0) * navigator_P.Gain4_Gain_i +
                       rtb_DataTypeConversion1[6], navigator_P.Constant2_Value_h);

  /* Product: '<S31>/Product' incorporates:
   *  Constant: '<S31>/Constant'
   */
  rtb_PositionError_idx = rtb_Pz / navigator_P.Constant_Value_kc;

  /* Rounding: '<S31>/Rounding Function' */
  if (rtb_PositionError_idx < 0.0) {
    rtb_PositionError_idx = ceil(rtb_PositionError_idx);
  } else {
    rtb_PositionError_idx = floor(rtb_PositionError_idx);
  }

  /* Sum: '<S31>/Sum2' incorporates:
   *  Gain: '<S31>/Gain'
   *  Rounding: '<S31>/Rounding Function'
   */
  rtb_Pz -= navigator_P.Gain_Gain_kt * rtb_PositionError_idx;

  /* Gain: '<S33>/Unit Conversion' incorporates:
   *  Constant: '<S29>/initial_pos'
   *  Sum: '<S29>/Sum1'
   */
  rtb_UnitConversion_g_idx = (rtb_Py_c - navigator_P.initial_pos_Value_h[0]) *
    navigator_P.UnitConversion_Gain_gs;
  rtb_UnitConversion_g_idx_0 = (rtb_Pz - navigator_P.initial_pos_Value_h[1]) *
    navigator_P.UnitConversion_Gain_gs;

  /* Sum: '<S38>/Sum' incorporates:
   *  Constant: '<S38>/Constant'
   *  Constant: '<S38>/f'
   */
  rtb_Py_c = navigator_P.f_Value_j - navigator_P.Constant_Value_n;

  /* Sqrt: '<S39>/sqrt' incorporates:
   *  Constant: '<S39>/Constant'
   *  Product: '<S39>/Product1'
   *  Sum: '<S39>/Sum1'
   */
  rtb_Py_c = sqrt(navigator_P.Constant_Value_m - rtb_Py_c * rtb_Py_c);

  /* Gain: '<S36>/Unit Conversion' incorporates:
   *  Constant: '<S29>/initial_latg'
   */
  rtb_Pz = navigator_P.UnitConversion_Gain_i * navigator_P.initial_latg_Value_i;

  /* Trigonometry: '<S37>/Trigonometric Function1' */
  rtb_SinCos_o1 = sin(rtb_Pz);

  /* Sum: '<S37>/Sum1' incorporates:
   *  Constant: '<S37>/Constant'
   *  Product: '<S37>/Product1'
   */
  rtb_SinCos_o1 = navigator_P.Constant_Value_ks - rtb_Py_c * rtb_Py_c *
    rtb_SinCos_o1 * rtb_SinCos_o1;

  /* Product: '<S34>/Product1' incorporates:
   *  Constant: '<S34>/Constant1'
   *  Sqrt: '<S34>/sqrt'
   */
  rtb_Px = navigator_P.Constant1_Value_o / sqrt(rtb_SinCos_o1);

  /* Product: '<S32>/dNorth' incorporates:
   *  Constant: '<S34>/Constant'
   *  Constant: '<S34>/Constant2'
   *  Product: '<S34>/Product2'
   *  Product: '<S34>/Product3'
   *  Sum: '<S34>/Sum1'
   *  Trigonometry: '<S34>/Trigonometric Function1'
   */
  rtb_Py_c = rtb_UnitConversion_g_idx / rt_atan2d_snf
    (navigator_P.Constant2_Value_n, (navigator_P.Constant_Value_f - rtb_Py_c *
      rtb_Py_c) * rtb_Px / rtb_SinCos_o1);

  /* Gain: '<S35>/Unit Conversion' incorporates:
   *  Constant: '<S32>/ref_pos'
   */
  rtb_Gain = navigator_P.UnitConversion_Gain_c * navigator_P.ref_pos_Value_c;

  /* Trigonometry: '<S32>/SinCos' */
  rtb_SinCos_o1 = sin(rtb_Gain);
  rtb_SinCos_o2 = cos(rtb_Gain);

  /* Product: '<S32>/dEast' incorporates:
   *  Constant: '<S34>/Constant3'
   *  Product: '<S34>/Product4'
   *  Trigonometry: '<S34>/Trigonometric Function'
   *  Trigonometry: '<S34>/Trigonometric Function2'
   */
  rtb_Pz = 1.0 / rt_atan2d_snf(navigator_P.Constant3_Value_o, rtb_Px * cos
    (rtb_Pz)) * rtb_UnitConversion_g_idx_0;

  /* Sum: '<S1>/Sum2' incorporates:
   *  Product: '<S32>/x*cos'
   *  Product: '<S32>/x*sin'
   *  Product: '<S32>/y*cos'
   *  Product: '<S32>/y*sin'
   *  Sum: '<S32>/Sum2'
   *  Sum: '<S32>/Sum3'
   */
  rtb_PositionError_idx = rtb_Px_k - (rtb_Py_c * rtb_SinCos_o2 + rtb_Pz *
    rtb_SinCos_o1);
  rtb_UnitConversion_g_idx = rtb_Py - (rtb_Pz * rtb_SinCos_o2 - rtb_Py_c *
    rtb_SinCos_o1);

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S4>/Constant'
   *  Constant: '<S5>/Constant'
   *  DotProduct: '<S2>/Dot Product'
   *  Product: '<S7>/Divide'
   *  Product: '<S7>/Product'
   *  Sqrt: '<S2>/Sqrt'
   *  Sum: '<S18>/Sum'
   *  Sum: '<S1>/Sum2'
   *  Sum: '<S29>/Sum'
   *  UnaryMinus: '<S18>/Ze2height'
   *  UnaryMinus: '<S29>/Ze2height'
   */
  if (sqrt(rtb_PositionError_idx * rtb_PositionError_idx +
           rtb_UnitConversion_g_idx * rtb_UnitConversion_g_idx) >=
      navigator_P.Switch_Threshold) {
    /* Sqrt: '<S7>/Sqrt' incorporates:
     *  DotProduct: '<S7>/Dot Product'
     */
    rtb_Gain = sqrt(rtb_PositionError_idx * rtb_PositionError_idx +
                    rtb_UnitConversion_g_idx * rtb_UnitConversion_g_idx);

    /* Saturate: '<S7>/Saturation' */
    if (rtb_Gain >= navigator_P.Saturation_UpperSat) {
      rtb_UnitConversion = navigator_P.Saturation_UpperSat;
    } else if (rtb_Gain <= navigator_P.Saturation_LowerSat) {
      rtb_UnitConversion = navigator_P.Saturation_LowerSat;
    } else {
      rtb_UnitConversion = rtb_Gain;
    }

    /* End of Saturate: '<S7>/Saturation' */
    rtb_Px = rtb_PositionError_idx / rtb_Gain * rtb_UnitConversion;
    rtb_UnitConversion_g_idx = rtb_UnitConversion_g_idx / rtb_Gain *
      rtb_UnitConversion;
    rtb_PositionError_idx = -(rtb_DataTypeConversion1[2] +
      navigator_P.Constant_Value_f1) - (-(rtb_DataTypeConversion1[7] +
      navigator_P.Constant_Value_kn));
  } else {
    rtb_Px = navigator_P.Constant1_Value[0];
    rtb_UnitConversion_g_idx = navigator_P.Constant1_Value[1];
    rtb_PositionError_idx = navigator_P.Constant1_Value[2];
  }

  /* End of Switch: '<S2>/Switch' */

  /* Outport: '<Root>/Out' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   */
  navigator_Y.Out[0] = rtb_XYZ_idx;
  navigator_Y.Out[1] = rtb_XYZ_idx_0;
  navigator_Y.Out[2] = (real32_T)rtb_DataTypeConversion1[7];
  navigator_Y.Out[3] = (real32_T)rtb_Px;
  navigator_Y.Out[4] = (real32_T)rtb_UnitConversion_g_idx;
  navigator_Y.Out[5] = (real32_T)rtb_PositionError_idx;
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
