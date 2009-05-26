#include "Ident.h"
#include <map>

Ident::Ident(string name)
{
    name_ = name;
}

int Ident::eval(map<string,int> T) const
{	
	return T[name_];
}
