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
    bool check(TreeNode* l,TreeNode* r)
    {
        if(!l&&!r) return 1;
        if(!l||!r) return 0;
        if(l->val!=r->val) return 0;
        return check(l->left,r->right)&&check(l->right,r->left);// ����Ļ�l��������Ӧ�ú�r���������ɾ����ϵ 
    }
    bool isSymmetric(TreeNode* root) 
    {
        if(!root) return 1;
        return check(root->left,root->right);//�ж����������Ƿ���    
    }
};
