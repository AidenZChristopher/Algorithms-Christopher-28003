#ifndef DOUBLYLINKEDLIST_CPP
#define DOUBLYLINKEDLIST_CPP

#include "doublylinkedlist.h"
DoublyLinkedList::DoublyLinkedList()
{
    head = NULL;
    tail = NULL;
}
DoublyLinkedList::~DoublyLinkedList()
{
}
void DoublyLinkedList::addNewNodeToFront(Node * newNode) {
    if(head == NULL && tail == NULL) {
            head = tail = newNode;
    } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
    }
}
void DoublyLinkedList::addNewNodeToBack(Node * newNode) {
    if(head == NULL && tail == NULL) {
            head = tail = newNode;
    } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
    }
}

Node* DoublyLinkedList::removeNodeFromFront()
{
        Node *tempNode;
        tempNode = head;
        head = head->next;
        return tempNode;
}
void DoublyLinkedList::displayDoublyLinkedList()
{
        Node *tempNode;
        tempNode = head;
        while (tempNode != NULL)
    {
        cout << tempNode->value << " " << endl;
        tempNode = tempNode->next; 
    }
}
void DoublyLinkedList::drawDoublyLinkedList(){
    Node* temp= head;
    while (temp != nullptr)
    {
        cout << "Address: " << temp << 
                " Prev: " << temp->prev << 
                " Value: " << temp->value << 
                " Next: " << temp->next << endl;
        temp = temp->next;
    }
}

bool DoublyLinkedList::isPalindrome()
{
    // Empty list or single node check
    if (head == NULL || head == tail)
        return true;

    Node* left = head;
    Node* right = tail;

    while (left != right && right->next != left)
    {
        //Compare values at left and right pointers
        if (left->value != right->value)
            return false;

        // Move Pointers towards the center
        left = left->next;
        right = right->prev;
    }

    //Check Middle Node
    return (left->value == right->value);
}

void DoublyLinkedList::split(int n)
{
    //Get size of list
    int size = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    
    //Validation Check
    if (n == 1 || n > size || size % n != 0 || n < 1)
    {
        cout << "cannot be processed." << endl;
        return;
    }

    cout << n << " evenly split sub doubly linked lists." << endl;

    int subSize = size / n;
    Node* current = head;

    for (int i = 0; i < n; i++)
    {
        DoublyLinkedList subList;
        subList.head = current;

        //Find tail of the sub-list
        for (int j = 0; j < subSize - 1; j++)
        {
            current = current->next;
        }

        subList.tail = current;
        // Save start of next sub-list
        Node* nextStart = current->next;  

        //Break the link
        current->next = NULL;
        if (nextStart != NULL)
            nextStart->prev = NULL;

        // Print the sub-list
        Node* printNode = subList.head;
        while (printNode != NULL) 
        {
            //print value of current node
            cout << printNode->value;
            //prints space if next value is empty
            if (printNode->next != NULL)
                cout << " ";
            //move to next node
            printNode = printNode->next;
        }
        cout << endl;

        //move to start of next sub-list
        current = nextStart; 
    }
}

void DoublyLinkedList::addNewNodeBeforeTargetNode(Node* newNode, int val)
{
    // Empty list — nothing to insert before
    if (head == NULL)
        return;

    Node* temp = head;

    // Search for the target node containing val
    while (temp != NULL)
    {
        if (temp->value == val)
        {
            // Checks if target is head
            if (temp == head)
            {
                newNode->next = head;
                newNode->prev = NULL;
                head->prev = newNode;
                head = newNode;
            }
            else // Case if target is in middle or end
            {
                newNode->prev = temp->prev;   
                newNode->next = temp;         
                temp->prev->next = newNode;   
                temp->prev = newNode;         
            }
            return;
        }
        temp = temp->next; // check next node
    }
}
#endif