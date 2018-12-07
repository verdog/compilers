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
#  READ ( dword ptr [ %ebp-4 ] ) (LOCAL)
   mov %eax, %ebp
   sub %eax, 4
   push %eax
   push [ offset .io_format_in + 0 ]
   call scanf
   add %esp, 8
#  Saving registers
#  Storing expression result on stack
   push 100
#  Store temporary %esp (which will be the base of the temporary parameter stack) in register
   lea %edx, [ %esp+4 ]
#  Pushing temporary stack address
   mov %eax, %edx
   sub %eax, 4
   push %eax
#  deriveAddress: dword ptr [ %ebp-4 ] -> [ %ebp-4 ]
#  Pushing procedure argument (Variable)
   lea %eax, [ %ebp-4 ]
   push %eax
#  Push main's access link
   push %ebp
   call decls
   add %esp, 16
#  Recovering registers
#  Saving registers
#  Storing expression result on stack
   push 10
#  Store temporary %esp (which will be the base of the temporary parameter stack) in register
   lea %edx, [ %esp+4 ]
#  Pushing temporary stack address
   mov %eax, %edx
   sub %eax, 4
   push %eax
#  deriveAddress: dword ptr [ %ebp-4 ] -> [ %ebp-4 ]
#  Pushing procedure argument (Variable)
   lea %eax, [ %ebp-4 ]
   push %eax
#  Push main's access link
   push %ebp
   call foo
   add %esp, 16
#  Recovering registers
#  Return 0
   mov %eax, 0
   leave
   ret
# ---------------------------------------------------------------------------- #
decls:
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
#  [ %edi ] > 0 (INT)
   mov %eax, [ %edi ]
   cmp %eax, 0
   jg __L_TRUE_0
__L_FALSE_0:
   mov %esi, 0
   jmp __L_DONE_0
__L_TRUE_0:
   mov %esi, 0xffffffff
   jmp __L_DONE_0
__L_DONE_0:
#  If %esi
   cmp %esi, 0
   je __L_FALSE_1
__L_TRUE_1:
#  Saving registers
#  Deference paremeter address
   mov %edi, dword ptr [ %ebp+12 ]
#  [ %edi ] - 1
   mov %esi, [ %edi ]
   sub %esi, 1
#  Storing expression result on stack
   push %esi
#  Deference paremeter address
   mov %edi, dword ptr [ %ebp+16 ]
#  [ %edi ] % 2
   xor %edx, %edx
   mov %eax, [ %edi ]
   mov %esi, 2
   idiv %esi
   mov %esi, %edx
#  Storing expression result on stack
   push %esi
#  Store temporary %esp (which will be the base of the temporary parameter stack) in register
   lea %edx, [ %esp+8 ]
#  Pushing temporary stack address
   mov %eax, %edx
   sub %eax, 8
   push %eax
#  Pushing temporary stack address
   mov %eax, %edx
   sub %eax, 4
   push %eax
#  Push main's access link (already on the stack)
   push [ %ebp+8 ]
   call decls
   add %esp, 20
#  Recovering registers
   jmp __L_DONE_1
__L_FALSE_1:
#  Deference paremeter address
   mov %edi, dword ptr [ %ebp+12 ]
#  Assignment: a := 0
   mov %esi, 0
   mov [ %edi ], %esi
#  Cleared the register manager.
__L_DONE_1:
#  default leave return
   leave
   ret
# ---------------------------------------------------------------------------- #
foo:
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
#  default leave return
   leave
   ret
