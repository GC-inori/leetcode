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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        stack<TreeNode*> s;
        while(root)
        {
            while(root)//沿着左子树访问 
            {
                res.push_back(root->val);
                if(root->right) s.push(root->right);//如果右子树不为空加入栈中 
                root=root->left;
            }
            if(s.size()) //访问右子树 
            {
                root=s.top();
                s.pop();
            }
        }
        return res;
    }
};
