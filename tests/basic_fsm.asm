; 0 = false ; 1 = true
; states are 0, 1, 2
; i guess rdx is our state counter
section .text
global read_commands
global _strlen
read_commands:;(const char* commands)
    push rbp
    mov rbp, rsp
    push rdx
    push rcx
    mov rdx, 0 ; q1, initial state
    xor rcx, rcx
_state_loop:
    mov al, byte [rdi+rcx]
    cmp al, 0
    jz _read_commands_halt
    ; usage of jump zero, greater, and less than means we only need 1 cmp; which is nice
    cmp rdx, 1
    jz _q2_sub
    jg _q3_sub
    jl _q1_sub
    jmp _exit   ; if something goes wrong, we want to terminate
_q1_sub:
    cmp al, 0x30
    jz _state_loop_reset
    mov rdx, 1
    jmp _state_loop_reset
_q2_sub:
    cmp al, 0x31
    jz _state_loop_reset
    mov rdx, 2
    jmp _state_loop_reset
_q3_sub:
    mov rdx, 1
_state_loop_reset:
    inc rcx
    jmp _state_loop
_read_commands_halt:
    cmp rdx, 1
    jz _true
    jmp _false
_true:
    mov rdx, 1
    jmp _end
_false:
    mov rdx, 0
_end:
    mov rax, rdx
    pop rcx
    pop rdx
    pop rbp
    ret
_exit:
    mov rax, 60
    mov rdi, 0
    syscall
    ret
