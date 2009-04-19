#include "List.h"


List::List() {
    elements = NULL;
}

// constructor with sequence
List::List (list<Element*> *s) {
    elements = s;
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
    return 0;
}

List::~List() {
    for (list<Element*>::iterator iterator = elements->begin(); iterator != elements->end(); iterator++) {
        delete (*iterator);
    }
    delete elements;
}
