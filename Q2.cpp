#include <iostream>
#include <vector>
using namespace std;

void prefix(vector<vector<int>>& v);

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

    prefix(matrix);

    return 0;
}

void prefix(vector<vector<int>>& v)
{
    int row = v.size();
    int col = v[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            v[i][j] += v[i][j-1];
        }
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            v[i][j] += v[i - 1][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    return;
}