/* Unit control for mlog.
 * This file is part of MlogEvo "standard" library.
 */

#ifndef _ARCH_MLOG_UNIT_H
#define _ARCH_MLOG_UNIT_H

#include <mlogevo/arch_mlog/radar.h>

#define UNIT_BIND(type) __asm__ volatile("ubind " type)

inline void unit_bind(struct MlogObject type) {
    __asm__ volatile (
            "ubind %0"
            : /* no output */
            : "r" (type)
    );
}

inline void unit_idle() {
    __asm__ volatile ("ucontrol idle 0 0 0 0 0");
}

inline void unit_stop() {
    __asm__ volatile ("ucontrol idle 0 0 0 0 0");
}

inline void unit_move(double x, double y) {
    __asm__ volatile (
            "ucontrol move %0 %1 0 0 0"
            : : "r" (x), "r" (y)
    );
}

inline void unit_approach(double x, double y, double radius) {
    __asm__ volatile (
            "ucontrol approach %0 %1 %2 0 0"
            : : "r" (x), "r" (y), "r" (radius)
    );
}

#define unit_boost unit_toggle_boost
inline void unit_toggle_boost(int enable) {
    __asm__ volatile (
            "ucontrol boost %0 0 0 0 0"
            : : "r" (enable)
    );
}

// TODO: rename this?
inline void unit_target(double x, double y, int shoot) {
    __asm__ volatile (
            "ucontrol target %0 %1 %2 0 0"
            : : "r" (x), "r" (y), "r" (shoot)
    );
}

inline void unit_targetp(struct MlogObject target, int shoot) {
    __asm__ volatile (
            "ucontrol targetp %0 %1 0 0 0"
            : : "r" (target), "r" (shoot)
    );
}

inline void unit_drop_item(struct MlogObject building, int amount) {
    __asm__ volatile (
            "ucontrol itemDrop %0 %1 0 0 0"
            : : "r" (building), "r" (amount)
    );
}

inline void unit_take_item(struct MlogObject building, struct MlogObject item_type, int amount) {
    __asm__ volatile (
            "ucontrol itemTake %0 %1 %2 0 0"
            : : "r" (building), "r" (item_type), "r" (amount)
    );
}

#define UNIT_TAKE_ITEM(building, item_type_str, amount) \
    __asm__ volatile ( \
            "ucontrol itemTake %0 " item_type_str " %1 0 0" \
            : : "r" (building), "r" (amount) \
    )

inline void unit_drop_payload() {
    __asm__ volatile ("ucontrol payDrop 0 0 0 0 0");
}

inline void unit_take_payload(int take_units) {
    __asm__ volatile ("ucontrol payTake %0 0 0 0 0" : : "r" (take_units) );
}

inline void unit_enter_payload() {
    __asm__ volatile ("ucontrol payEnter 0 0 0 0 0");
}

inline void unit_mine(double x, double y) {
    __asm__ volatile (
            "ucontrol mine %0 %1 0 0 0"
            : : "r" (x), "r" (y)
    );
}

inline void unit_flag(double flag) {
    __asm__ volatile (
            "ucontrol flag %0 0 0 0 0"
            : : "r" (flag)
    );
}

inline void unit_build(double x, double y,
        struct MlogObject type, int rotation, struct MlogObject config) {
    __asm__ volatile (
            "ucontrol build %0 %1 %2 %3 %4"
            : : "r" (x), "r" (y), "r" (type), "r" (rotation), "r" (config)
    );
}

#define UNIT_GET_BLOCK(building_type, building, floor_type, x, y) \
    __asm__ ("ucontrol getBlock %3 %4 %0 %1 %2" \
            : "=r" (building_type), "=r" (building), "=r" (floor_type) \
            : "r" (x), "r" (y) )

#define unit_within unit_is_within
inline int unit_is_within(double x, double y, double radius) {
    __asm__ (
            "ucontrol within %1 %2 %3 %0 0"
            : "=r" (__mlogev_function_return_value__)
            : "r" (x), "r" (y), "r" (radius)
    );
}

inline void unit_unbind() {
    __asm__ volatile ("ucontrol unbind 0 0 0 0 0");
}

// TODO: unit locate

// extended part

inline double get_unit_flag() {
    __asm__ (
            "sensor %0 @unit @flag"
            : "=r" (__mlogev_function_return_value__)
    );
}

#endif //_ARCH_MLOG_UNIT_H
