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
   sub %esp, 8
#  READ ( dword ptr [ %ebp-4 ] )
   mov %eax, %ebp
   sub %eax, 4
   push %eax
   push [ offset .io_format_in + 0 ]
   call scanf
   add %esp, 8
#  READ ( dword ptr [ %ebp-8 ] )
   mov %eax, %ebp
   sub %eax, 8
   push %eax
   push [ offset .io_format_in + 0 ]
   call scanf
   add %esp, 8
#  If dword ptr [ %ebp-8 ]
   cmp dword ptr [ %ebp-8 ], 0
   je __L_FALSE_0
__L_TRUE_0:
#  If dword ptr [ %ebp-4 ]
   cmp dword ptr [ %ebp-4 ], 0
   je __L_FALSE_1
__L_TRUE_1:
#  Printing expression: (NON-FLOAT)
   push 0
   push offset .io_format
   call printf
   add %esp, 8
   jmp __L_DONE_1
__L_FALSE_1:
#  Printing expression: (NON-FLOAT)
   push 1
   push offset .io_format
   call printf
   add %esp, 8
__L_DONE_1:
   jmp __L_DONE_0
__L_FALSE_0:
#  Printing expression: (NON-FLOAT)
   push 2
   push offset .io_format
   call printf
   add %esp, 8
__L_DONE_0:
#  Return 0
   mov %eax, 0
   leave
   ret
