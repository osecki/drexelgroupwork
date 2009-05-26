#ifndef PROGRAM_H
#define PROGRAM_H

#include <map>
#include <string>
#include "StmtList.h"
using namespace std;

class Program
{
public:
    Program(StmtList *SL);
    Program(){};
		//~Program() {delete SL_; };
    void dump();
    //void eval();
    void translate();

    static int constantCounter;
    static int temporaryVarCounter;
    static int labelCounter;

private:
    StmtList *SL_;
    //map<string, int> SymbolTable_;
    map<int, string> constantValues;
    map<string, SymbolDetails> symbolTable;
};

#endif
