#pragma once

#include <iostream>

// Array-based list implementation
class AList {
    struct Node {
        int data;
        int next;
    };

    Node* list;
    int headList;
    int headFree;
    unsigned int size;
public:
    AList(unsigned int _size) : headList(-1), headFree(0), size(_size){
        list = new Node[size];
        makeEmpty();
    }

    ~AList() { delete[] list; }

    void makeEmpty() {
        for (int i = 0; i < size - 1; i++) {
            list[i].next = i + 1;
        }
        list[size - 1].next = -1;
    }

    bool isEmpty() { return headList == -1; }

    void insert(int data) {
        if (isEmpty()) {
            int loc = list[headFree].next;
            list[headFree].data = data;
            list[headFree].next = -1;
            headList = headFree;
            headFree = loc;
        }
        else {
            list[headFree].data = data;
            list[headFree].next = headList;
            headFree = list[headFree].next;
        }
    }

    void print() {
        int i = headList;
        while (i != -1) {
            std::cout << list[i].data << ' ';
            i = list[i].next;
        }
        std::cout << std::endl;
    }

    int next(int currIndex) {
        return list[currIndex].next;
    }

    int value(int currIndex) {
        return list[currIndex].data;
    }

    int getHeadListIndex() { return headList;  }
};

