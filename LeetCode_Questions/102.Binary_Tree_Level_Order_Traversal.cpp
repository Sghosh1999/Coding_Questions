class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        queue<TreeNode *> q;

        vector<vector<int>> results;
        vector<int> levels;

        if (!root)
        {
            return results;
        }

        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {

            TreeNode *temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                cout << endl;
                results.push_back(levels);
                levels.resize(0);

                if (q.size() > 0)
                {
                    q.push(NULL);
                }
            }
            else
            {
                cout << temp->val << " ";
                levels.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }

        return results;
    }
};