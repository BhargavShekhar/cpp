#include<iostream>
using namespace std;

void printHeap(int *arr, int size) {
    for(int i = 1; i < size; i++) {
        cout << arr[i] << " ";
    }   cout << endl;
}

void heapify(int *arr, int currIndex, int size) {
    int leftChildIndex = 2*currIndex;
    int rightChildIndex = 2*currIndex + 1;

    int largestIndex = currIndex;

    if(leftChildIndex < size && arr[largestIndex] < arr[leftChildIndex]) largestIndex = leftChildIndex;
    if(rightChildIndex < size && arr[largestIndex] < arr[rightChildIndex]) largestIndex = rightChildIndex;

    if(largestIndex != currIndex) {
        swap(arr[currIndex], arr[largestIndex]);
        heapify(arr, largestIndex, size);
    }
}

void heapSort(int *arr, int size) {
    int lastIndex = size - 1;
    while(lastIndex > 1) {
        // delete and heapify
        swap(arr[1], arr[lastIndex]);
        lastIndex--;
        heapify(arr, 1, lastIndex+1); 
    }
}

int main()
{
    // input should be a valid heap
    int arr[] = {-1, 50, 40, 30, 10, 20};
    int size = sizeof(arr) / sizeof(int);

    cout << "Heap Before HeapSort" << endl;
    printHeap(arr, size);

    heapSort(arr, size);

    cout << "Heap After HeapSort" << endl;
    printHeap(arr, size);

    return 0;
}