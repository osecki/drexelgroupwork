/**
 * Program:  List.cpp
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, and Alimoor Reza
 * Class:    CS550, Assignment 2, Spring 2009
**/

#include "List.h"
#include "Element.h"
#include "Number.h"
#include "ConsCell.h"
#include<vector>

using namespace std;

// default constructor
List::List() {
    elements = new list<Element*>;
}

// constructor with sequence
List::List (list<Element*> *s) {
    elements = new list<Element*>;
    elements->insert(elements->begin(), s->begin(), s->end());
}

// copy constructor
List::List(List* other) {
    elements = new list<Element*>;
    elements->insert(elements->begin(), other->elements->begin(), other->elements->end());
}

// destructor
List::~List() {
	    for (list<Element*>::iterator iterator = elements->begin(); iterator != elements->end(); iterator++) {
				        delete (*iterator);
								    }
			    delete elements;
}

// functions for A2
Element* List::getFirst() {
	  // If list size >= 1, then return first element, otherwise crash
    if(elements->size()) {
        return elements->front();
    } else {
        // Error out
				cout << "ERROR:  Cannot do a Car(list) on an empty list or other object." << endl;
				exit(1);
        return new List;
    }
}

Element* List::getRest() {
	 // If list size >= 2, return all but the first element, otherwise crash
	 if (elements->size() + 1) {
		   list<Element*> * temp = new list<Element*>;
			 list<Element*>::iterator iterator = elements->begin();
			 iterator++;

			 while ( iterator != elements->end() )
			 {
				 temp->push_back((*iterator));
				 iterator++;
			 }
			 return new List (temp);
	 } else {
		   // Error out
			 cout << "ERROR:  Cannot do a Cdr(list) on an empty list or other object." << endl;
			 exit(1);
			 return new List;
	 }
}

int List::nullp()
{
	return elements->size() == 0;
}

int List::listp() {
	    return 1;
}

void List::cons (Element* e)
{
	elements->push_front(e);
}

void List::concatenate(List* other) {
    elements->insert(elements->end(), other->elements->begin(), other->elements->end());
}

// general functions
string List::toString() const {
    string s = "[";

    // Iterate over elements and print out each one and commas
    list<Element*>::iterator iterator = elements->begin();
		while ( iterator != elements->end() )
		{
        s = s + (*iterator)->toString();

				iterator++;

				if ( iterator != elements->end() )
					s = s + ',';
    }
    return s + "]";
}

Element* List::eval(map<string,Element*> &NT, map<string,Proc*> &FT,vector<ConsCell> &listMemory, int &avail) const {
    List* newL = new List;
    newL->elements = elements;
    return newL;
}

int List::getStartAddress() {
	return this->startAddress;
}

void List::setStartAddress(int stAddress) {
	startAddress = stAddress;
}

