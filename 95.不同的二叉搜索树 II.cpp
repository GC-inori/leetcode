����ÿ������������ l,l+1,��rl,l+1,��r��ö�ٶ������������ڵ��λ�ã�
�ֱ�ݹ�����������������з�����
������������һ�ַ�����������������һ�ַ���ƴ��һ�𣬿��Եõ���ǰ�ڵ��һ�ַ��������Խ��������������з���������ϣ�����¼�ڴ��С�
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
            for(auto &cl:ll)//ö������������ 
                for(auto &cr:rr)//ö������������ 
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
