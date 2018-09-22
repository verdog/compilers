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
// expression:integer: 4
// assignment: ID:a:-4 <- 4
mov %eax, 4
mov dword ptr [%ebp-4], %eax
// re-openning all registers and temporary memory...
// expression:integer: 2
// assignment: ID:b:-8 <- 2
mov %eax, 2
mov dword ptr [%ebp-8], %eax
// re-openning all registers and temporary memory...
// expression:integer: 3
// assignment: ID:c:-12 <- 3
mov %eax, 3
mov dword ptr [%ebp-12], %eax
// re-openning all registers and temporary memory...
// expression:identifier: ID:a:-4
// expression:identifier: ID:b:-8
// expression:identifier: ID:c:-12
// exponent: dword ptr [%ebp-8] ^ dword ptr [%ebp-12]
// obtaining free location... got %edi!
// obtaining free location... got %edx!
// obtaining free location... got %esi!
mov %eax, 1
mov %edi, dword ptr [%ebp-8]
mov %edx, dword ptr [%ebp-12]
loop_0:
cmp %edx, 0
je loop_0_end
imul %edi
sub %edx, 1
jmp loop_0
loop_0_end:
mov %esi, %eax
// re-opened register dword ptr [%ebp-8]
// /!\ tried to re-open a nonexistant register 
// re-opened register dword ptr [%ebp-12]
// /!\ tried to re-open a nonexistant register 
// re-opened register %edi
// re-opened register %edx
// exponent: dword ptr [%ebp-4] ^ %esi
// obtaining free location... got %edi!
// obtaining free location... got %edx!
// obtaining free location... got %ecx!
mov %eax, 1
mov %edi, dword ptr [%ebp-4]
mov %edx, %esi
loop_1:
cmp %edx, 0
je loop_1_end
imul %edi
sub %edx, 1
jmp loop_1
loop_1_end:
mov %ecx, %eax
// re-opened register dword ptr [%ebp-4]
// /!\ tried to re-open a nonexistant register 
// re-opened register %esi
// re-opened register %edi
// re-opened register %edx
// assignment: ID:d:-16 <- %ecx
mov %eax, %ecx
mov dword ptr [%ebp-16], %eax
// re-openning all registers and temporary memory...
// expression:identifier: ID:d:-16
// output: dword ptr [%ebp-16]
push dword ptr [%ebp-16]
push offset flat:.io_format
call printf
add %esp, 8
// re-openning all registers and temporary memory...
mov %eax, 0
leave
ret
