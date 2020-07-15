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
    bool check(TreeNode* l,TreeNode* r)
    {
        if(!l&&!r) return 1;
        if(!l||!r) return 0;
        if(l->val!=r->val) return 0;
        return check(l->left,r->right)&&check(l->right,r->left);// 镜像的话l的左子树应该和r的右子树成镜像关系 
    }
    bool isSymmetric(TreeNode* root) 
    {
        if(!root) return 1;
        return check(root->left,root->right);//判断两棵子树是否镜像    
    }
};
