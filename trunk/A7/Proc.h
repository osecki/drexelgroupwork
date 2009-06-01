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
    
    // Generate code for the function
    void translate(map<int, string> &constantValues, map<string, Proc*> &FT);
    
    void insert(ostream& out) const;
    
    vector<string> getCode();

private:
    StmtList *SL_;
    list<string> *PL_;
    unsigned int NumParam_;
    
    // Code for the proc
    vector<string> ralProgram;
    
    // Local and temporaries for the proc
    map<string, SymbolDetails> symbolTable;
    
    // Convert an address into an actual offset
    string getOffset(const string & name, map<int, string> & constants);
    
    int temps;
    int vars;
    int constants;
    
};

ostream& operator <<(ostream &out, const Proc & p);

#endif
