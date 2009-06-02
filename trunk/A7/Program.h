#ifndef PROGRAM_H
#define PROGRAM_H

#include <map>
#include <string>
#include <vector>
#include "StmtList.h"
using namespace std;

#define FP string("FP")
#define TEMP string("TEMP")
#define FPB string("FPB")
#define NEXT_FP string("NEXT_FP")
#define LINE string("ROW")

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
    void dumpCode(ostream& out);
    void dumpMemory(ostream& out);
    
    void translate();
	void fixLabels();
	void link();
	void compile();

    static int constantCounter;
    static int temporaryVarCounter;
    static int labelCounter;
private:
    StmtList *SL_;
    map<string, SymbolDetails> constAddresses;
    map<int, string> constantValues;
    vector<string> ralProgram;
    Proc* p;
    FunCall* f;
    DefineStmt* d;
    map<string, Proc*> FT;
};

#endif
