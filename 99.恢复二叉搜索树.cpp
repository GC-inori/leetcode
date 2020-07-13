�������������������һ������ԣ�˵��������node�轻����������������ԣ�˵����һ�Ե�ǰһ��node�͵ڶ��Եĺ�һ��node��Ҫ������
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
class Solution {
public:
    TreeNode* pre=NULL,*w1=NULL,*w2=NULL;
    void bst(TreeNode *r)
    {
        if(!r) return;
        bst(r->left);
        if(pre&&pre->val>r->val)
        {
            w1=r;
            if(!w2) w2=pre;
        }
        pre=r;
        bst(r->right);
    }
    void recoverTree(TreeNode* root) 
    {
        bst(root);
        swap(w1->val,w2->val);
    }
};
