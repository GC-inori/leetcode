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
    unordered_map<int,int> hash;
    TreeNode *build(vector<int>& inorder, vector<int>& postorder,int l1,int r1,int l2,int r2)
    {
        if(r1<l1) return NULL;
        cout<<r2<<" ";
        TreeNode *roof=new TreeNode(postorder[r2]);
        int t=hash[postorder[r2]];
        roof->left=build(inorder,postorder,l1,t-1,l2,l2+t-1-l1);
        roof->right=build(inorder,postorder,t+1,r1,l2-l1+t,r2-1);
        return roof;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        for(int i=0;i<inorder.size();i++) hash[inorder[i]]=i;
        return build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);    
    }
};
