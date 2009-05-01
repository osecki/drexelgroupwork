#include "Ident.h"
#include "Proc.h"
#include <map>

Ident::Ident(string name)
{
    name_ = name;
}

// Changed environment table here
Element* Ident::eval(map<string,Element*> NT, map<string,Proc*> FT, Memory &memory) const
{
    return NT[name_];
}
