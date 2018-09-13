.intel_syntax
.section .rodata
.io_format:
.string "%d\12\0"
.text
.globl main;
.type main, @function
main:
push %ebp
mov %ebp, %esp
sub %esp, 64
; identifier: ID:a:-4
; integer: 10
; expression:integer: 10
; assignment: ID:a:-4 <- 10
; identifier: ID:a:-4
; expression:integer: ID:a:-4
; output: -1918611696
push dword ptr [%ebp-4]
push offset flat:.io_format
call printf
add %esp, 8
leave
ret
