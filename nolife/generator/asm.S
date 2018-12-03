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
   sub %esp, 4
#  Assignment: a := 1
   mov %edi, 1
   mov dword ptr [ %ebp-4 ], %edi
#  Cleared the register manager.
#  While loop
__L_TRUE_0:
#  dword ptr [ %ebp-4 ] != 10 (INT)
   mov %eax, dword ptr [ %ebp-4 ]
   cmp %eax, 10
   jne __L_TRUE_1
__L_FALSE_1:
   mov %edi, 0
   jmp __L_DONE_1
__L_TRUE_1:
   mov %edi, 0xffffffff
   jmp __L_DONE_1
__L_DONE_1:
   cmp %edi, 0
   je __L_DONE_0
#  Printing expression: (NON-FLOAT)
   push dword ptr [ %ebp-4 ]
   push offset .io_format
   call printf
   add %esp, 8
#  dword ptr [ %ebp-4 ] + 1 (INT)
   mov %edi, dword ptr [ %ebp-4 ]
   add %edi, 1
#  Assignment: a := %edi
   mov %esi, %edi
   mov dword ptr [ %ebp-4 ], %esi
#  Cleared the register manager.
   jmp __L_TRUE_0
__L_DONE_0:
#  Printing expression: (NON-FLOAT)
   push dword ptr [ %ebp-4 ]
   push offset .io_format
   call printf
   add %esp, 8
#  Return 0
   mov %eax, 0
   leave
   ret
