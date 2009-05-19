/**
 * Program:  List.h
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 * Class:    CS550, Assignment 5, Spring 2009
**/

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <list>
#include <map>
#include "Element.h"

using namespace std;

class Proc;

class List : public Element {

public:
	// default constructor
	List();

	// constructor with sequence
	List (list<Expr*> *s);

      // copy constructor
	List (List* other);

	// destructor
      virtual ~List();

	// Functions for A2
  	Expr* getFirst();
 	Expr* getRest();
  	void concatenate(List* other);
  	void cons (Expr* e);
  	virtual int listp();
  	int nullp();

  	virtual string toString(map<string,Element*> NT) const;
  	virtual Element* eval(map<string,Element*> &NT) const;

private:
	list<Expr*> *elements;
};

#endif
