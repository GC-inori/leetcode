/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

由于这是一棵二叉查找树，可以利用二叉查找树的性质来从根结点开始寻找。
首先根结点必定是候选公共祖先，接着如果 p 和 q 同时出现在左子树，则往左儿子移动；如果 p 和 q 同时出现在右子树，则往右儿子移动；
若发现不满足 2 中的两个条件，则停止寻找，当前结点就是最近公共祖先。
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(p->val>q->val) swap(p,q);
        if(p->val<=root->val&&q->val>=root->val) return root;
        if(q->val<root->val) return lowestCommonAncestor(root->left,p, q); //往左子树寻找 
        return lowestCommonAncestor(root->right,p, q); //往右子树寻找 
    }
};
