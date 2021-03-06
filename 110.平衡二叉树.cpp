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
    bool ans=1;
    int dfs(TreeNode* root)
    {
        if(!root) return 0;
        int l=dfs(root->left),r=dfs(root->right);
        if(abs(l-r)>1)
            ans=0;
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) 
    {
        dfs(root);
        return ans;
    }
};
