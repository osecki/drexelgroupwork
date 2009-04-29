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

List::List(int address) {
    this->address = address;
}

// destructor
List::~List() {
    for (list<Expr*>::iterator iterator = expressions->begin(); iterator != expressions->end(); iterator++) {
        delete (*iterator);
    }
    delete expressions;
}

int List::listp() {
	    return 1;
}

// general functions
string List::toString(const Memory &memory) const {
    string s = "[";

    int current = address;
    while(current != NULL_POINTER) {
        s = s + memory[current].car->toString(memory);
        current = memory[current].cdr;
        if(current != NULL_POINTER)
            s = s + ",";
    }

    return s + "]";
}

Element* List::eval(map<string,Element*> NT, map<string,Proc*> FT, Memory &memory) const {

    if(expressions->size()) {
        int address = NULL_POINTER;
        Element* e ;
        for (list<Expr*>::reverse_iterator iterator = expressions->rbegin(); iterator != expressions->rend(); iterator++) {
            e = (*iterator)->eval(NT,FT,memory);
            address = memory.cons(e, address, NT);
            e->setAddress(address);
            NT[TEMP_NAME] = e;
        }

        NT.erase(NT.find(TEMP_NAME));
        return new List(address);
    }

    return new List(NULL_POINTER);
}
