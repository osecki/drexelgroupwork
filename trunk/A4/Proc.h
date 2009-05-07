/**
 * Program:  Proc.h
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 * Class:    CS550, Assignment 4, Spring 2009
**/

#ifndef PROC_H
#define PROC_H

#include <iostream>
#include <map>
#include <string>
#include "StmtList.h"
#incldue "Element.h"

using namespace std;

class Expr;

class Proc : public Element {

public:
    	Proc(list<string> *PL, StmtList *SL);
    	~Proc() {delete SL_; };
		
	virtual string toString() const;
  	virtual Element* eval(map<string,Element*> NT, map<string,Proc*> FT) const;

	Element* apply(map<string,Element*> &NT, map<string,Proc*> &FT, list<Expr*> *EL);

private:
    	StmtList *SL_;
    	list<string> *PL_;
    	int NumParam_;
};

#endif
