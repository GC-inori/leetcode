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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(!p&&!q) return 1;//两个都为空 
        if(!p||!q) return 0;//一个空一个不空 
        if(p->val!=q->val) return 0;//值不相等 
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);//左右子树是否相等 
    }
};
