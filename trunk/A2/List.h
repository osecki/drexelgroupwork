/*
 * List.h
 *
 *  Created on: Apr 13, 2009
 *      Author: reza
 */

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
	List() {
		elements = NULL;
	}

	// constructor with sequence
	List (list<Element*> *s) {
		elements = s;
	}

	virtual string toString() const {
		string s = "(";

        for (list<Element*>::iterator iterator = elements->begin(); iterator != elements->end(); iterator++) {
            s = s + (*iterator)->toString();
            s = s + ",";
        }
        return s;
		return s + ")";
	}

    // What does it mean to evalute a list?
    virtual int eval(map<string,int> NT, map<string,Proc*> FT) const {
        return 0;
    }

    virtual ~List() {
        for (list<Element*>::iterator iterator = elements->begin(); iterator != elements->end(); iterator++) {
            delete (*iterator);
        }
        delete elements;
    }

private:
	list<Element*> *elements;
};
#endif /* LIST_H_ */
