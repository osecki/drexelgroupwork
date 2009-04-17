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
    int apply(map<string,int> &NT, map<string,Proc*> &FT, list<Expr*> *EL);
private:
    StmtList *SL_;
    list<string> *PL_;
    int NumParam_;
};


#endif
