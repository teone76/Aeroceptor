/*
 * File: rt_nonfinite.h
 *
 * Code generated for Simulink model 'navigator'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Tue Mar 03 17:11:32 2015
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

#ifndef RTW_HEADER_rt_nonfinite_h_
#define RTW_HEADER_rt_nonfinite_h_
#include <stddef.h>
#include "rtwtypes.h"
#ifdef __cplusplus

extern "C" {

#endif

  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  extern void rt_InitInfAndNaN(size_t realSize);
  extern boolean_T rtIsInf(real_T value);
  extern boolean_T rtIsInfF(real32_T value);
  extern boolean_T rtIsNaN(real_T value);
  extern boolean_T rtIsNaNF(real32_T value);
  typedef struct {
    struct {
      uint32_T wordH;
      uint32_T wordL;
    } words;
  } BigEndianIEEEDouble;

  typedef struct {
    struct {
      uint32_T wordL;
      uint32_T wordH;
    } words;
  } LittleEndianIEEEDouble;

  typedef struct {
    union {
      real32_T wordLreal;
      uint32_T wordLuint;
    } wordL;
  } IEEESingle;

#ifdef __cplusplus

}                                      /* extern "C" */
#endif
#endif                                 /* RTW_HEADER_rt_nonfinite_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */