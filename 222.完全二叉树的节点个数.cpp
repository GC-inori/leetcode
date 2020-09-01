二叉树一般都可以考虑成递归问题，对于每个节点，计算一直向左和一直向右的高度，如果相等则说明是满二叉树，那么该树节点个数为^h-1(h是二叉树的高度)；
如果不相等则说明不是满二叉树，则需要递归地向下求解，该棵树的节点个数等于1+左子树节点数+右子树节点数.
其实这和一般的二叉树计算节点个数的思路是一样的，不同点在于这是完全二叉树，所以如果一直向左和一直向右的高度相等的话就可以马上计算出节点个数而不用继续向下递归了。
这道题相当于二分查找最后一层最后一个节点的位置，每次查找的复杂度是O(logn)，一共需要查找O(logn)次，所以复杂度为O(logn)*O(logn)。
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
    int countNodes(TreeNode* root) 
    {
        if(!root) return 0;
        auto l=root->left,r=root->right;
        int cntl=0,cntr=0;
        while(l) cntl++,l=l->left;
        while(r) cntr++,r=r->right;
        if(cntl==cntr)
            return (1<<(cntl+1))-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};

