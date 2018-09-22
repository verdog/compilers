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
// identifier: ID:c:-4
// integer: 8
// expression:integer: 8
// integer: 2
// expression:integer: 2
// negative: 2
// obtaining free location... got %edi!
mov %edi, 2
neg %edi
// clearing register 2
// /!\ tried to clear a nonexistant register 
// addition: 8 + %edi
// obtaining free location... got %esi!
mov %eax, 8
add %eax, %edi
mov %esi, %eax
// clearing register 8
// /!\ tried to clear a nonexistant register 
// assignment: ID:c:-4 <- %esi
mov %eax, %esi
mov dword ptr [%ebp-4], %eax
// clearing the register manager...
// identifier: ID:c:-4
// identifier: ID:c:-4
// expression:identifier: ID:c:-4
// negative: dword ptr [%ebp-4]
// obtaining free location... got %edi!
mov %edi, dword ptr [%ebp-4]
neg %edi
// clearing register dword ptr [%ebp-4]
// /!\ tried to clear a nonexistant register 
// assignment: ID:c:-4 <- %edi
mov %eax, %edi
mov dword ptr [%ebp-4], %eax
// clearing the register manager...
// identifier: ID:c:-4
// expression:identifier: ID:c:-4
// output: dword ptr [%ebp-4]
push dword ptr [%ebp-4]
push offset flat:.io_format
call printf
add %esp, 8
// clearing the register manager...
mov %eax, 0
leave
ret
