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
#  READ ( dword ptr [ %ebp-4 ] )
   mov %eax, %ebp
   sub %eax, 4
   push %eax
   push [ offset .io_format_in + 0 ]
   call scanf
   add %esp, 8
#  Generating expression code for case statement
#  Comparing with each label
#  dword ptr [ %ebp-4 ] == 1 (INT)
   mov %eax, dword ptr [ %ebp-4 ]
   cmp %eax, 1
   je __L_TRUE_0
__L_FALSE_0:
   mov %edi, 0
   jmp __L_DONE_0
__L_TRUE_0:
   mov %edi, 0xffffffff
   jmp __L_DONE_0
__L_DONE_0:
#  Case when dword ptr [ %ebp-4 ] == 1
   cmp %edi, 0xffffffff
   je __L_CASEJMP_0_0
#  dword ptr [ %ebp-4 ] == 2 (INT)
   mov %eax, dword ptr [ %ebp-4 ]
   cmp %eax, 2
   je __L_TRUE_1
__L_FALSE_1:
   mov %edi, 0
   jmp __L_DONE_1
__L_TRUE_1:
   mov %edi, 0xffffffff
   jmp __L_DONE_1
__L_DONE_1:
#  Case when dword ptr [ %ebp-4 ] == 2
   cmp %edi, 0xffffffff
   je __L_CASEJMP_0_0
#  dword ptr [ %ebp-4 ] == 5 (INT)
   mov %eax, dword ptr [ %ebp-4 ]
   cmp %eax, 5
   je __L_TRUE_2
__L_FALSE_2:
   mov %edi, 0
   jmp __L_DONE_2
__L_TRUE_2:
   mov %edi, 0xffffffff
   jmp __L_DONE_2
__L_DONE_2:
#  Case when dword ptr [ %ebp-4 ] == 5
   cmp %edi, 0xffffffff
   je __L_CASEJMP_0_1
#  Jump to end of case on no matches
   jmp __L_CASEEND_0
__L_CASEJMP_0_0:
#  Printing expression: (NON-FLOAT)
   push 0
   push offset .io_format
   call printf
   add %esp, 8
   jmp __L_CASEEND_0
__L_CASEJMP_0_1:
#  Printing expression: (NON-FLOAT)
   push 1
   push offset .io_format
   call printf
   add %esp, 8
   jmp __L_CASEEND_0
__L_CASEEND_0:
#  Return 0
   mov %eax, 0
   leave
   ret
