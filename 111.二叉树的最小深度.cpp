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
    int minDepth(TreeNode* root) 
    {
        if(!root) return 0;
        int left=minDepth(root->left),right=minDepth(root->right);
        if(!left||!right) return 1+max(left,right);//返回左右子树不为空的那个 
        return  min(left,right)+1;   //左右子树都不为空 返回左右子树最小的那个 
    }
};
