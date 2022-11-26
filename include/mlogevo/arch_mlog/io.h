/* Message board, Display and SENSOR for mlog.
 * This file is part of MlogEvo "standard" library.
 */

#ifndef _ARCH_MLOG_IO_H
#define _ARCH_MLOG_IO_H

#define SENSOR(result, attribute, target_object) \
    __asm__ ("sensor %0 %1 " attribute "" \
            : "=r" (result) \
            : "r" (target_object) )

#define PRINT_STRING(string_literal) \
    __asm__ volatile ("print \"" string_literal "\"" )

inline void print_object(struct MlogObject object) {
    __asm__ volatile (
            "print %0"
            : /* no output */
            : "r" (object)
    );
}

inline void print_double(double x) {
    __asm__ volatile (
            "print %0"
            : /* no output */
            : "r" (x)
    );
}

inline void print_int(int x) {
    __asm__ volatile (
            "print %0"
            : /* no output */
            : "r" (x)
    );
}

#define printflush print_flush
inline void print_flush(struct MlogObject message_board) {
    __asm__ volatile (
            "printflush %0"
            : /* no output */
            : "r" (message_board)
    );
}

inline void draw_clear(double r, double g, double b) {
    __asm__ volatile (
            "draw clear %0 %1 %2 0 0 0"
            :
            : "r" (r), "r" (g), "r" (b)
    );
}

inline void draw_set_color(double r, double g, double b, double alpha) {
    __asm__ volatile (
            "draw color %0 %1 %2 %3 0 0"
            :
            : "r" (r), "r" (g), "r" (b), "r" (alpha)
    );
}

inline void draw_set_stroke(double width) {
    __asm__ volatile (
            "draw stroke %0 0 0 0 0 0"
            :
            : "r" (width)
    );
}

inline void draw_line(double x1, double y1, double x2, double y2) {
    __asm__ volatile (
            "draw line %0 %1 %2 %3 0 0"
            :
            : "r" (x1), "r" (y1), "r" (x2), "r" (y2)
    );
}

inline void draw_rectangle(double x, double y, double width, double height) {
    __asm__ volatile (
            "draw rect %0 %1 %2 %3 0 0"
            :
            : "r" (x), "r" (y), "r" (width), "r" (height)
    );
}

inline void draw_rectangle_border(double x, double y, double width, double height) {
    __asm__ volatile (
            "draw lineRect %0 %1 %2 %3 0 0"
            :
            : "r" (x), "r" (y), "r" (width), "r" (height)
    );
}

inline void draw_polygon(double x, double y, int sides, double radius, double rotation) {
    __asm__ volatile (
            "draw poly %0 %1 %2 %3 %4 0"
            :
            : "r" (x), "r" (y), "r" (sides), "r" (radius), "r" (rotation)
    );
}

inline void draw_polygon_border(double x, double y, int sides, double radius, double rotation) {
    __asm__ volatile (
            "draw linePoly %0 %1 %2 %3 %4 0"
            :
            : "r" (x), "r" (y), "r" (sides), "r" (radius), "r" (rotation)
    );
}

inline void draw_triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    __asm__ volatile (
            "draw triangle %0 %1 %2 %3 %4 %5"
            :
            : "r" (x1), "r" (y1), "r" (x2), "r" (y2), "r" (x3), "r" (y3)
    );
}

inline void draw_triangle_border(double x1, double y1, double x2, double y2, double x3, double y3) {
    __asm__ volatile (
            "draw line %0 %1 %2 %3 0 0\n"
            "draw line %0 %1 %4 %5 0 0\n"
            "draw line %2 %3 %4 %5 0 0"
            :
            : "r" (x1), "r" (y1), "r" (x2), "r" (y2), "r" (x3), "r" (y3)
    );
}

inline void draw_image(double x, double y, struct MlogObject object, double size, double rotation) {
    __asm__ volatile (
            "draw image %0 %1 %2 %3 %4 0"
            :
            : "r" (x), "r" (y), "r" (object), "r" (size), "r" (rotation)
    );
}

#define DRAW_IMAGE(x, y, object, size, rotation) \
    __asm__ volatile ( \
            "draw image %0 %1 " object " %2 %3 0" \
            : \
            : "r" (x), "r" (y), "r" (size), "r" (rotation) \
    )

inline void draw_image(double x, double y, struct MlogObject object, double size, double rotation) {
    __asm__ volatile (
            "draw image %0 %1 %2 %3 %4 0" 
            :
            : "r" (x), "r" (y), "r" (object), "r" (size), "r" (rotation)
    );
}



#define drawflush draw_flush
inline void draw_flush(struct MlogObject display) {
    __asm__ volatile (
            "drawflush %0"
            : /* no output */
            : "r" (display)
    );
}

#endif //_ARCH_MLOG_IO_H
