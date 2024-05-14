/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * getLocalTime.h
 *
 * Code generation for function 'getLocalTime'
 *
 */

#ifndef GETLOCALTIME_H
#define GETLOCALTIME_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double getLocalTime(double *t_tm_sec, double *t_tm_min, double *t_tm_hour,
                    double *t_tm_mday, double *t_tm_mon, double *t_tm_year,
                    boolean_T *t_tm_isdst);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (getLocalTime.h) */
