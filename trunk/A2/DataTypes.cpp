/*
 * file:  expr.cpp (implementation of Expr).
 * Author: Jeremy Johnson 
 * Date: 2/5/07
 *
 * Description: 
 */

#include <iostream>
#include <string>
#include <map>
#include <list>
#include "DataTypes.h"

using namespace std;


Program::Program(StmtList *SL)
{
NameTable_.clear();
FunctionTable_.clear();
SL_ = SL;
}

void Program::dump() 
{
  map<string,int>::iterator p;
  map<string,Proc*>::iterator f;

  cout << "Dump of Symbol Table" << endl;
  cout << "Name Table" << endl;
  for (p = NameTable_.begin();p != NameTable_.end();p++)
    cout << p->first << " -> " << p->second << endl;
  cout << "Function Table" << endl;
  for (f = FunctionTable_.begin();f != FunctionTable_.end();f++) 
    cout << f->first << endl;
}

void Program::eval() 
{
	SL_->eval(NameTable_, FunctionTable_);
}


void StmtList::insert(Stmt * S)
{
  SL_.push_front(S);
}

void StmtList::eval(map<string,int> &NT, map<string,Proc*> &FT) 
{
  list<Stmt*>::iterator Sp;
  for (Sp = SL_.begin();Sp != SL_.end();Sp++)
	(*Sp)->eval(NT,FT);
}

AssignStmt::AssignStmt(string name, Expr *E)
{
  name_ = name;
  E_ = E;
}

void AssignStmt::eval(map<string,int> &NT, map<string,Proc*> &FT) const
{
	NT[name_] = E_->eval(NT,FT);
}

DefineStmt::~DefineStmt()
{
  delete P_; 
}

DefineStmt::DefineStmt(string name, Proc *P)
{
  name_ = name;
  P_ = P;
}

void DefineStmt::eval(map<string,int> &NT, map<string,Proc*> &FT) const
{
	FT[name_] = P_;
}

IfStmt::IfStmt(Expr *E, StmtList *S1, StmtList *S2)
{
  E_ = E;
  S1_ = S1;
  S2_ = S2;
}

IfStmt::~IfStmt() { delete E_; delete S1_; delete S2_; }

void IfStmt::eval(map<string,int> &NT, map<string,Proc*> &FT) const
{
	if (E_->eval(NT,FT) > 0)
		S1_->eval(NT,FT);
	else
		S2_->eval(NT,FT);
}

WhileStmt::WhileStmt(Expr *E, StmtList *S)
{
  E_ = E;
  S_ = S;
}

WhileStmt::~WhileStmt() { delete E_; delete S_; }

void WhileStmt::eval(map<string,int> &NT, map<string,Proc*> &FT) const
{
	while (E_->eval(NT,FT) > 0) 
		S_->eval(NT,FT);
}

Number::Number(int value)
{
	value_ = value;
}

int Number::eval(map<string,int> NT, map<string,Proc*> FT) const
{
	return value_;
}

Ident::Ident(string name)
{
	name_ = name;
}

int Ident::eval(map<string,int> NT, map<string,Proc*> FT) const
{
	return NT[name_];
}

Plus::Plus(Expr* op1, Expr* op2)
{
	op1_ = op1;
	op2_ = op2;
}

int Plus::eval(map<string,int> NT, map<string,Proc*> FT) const
{
	return op1_->eval(NT,FT) + op2_->eval(NT,FT);
}

Minus::Minus(Expr* op1, Expr* op2)
{
	op1_ = op1;
	op2_ = op2;
}

int Minus::eval(map<string,int> NT, map<string,Proc*> FT) const
{
	return op1_->eval(NT,FT) - op2_->eval(NT,FT);
}

Times::Times(Expr* op1, Expr* op2)
{
	op1_ = op1;
	op2_ = op2;
}

int Times::eval(map<string,int> NT, map<string,Proc*> FT) const
{
	return op1_->eval(NT,FT) * op2_->eval(NT,FT);
}

