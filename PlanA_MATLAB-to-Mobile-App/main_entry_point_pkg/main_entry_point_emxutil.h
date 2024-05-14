/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main_entry_point_emxutil.h
 *
 * Code generation for function 'main_entry_point_emxutil'
 *
 */

#ifndef MAIN_ENTRY_POINT_EMXUTIL_H
#define MAIN_ENTRY_POINT_EMXUTIL_H

/* Include files */
#include "main_entry_point_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxEnsureCapacity_char_T(emxArray_char_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxFree_char_T(emxArray_char_T **pEmxArray);

extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxInit_char_T(emxArray_char_T **pEmxArray);

extern void emxInit_int32_T(emxArray_int32_T **pEmxArray);

extern void emxInit_real_T(emxArray_real_T **pEmxArray);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (main_entry_point_emxutil.h) */
