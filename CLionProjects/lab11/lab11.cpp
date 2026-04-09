// Name: Tristen Williams
// File Name: lab11.cpp
// Date: 8 April 2026
// This program peforms different operations on a linked list

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void display(Node*);
Node* deleteFirst(Node*);
Node* deleteLast(Node*);
void destroy(Node* &);

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    // exercise 1
    // build a linked list containing the integers 1-10
    // build the list by repeatedly inserting at the end
for (int  i =1; i<=10; i++) {
    Node* pnew = new Node();
    pnew->data = i;
    pnew->next = NULL;
    if (head == NULL) {
        head = pnew;
        tail = pnew;
    }
    else
        tail->next = pnew;
    tail = pnew;
}
    cout << " The original list: ";
    display(head);

    head = deleteFirst(head);
    cout << " The list after deleting the first node: ";
    display(head);

    head = deleteLast(head);
    cout << " The list after deleting the last node: ";
    display(head);

    destroy(head);
    cout << " The list after deleting all nodes: ";
    display(head);

    return 0;
}

// exercise 2
// display the list recursively in comma separated format
// if the list is empty, display "empty"

void display(Node* h)
{
    if (h == NULL) {
        cout << "The list is empty.";
        return;
    }
    if (h->next == NULL) {
        cout << h->data << endl;
    }
    else {
        cout << h->data << "," ;
        display(h->next);
    }
}

// exercise 3
// delete the first node and return the adjusted head pointer
Node* deleteFirst(Node* h) {
    if (h == NULL) {
        return NULL;
    }
        Node* tmp = h;
        h = h->next;
        delete tmp;
        return h;
    }



    // exercise 4
    // delete the last node and return the head pointer
    // if you are deleting the only remaining node, return NULL
    Node* deleteLast(Node* h) {
        if (h == NULL) {
            return NULL;

        }
        Node* walker = NULL;
         walker = h;
    while (walker->next->next != NULL) {
        walker = walker->next;
    }
    delete walker->next;
    walker->next = NULL;
    return h;
    }


// exercise 5
// destroy the list recursively by repeatedly deleting the first node
void destroy(Node* &h)
{
if (h == NULL) {
    return;
}
    h = deleteFirst(h);
    destroy(h);

}