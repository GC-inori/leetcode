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
 //找规律 
class Solution {
public:
    void flatten(TreeNode* root) 
    {
        while(root)
        {
            if(root->left)//如果一个结点的左子树为空 不需要转化 
            {
                auto t=root->left;  
                while(t->right) t=t->right;//在左子树的最右子树末尾接上root的右子树 
                t->right=root->right;
                root->right=root->left;//将右子树等于左子树  左子树置空
                root->left=NULL;
            }
            root=root->right;
        } 
    }
};
