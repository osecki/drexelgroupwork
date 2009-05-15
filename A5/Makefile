flex: lex.l
	flex lex.l

parse: *.ypp *.y
	bison *.ypp
	bison -d *.y

static: lex.yy.c interpreter.tab.cpp
	gcc -c lex.yy.c
	g++-4.2 -g *.cpp lex.yy.o -DSTATIC=true -o Static
	
dynamic: lex.yy.c interpreter.tab.cpp
	gcc -c lex.yy.c
	g++-4.2 -g *.cpp lex.yy.o -DSTATIC=false -o Dynamic

parserOnly: lex.yy.c
	bison -d *.y
	gcc-4.2 -g *.c -ly -lfl -o Parser

clean:
	rm -f lex.yy.c lex.yy.o *.tab.* Static Dynamic
