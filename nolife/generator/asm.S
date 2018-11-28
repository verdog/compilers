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
   sub %esp, 4
#  Assignment: a := 7
   mov %edi, 7
   mov dword ptr [ %ebp-4 ], %edi
#  Cleared the register manager.
   # dword ptr [ %ebp-4 ] % 4
   xor %edx, %edx
   mov %eax, dword ptr [ %ebp-4 ]
   mov %edi, 4
   idiv %edi
   mov %edi, %edx
#  Assignment: a := %edi
   mov %esi, %edi
   mov dword ptr [ %ebp-4 ], %esi
#  Cleared the register manager.
#  Printing expression:
   push dword ptr [ %ebp-4 ]
   push offset flat:.io_format
   call printf
   add %esp, 8
   # Return 0
   mov %eax, 0
   leave
   ret
