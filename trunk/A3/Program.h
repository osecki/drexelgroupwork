#ifndef PROGRAM_H
#define PROGRAM_H

#include <map>
#include <vector>
#include <string>
#include "StmtList.h"
#include "ConsCell.h"

#define MAX_MEMORY 8

using namespace std;


// TODO Maybe make a parameter to eval
static vector<ConsCell> memory;


class Program
{
public:
    Program(StmtList *SL);
    ~Program() {delete SL_; };
    void dump();
    void eval();

    Element* cons(Element* e, int address);

private:

    int getAvail();
    void markGarbage();

    StmtList *SL_;
		// Changed the environmental table in order to bind to Element* rather
		// than int
    map<string, Element*> NameTable_;
    map<string, Proc*> FunctionTable_;
};

#endif
