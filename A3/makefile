flex: ML-lex.l
	flex ML-lex.l

parse: *.ypp *.y
	bison *.ypp
	bison -d *.y

compile: lex.yy.c interpreter.tab.cpp
	gcc -c lex.yy.c
	g++-4.2 *.cpp lex.yy.o -o Compiler

debug: lex.yy.c
	bison -d *.y
	gcc-4.2 *.c -ly -lfl -o Debugger

run: Compiler
	./Compiler

clean:
	rm -f lex.yy.c lex.yy.o *.tab.* Compiler
