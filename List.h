#pragma once

#include <iostream>
using namespace std;

// Node class to represent
// a node of the linked list.
class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Linked list class to
// implement a linked list.
class List {
    Node* head;

public:
    // Default constructor
    List() { head = NULL; }

    Node* getHead() { return head; }

    // Function to insert a
    // node at the end of the
    // linked list.
    void insert(int);

    // Function to print the
    // linked list.
    void printList();

    // Function to delete the
    // node at given position
    void deleteNode(int);
};

