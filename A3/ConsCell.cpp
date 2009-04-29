/**
 *  Program:  ConsCell.cpp
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, Alimoor Reza
 *  Class:  CS550, Assignment 3, Spring 2009
**/

#include<iostream>
#include<vector>
#include "Element.h"
#include "ConsCell.h"
using namespace std;

ConsCell::ConsCell() {
	car = NULL;
	cdr = NULL_POINTER;
	inUse = false;
}

ConsCell::ConsCell(Element* aCarPtr, int aCdrPtr) {
    car = aCarPtr;
    cdr = aCdrPtr;
    inUse = true;
}
