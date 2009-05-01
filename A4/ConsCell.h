/**
 *  Program:  ConsCell.h
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, Alimoor Reza
 *  Class:  CS550, Assignment 3, Spring 2009
**/

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

    Element* car;
    int cdr;
    bool inUse;
};

#endif
