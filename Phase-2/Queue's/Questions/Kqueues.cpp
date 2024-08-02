#include<iostream>
using namespace std;

class kQueue{
    private:
        int *arr;
        int *next;
        int *front;
        int *rear;
        int freeSpace;

    public:
        // constructor
        kQueue(int size, int k)
        {
            arr = new int[size];
            next = new int[size];
            front = new int[k];
            rear = new int[k];

            for (int i = 0; i < size - 1; i++)
            {
                next[i] = i + 1;
            }
            next[size - 1] = -1;

            for (int i = 0; i < k; i++)
            {
                front[i] = -1;
                rear[i] = -1;
            }
            
            freeSpace = 0;

            cout << "Queue of size " << size << " and of " << k << " divistion is created" << endl;
        }

        // Push function
        void enqueue(int data, int k)
        {
            // check for overflow
            if (freeSpace == -1)
            {
                cout << "Queue overflow" << endl;
                return;
            }
            
            // update index
            int index = freeSpace;

            // update freespot
            freeSpace = next[index];

            // check if first element
            if (front[k - 1] == -1)
            {
                front[k - 1] = index;
            }

            // link new element
            else
            {
                next[rear[k - 1]] =  index;
            }

            // update index
            next[index] = -1;

            // push data
            arr[index] = data;

            // update rear
            rear[k -1] =index;
        }

        int dequeue(int k)
        {
            // check for underflow
            if (front[k - 1] == -1)
            {
                cout << "queue is empty" << endl;
                return -1;
            }
            
            // find index
            int index = front[k - 1];

            // update front
            front[k - 1] = next[index];

            // update next
            next[index] = freeSpace;

            // update feespace
            freeSpace = index;

            // return value
            return arr[index];
        }
};

int main()
{
    kQueue q(5, 3);

    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    
    cout << q.dequeue(1) << endl;
    
    return 0;
}
