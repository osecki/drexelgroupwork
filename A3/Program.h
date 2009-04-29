#ifndef PROGRAM_H
#define PROGRAM_H

#include <map>
#include <vector>
#include <string>
#include "StmtList.h"
#include "ConsCell.h"
#include "Memory.h"

// An invalid variable name to use to protect ConsCells as they are created
#define TEMP_NAME string("!R*@^$@!(*$^")
#define DEBUG true

using namespace std;

class Program
{
public:
    Program(StmtList *SL);
    ~Program();
    void dump();
    void eval();

private:
    StmtList *SL_;
    Memory memory;
    map<string, Element*> NameTable_;
    map<string, Proc*> FunctionTable_;
};

#endif
