/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 二叉搜索树中序遍历有序 中序遍历第k个几位第k小 
class Solution {
public:
    int ans,kk;
    void dfs(TreeNode* root)
    {
        if(kk<=0||!root) return;
        dfs(root->left);
        if(!--kk)
        {
            ans=root->val;
            return;
        }
        dfs(root->right);
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        kk=k;
        dfs(root);
        return ans;    
    }
};
