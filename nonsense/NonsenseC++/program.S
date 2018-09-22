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
// division: 8 / 2
// obtaining free location... got %edi!
// obtaining free location... got %esi!
mov %eax, 8
mov %esi, 2
cdq
idiv %esi
mov %edi, %eax
// re-opened register 8
// /!\ tried to re-open a nonexistant register 
// re-opened register 2
// /!\ tried to re-open a nonexistant register 
// re-opened register %esi
// assignment: ID:c:-4 <- %edi
mov %eax, %edi
mov dword ptr [%ebp-4], %eax
// re-openning all registers/temporary memory...
// identifier: ID:c:-4
// expression:identifier: ID:c:-4
// output: dword ptr [%ebp-4]
push dword ptr [%ebp-4]
push offset flat:.io_format
call printf
add %esp, 8
// re-openning all registers/temporary memory...
mov %eax, 0
leave
ret
