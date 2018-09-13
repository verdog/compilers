OBJS = ns.tab.o lex.yy.o types.o
nsc: $(OBJS)
	g++ -g $(OBJS) -o $@

types.o: types.hpp
	g++ -g -c types.cpp

ns.tab.o: ns.y types.hpp
	bison -d ns.y
	bison ns.y
	g++ -g -c ns.tab.c

lex.yy.o: ns.l types.hpp
	flex ns.l
	g++ -g -c lex.yy.c

clean:
	/bin/rm -f *.o *~ *.tab.c *.tab.h nsc
