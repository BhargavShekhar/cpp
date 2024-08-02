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
};

class stack
{
    public:
        // int data;
        Node* top;

        // Constructor
        stack()
        {
            top = nullptr;
        }

        // Behaviour
        bool empty()
        {
            return top == nullptr;
        }

        void push(int data)
        {
            if (!empty())
            {
                Node* temp = new Node(data);
                temp -> next = top;
                top = temp;
            }
            else
            {
                Node* temp = new Node(data);
                top = temp;
            }
        }

        void pop()
        {
            if(!empty())
            {
                Node* temp = top;
                top = top -> next;
                delete temp;
            }
            else
            {
                cout << "Stackunderflow, Can not remove element" << endl;
            }
        }

        void peak()
        {
            if (!empty())
            {
                cout << top -> data << endl;
            }
            else
            {
                cout << "Stackunderflow, No element to display" << endl;
            }
        }
};

int main()
{
    stack st;

    st.push(5);
    st.push(10);
    st.push(15);
    st.push(20);

    st.peak();
    st.pop();
    st.peak();
    st.pop();
    st.peak();
    st.pop();
    st.peak();
    st.pop();
    st.peak();

    cout << st.empty() << endl;
    
    return 0;
}