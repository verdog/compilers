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
   .globl main
   .type main, @function
main:
   push %ebp
   mov %ebp, %esp
#  Allocating stack for main
   sub %esp, 8
#  Store temporary %esp (which will be the base of the temporary parameter stack) in register
   mov %edx, %esp
#  1 + 1 (INT)
   mov %edi, 1
   add %edi, 1
#  Storing expression result on stack
   push %edi
#  Storing expression result on stack
   push 1
#  Pushing temporary stack address
   mov %eax, %edx
   sub %eax, 8
   push %eax
#  Pushing temporary stack address
   mov %eax, %edx
   sub %eax, 4
   push %eax
#  Push main's access link
   push %ebp
   call mywrite
   add %esp, 20
#  Return 0
   mov %eax, 0
   leave
   ret
mywrite:
   push %ebp
   mov %ebp, %esp
#  Deference paremeter address
   mov %esi, dword ptr [ %ebp+12 ]
#  Printing expression: (NON-FLOAT)
   push [ %esi ]
   push offset .io_format
   call printf
   add %esp, 8
#  Deference paremeter address
   mov %edi, dword ptr [ %ebp+16 ]
#  Printing expression: (NON-FLOAT)
   push [ %edi ]
   push offset .io_format
   call printf
   add %esp, 8
#  Deference paremeter address
   mov %edi, dword ptr [ %ebp+12 ]
#  Printing expression: (NON-FLOAT)
   push [ %edi ]
   push offset .io_format
   call printf
   add %esp, 8
#  default leave return
   leave
   ret
