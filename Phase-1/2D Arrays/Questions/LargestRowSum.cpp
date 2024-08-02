// Question ---> From the RowWiseSum problem return the row who has the largest sum
#include<iostream>
using namespace std;

int print_RowSum(int arr[][3], int row, int col)
{
    int index = 0;

    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        
        cout << sum << " ";

        if (sum > index)
        {
            index = i;
        }
        
    }
    cout << endl;   

    return index + 1;
}

int main()
{
    int arr[][3] = {{3, 4, 11}, {2, 12, 1}, {7, 8, 7}};

    cout << "Row which has largest sum is row " << print_RowSum(arr, 3, 3) << endl;

    return 0;
}