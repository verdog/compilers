#-------------------------------#
# nolife compiler               #
# Josh Chandler                 #
#-------------------------------#
   .intel_syntax
   .section .rodata
.io_format:
   .string "%d\12"
   .string "%s\12"
_constant:
   .string "aaaa"
   .float 1.0
   .float 2.0
   .float 3.0
   .string "bbbb"
   .text
   .globl main;
   .type main, @function
main:
   push %ebp
   mov %ebp, %esp
   sub %esp, 4
   mov %eax, offset flat:_constant

   push %eax
   push [offset flat:.io_format + 4]
   call printf
   add %esp, 8
   leave
   ret
