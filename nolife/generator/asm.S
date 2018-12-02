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
   .float 1.0
   .float 10.0
.text
   .globl main;
   .type main, @function
main:
   push %ebp
   mov %ebp, %esp
#  [ _constant + 0 ] <= [ _constant + 4 ] (FLOAT)
   push [ _constant + 4 ]
   fld dword ptr [ %esp ]
   push [ _constant + 0 ]
   fld dword ptr [ %esp ]
   add %esp, 8
   fcomip %st(0), %st(1)
   fstp %st(0) # to clear stack
   jbe __L_TRUE_0
__L_FALSE_0:
   mov %edi, 0
   jmp __L_DONE_0
__L_TRUE_0:
   mov %edi, 0xffffffff
   jmp __L_DONE_0
__L_DONE_0:
#  Printing expression: (NON-FLOAT)
   push %edi
   push offset .io_format
   call printf
   add %esp, 8
#  [ _constant + 4 ] <= [ _constant + 0 ] (FLOAT)
   push [ _constant + 0 ]
   fld dword ptr [ %esp ]
   push [ _constant + 4 ]
   fld dword ptr [ %esp ]
   add %esp, 8
   fcomip %st(0), %st(1)
   fstp %st(0) # to clear stack
   jbe __L_TRUE_1
__L_FALSE_1:
   mov %edi, 0
   jmp __L_DONE_1
__L_TRUE_1:
   mov %edi, 0xffffffff
   jmp __L_DONE_1
__L_DONE_1:
#  Printing expression: (NON-FLOAT)
   push %edi
   push offset .io_format
   call printf
   add %esp, 8
#  Return 0
   mov %eax, 0
   leave
   ret
