/* Trigonometric functions in degree measures.
 * They're faster on Mlog arch
 */
#ifndef _ARCH_MLOG_DEGREE_MEASURES_H
#define _ARCH_MLOG_DEGREE_MEASURES_H

PURE_ARITHMETIC_FUNCTION double acos_degm(double x) {
    __asm__ (
        "op acos %0 %1 0\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
    // return omitted
}

PURE_ARITHMETIC_FUNCTION double asin_degm(double x) {
    __asm__ (
        "op asin %0 %1 0\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
    // return omitted
}

PURE_ARITHMETIC_FUNCTION double atan_degm(double x) {
    __asm__ (
        "op angle %0 %1 0\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
}

PURE_ARITHMETIC_FUNCTION double atan2_degm(double y, double x) {
    __asm__ (
        "op angle %0 %1 %2 \n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x), "r" (y)
    );
}

PURE_ARITHMETIC_FUNCTION double cos_degm(double x) {
    __asm__ (
        "op cos %0 %1 0\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
}

PURE_ARITHMETIC_FUNCTION double sin_degm(double x) {
    __asm__ (
        "op sin %0 %1 0\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
}

PURE_ARITHMETIC_FUNCTION double tan_degm(double x) {
    __asm__ (
        "op tan %0 %1 0\n"
        : "=r" (__mlogev_function_return_value__)
        : "r" (x)
    );
}

#endif // _ARCH_MLOG_DEGREE_MEASURES_H
