/*
 * List.h
 *
 *  Created on: Apr 13, 2009
 *      Author: reza
 */

#ifndef LIST_H_
#define LIST_H_
#include<iostream>
#include "ListElement.h"
#include "Sequence.h"
using namespace std;
class List : public ListElement{

public:
	// default constructor
	List() {
		elements = NULL;
	}

	// constructor with sequence
	List (Sequence* s) {
		elements = s;
	}

	string toString() {
		string s = "(";
		if (elements != NULL)
			s = s + elements->toString();
		return s + ")";
	}

	void print() {
		cout<<toString()<<endl;
	}
private:
	Sequence* elements;
};
#endif /* LIST_H_ */
