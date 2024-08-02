// Print max number from numric string

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string str = "2121389";

    sort(str.begin(), str.end(), greater<int>());

    cout << str << endl;

    return 0;
}