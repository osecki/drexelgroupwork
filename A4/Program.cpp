#include <map>
#include <iostream>
#include "Program.h"
#include "Element.h"

Program::Program(StmtList *SL)
{
    NameTable_.clear();
    SL_ = SL;
}

void Program::dump()
{
    cout << "Dump of Symbol Table" << endl;
    for (map<string,Element*>::iterator p = NameTable_.begin();p != NameTable_.end();p++) {
        cout << p->first << " -> " << p->second->toString(NameTable_) << endl;
    }
}

void Program::eval()
{
    SL_->eval(NameTable_);
}
