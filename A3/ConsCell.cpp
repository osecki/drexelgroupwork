#include<iostream>
#include<vector>
#include "Element.h"
#include "ConsCell.h"
using namespace std;

ConsCell::ConsCell() {
	this->carPtr = NULL;
	this->cdrPtr = NULL;
	this->marked = false;
	//this->intOrPtr = false;
}

ConsCell::ConsCell(Element* aCarPtr, Element* aCdrPtr) {
	this->carPtr = aCarPtr;
	this->cdrPtr = aCdrPtr;
	this->marked = false;
	//this->intOrPtr = false;
}

Element* ConsCell::getCarPtr() const
{
	return this->carPtr;
}

void ConsCell::setCarPtr(Element *carPtr)
{
	this->carPtr = carPtr;
}

Element* ConsCell::getCdrPtr() const
{
	return this->cdrPtr;
}

void ConsCell::setCdrPtr(Element *cdrPtr)
{
	this->cdrPtr = cdrPtr;
}

bool ConsCell::getMarked() const
{
	return this->marked;
}

void ConsCell::setMarked(bool marked)
{
	this->marked = marked;
}

/*bool ConsCell::getIntOrPtr() const
{
	return this->intOrPtr;
}

void ConsCell::	setIntOrPtr(bool intOrPtr)
{
	this->intOrPtr = intOrPtr;
}
*/
