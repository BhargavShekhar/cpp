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

        // Destructor
        ~Node()
        {
            int value = this -> data;

            while (this -> next != NULL)
            {
                delete next;
                this -> next = NULL; 
            }
            
            cout << "Memory free for load with data " << value << endl;
        }
};

void InsertNode(Node* &tail, int element, int d)    // element => postion after which we have to insert the node.
{
    // Empty List
    if (tail == NULL)
    {
        Node* newNode = new Node(d);

        tail = newNode;
        newNode -> next = newNode;
    }

    else
    {
        Node* current = tail;

        while (current -> data != element)
        {
            current = current -> next;
        }
        
        Node* temp = new Node(d);

        temp -> next = current -> next;
        current -> next = temp;

    }
    
}

void print(Node* tail)  // not passing by refferal since we are updating the tail value.
{
    Node* temp = tail;

    // if empty list
    if (tail == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }

    // using do while since we can have a single node
    do
    {
        cout << tail -> data << " ";
        tail = tail -> next;

    } while (tail != temp);    
    cout << endl;
    
}

void deleteNode(Node* &tail, int value)
{
    // Empty List
    if (tail == NULL)
    {
        cout << "List is empty, please check again!" << endl;
        return;
    }

    else
    {
        Node* previous = tail;
        Node* current = previous -> next;

        while (current -> data != value)
        {
            previous = current;
            current = current -> next;
        }

        previous -> next = current -> next;

        // 1 node linked list
        if (current == previous)
        {
            tail = NULL;
        }
        
        // >=2 node linked list
        if (tail == current)
        {
            tail = previous;
        }
        
        current -> next = NULL;
        delete current;
        
    }
    
}

int main()
{
    Node* tail = NULL;

    InsertNode(tail, 5, 3); // element doesn't matter in case of empty list.
    print(tail);

    // InsertNode(tail, 3, 5);
    // print(tail);

    // InsertNode(tail, 5, 7);
    // print(tail);

    // InsertNode(tail, 7, 9);
    // print(tail);

    // InsertNode(tail, 5, 6);
    // print(tail);

    // InsertNode(tail, 9, 10);
    // print(tail);

    // InsertNode(tail, 3, 4);
    // print(tail);

    // deleteNode(tail, 3);
    // print(tail);

    // deleteNode(tail, 6);
    // print(tail);

    deleteNode(tail, 3);
    print(tail);

    return 0;
}