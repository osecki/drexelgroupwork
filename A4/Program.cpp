#include <map>
#include <iostream>
#include <iomanip>
#include "Program.h"
#include "Element.h"

Program::Program(StmtList *SL)
{
    NameTable_.clear();
    SL_ = SL;
}

void Program::dump()
{
	cout << endl << endl;
	cout << setw(20) << right << "Symbol" << " | " << left << "Value" << endl;
	cout << setfill('-') << setw(22) << right << "+" << setw(20) << "-" << setfill(' ') << endl;
    for (map<string,Element*>::iterator p = NameTable_.begin(); p != NameTable_.end(); p++) {
        cout << setw(20) << right << p->first << " | " << left << p->second->toString(NameTable_) << endl;
    }
}

void Program::eval()
{
    SL_->eval(NameTable_);
}
