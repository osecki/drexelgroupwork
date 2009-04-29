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
						
						// Print out Name table after current statement
						map<string,Element*>::iterator p;
						cout << "Name Table" << endl;
						cout << right << setw(10) << "Name" << setw(14) << "Value" << setw(14) << "List Value" << endl;
					  for (p = NT.begin();p != NT.end();p++) {
								cout << setw(10) << p->first;
								if(p->second->listp()) {
										cout << setw(13) <<  p->second->getAddress() << setw(1) << "*";
								}
										cout << setw(14) << p->second->toString(memory) << endl;
						}
        }
    }
}
