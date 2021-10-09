

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void findPermutaions(string input, int idx,vector<string> &list){
    if(idx == input.length())
    {
            list.push_back(input);
            return;
    }
    for(int i= idx;i<input.length();i++){
        swap(input[i],input[idx]);
        
        findPermutaions(input,idx+1,list);
        
        swap(input[i],input[idx]);
    }
}

int main()
{
    string input;
    
    cin>>input;
    vector<string>list;
    
    findPermutaions(input,0,list);
    
    for(auto x: list){
        cout<<x<<endl;
    }
    
    
}