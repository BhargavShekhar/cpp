#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        // constructor
        Node(int data)
        {
            this -> data = data;
            this -> next = NULL;
        }

        // destructor
        ~Node()
        {
            int value = this -> data;   // no need for this its just for the cout / print statement.
            // memory free
            if (this -> next != NULL)
            {
                delete next;
                this -> next = NULL;
            }

            cout << "Memory is free for node with data: " << value << endl;            
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
    }   cout << endl;
    
}

void deleteNode(Node* &head, int position)
{
    if (position == 1)
    {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }

    else
    {
        Node* current = head;
        Node* previous = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            previous = current;
            current = current -> next;
            cnt++;
        }

        previous -> next = current -> next;
        current -> next = NULL;
        delete current;
        
    }
    
}

int main()
{
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    InsertAtTail(tail, 15);
    InsertAtTail(tail, 20);

    print(head);

    deleteNode(head, 2);

    cout << "head: " << head -> data << endl;
    cout << "tail: " << tail -> data << endl;
    
    return 0;
}