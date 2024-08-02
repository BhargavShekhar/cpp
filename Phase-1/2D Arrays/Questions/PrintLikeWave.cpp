#include<iostream>
using namespace std;

int main()
{
    int arr[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    int row = 0;
    int col = 0;

    while (row < 4)
    {
        if (row % 2 == 0)
        {
            for (int i = 0; i < 3; i++)
            {
                cout << arr[i][col] << " ";
            }

            col++;
        }

        else
        {
            for (int i = 2; i >= 0; i--)
            {
                cout << arr[i][col] << " ";
            }
            
            col++;
        }
        
        row++;
    }
    

    return 0;
}