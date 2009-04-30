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
    SL_->dumpNameTable(NameTable_, memory);
    cout << "Function Table" << endl;
    for (map<string, Proc*>::iterator f = FunctionTable_.begin();f != FunctionTable_.end();f++)
        cout << f->first << endl;
}

void Program::eval()
{
    SL_->eval(NameTable_, FunctionTable_, memory);
}

