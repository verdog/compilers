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
   .float 2.0
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
#  Assignment: a := [ offset flat:_constant + 0 ]
   mov %esi, [ offset flat:_constant + 0 ]
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
#  Printing float constant
   sub %esp, 8
   mov %esi, [%edi]
   fld dword ptr [%esi]
   fstp qword ptr [%esp]
   push [ offset flat:.io_format + 4 ]
   call printf
   add %esp, 12
   leave
   ret
