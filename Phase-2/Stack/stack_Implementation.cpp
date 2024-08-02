#include<iostream>
using namespace std;
// Stack Implimentation Using Array.
class stack
{
    // properties
    public:
        int *arr;
        int top;
        int size;


    // behaviour --> #(Functions)
        stack(int size)             // --> CONSTRUCTOR !!
        {
            this -> size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int element)
        {
            // checking if size is available
            if (size - top > 1)
            {
                top++;
                arr[top] = element;
            }

            else
            {
                cout << "Stack Overflow" << endl;
            }
            
        }

        void pop()
        {
            // checking if element is preseny
            if(top > -1)
            {
                top--;
            }

            else
            {
                cout << "Stack Underflow" << endl;
            }
        }

        int peak()
        {
            // checking if element is present
            if (top > -1)
            {
                return arr[top];
            }

            else
            {
                cout << "Stack is Empty" << endl;
                return -1;
            }
            
        }

        bool empty()
        {
            if (top == -1)
            {
                return true;
            }

            else
            {
                return false;
            }
            
        }

};

int main()
{
    stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);

    cout << "Top of the stack is " << st.peak() << endl;
    st.pop();
    cout << "Top of the stack is " << st.peak() << endl;
    st.pop();
    cout << "Top of the stack is " << st.peak() << endl;
    st.pop();
    cout << "Top of the stack is " << st.peak() << endl;

    cout << "Is stack empty: " << st.empty() << endl; 
    
    return 0;
}