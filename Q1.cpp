//Q1 - Given a 2D matrix with m rows and n columns containing integers. Print and return the row number with maximum sum in the array.

#include <iostream>
#include <vector>
using namespace std;

int maxRow(vector<vector<int>> v);

int main()
{
    int m,n;
    cout<<"Enter number of rows: ";
    cin>>m;
    cout<<"Enter number of rows: ";
    cin>>n;

    vector<vector<int>> matrix(m, vector<int> (n));

    for (int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout<<"Enter array element: ";
            cin>>matrix[i][j];
        }
        cout<<endl;
    }

    cout<<maxRow(matrix)<<endl;

    return 0;
}

int maxRow(vector<vector<int>> v)
{   
    int col_size = v[0].size();
    //Prefix sum of each row of matrix v
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 1; j < col_size; j++)
        {
            v[i][j] += v[i][j-1];
        }
    }

    int max = v[0][col_size-1];
    int max_index = 1;
    
    for (int i = 1; i < v.size(); i++)
    {
        if (max < v[i][col_size-1])
        {
            max = v[i][col_size-1];
            max_index = i + 1;
        }
    }
    return max_index;
}