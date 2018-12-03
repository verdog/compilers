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
.io_format_in:
   .string "%d"
   .string "%f"
   .string "%c"
_constant:
   .float 9.8
.text
   .globl main;
   .type main, @function
main:
   push %ebp
   mov %ebp, %esp
   sub %esp, 4
#  Converting float to int
   push [ _constant + 0 ]
   fld dword ptr [ %esp ]
   fisttp dword ptr [ %esp ]
   pop %edi
#  Assignment: a := %edi
   mov %esi, %edi
   mov dword ptr [ %ebp-4 ], %esi
#  Cleared the register manager.
#  Printing expression: (NON-FLOAT)
   push dword ptr [ %ebp-4 ]
   push offset .io_format
   call printf
   add %esp, 8
#  Return 0
   mov %eax, 0
   leave
   ret
