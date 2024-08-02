#include<iostream>
#include<stack>
using namespace std;

int main()
{
    // Creating a Stack.
    stack<int> s;

    // Pushing Elements on it.
    s.push(2);
    s.push(3);

    // Removing a element.
    s.pop();

    // Printing top element.
    cout << "Top element is " << s.top() << endl;

    // checking if empty or not.
    cout << "Is Stack empty -> " << s.empty() << endl;

    // checking the size of the stack
    cout << "Size of the stack is " << s.size() << endl;
    
    return 0;
}