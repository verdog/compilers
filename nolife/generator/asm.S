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
   .float 8.0
   .string "lmaoxd"
   .float 30.0
.text
   .globl main;
   .type main, @function
main:
   push %ebp
   mov %ebp, %esp
#  Printing expression:
   push [ offset flat:_constant + 0 ]
   push offset [ offset flat:.io_format + 4 ]
   call printf
   add %esp, 8
#  Printing string constant: 'lmaoxd'
   push [ offset flat:_constant + 4 ]
   push [ offset flat:.io_format + 12 ]
   call printf
   add %esp, 8
   leave
   ret
