//Q3 - You are given an m x n integer matrix grid. Here m>=3 and n>=3. Return the maximum sum of the elements of an hourglass.

#include <iostream>
#include <vector>
using namespace std;

int hourglass(vector<vector<int>> v);

int main()
{
    int m,n;
    cout<<"Enter number of rows: ";
    cin>>m;
    cout<<"Enter number of columns: ";
    cin>>n;

    if (m < 3 || n < 3)
    {
        cout<<"Number of rows and columns should be greater than 3";
        return 1;
    }

    else
    {
        vector<vector<int>> matrix(m, vector<int> (n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<"Enter the array element: ";
                cin>> matrix[i][j];
            }
            cout<<endl;
        }

        cout<<hourglass(matrix)<<endl;

        return 0;
    }
}

int hourglass(vector<vector<int>> v)
{
    int row = v.size();
    int col = v[0].size();

    int max_sum = INT16_MIN;
    for (int i = 0; i < row - 2; i++)
    {
        for (int j = 0; j < col - 2; j++)
        {
            int sum = v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j + 1] + v[i + 2][j] + v[i + 2][j + 1] + v[i + 2][j + 2];
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}