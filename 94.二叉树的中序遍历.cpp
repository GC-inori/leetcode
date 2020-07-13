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
    vector<int> inorderTraversal(TreeNode* root) //����д�� 
    {
        vector<int> res;
        stack<TreeNode*> s;
        while(s.size()||root)
        {
            while(root)//����ǰ����������������ջ 
            {
                s.push(root);
                root=root->left;
            }
            root=s.top();//ȡ���� 
            s.pop();
            res.push_back(root->val);//���� 
            root=root->right;//���������� 
        }
        return res;
    }
};
