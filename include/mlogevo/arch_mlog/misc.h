/* Misc
 * This file is part of MlogEvo "standard" library.
 */

#ifndef _ARCH_MLOG_MISC_H
#define _ARCH_MLOG_MISC_H

#define OBJECT_FROM_NAME(output,name) \
    __asm__ ("set %0 " name "" : "=r"(output) )

inline void halt() {
    __asm__ volatile ("stop");
}

inline void wait(double seconds) {
    __asm__ volatile ("wait %0" : : "r"(seconds) );
}

inline double randfloat(double max) {
    __asm__ ("op rand %0 %1 0" 
            : "=r" (__mlogev_function_return_value__)
            : "r" (max) );
}

#endif //_ARCH_MLOG_MISC_H
