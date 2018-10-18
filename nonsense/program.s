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
// obtaining free location... got %esi!
// obtaining free location... got %ecx!
mov %eax, 1
mov %edi, dword ptr [%ebp-8]
mov %esi, dword ptr [%ebp-12]
loop_0:
cmp %esi, 0
je loop_0_end
imul %edi
sub %esi, 1
jmp loop_0
loop_0_end:
mov %ecx, %eax
// re-opened register dword ptr [%ebp-8]
// /!\ tried to re-open a nonexistant register 
// re-opened register dword ptr [%ebp-12]
// /!\ tried to re-open a nonexistant register 
// re-opened register %edi
// re-opened register %esi
// exponent: dword ptr [%ebp-4] ^ %ecx
// obtaining free location... got %edi!
// obtaining free location... got %esi!
// obtaining free location... got %edx!
mov %eax, 1
mov %edi, dword ptr [%ebp-4]
mov %esi, %ecx
loop_1:
cmp %esi, 0
je loop_1_end
imul %edi
sub %esi, 1
jmp loop_1
loop_1_end:
mov %edx, %eax
// re-opened register dword ptr [%ebp-4]
// /!\ tried to re-open a nonexistant register 
// re-opened register %ecx
// re-opened register %edi
// re-opened register %esi
// assignment: ID:d:-16 <- %edx
mov %eax, %edx
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

