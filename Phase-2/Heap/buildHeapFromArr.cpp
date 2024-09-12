#include<iostream>
using namespace std;

void heapify(int* arr, int currIndex, int size) {
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

void buildHeap(int *arr, int size) // O(logn)
{
    for(int i = (size-1)/2; i >= 1; i--) {
        heapify(arr, i, size);
    }
}

int main()
{
    // Build Heap Should be -> 50 40 30 10 20
    int arr[] = {-1, 10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(int);

    buildHeap(arr, size);

    // print heap
    for(int i = 1; i < size; i++) {
        cout << arr[i] << " ";
    }   cout << endl;
    
    return 0;
}