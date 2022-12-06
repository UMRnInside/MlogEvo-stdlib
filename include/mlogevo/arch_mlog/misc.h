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

#endif //_ARCH_MLOG_MISC_H
