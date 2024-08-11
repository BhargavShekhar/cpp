#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// this is my logic and it may have some potential bug but it works fine
void reverse(queue<int> &q, int &k, int size) {
    // base case
        if(size <= 0) return;
        
        if(size >= k){
            stack<int> st;
            for(int i = 0; i < k; i++) {
                st.push(q.front());
                q.pop();
            }
            while(!st.empty()) {
                q.push(st.top());
                st.pop();
            }
        }
        else {
            int count = size;
            while(count--) {
                q.push(q.front());
                q.pop();
            }
        }
        
        reverse(q, k, size-k);
}

void printQueue(queue<int> q) {
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }   cout << endl;
}

int main()
{
    queue<int> q;

    int num {3};
    cout << num

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);

    int k = 6;
    int size = q.size();

    reverse(q, k, size);

    printQueue(q);
    
    return 0;
}