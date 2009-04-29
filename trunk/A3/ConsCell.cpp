#include<iostream>
#include<vector>
#include "Element.h"
#include "ConsCell.h"
using namespace std;

ConsCell::ConsCell() {
	car = NULL;
	cdr = NULL_POINTER;
	inUse = false;
	mark = 0;
}

ConsCell::ConsCell(Element* aCarPtr, int aCdrPtr) {
    car = aCarPtr;
    cdr = aCdrPtr;
    inUse = true;
		mark = 0;
}
