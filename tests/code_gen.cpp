/*
    efficient code generation is pretty hard, but i guess we can follow in the footsteps of gcc senpai

    an interesting observation that i had noticed were that the major compilers had left out the
    subtraction operation on the stack pointer. This is a very smart thing to do, as there is no
    need to unless we are planning on saving our stack frames memory.

    without subtracting/growing the stack towards lower memory addresses, this means that
    currently, rbp and rsp both point to the same location.

    which means that, if we push/pop; we can still access that data through the rbp register so it
    wont be writing data into random memory.

    if we are to call another function, then we will have to establish another stack frame; as to
    not tamper with the current subroutine's stack frame. This is pretty basic stuff that im sure
    you've already learned in your cs class.
*/
