/**
 * Program:  Element.cpp
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, and Alimoor Reza
 * Class:    CS550, Assignment 2, Spring 2009
**/
#include "Number.h"
#include "Element.h"

void Element::print(const Memory &memory) {
    cout<<toString(memory)<<endl;
}

int Element::listp() {
    return 0;
}

int Element::intp() {
    return 0;
}
