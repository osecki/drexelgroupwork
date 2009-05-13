/**
 * Program:  Proc.h
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 * Class:    CS550, Assignment 4, Spring 2009
**/

#ifndef PROC_H
#define PROC_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "StmtList.h"
#include "Element.h"

using namespace std;

class Expr;

class Proc : public Element {

public:
    Proc(list<string> *PL, StmtList *SL);
    ~Proc();

	virtual string toString(map<string,Element*> NT) const;
  	virtual Element* eval(map<string,Element*> &NT) const;
  	void setTheEnvironment(map<string,Element*>* NewNT) ;

	Element* apply(map<string,Element*> &NT, list<Expr*> *EL);

private:
	StmtList *SL_;
	list<string> *PL_;
	int NumParam_;
	map<string, Element*> *savedEnvironment;
};

#endif
