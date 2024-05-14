/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * plus.c
 *
 * Code generation for function 'plus'
 *
 */

/* Include files */
#include "plus.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
creal_T plus(const creal_T a, double b)
{
  creal_T c;
  double ahi;
  double b_slo;
  double bb;
  double shi_tmp;
  double slo;
  shi_tmp = a.re + b;
  bb = shi_tmp - a.re;
  slo = (a.re - (shi_tmp - bb)) + (b - bb);
  if (rtIsNaN(slo)) {
    slo = 0.0;
  }
  bb = a.im - a.im;
  b_slo = (a.im - (a.im - bb)) + (0.0 - bb);
  if (rtIsNaN(b_slo)) {
    b_slo = 0.0;
  }
  ahi = shi_tmp;
  if (a.im != 0.0) {
    slo += a.im;
    ahi = shi_tmp + slo;
    slo -= ahi - shi_tmp;
  }
  if (rtIsNaN(slo)) {
    slo = 0.0;
  }
  bb = ahi;
  if (b_slo != 0.0) {
    slo += b_slo;
    bb = ahi + slo;
    slo -= bb - ahi;
  }
  if (rtIsNaN(slo)) {
    slo = 0.0;
  }
  c.re = bb;
  c.im = slo;
  return c;
}

/* End of code generation (plus.c) */
