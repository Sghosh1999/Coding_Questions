class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        //Sort the string array because the longest common prefix will be the
        //common prefix of the first and last string
        sort(strs.begin(), strs.end());

        string first = strs[0];
        string end = strs[strs.size() - 1];

        int i = 0, j = 0;
        string ans = "";
        while (i < first.length() && j < end.length())
        {
            if (first[i] == end[j])
            {
                ans += first[i];
            }
            else
            {
                break;
            }
            i++;
            j++;
        }
        return ans;
    }
};