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
   .float 2.0
   .float 3.4
.text
   .globl main;
   .type main, @function
main:
   push %ebp
   mov %ebp, %esp
   sub %esp, 4
   # 4 * [ offset flat:_constant + 4 ]
   mov %edi, 4
   imul %edi, [ offset flat:_constant + 4 ]
   # [ offset flat:_constant + 0 ] + %edi
   mov %esi, [ offset flat:_constant + 0 ]
   add %esi, %edi
#  Assignment: a := %esi
   mov %ebx, %esi
   mov dword ptr [ %ebp-4 ], %ebx
#  Cleared the register manager.
#  Printing expression:
   push dword ptr [ %ebp-4 ]
   push offset flat:.io_format
   call printf
   add %esp, 8
#  Return 0
   mov %eax, 0
   leave
   ret
