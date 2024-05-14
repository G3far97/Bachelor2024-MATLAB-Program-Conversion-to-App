/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find.c
 *
 * Code generation for function 'find'
 *
 */

/* Include files */
#include "find.h"
#include "main_entry_point_emxutil.h"
#include "main_entry_point_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
int b_eml_find(const boolean_T x_data[], const int x_size[2], int i_data[],
               int j_data[], int *j_size)
{
  int i_size;
  i_size = x_size[0] * x_size[1];
  if (i_size == 0) {
    i_size = 0;
    *j_size = 0;
  } else {
    int idx;
    int ii;
    int jj;
    boolean_T exitg1;
    idx = 0;
    *j_size = i_size;
    ii = 1;
    jj = 1;
    exitg1 = false;
    while ((!exitg1) && (jj <= x_size[1])) {
      boolean_T guard1;
      guard1 = false;
      if (x_data[(ii + x_size[0] * (jj - 1)) - 1]) {
        idx++;
        i_data[idx - 1] = ii;
        j_data[idx - 1] = jj;
        if (idx >= i_size) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        ii++;
        if (ii > x_size[0]) {
          ii = 1;
          jj++;
        }
      }
    }
    if (i_size == 1) {
      if (idx == 0) {
        i_size = 0;
        *j_size = 0;
      }
    } else {
      if (idx < 1) {
        i_size = 0;
      } else {
        i_size = idx;
      }
      *j_size = i_size;
    }
  }
  return i_size;
}

int binary_expand_op(const double in2[2764800], int in3, int in4, int in5,
                     int in6, int in7, int in8, int in9, int in10, int in11,
                     int in12, int in13, int in14, int in15_data[],
                     int in16_data[], int *in16_size)
{
  int tmp_size[2];
  int aux_0_1;
  int aux_1_1;
  int aux_2_1;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  int stride_2_0;
  int stride_2_1;
  boolean_T tmp_data[10000];
  i = (in8 - in7) + 1;
  i1 = (in12 - in11) + 1;
  stride_2_1 = (in4 - in3) + 1;
  if (i1 == 1) {
    if (i == 1) {
      loop_ub = stride_2_1;
    } else {
      loop_ub = i;
    }
  } else {
    loop_ub = i1;
  }
  tmp_size[0] = loop_ub;
  aux_1_1 = (in10 - in9) + 1;
  aux_2_1 = (in14 - in13) + 1;
  aux_0_1 = (in6 - in5) + 1;
  if (aux_2_1 == 1) {
    if (aux_1_1 == 1) {
      b_loop_ub = aux_0_1;
    } else {
      b_loop_ub = aux_1_1;
    }
  } else {
    b_loop_ub = aux_2_1;
  }
  tmp_size[1] = b_loop_ub;
  stride_0_0 = (stride_2_1 != 1);
  stride_0_1 = (aux_0_1 != 1);
  stride_1_0 = (i != 1);
  stride_1_1 = (aux_1_1 != 1);
  stride_2_0 = (i1 != 1);
  stride_2_1 = (aux_2_1 != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      double b_varargin_1;
      double c_varargin_1;
      double varargin_1;
      varargin_1 = in2[(in3 + i1 * stride_0_0) + 720 * (in5 + aux_0_1)] - 124.0;
      b_varargin_1 =
          in2[((in7 + i1 * stride_1_0) + 720 * (in9 + aux_1_1)) + 921600] -
          35.0;
      c_varargin_1 =
          in2[((in11 + i1 * stride_2_0) + 720 * (in13 + aux_2_1)) + 1843200] -
          35.0;
      tmp_data[i1 + loop_ub * i] =
          ((varargin_1 * varargin_1 + b_varargin_1 * b_varargin_1) +
               c_varargin_1 * c_varargin_1 <
           340.0);
    }
    aux_2_1 += stride_2_1;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  return b_eml_find(tmp_data, tmp_size, in15_data, in16_data, in16_size);
}

