/*
 * file:  main.h (main program to test Expr).
 * Author: Jeremy Johnson 
 * Date: 2/5/07
 *
 * Description:
 */

#include <iostream>
#include <string>
#include <map>
#include <list>
#include "programext.h"

using namespace std;


int main()
{

	StmtList *SL, *SL1;
	Stmt *S1, *S2, *S3, *S4, *S5, *S6;
	Expr *E;


// statement list for Add function

	S1 = new AssignStmt("i",new Ident("n"));
	S2 = new AssignStmt("s",new Number(0));
	S3 = new AssignStmt("s",
                   new Plus(new Ident("s"), new Ident("i")));
	S4 = new AssignStmt("i",
                   new Minus(new Ident("i"), new Number(1)));
	SL1 = new StmtList();
	SL1->insert(S4);  SL1->insert(S3);
	E = new Ident("i");

	S5 = new WhileStmt(E,SL1);

	S6 = new AssignStmt("return", new Ident("s"));

	SL = new StmtList();
	SL->insert(S6);  SL->insert(S5);  SL->insert(S2); SL->insert(S1);

        Proc *Add;
	list<string> *paramlist;
	paramlist = new list<string>;
	paramlist->push_front("n");
	Add = new Proc(paramlist,SL);

	cout << "Program that defines and calls add" << endl << endl;
	cout << "define add proc(n)" << endl;
	cout << "  i := n; s := 0;" << endl;
	cout << "  while i do s := s+i; i := i-1 od;" << endl;
	cout << "  return := s" << endl;
	cout << "end" << endl;
	cout << "n := 5;" << endl;
	cout << "s := add(n)" << endl << endl;

	Stmt *S7, *S8, *S9, *S10;
	Expr *E1;
	list<Expr*> *AL;
	StmtList *PSL;

	S7 = new DefineStmt("add",Add);
	E1 = new Number(5);
	S8 = new AssignStmt("n",E1);
	AL = new list<Expr*>;
	AL->push_front(E1);
	S9 = new AssignStmt("s",new FunCall("add",AL));
	PSL = new StmtList();
	PSL->insert(S9); PSL->insert(S8); PSL->insert(S7);


	Program P(PSL);
	cout << "Testing Program" << endl;
	P.eval();
	cout << "Symbol Table dump" << endl;
	P.dump();	
	cout << endl;

	return 0;
}


