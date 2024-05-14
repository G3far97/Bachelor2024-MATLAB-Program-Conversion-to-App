/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * minOrMax.c
 *
 * Code generation for function 'minOrMax'
 *
 */

/* Include files */
#include "minOrMax.h"
#include "main_entry_point_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
double maximum(const emxArray_real_T *x)
{
  const double *x_data;
  double ex;
  int k;
  int last;
  x_data = x->data;
  last = x->size[0];
  if (x->size[0] <= 2) {
    if (x->size[0] == 1) {
      ex = x_data[0];
    } else {
      double ex_tmp;
      ex_tmp = x_data[x->size[0] - 1];
      if (x_data[0] < ex_tmp) {
        ex = ex_tmp;
      } else {
        ex = x_data[0];
      }
    }
  } else {
    ex = x_data[0];
    for (k = 2; k <= last; k++) {
      double ex_tmp;
      ex_tmp = x_data[k - 1];
      if (ex < ex_tmp) {
        ex = ex_tmp;
      }
    }
  }
  return ex;
}

double minimum(const emxArray_real_T *x)
{
  const double *x_data;
  double ex;
  int k;
  int last;
  x_data = x->data;
  last = x->size[0];
  if (x->size[0] <= 2) {
    if (x->size[0] == 1) {
      ex = x_data[0];
    } else {
      double ex_tmp;
      ex_tmp = x_data[x->size[0] - 1];
      if (x_data[0] > ex_tmp) {
        ex = ex_tmp;
      } else {
        ex = x_data[0];
      }
    }
  } else {
    ex = x_data[0];
    for (k = 2; k <= last; k++) {
      double ex_tmp;
      ex_tmp = x_data[k - 1];
      if (ex > ex_tmp) {
        ex = ex_tmp;
      }
    }
  }
  return ex;
}

/* End of code generation (minOrMax.c) */
