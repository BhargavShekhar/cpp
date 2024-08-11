#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void printQueue(queue<int> q) {
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }   cout << endl;
}

void reverseQueue(queue<int> &q) {
    stack<int> st;
    while(!q.empty()) {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }
}

void reverseQueueRecursivly(queue<int> &q) {
    // base case
    if(q.empty()) return;

    int elem = q.front();
    q.pop();

    reverseQueueRecursivly(q);

    q.push(elem);
}

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Before Reverse:" << endl;
    printQueue(q);

    reverseQueue(q);

    cout << "After Reverse:" << endl;
    printQueue(q);

    reverseQueueRecursivly(q);

    cout << "After Recursive Reverse:" << endl;
    printQueue(q);
    
    return 0;
}