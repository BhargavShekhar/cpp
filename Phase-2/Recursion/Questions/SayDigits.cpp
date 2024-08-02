#include<iostream>
using namespace std;

void sayDigit(int num, string word[])
{    
    // base case
    if (num == 0)
    {
        return ;
    } 

    // recursive relation
    sayDigit(num / 10, word);

    cout << word[num % 10] << " ";
}

int main()
{
    int n;
    cout << "Enter some digits:" << endl;
    cin >> n;

    // maping the digits
    string word[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    sayDigit(n, word);

    return 0;
}