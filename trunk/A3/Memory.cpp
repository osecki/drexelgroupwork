
#include "Memory.h"

Memory::Memory() {
    heap.resize(MAX_MEMORY);
}

int Memory::getAvail() {
    return -1;
}

void Memory::markGarbage() {
}

int Memory::cons(Element* e, int address) {
    return -1;
}

/*


int Program::getAvail() {
    // Do garbage management whatever, fond a spot or freak out
    for(bool mark = true; mark; mark = !mark) {
        for(int index = 0; index < memory.size(); index++) {
            if(!memory[index].inUse) {
                return index;
            }
        }
        if(mark) {
            markGarbage();
        }
    }
    return -1;
}

void Program::markGarbage() {
    // TODO Implement me
    // Iterate through nameTable marke accessible entries
}

*/
