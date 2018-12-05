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
#  deriveAddress: dword ptr [ %ebp-8 ] -> [ %ebp-8 ]
#  Pushing procedure argument (Variable)
   lea %eax, [ %ebp-8 ]
   push %eax
#  Push main's access link
   push %ebp
   call xd
   add %esp, 8
#  Array access: x[1] (LOCAL)
   mov %eax, 1
   sub %eax, 1
   mov %edx, 4
   imul %edx
   mov %edx, %ebp
   sub %edx, 8
   add %edx, %eax
   mov %edi, %edx
#  Printing expression: (NON-FLOAT)
   push [ %edi ]
   push offset .io_format
   call printf
   add %esp, 8
#  Array access: x[2] (LOCAL)
   mov %eax, 2
   sub %eax, 1
   mov %edx, 4
   imul %edx
   mov %edx, %ebp
   sub %edx, 8
   add %edx, %eax
   mov %edi, %edx
#  Printing expression: (NON-FLOAT)
   push [ %edi ]
   push offset .io_format
   call printf
   add %esp, 8
#  Return 0
   mov %eax, 0
   leave
   ret
xd:
   push %ebp
   mov %ebp, %esp
#  Array access: a[1] (PARAM)
   mov %eax, 1
   sub %eax, 1
   mov %edx, 4
   imul %edx
#  Derive beginning of array from parameter
   mov %edx, [ %ebp+12 ]
   add %edx, %eax
   mov %edi, %edx
#  Assignment: a := 1
   mov %esi, 1
   mov [ %edi ], %esi
#  Cleared the register manager.
#  Array access: a[2] (PARAM)
   mov %eax, 2
   sub %eax, 1
   mov %edx, 4
   imul %edx
#  Derive beginning of array from parameter
   mov %edx, [ %ebp+12 ]
   add %edx, %eax
   mov %edi, %edx
#  READ ( [ %edi ] ) ( ArrayAccess )
   lea %eax, [ %edi ]
   push %eax
   push [ offset .io_format_in + 0 ]
   call scanf
   add %esp, 8
#  default leave return
   leave
   ret
