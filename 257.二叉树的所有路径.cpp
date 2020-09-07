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
    vector<string> ans;
    vector<int> tmp;
    void dfs(TreeNode *root)
    {
        tmp.push_back(root->val);
        if(!root->left&&!root->right)
        {
            string t=to_string(tmp[0]);
            for(int i=1;i<tmp.size();i++)
                t+="->"+to_string(tmp[i]);
                ans.push_back(t);
            tmp.pop_back();
            return;
        }
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
        tmp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        if(!root) return {};
        dfs(root);
        return ans;
    }
};
