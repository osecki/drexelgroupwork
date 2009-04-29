#include<iostream>
#include<vector>
#include "Element.h"
#include "ConsCell.h"
using namespace std;

ConsCell::ConsCell() {
	car = NULL;
	cdr = NULL;
	inUse = false;
}

ConsCell::ConsCell(Element* aCarPtr, Element* aCdrPtr) {
    car = aCarPtr;
    cdr = aCdrPtr;
    inUse = true;
}
