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
.text
   .globl main;
   .type main, @function
main:
   push %ebp
   mov %ebp, %esp
#  Printing expression:
#  Printing float constant
   sub %esp, 8
   mov %edi, [ offset flat:_constant + 0 ]
   fld dword ptr [%edi]
   fstp qword ptr [%esp]
   push [ offset flat:.io_format + 4 ]
   call printf
   add %esp, 12
#  Printing string constant: 'lmaoxd'
   push [ offset flat:_constant + 4 ]
   push [ offset flat:.io_format + 12 ]
   call printf
   add %esp, 8
#  Printing expression:
   push 0x68
   push [ offset flat:.io_format + 8 ]
   call printf
   add %esp, 8
#  Printing expression:
   push 50
   push offset flat:.io_format
   call printf
   add %esp, 8
   leave
   ret
