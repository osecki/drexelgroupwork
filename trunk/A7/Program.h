#ifndef PROGRAM_H
#define PROGRAM_H

#include <map>
#include <string>
#include <vector>
#include "StmtList.h"
using namespace std;

class Proc;
class FunCall;
class DefineStmt;

class Program
{
public:
    Program(StmtList *SL);
    Program(){};
		//~Program() {delete SL_; };
    void dump();
    //void eval();
    void translate();
		void optimize();
		void fixLabels();
		void link();
		void compile();

    static int constantCounter;
    static int temporaryVarCounter;
    static int labelCounter;
private:
    StmtList *SL_;
    map<int, string> constantValues;
    map<string, SymbolDetails> symbolTable;
    vector<string> ralProgram;
    Proc* p;
    FunCall* f;
    DefineStmt* d;
    map<string, Proc*> FT;
};

#endif
