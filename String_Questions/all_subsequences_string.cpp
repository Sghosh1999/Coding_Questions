#include <bits/stdc++.h>
using namespace std;

int subsequences(string input, string output[])
{
    //Base case
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    //Calling the function of remaining
    string reststring = input.substr(1);
    int small_output = subsequences(reststring, output);

    for (int i = 0; i < small_output; i++)
    {
        output[i + small_output] = output[i] + input[0];
    }

    return 2 * small_output;
}

//Peek and No Peek approach
void subsequences(string input, int i, char *output, int j)
{

    if (i == input.size())
    {
        output[j] = '\0';
        cout << output << endl;
        return;
    }

    //Include the ith Character
    output[j] = input[i];
    subsequences(input, i + 1, output, j + 1);

    //Exclude the ith Character
    subsequences(input, i + 1, output, j);
}

int main()
{
    string input;
    cin >> input;

    // string* output = new string[10001];

    // int len = subsequences(input,output);
    // for(int i=0;i<len;i++){
    //     cout<<output[i]<<endl;
    // }

    char *output = new char[10001];

    subsequences(input, 0, output, 0);
}