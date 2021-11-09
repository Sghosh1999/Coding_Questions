#include <bits/stdc++.h>
class Solution
{
public:
    int lengthOfLIS(vector<int> &arr)
    {

        int len = arr.size();

        vector<int> dp(len, 1);

        int max_ele = dp[0];

        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        for (int i = 0; i < dp.size(); i++)
        {
            max_ele = max(max_ele, dp[i]);
        }
        return max_ele;
    }
};