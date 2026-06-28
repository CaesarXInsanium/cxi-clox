#ifndef clox_compiler_h
#define clox_compiler_h
#include <stdbool.h>
typedef struct ObjFunction ObjFunction;
ObjFunction* compile(const char* source);
void mark_compiler_roots(void);
#endif
