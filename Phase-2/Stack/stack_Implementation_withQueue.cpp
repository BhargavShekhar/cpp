#include<iostream>
#include<queue>
using namespace std;

class stack
{
    private:
        int top;

    public:
        // constructor
        stack(int data)
        {
            queue<int> q;
            q.push(data);
            top = data;
            cout << "stack created" << endl;
        }

        // top fuction
        top()
        {
            cout << top << endl;
        }

        // push fuction
        push(int data)
        {
            q.push(data);
            top = data;
        }

        // pop function
        pop()
        {
            
        }
};

int main()
{
    
    return 0;
}