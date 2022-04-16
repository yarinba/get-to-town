#include "AList.h"

AList::AList(unsigned int _size) : headList(-1), tailList(-1), headFree(0), size(_size) {
    list.resize(_size);
    makeEmpty();
}

void AList::makeEmpty() {
    for (int i = 0; i < size - 1; i++) {
        list[i].next = i + 1;
    }
    list[size - 1].next = -1;
}

void AList::insert(int data) {
    int loc = list[headFree].next;
    list[headFree].data = data;

    if (isEmpty())
        headList = headFree;
    else
        list[tailList].next = headFree;

    tailList = headFree;
    list[tailList].next = -1;
    headFree = loc;
}

void AList::print() {
    int i = headList;
    while (i != -1) {
        std::cout << list[i].data << ' ';
        i = list[i].next;
    }
    std::cout << std::endl;
}