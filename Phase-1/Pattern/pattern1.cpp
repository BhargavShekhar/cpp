#include<iostream>
using namespace std;

int main()
{
    // Patter printing
    int row = 5;
    int col = 5;
    int n = 5;

    // rectangle pattern
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }   cout << endl;

    // Hollow rectangle pattern
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 || j == 0 || i == row - 1 || j == col - 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
            
        }
        cout << endl;
    }   cout << endl;

    // Half Pyramid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }   cout << endl;
    
    // Inverted Half Pyramid
    for (int i = 0; i < n; i++)
    {
        for (int j = n - i; j > 0; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }   cout << endl;

    // 180 Half pyramid
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1 - i; j > 0; j--)
        {
            cout << "  ";
        }

        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }    

        cout << endl;
    }   cout << endl;

    // Half pyramid using numbers
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }   cout << endl;

    // Floyd's triangle
    int cnt  = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << cnt << " ";
            cnt++;
        }
        cout << endl;
    }   cout << endl;

    // Butterfly patter
    int midRow = 4;
    int midCol = 8;
    for (int i = 0; i < midRow; i++)
    {
        for (int j = 0; j < midCol / 2; j++)
        {
            if (j <= i)
            {
                cout << "* ";
            }

            else
            {
                cout << "  ";
            }
        }

        for (int j = 0; j < midCol / 2; j++)
        {
            if (j < midCol / 2 - 1 - i)
            {
                cout << "  ";
            }

            else
            {
                cout << "* ";
            } 
        }
              
        cout << endl;
    }

    for (int i = 0; i < midRow; i++)
    {
        for (int j = 0; j < midCol / 2; j++)
        {
            if (j <= midCol / 2 - i)
            {
                cout << "* ";
            }

            else
            {
                cout << "  ";
            }
        }

        for (int j = 0; j < midCol / 2; j++)
        {
            if (j < midCol / 2 - 1 - i)
            {
                cout << "  ";
            }

            else
            {
                cout << "* ";
            } 
        }
              
        cout << endl;
    }   cout << endl;

    // Pyramid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }

        for (int j = 0; j < 2 * i + 1; j++)
        {
            if (j <= i)
            {
                cout << "* ";
            }

            else
            {
                cout << "# ";
            }
            
        }

        cout << endl;
        
    }
    

    return 0;
}