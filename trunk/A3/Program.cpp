#include <map>
#include <iostream>
#include <iomanip>
#include "Program.h"
#include "Element.h"

Program::~Program() {
    delete SL_;
}

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
    cout << right << setw(10) << "Name" << setw(14) << "Value" << setw(14) << "List Value" << endl;
    for (p = NameTable_.begin();p != NameTable_.end();p++) {
        cout << setw(10) << p->first;
        if(p->second->listp()) {
            cout << setw(13) <<  p->second->getAddress() << setw(1) << "*";
        }
        cout << setw(14) << p->second->toString(memory) << endl;
    }
    cout << "Function Table" << endl;
    for (f = FunctionTable_.begin();f != FunctionTable_.end();f++)
        cout << f->first << endl;
}

void Program::eval()
{
    SL_->eval(NameTable_, FunctionTable_, memory);
}

