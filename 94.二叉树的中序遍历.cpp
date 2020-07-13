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
    vector<int> res;
    void inorder(TreeNode* root)
    {
        if(!root) return;
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        inorder(root);
        return res;
    }
    vector<int> inorderTraversal(TreeNode* root) //迭代写法 
    {
        vector<int> res;
        stack<TreeNode*> s;
        while(s.size()||root)
        {
            while(root)//将当前结点和所有左子树入栈 
            {
                s.push(root);
                root=root->left;
            }
            root=s.top();//取队首 
            s.pop();
            res.push_back(root->val);//访问 
            root=root->right;//遍历右子树 
        }
        return res;
    }
};
