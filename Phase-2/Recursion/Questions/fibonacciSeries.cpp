#include<iostream>
using namespace std;

void Fibonacci(int n, int prevElement, int next_element, int count)
{
    // base case
    if (count == n)
    {
        return;
    }
    
    // resurtsion relation
    cout << prevElement << " ";
    int temp = prevElement;
    prevElement = next_element;
    next_element += temp;
    Fibonacci(n, prevElement, next_element, ++count);
}

int main()
{
    int n, starting_Element = 0, next_Element = 1;
    cout << "Enter the nth term of fibonaci series" << endl;
    cin >> n;

    cout << "Fibanacci series till " << n << "th term:" << endl;
    Fibonacci(n, starting_Element, next_Element, 0);

    return 0;
}