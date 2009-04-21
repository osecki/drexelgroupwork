/**
 * Program:  List.h
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, and Alimoor Reza
 * Class:    CS550, Assignment 2, Spring 2009
**/

#ifndef LIST_H_
#define LIST_H_
#include<iostream>
#include <list>
#include <iostream>
#include <map>
#include "Element.h"

using namespace std;

class Proc;

class List : public Element {

public:
	// default constructor
	List();

	// constructor with sequence
	List (list<Element*> *s);

    Element* getFirst();
    Element* getRest();
    /*void nullp();
		List* cons (Element x);
	  List* concatenate ( List a, List b);
    */
	  virtual string toString() const;

    // What does it mean to evalute a list?
    virtual int eval(map<string,int> NT, map<string,Proc*> FT) const;

    virtual ~List();

private:
	list<Element*> *elements;
};
#endif