int binary_expand_op_1(const double in2[2764800], int in3, int in4, int in5,
                       int in6, int in7, int in8, int in9, int in10, int in11,
                       int in12, int in13, int in14, int in15_data[],
                       int in16_data[], int *in16_size)
{
  int tmp_size[2];
  int aux_0_1;
  int aux_1_1;
  int aux_2_1;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  int stride_2_0;
  int stride_2_1;
  boolean_T tmp_data[10000];
  i = (in8 - in7) + 1;
  i1 = (in12 - in11) + 1;
  stride_2_1 = (in4 - in3) + 1;
  if (i1 == 1) {
    if (i == 1) {
      loop_ub = stride_2_1;
    } else {
      loop_ub = i;
    }
  } else {
    loop_ub = i1;
  }
  tmp_size[0] = loop_ub;
  aux_1_1 = (in10 - in9) + 1;
  aux_2_1 = (in14 - in13) + 1;
  aux_0_1 = (in6 - in5) + 1;
  if (aux_2_1 == 1) {
    if (aux_1_1 == 1) {
      b_loop_ub = aux_0_1;
    } else {
      b_loop_ub = aux_1_1;
    }
  } else {
    b_loop_ub = aux_2_1;
  }
  tmp_size[1] = b_loop_ub;
  stride_0_0 = (stride_2_1 != 1);
  stride_0_1 = (aux_0_1 != 1);
  stride_1_0 = (i != 1);
  stride_1_1 = (aux_1_1 != 1);
  stride_2_0 = (i1 != 1);
  stride_2_1 = (aux_2_1 != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      double b_varargin_1;
      double c_varargin_1;
      double varargin_1;
      varargin_1 = in2[(in3 + i1 * stride_0_0) + 720 * (in5 + aux_0_1)] - 165.0;
      b_varargin_1 =
          in2[((in7 + i1 * stride_1_0) + 720 * (in9 + aux_1_1)) + 921600] -
          116.0;
      c_varargin_1 =
          in2[((in11 + i1 * stride_2_0) + 720 * (in13 + aux_2_1)) + 1843200] -
          40.0;
      tmp_data[i1 + loop_ub * i] =
          ((varargin_1 * varargin_1 + b_varargin_1 * b_varargin_1) +
               c_varargin_1 * c_varargin_1 <
           340.0);
    }
    aux_2_1 += stride_2_1;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  return b_eml_find(tmp_data, tmp_size, in15_data, in16_data, in16_size);
}

int binary_expand_op_2(const double in2[2764800], int in3, int in4, int in5,
                       int in6, int in7, int in8, int in9, int in10, int in11,
                       int in12, int in13, int in14, int in15_data[],
                       int in16_data[], int *in16_size)
{
  int tmp_size[2];
  int aux_0_1;
  int aux_1_1;
  int aux_2_1;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  int stride_2_0;
  int stride_2_1;
  boolean_T tmp_data[10000];
  i = (in8 - in7) + 1;
  i1 = (in12 - in11) + 1;
  stride_2_1 = (in4 - in3) + 1;
  if (i1 == 1) {
    if (i == 1) {
      loop_ub = stride_2_1;
    } else {
      loop_ub = i;
    }
  } else {
    loop_ub = i1;
  }
  tmp_size[0] = loop_ub;
  aux_1_1 = (in10 - in9) + 1;
  aux_2_1 = (in14 - in13) + 1;
  aux_0_1 = (in6 - in5) + 1;
  if (aux_2_1 == 1) {
    if (aux_1_1 == 1) {
      b_loop_ub = aux_0_1;
    } else {
      b_loop_ub = aux_1_1;
    }
  } else {
    b_loop_ub = aux_2_1;
  }
  tmp_size[1] = b_loop_ub;
  stride_0_0 = (stride_2_1 != 1);
  stride_0_1 = (aux_0_1 != 1);
  stride_1_0 = (i != 1);
  stride_1_1 = (aux_1_1 != 1);
  stride_2_0 = (i1 != 1);
  stride_2_1 = (aux_2_1 != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      double b_varargin_1;
      double c_varargin_1;
      double varargin_1;
      varargin_1 = in2[(in3 + i1 * stride_0_0) + 720 * (in5 + aux_0_1)] - 50.0;
      b_varargin_1 =
          in2[((in7 + i1 * stride_1_0) + 720 * (in9 + aux_1_1)) + 921600] -
          86.0;
      c_varargin_1 =
          in2[((in11 + i1 * stride_2_0) + 720 * (in13 + aux_2_1)) + 1843200] -
          129.0;
      tmp_data[i1 + loop_ub * i] =
          ((varargin_1 * varargin_1 + b_varargin_1 * b_varargin_1) +
               c_varargin_1 * c_varargin_1 <
           340.0);
    }
    aux_2_1 += stride_2_1;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  return b_eml_find(tmp_data, tmp_size, in15_data, in16_data, in16_size);
}

void eml_find(const boolean_T x[921600], emxArray_int32_T *i,
              emxArray_int32_T *j)
{
  int idx;
  int ii;
  int jj;
  int *i_data;
  int *j_data;
  boolean_T exitg1;
  idx = 0;
  jj = i->size[0];
  i->size[0] = 921600;
  emxEnsureCapacity_int32_T(i, jj);
  i_data = i->data;
  jj = j->size[0];
  j->size[0] = 921600;
  emxEnsureCapacity_int32_T(j, jj);
  j_data = j->data;
  ii = 1;
  jj = 1;
  exitg1 = false;
  while ((!exitg1) && (jj <= 1280)) {
    boolean_T guard1;
    guard1 = false;
    if (x[(ii + 720 * (jj - 1)) - 1]) {
      idx++;
      i_data[idx - 1] = ii;
      j_data[idx - 1] = jj;
      if (idx >= 921600) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      ii++;
      if (ii > 720) {
        ii = 1;
        jj++;
      }
    }
  }
  if (idx < 1) {
    jj = 0;
  } else {
    jj = idx;
  }
  ii = i->size[0];
  i->size[0] = jj;
  emxEnsureCapacity_int32_T(i, ii);
  ii = j->size[0];
  j->size[0] = jj;
  emxEnsureCapacity_int32_T(j, ii);
}

/* End of code generation (find.c) */
