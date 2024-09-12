#include<iostream>
#include<queue>
using namespace std;

int main()
{
    // max-heap
    priority_queue<int> pq;

    pq.push(10);
    pq.push(50);
    pq.push(30);
    pq.push(70);
    pq.push(40);

    while(!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }   cout << endl;

    // min-heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(40);
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(50);
    minHeap.push(30);

    while(!minHeap.empty()) {
        cout << minHeap.top() << endl;
        minHeap.pop();
    }   cout << endl;
    
    return 0;
}