/*
 * File: navigator.cpp
 *
 * Code generated for Simulink model 'navigator'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Wed Mar 18 18:11:14 2015
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
  real_T rtb_SinCos_o2;
  real_T rtb_Px_l;
  real_T rtb_SinCos_o1;
  real_T rtb_Pz;
  real_T rtb_UnitConversion;
  real_T rtb_Sum1_k;
  real_T rtb_Sum_o;
  real_T rtb_Py_c;
  int16_T i;
  real32_T rtb_DataTypeConversion_idx;
  real32_T rtb_DataTypeConversion_idx_0;
  real_T rtb_UnitConversion_g_idx;
  real_T rtb_UnitConversion_g_idx_0;

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/In'
   */
  for (i = 0; i < 15; i++) {
    rtb_DataTypeConversion1[i] = navigator_U.In[i];
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion1' */

  /* Math: '<S18>/Math Function1' incorporates:
   *  Constant: '<S18>/Constant5'
   */
  rtb_SinCos_o2 = rt_remd_snf(rtb_DataTypeConversion1[0],
    navigator_P.Constant5_Value);

  /* Product: '<S18>/Product2' incorporates:
   *  Constant: '<S18>/Constant4'
   */
  rtb_UnitConversion_g_idx = rtb_SinCos_o2 / navigator_P.Constant4_Value;

  /* Rounding: '<S18>/Rounding Function1' */
  if (rtb_UnitConversion_g_idx < 0.0) {
    rtb_UnitConversion_g_idx = ceil(rtb_UnitConversion_g_idx);
  } else {
    rtb_UnitConversion_g_idx = floor(rtb_UnitConversion_g_idx);
  }

  /* Sum: '<S18>/Sum1' incorporates:
   *  Gain: '<S18>/Gain3'
   *  Rounding: '<S18>/Rounding Function1'
   */
  rtb_SinCos_o2 -= navigator_P.Gain3_Gain * rtb_UnitConversion_g_idx;

  /* Product: '<S18>/Product' incorporates:
   *  Constant: '<S18>/Constant1'
   */
  rtb_Px_l = rtb_SinCos_o2 / navigator_P.Constant1_Value_h;

  /* Rounding: '<S18>/Rounding Function' */
  if (rtb_Px_l < 0.0) {
    rtb_UnitConversion_g_idx = ceil(rtb_Px_l);
  } else {
    rtb_UnitConversion_g_idx = floor(rtb_Px_l);
  }

  /* Gain: '<S18>/Gain1' */
  rtb_Px_l *= navigator_P.Gain1_Gain;

  /* Product: '<S18>/Product1' */
  rtb_Px_l *= rtb_Px_l;

  /* Sqrt: '<S18>/sqrt' */
  rtb_Px_l = sqrt(rtb_Px_l);

  /* Rounding: '<S18>/Rounding Function2' */
  if (rtb_Px_l < 0.0) {
    rtb_Px_l = ceil(rtb_Px_l);
  } else {
    rtb_Px_l = floor(rtb_Px_l);
  }

  /* End of Rounding: '<S18>/Rounding Function2' */

  /* Gain: '<S18>/Gain2' */
  rtb_Px_l *= navigator_P.Gain2_Gain;

  /* Sum: '<S18>/Sum2' incorporates:
   *  Constant: '<S18>/Constant3'
   *  Gain: '<S18>/Gain'
   *  Math: '<S18>/Math Function2'
   *  Product: '<S18>/Product3'
   *  Rounding: '<S18>/Rounding Function'
   */
  rtb_SinCos_o2 = (rtb_SinCos_o2 - navigator_P.Gain_Gain *
                   rtb_UnitConversion_g_idx) - rtb_Px_l * rt_remd_snf
    (rtb_SinCos_o2, navigator_P.Constant3_Value);

  /* Math: '<S19>/Math Function2' incorporates:
   *  Constant: '<S19>/Constant2'
   *  DataTypeConversion: '<S18>/Data Type Conversion'
   *  Gain: '<S18>/Gain4'
   *  Logic: '<S18>/Logical Operator1'
   *  Sum: '<S18>/Sum3'
   */
  rtb_SinCos_o1 = rt_remd_snf((real_T)(rtb_Px_l != 0.0) * navigator_P.Gain4_Gain
    + rtb_DataTypeConversion1[1], navigator_P.Constant2_Value);

  /* Product: '<S19>/Product' incorporates:
   *  Constant: '<S19>/Constant'
   */
  rtb_UnitConversion_g_idx = rtb_SinCos_o1 / navigator_P.Constant_Value;

  /* Rounding: '<S19>/Rounding Function' */
  if (rtb_UnitConversion_g_idx < 0.0) {
    rtb_UnitConversion_g_idx = ceil(rtb_UnitConversion_g_idx);
  } else {
    rtb_UnitConversion_g_idx = floor(rtb_UnitConversion_g_idx);
  }

  /* Sum: '<S19>/Sum2' incorporates:
   *  Gain: '<S19>/Gain'
   *  Rounding: '<S19>/Rounding Function'
   */
  rtb_SinCos_o1 -= navigator_P.Gain_Gain_h * rtb_UnitConversion_g_idx;

  /* Gain: '<S21>/Unit Conversion' incorporates:
   *  Constant: '<S17>/initial_pos'
   *  Sum: '<S17>/Sum1'
   */
  rtb_UnitConversion_g_idx = (rtb_SinCos_o2 - navigator_P.initial_pos_Value_l[0])
    * navigator_P.UnitConversion_Gain;
  rtb_UnitConversion_g_idx_0 = (rtb_SinCos_o1 - navigator_P.initial_pos_Value_l
    [1]) * navigator_P.UnitConversion_Gain;

  /* Sum: '<S26>/Sum' incorporates:
   *  Constant: '<S26>/Constant'
   *  Constant: '<S26>/f'
   */
  rtb_SinCos_o1 = navigator_P.f_Value - navigator_P.Constant_Value_om;

  /* Sqrt: '<S27>/sqrt' incorporates:
   *  Constant: '<S27>/Constant'
   *  Product: '<S27>/Product1'
   *  Sum: '<S27>/Sum1'
   */
  rtb_SinCos_o1 = sqrt(navigator_P.Constant_Value_o - rtb_SinCos_o1 *
                       rtb_SinCos_o1);

  /* Gain: '<S24>/Unit Conversion' incorporates:
   *  Constant: '<S17>/initial_latg'
   */
  rtb_Px_l = navigator_P.UnitConversion_Gain_o * navigator_P.initial_latg_Value;

  /* Trigonometry: '<S25>/Trigonometric Function1' */
  rtb_SinCos_o2 = sin(rtb_Px_l);

  /* Sum: '<S25>/Sum1' incorporates:
   *  Constant: '<S25>/Constant'
   *  Product: '<S25>/Product1'
   */
  rtb_SinCos_o2 = navigator_P.Constant_Value_e - rtb_SinCos_o1 * rtb_SinCos_o1 *
    rtb_SinCos_o2 * rtb_SinCos_o2;

  /* Product: '<S22>/Product1' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Sqrt: '<S22>/sqrt'
   */
  rtb_Pz = navigator_P.Constant1_Value_b / sqrt(rtb_SinCos_o2);

  /* Product: '<S20>/dNorth' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S22>/Constant2'
   *  Product: '<S22>/Product2'
   *  Product: '<S22>/Product3'
   *  Sum: '<S22>/Sum1'
   *  Trigonometry: '<S22>/Trigonometric Function1'
   */
  rtb_SinCos_o1 = rtb_UnitConversion_g_idx / rt_atan2d_snf
    (navigator_P.Constant2_Value_o, (navigator_P.Constant_Value_b -
      rtb_SinCos_o1 * rtb_SinCos_o1) * rtb_Pz / rtb_SinCos_o2);

  /* Gain: '<S23>/Unit Conversion' incorporates:
   *  Constant: '<S20>/ref_pos'
   */
  rtb_UnitConversion = navigator_P.UnitConversion_Gain_b *
    navigator_P.ref_pos_Value;

  /* Trigonometry: '<S20>/SinCos' */
  rtb_SinCos_o2 = sin(rtb_UnitConversion);
  rtb_Sum1_k = cos(rtb_UnitConversion);

  /* Product: '<S20>/dEast' incorporates:
   *  Constant: '<S22>/Constant3'
   *  Product: '<S22>/Product4'
   *  Trigonometry: '<S22>/Trigonometric Function'
   *  Trigonometry: '<S22>/Trigonometric Function2'
   */
  rtb_Pz = 1.0 / rt_atan2d_snf(navigator_P.Constant3_Value_j, rtb_Pz * cos
    (rtb_Px_l)) * rtb_UnitConversion_g_idx_0;

  /* Gain: '<S2>/Gain1' */
  rtb_Px_l = navigator_P.Gain1_Gain_m * rtb_DataTypeConversion1[4];

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/dt'
   *  Product: '<S1>/Product'
   *  Product: '<S1>/Product2'
   *  Product: '<S20>/x*cos'
   *  Product: '<S20>/y*sin'
   *  Sum: '<S20>/Sum2'
   *  Trigonometry: '<S1>/Trigonometric Function'
   */
  rtb_Sum_o = (rtb_SinCos_o1 * rtb_Sum1_k + rtb_Pz * rtb_SinCos_o2) +
    rtb_DataTypeConversion1[3] * cos(rtb_Px_l) * navigator_P.dt_Value;

  /* Gain: '<S12>/Unit Conversion' incorporates:
   *  Constant: '<S8>/ref_pos'
   */
  rtb_UnitConversion_g_idx = navigator_P.UnitConversion_Gain_f *
    navigator_P.ref_pos_Value_n;

  /* Trigonometry: '<S8>/SinCos' */
  rtb_Py_c = sin(rtb_UnitConversion_g_idx);
  rtb_UnitConversion = cos(rtb_UnitConversion_g_idx);

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S1>/dt1'
   *  Product: '<S1>/Product1'
   *  Product: '<S1>/Product3'
   *  Product: '<S20>/x*sin'
   *  Product: '<S20>/y*cos'
   *  Sum: '<S20>/Sum3'
   *  Trigonometry: '<S1>/Trigonometric Function1'
   */
  rtb_Sum1_k = (rtb_Pz * rtb_Sum1_k - rtb_SinCos_o1 * rtb_SinCos_o2) +
    rtb_DataTypeConversion1[3] * sin(rtb_Px_l) * navigator_P.dt1_Value;

  /* Sum: '<S15>/Sum' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S15>/f'
   */
  rtb_Pz = navigator_P.f_Value_b - navigator_P.Constant_Value_p;

  /* Sqrt: '<S16>/sqrt' incorporates:
   *  Constant: '<S16>/Constant'
   *  Product: '<S16>/Product1'
   *  Sum: '<S16>/Sum1'
   */
  rtb_Pz = sqrt(navigator_P.Constant_Value_kd - rtb_Pz * rtb_Pz);

  /* Gain: '<S13>/Unit Conversion' incorporates:
   *  Constant: '<S3>/initial_latg'
   */
  rtb_SinCos_o1 = navigator_P.UnitConversion_Gain_h *
    navigator_P.initial_latg_Value_n;

  /* Trigonometry: '<S14>/Trigonometric Function1' */
  rtb_Px_l = sin(rtb_SinCos_o1);

  /* Sum: '<S14>/Sum1' incorporates:
   *  Constant: '<S14>/Constant'
   *  Product: '<S14>/Product1'
   */
  rtb_Px_l = navigator_P.Constant_Value_k - rtb_Pz * rtb_Pz * rtb_Px_l *
    rtb_Px_l;

  /* Product: '<S11>/Product1' incorporates:
   *  Constant: '<S11>/Constant1'
   *  Sqrt: '<S11>/sqrt'
   */
  rtb_SinCos_o2 = navigator_P.Constant1_Value_f / sqrt(rtb_Px_l);

  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<S11>/Constant3'
   *  Constant: '<S3>/initial_pos'
   *  Gain: '<S10>/Unit Conversion'
   *  Product: '<S11>/Product4'
   *  Product: '<S8>/rad long '
   *  Product: '<S8>/x*sin'
   *  Product: '<S8>/y*cos'
   *  Sum: '<S8>/Sum1'
   *  Trigonometry: '<S11>/Trigonometric Function'
   *  Trigonometry: '<S11>/Trigonometric Function2'
   */
  rtb_UnitConversion_g_idx_0 = (rtb_Sum_o * rtb_Py_c + rtb_Sum1_k *
    rtb_UnitConversion) * rt_atan2d_snf(navigator_P.Constant3_Value_jt,
    rtb_SinCos_o2 * cos(rtb_SinCos_o1)) * navigator_P.UnitConversion_Gain_g +
    navigator_P.initial_pos_Value[1];

  /* Math: '<S7>/Math Function1' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/Constant2'
   *  Constant: '<S3>/initial_pos'
   *  Constant: '<S7>/Constant5'
   *  Gain: '<S10>/Unit Conversion'
   *  Product: '<S11>/Product2'
   *  Product: '<S11>/Product3'
   *  Product: '<S8>/rad lat'
   *  Product: '<S8>/x*cos'
   *  Product: '<S8>/y*sin'
   *  Sum: '<S11>/Sum1'
   *  Sum: '<S3>/Sum'
   *  Sum: '<S8>/Sum'
   *  Trigonometry: '<S11>/Trigonometric Function1'
   */
  rtb_UnitConversion = rt_remd_snf(rt_atan2d_snf(navigator_P.Constant2_Value_f,
                                    (navigator_P.Constant_Value_c - rtb_Pz *
    rtb_Pz) * rtb_SinCos_o2 / rtb_Px_l) * (rtb_Sum_o * rtb_UnitConversion -
    rtb_Sum1_k * rtb_Py_c) * navigator_P.UnitConversion_Gain_g +
    navigator_P.initial_pos_Value[0], navigator_P.Constant5_Value_e);

  /* Product: '<S7>/Product2' incorporates:
   *  Constant: '<S7>/Constant4'
   */
  rtb_UnitConversion_g_idx = rtb_UnitConversion / navigator_P.Constant4_Value_g;

  /* Rounding: '<S7>/Rounding Function1' */
  if (rtb_UnitConversion_g_idx < 0.0) {
    rtb_UnitConversion_g_idx = ceil(rtb_UnitConversion_g_idx);
  } else {
    rtb_UnitConversion_g_idx = floor(rtb_UnitConversion_g_idx);
  }

  /* Sum: '<S7>/Sum1' incorporates:
   *  Gain: '<S7>/Gain3'
   *  Rounding: '<S7>/Rounding Function1'
   */
  rtb_UnitConversion -= navigator_P.Gain3_Gain_l * rtb_UnitConversion_g_idx;

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  rtb_Py_c = rtb_UnitConversion / navigator_P.Constant1_Value_g;

  /* Rounding: '<S7>/Rounding Function' */
  if (rtb_Py_c < 0.0) {
    rtb_UnitConversion_g_idx = ceil(rtb_Py_c);
  } else {
    rtb_UnitConversion_g_idx = floor(rtb_Py_c);
  }

  /* Gain: '<S7>/Gain1' */
  rtb_Py_c *= navigator_P.Gain1_Gain_d;

  /* Product: '<S7>/Product1' */
  rtb_Py_c *= rtb_Py_c;

  /* Sqrt: '<S7>/sqrt' */
  rtb_Py_c = sqrt(rtb_Py_c);

  /* Rounding: '<S7>/Rounding Function2' */
  if (rtb_Py_c < 0.0) {
    rtb_Py_c = ceil(rtb_Py_c);
  } else {
    rtb_Py_c = floor(rtb_Py_c);
  }

  /* End of Rounding: '<S7>/Rounding Function2' */

  /* Gain: '<S7>/Gain2' */
  rtb_Py_c *= navigator_P.Gain2_Gain_p;

  /* Sum: '<S7>/Sum2' incorporates:
   *  Constant: '<S7>/Constant3'
   *  Gain: '<S7>/Gain'
   *  Math: '<S7>/Math Function2'
   *  Product: '<S7>/Product3'
   *  Rounding: '<S7>/Rounding Function'
   */
  rtb_UnitConversion = (rtb_UnitConversion - navigator_P.Gain_Gain_c *
                        rtb_UnitConversion_g_idx) - rtb_Py_c * rt_remd_snf
    (rtb_UnitConversion, navigator_P.Constant3_Value_h);

  /* Math: '<S9>/Math Function2' incorporates:
   *  Constant: '<S9>/Constant2'
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   *  Gain: '<S7>/Gain4'
   *  Logic: '<S7>/Logical Operator1'
   *  Sum: '<S7>/Sum3'
   */
  rtb_Py_c = rt_remd_snf((real_T)(rtb_Py_c != 0.0) * navigator_P.Gain4_Gain_j +
    rtb_UnitConversion_g_idx_0, navigator_P.Constant2_Value_e);

  /* Product: '<S9>/Product' incorporates:
   *  Constant: '<S9>/Constant'
   */
  rtb_UnitConversion_g_idx = rtb_Py_c / navigator_P.Constant_Value_d;

  /* Rounding: '<S9>/Rounding Function' */
  if (rtb_UnitConversion_g_idx < 0.0) {
    rtb_UnitConversion_g_idx = ceil(rtb_UnitConversion_g_idx);
  } else {
    rtb_UnitConversion_g_idx = floor(rtb_UnitConversion_g_idx);
  }

  /* Sum: '<S9>/Sum2' incorporates:
   *  Gain: '<S9>/Gain'
   *  Rounding: '<S9>/Rounding Function'
   */
  rtb_Py_c -= navigator_P.Gain_Gain_j * rtb_UnitConversion_g_idx;

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  rtb_DataTypeConversion_idx = (real32_T)rtb_UnitConversion;
  rtb_DataTypeConversion_idx_0 = (real32_T)rtb_Py_c;

  /* Math: '<S29>/Math Function1' incorporates:
   *  Constant: '<S29>/Constant5'
   */
  rtb_Py_c = rt_remd_snf(rtb_DataTypeConversion1[5],
    navigator_P.Constant5_Value_b);

  /* Product: '<S29>/Product2' incorporates:
   *  Constant: '<S29>/Constant4'
   */
  rtb_UnitConversion_g_idx = rtb_Py_c / navigator_P.Constant4_Value_g4;

  /* Rounding: '<S29>/Rounding Function1' */
  if (rtb_UnitConversion_g_idx < 0.0) {
    rtb_UnitConversion_g_idx = ceil(rtb_UnitConversion_g_idx);
  } else {
    rtb_UnitConversion_g_idx = floor(rtb_UnitConversion_g_idx);
  }

  /* Sum: '<S29>/Sum1' incorporates:
   *  Gain: '<S29>/Gain3'
   *  Rounding: '<S29>/Rounding Function1'
   */
  rtb_Py_c -= navigator_P.Gain3_Gain_o * rtb_UnitConversion_g_idx;

  /* Product: '<S29>/Product' incorporates:
   *  Constant: '<S29>/Constant1'
   */
  rtb_Pz = rtb_Py_c / navigator_P.Constant1_Value_d;

  /* Rounding: '<S29>/Rounding Function' */
  if (rtb_Pz < 0.0) {
    rtb_UnitConversion_g_idx = ceil(rtb_Pz);
  } else {
    rtb_UnitConversion_g_idx = floor(rtb_Pz);
  }

  /* Gain: '<S29>/Gain1' */
  rtb_Pz *= navigator_P.Gain1_Gain_i;

  /* Product: '<S29>/Product1' */
  rtb_Pz *= rtb_Pz;

  /* Sqrt: '<S29>/sqrt' */
  rtb_Pz = sqrt(rtb_Pz);

  /* Rounding: '<S29>/Rounding Function2' */
  if (rtb_Pz < 0.0) {
    rtb_Pz = ceil(rtb_Pz);
  } else {
    rtb_Pz = floor(rtb_Pz);
  }

  /* End of Rounding: '<S29>/Rounding Function2' */

  /* Gain: '<S29>/Gain2' */
  rtb_Pz *= navigator_P.Gain2_Gain_k;

  /* Sum: '<S29>/Sum2' incorporates:
   *  Constant: '<S29>/Constant3'
   *  Gain: '<S29>/Gain'
   *  Math: '<S29>/Math Function2'
   *  Product: '<S29>/Product3'
   *  Rounding: '<S29>/Rounding Function'
   */
  rtb_Py_c = (rtb_Py_c - navigator_P.Gain_Gain_k * rtb_UnitConversion_g_idx) -
    rtb_Pz * rt_remd_snf(rtb_Py_c, navigator_P.Constant3_Value_c);

  /* Math: '<S30>/Math Function2' incorporates:
   *  Constant: '<S30>/Constant2'
   *  DataTypeConversion: '<S29>/Data Type Conversion'
   *  Gain: '<S29>/Gain4'
   *  Logic: '<S29>/Logical Operator1'
   *  Sum: '<S29>/Sum3'
   */
  rtb_Pz = rt_remd_snf((real_T)(rtb_Pz != 0.0) * navigator_P.Gain4_Gain_i +
                       rtb_DataTypeConversion1[6], navigator_P.Constant2_Value_h);

  /* Product: '<S30>/Product' incorporates:
   *  Constant: '<S30>/Constant'
   */
  rtb_UnitConversion_g_idx = rtb_Pz / navigator_P.Constant_Value_kc;

  /* Rounding: '<S30>/Rounding Function' */
  if (rtb_UnitConversion_g_idx < 0.0) {
    rtb_UnitConversion_g_idx = ceil(rtb_UnitConversion_g_idx);
  } else {
    rtb_UnitConversion_g_idx = floor(rtb_UnitConversion_g_idx);
  }

  /* Sum: '<S30>/Sum2' incorporates:
   *  Gain: '<S30>/Gain'
   *  Rounding: '<S30>/Rounding Function'
   */
  rtb_Pz -= navigator_P.Gain_Gain_kt * rtb_UnitConversion_g_idx;

  /* Gain: '<S32>/Unit Conversion' incorporates:
   *  Constant: '<S28>/initial_pos'
   *  Sum: '<S28>/Sum1'
   */
  rtb_UnitConversion_g_idx = (rtb_Py_c - navigator_P.initial_pos_Value_h[0]) *
    navigator_P.UnitConversion_Gain_gs;
  rtb_UnitConversion_g_idx_0 = (rtb_Pz - navigator_P.initial_pos_Value_h[1]) *
    navigator_P.UnitConversion_Gain_gs;

  /* Sum: '<S37>/Sum' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/f'
   */
  rtb_Py_c = navigator_P.f_Value_j - navigator_P.Constant_Value_n;

  /* Sqrt: '<S38>/sqrt' incorporates:
   *  Constant: '<S38>/Constant'
   *  Product: '<S38>/Product1'
   *  Sum: '<S38>/Sum1'
   */
  rtb_Py_c = sqrt(navigator_P.Constant_Value_m - rtb_Py_c * rtb_Py_c);

  /* Gain: '<S35>/Unit Conversion' incorporates:
   *  Constant: '<S28>/initial_latg'
   */
  rtb_Pz = navigator_P.UnitConversion_Gain_i * navigator_P.initial_latg_Value_i;

  /* Trigonometry: '<S36>/Trigonometric Function1' */
  rtb_SinCos_o1 = sin(rtb_Pz);

  /* Sum: '<S36>/Sum1' incorporates:
   *  Constant: '<S36>/Constant'
   *  Product: '<S36>/Product1'
   */
  rtb_SinCos_o1 = navigator_P.Constant_Value_ks - rtb_Py_c * rtb_Py_c *
    rtb_SinCos_o1 * rtb_SinCos_o1;

  /* Product: '<S33>/Product1' incorporates:
   *  Constant: '<S33>/Constant1'
   *  Sqrt: '<S33>/sqrt'
   */
  rtb_Px_l = navigator_P.Constant1_Value_o / sqrt(rtb_SinCos_o1);

  /* Product: '<S31>/dNorth' incorporates:
   *  Constant: '<S33>/Constant'
   *  Constant: '<S33>/Constant2'
   *  Product: '<S33>/Product2'
   *  Product: '<S33>/Product3'
   *  Sum: '<S33>/Sum1'
   *  Trigonometry: '<S33>/Trigonometric Function1'
   */
  rtb_Py_c = rtb_UnitConversion_g_idx / rt_atan2d_snf
    (navigator_P.Constant2_Value_n, (navigator_P.Constant_Value_f - rtb_Py_c *
      rtb_Py_c) * rtb_Px_l / rtb_SinCos_o1);

  /* Gain: '<S34>/Unit Conversion' incorporates:
   *  Constant: '<S31>/ref_pos'
   */
  rtb_UnitConversion_g_idx = navigator_P.UnitConversion_Gain_c *
    navigator_P.ref_pos_Value_c;

  /* Trigonometry: '<S31>/SinCos' */
  rtb_SinCos_o1 = sin(rtb_UnitConversion_g_idx);
  rtb_SinCos_o2 = cos(rtb_UnitConversion_g_idx);

  /* Product: '<S31>/dEast' incorporates:
   *  Constant: '<S33>/Constant3'
   *  Product: '<S33>/Product4'
   *  Trigonometry: '<S33>/Trigonometric Function'
   *  Trigonometry: '<S33>/Trigonometric Function2'
   */
  rtb_Pz = 1.0 / rt_atan2d_snf(navigator_P.Constant3_Value_o, rtb_Px_l * cos
    (rtb_Pz)) * rtb_UnitConversion_g_idx_0;

  /* Sum: '<S1>/Sum2' incorporates:
   *  Product: '<S31>/x*cos'
   *  Product: '<S31>/x*sin'
   *  Product: '<S31>/y*cos'
   *  Product: '<S31>/y*sin'
   *  Sum: '<S31>/Sum2'
   *  Sum: '<S31>/Sum3'
   */
  rtb_UnitConversion_g_idx_0 = rtb_Sum_o - (rtb_Py_c * rtb_SinCos_o2 + rtb_Pz *
    rtb_SinCos_o1);
  rtb_Px_l = rtb_Sum1_k - (rtb_Pz * rtb_SinCos_o2 - rtb_Py_c * rtb_SinCos_o1);

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S4>/Constant'
   *  Constant: '<S5>/Constant'
   *  DotProduct: '<S1>/Dot Product'
   *  Product: '<S6>/Divide'
   *  Product: '<S6>/Product'
   *  Sqrt: '<S1>/Sqrt'
   *  Sum: '<S17>/Sum'
   *  Sum: '<S1>/Sum2'
   *  Sum: '<S28>/Sum'
   *  UnaryMinus: '<S17>/Ze2height'
   *  UnaryMinus: '<S28>/Ze2height'
   */
  if (sqrt(rtb_UnitConversion_g_idx_0 * rtb_UnitConversion_g_idx_0 + rtb_Px_l *
           rtb_Px_l) >= navigator_P.Switch_Threshold) {
    /* Sqrt: '<S6>/Sqrt' incorporates:
     *  DotProduct: '<S6>/Dot Product'
     */
    rtb_UnitConversion_g_idx = sqrt(rtb_UnitConversion_g_idx_0 *
      rtb_UnitConversion_g_idx_0 + rtb_Px_l * rtb_Px_l);

    /* Saturate: '<S6>/Saturation' */
    if (rtb_UnitConversion_g_idx >= navigator_P.Saturation_UpperSat) {
      rtb_UnitConversion = navigator_P.Saturation_UpperSat;
    } else if (rtb_UnitConversion_g_idx <= navigator_P.Saturation_LowerSat) {
      rtb_UnitConversion = navigator_P.Saturation_LowerSat;
    } else {
      rtb_UnitConversion = rtb_UnitConversion_g_idx;
    }

    /* End of Saturate: '<S6>/Saturation' */
    rtb_UnitConversion_g_idx_0 = rtb_UnitConversion_g_idx_0 /
      rtb_UnitConversion_g_idx * rtb_UnitConversion;
    rtb_Px_l = rtb_Px_l / rtb_UnitConversion_g_idx * rtb_UnitConversion;
    rtb_UnitConversion_g_idx = -(rtb_DataTypeConversion1[2] +
      navigator_P.Constant_Value_f1) - (-(rtb_DataTypeConversion1[7] +
      navigator_P.Constant_Value_kn));
  } else {
    rtb_UnitConversion_g_idx_0 = navigator_P.Constant1_Value[0];
    rtb_Px_l = navigator_P.Constant1_Value[1];
    rtb_UnitConversion_g_idx = navigator_P.Constant1_Value[2];
  }

  /* End of Switch: '<S1>/Switch' */

  /* Outport: '<Root>/Out' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   */
  navigator_Y.Out[0] = rtb_DataTypeConversion_idx;
  navigator_Y.Out[1] = rtb_DataTypeConversion_idx_0;
  navigator_Y.Out[2] = (real32_T)rtb_DataTypeConversion1[7];
  navigator_Y.Out[3] = (real32_T)rtb_UnitConversion_g_idx_0;
  navigator_Y.Out[4] = (real32_T)rtb_Px_l;
  navigator_Y.Out[5] = (real32_T)rtb_UnitConversion_g_idx;
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
