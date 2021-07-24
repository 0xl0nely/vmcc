#ifndef OPCODES_H
#define OPCODES_H
#include "bytecode.h"

#define R 1
#define W 2
#define X 4

typedef enum class {
// no operand instructions
    RET,
    SYSCALL,

// stos instruction copies size from r0 to wherever r1 is pointing to: rax -> rdi
    STOSB,
    STOSW,
    STOSD,
    STOSQ,

// single operand instructions
    JMP,
    JZ,
    JNZ, // no need for je/jne, they are the same
    JS,
    JG,
    JNS,
    JNG,
    NOT,
    INC,
    DEC,
    CALL,
    PUSH,
    POP,
    REP,   // repeat string instruction while equal
    REPNZ, // repeat while not equals\

// double operand instructions
    MOV,
    LEA,
    ADD,
    SUB,
    DIV,
    MUL,
    AND,
    OR,
    XOR,
    SAR,
    SAL,
    ROR,
    ROL,
    CMP,
    TEST,
};

/*
    no 8/16/32 bit compatibility, just 64 bit addressing mode
    we have the memory, we are going to use it >:)
*/

typedef enum class {
// 64 bit registers
    r0, // return register
    r1, // param 1
    r2, // param 2
    r3, // param 3
    r4,
    r5,
    r6,
    r7,
    r8,
    r9,
    bp,
    sp,
// special register
    ip
} registers;

typedef enum class {
    ZF,  // zero flag
    CF,  // carry flag
    SF,  // signed flag
    OF,  // overflow flag
} flags;

typedef enum class {
    BYTE,
    WORD,
    DWORD,
    QWORD
}size;

class CPU {
private:
    registers reg;
    flags flags;
public:
    CPU();
    ~CPU();





};

#endif
