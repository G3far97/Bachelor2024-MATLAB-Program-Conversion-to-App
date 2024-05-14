/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Lungentrainer02.c
 *
 * Code generation for function 'Lungentrainer02'
 *
 */

/* Include files */
#include "Lungentrainer02.h"
#include "find.h"
#include "main_entry_point_emxutil.h"
#include "main_entry_point_types.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
double getballs(const double img2[2764800], double *yellowmax, double *redmax)
{
  static boolean_T y[921600];
  emxArray_int32_T *ii;
  emxArray_int32_T *jj;
  emxArray_real_T *kxblue1;
  emxArray_real_T *kyblue;
  emxArray_real_T *kyblue1;
  emxArray_real_T *kyred;
  emxArray_real_T *kyyellow;
  double b_varargin_1;
  double bluemax;
  double c_varargin_1;
  double d;
  double minval_tmp;
  double varargin_1;
  double *kyblue_data;
  int b_ii_data[10000];
  int b_jj_data[10000];
  int tmp_size[2];
  int b_loop_ub;
  int i;
  int i1;
  int i10;
  int i11;
  int i12;
  int i13;
  int i14;
  int i2;
  int i3;
  int i4;
  int i5;
  int i6;
  int i7;
  int i8;
  int i9;
  int k;
  int loop_ub;
  int *ii_data;
  int *jj_data;
  boolean_T tmp_data[10000];
  /*  Ball detection function */
  for (k = 0; k < 921600; k++) {
    varargin_1 = img2[k] - 50.0;
    b_varargin_1 = varargin_1 * varargin_1;
    varargin_1 = img2[k + 921600] - 86.0;
    c_varargin_1 = varargin_1 * varargin_1;
    varargin_1 = img2[k + 1843200] - 129.0;
    y[k] = ((b_varargin_1 + c_varargin_1) + varargin_1 * varargin_1 < 170.0);
  }
  emxInit_int32_T(&ii);
  emxInit_int32_T(&jj);
  eml_find(y, ii, jj);
  jj_data = jj->data;
  ii_data = ii->data;
  emxInit_real_T(&kyblue1);
  i = kyblue1->size[0];
  kyblue1->size[0] = ii->size[0];
  emxEnsureCapacity_real_T(kyblue1, i);
  kyblue_data = kyblue1->data;
  loop_ub = ii->size[0];
  for (i = 0; i < loop_ub; i++) {
    kyblue_data[i] = ii_data[i];
  }
  emxInit_real_T(&kxblue1);
  i = kxblue1->size[0];
  kxblue1->size[0] = jj->size[0];
  emxEnsureCapacity_real_T(kxblue1, i);
  kyblue_data = kxblue1->data;
  loop_ub = jj->size[0];
  for (i = 0; i < loop_ub; i++) {
    kyblue_data[i] = jj_data[i];
  }
  minval_tmp = minimum(kyblue1);
  varargin_1 = fmax(1.0, minval_tmp - 25.0);
  b_varargin_1 = fmin(100.0, maximum(kyblue1) + 25.0);
  if (varargin_1 > b_varargin_1) {
    i = -1;
    i1 = -1;
  } else {
    i = (int)varargin_1 - 2;
    i1 = (int)b_varargin_1 - 1;
  }
  c_varargin_1 = fmax(1.0, minimum(kxblue1) - 25.0);
  d = fmin(100.0, maximum(kxblue1) + 25.0);
  if (c_varargin_1 > d) {
    i2 = -1;
    i3 = -1;
    i4 = -1;
    i5 = -1;
  } else {
    i2 = (int)c_varargin_1 - 2;
    i3 = (int)d - 1;
    i4 = (int)c_varargin_1 - 2;
    i5 = (int)d - 1;
  }
  if (varargin_1 > b_varargin_1) {
    i6 = -1;
    i7 = -1;
    i8 = 0;
    i9 = 0;
  } else {
    i6 = (int)varargin_1 - 2;
    i7 = (int)b_varargin_1 - 1;
    i8 = (int)varargin_1 - 1;
    i9 = (int)b_varargin_1;
  }
  if (c_varargin_1 > d) {
    i10 = 0;
    i11 = 0;
  } else {
    i10 = (int)c_varargin_1 - 1;
    i11 = (int)d;
  }
  loop_ub = i1 - i;
  k = i7 - i6;
  b_loop_ub = i3 - i2;
  i12 = i5 - i4;
  if (loop_ub == 1) {
    i13 = k;
  } else {
    i13 = loop_ub;
  }
  if (b_loop_ub == 1) {
    i14 = i12;
  } else {
    i14 = b_loop_ub;
  }
  if ((loop_ub == k) && (b_loop_ub == i12) && (i13 == i9 - i8) &&
      (i14 == i11 - i10)) {
    tmp_size[0] = loop_ub;
    tmp_size[1] = b_loop_ub;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i3 = 0; i3 < loop_ub; i3++) {
        varargin_1 = img2[((i + i3) + 720 * ((i2 + i1) + 1)) + 1] - 50.0;
        b_varargin_1 =
            img2[((i6 + i3) + 720 * ((i4 + i1) + 1)) + 921601] - 86.0;
        c_varargin_1 = img2[((i8 + i3) + 720 * (i10 + i1)) + 1843200] - 129.0;
        tmp_data[i3 + loop_ub * i1] =
            ((varargin_1 * varargin_1 + b_varargin_1 * b_varargin_1) +
                 c_varargin_1 * c_varargin_1 <
             340.0);
      }
    }
    k = b_eml_find(tmp_data, tmp_size, b_ii_data, b_jj_data, &loop_ub);
  } else {
    k = binary_expand_op_2(img2, i + 1, i1, i2 + 1, i3, i6 + 1, i7, i4 + 1, i5,
                           i8, i9 - 1, i10, i11 - 1, b_ii_data, b_jj_data,
                           &loop_ub);
  }
  emxInit_real_T(&kyblue);
  i = kyblue->size[0];
  kyblue->size[0] = k;
  emxEnsureCapacity_real_T(kyblue, i);
  kyblue_data = kyblue->data;
  for (i = 0; i < k; i++) {
    kyblue_data[i] = (((double)b_ii_data[i] + minval_tmp) - 25.0) - 1.0;
  }
  for (k = 0; k < 921600; k++) {
    varargin_1 = img2[k] - 165.0;
    b_varargin_1 = varargin_1 * varargin_1;
    varargin_1 = img2[k + 921600] - 116.0;
    c_varargin_1 = varargin_1 * varargin_1;
    varargin_1 = img2[k + 1843200] - 40.0;
    y[k] = ((b_varargin_1 + c_varargin_1) + varargin_1 * varargin_1 < 170.0);
  }
  eml_find(y, ii, jj);
  jj_data = jj->data;
  ii_data = ii->data;
  i = kyblue1->size[0];
  kyblue1->size[0] = ii->size[0];
  emxEnsureCapacity_real_T(kyblue1, i);
  kyblue_data = kyblue1->data;
  loop_ub = ii->size[0];
  for (i = 0; i < loop_ub; i++) {
    kyblue_data[i] = ii_data[i];
  }
  i = kxblue1->size[0];
  kxblue1->size[0] = jj->size[0];
  emxEnsureCapacity_real_T(kxblue1, i);
  kyblue_data = kxblue1->data;
  loop_ub = jj->size[0];
  for (i = 0; i < loop_ub; i++) {
    kyblue_data[i] = jj_data[i];
  }
  minval_tmp = minimum(kyblue1);
  varargin_1 = fmax(1.0, minval_tmp - 25.0);
  b_varargin_1 = fmin(100.0, maximum(kyblue1) + 25.0);
  if (varargin_1 > b_varargin_1) {
    i = -1;
    i1 = -1;
  } else {
    i = (int)varargin_1 - 2;
    i1 = (int)b_varargin_1 - 1;
  }
  c_varargin_1 = fmax(1.0, minimum(kxblue1) - 25.0);
  d = fmin(100.0, maximum(kxblue1) + 25.0);
  if (c_varargin_1 > d) {
    i2 = -1;
    i3 = -1;
    i4 = -1;
    i5 = -1;
  } else {
    i2 = (int)c_varargin_1 - 2;
    i3 = (int)d - 1;
    i4 = (int)c_varargin_1 - 2;
    i5 = (int)d - 1;
  }
  if (varargin_1 > b_varargin_1) {
    i6 = -1;
    i7 = -1;
    i8 = 0;
    i9 = 0;
  } else {
    i6 = (int)varargin_1 - 2;
    i7 = (int)b_varargin_1 - 1;
    i8 = (int)varargin_1 - 1;
    i9 = (int)b_varargin_1;
  }
  if (c_varargin_1 > d) {
    i10 = 0;
    i11 = 0;
  } else {
    i10 = (int)c_varargin_1 - 1;
    i11 = (int)d;
  }
  loop_ub = i1 - i;
  k = i7 - i6;
  b_loop_ub = i3 - i2;
  i12 = i5 - i4;
  if (loop_ub == 1) {
    i13 = k;
  } else {
    i13 = loop_ub;
  }
  if (b_loop_ub == 1) {
    i14 = i12;
  } else {
    i14 = b_loop_ub;
  }
  if ((loop_ub == k) && (b_loop_ub == i12) && (i13 == i9 - i8) &&
      (i14 == i11 - i10)) {
    tmp_size[0] = loop_ub;
    tmp_size[1] = b_loop_ub;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i3 = 0; i3 < loop_ub; i3++) {
        varargin_1 = img2[((i + i3) + 720 * ((i2 + i1) + 1)) + 1] - 165.0;
        b_varargin_1 =
            img2[((i6 + i3) + 720 * ((i4 + i1) + 1)) + 921601] - 116.0;
        c_varargin_1 = img2[((i8 + i3) + 720 * (i10 + i1)) + 1843200] - 40.0;
        tmp_data[i3 + loop_ub * i1] =
            ((varargin_1 * varargin_1 + b_varargin_1 * b_varargin_1) +
                 c_varargin_1 * c_varargin_1 <
             340.0);
      }
    }
    k = b_eml_find(tmp_data, tmp_size, b_ii_data, b_jj_data, &loop_ub);
  } else {
    k = binary_expand_op_1(img2, i + 1, i1, i2 + 1, i3, i6 + 1, i7, i4 + 1, i5,
                           i8, i9 - 1, i10, i11 - 1, b_ii_data, b_jj_data,
                           &loop_ub);
  }
  emxInit_real_T(&kyyellow);
  i = kyyellow->size[0];
  kyyellow->size[0] = k;
  emxEnsureCapacity_real_T(kyyellow, i);
  kyblue_data = kyyellow->data;
  for (i = 0; i < k; i++) {
    kyblue_data[i] = (((double)b_ii_data[i] + minval_tmp) - 25.0) - 1.0;
  }
  for (k = 0; k < 921600; k++) {
    varargin_1 = img2[k] - 124.0;
    b_varargin_1 = varargin_1 * varargin_1;
    varargin_1 = img2[k + 921600] - 35.0;
    c_varargin_1 = varargin_1 * varargin_1;
    varargin_1 = img2[k + 1843200] - 35.0;
    y[k] = ((b_varargin_1 + c_varargin_1) + varargin_1 * varargin_1 < 170.0);
  }
  eml_find(y, ii, jj);
  jj_data = jj->data;
  ii_data = ii->data;
  i = kyblue1->size[0];
  kyblue1->size[0] = ii->size[0];
  emxEnsureCapacity_real_T(kyblue1, i);
  kyblue_data = kyblue1->data;
  loop_ub = ii->size[0];
  for (i = 0; i < loop_ub; i++) {
    kyblue_data[i] = ii_data[i];
  }
  emxFree_int32_T(&ii);
  i = kxblue1->size[0];
  kxblue1->size[0] = jj->size[0];
  emxEnsureCapacity_real_T(kxblue1, i);
  kyblue_data = kxblue1->data;
  loop_ub = jj->size[0];
  for (i = 0; i < loop_ub; i++) {
    kyblue_data[i] = jj_data[i];
  }
  emxFree_int32_T(&jj);
  minval_tmp = minimum(kyblue1);
  varargin_1 = fmax(1.0, minval_tmp - 25.0);
  b_varargin_1 = fmin(100.0, maximum(kyblue1) + 25.0);
  emxFree_real_T(&kyblue1);
  if (varargin_1 > b_varargin_1) {
    i = -1;
    i1 = -1;
  } else {
    i = (int)varargin_1 - 2;
    i1 = (int)b_varargin_1 - 1;
  }
  c_varargin_1 = fmax(1.0, minimum(kxblue1) - 25.0);
  d = fmin(100.0, maximum(kxblue1) + 25.0);
  emxFree_real_T(&kxblue1);
  if (c_varargin_1 > d) {
    i2 = -1;
    i3 = -1;
    i4 = -1;
    i5 = -1;
  } else {
    i2 = (int)c_varargin_1 - 2;
    i3 = (int)d - 1;
    i4 = (int)c_varargin_1 - 2;
    i5 = (int)d - 1;
  }
  if (varargin_1 > b_varargin_1) {
    i6 = -1;
    i7 = -1;
    i8 = 0;
    i9 = 0;
  } else {
    i6 = (int)varargin_1 - 2;
    i7 = (int)b_varargin_1 - 1;
    i8 = (int)varargin_1 - 1;
    i9 = (int)b_varargin_1;
  }
  if (c_varargin_1 > d) {
    i10 = 0;
    i11 = 0;
  } else {
    i10 = (int)c_varargin_1 - 1;
    i11 = (int)d;
  }
  loop_ub = i1 - i;
  k = i7 - i6;
  b_loop_ub = i3 - i2;
  i12 = i5 - i4;
  if (loop_ub == 1) {
    i13 = k;
  } else {
    i13 = loop_ub;
  }
  if (b_loop_ub == 1) {
    i14 = i12;
  } else {
    i14 = b_loop_ub;
  }
  if ((loop_ub == k) && (b_loop_ub == i12) && (i13 == i9 - i8) &&
      (i14 == i11 - i10)) {
    tmp_size[0] = loop_ub;
    tmp_size[1] = b_loop_ub;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i3 = 0; i3 < loop_ub; i3++) {
        varargin_1 = img2[((i + i3) + 720 * ((i2 + i1) + 1)) + 1] - 124.0;
        b_varargin_1 =
            img2[((i6 + i3) + 720 * ((i4 + i1) + 1)) + 921601] - 35.0;
        c_varargin_1 = img2[((i8 + i3) + 720 * (i10 + i1)) + 1843200] - 35.0;
        tmp_data[i3 + loop_ub * i1] =
            ((varargin_1 * varargin_1 + b_varargin_1 * b_varargin_1) +
                 c_varargin_1 * c_varargin_1 <
             340.0);
      }
    }
    k = b_eml_find(tmp_data, tmp_size, b_ii_data, b_jj_data, &loop_ub);
  } else {
    k = binary_expand_op(img2, i + 1, i1, i2 + 1, i3, i6 + 1, i7, i4 + 1, i5,
                         i8, i9 - 1, i10, i11 - 1, b_ii_data, b_jj_data,
                         &loop_ub);
  }
  emxInit_real_T(&kyred);
  i = kyred->size[0];
  kyred->size[0] = k;
  emxEnsureCapacity_real_T(kyred, i);
  kyblue_data = kyred->data;
  for (i = 0; i < k; i++) {
    kyblue_data[i] = (((double)b_ii_data[i] + minval_tmp) - 25.0) - 1.0;
  }
  if (kyblue->size[0] != 0) {
    bluemax = (100.0 - minimum(kyblue)) + 1.0;
  } else {
    /*  Handle the case when kyblue is empty (e.g., set bluemax to some default
     * value) */
    bluemax = 0.0;
    /*  or any other appropriate default value */
  }
  emxFree_real_T(&kyblue);
  if (kyyellow->size[0] != 0) {
    *yellowmax = (100.0 - minimum(kyyellow)) + 1.0;
  } else {
    /*  Handle the case when kyyellow is empty (e.g., set yellowmax to some
     * default value) */
    *yellowmax = 0.0;
    /*  or any other appropriate default value */
  }
  emxFree_real_T(&kyyellow);
  if (kyred->size[0] != 0) {
    *redmax = (100.0 - minimum(kyred)) + 1.0;
  } else {
    /*  Handle the case when kyred is empty (e.g., set redmax to some default
     * value) */
    *redmax = 0.0;
    /*  or any other appropriate default value */
  }
  emxFree_real_T(&kyred);
  return bluemax;
}

/* End of code generation (Lungentrainer02.c) */
