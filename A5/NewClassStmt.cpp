#include <iostream>
#include <map>
#include "StmtList.h"
#include "Element.h"
#include "NewClass.h"
#include "NewClassStmt.h"

using namespace std;

NewClassStmt::NewClassStmt(NewClass* NC) {
	this->NC_ = NC;
	cout<<"NewClassStmt constructor\n";
}
NewClassStmt::~NewClassStmt(){
	delete NC_;
}
void NewClassStmt::eval(map<string, Element*> &NT) const {
	this->NC_->eval(NT);
}
