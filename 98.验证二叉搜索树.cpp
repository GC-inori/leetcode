/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {//中序遍历有序即为二叉搜索树 
public:
    TreeNode* pre=NULL;
    bool bst(TreeNode* r)
    {
        if(!r) return 1;
        if(!bst(r->left)) return 0;//如果左子树无序返回0 
        if(pre&&pre->val>=r->val) return 0;//如果前一个结点大于当前结点 说明无序 
        pre=r;//更新前一个结点 
        return bst(r->right); //遍历右子树 
    }
    bool isValidBST(TreeNode* root) 
    {
        return bst(root);    
    }
};
