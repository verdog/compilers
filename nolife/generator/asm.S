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
   sub %esp, 52
#  Array access: d[4]
   mov %eax, 4
   sub %eax, 1
   mov %edx, 4
   imul %edx
   mov %edx, %ebp
   sub %edx, 52
   add %edx, %eax
   mov %edi, %edx
#  READ ( [ %edi ] ) ( ArrayAccess )
   lea %eax, [ %edi ]
   push %eax
   push [ offset flat:.io_format_in + 0 ]
   call scanf
   add %esp, 8
#  Array access: d[4]
   mov %eax, 4
   sub %eax, 1
   mov %edx, 4
   imul %edx
   mov %edx, %ebp
   sub %edx, 52
   add %edx, %eax
   mov %edi, %edx
#  Printing expression:
   push [ %edi ]
   push offset flat:.io_format
   call printf
   add %esp, 8
   # Return 0
   mov %eax, 0
   leave
   ret
