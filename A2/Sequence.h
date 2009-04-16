/*
 * Sequence.h
 *
 *  Created on: Apr 13, 2009
 *      Author: reza
 */

#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include<iostream>
#include<vector>
using namespace std;
#include "ListElement.h"

class Sequence {

public:

    // (GAO) I don't think having this constructor makes sense
    Sequence() {
    }

	Sequence(ListElement* e) {
		elements.insert(elements.begin(), e);
	}

	string toString() {
        string s = "";

        for (vector<ListElement*>::iterator iterator = elements.begin(); iterator != elements.end(); iterator++) {
            s = s + (*iterator)->toString();
            s = s + ",";
        }
        return s;
    }

private:
	vector<ListElement*> elements;

};
#endif /* SEQUENCE_H_ */
