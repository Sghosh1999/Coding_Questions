#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isPair(char opening, char closing)
{

    if (opening == '(' && closing == ')')
        return true;
    else if (opening == '{' && closing == '}')
        return true;
    else if (opening == '[' && closing == ']')
        return true;
    return false;
}

bool isBalanced(string expr)
{
    stack<char> xyz;

    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        {
            xyz.push(expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            if (xyz.empty() || !isPair(xyz.top(), expr[i]))
            {
                return false;
            }
            else
                xyz.pop();
        }
    }

    // while(!xyz.empty()){
    //     cout<<xyz.top()<<endl;
    //     xyz.pop();
    // }

    return xyz.empty() ? true : false;
}

int main()
{

    string expr = "(A+B)";
    //cin>>expr;

    if (isBalanced(expr))
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not Balanced";
    }
    return 0;
}