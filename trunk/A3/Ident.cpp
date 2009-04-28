#include "Ident.h"
#include "Proc.h"
#include <map>
#include "ConsCell.h"
#include<vector>


Ident::Ident(string name)
{
    name_ = name;
}

// Changed environment table here
Element* Ident:: eval(map<string,Element*> &NT, map<string,Proc*> &FT,vector<ConsCell> &listMemory, int &avail)const
{
    return NT[name_];
}
