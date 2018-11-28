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
   sub %ebp, 4
#  Printing expression:
   push 
   push offset flat:.io_format
   call printf
   add %esp, 8
   leave
   ret
