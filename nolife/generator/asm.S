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
#  READ ( dword ptr [ %ebp-4 ] ) (LOCAL)
   mov %eax, %ebp
   sub %eax, 4
   push %eax
   push [ offset .io_format_in + 0 ]
   call scanf
   add %esp, 8
#  READ ( dword ptr [ %ebp-8 ] ) (LOCAL)
   mov %eax, %ebp
   sub %eax, 8
   push %eax
   push [ offset .io_format_in + 0 ]
   call scanf
   add %esp, 8
#  While loop
__L_TRUE_0:
#  dword ptr [ %ebp-4 ] != 0 (INT)
   mov %eax, dword ptr [ %ebp-4 ]
   cmp %eax, 0
   jne __L_TRUE_1
__L_FALSE_1:
   mov %edi, 0
   jmp __L_DONE_1
__L_TRUE_1:
   mov %edi, 0xffffffff
   jmp __L_DONE_1
__L_DONE_1:
#  dword ptr [ %ebp-8 ] != 0 (INT)
   mov %eax, dword ptr [ %ebp-8 ]
   cmp %eax, 0
   jne __L_TRUE_2
__L_FALSE_2:
   mov %esi, 0
   jmp __L_DONE_2
__L_TRUE_2:
   mov %esi, 0xffffffff
   jmp __L_DONE_2
__L_DONE_2:
   # %edi OR %esi
   mov %eax, %edi
   or %eax, %esi
   mov %ebx, %eax
   cmp %ebx, 0
   je __L_DONE_0
#  Store temporary %esp (which will be the base of the temporary parameter stack) in register
   mov %edx, %esp
#  deriveAddress: dword ptr [ %ebp-8 ] -> [ %ebp-8 ]
#  Pushing procedure argument (Variable)
   lea %eax, [ %ebp-8 ]
   push %eax
#  deriveAddress: dword ptr [ %ebp-4 ] -> [ %ebp-4 ]
#  Pushing procedure argument (Variable)
   lea %eax, [ %ebp-4 ]
   push %eax
#  Push main's access link
   push %ebp
   call gcd
   add %esp, 12
#  Grab return value
   mov %edi, %eax
#  Printing expression: (NON-FLOAT)
   push %edi
   push offset .io_format
   call printf
   add %esp, 8
#  READ ( dword ptr [ %ebp-4 ] ) (LOCAL)
   mov %eax, %ebp
   sub %eax, 4
   push %eax
   push [ offset .io_format_in + 0 ]
   call scanf
   add %esp, 8
#  READ ( dword ptr [ %ebp-8 ] ) (LOCAL)
   mov %eax, %ebp
   sub %eax, 8
   push %eax
   push [ offset .io_format_in + 0 ]
   call scanf
   add %esp, 8
   jmp __L_TRUE_0
__L_DONE_0:
#  Return 0
   mov %eax, 0
   leave
   ret
# ---------------------------------------------------------------------------- #
gcd:
   push %ebp
   mov %ebp, %esp
#  Deference paremeter address
   mov %edi, dword ptr [ %ebp+16 ]
#  [ %edi ] == 0 (INT)
   mov %eax, [ %edi ]
   cmp %eax, 0
   je __L_TRUE_3
__L_FALSE_3:
   mov %esi, 0
   jmp __L_DONE_3
__L_TRUE_3:
   mov %esi, 0xffffffff
   jmp __L_DONE_3
__L_DONE_3:
#  If %esi
   cmp %esi, 0
   je __L_FALSE_4
__L_TRUE_4:
#  Deference paremeter address
   mov %edi, dword ptr [ %ebp+12 ]
#  Return [ %edi ]
   mov %eax, [ %edi ]
   leave
   ret
   jmp __L_DONE_4
__L_FALSE_4:
#  Store temporary %esp (which will be the base of the temporary parameter stack) in register
   mov %edx, %esp
#  Deference paremeter address
   mov %edi, dword ptr [ %ebp+12 ]
#  Deference paremeter address
   mov %esi, dword ptr [ %ebp+16 ]
#  [ %edi ] % [ %esi ]
   xor %edx, %edx
   mov %eax, [ %edi ]
   mov %ebx, [ %esi ]
   idiv %ebx
   mov %ebx, %edx
#  Storing expression result on stack
   push %ebx
#  Pushing temporary stack address
   mov %eax, %edx
   sub %eax, 4
   push %eax
#  Deference paremeter address
   mov %edi, dword ptr [ %ebp+16 ]
#  deriveAddress: [ %edi ] -> [ %edi ]
#  Pushing procedure argument (Variable)
   lea %eax, [ %edi ]
   push %eax
#  Push main's access link (already on the stack)
   push [ %ebp + 8 ]
   call gcd
   add %esp, 16
#  Grab return value
   mov %edi, %eax
#  Return %edi
   mov %eax, %edi
   leave
   ret
__L_DONE_4:
#  default leave return
   leave
   ret
