#include "Ident.h"
#include "Proc.h"
#include <map>

Ident::Ident(string name)
{
    name_ = name;
}

// Changed environment table here
Element* Ident::eval(map<string,Element*> &NT) const
{	
	map<string,Element*>::iterator location = NT.find(name_);
	if(NT.end() != location) {
		if(NULL == NT[name_]) {
			// Should never happen, but is useful for debugging
			cerr << "ERROR: " << name_ << " was found, but is NULL pointer" << endl;
			exit(1); 
		}		
    	return NT[name_];
	} else {
		cout << "ERROR: No such variable '" << name_ << "'" << endl;
		exit(1);
	}
}
