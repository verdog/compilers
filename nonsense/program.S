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
// expression:integer: 10
// assignment: ID:a:-4 <- 10
mov %eax, 10
mov dword ptr [%ebp-4], %eax
// re-openning all registers and temporary memory...
// expression:identifier: ID:a:-4
// output: dword ptr [%ebp-4]
push dword ptr [%ebp-4]
push offset flat:.io_format
call printf
add %esp, 8
// re-openning all registers and temporary memory...
mov %eax, 0
leave
ret
