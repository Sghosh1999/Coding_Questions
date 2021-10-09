//infix to postfix//

#include <bits/stdc++.h>
using namespace std;

int priority(char k)
{
    if (k == '^')
        return 3;
    else if (k == '/' || k == '*')
        return 2;
    else if (k == '+' || k == '-')
        return 1;

    else
        return -1;
}

void infix_postfix(string expr)
{
    string result;
    stack<char> st;
    for (int i = 0; i < expr.length(); i++)
    {
        char c = expr[i];
        if (isalnum(c))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result = result + st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && priority(c) <= priority(st.top()))
            {
                result = result + st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        result = result + st.top();
        st.pop();
    }

    cout << result;
}
int main()
{
    string expr;
    cin >> expr;
    infix_postfix(expr);
    return 0;
}