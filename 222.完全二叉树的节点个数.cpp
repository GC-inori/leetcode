������һ�㶼���Կ��ǳɵݹ����⣬����ÿ���ڵ㣬����һֱ�����һֱ���ҵĸ߶ȣ���������˵����������������ô�����ڵ����Ϊ^h-1(h�Ƕ������ĸ߶�)��
����������˵��������������������Ҫ�ݹ��������⣬�ÿ����Ľڵ��������1+�������ڵ���+�������ڵ���.
��ʵ���һ��Ķ���������ڵ������˼·��һ���ģ���ͬ������������ȫ���������������һֱ�����һֱ���ҵĸ߶���ȵĻ��Ϳ������ϼ�����ڵ���������ü������µݹ��ˡ�
������൱�ڶ��ֲ������һ�����һ���ڵ��λ�ã�ÿ�β��ҵĸ��Ӷ���O(logn)��һ����Ҫ����O(logn)�Σ����Ը��Ӷ�ΪO(logn)*O(logn)��
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
    int countNodes(TreeNode* root) 
    {
        if(!root) return 0;
        auto l=root->left,r=root->right;
        int cntl=0,cntr=0;
        while(l) cntl++,l=l->left;
        while(r) cntr++,r=r->right;
        if(cntl==cntr)
            return (1<<(cntl+1))-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};

