/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

��������һ�ö�����������������ö�����������������Ӹ���㿪ʼѰ�ҡ�
���ȸ����ض��Ǻ�ѡ�������ȣ�������� p �� q ͬʱ������������������������ƶ������ p �� q ͬʱ�������������������Ҷ����ƶ���
�����ֲ����� 2 �е�������������ֹͣѰ�ң���ǰ����������������ȡ�
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(p->val>q->val) swap(p,q);
        if(p->val<=root->val&&q->val>=root->val) return root;
        if(q->val<root->val) return lowestCommonAncestor(root->left,p, q); //��������Ѱ�� 
        return lowestCommonAncestor(root->right,p, q); //��������Ѱ�� 
    }
};
