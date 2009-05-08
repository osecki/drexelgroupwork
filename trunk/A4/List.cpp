/**
 * Program:  List.cpp
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 * Class:    CS550, Assignment 4, Spring 2009
**/

#include "List.h"
#include "Element.h"
#include "Number.h"
using namespace std;

// default constructor
List::List() {
    elements = new list<Expr*>;
}

// constructor with sequence
List::List (list<Expr*> *s) {
    elements = new list<Expr*>;
    elements->insert(elements->begin(), s->begin(), s->end());
}

// copy constructor
List::List(List* other) {
    elements = new list<Expr*>;
    elements->insert(elements->begin(), other->elements->begin(), other->elements->end());
}

// destructor
List::~List() {
    for (list<Expr*>::iterator iterator = elements->begin(); iterator != elements->end(); iterator++) {
        delete (*iterator);
    }
    delete elements;
}

// functions for A2
Expr* List::getFirst() {
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

Expr* List::getRest() {
	 // If list size >= 2, return all but the first element, otherwise crash
	 if (elements->size() + 1) {
        list<Expr*> * temp = new list<Expr*>;
        list<Expr*>::iterator iterator = elements->begin();
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

void List::cons (Expr* e)
{
	elements->push_front(e);
}

void List::concatenate(List* other) {
    elements->insert(elements->end(), other->elements->begin(), other->elements->end());
}

// general functions
string List::toString((map<string,Element*> NT) const {
    string s = "[";

    // Iterate over elements and print out each one and commas
    list<Expr*>::iterator iterator = elements->begin();
    while ( iterator != elements->end() )
    {
        s = s + (*iterator)->eval(NT)->toString(NT);

        iterator++;

        if ( iterator != elements->end() )
            s = s + ',';
    }
    return s + "]";
}

Element* List::eval(map<string,Element*> NT) const {
    List* newL = new List;
    newL->elements = elements;
    return newL;
}

