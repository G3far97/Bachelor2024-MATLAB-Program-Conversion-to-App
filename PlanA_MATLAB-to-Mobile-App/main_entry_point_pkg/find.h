/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find.h
 *
 * Code generation for function 'find'
 *
 */

#ifndef FIND_H
#define FIND_H

/* Include files */
#include "main_entry_point_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
int b_eml_find(const boolean_T x_data[], const int x_size[2], int i_data[],
               int j_data[], int *j_size);

int binary_expand_op(const double in2[2764800], int in3, int in4, int in5,
                     int in6, int in7, int in8, int in9, int in10, int in11,
                     int in12, int in13, int in14, int in15_data[],
                     int in16_data[], int *in16_size);

int binary_expand_op_1(const double in2[2764800], int in3, int in4, int in5,
                       int in6, int in7, int in8, int in9, int in10, int in11,
                       int in12, int in13, int in14, int in15_data[],
                       int in16_data[], int *in16_size);

int binary_expand_op_2(const double in2[2764800], int in3, int in4, int in5,
                       int in6, int in7, int in8, int in9, int in10, int in11,
                       int in12, int in13, int in14, int in15_data[],
                       int in16_data[], int *in16_size);

void eml_find(const boolean_T x[921600], emxArray_int32_T *i,
              emxArray_int32_T *j);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (find.h) */
