#ifndef clox_chunk_h
#define clox_chunk_h
#include "common.h"
#include "memory.h"
#include "value.h"
#include <stddef.h>
#include <stdint.h>

typedef enum {
  OP_RETURN,
  OP_CONSTANT,
} OpCode;

typedef struct {
  int count;
  int capacity;
  uint8_t* code;
  ValueArray constants;
} Chunk;

void init_chunk(Chunk* chunk);
void write_chunk(Chunk* chunk, uint8_t byte);
int add_constant(Chunk* chunk, Value value);
void free_chunk(Chunk* chunk);

#endif
