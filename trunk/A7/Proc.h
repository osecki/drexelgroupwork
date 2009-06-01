#ifndef PROC_H
#define PROC_H

#include <map>
#include <string>
#include "StmtList.h"
using namespace std;

class Expr;

class Proc
{
public:
    Proc(list<string> *PL, StmtList *SL);
    ~Proc() {delete SL_; };
    int apply(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram, map<string, Proc*> &ralProgramFT);
    string translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram, map<string, Proc*> &ralProgramFT);
    void link(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram, map<string, Proc*> &ralProgramFT);
private:
    StmtList *SL_;
    list<string> *PL_;
    unsigned int NumParam_;
};

#endif
