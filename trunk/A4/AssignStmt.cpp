#include <map>
#include "Proc.h"
#include "AssignStmt.h"

AssignStmt::AssignStmt(string name, Expr *E)
{
  name_ = name;
  E_ = E;
}

// Changed environment table here
void AssignStmt::eval(map<string,Element*> &NT, map<string,Proc*> &FT, Memory &memory) const
{
    #if 0 // This was removed to allow cyclical definitons (like count := count + 1) - Geoff
    // Incase we are over-writing a value, remove the value from the name table
    // so that its memory (if any) will not be protected during garbage collection
    map<string,Element*>::iterator location = NT.find(name_);
    if(location != NT.end()) {
        NT.erase(location);
    }
    #endif

    // Update the name table with the new Element
    NT[name_] = E_->eval(NT,FT,memory);
}
