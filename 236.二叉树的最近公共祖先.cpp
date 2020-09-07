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
        int cnt=dfs(rt->left,p,q)+dfs(rt->right,p,q);//���������ҵ������������ 
        if(p==rt) cnt++;
        else if(q==rt) cnt++;
        if(cnt==2&&!ans) ans=rt;//��һ���ҵ�������ļ�Ϊ�� 
        return cnt;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        dfs(root,p,q);
        return ans;
    }
};
