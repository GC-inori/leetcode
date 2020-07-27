/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 树形dp
 我们在每条路径上深度最小的那个点上计算路径长度 
class Solution {
public:
    int ans;
    int dfs(TreeNode* root)
    {
        if(!root) return 0;
        int d1=max(0,dfs(root->left)),d2=max(0,dfs(root->right));//求左右子树的最大长度，如果小于0则不往该方向扩展 
        ans=max(ans,d1+d2+root->val);
        return root->val+max(d1,d2);
    }
    int maxPathSum(TreeNode* root) 
    {
        ans=root->val;
        dfs(root);
        return ans;
    }
};
