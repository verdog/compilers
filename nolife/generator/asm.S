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
   sub %esp, 4
#  Assignment: a := 1
   mov %edi, 1
   mov dword ptr [ %ebp-4 ], %edi
#  Cleared the register manager.
   # dword ptr [ %ebp-4 ] <= 1
   mov %eax, dword ptr [ %ebp-4 ]
   cmp %eax, 1
   jle __L_TRUE_0
__L_FALSE_0:
   mov %edi, 0
   jmp __L_DONE_0
__L_TRUE_0:
   mov %edi, 0xffffffff
   jmp __L_DONE_0
__L_DONE_0:
#  Printing expression:
   push %edi
   push offset flat:.io_format
   call printf
   add %esp, 8
   # dword ptr [ %ebp-4 ] < 1
   mov %eax, dword ptr [ %ebp-4 ]
   cmp %eax, 1
   jl __L_TRUE_1
__L_FALSE_1:
   mov %edi, 0
   jmp __L_DONE_1
__L_TRUE_1:
   mov %edi, 0xffffffff
   jmp __L_DONE_1
__L_DONE_1:
#  Printing expression:
   push %edi
   push offset flat:.io_format
   call printf
   add %esp, 8
   # dword ptr [ %ebp-4 ] >= 1
   mov %eax, dword ptr [ %ebp-4 ]
   cmp %eax, 1
   jge __L_TRUE_2
__L_FALSE_2:
   mov %edi, 0
   jmp __L_DONE_2
__L_TRUE_2:
   mov %edi, 0xffffffff
   jmp __L_DONE_2
__L_DONE_2:
#  Printing expression:
   push %edi
   push offset flat:.io_format
   call printf
   add %esp, 8
   # dword ptr [ %ebp-4 ] > 1
   mov %eax, dword ptr [ %ebp-4 ]
   cmp %eax, 1
   jg __L_TRUE_3
__L_FALSE_3:
   mov %edi, 0
   jmp __L_DONE_3
__L_TRUE_3:
   mov %edi, 0xffffffff
   jmp __L_DONE_3
__L_DONE_3:
#  Printing expression:
   push %edi
   push offset flat:.io_format
   call printf
   add %esp, 8
   # dword ptr [ %ebp-4 ] = 1
   mov %eax, dword ptr [ %ebp-4 ]
   cmp %eax, 1
   je __L_TRUE_4
__L_FALSE_4:
   mov %edi, 0
   jmp __L_DONE_4
__L_TRUE_4:
   mov %edi, 0xffffffff
   jmp __L_DONE_4
__L_DONE_4:
#  Printing expression:
   push %edi
   push offset flat:.io_format
   call printf
   add %esp, 8
   # dword ptr [ %ebp-4 ] <> 1
   mov %eax, dword ptr [ %ebp-4 ]
   cmp %eax, 1
   jne __L_TRUE_5
__L_FALSE_5:
   mov %edi, 0
   jmp __L_DONE_5
__L_TRUE_5:
   mov %edi, 0xffffffff
   jmp __L_DONE_5
__L_DONE_5:
#  Printing expression:
   push %edi
   push offset flat:.io_format
   call printf
   add %esp, 8
   # dword ptr [ %ebp-4 ] AND 2
   mov %eax, dword ptr [ %ebp-4 ]
   and %eax, 2
   mov %edi, %eax
#  Printing expression:
   push %edi
   push offset flat:.io_format
   call printf
   add %esp, 8
   # dword ptr [ %ebp-4 ] OR 2
   mov %eax, dword ptr [ %ebp-4 ]
   or %eax, 2
   mov %edi, %eax
#  Printing expression:
   push %edi
   push offset flat:.io_format
   call printf
   add %esp, 8
   # Return 0
   mov %eax, 0
   leave
   ret
