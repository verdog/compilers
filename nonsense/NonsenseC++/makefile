SRC = ./test_programs/ten.ns
OBJS = ns.tab.o lex.yy.o types.o

nsc: $(OBJS)
	g++ -g $(OBJS) -o $@

types.o: types.cpp types.hpp
	g++ -g -c types.cpp

ns.tab.o: ns.y
	bison -d ns.y
	bison ns.y
	g++ -g -c ns.tab.c

lex.yy.o: ns.l
	flex ns.l
	g++ -g -c lex.yy.c

clean:
	/bin/rm -f *.o *~ *.tab.c *.tab.h nsc program.S

program.S: $(SRC) nsc
	cat $(SRC) | ./nsc > program.S

bin: $(SRC) program.S
	scp ./program.S ub32:~/Code/compilers/nonsense
	ssh ub32 'cd ~/Code/compilers/nonsense && g++ program.S -o bin'

test: $(SRC) program.S
	ssh ub32 'cd ~/Code/compilers/nonsense && ./bin'