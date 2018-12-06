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
   .string "A?"
   .string "A:"
   .float 1.7
.text
   .globl main
   .type main, @function
main:
   push %ebp
   mov %ebp, %esp
#  Allocating stack for main
   sub %esp, 84
#  Array access: A[0] (LOCAL)
   mov %eax, 0
   sub %eax, 0
   mov %edx, 4
   imul %edx
   mov %edx, %ebp
   sub %edx, 84
   add %edx, %eax
   mov %edi, %edx
#  0 - 1
   mov %esi, 0
   sub %esi, 1
#  Assignment: A := %esi
   mov %ebx, %esi
   mov [ %edi ], %ebx
#  Cleared the register manager.
#  Array access: A[20] (LOCAL)
   mov %eax, 20
   sub %eax, 0
   mov %edx, 4
   imul %edx
   mov %edx, %ebp
   sub %edx, 84
   add %edx, %eax
   mov %edi, %edx
#  Assignment: A := 1000
   mov %esi, 1000
   mov [ %edi ], %esi
#  Cleared the register manager.
#  Store temporary %esp (which will be the base of the temporary parameter stack) in register
   mov %edx, %esp
#  Push main's access link
   push %ebp
   call readarray
   add %esp, 4
#  Store temporary %esp (which will be the base of the temporary parameter stack) in register
   mov %edx, %esp
#  Push main's access link
   push %ebp
   call writearray
   add %esp, 4
#  Store temporary %esp (which will be the base of the temporary parameter stack) in register
   mov %edx, %esp
#  Storing expression result on stack
   push 1
#  Storing expression result on stack
   push 19
#  Pushing temporary stack address
   mov %eax, %edx
   sub %eax, 8
   push %eax
#  Pushing temporary stack address
   mov %eax, %edx
   sub %eax, 4
   push %eax
#  deriveAddress: dword ptr [ %ebp-84 ] -> [ %ebp-84 ]
#  Pushing procedure argument (Variable)
   lea %eax, [ %ebp-84 ]
   push %eax
#  Push main's access link
   push %ebp
   call quicksort
   add %esp, 24
#  Store temporary %esp (which will be the base of the temporary parameter stack) in register
   mov %edx, %esp
#  Push main's access link
   push %ebp
   call writearray
   add %esp, 4
#  Return 0
   mov %eax, 0
   leave
   ret
# ---------------------------------------------------------------------------- #
readarray:
   push %ebp
   mov %ebp, %esp
#  Allocating stack for readarray
   sub %esp, 4
#  Printing string constant: 'A?'
   push [ offset _constant + 0 ]
   push [ offset .io_format + 12 ]
   call printf
   add %esp, 8
#  Assignment: i := 1
   mov %edi, 1
   mov dword ptr [ %ebp-4 ], %edi
#  Cleared the register manager.
#  While loop
__L_TRUE_0:
#  dword ptr [ %ebp-4 ] < 20 (INT)
   mov %eax, dword ptr [ %ebp-4 ]
   cmp %eax, 20
   jl __L_TRUE_1
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
#  Array access: A[dword ptr [ %ebp-4 ]] (GLOBAL)
   mov %eax, dword ptr [ %ebp-4 ]
   sub %eax, 0
   mov %edx, 4
   imul %edx
#  Load access link and get variable from main
   mov %edx, [ %ebp + 8 ]
   add %edx, -84
#  Add offset
   add %edx, %eax
   mov %edi, %edx
#  READ ( [ %edi ] ) ( ArrayAccess )
   lea %eax, [ %edi ]
   push %eax
   call scanf
   add %esp, 8
#  dword ptr [ %ebp-4 ] + 1 (INT)
   mov %edi, dword ptr [ %ebp-4 ]
   add %edi, 1
#  Assignment: i := %edi
   mov %esi, %edi
   mov dword ptr [ %ebp-4 ], %esi
#  Cleared the register manager.
   jmp __L_TRUE_0
__L_DONE_0:
#  default leave return
   leave
   ret
# ---------------------------------------------------------------------------- #
writearray:
   push %ebp
   mov %ebp, %esp
#  Allocating stack for writearray
   sub %esp, 4
#  Printing string constant: 'A:'
   push [ offset _constant + 3 ]
   push [ offset .io_format + 12 ]
   call printf
   add %esp, 8
#  Assignment: i := 1
   mov %edi, 1
   mov dword ptr [ %ebp-4 ], %edi
