/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {//�����������Ϊ���������� 
public:
    TreeNode* pre=NULL;
    bool bst(TreeNode* r)
    {
        if(!r) return 1;
        if(!bst(r->left)) return 0;//������������򷵻�0 
        if(pre&&pre->val>=r->val) return 0;//���ǰһ�������ڵ�ǰ��� ˵������ 
        pre=r;//����ǰһ����� 
        return bst(r->right); //���������� 
    }
    bool isValidBST(TreeNode* root) 
    {
        return bst(root);    
    }
};
