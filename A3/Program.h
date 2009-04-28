#ifndef PROGRAM_H
#define PROGRAM_H

#include <map>
#include <string>
#include<vector>
#include "StmtList.h"
#include "ConsCell.h"

using namespace std;

class Program
{
public:
    Program(StmtList *SL);
    ~Program() {delete SL_; };
    void dump();
    void eval();

private:
    StmtList *SL_;
		// Changed the environmental table in order to bind to Element* rather
		// than int
    map<string, Element*> NameTable_;
    map<string, Proc*> FunctionTable_;
    // vector of cons cells in order to corporate dynamic list and garbage collection
    vector<ConsCell> listMemory;
    // available pointer
    int avail;
    static const int SIZEOFMEMORY = 8;
};

#endif
