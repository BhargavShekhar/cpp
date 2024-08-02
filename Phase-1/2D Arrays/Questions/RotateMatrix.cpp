// Rotaion of matrix 90deg without creating another matrix
#include<iostream>
#include<algorithm>
using namespace std;

void printarr(int arr[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
}

int main()
{
    int matrix[4][4] = {{11, 12, 13, 14}, {51, 61, 17, 81}, {91, 10, 11, 12}, {13, 14, 15, 16}};

    int row = 4;
    int col = 4;

    cout << "Original matrix:" << endl;
    printarr(matrix, row, col);

    // creating transverse of the matrix
    for (int i = 0; i < row - 1; i++)
    {
        for (int j = i + 1; j < col; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    cout << "Transverse matrix:" << endl;
    printarr(matrix, row, col);

    // swaping the columns
    int startingRow = 0;
    int endingRow = row - 1;   // ----> Indexing
    int startingCol = 0;
    int endingCol = col - 1;

    int midCol = endingCol / 2;

    while (startingCol <= midCol)
    {
        for (int index = startingRow; index <= endingRow; index++)
        {
            swap(matrix[index][startingCol], matrix[index][endingCol]);
        }
        startingCol++;
        endingCol--;
    }
    
    // printing the matrix
    cout << "Rotated matrix:" << endl;
    printarr(matrix, row, col);
    
    return 0;
}