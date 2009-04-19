/*
 * ListElement.h
 *
 *  Created on: Apr 13, 2009
 *      Author: reza
 */

#ifndef ELEMENT_H
#define ELEMENT_H

#include "Expr.h"
#include<iostream>
using namespace std;

class Element : public Expr {
public:
	virtual string toString() const = 0;
	void print();
};


#endif

