#include <map>
#include <iostream>
#include "Program.h"
#include "Element.h"



Program::Program(StmtList *SL)
{
    NameTable_.clear();
    FunctionTable_.clear();
    SL_ = SL;
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
}

void Program::eval()
{
    SL_->eval(NameTable_, FunctionTable_, memory);
}



