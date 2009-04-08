JAVAC = javac
JAVA = java
CLASSPATH = /usr/share/java/cup.jar:/usr/share/java/JFLex.jar:.
INPUT_FILE = sample_input

part1: compile1 run1
part2: parse lex compile2 run2

part1file: compile1 run1file
part2file: parse lex compile2 run2file

parse: *.cup
	cup *.cup

lex: *.lex
	jflex *.lex

compile2: sym.java parser.java Yylex.java 
	$(JAVAC) -classpath $(CLASSPATH) sym.java parser.java Yylex.java List.java ListElement.java NumberListElement.java Sequence.java ListListElement.java

run2:
	$(JAVA) -classpath $(CLASSPATH) parser

run2file:
	$(JAVA) -classpath $(CLASSPATH) parser < $(INPUT_FILE)

compile1: List_RDP.java
	$(JAVAC) List_RDP.java List.java ListElement.java NumberListElement.java Sequence.java ListListElement.java

run1:
	$(JAVA) List_RDP

run1file:
	$(JAVA) List_RDP < $(INPUT_FILE)
