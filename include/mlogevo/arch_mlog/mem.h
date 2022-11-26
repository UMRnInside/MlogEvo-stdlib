/* Memory r/w for mlog.
 * This file is part of MlogEvo "standard" library.
 */

#ifndef _ARCH_MLOG_MEM_H
#define _ARCH_MLOG_MEM_H
#define memwrite_f64 memwrite
#define memread_f64 memread

inline void memwrite_i32(struct MlogObject cell, int pos, int value) {
    __asm__ volatile (
            "write %2 %0 %1"
            : /* no output */
            : "r" (cell), "r" (pos), "r" (value)
    );
}

inline void memwrite(struct MlogObject cell, int pos, double value) {
    __asm__ volatile (
            "write %2 %0 %1"
            : /* no output */
            : "r" (cell), "r" (pos), "r" (value)
    );
}

inline int memread_i32(struct MlogObject cell, int pos) {
    __asm__  (
            "read %0 %1 %2"
            : "=r" (__mlogev_function_return_value__)
            : "r" (cell), "r" (pos)
    );
}

inline double memread(struct MlogObject cell, int pos) {
    __asm__  (
            "read %0 %1 %2"
            : "=r" (__mlogev_function_return_value__)
            : "r" (cell), "r" (pos)
    );
}

#endif //_ARCH_MLOG_MEM_H
