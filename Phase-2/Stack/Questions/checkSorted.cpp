#include<iostream>
#include<limits.h>
#include<stack>

using namespace std;

void printStack(stack<int> st) {
    while(!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }   cout << endl;
}

bool isSorted(stack<int> &st, int element = INT_MIN) {
    // base case
    if(st.empty()) return true;
    if(st.top() < element) return false;

    element = st.top();
    st.pop();
    bool ans = isSorted(st, element);
    st.push(element);

    return ans;
}

int main()
{
    stack<int> st1;
    st1.push(5);
    st1.push(4);
    st1.push(3);
    st1.push(2);
    st1.push(1);

    stack<int> st2;
    st2.push(5);
    st2.push(9);
    st2.push(12);
    st2.push(4);

    cout << "Is stack 1 sorted: " << isSorted(st1) << endl;
    cout << "Is stack 2 sorted: " << isSorted(st2) << endl;

    return 0;
}