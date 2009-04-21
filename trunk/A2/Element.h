/**
 *  Program:  Element.h
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, and Alimoor Reza
 *  Class:    CS550, Assignment 2, Spring 2009
**/

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

