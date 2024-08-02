#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;

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
            if (this -> next != NULL)
            {
                delete next;
                this -> next = NULL;
            }
            
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

void InsertatHead(Node* &head, int d)
{
    Node* temp = new Node(d);

    // if Node is empty
    if (head == NULL)
    {
        head = temp;
    }
    
    else
    {
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
    
}

void InsertAtPosition(Node* head, int d, int position)
{
    if (position == 1)
    {
        InsertatHead(head, d);
        return;
    }
    

    Node* NodeToInsert = new Node(d);
    Node* temp = head;

    int cnt = 0;

    while (cnt < position - 1)
    {
        temp = temp -> next;
        cnt++;
    }
    
    NodeToInsert -> next = temp -> next;
    temp -> next -> prev = NodeToInsert;
    temp -> next = NodeToInsert;
    NodeToInsert -> prev = temp;

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

void RemoveDuplicates(Node* &head)
{
    Node* temp = head;
    Node* search = temp -> next;
    Node* previous = head;

    while (temp -> next != nullptr)
    {
        while (search != nullptr)
        {
            if (search -> data != temp -> data)
            {
                search = search -> next;
                previous = previous -> next;
            }

            else
            {
                Node* toDelete = search;
                previous -> next = search -> next;
                search = search -> next;
                toDelete -> next = nullptr;
                delete toDelete;
            }
        }
        
        temp = temp -> next;
        search = temp -> next;
        previous = temp;
    }
    
}

int main()
{
    Node* Node1 = new Node(2);
    Node* head = Node1;
    Node* tail = Node1;

    InsertatHead(head, 2);
    InsertatHead(head, 4);
    InsertatHead(head, 5);
    InsertatHead(head, 2);
    InsertatHead(head, 4);
    
    print(head);

    RemoveDuplicates(head);

    print(head);
    
    return 0;
}