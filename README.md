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

## Todo

What is left to do is add support for comments. However I doubt that I would
actually bother with doing that.

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

An update, we have changed the definition of the Value type to a tagged union.
Now it can represent a number, a object type for OOP(which will be done later),
and a string.
```c
typedef struct {
  ValueType type;
  union {
    bool boolean;
    double number;
    Obj* obj;
  } as;
} Value;
```

There is still a lot of design decisions that I do not like. Like global
variables VM, and procedures with side effects. From what I can see the compiler
merely walks down an abstract tree as it passes by the source code, parses it
bit by bit, chunk by chunk and emits bytes as it goes trough. I do not
understand why there is no tree being built.

The main parsing is done with an array where each token gets assigned a parse
rule or not. I still do no understand how precedence is decided.

## Memory

From what I can see is that the main thing of concern is the lifetime of the
buffer where the `char *source` is held, that buffer needs to live long enough
to be used throughout the entirety of the program runtime.

Token lexemes are simply pointers and a length that need to be stored. This is
why the source needs to outlive the execution of the program.

I still have not gotten to the code where the Garbage collector is dealt with.

I might to once again look around for other compilers written in C or in other
languages. A C compiler written in Rust sounds like an adventure.

I might have to check out the REDOX OS project to learn more.

I will also have to start reading the "Writing a C compiler book". And see how
far the C programming language can actually take me

## Variables

It seems that variables are implemented by having some sort of global hash table
to hold all the variable names as strings, their hashes and stuff. I can see why
this is done but, I do not fully understand why. Maybe it is for sake of
simplicity of implementation.

I don't really understand the real difference between local and global variables
in terms of the actual implementation of the lox language in this book. They say
that they do not used seperate hash tables for different scopes but that is
difficult to believe. There is a sort of a Compiler struct that deals with the
scoping.

```c
typedef struct {
  Local locals[UINT8_COUNT];
  int local_count;
  int scope_depth;
} Compiler;
```

Yeah, this thing. Maybe there are seperate `Compiler` structs floating around,
and the state of the whole file switches between them whenever there is other
scopes to deal with.

I get scoping now. A number is representing the scope level is tracked. Variable
declared inside a scope are deleted once the scope exits.

## Performance

Profilers are very useful in measuring the performance of language, in particular
where in the language the language implementation/runtime spends most of its
time in doing.

Another optimization is dead code elimination, so that no time is spent in
compiling or running code that would never run. Very tricky to use with
profilers as some benchmark programs will be optimized away to absolutely
nothing. This field is a science in of itself.

`NaN` boxing is a concept that should studied further to be understood for being
something very interesting. It uses floats to store that efficiently, in
particular inside of the valid NAN values that the IEEE 754 standard defines, such
that useful information is stored inside of otherwise wasted space.

The amount of space available is enough to even store memory addresses, if the
correct offset is stored. Normal numbers remain floating point values, while
everything else fits.

## Ending

Unfortunately I really want to hurry up and finish this book so I can do my own
language design and implementation. Namely my first project will be a Scheme
bytecode compiler. Macros might be a bit more difficult. Its all symbols anyway
so it might be fine.

I skipped the NaN boxing section due to the fact that I don't understand the
architecture of this code nor do I wanna bother. I would rather have my own
implementation with my own design decisions.
