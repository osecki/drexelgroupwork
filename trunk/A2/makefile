JAVAC = javac
JAVA = java
CLASSPATH = /usr/share/java/cup.jar:/usr/share/java/JFLex.jar:.
INPUT_FILE = sample_input

parse: ML-interpreterBody.ypp ML-interpreterHead.y
	bison ML-interpreterBody.ypp
	bison -d ML-interpreterHead.y

flex: ML-lex.l
	flex ML-lex.l

compile: lex.yy.c ML-interpreterBody.tab.cpp DataTypes.cpp
	gcc -c lex.yy.c
	g++ ML-interpreterBody.tab.cpp DataTypes.cpp lex.yy.o -o Compiler

run: Compiler
	./Compiler

runfile: Compiler
	./Compiler < $(INPUT_FILE)
