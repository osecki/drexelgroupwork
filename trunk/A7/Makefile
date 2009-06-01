CC=g++-4.2
C=gcc-4.2
OPTIMIZE=false
CFLAGS = -Wall -g -DOPTIMIZE=$(OPTIMIZE)
SRC_FILES=interpreter.tab.cpp AssignStmt.cpp FunCall.cpp IfStmt.cpp Minus.cpp Plus.cpp Program.cpp SymbolDetails.cpp WhileStmt.cpp DefineStmt.cpp Ident.cpp Number.cpp Proc.cpp StmtList.cpp Times.cpp
OBJECT_FILES=$(SRC_FILES:.cpp=.o)

all:Compiler

Compiler: $(OBJECT_FILES) lex.yy.o interpreter.tab.o
	$(CC) $(CFLAGS) -o $@ $^

Parser: lex.yy.c interpreter.tab.c
	$(C) $(CFLAGS) $^ -ly -lfl -o $@

lex.yy.c: lex.l
	flex lex.l

lex.yy.o: lex.yy.c
	$(C) -c lex.yy.c

interpreter.tab.cpp: interpreter.ypp
	bison *.ypp

interpreter.tab.c interpreter.tab.h: interpreter.y
	bison -d *.y	

interpreter.tab.o: interpreter.tab.h interpreter.tab.c


$(OBJECT_FILES): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f lex.yy.c *.o *.tab.* Compiler Parser
