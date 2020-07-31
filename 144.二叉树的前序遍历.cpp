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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        stack<TreeNode*> s;
        while(root)
        {
            while(root)//�������������� 
            {
                res.push_back(root->val);
                if(root->right) s.push(root->right);//�����������Ϊ�ռ���ջ�� 
                root=root->left;
            }
            if(s.size()) //���������� 
            {
                root=s.top();
                s.pop();
            }
        }
        return res;
    }
};
