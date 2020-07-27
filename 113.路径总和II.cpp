/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(TreeNode* root, int sum)
    {
        if(!root) return;
        sum-=root->val;
        if(!root->left&&!root->right)//在叶子节点处进行判断 
        {
            if(!sum)
            {
                tmp.push_back(root->val);
                res.push_back(tmp);
                tmp.pop_back();
            }
            return;
        }
        tmp.push_back(root->val);
        dfs(root->left,sum);
        dfs(root->right,sum);
        tmp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        dfs(root,sum);
        return res;
    }
};
