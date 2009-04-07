/*
 *  Program:  List_CUP.lex
 *  Authors:  Jordan Osecki, Joseph Conley, Geoff Oxholm, and Rich Price
 *  Class:    CS550, Assignment 1, Spring 2009
 *  Description:  Uses a parser coded in CUP to parse a list, store it in an object, and then print it out.
 */

/*
 * 1. List:  ( Sequence ) | ( )
 * 2. Sequence:  ListElement, Sequence | ListElement
 * 3. ListElement:  List | NUMBER
 */

// This is the lex file for the List

import java_cup.runtime.Symbol;
%%
%cup
%%
"(" {return new Symbol(sym.LPAREN); }
")" {return new Symbol(sym.RPAREN); }
"," {return new Symbol(sym.COMMA); }
[0-9] {return new Symbol(sym.NUM, new Integer(yytext())); }
[ \t\r\n\f] {/* ignore white space */}
. {System.err.println("Illegal character: "+yytext());}