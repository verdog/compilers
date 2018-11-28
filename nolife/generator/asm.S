#-------------------------------#
# nolife compiler               #
# Josh Chandler                 #
#-------------------------------#
   .intel_syntax
   .section .rodata
.io_format:
   .string "%d\12"
   .string "%f\12"
   .string "%c\12"
   .string "%s\12"
_constant:
.text
   .globl main;
   .type main, @function
main:
   push %ebp
   mov %ebp, %esp
   sub %esp, 12
#  Array access: a
   mov %eax, 1
   sub %eax, 1
   mov %ebx, 4
   imul %ebx
   lea %ebx, dword ptr [ %ebp-12 ]
   add %ebx, %eax
   mov %edi, %ebx
#  Assignment: a := 5
   mov %esi, 5
   mov [%edi], %esi
#  Cleared the register manager.
#  Array access: a
   mov %eax, 1
   sub %eax, 1
   mov %ebx, 4
   imul %ebx
   lea %ebx, dword ptr [ %ebp-12 ]
   add %ebx, %eax
   mov %edi, %ebx
#  Printing expression:
   push [%edi]
   push offset flat:.io_format
   call printf
   add %esp, 8
   leave
   ret
