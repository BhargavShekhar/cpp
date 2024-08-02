#include<iostream>
#include<string>
using namespace std;

void reverse(string& str, int i, int j)
{
    // Base Case
    if (i >= j)
    {
        return ;
    }
    // Recursive Relation
    swap(str[i], str[j]);
    reverse(str, ++i, --j);
}

int main()
{
    string name = "bhargav";

    reverse(name, 0, name.size() - 1);

    cout << name << endl;
    
    return 0;
}