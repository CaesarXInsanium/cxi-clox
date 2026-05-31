# Lox: C Language Implementation

This will be my work in implementing the Lox programming language in C. I might
make other implementations in other languages.
I will try to get into English words how exactly everything works around in this
project. The reason is to that I can design and write my own version that
actually works.

The `chunk` structure is basically a dynamic array where each byte is an 
instruction. The vm is stack based, values are push unto the stack, operations
pop them off of the stack.

The main `interpret` procedure will iterate over the bytes and do the
instructions that are shown. At the end all of the related memory must be freed.

## Instructions

To interpret the instructions, first the vm must be reset. The program
counter or instruction pointer must be set to very first element in the chunks.

The VM itself is a global variable defined in `vm.c`. This is a decision meant
to keep the architecture of this project relatively simple.

The place where main work occurs is in `run()`. Here is where the iteration over
the bytes that make up the instructions is done. The work is done in a big
switch statement.

## Constants

For the moment all numbers are actually doubles, or in practice they seem to be
64-bit floating point.

```c
typedef double Value;
```

## Memory

From what I can see is that the main thing of concern is the lifetime of the
buffer where the `char *source` is held, that buffer needs to life long enough
to be used throughout the entirety of the program runtime.

Token lexemes are simply pointers and a length that need to be stored. This is
why the source needs to outlive the execution of the program.
