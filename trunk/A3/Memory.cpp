#include "Memory.h"
#include "Element.h"
#include "List.h"
#include "Number.h"
#include <iostream>

using namespace std;

Memory::Memory() {
    heap.resize(MAX_MEMORY);
}

int Memory::getAvail(map<string,Element*> NT) {
    for(bool doMark = true; doMark; doMark = !doMark) {
        for(int index = 0; index < MAX_MEMORY; index++) {
            if(!heap[index].inUse) {
                return index;
            }
        }
        if(doMark) {
            markGarbage(NT);
        }
    }
    return -1;
}

void Memory::markGarbage(map<string,Element*> NT) {
/*   	// Iterate name table, if list, mark Concells it reaches
		map<string,Element*>::iterator p;
		for (p = NT_.begin();p != NT_.end();p++) {
			  Element* tempElem = ((Element*)p->second);
				if ( tempElem->listp() ) {
						// Mark main ConsCell
						heap[tempElem->getAddress()].mark = 1;

						// Mark down car path

						// Mark down cdr path
				}
		}

		// Iterate memory table, if unmarked, inUse = false
		for(int index = 0; index < MAX_MEMORY; index++) {
				if ( ! heap[index].mark )
					inUse = false;

				// Unmark all in table
				heap[index].mark = 0;
		}*/
}

int Memory::cons(Element* e, int address, map<string,Element*> NT) {
    int newAddress = getAvail(NT);
    if(newAddress < 0) {
        std::cout<<"No more memory"<<std::endl;
        exit(1);
    }

    heap[newAddress].car = e;
    heap[newAddress].cdr = address;
    heap[newAddress].inUse = true;

    return newAddress;
}

ConsCell & Memory::operator[](int index) {
    return heap[index];
}

ConsCell Memory::operator[](int index) const {
    return heap[index];
}

void Memory::output() const {
    int index = 0;
    for(vector<ConsCell>::const_iterator iter = heap.begin(); iter != heap.end(); iter++) {
        ConsCell cell = *iter;
        cout << index++ << "\t";
        if(cell.car == NULL) {
            cout << "X\t";
        } else if(cell.car->listp()) {
            cout << "L\t" << ((List*)cell.car)->getAddress();
        } else {
            cout << "N\t" << ((Number*)cell.car)->getValue();
        }
        cout << "\t" << cell.cdr << "\t" << (cell.inUse ? "T" : "F") << endl;
    }
}

