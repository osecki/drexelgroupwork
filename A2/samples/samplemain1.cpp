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

	cout << "Add(n)" << endl;
	cout << "i := n; s := 0;" << endl;
	cout << "while i do s := s+i; i := i-1 od;" << endl;
	cout << "return := s" << endl;
        Proc *Add;
	list<string> *paramlist;
	paramlist = new list<string>;
	paramlist->push_front("n");

	cout << "Creating function" << endl;

	Add = new Proc(paramlist,SL);

	map<string,int> NT;
	map<string,Proc*> FT;
	NT.clear();  FT.clear();
	FT["add"] = Add;
	list<Expr*> *arglist;
	Expr *E1;
	int n;
	cout << "Enter n:  ";
	cin >> n;
	E1 = new Number(n);
	arglist = new list<Expr*>;
	arglist->push_front(E1);

	cout << "Calling function" << endl;
	cout << "Add(" << E1->eval(NT,FT) << ") = ";
        cout << Add->apply(NT,FT,arglist) << endl;
       
	return 0;
}
