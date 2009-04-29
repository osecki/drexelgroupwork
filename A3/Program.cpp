#include <map>
#include <iostream>
#include "Program.h"
#include "Element.h"



Program::Program(StmtList *SL)
{
    NameTable_.clear();
    FunctionTable_.clear();
    memory.clear();
    memory.resize(MAX_MEMORY);
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
    SL_->eval(NameTable_, FunctionTable_);
}



int Program::getAvail() {
    // Do garbage management whatever, fond a spot or freak out
    for(bool mark = true; mark; mark = !mark) {
        for(int index = 0; index < memory.size(); index++) {
            if(!memory[index].inUse) {
                return index;
            }
        }
        if(mark) {
            markGarbage();
        }
    }
    return -1;
}

void Program::markGarbage() {
    // TODO Implement me
    // Iterate through nameTable marke accessible entries
}
