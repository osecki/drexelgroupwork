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
#include "ConsCell.h"
#include<vector>


using namespace std;

class Proc;

class List : public Element {

public:
	// default constructor
	List();

	// constructor with sequence
	List (list<Element*> *s);

  // copy constructor
	List (List* other);

	// destructor
  virtual ~List();

	// Functions for A2
  Element* getFirst();
  Element* getRest();
  void concatenate(List* other);
  void cons (Element* e);
  virtual int listp();
  int nullp();
  int getStartAddress();
  void setStartAddress(int sa);

  virtual string toString() const;
  virtual Element* eval(map<string,Element*> &NT, map<string,Proc*> &FT,vector<ConsCell> &listMemory, int &avail) const;

private:
	list<Element*> *elements;
	// address in the virtual memory
	int startAddress;
};

#endif
