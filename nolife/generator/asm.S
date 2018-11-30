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
   sub %esp, 12
   # READ ( dword ptr [ %ebp-4 ] )
   mov %eax, %ebp
   sub %eax, 4
   push %eax
   push [ offset flat:.io_format_in + 0 ]
   call scanf
   add %esp, 8
   # READ ( dword ptr [ %ebp-8 ] )
   mov %eax, %ebp
   sub %eax, 8
   push %eax
   push [ offset flat:.io_format_in + 3 ]
   call scanf
   add %esp, 8
   # READ ( dword ptr [ %ebp-12 ] )
   mov %eax, %ebp
   sub %eax, 12
   push %eax
   push [ offset flat:.io_format_in + 6 ]
   call scanf
   add %esp, 8
#  Printing expression:
   push dword ptr [ %ebp-4 ]
   push offset flat:.io_format
   call printf
   add %esp, 8
#  Printing expression:
#  Printing float constant
   sub %esp, 4
   push dword ptr [ %ebp-8 ]
   fld dword ptr [ %esp ]
   fstp qword ptr [ %esp ]
   push [ offset flat:.io_format + 4 ]
   call printf
   add %esp, 12
#  Printing expression:
   push dword ptr [ %ebp-12 ]
   push [ offset flat:.io_format + 8 ]
   call printf
   add %esp, 8
   # Return 0
   mov %eax, 0
   leave
   ret
