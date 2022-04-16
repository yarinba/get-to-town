#pragma once

#include <iostream>
#include <vector>
using std::vector;

// Array-based list implementation
class AList {
    struct ANode {
        int data;
        int next;
    };
    
    vector<ANode> list;
    int headList;
    int tailList;
    int headFree;
    unsigned int size;

public:
    AList(unsigned int _size);

    ~AList() { }

    bool isEmpty() { return headList == -1; }

    int next(int currIndex) { return list[currIndex].next; }

    int value(int currIndex) { return list[currIndex].data; }

    int getHeadListIndex() { return headList; }

    void makeEmpty();

    void insert(int data);

    void print();
};

