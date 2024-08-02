#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        // contructor
        Node(int data)
        {
            this -> data = data;
            this -> next = NULL;
        }
};

void InsertionAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
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
    // Created a new Node
    Node* node1 = new Node(10);

    // Tail Pointed at node1
    Node* head = node1;
    Node* tail = node1;
    print(head);

    InsertionAtTail(tail, 12);
    print(head);

    InsertionAtTail(tail, 15);
    print(head);
    
    return 0;
}