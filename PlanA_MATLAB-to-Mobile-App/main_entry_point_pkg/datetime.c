/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * datetime.c
 *
 * Code generation for function 'datetime'
 *
 */

/* Include files */
#include "datetime.h"
#include "getLocalTime.h"
#include "plus.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
creal_T datetime_datetime(void)
{
  creal_T this_data;
  double c_tm_hour;
  double c_tm_min;
  double c_tm_mon;
  double c_tm_year;
  double check;
  double fracSecs;
  double second;
  double shi;
  boolean_T expl_temp;
  check = getLocalTime(&second, &c_tm_min, &c_tm_hour, &shi, &c_tm_mon,
                       &c_tm_year, &expl_temp);
  fracSecs = check / 1.0E+6;
  check = (((((c_tm_year + c_tm_mon) + shi) + c_tm_hour) + c_tm_min) + second) +
          fracSecs;
  if ((!rtIsInf(check)) && (!rtIsNaN(check))) {
    creal_T ahi;
    double wholeSecsFromMillis;
    if ((c_tm_mon < 1.0) || (c_tm_mon > 12.0)) {
      wholeSecsFromMillis = floor((c_tm_mon - 1.0) / 12.0);
      c_tm_year += wholeSecsFromMillis;
      c_tm_mon = ((c_tm_mon - 1.0) - wholeSecsFromMillis * 12.0) + 1.0;
    }
    if (c_tm_mon < 3.0) {
      c_tm_year--;
      c_tm_mon += 9.0;
    } else {
      c_tm_mon -= 3.0;
    }
    wholeSecsFromMillis = ((((((365.0 * c_tm_year + floor(c_tm_year / 4.0)) -
                               floor(c_tm_year / 100.0)) +
                              floor(c_tm_year / 400.0)) +
                             floor((153.0 * c_tm_mon + 2.0) / 5.0)) +
                            shi) +
                           60.0) -
                          719529.0;
    check = 1.34217729E+8 * wholeSecsFromMillis;
    check -= check - wholeSecsFromMillis;
    shi = wholeSecsFromMillis * 8.64E+7;
    check = (wholeSecsFromMillis - check) * 8.64E+7 + (check * 8.64E+7 - shi);
    if (rtIsNaN(check)) {
      check = 0.0;
    }
    if ((fracSecs < 0.0) || (fracSecs >= 1000.0)) {
      wholeSecsFromMillis = floor(fracSecs / 1000.0);
      second += wholeSecsFromMillis;
      fracSecs -= wholeSecsFromMillis * 1000.0;
    }
    ahi.re = shi;
    ahi.im = check;
    this_data = plus(plus(plus(ahi, (60.0 * c_tm_hour + c_tm_min) * 60000.0),
                          second * 1000.0),
                     fracSecs);
  } else {
    this_data.re = check;
    this_data.im = 0.0;
  }
  return this_data;
}

/* End of code generation (datetime.c) */
