对于每段连续的序列 l,l+1,…rl,l+1,…r，枚举二叉搜索树根节点的位置；
分别递归求出左右子树的所有方案；
左子树的任意一种方案和右子树的任意一种方案拼在一起，可以得到当前节点的一种方案，所以将左右子树的所有方案两两组合，并记录在答案中。
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
    vector<TreeNode*> dfs(int l,int r)
    {
        if(l>r) return {NULL};
        vector<TreeNode*> v;
        for(int i=l;i<=r;i++)
        {
            auto ll=dfs(l,i-1),rr=dfs(i+1,r);
            for(auto &cl:ll)//枚举左子树方案 
                for(auto &cr:rr)//枚举右子树方案 
                {
                    auto r=new TreeNode(i);
                    r->left=cl;
                    r->right=cr;
                    v.push_back(r);
                }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) 
    {
        if(!n) return {};
        return dfs(1,n);    
    }
};
