
#ifndef MEMORY_H
#define MEMORY_H

#define MAX_MEMORY 8
#define NULL_POINTER -1

#include <vector>
#include "ConsCell.h"
using namespace std;

class Memory
{
    public:
        Memory();
        int cons(Element* e, int address);

    private:
        int getAvail();
        void markGarbage();
        vector<ConsCell> heap;
};

#endif