#  Cleared the register manager.
#  While loop
__L_TRUE_2:
#  dword ptr [ %ebp-4 ] < 20 (INT)
   mov %eax, dword ptr [ %ebp-4 ]
   cmp %eax, 20
   jl __L_TRUE_3
__L_FALSE_3:
   mov %edi, 0
   jmp __L_DONE_3
__L_TRUE_3:
   mov %edi, 0xffffffff
   jmp __L_DONE_3
__L_DONE_3:
   cmp %edi, 0
   je __L_DONE_2
#  Array access: A[dword ptr [ %ebp-4 ]] (GLOBAL)
   mov %eax, dword ptr [ %ebp-4 ]
   sub %eax, 0
   mov %edx, 4
   imul %edx
#  Load access link and get variable from main
   mov %edx, [ %ebp + 8 ]
   add %edx, -84
#  Add offset
   add %edx, %eax
   mov %esi, %edx
#  Printing expression: (NON-FLOAT)
   push [ %esi ]
   push offset .io_format
   call printf
   add %esp, 8
#  dword ptr [ %ebp-4 ] + 1 (INT)
   mov %edi, dword ptr [ %ebp-4 ]
   add %edi, 1
#  Assignment: i := %edi
   mov %esi, %edi
   mov dword ptr [ %ebp-4 ], %esi
#  Cleared the register manager.
   jmp __L_TRUE_2
__L_DONE_2:
#  default leave return
   leave
   ret
# ---------------------------------------------------------------------------- #
partition:
   push %ebp
   mov %ebp, %esp
#  Allocating stack for partition
   sub %esp, 20
#  Deference paremeter address
   mov %edi, dword ptr [ %ebp+16 ]
#  Array access: B[[ %edi ]] (PARAM)
   mov %eax, [ %edi ]
   sub %eax, 0
   mov %edx, 4
   imul %edx
#  Derive beginning of array from parameter
   mov %edx, [ %ebp+12 ]
   add %edx, %eax
   mov %esi, %edx
#  Assignment: x := [ %esi ]
   mov %ebx, [ %esi ]
   mov dword ptr [ %ebp-12 ], %ebx
#  Cleared the register manager.
#  Deference paremeter address
   mov %edi, dword ptr [ %ebp+16 ]
#  [ %edi ] - 1
   mov %esi, [ %edi ]
   sub %esi, 1
#  Assignment: i := %esi
   mov %edi, %esi
   mov dword ptr [ %ebp-4 ], %edi
#  Cleared the register manager.
#  Deference paremeter address
   mov %edi, dword ptr [ %ebp+20 ]
#  [ %edi ] + 1 (INT)
   mov %esi, [ %edi ]
   add %esi, 1
#  Assignment: j := %esi
   mov %edi, %esi
   mov dword ptr [ %ebp-8 ], %edi
#  Cleared the register manager.
#  While loop
__L_TRUE_4:
   cmp [ _constant + 6 ], 0
   je __L_DONE_4
#  dword ptr [ %ebp-8 ] - 1
   mov %edi, dword ptr [ %ebp-8 ]
   sub %edi, 1
#  Assignment: j := %edi
   mov %esi, %edi
   mov dword ptr [ %ebp-8 ], %esi
#  Cleared the register manager.
#  While loop
__L_TRUE_5:
#  Array access: A[dword ptr [ %ebp-8 ]] (GLOBAL)
   mov %eax, dword ptr [ %ebp-8 ]
   sub %eax, 0
   mov %edx, 4
   imul %edx
#  Load access link and get variable from main
   mov %edx, [ %ebp + 8 ]
   add %edx, -84
#  Add offset
   add %edx, %eax
   mov %edi, %edx
#  [ %edi ] > dword ptr [ %ebp-12 ] (INT)
   mov %eax, [ %edi ]
   cmp %eax, dword ptr [ %ebp-12 ]
   jg __L_TRUE_6
__L_FALSE_6:
   mov %esi, 0
   jmp __L_DONE_6
__L_TRUE_6:
   mov %esi, 0xffffffff
   jmp __L_DONE_6
__L_DONE_6:
   cmp %esi, 0
   je __L_DONE_5
#  dword ptr [ %ebp-8 ] - 1
   mov %edi, dword ptr [ %ebp-8 ]
   sub %edi, 1
#  Assignment: j := %edi
   mov %ebx, %edi
   mov dword ptr [ %ebp-8 ], %ebx
