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
    ConsCell(Element*, Element*);

	Element* car;
	Element* cdr;
	bool inUse;

};

#endif
