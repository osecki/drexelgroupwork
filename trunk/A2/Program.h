#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <map>
#include <string>
#include "StmtList.h"

using namespace std;

class Program
{
public:
    Program(StmtList *SL)
    {
        NameTable_.clear();
        FunctionTable_.clear();
        SL_ = SL;
    }

    ~Program() {delete SL_; }

    void dump()
    {
        map<string,int>::iterator p;
        map<string,Proc*>::iterator f;

        cout << "Dump of Symbol Table" << endl;
        cout << "Name Table" << endl;
        for (p = NameTable_.begin();p != NameTable_.end();p++)
            cout << p->first << " -> " << p->second << endl;
        cout << "Function Table" << endl;
        for (f = FunctionTable_.begin();f != FunctionTable_.end();f++)
        cout << f->first << endl;
    }

    void eval()
    {
	  SL_->eval(NameTable_, FunctionTable_);
    }

private:
    StmtList *SL_;
    map<string,int> NameTable_;
    map<string,Proc*> FunctionTable_;
};

#endif

