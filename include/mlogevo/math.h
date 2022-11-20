/* Declarations (and implementations) for math functions.
 * This file is part of MlogEvo "standard" library
 */

#ifndef _MLOGEVO_MATH_H
#define _MLOGEVO_MATH_H
// https://www.gnu.org/software/libc/manual/html_node/Mathematical-Constants.html
// calculated in Python though
#define M_E 2.718281828459045
#define M_LOG2E 1.4426950408889634
#define M_LOG10E 0.43429448190325176
#define M_LN2 0.6931471805599453
#define M_LN10 2.302585092994046
#define M_PI 3.141592653589793
#define M_PI_2 1.5707963267948966
#define M_PI_4 0.7853981633974483
#define M_1_PI 0.3183098861837907
#define M_2_PI 0.6366197723675814
#define M_2_SQRTPI 1.1283791670955126
#define M_SQRT2 1.4142135623730951
#define M_SQRT1_2 0.7071067811865476
// Tau, 2*M_PI
// See https://tauday.com/
#define M_TAU 6.283185307179586

// M_TAU / 360.0
#define M_DEG2RAD 0.017453292519943295
// 360.0 / M_TAU
#define M_RAD2DEG 57.29577951308232

// C99 says there are double_t and float_t
#define double_t double
#define float_t float

#include "arch.h"
#if MLOGEV_ARCH == MLOGEV_ARCH_MLOG
#include "mlogevo/arch_mlog/math.h"
#endif

#endif // _MLOGEVO_MATH_H