#  Cleared the register manager.
   jmp __L_TRUE_5
__L_DONE_5:
#  dword ptr [ %ebp-4 ] + 1 (INT)
   mov %edi, dword ptr [ %ebp-4 ]
   add %edi, 1
#  Assignment: i := %edi
   mov %esi, %edi
   mov dword ptr [ %ebp-4 ], %esi
#  Cleared the register manager.
#  While loop
__L_TRUE_7:
#  Array access: A[dword ptr [ %ebp-4 ]] (GLOBAL)
   mov %eax, dword ptr [ %ebp-4 ]
   sub %eax, 0
   mov %edx, 4
   imul %edx
#  Load access link and get variable from main
   mov %edx, [ %ebp + 8 ]
   add %edx, -84
#  Add offset
   add %edx, %eax
   mov %edi, %edx
#  [ %edi ] < dword ptr [ %ebp-12 ] (INT)
   mov %eax, [ %edi ]
   cmp %eax, dword ptr [ %ebp-12 ]
   jl __L_TRUE_8
__L_FALSE_8:
   mov %esi, 0
   jmp __L_DONE_8
__L_TRUE_8:
   mov %esi, 0xffffffff
   jmp __L_DONE_8
__L_DONE_8:
   cmp %esi, 0
   je __L_DONE_7
#  dword ptr [ %ebp-4 ] + 1 (INT)
   mov %edi, dword ptr [ %ebp-4 ]
   add %edi, 1
#  Assignment: i := %edi
   mov %ebx, %edi
   mov dword ptr [ %ebp-4 ], %ebx
#  Cleared the register manager.
   jmp __L_TRUE_7
__L_DONE_7:
#  dword ptr [ %ebp-4 ] < dword ptr [ %ebp-8 ] (INT)
   mov %eax, dword ptr [ %ebp-4 ]
   cmp %eax, dword ptr [ %ebp-8 ]
   jl __L_TRUE_9
__L_FALSE_9:
   mov %edi, 0
   jmp __L_DONE_9
__L_TRUE_9:
   mov %edi, 0xffffffff
   jmp __L_DONE_9
__L_DONE_9:
#  If %edi
   cmp %edi, 0
   je __L_FALSE_10
__L_TRUE_10:
#  Array access: A[dword ptr [ %ebp-4 ]] (GLOBAL)
   mov %eax, dword ptr [ %ebp-4 ]
   sub %eax, 0
   mov %edx, 4
   imul %edx
#  Load access link and get variable from main
   mov %edx, [ %ebp + 8 ]
   add %edx, -84
#  Add offset
   add %edx, %eax
   mov %esi, %edx
#  Assignment: t := [ %esi ]
   mov %ebx, [ %esi ]
   mov dword ptr [ %ebp-16 ], %ebx
#  Cleared the register manager.
#  Array access: A[dword ptr [ %ebp-4 ]] (GLOBAL)
   mov %eax, dword ptr [ %ebp-4 ]
   sub %eax, 0
   mov %edx, 4
   imul %edx
#  Load access link and get variable from main
   mov %edx, [ %ebp + 8 ]
   add %edx, -84
#  Add offset
   add %edx, %eax
   mov %edi, %edx
#  Array access: A[dword ptr [ %ebp-8 ]] (GLOBAL)
   mov %eax, dword ptr [ %ebp-8 ]
   sub %eax, 0
   mov %edx, 4
   imul %edx
#  Load access link and get variable from main
   mov %edx, [ %ebp + 8 ]
   add %edx, -84
#  Add offset
   add %edx, %eax
   mov %esi, %edx
#  Assignment: A := [ %esi ]
   mov %ebx, [ %esi ]
   mov [ %edi ], %ebx
#  Cleared the register manager.
#  Array access: A[dword ptr [ %ebp-8 ]] (GLOBAL)
   mov %eax, dword ptr [ %ebp-8 ]
   sub %eax, 0
   mov %edx, 4
   imul %edx
#  Load access link and get variable from main
   mov %edx, [ %ebp + 8 ]
   add %edx, -84
#  Add offset
   add %edx, %eax
   mov %edi, %edx
#  Assignment: A := dword ptr [ %ebp-16 ]
   mov %esi, dword ptr [ %ebp-16 ]
   mov [ %edi ], %esi
#  Cleared the register manager.
   jmp __L_DONE_10
