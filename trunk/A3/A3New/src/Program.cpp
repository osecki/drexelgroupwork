#include <map>
#include <iostream>
#include "Program.h"
#include "Element.h"
#include "ConsCell.h"
#include<vector>
#include "Number.h"

Program::Program(StmtList *SL)
{
NameTable_.clear();
FunctionTable_.clear();
SL_ = SL;
// list memory size is 8 and initialized with value 0
//listMemory.resize(8);
avail =0;
}

void Program::dump()
{
	// Changed environment table here
  map<string,Element*>::iterator p;
  map<string,Proc*>::iterator f;

  cout << "Dump of Symbol Table" << endl;
  cout << "Name Table" << endl;
  for (p = NameTable_.begin();p != NameTable_.end();p++)
    cout << p->first << " -> " << p->second->toString() << endl;
  cout << "Function Table" << endl;
  for (f = FunctionTable_.begin();f != FunctionTable_.end();f++)
    cout << f->first << endl;
  cout<<"List memory\n";
  for ( int i=0; i<listMemory.size(); i++) {
	  ConsCell consCell = listMemory[i];
	  Number* carVal = (Number*)consCell.getCarPtr();
	  Number* cdrVal = (Number*)consCell.getCdrPtr();
	  cout<<"ConsCell["<<i<<"] "<<carVal->getValue()<<", "<<cdrVal->getValue()<<endl;
  }
}

void Program::eval()
{
	// change the eval to pass the vector and avail pointer
    SL_->eval(NameTable_, FunctionTable_,listMemory, avail);
}
