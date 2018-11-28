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
   sub %esp, 16
#  Assignment: b := 2
   mov %edi, 2
   mov dword ptr [ %ebp-16 ], %edi
#  Cleared the register manager.
#  Array access: a[dword ptr [ %ebp-16 ]]
   mov %eax, dword ptr [ %ebp-16 ]
   sub %eax, 1
   mov %ebx, 4
   imul %ebx
   lea %ebx, dword ptr [ %ebp-12 ]
   add %ebx, %eax
   mov %edi, %ebx
#  Assignment: a := 2
   mov %esi, 2
   mov [%edi], %esi
#  Cleared the register manager.
#  Array access: a[2]
   mov %eax, 2
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
