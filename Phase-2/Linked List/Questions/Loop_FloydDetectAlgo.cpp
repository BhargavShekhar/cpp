#include<iostream>
#include<map>
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

bool floydDetectLoop(Node* &head)
{
    if (head == NULL)
    {
        return false;
    }

    Node* fast = head;
    Node* slow = head;

    while (fast != NULL)
    {
        fast = fast -> next;

        if (fast != NULL)
        {
            fast = fast -> next;
        }

        slow = slow -> next;

        // Loop is present
        if (fast == slow)
        {
            cout << "Loop is present at node with data " << fast -> data << endl;
            return true;
        }

    }

    return false;
}

int main()
{
    Node* Node1 = new Node(10);
    Node* head = Node1;
    Node* tail = Node1;

    InsertatHead(head, 8);
    InsertatHead(head, 6);
    InsertatHead(head, 4);
    InsertatHead(head, 2);

    // pointing tail at its position
    while (tail -> next != NULL)
    {
        tail = tail -> next;
    }
    
    tail -> next = head -> next;    // making a loop
    // print(head);

    if (floydDetectLoop(head))
    {
        cout << "Linked List is circular" << endl;
    }

    else
    {
        cout << "Linked List is not circular" << endl;
    }    
    
    return 0;
}