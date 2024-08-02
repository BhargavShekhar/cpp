#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int> st) {
    while(!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }   cout << endl;
}

void sortedInsert(stack<int> &st, int &element) {
    // base case
    if(st.empty() || st.top() < element) {
        st.push(element);
        return;
    }

    int currElem = st.top();
    st.pop();
    sortedInsert(st, element);
    st.push(currElem);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(4);
    st.push(5);

    int element = 3;

    cout << "Before Insertion:" << endl;
    printStack(st);

    sortedInsert(st, element);

    cout << "After Insertion:" << endl;
    printStack(st);
    
    return 0;
}