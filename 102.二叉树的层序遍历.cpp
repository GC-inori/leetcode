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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<TreeNode*> s;
        s.push(root);
        vector<vector<int>> res;
        if(!root) return res;
        while(s.size())
        {
            int len=s.size();
            vector<int> tmp;
            while(len--) //一次遍历一层 
            {
                auto t=s.front();
                s.pop();
                if(t->left) s.push(t->left);
                if(t->right) s.push(t->right);
                tmp.push_back(t->val);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
