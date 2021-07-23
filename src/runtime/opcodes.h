#ifndef OPCODES_H
#define OPCODES_H

typedef enum class {
// no operand instructions
    RET,
    SYSCALL,
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

class CPU {
private:
    registers reg;
    flags flags;
public:
    CPU();
    ~CPU();





};

class BYTECODE_FORMAT







#endif
