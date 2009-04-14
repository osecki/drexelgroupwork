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

// statement list for Addr function

        Proc *Addr;
	list<string> *paramlist;
	paramlist = new list<string>;
	paramlist->push_front("n");
	StmtList *SL;
	SL = new StmtList();
	Addr = new Proc(paramlist,SL);

	Stmt *S1, *S2, *S3;
	StmtList *SL1, *SL2;
	Expr *E, *E1;
	E1 = new Minus(new Ident("n"),new Number(1));
	list<Expr*> *AL1;
	AL1 = new list<Expr*>;
	AL1->push_front(E1);
	S1 = new AssignStmt("return",
                 new Plus(new Ident("n"), new FunCall("addr",AL1)));
	S2 = new AssignStmt("return",new Number(0));
	SL1 = new StmtList(); SL2 = new StmtList();
	SL1->insert(S1);  SL2->insert(S2);
	E = new Ident("n");
	S3 = new IfStmt(E,SL1,SL2);
	SL->insert(S3);


	cout << "Program that defines and calls recursive add" << endl << endl;
	cout << "define addr proc(n)" << endl;
	cout << "  if n then return := n + addr(n-1) else return := 0 fi" << endl;
	cout << "end" << endl;
	cout << "n := 5;" << endl;
	cout << "s := addr(n)" << endl << endl;

	Stmt *S4, *S5, *S6;
	Expr *E2;
	list<Expr*> *AL;
	StmtList *PSL;

	S4 = new DefineStmt("addr",Addr);
	E2 = new Number(5);
	S5 = new AssignStmt("n",E2);
	AL = new list<Expr*>;
	AL->push_front(E2);
	S6 = new AssignStmt("s",new FunCall("addr",AL));
	PSL = new StmtList();
	PSL->insert(S6); PSL->insert(S5); PSL->insert(S4);


	Program P(PSL);
	cout << "Testing Program" << endl;
	P.eval();
	cout << "Symbol Table dump" << endl;
	P.dump();	
	cout << endl;
	return 0;
}


