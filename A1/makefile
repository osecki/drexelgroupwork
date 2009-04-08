JAVAC = javac
JAVA = java
CLASSPATH = /usr/share/java/cup.jar:/usr/share/java/JLex.jar:.

parse: *.cup
	cup *.cup

lex: *.lex
	jflex *.lex

compile1: sym.java parser.java Yylex.java 
	$(JAVAC) sym.java parser.java Yylex.java List.java ListElement.java NumberListElement.java Sequence.java Sequence.java
	
run1:
	$(JAVA) -classpath $(CLASSPATH) parser

compile2: List_RDP.java
	$(JAVAC) List_RDP.java List.java ListElement.java NumberListElement.java Sequence.java Sequence.java

run2:
	$(JAVA) List_RDP