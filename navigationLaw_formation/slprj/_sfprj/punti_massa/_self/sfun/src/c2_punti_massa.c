/* Include files */

#include <stddef.h>
#include "blas.h"
#include "punti_massa_sfun.h"
#include "c2_punti_massa.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "punti_massa_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[10] = { "d", "nargin", "nargout",
  "X_North", "X_East", "X_East_WP", "X_North_WP", "X_East_In", "X_North_In", "y"
};

/* Function Declarations */
static void initialize_c2_punti_massa(SFc2_punti_massaInstanceStruct
  *chartInstance);
static void initialize_params_c2_punti_massa(SFc2_punti_massaInstanceStruct
  *chartInstance);
static void enable_c2_punti_massa(SFc2_punti_massaInstanceStruct *chartInstance);
static void disable_c2_punti_massa(SFc2_punti_massaInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_punti_massa
  (SFc2_punti_massaInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_punti_massa
  (SFc2_punti_massaInstanceStruct *chartInstance);
static void set_sim_state_c2_punti_massa(SFc2_punti_massaInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_punti_massa(SFc2_punti_massaInstanceStruct
  *chartInstance);
static void sf_c2_punti_massa(SFc2_punti_massaInstanceStruct *chartInstance);
static void initSimStructsc2_punti_massa(SFc2_punti_massaInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_punti_massaInstanceStruct *chartInstance,
  const mxArray *c2_y, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_punti_massaInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_punti_massaInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[2]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(const mxArray **c2_info);
static const mxArray *c2_emlrt_marshallOut(char * c2_u);
static const mxArray *c2_b_emlrt_marshallOut(uint32_T c2_u);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_punti_massaInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_punti_massaInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_punti_massa, const char_T
  *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_punti_massaInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_punti_massaInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_punti_massa(SFc2_punti_massaInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_punti_massa = 0U;
}

static void initialize_params_c2_punti_massa(SFc2_punti_massaInstanceStruct
  *chartInstance)
{
}

static void enable_c2_punti_massa(SFc2_punti_massaInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_punti_massa(SFc2_punti_massaInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_punti_massa
  (SFc2_punti_massaInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_punti_massa
  (SFc2_punti_massaInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T *c2_d_y;
  c2_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  c2_hoistedGlobal = *c2_d_y;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_punti_massa;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_punti_massa(SFc2_punti_massaInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_y;
  c2_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "y");
  chartInstance->c2_is_active_c2_punti_massa = c2_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_punti_massa");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_punti_massa(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_punti_massa(SFc2_punti_massaInstanceStruct
  *chartInstance)
{
}

static void sf_c2_punti_massa(SFc2_punti_massaInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_f_hoistedGlobal;
  real_T c2_X_North;
  real_T c2_X_East;
  real_T c2_X_East_WP;
  real_T c2_X_North_WP;
  real_T c2_X_East_In;
  real_T c2_X_North_In;
  uint32_T c2_debug_family_var_map[10];
  real_T c2_d[2];
  real_T c2_nargin = 6.0;
  real_T c2_nargout = 1.0;
  real_T c2_y;
  int32_T c2_i0;
  static char_T c2_cv0[2] = { 'o', 'n' };

  char_T c2_u[2];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i1;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  int32_T c2_i2;
  static char_T c2_cv1[4] = { 'r', '-', '-', 'o' };

  char_T c2_d_u[4];
  const mxArray *c2_e_y = NULL;
  int32_T c2_i3;
  static char_T c2_cv2[9] = { 'L', 'i', 'n', 'e', 'W', 'i', 'd', 't', 'h' };

  char_T c2_e_u[9];
  const mxArray *c2_f_y = NULL;
  real_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  int32_T c2_i4;
  static char_T c2_cv3[10] = { 'M', 'a', 'r', 'k', 'e', 'r', 'S', 'i', 'z', 'e'
  };

  char_T c2_g_u[10];
  const mxArray *c2_h_y = NULL;
  real_T c2_h_u;
  const mxArray *c2_i_y = NULL;
  int32_T c2_i5;
  static char_T c2_cv4[15] = { 'M', 'a', 'r', 'k', 'e', 'r', 'E', 'd', 'g', 'e',
    'C', 'o', 'l', 'o', 'r' };

  char_T c2_i_u[15];
  const mxArray *c2_j_y = NULL;
  char_T c2_j_u;
  const mxArray *c2_k_y = NULL;
  int32_T c2_i6;
  static real_T c2_dv0[4] = { -10.5, 10.5, -10.5, 10.5 };

  real_T c2_k_u[4];
  const mxArray *c2_l_y = NULL;
  real_T c2_l_u;
  const mxArray *c2_m_y = NULL;
  real_T c2_m_u;
  const mxArray *c2_n_y = NULL;
  int32_T c2_i7;
  static char_T c2_cv5[4] = { 'b', '-', '-', 'o' };

  char_T c2_n_u[4];
  const mxArray *c2_o_y = NULL;
  int32_T c2_i8;
  char_T c2_o_u[9];
  const mxArray *c2_p_y = NULL;
  real_T c2_p_u;
  const mxArray *c2_q_y = NULL;
  int32_T c2_i9;
  char_T c2_q_u[10];
  const mxArray *c2_r_y = NULL;
  real_T c2_r_u;
  const mxArray *c2_s_y = NULL;
  int32_T c2_i10;
  char_T c2_s_u[15];
  const mxArray *c2_t_y = NULL;
  char_T c2_t_u;
  const mxArray *c2_u_y = NULL;
  real_T c2_u_u;
  const mxArray *c2_v_y = NULL;
  real_T c2_v_u;
  const mxArray *c2_w_y = NULL;
  int32_T c2_i11;
  static char_T c2_cv6[4] = { '-', '-', 'g', 's' };

  char_T c2_w_u[4];
  const mxArray *c2_x_y = NULL;
  int32_T c2_i12;
  char_T c2_x_u[9];
  const mxArray *c2_y_y = NULL;
  real_T c2_y_u;
  const mxArray *c2_ab_y = NULL;
  int32_T c2_i13;
  char_T c2_ab_u[10];
  const mxArray *c2_bb_y = NULL;
  real_T c2_bb_u;
  const mxArray *c2_cb_y = NULL;
  int32_T c2_i14;
  char_T c2_cb_u[15];
  const mxArray *c2_db_y = NULL;
  char_T c2_db_u;
  const mxArray *c2_eb_y = NULL;
  int32_T c2_i15;
  static char_T c2_cv7[15] = { 'M', 'a', 'r', 'k', 'e', 'r', 'F', 'a', 'c', 'e',
    'C', 'o', 'l', 'o', 'r' };

  char_T c2_eb_u[15];
  const mxArray *c2_fb_y = NULL;
  int32_T c2_i16;
  real_T c2_fb_u[3];
  const mxArray *c2_gb_y = NULL;
  real_T c2_gb_u;
  const mxArray *c2_hb_y = NULL;
  real_T *c2_b_X_North_In;
  real_T *c2_b_X_East_In;
  real_T *c2_b_X_North_WP;
  real_T *c2_b_X_East_WP;
  real_T *c2_b_X_East;
  real_T *c2_b_X_North;
  real_T *c2_ib_y;
  c2_b_X_North_In = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_b_X_East_In = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_X_North_WP = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_X_East_WP = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_ib_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_X_East = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_X_North = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_b_X_North, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_X_East, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_ib_y, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_b_X_East_WP, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_b_X_North_WP, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_b_X_East_In, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_b_X_North_In, 6U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_X_North;
  c2_b_hoistedGlobal = *c2_b_X_East;
  c2_c_hoistedGlobal = *c2_b_X_East_WP;
  c2_d_hoistedGlobal = *c2_b_X_North_WP;
  c2_e_hoistedGlobal = *c2_b_X_East_In;
  c2_f_hoistedGlobal = *c2_b_X_North_In;
  c2_X_North = c2_hoistedGlobal;
  c2_X_East = c2_b_hoistedGlobal;
  c2_X_East_WP = c2_c_hoistedGlobal;
  c2_X_North_WP = c2_d_hoistedGlobal;
  c2_X_East_In = c2_e_hoistedGlobal;
  c2_X_North_In = c2_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_d, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_X_North, 3U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_X_East, 4U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_X_East_WP, 5U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_X_North_WP, 6U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_X_East_In, 7U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_X_North_In, 8U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_y, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_y = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  for (c2_i0 = 0; c2_i0 < 2; c2_i0++) {
    c2_u[c2_i0] = c2_cv0[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("hold", 0U, 1U, 14, c2_b_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
    c2_d[c2_i1] = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_b_u = c2_X_East_In;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  c2_c_u = c2_X_North_In;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  for (c2_i2 = 0; c2_i2 < 4; c2_i2++) {
    c2_d_u[c2_i2] = c2_cv1[c2_i2];
  }

  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_d_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  for (c2_i3 = 0; c2_i3 < 9; c2_i3++) {
    c2_e_u[c2_i3] = c2_cv2[c2_i3];
  }

  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_e_u, 10, 0U, 1U, 0U, 2, 1, 9),
                FALSE);
  c2_f_u = 2.0;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  for (c2_i4 = 0; c2_i4 < 10; c2_i4++) {
    c2_g_u[c2_i4] = c2_cv3[c2_i4];
  }

  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_g_u, 10, 0U, 1U, 0U, 2, 1, 10),
                FALSE);
  c2_h_u = 2.0;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  for (c2_i5 = 0; c2_i5 < 15; c2_i5++) {
    c2_i_u[c2_i5] = c2_cv4[c2_i5];
  }

  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", c2_i_u, 10, 0U, 1U, 0U, 2, 1, 15),
                FALSE);
  c2_j_u = 'r';
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_j_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("plot", 0U, 9U, 14, c2_c_y, 14, c2_d_y, 14, c2_e_y, 14,
                    c2_f_y, 14, c2_g_y, 14, c2_h_y, 14, c2_i_y, 14, c2_j_y, 14,
                    c2_k_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  for (c2_i6 = 0; c2_i6 < 4; c2_i6++) {
    c2_k_u[c2_i6] = c2_dv0[c2_i6];
  }

  c2_l_y = NULL;
  sf_mex_assign(&c2_l_y, sf_mex_create("y", c2_k_u, 0, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("axis", 0U, 1U, 14, c2_l_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_l_u = c2_X_East_WP;
  c2_m_y = NULL;
  sf_mex_assign(&c2_m_y, sf_mex_create("y", &c2_l_u, 0, 0U, 0U, 0U, 0), FALSE);
  c2_m_u = c2_X_North_WP;
  c2_n_y = NULL;
  sf_mex_assign(&c2_n_y, sf_mex_create("y", &c2_m_u, 0, 0U, 0U, 0U, 0), FALSE);
  for (c2_i7 = 0; c2_i7 < 4; c2_i7++) {
    c2_n_u[c2_i7] = c2_cv5[c2_i7];
  }

  c2_o_y = NULL;
  sf_mex_assign(&c2_o_y, sf_mex_create("y", c2_n_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  for (c2_i8 = 0; c2_i8 < 9; c2_i8++) {
    c2_o_u[c2_i8] = c2_cv2[c2_i8];
  }

  c2_p_y = NULL;
  sf_mex_assign(&c2_p_y, sf_mex_create("y", c2_o_u, 10, 0U, 1U, 0U, 2, 1, 9),
                FALSE);
  c2_p_u = 2.0;
  c2_q_y = NULL;
  sf_mex_assign(&c2_q_y, sf_mex_create("y", &c2_p_u, 0, 0U, 0U, 0U, 0), FALSE);
  for (c2_i9 = 0; c2_i9 < 10; c2_i9++) {
    c2_q_u[c2_i9] = c2_cv3[c2_i9];
  }

  c2_r_y = NULL;
  sf_mex_assign(&c2_r_y, sf_mex_create("y", c2_q_u, 10, 0U, 1U, 0U, 2, 1, 10),
                FALSE);
  c2_r_u = 2.0;
  c2_s_y = NULL;
  sf_mex_assign(&c2_s_y, sf_mex_create("y", &c2_r_u, 0, 0U, 0U, 0U, 0), FALSE);
  for (c2_i10 = 0; c2_i10 < 15; c2_i10++) {
    c2_s_u[c2_i10] = c2_cv4[c2_i10];
  }

  c2_t_y = NULL;
  sf_mex_assign(&c2_t_y, sf_mex_create("y", c2_s_u, 10, 0U, 1U, 0U, 2, 1, 15),
                FALSE);
  c2_t_u = 'b';
  c2_u_y = NULL;
  sf_mex_assign(&c2_u_y, sf_mex_create("y", &c2_t_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("plot", 0U, 9U, 14, c2_m_y, 14, c2_n_y, 14, c2_o_y, 14,
                    c2_p_y, 14, c2_q_y, 14, c2_r_y, 14, c2_s_y, 14, c2_t_y, 14,
                    c2_u_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_u_u = c2_X_East;
  c2_v_y = NULL;
  sf_mex_assign(&c2_v_y, sf_mex_create("y", &c2_u_u, 0, 0U, 0U, 0U, 0), FALSE);
  c2_v_u = c2_X_North;
  c2_w_y = NULL;
  sf_mex_assign(&c2_w_y, sf_mex_create("y", &c2_v_u, 0, 0U, 0U, 0U, 0), FALSE);
  for (c2_i11 = 0; c2_i11 < 4; c2_i11++) {
    c2_w_u[c2_i11] = c2_cv6[c2_i11];
  }

  c2_x_y = NULL;
  sf_mex_assign(&c2_x_y, sf_mex_create("y", c2_w_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  for (c2_i12 = 0; c2_i12 < 9; c2_i12++) {
    c2_x_u[c2_i12] = c2_cv2[c2_i12];
  }

  c2_y_y = NULL;
  sf_mex_assign(&c2_y_y, sf_mex_create("y", c2_x_u, 10, 0U, 1U, 0U, 2, 1, 9),
                FALSE);
  c2_y_u = 2.0;
  c2_ab_y = NULL;
  sf_mex_assign(&c2_ab_y, sf_mex_create("y", &c2_y_u, 0, 0U, 0U, 0U, 0), FALSE);
  for (c2_i13 = 0; c2_i13 < 10; c2_i13++) {
    c2_ab_u[c2_i13] = c2_cv3[c2_i13];
  }

  c2_bb_y = NULL;
  sf_mex_assign(&c2_bb_y, sf_mex_create("y", c2_ab_u, 10, 0U, 1U, 0U, 2, 1, 10),
                FALSE);
  c2_bb_u = 2.0;
  c2_cb_y = NULL;
  sf_mex_assign(&c2_cb_y, sf_mex_create("y", &c2_bb_u, 0, 0U, 0U, 0U, 0), FALSE);
  for (c2_i14 = 0; c2_i14 < 15; c2_i14++) {
    c2_cb_u[c2_i14] = c2_cv4[c2_i14];
  }

  c2_db_y = NULL;
  sf_mex_assign(&c2_db_y, sf_mex_create("y", c2_cb_u, 10, 0U, 1U, 0U, 2, 1, 15),
                FALSE);
  c2_db_u = 'g';
  c2_eb_y = NULL;
  sf_mex_assign(&c2_eb_y, sf_mex_create("y", &c2_db_u, 10, 0U, 0U, 0U, 0), FALSE);
  for (c2_i15 = 0; c2_i15 < 15; c2_i15++) {
    c2_eb_u[c2_i15] = c2_cv7[c2_i15];
  }

  c2_fb_y = NULL;
  sf_mex_assign(&c2_fb_y, sf_mex_create("y", c2_eb_u, 10, 0U, 1U, 0U, 2, 1, 15),
                FALSE);
  for (c2_i16 = 0; c2_i16 < 3; c2_i16++) {
    c2_fb_u[c2_i16] = 0.5;
  }

  c2_gb_y = NULL;
  sf_mex_assign(&c2_gb_y, sf_mex_create("y", c2_fb_u, 0, 0U, 1U, 0U, 2, 1, 3),
                FALSE);
  sf_mex_call_debug("plot", 0U, 11U, 14, c2_v_y, 14, c2_w_y, 14, c2_x_y, 14,
                    c2_y_y, 14, c2_ab_y, 14, c2_bb_y, 14, c2_cb_y, 14, c2_db_y,
                    14, c2_eb_y, 14, c2_fb_y, 14, c2_gb_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  c2_gb_u = 0.033333333333333333;
  c2_hb_y = NULL;
  sf_mex_assign(&c2_hb_y, sf_mex_create("y", &c2_gb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("pause", 0U, 1U, 14, c2_hb_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  *c2_ib_y = c2_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_punti_massaMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_punti_massa(SFc2_punti_massaInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_punti_massaInstanceStruct *chartInstance;
  chartInstance = (SFc2_punti_massaInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_punti_massaInstanceStruct *chartInstance,
  const mxArray *c2_y, const char_T *c2_identifier)
{
  real_T c2_b_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId);
  sf_mex_destroy(&c2_y);
  return c2_b_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_punti_massaInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_y;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y;
  SFc2_punti_massaInstanceStruct *chartInstance;
  chartInstance = (SFc2_punti_massaInstanceStruct *)chartInstanceVoid;
  c2_y = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId);
  sf_mex_destroy(&c2_y);
  *(real_T *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i17;
  real_T c2_b_inData[2];
  int32_T c2_i18;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_punti_massaInstanceStruct *chartInstance;
  chartInstance = (SFc2_punti_massaInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i17 = 0; c2_i17 < 2; c2_i17++) {
    c2_b_inData[c2_i17] = (*(real_T (*)[2])c2_inData)[c2_i17];
  }

  for (c2_i18 = 0; c2_i18 < 2; c2_i18++) {
    c2_u[c2_i18] = c2_b_inData[c2_i18];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_punti_massaInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[2])
{
  real_T c2_dv1[2];
  int32_T c2_i19;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 2, 1, 2);
  for (c2_i19 = 0; c2_i19 < 2; c2_i19++) {
    c2_y[c2_i19] = c2_dv1[c2_i19];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_d;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[2];
  int32_T c2_i20;
  SFc2_punti_massaInstanceStruct *chartInstance;
  chartInstance = (SFc2_punti_massaInstanceStruct *)chartInstanceVoid;
  c2_d = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_d), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_d);
  for (c2_i20 = 0; c2_i20 < 2; c2_i20++) {
    (*(real_T (*)[2])c2_outData)[c2_i20] = c2_y[c2_i20];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_punti_massa_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_createstruct("structure", 2, 9, 1),
                FALSE);
  c2_info_helper(&c2_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(const mxArray **c2_info)
{
  const mxArray *c2_rhs0 = NULL;
  const mxArray *c2_lhs0 = NULL;
  const mxArray *c2_rhs1 = NULL;
  const mxArray *c2_lhs1 = NULL;
  const mxArray *c2_rhs2 = NULL;
  const mxArray *c2_lhs2 = NULL;
  const mxArray *c2_rhs3 = NULL;
  const mxArray *c2_lhs3 = NULL;
  const mxArray *c2_rhs4 = NULL;
  const mxArray *c2_lhs4 = NULL;
  const mxArray *c2_rhs5 = NULL;
  const mxArray *c2_lhs5 = NULL;
  const mxArray *c2_rhs6 = NULL;
  const mxArray *c2_lhs6 = NULL;
  const mxArray *c2_rhs7 = NULL;
  const mxArray *c2_lhs7 = NULL;
  const mxArray *c2_rhs8 = NULL;
  const mxArray *c2_lhs8 = NULL;
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("hold"), "name", "name", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/matlab/graphics/hold.m"), "resolved", "resolved",
                  0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1305036298U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c2_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("plot"), "name", "name", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/graph2d/plot"), "resolved", "resolved", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c2_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("axis"), "name", "name", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/matlab/graph2d/axis.m"), "resolved", "resolved",
                  2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1344472132U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c2_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mrdivide"), "name", "name", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1373306508U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1319729966U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c2_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("rdivide"), "name", "name", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c2_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c2_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c2_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_div"), "name", "name", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363713866U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c2_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("pause"), "name", "name", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/timefun/pause"), "resolved", "resolved",
                  8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c2_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs8), "lhs", "lhs", 8);
  sf_mex_destroy(&c2_rhs0);
  sf_mex_destroy(&c2_lhs0);
  sf_mex_destroy(&c2_rhs1);
  sf_mex_destroy(&c2_lhs1);
  sf_mex_destroy(&c2_rhs2);
  sf_mex_destroy(&c2_lhs2);
  sf_mex_destroy(&c2_rhs3);
  sf_mex_destroy(&c2_lhs3);
  sf_mex_destroy(&c2_rhs4);
  sf_mex_destroy(&c2_lhs4);
  sf_mex_destroy(&c2_rhs5);
  sf_mex_destroy(&c2_lhs5);
  sf_mex_destroy(&c2_rhs6);
  sf_mex_destroy(&c2_lhs6);
  sf_mex_destroy(&c2_rhs7);
  sf_mex_destroy(&c2_lhs7);
  sf_mex_destroy(&c2_rhs8);
  sf_mex_destroy(&c2_lhs8);
}

static const mxArray *c2_emlrt_marshallOut(char * c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c2_u)), FALSE);
  return c2_y;
}

static const mxArray *c2_b_emlrt_marshallOut(uint32_T c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c2_y;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_punti_massaInstanceStruct *chartInstance;
  chartInstance = (SFc2_punti_massaInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_punti_massaInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i21;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i21, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i21;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_punti_massaInstanceStruct *chartInstance;
  chartInstance = (SFc2_punti_massaInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_punti_massaInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_punti_massa, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_punti_massa), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_punti_massa);
  return c2_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_punti_massaInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_punti_massaInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c2_punti_massa_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2249074014U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2597866570U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3135152246U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2973994456U);
}

mxArray *sf_c2_punti_massa_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("gQ8xhXuwNa1mZQhUvYnyTB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_punti_massa_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_punti_massa_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_punti_massa(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c2_punti_massa\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_punti_massa_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_punti_massaInstanceStruct *chartInstance;
    chartInstance = (SFc2_punti_massaInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _punti_massaMachineNumber_,
           2,
           1,
           1,
           7,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_punti_massaMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_punti_massaMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _punti_massaMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"X_North");
          _SFD_SET_DATA_PROPS(1,1,1,0,"X_East");
          _SFD_SET_DATA_PROPS(2,2,0,1,"y");
          _SFD_SET_DATA_PROPS(3,1,1,0,"X_East_WP");
          _SFD_SET_DATA_PROPS(4,1,1,0,"X_North_WP");
          _SFD_SET_DATA_PROPS(5,1,1,0,"X_East_In");
          _SFD_SET_DATA_PROPS(6,1,1,0,"X_North_In");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,469);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_X_North;
          real_T *c2_X_East;
          real_T *c2_y;
          real_T *c2_X_East_WP;
          real_T *c2_X_North_WP;
          real_T *c2_X_East_In;
          real_T *c2_X_North_In;
          c2_X_North_In = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c2_X_East_In = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_X_North_WP = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_X_East_WP = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_X_East = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_X_North = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_X_North);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_X_East);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_y);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_X_East_WP);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_X_North_WP);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_X_East_In);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_X_North_In);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _punti_massaMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "vFNgN0XnoGbPxwGA6XRM9B";
}

static void sf_opaque_initialize_c2_punti_massa(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_punti_massaInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c2_punti_massa((SFc2_punti_massaInstanceStruct*)
    chartInstanceVar);
  initialize_c2_punti_massa((SFc2_punti_massaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_punti_massa(void *chartInstanceVar)
{
  enable_c2_punti_massa((SFc2_punti_massaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_punti_massa(void *chartInstanceVar)
{
  disable_c2_punti_massa((SFc2_punti_massaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_punti_massa(void *chartInstanceVar)
{
  sf_c2_punti_massa((SFc2_punti_massaInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_punti_massa(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_punti_massa
    ((SFc2_punti_massaInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_punti_massa();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c2_punti_massa(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_punti_massa();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_punti_massa((SFc2_punti_massaInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_punti_massa(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_punti_massa(S);
}

static void sf_opaque_set_sim_state_c2_punti_massa(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_punti_massa(S, st);
}

static void sf_opaque_terminate_c2_punti_massa(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_punti_massaInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_punti_massa_optimization_info();
    }

    finalize_c2_punti_massa((SFc2_punti_massaInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_punti_massa((SFc2_punti_massaInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_punti_massa(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_punti_massa((SFc2_punti_massaInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_punti_massa(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_punti_massa_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2965575498U));
  ssSetChecksum1(S,(4123666650U));
  ssSetChecksum2(S,(1421510598U));
  ssSetChecksum3(S,(1341308086U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_punti_massa(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_punti_massa(SimStruct *S)
{
  SFc2_punti_massaInstanceStruct *chartInstance;
  chartInstance = (SFc2_punti_massaInstanceStruct *)utMalloc(sizeof
    (SFc2_punti_massaInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_punti_massaInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_punti_massa;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_punti_massa;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_punti_massa;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_punti_massa;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_punti_massa;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_punti_massa;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_punti_massa;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_punti_massa;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_punti_massa;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_punti_massa;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_punti_massa;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_punti_massa_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_punti_massa(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_punti_massa(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_punti_massa(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_punti_massa_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
