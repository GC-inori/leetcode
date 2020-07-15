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
    TreeNode *build(vector<int>& preorder, vector<int>& inorder,int l1,int l2,int r1,int r2)
    {
        if(l1>r1) return NULL;
        TreeNode* roof=new TreeNode(preorder[l1]);
        int t=m[preorder[l1]];
        roof->left=build(preorder,inorder,l1+1,l2,l1+t-l2,t-1);
        roof->right=build(preorder,inorder,l1+t-l2+1,t+1,r1,r2);
        return roof;
    }
    unordered_map<int,int> m;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        for(int i=0;i<inorder.size();i++) m[inorder[i]]=i;  //用m保存每个值的位置  便于在中序中寻找根 
        return build(preorder,inorder,0,0,preorder.size()-1,inorder.size()-1);    
    }
};
