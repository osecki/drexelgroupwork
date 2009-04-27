/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CAR = 258,
     CDR = 259,
     NULLP = 260,
     LISTP = 261,
     INTP = 262,
     CONS = 263,
     IDENT = 264,
     NUMBER = 265,
     ASSIGNOP = 266,
     DEFINE = 267,
     IF = 268,
     THEN = 269,
     ELSE = 270,
     FI = 271,
     WHILE = 272,
     DO = 273,
     OD = 274,
     PROC = 275,
     END = 276
   };
#endif
/* Tokens.  */
#define CAR 258
#define CDR 259
#define NULLP 260
#define LISTP 261
#define INTP 262
#define CONS 263
#define IDENT 264
#define NUMBER 265
#define ASSIGNOP 266
#define DEFINE 267
#define IF 268
#define THEN 269
#define ELSE 270
#define FI 271
#define WHILE 272
#define DO 273
#define OD 274
#define PROC 275
#define END 276




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 1 "ML-interpreterHead.y"
{

/**
 *  Program:  ML-interpreterHead.y
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, and Alimoor Reza
 *  Class:    CS550, Assignment 2, Spring 2009
**/

   int value;
   char *ident;
}
/* Line 1529 of yacc.c.  */
#line 103 "ML-interpreterHead.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

