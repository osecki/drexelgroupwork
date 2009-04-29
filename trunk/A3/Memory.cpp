#include "Memory.h"
#include "Element.h"
#include "List.h"
#include "Number.h"
#include <iostream>

using namespace std;

Memory::Memory() {
    heap.resize(MAX_MEMORY);
}

// Returns the next available index in the heap
int Memory::getAvail(map<string,Element*> NT) {
    for(int doMark = 0; doMark <= 1; doMark++) {
        for(int index = 0; index < MAX_MEMORY; index++) {
            if(!heap[index].inUse) {
                return index;
            }
        }
        if(0 == doMark) {
            markGarbage(NT);
        }
    }
    return -1;
}

void Memory::markGarbage(map<string,Element*> NT) {
    cerr << "Performing garbage collection"<<endl;
    // Set all memory elements to be not-in use
    for(vector<ConsCell>::iterator iter = heap.begin(); iter != heap.end(); iter++) {
        iter->inUse = false;
    }

    // Recursively mark each value in the name tabe
    for(map<string,Element*>::iterator iter = NT.begin(); iter!= NT.end(); iter++){
        if(iter->second == NULL) {
            // .... Why would there be a null entry? I'm not clear on this (GAO)
        } else {
            inUse(iter->second);
        }
    }
    output();
}

// Sets a memory address (assumed to be a list) as in-use
void Memory::inUse(int address, bool isNumber) {
    if(address != NULL_POINTER) {
        heap[address].inUse = true;
        if(!isNumber) {
            inUse(heap[address].car);
        }
        inUse(heap[address].cdr);
    }
}

// Sets an element to be in use
void Memory::inUse(Element* e) {
    int address = e->getAddress();
    inUse(address, e->intp());
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

// Dumps the memory table to standard out
void Memory::output() const {
    int index = 0;
    cout << "index\tcar\tcdr\tinUse"<<endl;
    for(vector<ConsCell>::const_iterator iter = heap.begin(); iter != heap.end(); iter++) {
        ConsCell cell = *iter;
        cout << index++ << "\t";
        if(cell.car == NULL) {
            cout << "X";
        } else if(cell.car->listp()) {
            cout << ((List*)cell.car)->getAddress() << "*";
        } else {
            cout << ((Number*)cell.car)->getValue();
        }
        cout << "\t" << cell.cdr << "*\t" << (cell.inUse ? "T" : "F") << endl;
    }
}

