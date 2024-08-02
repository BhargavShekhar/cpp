#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* prev;
        Node* next;

        // Constructor
        Node(int data)
        {
            this -> data = data;
            this -> next = NULL;
            this -> prev = NULL;
        }

        // Deconstructor
        ~Node()
        {
            // Just to show value
            int value = this -> data;

            if (this -> next != NULL)
            {
                delete next;
                this -> next = NULL;
            }

            cout << "Memory free for load with data " << value <<endl;
            
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

int getLength(Node* &head)
{
    Node* temp = head;
    int cnt = 0;

    while (temp != NULL)
    {
        cnt++;
        temp = temp -> next;
    }

    return cnt;
}

void InsertAtHead(Node* &head, Node* &tail, int d)
{
    // If empty List
    if (head == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }

    else
    {
        Node* temp = new Node(d);

        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
        
}

void InserAtTail(Node* &head, Node* &tail, int d)
{
    // cout << "tail: " << tail << endl;

    if (tail == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }

    else
    {
        Node* temp = new Node(d);

        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
    
}

void InsertAtPosition(Node* &head, Node* &tail, int position, int d)
{
    // Insertion if position == head
    if (position == 1)
    {
        InsertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp -> next;
        cnt++;
    }

    // Insertion if position == tail
    if (temp -> next == NULL)
    {
        InserAtTail(head, tail, d);
        return;
    }
    
    // Insertion if position is in between
    Node* NodeToInsert = new Node(d);

    NodeToInsert -> next = temp -> next;
    temp -> next -> prev = NodeToInsert;
    temp -> next = NodeToInsert;
    NodeToInsert -> prev = temp;
    
}

void deleteNode(Node* &head, int position)
{
    // deletion of starting Node
    if (position == 1)
    {
        Node* temp = head;
        
        head = head -> next;
        temp -> next = NULL;
        head -> prev = NULL;    // lecture code => temp -> next -> prev = NULL;

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
        current -> prev = NULL;
        // current -> next -> prev = previous;
        current -> next = NULL;

        delete current;
    }
    
}

int main()
{
    // Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    // cout << "Lenght of the linked List is " << getLength(head) << endl;

    InsertAtHead(head, tail, 11);
    print(head);

    cout << "head: " << head -> data << endl;
    cout << "tail: " << tail -> data << endl;

    InsertAtHead(head, tail, 13);
    print(head);

    cout << "head: " << head -> data << endl;
    cout << "tail: " << tail -> data << endl;
    
    InsertAtHead(head ,tail, 8);
    print(head);
    
    cout << "head: " << head -> data << endl;
    cout << "tail: " << tail -> data << endl;

    InserAtTail(head, tail, 25);
    print(head);
    
    cout << "head: " << head -> data << endl;
    cout << "tail: " << tail -> data << endl;

    InsertAtPosition(head, tail, 2, 100);
    print(head);
    
    cout << "head: " << head -> data << endl;
    cout << "tail: " << tail -> data << endl;

    InsertAtPosition(head, tail, 1, 101);
    print(head);
    
    cout << "head: " << head -> data << endl;
    cout << "tail: " << tail -> data << endl;

    InsertAtPosition(head, tail, 7, 102);
    print(head);
    
    cout << "head: " << head -> data << endl;
    cout << "tail: " << tail -> data << endl;

    deleteNode(head, 1);
    print(head);
    
    cout << "head: " << head -> data << endl;
    cout << "tail: " << tail -> data << endl;

    deleteNode(head, 5);
    print(head);
    
    cout << "head: " << head -> data << endl;
    cout << "tail: " << tail -> data << endl;

    deleteNode(head, 5);
    print(head);
    
    cout << "head: " << head -> data << endl;
    cout << "tail: " << tail -> data << endl;

    return 0;
}