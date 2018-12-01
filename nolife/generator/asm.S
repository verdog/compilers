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
   .float 10.0
   .float 5.0
.text
   .globl main;
   .type main, @function
main:
   push %ebp
   mov %ebp, %esp
   sub %esp, 4
   # [ offset _constant + 0 ] + [ offset _constant + 4 ] (FLOAT)
   mov %eax, [ offset _constant + 0 ]
   fld dword ptr [ %eax ]
   mov %eax, [ offset _constant + 4 ]
   fadd dword ptr [ %eax ]
   sub %esp, 4
   fstp dword ptr [ %esp ] 
   pop %edi
#  Printing expression:
#  Printing float constant
   sub %esp, 4
   push %edi
   fld dword ptr [ %esp ]
   fstp qword ptr [ %esp ]
   push [ offset .io_format + 4 ]
   call printf
   add %esp, 12
#  Return 0
   mov %eax, 0
   leave
   ret
