#include<iostream>
using namespace std;

void home(int source, int des)
{
    // base case
    if (source == des)
    {
        cout << "Reached destination" << endl;
        return;
    }

    // recursive relation
    cout << "Destination is " << des - source << " times far" << endl;
    home(++source, des);
}

int main()
{
    int source = 0;
    int des = 10;

    home(source, des);

    return 0;
}