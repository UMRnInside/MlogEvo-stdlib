/* Declarations and implementations for block control functions. 
 * does not include drawflush/printflush and radar.
 * This file is part of MlogEvo "standard" library
 */
#ifndef _ARCH_MLOG_BLOCK_CONTROL_H
#define _ARCH_MLOG_BLOCK_CONTROL_H
#define __STR(x) #x

#ifdef MLOGEV_VOLATILE_CONTROL_WANTED
#define ASM_QUALIFIER volatile
#else
#define ASM_QUALIFIER
#endif

// On mlog arch, we have __mlogev_function_return_value__
// NOTE: drawflush/printflush is not defined here

inline struct MlogObject getlink(int i) {
    __asm__ ASM_QUALIFIER (
            "gelink %0 %1"
            : "=r" (__mlogev_function_return_value__)
            : "r" (i)
    );
}

#define control_enabled control_toggle
inline void
control_toggle(struct MlogObject building, int status) {
    __asm__ ASM_QUALIFIER (
            "control enabled %0 %1 0 0 0"
            : /* no output */
            : "r" (building), "r" (status)
    );
}

inline void
control_shoot(struct MlogObject turret, double x, double y, int should_shoot) {
    __asm__ ASM_QUALIFIER (
            "control shoot %0 %1 %2 %3 0"
            : /* no output */
            : "r" (turret), "r" (x), "r" (y), "r" (should_shoot)
    );
}

inline void 
control_shootp(struct MlogObject turret, struct MlogObject target, int should_shoot) {
    __asm__ ASM_QUALIFIER (
            "control shootp %0 %1 %2 %3 0"
            : /* no output */
            : "r" (turret), "r" (target), "r" (should_shoot)
    );
}

inline void
control_config(struct MlogObject building, struct MlogObject config) {
    __asm__ ASM_QUALIFIER (
            "control config %0 %1 0 0 0"
            : /* no output */
            : "r" (building), "r" (config)
    );
}

inline void
control_color(struct MlogObject illuminator, double packed_color) {
    __asm__ ASM_QUALIFIER (
            "control color %0 %1 0 0 0"
            : /* no output */
            : "r" (illuminator), "r" (packed_color)
    );
}

#undef __STR
#undef ASM_QUALIFIER
#endif // __ARCH_MLOG_BLOCK_CONTROL_H__
