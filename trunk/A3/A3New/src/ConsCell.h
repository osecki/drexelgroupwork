#ifndef CONSCELL_H
#define CONSCELL_H
#include<iostream>
#include <map>
#include <string>
#include "Element.h"

#include<vector>

using namespace std;

class Element;

class ConsCell{

public:
	ConsCell();
	ConsCell(Element* aCarPtr, Element* aCdrPtr);
	Element* getCarPtr() const;

	void setCarPtr(Element *carPtr);

	Element* getCdrPtr() const;

	void setCdrPtr(Element *cdrPtr);

	bool getMarked() const;

	void setMarked(bool marked);

	//bool getIntOrPtr() const;

	//void setIntOrPtr(bool intOrPtr);

//private:
	Element* carPtr;
	Element* cdrPtr;
	bool marked;
	//bool intOrPtr;

};

#endif
