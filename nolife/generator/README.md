# Nolife Compiler

## Requirements
For this compiler, your system needs to have:
* flex
* bison
* a c++ compiler that supports c++11

## Compiling the compiler

Type these commands in the directory containing this readme:
```
make clean
make
```

## Compiling a nolife program
To compile a nolife program, call `./nlc`. 

```
./nlc <.nl file to check>
```

e.g.:
```
./nlc simple.nl
```

This will put a memory map into `simple.mem` and assembly into `simple.S`.

Written by Josh Chandler for CS 5810.