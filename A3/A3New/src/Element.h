/**
 *  Program:  Element.h
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, and Alimoor Reza
 *  Class:    CS550, Assignment 2, Spring 2009
**/

#ifndef ELEMENT_H
#define ELEMENT_H

#include "Expr.h"
#include<iostream>

#include<vector>

using namespace std;

class Proc;

class ConsCell;

class Element : public Expr{
public:
  // These two functions are here because input can be list or number
	virtual int listp();
	virtual int intp();
	virtual ~Element(){};
	virtual Element* eval(map<string,Element*> &NT, map<string,Proc*> &FT,vector<ConsCell> &listMemory, int &avail) const = 0;
	virtual string toString() const = 0;
	bool getIntOrPtr() const;
	void setIntOrPtr(bool);
	void print();
private:
	// intOrPtr == true means integer and false means ptr
	bool intOrPtr;
};


#endif

