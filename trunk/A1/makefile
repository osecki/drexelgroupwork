JAVAC = javac
JAVA = java
CLASSPATH = /usr/share/java/cup.jar:/usr/share/java/JFLex.jar:.

part1: compile1 run1
part2: parse lex compile2 run2

parse: *.cup
	cup *.cup

lex: *.lex
	jflex *.lex

compile2: sym.java parser.java Yylex.java 
	$(JAVAC) -classpath $(CLASSPATH) sym.java parser.java Yylex.java List.java ListElement.java NumberListElement.java Sequence.java

run2:
	$(JAVA) -classpath $(CLASSPATH) parser

compile1: List_RDP.java
	$(JAVAC) List_RDP.java List.java ListElement.java NumberListElement.java Sequence.java

run1:
	$(JAVA) List_RDP
