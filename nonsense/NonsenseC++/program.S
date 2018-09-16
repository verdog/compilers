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
// identifier: ID:a:-4
// integer: 4
// expression:integer: 4
// assignment: ID:a:-4 <- 4
mov %eax, 4
mov dword ptr [%ebp-4], %eax
// identifier: ID:b:-8
// integer: 2
// expression:integer: 2
// assignment: ID:b:-8 <- 2
mov %eax, 2
mov dword ptr [%ebp-8], %eax
// identifier: ID:c:-12
// identifier: ID:b:-8
// expression:identifier: ID:b:-8
// identifier: ID:a:-4
// expression:identifier: ID:a:-4
// mulitplication: dword ptr [%ebp-8] * dword ptr [%ebp-4]
mov %eax, dword ptr [%ebp-8]
imul %eax, dword ptr [%ebp-4]
// assignment: ID:c:-12 <- %eax
mov %eax, %eax
mov dword ptr [%ebp-12], %eax
// identifier: ID:c:-12
// expression:identifier: ID:c:-12
// output: dword ptr [%ebp-12]
push dword ptr [%ebp-12]
push offset flat:.io_format
call printf
add %esp, 8
// identifier: ID:c:-12
// identifier: ID:a:-4
// expression:identifier: ID:a:-4
// identifier: ID:b:-8
// expression:identifier: ID:b:-8
// mulitplication: dword ptr [%ebp-4] * dword ptr [%ebp-8]
mov %eax, dword ptr [%ebp-4]
imul %eax, dword ptr [%ebp-8]
// assignment: ID:c:-12 <- %eax
mov %eax, %eax
mov dword ptr [%ebp-12], %eax
// identifier: ID:c:-12
// expression:identifier: ID:c:-12
// output: dword ptr [%ebp-12]
push dword ptr [%ebp-12]
push offset flat:.io_format
call printf
add %esp, 8
leave
ret
