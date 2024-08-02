#include<iostream>
#include<queue>
using namespace std;

int main()
{
    // creating a queue
    queue<int> q;

    q.push(11);
    q.push(15);
    q.push(13);

    cout << "size of queue is " << q.size() << endl;

    q.pop();
    q.pop();
    q.pop();

    cout << "size of queue is " << q.size() << endl;

    cout << "Is queue empty " << q.empty() << endl;

    q.push(11);
    q.push(15);
    q.push(13);

    cout << "Front of queue is " << q.front() << endl;
    cout << "Back of queue is " << q.back() << endl;
    
    return 0;
}