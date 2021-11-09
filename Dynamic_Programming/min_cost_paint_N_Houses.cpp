#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int findMinimumCost(int arr[][3])
{

    int costs[3][3] = {0};

    costs[0][0] = arr[0][0];
    costs[0][1] = arr[0][1];
    costs[0][2] = arr[0][2];

    for (int i = 1; i < 3; i++)
    {
        costs[i][0] = min(costs[i - 1][1], costs[i - 1][2]) + arr[i][0];

        costs[i][1] = min(costs[i - 1][0], costs[i - 1][2]) + arr[i][1];

        costs[i][2] = min(costs[i - 1][0], costs[i - 1][1]) + arr[i][2];
    }

    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<costs[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return min(costs[2][0], min(costs[2][1], costs[2][2]));
}

int main()
{
    int arr[3][3] = {{14, 2, 11},
                     {11, 14, 5},
                     {14, 3, 10}};

    cout << findMinimumCost(arr);
}