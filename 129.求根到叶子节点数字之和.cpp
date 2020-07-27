/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 ����dp ��Ҷ�ӽڵ㴦������ֵ 
class Solution {
public:
    int ans=0;
    void dfs(TreeNode* root,int x)
    {
        x=x*10+root->val;  //���¸����ýڵ����ֵ 
        if(!root->left&&!root->right)//Ҷ�ӽڵ㷵�� 
        {
            ans+=x;
            return;
        }
        if(root->left)  dfs(root->left,x);
        if(root->right) dfs(root->right,x);
    }
    int sumNumbers(TreeNode* root) 
    {
        if(!root) return 0;
        dfs(root,0);
        return ans;
    }
};
