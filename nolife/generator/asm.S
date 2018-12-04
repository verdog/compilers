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
   sub %esp, 4
#  Store temporary %esp (which will be the base of the temporary parameter stack) in register
   mov %edx, %esp
#  Pushing procedure argument (Variable)
   lea %eax, [ %ebp-4 ]
   push %eax
#  Push main's access link
   push %ebp
   call myread
   add %esp, 8
#  Printing expression: (NON-FLOAT)
   push dword ptr [ %ebp-4 ]
   push offset .io_format
   call printf
   add %esp, 8
#  Return 0
   mov %eax, 0
   leave
   ret
myread:
   push %ebp
   mov %ebp, %esp
#  Deference paremeter address
   mov %edi, dword ptr [ %ebp+12 ]
#  READ ( a ) (PARAM)
   lea %eax, [ %ebp+12 ]
   push [ %eax ]
   push [ offset .io_format_in + 0 ]
   call scanf
   add %esp, 8
#  Store temporary %esp (which will be the base of the temporary parameter stack) in register
   mov %edx, %esp
#  Deference paremeter address
   mov %edi, dword ptr [ %ebp+12 ]
#  Pushing procedure argument (Variable)
   lea %eax, [ %edi ]
   push %eax
#  Push main's access link (already on the stack)
   push [ %ebp + 8 ]
   call myread
   add %esp, 8
#  default leave return
   leave
   ret
