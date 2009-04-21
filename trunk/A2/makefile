INPUT_FILE = samples/sampleNEW

parse: ML-interpreterBody.ypp ML-interpreterHead.y
	bison ML-interpreterBody.ypp
	bison -d ML-interpreterHead.y

flex: ML-lex.l
	flex ML-lex.l

compile: lex.yy.c ML-interpreterBody.tab.cpp
	gcc -c lex.yy.c
	g++-4.2 *.cpp lex.yy.o -o Compiler

run: Compiler
	./Compiler

runfile: Compiler
	./Compiler < $(INPUT_FILE)

clean:
	rm -f lex.yy.c lex.yy.o *.tab.* Compiler
