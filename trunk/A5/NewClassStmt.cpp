/**
 *  Program:  NewClassStmt.cpp
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 *  Class:    CS550, Assignment 5, Spring 2009
**/

#include <iostream>
#include <map>
#include "StmtList.h"
#include "Element.h"
#include "NewClass.h"
#include "NewClassStmt.h"

using namespace std;

NewClassStmt::NewClassStmt(NewClass* NC) {
	this->NC_ = NC;
}
NewClassStmt::~NewClassStmt(){
	delete NC_;
}
void NewClassStmt::eval(map<string, Element*> &NT) const {
	this->NC_->eval(NT);
}
