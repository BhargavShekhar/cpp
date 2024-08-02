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
    Node* temp = new Node(d);

    temp -> next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);

    tail -> next = temp;
    tail = temp;
}

void InsertAtPosition(Node* &head,Node* &tail, int position, int d)
{
    // Insert at Start
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp -> next;
        cnt++;
    }

    // Updating tail if we insert at last position
    if (temp -> next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }
    

    // creating a node for d
    Node* NodeToInsert = new Node(d);

    NodeToInsert -> next = temp -> next;
    temp -> next = NodeToInsert;
    
}

void print(Node* &head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    
}

int main()
{
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    InsertAtTail(tail, 15);
    InsertAtTail(tail, 20);

    InsertAtPosition(head, tail, 4, 12);

    print(head);
    cout << "\nHead is " << head -> data << endl;
    cout << "Tail is " << tail -> data << endl;
    
    return 0;
}