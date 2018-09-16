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
// identifier: ID:x:-4
// integer: 2
// expression:integer: 2
// integer: 3
// expression:integer: 3
// mulitplication: 2 * 3
// obtaining free location... got %edi!
mov %eax, 2
imul %eax, 3
mov %edi, %eax
// integer: 6
// expression:integer: 6
// division: %edi / 6
// obtaining free location... got %esi!
mov %eax, %edi
mov %ebx, 6
cdq
idiv %ebx
mov %esi, %eax
// integer: 1
// expression:integer: 1
// integer: 1
// expression:integer: 1
// addition: 1 + 1
// obtaining free location... got %ecx!
mov %eax, 1
add %eax, 1
mov %ecx, %eax
// integer: 1
// expression:integer: 1
// addition: %ecx + 1
// obtaining free location... got %edx!
mov %eax, %ecx
add %eax, 1
mov %edx, %eax
// integer: 1
// expression:integer: 1
// addition: %edx + 1
// obtaining free location... got dword ptr [%ebp-68]!
sub %esp, 4
mov %eax, %edx
add %eax, 1
mov dword ptr [%ebp-68], %eax
// integer: 1
// expression:integer: 1
// addition: dword ptr [%ebp-68] + 1
// obtaining free location... got dword ptr [%ebp-72]!
sub %esp, 4
mov %eax, dword ptr [%ebp-68]
add %eax, 1
mov dword ptr [%ebp-72], %eax
// integer: 1
// expression:integer: 1
// addition: dword ptr [%ebp-72] + 1
// obtaining free location... got dword ptr [%ebp-76]!
sub %esp, 4
mov %eax, dword ptr [%ebp-72]
add %eax, 1
mov dword ptr [%ebp-76], %eax
// integer: 1
// expression:integer: 1
// subtraction: dword ptr [%ebp-76] - 1
// obtaining free location... got dword ptr [%ebp-80]!
sub %esp, 4
mov %eax, dword ptr [%ebp-76]
sub %eax, 1
mov dword ptr [%ebp-80], %eax
// expression:parens: dword ptr [%ebp-80]
// addition: %esi + dword ptr [%ebp-80]
// obtaining free location... got dword ptr [%ebp-84]!
sub %esp, 4
mov %eax, %esi
add %eax, dword ptr [%ebp-80]
mov dword ptr [%ebp-84], %eax
// assignment: ID:x:-4 <- dword ptr [%ebp-84]
mov %eax, dword ptr [%ebp-84]
mov dword ptr [%ebp-4], %eax
// clearing the register manager...
add %esp, 20
// identifier: ID:x:-4
// expression:identifier: ID:x:-4
// output: dword ptr [%ebp-4]
push dword ptr [%ebp-4]
push offset flat:.io_format
call printf
add %esp, 8
// clearing the register manager...
add %esp, 20
mov %eax, 0
leave
ret
