#include "Ident.h"
#include "Proc.h"
#include <map>

Ident::Ident(string name)
{
    name_ = name;
}

int Ident::eval(map<string,int> NT, map<string,Proc*> FT) const
{
    return NT[name_];
}