__L_FALSE_10:
#  Return dword ptr [ %ebp-8 ]
   mov %eax, dword ptr [ %ebp-8 ]
   leave
   ret
__L_DONE_10:
   jmp __L_TRUE_4
__L_DONE_4:
#  default leave return
   leave
   ret
# ---------------------------------------------------------------------------- #
quicksort:
   push %ebp
   mov %ebp, %esp
#  Allocating stack for quicksort
   sub %esp, 4
#  Deference paremeter address
   mov %edi, dword ptr [ %ebp+16 ]
#  Deference paremeter address
   mov %esi, dword ptr [ %ebp+20 ]
#  [ %edi ] < [ %esi ] (INT)
   mov %eax, [ %edi ]
   cmp %eax, [ %esi ]
   jl __L_TRUE_11
__L_FALSE_11:
   mov %ebx, 0
   jmp __L_DONE_11
__L_TRUE_11:
   mov %ebx, 0xffffffff
   jmp __L_DONE_11
__L_DONE_11:
#  If %ebx
   cmp %ebx, 0
   je __L_FALSE_12
__L_TRUE_12:
#  Store temporary %esp (which will be the base of the temporary parameter stack) in register
   mov %edx, %esp
#  Deference paremeter address
   mov %edi, dword ptr [ %ebp+20 ]
#  deriveAddress: [ %edi ] -> %edi
#  Pushing procedure argument (Variable)
   lea %eax, %edi
   push %eax
#  Deference paremeter address
   mov %esi, dword ptr [ %ebp+16 ]
#  deriveAddress: [ %esi ] -> %esi
#  Pushing procedure argument (Variable)
   lea %eax, %esi
   push %eax
#  Deference paremeter address
   mov %ecx, dword ptr [ %ebp+12 ]
#  deriveAddress: [ %ecx ] -> %ecx
#  Pushing procedure argument (Variable)
   lea %eax, %ecx
   push %eax
#  Push main's access link (already on the stack)
   push [ %ebp + 8 ]
   call partition
   add %esp, 16
#  Grab return value
   mov !!! Ran out of free registers !!!, %eax
#  Assignment: q := !!! Ran out of free registers !!!
   mov !!! Ran out of free registers !!!, !!! Ran out of free registers !!!
   mov dword ptr [ %ebp-4 ], !!! Ran out of free registers !!!
#  Cleared the register manager.
#  Store temporary %esp (which will be the base of the temporary parameter stack) in register
   mov %edx, %esp
#  deriveAddress: dword ptr [ %ebp-4 ] -> [ %ebp-4 ]
#  Pushing procedure argument (Variable)
   lea %eax, [ %ebp-4 ]
   push %eax
#  Deference paremeter address
   mov %edi, dword ptr [ %ebp+16 ]
#  deriveAddress: [ %edi ] -> %edi
#  Pushing procedure argument (Variable)
   lea %eax, %edi
   push %eax
#  Deference paremeter address
   mov %esi, dword ptr [ %ebp+12 ]
#  deriveAddress: [ %esi ] -> %esi
#  Pushing procedure argument (Variable)
   lea %eax, %esi
   push %eax
#  Push main's access link (already on the stack)
   push [ %ebp + 8 ]
   call quicksort
   add %esp, 16
#  Store temporary %esp (which will be the base of the temporary parameter stack) in register
   mov %edx, %esp
#  dword ptr [ %ebp-4 ] + 1 (INT)
   mov %ebx, dword ptr [ %ebp-4 ]
   add %ebx, 1
#  Storing expression result on stack
   push %ebx
#  Deference paremeter address
   mov %ecx, dword ptr [ %ebp+20 ]
#  deriveAddress: [ %ecx ] -> %ecx
#  Pushing procedure argument (Variable)
   lea %eax, %ecx
   push %eax
#  Pushing temporary stack address
   mov %eax, %edx
   sub %eax, 4
   push %eax
#  Deference paremeter address
   mov !!! Ran out of free registers !!!, dword ptr [ %ebp+12 ]
#  Pushing procedure argument (Variable)
   lea %eax, [ !!! Ran out of free registers !!! ]
   push %eax
#  Push main's access link (already on the stack)
   push [ %ebp + 8 ]
   call quicksort
   add %esp, 20
   jmp __L_DONE_12
__L_FALSE_12:
__L_DONE_12:
#  default leave return
   leave
   ret
