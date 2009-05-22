#include "Ident.h"
#include <map>

Ident::Ident(string name)
{
    name_ = name;
}

int Ident::eval(map<string,int> NT) const
{	
	return NT[name_];
}
