/**
 * Program:  List.cpp
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, and Alimoor Reza
 * Class:    CS550, Assignment 2, Spring 2009
**/

#include "List.h"
#include "Expr.h"
#include "Number.h"
#include "Memory.h"
#include "Program.h"
using namespace std;

// default constructor
List::List() {
    expressions = new list<Expr*>;
}

// constructor with sequence
List::List (list<Expr*> *s) {
    expressions = new list<Expr*>;
    expressions->insert(expressions->begin(), s->begin(), s->end());
}

// copy constructor
List::List(List* other) {
    expressions = new list<Expr*>;
    expressions->insert(expressions->begin(), other->expressions->begin(), other->expressions->end());
}

// destructor
List::~List() {
    for (list<Expr*>::iterator iterator = expressions->begin(); iterator != expressions->end(); iterator++) {
        delete (*iterator);
    }
    delete expressions;
}

// functions for A2
Expr* List::getFirst() {
	  // If list size >= 1, then return first element, otherwise crash
    if(expressions->size()) {
        return expressions->front();
    } else {
        // Error out
				cout << "ERROR:  Cannot do a Car(list) on an empty list or other object." << endl;
				exit(1);
        return new List;
    }
}

Expr* List::getRest() {
	 // If list size >= 2, return all but the first element, otherwise crash
	 if (expressions->size() + 1) {
		   list<Expr*> * temp = new list<Expr*>;
			 list<Expr*>::iterator iterator = expressions->begin();
			 iterator++;

			 while ( iterator != expressions->end() )
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
	return expressions->size() == 0;
}

int List::listp() {
	    return 1;
}

void List::cons (Expr* e)
{
	expressions->push_front(e);
}

void List::concatenate(List* other) {
    expressions->insert(expressions->end(), other->expressions->begin(), other->expressions->end());
}

// general functions
string List::toString() const {
    string s = "[";

    // TODO look at memory

    return s + "]";
}

Element* List::eval(map<string,Element*> NT, map<string,Proc*> FT, Memory &memory) const {

    int address = NULL_POINTER;

    for (list<Expr*>::reverse_iterator iterator = expressions->rbegin(); iterator != expressions->rend(); iterator++) {
        Element* e = (*iterator)->eval(NT,FT,memory);
        address = memory.cons(e, address, NT);
        NT[TEMP_NAME] = e;
    }

    NT.erase(NT.find(TEMP_NAME));

    List* l = new List();
    l->address = address;

    return l;
}


int List::getAddress() {
    return address;
}
