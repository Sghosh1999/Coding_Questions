class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        map<int, int> m;
        bool flag = true;
        for (int i = 0; i < arr.size(); i++)
        {
            m[arr[i]]++;
        }

        for (auto x : m)
        {
            auto temp = m.crbegin();

            if (x.second > 2)
            {
                flag = false;
            }

            if (temp->second == 2)
            {
                flag = false;
            }
        }

        //cout<<flag<<endl;
        int in_cnt = 0, de_cnt = 0;

        if (flag)
        {
            for (int i = 1; i < arr.size() - 1; i++)
            {
                if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
                {
                    int curr_ele = i;

                    //checking left side
                    for (int k = 0; k < i; k++)
                    {
                        if (arr[k] < arr[k + 1])
                        {
                            in_cnt++;
                        }
                    }

                    //checking left side
                    for (int k = i + 1; k < arr.size(); k++)
                    {
                        if (arr[k] < arr[k - 1])
                        {
                            de_cnt++;
                        }
                    }
                }
            }
        }

        //cout<<in_cnt<<" "<<de_cnt<<endl;

        if (flag && (in_cnt + de_cnt + 1 == arr.size()) && arr.size() > 2)
        {
            return true;
        }

        return false;
    }
};