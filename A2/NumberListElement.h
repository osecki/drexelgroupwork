/*
 * NumberListElement.h
 *
 *  Created on: Apr 13, 2009
 *      Author: reza
 */

#ifndef NUMBERLISTELEMENT_H_
#define NUMBERLISTELEMENT_H_
#include "ListElement.h"
#include <sstream>

class NumberListElement : public ListElement {
public:
	NumberListElement(int n) {
		this->n = n;
	}
	string toString() {
        std::stringstream s;
        s << n;
		return s.str();
	}

protected:
	int n;
};

#endif /* NUMBERLISTELEMENT_H_ */
