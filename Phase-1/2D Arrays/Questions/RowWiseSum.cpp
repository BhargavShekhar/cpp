#include<iostream>
using namespace std;

int main()
{
    // Queston ---> Print row wise sum of the given 2D-array
    int arr[][3] = {{3, 4, 11}, {2, 12, 1}, {7, 8, 7}};


    // Soln --->
    cout << "Given array is:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        
        cout << endl;
    }
    
    cout << "Sum of the Rows are ";
    for (int i = 0; i < 3; i++)
    {
        int ans = 0;
        for (int j = 0; j < 3; j++)
        {
            ans += arr[i][j];
        }
        
        cout << ans << " ";
    }

    return 0;
}