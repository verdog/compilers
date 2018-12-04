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
#  Assignment: x := 9
   mov %edi, 9
   mov dword ptr [ %ebp-4 ], %edi
#  Cleared the register manager.
#  Assignment: y := 10
   mov %edi, 10
   mov dword ptr [ %ebp-8 ], %edi
#  Cleared the register manager.
#  Pushing procedure argument
   lea %eax, [ %ebp-8 ]
   push %eax
#  Pushing procedure argument
   lea %eax, [ %ebp-4 ]
   push %eax
#  Push main's access link
   push %ebp
   call mywrite
   add %esp, 12
#  Return 0
   mov %eax, 0
   leave
   ret
mywrite:
   push %ebp
   mov %ebp, %esp
#  Deference paremeter address
   mov %edi, dword ptr [ %ebp+12 ]
#  Printing expression: (NON-FLOAT)
   push [ %edi ]
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
