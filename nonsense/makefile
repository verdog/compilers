SRC = ./test_programs/ten.ns
OBJS = ns.tab.o lex.yy.o types.o

nsc: $(OBJS)
	g++ -g $(OBJS) -o $@ -std=c++11

types.o: types.cpp types.hpp
	g++ -g -c types.cpp -std=c++11

ns.tab.o: ns.y
	bison -d ns.y
	g++ -g -c ns.tab.c -std=c++11

lex.yy.o: ns.l
	flex ns.l
	g++ -g -c lex.yy.c -std=c++11

clean:
	rm -f *.o *~ *.tab.c *.tab.h nsc program.S bin lex.yy.c

program.S: $(SRC) nsc
	./nsc $(SRC) > program.S

bin: $(SRC) program.S
	g++ program.S -o bin

test: bin
	./bin

# these were used to compile the assembly on a VM.
remote-bin: $(SRC) program.S
	scp ./program.S ub32:~/Code/compilers/nonsense
	ssh ub32 'cd ~/Code/compilers/nonsense && g++ program.S -o remote-bin'

remote-test: remote-bin
	ssh ub32 'cd ~/Code/compilers/nonsense && ./remote-bin'
