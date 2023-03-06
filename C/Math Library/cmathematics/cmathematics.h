#ifndef CMATHEMATICS_H
#define CMATHEMATICS_H

typedef unsigned char bool;
#define false 0
#define true 1



/**
 * @brief In GCC, the preprocessor eliminate the comma in
 *  , ##__VA_ARGS__ 
 *  More info: __VA_ARGS__
 * https://renenyffenegger.ch/notes/development/languages/C-C-plus-plus/preprocessor/macros/__VA_ARGS__/count-arguments
 * 
 */


#define NUMARGS(type, ...) (sizeof((type[]){0.0f, ##__VA_ARGS__}) / sizeof(type) - 1)

#define MAX(i1, i2) (i1 > i2 ? i1 : i2)


#endif // CMATHEMATICS_H