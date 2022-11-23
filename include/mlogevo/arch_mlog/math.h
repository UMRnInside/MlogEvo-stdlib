/* Declarations and implementations for math functions, mlog architecture ONLY.
 * This file is part of MlogEvo "standard" library
 */
#ifndef _ARCH_MLOG_MATH_H
#define _ARCH_MLOG_MATH_H
// https://gcc.gnu.org/onlinedocs/cpp/Stringizing.html
#define __STR(s) #s
#define __XSTR(s) __STR(s)
#define __DEG2RAD_OPERAND0__ "op mul %0 %0 " __XSTR(M_DEG2RAD) "\n"
#define __RAD2DEG_OPERAND1_OPERAND0__ "op mul %0 %1 " __XSTR(M_RAD2DEG) "\n"

// On mlog arch, we have __mlogev_function_return_value__


#define PURE_ARITHMETIC_FUNCTION inline __attribute__((pure)) __attribute__((const))

// TODO: 7.12.3 Classification macros

// 7.12.4 Trigonometric functions
PURE_ARITHMETIC_FUNCTION double acos(double x) {
    __asm__ (
        "op acos %0 %1 0\n"
        __DEG2RAD_OPERAND0__
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
    // return omitted
}

PURE_ARITHMETIC_FUNCTION double asin(double x) {
    __asm__ (
        "op asin %0 %1 0\n"
        __DEG2RAD_OPERAND0__
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
    // return omitted
}

PURE_ARITHMETIC_FUNCTION double atan(double x) {
    __asm__ (
        "op atan %0 %1 0\n"
        __DEG2RAD_OPERAND0__
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
}

PURE_ARITHMETIC_FUNCTION double atan2(double y, double x) {
    __asm__ (
        "op angle %0 %1 %2 \n"
        __DEG2RAD_OPERAND0__
        : "=r" (__mlogev_function_return_value__)
        : "r" (x), "r" (y)
    );
}

PURE_ARITHMETIC_FUNCTION double cos(double x) {
    __asm__ (
        __RAD2DEG_OPERAND1_OPERAND0__
        "op cos %0 %0 0\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
}

PURE_ARITHMETIC_FUNCTION double sin(double x) {
    __asm__ (
        __RAD2DEG_OPERAND1_OPERAND0__
        "op sin %0 %0 0\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
}

PURE_ARITHMETIC_FUNCTION double tan(double x) {
    __asm__ (
        __RAD2DEG_OPERAND1_OPERAND0__
        "op tan %0 %0 0\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
}
#include <mlogevo/arch_mlog/degree_measures.h>

// 7.12.5 Hyperbolic functions
// https://en.wikipedia.org/wiki/Hyperbolic_functions
PURE_ARITHMETIC_FUNCTION double acosh(double x) {
    double tmp;
    __asm__ (
        "op mul %1 %2 %2\n"
        "op sub %1 1\n"
        "op sqrt %1 %1 0\n"
        "op add %1 %1 %2\n"
        "op log %0 %1 0\n"
        : "=r" (__mlogev_function_return_value__), "=r" (tmp)
        : "r" (x)
    );
}

PURE_ARITHMETIC_FUNCTION double asinh(double x) {
    double tmp;
    __asm__ (
        "op mul %1 %2 %2\n"
        "op add %1 1\n"
        "op sqrt %1 %1 0\n"
        "op add %1 %1 %2\n"
        "op log %0 %1 0\n"
        : "=r" (__mlogev_function_return_value__), "=r" (tmp)
        : "r" (x)
    );
}

PURE_ARITHMETIC_FUNCTION double atanh(double x) {
    double tmp1, tmp2;
    __asm__ (
        "op add %1 1 %3\n"
        "op sub %2 1 %3\n"
        "op div %1 %1 %2\n"
        "op log %0 %1 0\n"
        "op div %0 %0 2\n"
        : "=r" (__mlogev_function_return_value__), "=r" (tmp1), "=r" (tmp2)
        : "r" (x)
    );
}

PURE_ARITHMETIC_FUNCTION double cosh(double x) {
    double tmp1, tmp2;
    __asm__ (
        "op pow %1 " __XSTR(M_E) " %3\n"
        "op sub %2 0 %3\n"
        "op pow %2 " __XSTR(M_E) " %2\n"
        "op add %1 %1 %2\n"
        "op div %0 %1 2\n"
        : "=r" (__mlogev_function_return_value__), "=r" (tmp1), "=r" (tmp2)
        : "r" (x)
    );
}

PURE_ARITHMETIC_FUNCTION double sinh(double x) {
    double tmp1, tmp2;
    __asm__ (
        "op pow %1 " __XSTR(M_E) " %3\n"
        "op sub %2 0 %3\n"
        "op pow %2 " __XSTR(M_E) " %2\n"
        "op sub %1 %1 %2\n"
        "op div %0 %1 2\n"
        : "=r" (__mlogev_function_return_value__), "=r" (tmp1), "=r" (tmp2)
        : "r" (x)
    );
}

PURE_ARITHMETIC_FUNCTION double tanh(double x) {
    double tmp;
    __asm__ (
        "op mul %1 %2 2\n"
        "op pow %1 " __XSTR(M_E) " %1\n"
        "op sub %0 %1 1\n"
        "op add %1 %1 1\n"
        "op div %0 %0 %1\n"
        : "=r" (__mlogev_function_return_value__), "=r" (tmp)
        : "r" (x)
    );
}

// 7.12.6 Exponential and logarithmic functions
PURE_ARITHMETIC_FUNCTION double exp(double x) {
    __asm__ (
        "op pow %0 " __XSTR(M_E) " %1\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
}

PURE_ARITHMETIC_FUNCTION double exp2(double x) {
    __asm__ (
        "op pow %0 2.0 %1\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
}

PURE_ARITHMETIC_FUNCTION double expm1(double x) {
    __asm__ (
        "op pow %0 " __XSTR(M_E) " %1\n"
        "op sub %0 %0 1\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
}
// TODO: ilogb, ldexp

PURE_ARITHMETIC_FUNCTION double log(double x) {
    __asm__ (
        "op log %0 %1 0\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
}

PURE_ARITHMETIC_FUNCTION double log10(double x) {
    __asm__ (
        "op log10 %0 %1 0\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
}

// TODO: For small magnitude x, log1p(x) is expected to be more accurate than log(1 + x)
PURE_ARITHMETIC_FUNCTION double log1p(double x) {
    double x1 = x + 1;
    __asm__ (
        "op log %0 %1 0\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x1)
    );
}

PURE_ARITHMETIC_FUNCTION double log2(double x) {
    __asm__ (
        "op log %0 %1 0\n"
        "op div %0 %0 " __XSTR(M_LN2)
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
}

// TODO: logb, modf, scalbn, scalbln
PURE_ARITHMETIC_FUNCTION double cbrt(double x) {
    __asm__ (
        // TODO: more precise cbrt
        "op pow %0 %1 0.3333333333333333\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
}

PURE_ARITHMETIC_FUNCTION double fabs(double x) {
    __asm__ (
        "op abs %0 %1 0\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
}

PURE_ARITHMETIC_FUNCTION double hypot(double x, double y) {
    __asm__ (
        "op len %0 %1 %2\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x), "r" (y)
    );
}

PURE_ARITHMETIC_FUNCTION double pow(double x, double y) {
    __asm__ (
        "op pow %0 %1 %2\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x), "r" (y)
    );
}

PURE_ARITHMETIC_FUNCTION double sqrt(double x) {
    __asm__ (
        "op sqrt %0 %1 0\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
}

// TODO: lgamma, tgamma
PURE_ARITHMETIC_FUNCTION double ceil(double x) {
    __asm__ (
        "op ceil %0 %1 0\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
}

PURE_ARITHMETIC_FUNCTION double floor(double x) {
    __asm__ (
        "op floor %0 %1 0\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
}
// TODO: nearbyint, rint, lrint, round, lround, llround, trunc
// TODO: fmod, remainder, remquo
// TODO: 7.12.11 copysign, nan, nextafter, nexttoward

// 7.12.12 Maximum, minimum, and positive difference functions
PURE_ARITHMETIC_FUNCTION double fdim(double x, double y) {
    __asm__ (
        "op sub %0 %1 %2\n"
        "op max %0 %0 0\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x), "r" (y)
    );
}

PURE_ARITHMETIC_FUNCTION double fmax(double x, double y) {
    __asm__ (
        "op max %0 %1 %2\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x), "r" (y)
    );
}

PURE_ARITHMETIC_FUNCTION double fmin(double x, double y) {
    __asm__ (
        "op min %0 %1 %2\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x), "r" (y)
    );
}

PURE_ARITHMETIC_FUNCTION double fmax(double x, double y) {
    __asm__ (
        "op max %0 %1 %2\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x), "r" (y)
    );
}

// TODO: fma

// Not part of C99 standard
PURE_ARITHMETIC_FUNCTION int _imin(int x, int y) {
    __asm__ (
        "op min %0 %1 %2\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x), "r" (y)
    );
}

PURE_ARITHMETIC_FUNCTION int _imax(int x, int y) {
    __asm__ (
        "op max %0 %1 %2\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x), "r" (y)
    );
}

#undef __RAD2DEG_OPERAND1_OPERAND0__
#undef __DEG2RAD_OPERAND0__
#undef __XSTR
#undef __STR
#undef PURE_ARITHMETIC_FUNCTION
#endif // __ARCH_MLOG_MATH_H__
