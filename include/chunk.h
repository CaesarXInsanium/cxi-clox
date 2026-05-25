#ifndef clox_chunk_h
#define clox_chunk_h
#include "common.h"
#include "memory.h"
#include "value.h"
#include <stddef.h>
#include <stdint.h>

typedef uint8_t OpCode;
#define  OP_RETURN 0
#define OP_CONSTANT 1
#define OP_ADD 2
#define OP_SUBTRACT 3
#define OP_MULTIPLY 4
#define OP_DIVIDE 5
#define OP_NEGATE 6

typedef struct {
  int count;
  int capacity;
  uint8_t* code;
  int* lines;
  ValueArray constants;
} Chunk;

void init_chunk(Chunk* chunk);
void write_chunk(Chunk* chunk, uint8_t byte, int line);
int add_constant(Chunk* chunk, Value value);
void free_chunk(Chunk* chunk);

#endif
