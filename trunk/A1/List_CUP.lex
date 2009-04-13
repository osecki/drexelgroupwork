/**
 *  Program:  List_CUP.lex
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, and Alimoor Reza
 *  Class:    CS550, Assignment 1, Spring 2009
 *  Description:  Uses a parser coded in CUP to parse a list, store it in an object, and then print it out.
 **/

/*
 * 1. List:  ( Sequence ) | ( )
 * 2. Sequence:  ListElement, Sequence | ListElement
 * 3. ListElement:  List | NUMBER
 */

// This is the lex file for the List

import java_cup.runtime.Symbol;
%%
%cup
%eof{
%eof}
%%
[\r\n|\n]+ {return new Symbol(sym.ENDLINE); }
[(] {return new Symbol(sym.LPAREN); }
[)] {return new Symbol(sym.RPAREN); }
[,] {return new Symbol(sym.COMMA); }
([0-9]+)|(-[0-9]+) {return new Symbol(sym.NUM, new Integer(yytext())); }
[ \t\f\n\r] {/* ignore white space */}
. {System.err.println("Illegal character: "+yytext());}
