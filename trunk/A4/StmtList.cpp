#include "StmtList.h"
#include "Stmt.h"
#include "Program.h"
#include "Element.h"
#include <map>
#include <iomanip>

void StmtList::insert(Stmt * S)
{
  SL_.push_front(S);
}

// Changed environment table here
void StmtList::eval(map<string,Element*> &NT, map<string,Proc*> &FT, Memory &memory)
{
    list<Stmt*>::iterator Sp;
    int statement = 1;
    for (Sp = SL_.begin();Sp != SL_.end();Sp++) {
        (*Sp)->eval(NT,FT,memory);
        if(DEBUG) {
					  // Print out Memory table after current statement
            cout << "Memory table after statement " << statement++ << endl;
            memory.output();

            dumpNameTable(NT, memory);
        }
    }
}

void StmtList::dumpNameTable(map<string,Element*> &NameTable_, Memory &memory) {
    cout << "Name Table" << endl;
    cout << right << setw(10) << "Name" << setw(10) << "Value" << setw(10) << "    List Value" << endl;
    for (map<string,Element*>::iterator p = NameTable_.begin();p != NameTable_.end();p++) {
        cout << setw(10) << p->first << setw(10) << right;
        if(p->second->listp()) {
            cout << setw(10) << right << p->second->getAddress() << setw(4) << left << "*" << setw(31) << left;
        }
        cout << p->second->toString(memory) << endl << right;
    }
}
