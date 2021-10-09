#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printNoard(int board[][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool canPlace(int board[][20], int n, int x, int y)
{
    //same column
    for (int k = 0; k < x; k++)
    {
        if (board[k][y] == 1)
            return false;
    }

    //left diagonal
    int i = x;
    int j = y;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        i--;
        j--;
    }

    //Right diagonal
    i = x;
    j = y;
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 1)
            return false;
        i--;
        j++;
    }
    return true;
}

bool solveNQueen(int board[][20], int n, int i)
{
    //base case
    if (i == n)
    {
        //print th eboard
        printNoard(board, n);
        return true;
    }
    //recursive case
    for (int j = 0; j < n; j++)
    {
        if (canPlace(board, n, i, j))
        {
            board[i][j] = 1;
            bool success = solveNQueen(board, n, i + 1);
            if (success)
            {
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    int board[20][20] = {0};

    int n;
    cin >> n;

    solveNQueen(board, n, 0);
}
