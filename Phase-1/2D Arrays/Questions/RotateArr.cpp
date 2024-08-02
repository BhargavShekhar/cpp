#include<iostream>
using namespace std;

// Rotation of array 90deg with creation of another array

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int row = 3;
    int col = 3;

    int ansRow = 0;
    int ansCol = 0;

    int ans[row][col];

    // Will transverse through matrix
    for (int j = 0; j < col; j++)
    {
        for (int i = row - 1; i >= 0; i--)
        {
            ans[ansRow][ansCol] = matrix[i][j];
            ansCol++;
        }
        ansRow++;
        ansCol = 0;
    }

    // Printing the ans array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}