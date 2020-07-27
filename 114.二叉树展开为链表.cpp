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
 //�ҹ��� 
class Solution {
public:
    void flatten(TreeNode* root) 
    {
        while(root)
        {
            if(root->left)//���һ������������Ϊ�� ����Ҫת�� 
            {
                auto t=root->left;  
                while(t->right) t=t->right;//������������������ĩβ����root�������� 
                t->right=root->right;
                root->right=root->left;//������������������  �������ÿ�
                root->left=NULL;
            }
            root=root->right;
        } 
    }
};
