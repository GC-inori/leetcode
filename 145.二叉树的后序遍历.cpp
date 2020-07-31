/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 后序遍历顺序为左右根 建立一种新遍历顺序 根右左和后序遍历顺序正好相反 把结果翻转就是后序遍历 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        stack<TreeNode*> s;
        while(root)
        {
            while(root)//沿右子树下降 
            {
                res.push_back(root->val);
                if(root->left) s.push(root->left);
                root=root->right;
            }
            if(s.size())//访问左子树 
            {
                root=s.top();
                s.pop();
            }
        }
        return vector<int> (res.rbegin(),res.rend());
    }
};
