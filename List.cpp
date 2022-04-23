#include "List.h"

// Delete node in given index
void List::deleteNode(int nodeOffset)
{
    Node* temp1 = head, * temp2 = NULL;
    int ListLen = 0;

    if (head == NULL) {
        cout << "List empty." << endl;
        return;
    }

    // Find length of the list.
    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }

    // Check if the index to be deleted is less than the length of the list.
    if (ListLen < nodeOffset) {
        cout << "Index out of range" << endl;
        return;
    }

    // Declare temp1
    temp1 = head;

    // Deleting the head.
    if (nodeOffset == 1) {

        // Update head
        head = head->next;
        delete temp1;
        return;
    }

    // Find the node to be deleted.
    while (nodeOffset-- > 1) {

        // Update temp2
        temp2 = temp1;

        // Update temp1
        temp1 = temp1->next;
    }

    // Change the next pointer of the previous node.
    temp2->next = temp1->next;

    // Delete the node
    delete temp1;
}

// Insert a new node to end
void List::insert(int data)
{
    // Create new Node
    Node* newNode = new Node(data);

    // Assign to head
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Traverse till end of list
    Node* temp = head;
    while (temp->next != NULL) {

        // Update temp
        temp = temp->next;
    }

    // Insert at the last.
    temp->next = newNode;
}

// Function to print the nodes of the linked list.
void List::printList()
{
    Node* temp = head;

    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }

    // Traverse the list.
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Function to delete the entire linked list
List::~List() {
    /* deref head_ref to get the real head */
    Node* current = head;
    Node* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }

    /* deref head_ref to affect the real head back in the caller. */
    head = NULL;
}