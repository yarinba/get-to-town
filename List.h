#pragma once

#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    // Constructors
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Linked list class
class List {
    Node* head;

public:
    // Constructor
    List() { head = NULL; }

    Node* getHead() { return head; }

    // Insert node to end of list
    void insert(int);

    // Print the list
    void printList();

    // Delete node in given index
    void deleteNode(int);
};

