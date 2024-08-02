#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

    // Constructor
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

void print(Node* &head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }   cout << endl;
    
}

int main()
{
    // created a new node object
    Node* node1 = new Node(10);   // in Heap / Dynamic allocation.
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;

    
    return 0;
}