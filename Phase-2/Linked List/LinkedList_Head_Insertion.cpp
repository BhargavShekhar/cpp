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

void InsertAtHead(Node* &head, int d)
{
    // new node create
    Node* temp = new Node(d);

    // temp pointer will point at head
    temp -> next = head;

    // new head pointer
    head = temp;
}

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
    // created a new node
    Node* node1 = new Node(10);

    // head pointed to node 1
    Node* head = node1;
    cout << "Node: ";
    print(head);

    InsertAtHead(head, 12);
    cout << "Node: ";
    print(head);

    InsertAtHead(head, 15);
    cout << "Node: ";
    print(head);
    
    return 0;
}