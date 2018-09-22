# Nonsense Compiler

## Requirements:
- bison
- flex

## How to use:

To compile the compiler, run:
```
make
```

This will create the `nsc` binary.

To compile a nonsense program, run:
```
./nsc [nonsense-source.ns]
# e.g. ./nsc test_programs/ten.ns | program.S
```

This will output the assembly to stdout. The assembly is for 32-bit machines only.

To compile the assembly into a binary, run the following **on a 32 bit machine**:
```
g++ program.S -o bin
```
**The file must have a `.S` extention in order for g++ to run its preprocessor, removing comments before compilation.**

Alternatively, you can do all of the above in one step. **On a 32 bit machine**, run:
```
make bin
```
This will make a binary out of the nonsense program specified in the top of the makefile. (`SRC`)

## By Josh Chandler