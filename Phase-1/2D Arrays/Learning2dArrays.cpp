#include<iostream>
using namespace std;

bool elementSearch(int arr1[][4], int target, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr1[i][j] == target)
            {
                return 1;
            }
            
        }
        
    }
    
    return 0;
}

int main()
{




    // creating 2d array
    int arr[3][4];

    // Taking input
    cout << "Enter the values of 2d arrays" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
        
    }
    
    // Printing the array
    cout << "The given array is:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }






    // intializing 2d array
    int arr1[3][4] = {{1,11,111,111}, {2,22,222,222}, {3,33,333,333}};

    // printing arr1
    cout << "Printing arr1" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }






    // Element Search in arr1
    int target = 3;
    if (elementSearch(arr1, target, 3, 4))
    {
        cout << "Element found" << endl;
    }

    else
    {
        cout << "Element not found" << endl;
    }







    
    
    return 0;
}