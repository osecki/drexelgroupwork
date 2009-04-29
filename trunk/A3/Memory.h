
#ifndef MEMORY_H
#define MEMORY_H

#define MAX_MEMORY 8
#define NULL_POINTER -1

#include <vector>
#include "ConsCell.h"
using namespace std;

class Element;

class Memory
{
    public:
        Memory();
        int cons(Element* e, int address, map<string,Element*> NT);
        ConsCell & operator[](int index);


    private:
        int getAvail(map<string,Element*> NT);
        void markGarbage(map<string,Element*> NT);
        vector<ConsCell> heap;
};


#endif
