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
            this -> next = nullptr;
        }

        // Deconstructor
        ~Node()
        {
            if(this -> next != nullptr)
            {
                delete next;
                this -> next = nullptr;
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

void InsertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);

    tail -> next = temp;
    tail = temp;
}

Node* getMid(Node* &head)
{
    Node* fast = head -> next;
    Node* slow = head;
        
    while(head != nullptr)
    {
        head = head -> next;
        if(head != nullptr)
        {
            head = head -> next;
        }
        slow = slow -> next;
    }
    return slow;
}

Node* reverseHalf(Node* temp)
{
    // Base Case
    if(temp == nullptr || temp -> next == nullptr)
    {
        return nullptr;
    }
        
    // Finding tail
    Node* tail = temp;
    Node* prevTail = nullptr;
    while(tail -> next != nullptr)
    {
        prevTail = tail;
        tail = tail -> next;
    }
        
    // Recursive Condition
    tail -> next = temp -> next;
    temp -> next = tail;
    prevTail -> next = nullptr;
        
    // Recursive Call
    temp -> next = reverseHalf(temp -> next);
}

int main()
{
    Node* head = new Node(1);
    Node* tail = head;
    InsertAtTail(tail, 2);
    InsertAtTail(tail, 2);
    InsertAtTail(tail, 1);

    print(head);

    Node* mid = getMid(head);

    cout << "Mid is: " << mid -> data << endl;

    Node* temp = reverseHalf(mid);
    print(head);
    
    return 0;
}