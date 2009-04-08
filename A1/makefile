JAVAC = javac
JAVA = java
CLASSPATH = /usr/share/java/cup.jar:/usr/share/java/JLex.jar:.

parse: *.cup
	cup *.cup

lex: *.lex
	jflex *.lex

compile: sym.java parser.java Yylex.java 
	$(JAVAC) sym.java parser.java Yylex.java List.java ListElement.java NumberListElement.java Sequence.java Sequence.java
run:
	$(JAVA) -classpath $(CLASSPATH) parser