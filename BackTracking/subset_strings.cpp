//Find Subsets Of a Given String
//Input - abc
//Output - "",a,b,c,ab,ac,bc,abc

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool custom(string a, string b)
{
    return a.length() == b.length() ? a < b : a.length() < b.length();
}

void printAllSubstring(char *input, char *output, int i, int j, vector<string> &list)
{
    //base case
    if (input[i] == '\0')
    {
        output[j] = '\0';
        string temp(output);
        list.push_back(temp);
        return;
    }

    //Include the ith Letter
    output[j] = input[i];
    printAllSubstring(input, output, i + 1, j + 1, list);
    //Exclude the ith letter
    printAllSubstring(input, output, i + 1, j, list);
}

int main()
{
    char str[100], output[100];
    cin >> str;

    vector<string> list;
    printAllSubstring(str, output, 0, 0, list);

    sort(list.begin(), list.end(), custom);
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << " ";
    }
}
