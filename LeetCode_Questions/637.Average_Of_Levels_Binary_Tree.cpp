https : //leetcode.com/problems/average-of-levels-in-binary-tree

        class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {

        int cnt = 0;
        long long sum = 0;

        cout << (double)29 / 2 << endl;
        queue<TreeNode *> q;
        vector<double> res;

        if (!root)
        {
            return res;
        }

        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                double val = (double)sum / (double)cnt;
                res.push_back(val);
                sum = 0;
                cnt = 0;
                if (q.size() > 0)
                {
                    q.push(NULL);
                }
            }
            else
            {
                sum += temp->val;
                cnt++;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
        return res;
    }
};