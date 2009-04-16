/*
 * ListListElement.h
 *
 *  Created on: Apr 13, 2009
 *      Author: reza
 */

#ifndef LISTLISTELEMENT_H_
#define LISTLISTELEMENT_H_
#include "ListElement.h"
class ListListElement : public ListElement {
public:
	ListListElement() {
        l = new List;
	}

	ListListElement(List* l) {
		this->l = l;
	}

	string toString() {
		return l->toString();
	}
private:
	List* l;
};

#endif /* LISTLISTELEMENT_H_ */
