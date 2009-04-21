#include "List.h"
#include <iostream>
using namespace std;

List::List() {
    elements = new list<Element*>;
}

// constructor with sequence
List::List (list<Element*> *s) {
    elements = s;
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

string List::toString() const {
    string s = "(";

    for (list<Element*>::iterator iterator = elements->begin(); iterator != elements->end(); iterator++) {
        s = s + (*iterator)->toString();
        s = s + ",";
    }
    return s;
    return s + ")";
}


// What does it mean to evalute a list?
int List::eval(map<string,int> NT, map<string,Proc*> FT) const {
    return elements->size();
}

List::~List() {
    for (list<Element*>::iterator iterator = elements->begin(); iterator != elements->end(); iterator++) {
        delete (*iterator);
    }
    delete elements;
}
