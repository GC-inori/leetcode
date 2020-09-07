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
    TreeNode *ans=NULL;
    int dfs(TreeNode*rt,TreeNode* p,TreeNode* q)
    {
        if(!rt) return 0;
        int cnt=dfs(rt->left,p,q)+dfs(rt->right,p,q);//左右子树找到两个点的数量 
        if(p==rt) cnt++;
        else if(q==rt) cnt++;
        if(cnt==2&&!ans) ans=rt;//第一个找到两个点的即为答案 
        return cnt;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        dfs(root,p,q);
        return ans;
    }
};
