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
   .float 4.0
.text
   .globl main;
   .type main, @function
main:
   push %ebp
   mov %ebp, %esp
   sub %esp, 4
#  Converting int to float
   push 4
   fild dword ptr [ %esp ]
   fstp dword ptr [ %esp ]
   pop %edi
#  %edi + [ _constant + 0 ] (FLOAT)
   push %edi
   fld dword ptr [ %esp ]
   push [ _constant + 0 ]
   fadd dword ptr [ %esp ]
   add %esp, 4
   fstp dword ptr [ %esp ] 
   pop %esi
#  Assignment: a := %esi
   push %esi
   fld dword ptr [%esp]
   add %esp, 4
   fstp dword ptr [%ebp - 4]
#  Cleared the register manager.
#  Printing expression: (FLOAT)
   sub %esp, 4
   push dword ptr [ %ebp-4 ]
   fld dword ptr [ %esp ]
   fstp qword ptr [ %esp ]
   push [ offset .io_format + 4 ]
   call printf
   add %esp, 12
#  Return 0
   mov %eax, 0
   leave
   ret
