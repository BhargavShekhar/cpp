#include<iostream>
using namespace std;

class Heap{
    public:
        int capacity;
        int *arr;
        int index;

        // ctor
        Heap(int capacity) {
            this->capacity = capacity + 1;
            arr = new int [this->capacity];
            index = 0;                  // we use 1 based indexing so that all the formula's of binary tree works
            arr[index] = -1;
        }

        void print() {
            for (int i = 1; i < capacity; i++)
            {
                cout << arr[i] << " ";
            }   cout << endl;
        }

        void insert(int data) // O(logn)
        {
            // check for overflow
            if(index == capacity-1) {
                cout << "Heap overflow" << endl;
                return;
            }

            // insert normally
            index++;
            arr[index] = data;

            // compare and place it in correct node / index
            int currIndex = index;
            while(currIndex > 1) {
                int parentIndex = currIndex/2;
                if(arr[currIndex] > arr[parentIndex]) 
                    swap(arr[currIndex], arr[parentIndex]);
                else break; // parent node is already greater
                currIndex = parentIndex;
            }
        }

        void remove() // O(logn)
        {
            // check for underflow
            if(index < 1) {
                cout << "Heap underflow" << endl;
                return;
            }
            // replace root node with last node
            arr[1] = arr[index];
            index--;
            heapify(1);
        }

        void heapify(int currIndex) // O(logn)
        {
            int leftChildIndex = 2*currIndex;
            int rightChildIndex = 2*currIndex + 1;

            int largestIndex = currIndex;

            if(leftChildIndex <= index && arr[largestIndex] < arr[leftChildIndex]) largestIndex = leftChildIndex;
            if(rightChildIndex <= index &&  arr[largestIndex] < arr[rightChildIndex]) largestIndex = rightChildIndex;

            if(currIndex != largestIndex) {
                swap(arr[currIndex], arr[largestIndex]);
                heapify(largestIndex);  // heapify rest of the node
            }
        }
};

int main()
{
    Heap pq(6);

    pq.insert(10);
    pq.print();

    pq.insert(20);
    pq.print();

    pq.insert(30);
    pq.print();

    pq.insert(40);
    pq.print();

    pq.insert(50);
    pq.print();

    pq.insert(60);
    pq.print();

    pq.insert(100); // overflow

    cout << "Removing nodes:" << endl;

    pq.remove();
    pq.print();

    pq.remove();
    pq.print();

    pq.remove();
    pq.print();

    pq.remove();
    pq.print();

    pq.remove();
    pq.print();

    pq.remove();
    pq.print();

    pq.remove(); // underflow
    
    return 0;
}