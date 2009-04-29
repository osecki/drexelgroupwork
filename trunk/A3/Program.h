#ifndef PROGRAM_H
#define PROGRAM_H

#include <map>
#include <vector>
#include <string>
#include "StmtList.h"
#include "ConsCell.h"
#include "Memory.h"


#define TEMP_NAME string("!R*@^$@!(*$^")


using namespace std;


// TODO Maybe make a parameter to eval



class Program
{
public:
    Program(StmtList *SL);
    ~Program() {delete SL_; };
    void dump();
    void eval();



private:



    Memory memory;
    StmtList *SL_;
		// Changed the environmental table in order to bind to Element* rather
		// than int
    map<string, Element*> NameTable_;
    map<string, Proc*> FunctionTable_;
};

#endif
