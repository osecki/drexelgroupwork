/**
 * Program:  NewClassStmt.h
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 * Class:    CS550, Assignment 5, Spring 2009
**/

#ifndef NEWCLASSSTMT_H
#define NEWCLASSSTMT_H

#include <iostream>
#include <map>
#include "StmtList.h"
#include "Element.h"
#include "NewClass.h"

using namespace std;

class NewClassStmt : public Stmt {

public:
    NewClassStmt(NewClass* NC_);
    ~NewClassStmt();
    void eval(map<string,Element*> &NT) const;
private:
	NewClass* NC_;
};

#endif
