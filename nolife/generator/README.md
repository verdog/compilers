# Nolife Compiler

## Requirements
For this compiler, your system needs to have:
* flex
* bison
* a c++ compiler that supports c++11

## Compiling the Compiler
Type these commands in the directory containing this readme:
```
make clean
make
```

## Compiling a Nolife Program
To compile a Nolife program, call `./nlc`. 

```
./nlc <.nl file to check>
```

e.g.:
```
./nlc simple.nl
```

This will put a memory map into `simple.mem` and assembly into `simple.S`.

## Layout of this Repository

The `parser` directory contains files for flex, bison, and the AST.  
The `utilities` directory contains utility classes (various managers) used by the code generator.
The `visitors` directory contains visitors used on the AST.  
There is a type checker visitor, a printer visitor (prints the AST), a memory map visitor, and a code generator visitor.
`nlc.cpp` sets up the visitors and compiles a Nolife program.

## Notes
The type checker will complain if the program name in the Nolife file (e.g. `program foo`) collides with the name of a variable or procedure. To fix this, just change the name of the program name.

Written by Josh Chandler for CS 5810.