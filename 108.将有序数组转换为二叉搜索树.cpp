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
    TreeNode* creat(vector<int>& nums,int l,int r)
    {
        if(l>r) return NULL;
        int mid=l+r>>1;
        TreeNode* rf=new TreeNode(nums[mid]);
        rf->left=creat(nums,l,mid-1);
        rf->right=creat(nums,mid+1,r);
        return rf;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return creat(nums,0,nums.size()-1);
    }
};
