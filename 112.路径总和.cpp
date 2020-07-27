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
    bool hasPathSum(TreeNode* root, int sum) 
    {
        if(!root) return 0; //根结点为空则不存在 
        sum-=root->val;
        if(!root->left&&!root->right) return !sum; //到达叶子结点时判断是否等于路径长度 
        return hasPathSum(root->left,sum)||hasPathSum(root->right,sum);    
    }
};
