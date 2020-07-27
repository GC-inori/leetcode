/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 树形dp 在叶子节点处计算数值 
class Solution {
public:
    int ans=0;
    void dfs(TreeNode* root,int x)
    {
        x=x*10+root->val;  //更新根到该节点的数值 
        if(!root->left&&!root->right)//叶子节点返回 
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
