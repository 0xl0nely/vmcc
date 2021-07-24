# VMCC Documentation

Alright, lets first talk about the internals, and the choices that were made
when implementing this project. If you would like to directly contribute to
the project, you can read through this section of the doc to get a better
understanding of the implementation.

## Architecture

### Summary

The virtual machine runs it's own custom architecture that only supports 64
bit addressing modes. Since practically all cpu's support 64 bit addressing
and I have no intention of supporting IOT/embedded devices; this was the most
efficient way to make use of the resources that are available to us.

Lets go over the registers, the general purpose register's naming was based
off of the ARM architecture, the calling convention was based off of x86's
cdecl; and the return register, instruction pointer, and stack pointers
were all based off of x86.

Another important thing to note here, the assembler abides by the intel syntax.

### Registers

Note: Despite their names that resemble x86's 16 bit naming conventions, each
of these registers are 64 bits wide.

| Registers     | Description                                    |
| ------------- | ----------------------------------------------:|
| r0            | General Purpose Register; Stores Return Values |
| r1            | Destination Register; First Argument           |
| r2            | Source Register; Second Argument               |
| r3            | General purpose Register; Third Argument       |
| r4-r9         | General Purpose Registers                      | 
| sp            | Stack Pointer                                  |
| bp            | Base Pointer                                   |
| ip            | Instruction pointer                            |

### Instructions

These are all of the supported instructions of VMCC's architecture.

| Instruction   | Description                                                               |
| ------------- | -------------------------------------------------------------------------:|
| RET           | Returns from procedure, pop's value from stack, into instruction pointer  |
| SYSCALL       | Executes Systen Call; r0, r1, r2, r3                                      |
| STOSB         | Store String (Byte); r0 -> r1                                             |
| STOSW         | Store String (Word); r0 -> r1                                             |
| STOSD         | Store String (Dword); r0 -> r1                                            |
| STOSQ         | Store String (Qword); r0 -> r1                                            |
| JMP           | Jump to reference                                                         |
| JZ            | Jump if zero                                                              |
| JNZ           | Jump if not zero                                                          |
| JS            | Jump if smaller than                                                      |
| JG            | Jump if greater than                                                      |
| JNS           | Jump not smaller than                                                     |
| JNG           | Jump not greater than                                                     |
| NOT           | Perform Bitwise NOT on operand                                            |
| INC           | Increment Operand                                                         |
| DEC           | Decrement Operand                                                         |
| CALL          | Call Subroutine                                                           |
| PUSH          | Push specified size on stack                                              |
| POP           | Pop value off stack, and into operand                                     |
| REP           | Repeat String Operation While Zero                                        |
| REPNZ         | Repeat String Operation While Not Zero                                    |
| MOV           | Move specified value from left operand into right operand                 |
| LEA           | Load effective address from second operand, and store into first operand  |
| ADD           | Add second operand to first operand, and store in first operand           |
| SUB           | Sub second operand to first operand, and store in first operand           |
| DIV           | Div first and secomd operand, store quotient in r0 and remainder in r3    |
| MUL           | Multiply second operand to first operand, and store in first operand      |
| MOD           | Modulus first and second operand, result stored in r0                     |
| AND           | Bitwise AND operation on first and second operand, store in first operand |
| OR            | Bitwise OR operation on first and second operand, store in first operand  |
| XOR           | Bitwise XOR operation on first and second operand, store in first operand |
| SAR           | Bitwise Shift Right                                                       |
| SAL           | Bitwise Shift Left                                                        |
| ROR           | Bitwise Rotate Right                                                      |
| ROL           | Bitwise Rotate Left                                                       |
| CMP           | Compare left operand with right operand                                   |
| TEST          | Performs bitwise AND instruction, and sets bit flags; result discarded    |


## Lexical Analysis
## Parsing into AST
## Semantic Analysis
## Bytecode File Format
## Code Generation
## Bytecode Loading & Initialization Process
## Heap Environment
## Dynamic Memory Allocator
## Syscall Implementation
## Sandboxing
## LIBC
## Bytecode Static and Dynamic Analysis
