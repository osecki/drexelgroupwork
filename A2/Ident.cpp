#include "Ident.h"
#include "Proc.h"
#include <map>

Ident::Ident(string name)
{
    name_ = name;
}

Element* Ident::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
    return NT[name_];
}