FunCall::FunCall(string name, list<Expr*> *AL)
{
	name_= name;
	AL_ = AL;
}

FunCall::~FunCall() { delete AL_; }

int FunCall::eval(map<string,int> NT, map<string,Proc*> FT) const
{
	return FT[name_]->apply(NT, FT, AL_);
}


Proc::Proc(list<string> *PL, StmtList *SL)
{
	SL_ = SL;
	PL_ = PL;
	NumParam_ = PL->size();
}

int Proc::apply(map<string,int> &NT, map<string,Proc*> &FT, list<Expr*> *EL) 
{
	map<string,int> NNT;
	NNT.clear();

	// bind parameters in new name table

	list<string>::iterator p;
	list<Expr*>::iterator e;
	if (NumParam_ != EL->size()) {
		cout << "Param count does not match" << endl;
		exit(1);
	}
	for (p = PL_->begin(), e = EL->begin(); p != PL_->end(); p++, e++) 
		NNT[*p] = (*e)->eval(NT,FT);

	// evaluate function body using new name table and old function table

	SL_->eval(NNT,FT);
	if ( NNT.find("return") != NNT.end() )
		return NNT["return"];
	else {
		cout << "Error:  no return value" << endl;
		exit(1);
	}
}


/*
 * List.h
 *
 *  Created on: Apr 13, 2009
 *      Author: reza
 */

#ifndef LIST_H_
#define LIST_H_
#include<iostream>
#include "ListElement.h"
#include "Sequence.h"
using namespace std;
class List : public ListElement{

public:
	// default constructor
	List() {
		elements = NULL;
	}

	// constructor with sequence
	List (Sequence s) {
		elements = s;
	}

	string toString() {
		string s = "(";
		if (elements != NULL)
			s = s + elements.toString();
		return s + ")";
	}

	void print() {
		cout<<toString()<<endl;
	}
private:
	Sequence elements;
};
#endif /* LIST_H_ */


/*
 * Sequence.h
 *
 *  Created on: Apr 13, 2009
 *      Author: reza
 */

#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include<iostream>
#include<vector>
using namespace std;
#include "ListElement.h";

class Sequence {

public:

	Sequence(ListElement e) {
		elements = new vector<ListElement>();
		elements.push_front(e);
	}

	string toString() {
        string s = "";

        for (Iterator<ListElement> iterator = elements.iterator (); iterator.hasNext (); ) {
            s = s + iterator.next().toString();
            if(iterator.hasNext()) {
                s = s + ",";
            }
        }
        return s;
    }

private:
	vector<ListElement> elements;

};
#endif /* SEQUENCE_H_ */


/*
 * ListElement.h
 *
 *  Created on: Apr 13, 2009
 *      Author: reza
 */

#ifndef LISTELEMENT_H_
#define LISTELEMENT_H_

#include<iostream>
using namespace std;

class ListElement{
public:
	// this method must be overriden in the child class
	virtual string toString();
	void print() {
		cout<<toString()<<endl;
	}


};


#endif /* LISTELEMENT_H_ */


/*
 * ListListElement.h
 *
 *  Created on: Apr 13, 2009
 *      Author: reza
 */

#ifndef LISTLISTELEMENT_H_
#define LISTLISTELEMENT_H_
#include "ListElement.h"
class ListListElement : public ListElement {
public:
	ListListElement() {
		l = new List();
	}

	ListListElement(List l) {
		this.l = l;
	}

	string toString() {
		return l.toString();
	}
private:
	List l;
};

#endif /* LISTLISTELEMENT_H_ */


/*
 * NumberListElement.h
 *
 *  Created on: Apr 13, 2009
 *      Author: reza
 */

#ifndef NUMBERLISTELEMENT_H_
#define NUMBERLISTELEMENT_H_
#include "ListElement.h"

class NumberListElement : public ListElement {
public:
	NumberListElement(int n) {
		this.n = n;
	}
	/*string toString() {
		return n.toString();
	}*/

protected:
	int n;
};

#endif /* NUMBERLISTELEMENT_H_ */
