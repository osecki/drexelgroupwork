/**
 * Program:  Proc.h
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 * Class:    CS550, Assignment 4, Spring 2009
**/

#ifndef NEWCLASS_H
#define NEWCLASS_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "StmtList.h"
#include "Element.h"

using namespace std;

class Expr;

class NewClass : public Element {

public:
    NewClass(string name, list<string> *PL, StmtList *SL);
    ~NewClass();

	virtual string toString(map<string,Element*> NT) const;
  	virtual Element* eval(map<string,Element*> &NT) const;
  	void setTheEnvironment(map<string,Element*>* NewNT) ;
  	map<string, Element*>* getTheEnvironment();
  	string getName();
	Element* constructor(map<string,Element*> &NT, list<Expr*> *EL);

private:
	StmtList *SL_;
	list<string> *PL_;
	int NumParam_;
	string name_;
	map<string, Element*>* savedEnvironment;
};

#endif
