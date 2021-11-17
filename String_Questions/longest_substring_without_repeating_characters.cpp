class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        map<char, int> m;

        int max_len = INT_MIN;
        int left = 0;
        int right = 0;

        if (s.length() == 0)
            return 0;

        while (right < s.length())
        {

            //if my right character is already seen before i need not to move the left pointer one by one ,
            //I can directly jump my left pointer to (1 + previosly seen last position of right)
            if (m.find(s[right]) != m.end())
            {

                //Updating the max only, because in case of my left is before my left , I will no update
                left = max(m[s[right]] + 1, left);
            }

            //if the right character is not exits in my map . i will update the valuie by its latest position
            m[s[right]] = right;
            max_len = max(max_len, (right - left) + 1);
            right++;
        }

        return max_len;
    }
};