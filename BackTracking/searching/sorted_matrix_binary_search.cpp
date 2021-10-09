//Binary Search in a Sorted Matrix

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

pair<int, int> search(vector<vector<int>> &d, int key)
{

    pair<int, int> cor;
    int n = d.size();
    int m = d[0].size();

    int start_col = 0;
    int end_col = m - 1;

    int start_row = 0;
    int end_row = n - 1;

    while (start_col <= end_col && start_row <= end_row)
    {
        int start = d[start_row][end_col];

        //cout<<start<<endl;
        if (start == key)
        {
            cor.first = start_row;
            cor.second = end_col;
            break;
        }
        else if (start < key)
        {
            start_row++;
        }
        else if (start > key)
        {
            end_col--;
        }
        // else
        // {
        //     cor.first = -1;
        //     cor.second = -1;
        // }
        cor.first = -1;
        cor.second = -1;
    }
    return cor;
}

int main()
{

    int n, m, temp, key;
    cin >> n >> m >> key;

    vector<vector<int>> d;

    for (int i = 0; i < m; i++)
    {

        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            row.push_back(temp);
        }
        d.push_back(row);
    }

    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<d[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    pair<int, int> ans;
    ans = search(d, key);

    cout << ans.first << " " << ans.second << endl;
}