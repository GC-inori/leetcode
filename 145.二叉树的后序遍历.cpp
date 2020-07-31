/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 �������˳��Ϊ���Ҹ� ����һ���±���˳�� ������ͺ������˳�������෴ �ѽ����ת���Ǻ������ 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        stack<TreeNode*> s;
        while(root)
        {
            while(root)//���������½� 
            {
                res.push_back(root->val);
                if(root->left) s.push(root->left);
                root=root->right;
            }
            if(s.size())//���������� 
            {
                root=s.top();
                s.pop();
            }
        }
        return vector<int> (res.rbegin(),res.rend());
    }
};
