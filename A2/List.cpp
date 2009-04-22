/**
 * Program:  Element.cpp
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, and Alimoor Reza
 * Class:    CS550, Assignment 2, Spring 2009
**/

#include "List.h"
#include "Element.h"
#include "Number.h"
using namespace std;

List::List() {
    elements = new list<Element*>;
}

// constructor with sequence
List::List (list<Element*> *s) {
    elements = new list<Element*>;
    elements->insert(elements->begin(), s->begin(), s->end());
}

List::List(List* other) {
    elements = new list<Element*>;
    elements->insert(elements->begin(), other->elements->begin(), other->elements->end());
}

Element* List::getFirst() {
    if(elements->size()) {
        return elements->front();
    } else {
        // Return null list
        return new List;
    }
}

Element* List::getRest() {
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
		   // Return null list
			 return new List;
	 }
}

int List::nullp()
{
	return elements->size() == 0;
}


void List::cons (Element* e)
{
	elements->push_front(e);
}




void List::concatenate(List* other) {
    elements->insert(elements->end(), other->elements->begin(), other->elements->end());
}


string List::toString() const {
    string s = "[";

    // TODO convert to in index and avoid last ,
    for (list<Element*>::iterator iterator = elements->begin(); iterator != elements->end(); iterator++) {
        s = s + (*iterator)->toString();
        s = s + ",";
    }
    return s + "]";
}

Element* List::eval(map<string,Element*> NT, map<string,Proc*> FT) const {
    List* newL = new List;
    newL->elements = elements;
    return newL;
}

List::~List() {
    for (list<Element*>::iterator iterator = elements->begin(); iterator != elements->end(); iterator++) {
        delete (*iterator);
    }
    delete elements;
}

int List::listp() {
    return 1;
}
