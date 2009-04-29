#ifndef CONSCELL_H
#define CONSCELL_H
#include<iostream>
#include <map>
#include <string>

#include<vector>

using namespace std;

class Element;

class ConsCell{

public:
	ConsCell();
    ConsCell(Element*, int);

	Element* car;
	int cdr;
	bool inUse;

};

#endif