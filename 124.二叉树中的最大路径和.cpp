/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 ����dp
 ������ÿ��·���������С���Ǹ����ϼ���·������ 
class Solution {
public:
    int ans;
    int dfs(TreeNode* root)
    {
        if(!root) return 0;
        int d1=max(0,dfs(root->left)),d2=max(0,dfs(root->right));//��������������󳤶ȣ����С��0�����÷�����չ 
        ans=max(ans,d1+d2+root->val);
        return root->val+max(d1,d2);
    }
    int maxPathSum(TreeNode* root) 
    {
        ans=root->val;
        dfs(root);
        return ans;
    }
};
