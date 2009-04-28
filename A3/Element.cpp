/**
 * Program:  Element.cpp
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, and Alimoor Reza
 * Class:    CS550, Assignment 2, Spring 2009
**/
#include "Number.h"
#include "Element.h"
#include "ConsCell.h"
#include<vector>

void Element::print() {
    cout<<toString()<<endl;
}

int Element::listp() {
    return 0;
}

int Element::intp() {
    return 0;
}
bool Element::getIntOrPtr() const
{
	return this->intOrPtr;
}

void Element::setIntOrPtr(bool intOrPtr)
{
	this->intOrPtr = intOrPtr;
}
