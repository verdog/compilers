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
.text
   .globl main;
   .type main, @function
main:
   push %ebp
   mov %ebp, %esp
   sub %esp, 4
   # Converting int to float
   push 4
   fild dword ptr [ %esp ]
   fstp dword ptr [ %esp ]
   pop %edi
#  Assignment: a := %edi
   mov %esi, %edi
   mov dword ptr [ %ebp-4 ], %esi
#  Cleared the register manager.
   # Converting int to float
   push 4
   fild dword ptr [ %esp ]
   fstp dword ptr [ %esp ]
   pop %edi
#  dword ptr [ %ebp-4 ] * %edi (FLOAT)
   push dword ptr [ %ebp-4 ]
   fld dword ptr [ %esp ]
   push %edi
   fmul dword ptr [ %esp ]
   add %esp, 4
   fstp dword ptr [ %esp ] 
   pop %esi
#  Printing expression: (FLOAT)
   sub %esp, 4
   push %esi
   fld dword ptr [ %esp ]
   fstp qword ptr [ %esp ]
   push [ offset .io_format + 4 ]
   call printf
   add %esp, 12
   # Converting int to float
   push 4
   fild dword ptr [ %esp ]
   fstp dword ptr [ %esp ]
   pop %edi
#  dword ptr [ %ebp-4 ] + %edi (FLOAT)
   push dword ptr [ %ebp-4 ]
   fld dword ptr [ %esp ]
   push %edi
   fadd dword ptr [ %esp ]
   add %esp, 4
   fstp dword ptr [ %esp ] 
   pop %esi
#  Printing expression: (FLOAT)
   sub %esp, 4
   push %esi
   fld dword ptr [ %esp ]
   fstp qword ptr [ %esp ]
   push [ offset .io_format + 4 ]
   call printf
   add %esp, 12
   # Converting int to float
   push 4
   fild dword ptr [ %esp ]
   fstp dword ptr [ %esp ]
   pop %edi
#  dword ptr [ %ebp-4 ] - %edi (FLOAT)
   push dword ptr [ %ebp-4 ]
   fld dword ptr [ %esp ]
   push %edi
   fsub dword ptr [ %esp ]
   add %esp, 4
   fstp dword ptr [ %esp ] 
   pop %esi
#  Printing expression: (FLOAT)
   sub %esp, 4
   push %esi
   fld dword ptr [ %esp ]
   fstp qword ptr [ %esp ]
   push [ offset .io_format + 4 ]
   call printf
   add %esp, 12
#  Return 0
   mov %eax, 0
   leave
   ret
