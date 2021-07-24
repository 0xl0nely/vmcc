# VMCC Documentation

Alright, lets first talk about the internals, and the choices that were made
when implementing this project. If you would like to directly contribute to
the project, you can read through this section of the doc to get a better
understanding of the implementation.

## Architecture

* Summary

The virtual machine runs it's own custom architecture that only supports 64
bit addressing modes. Since practically all cpu's support 64 bit addressing
and I have no intention of supporting IOT/embedded devices; this was the most
efficient way to make use of the resources that are available to us.

Lets go over the registers, the general purpose register's naming was based
off of the ARM architecture, the calling convention was based off of x86's
cdecl; and the return register, instruction pointer, and stack pointers
were all based off of x86.

* Registers

| Registers       | Description                                  |
| -------------   | --------------------------------------------:|
| Reg0            | General purpose. Used to store return values |
| Reg1            | General purpose.                             |
| Reg2            | General purpose.                             |
| Reg3            | General purpose.                             |
| Reg4            | General purpose.                             |
| Reg5            | General purpose.                             |
| Reg6            | General purpose.                             |
| Esp             | Stack pointer. Points to the top of the stack|





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