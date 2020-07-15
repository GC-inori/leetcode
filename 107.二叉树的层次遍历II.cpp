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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        queue<TreeNode*>  q;
        vector<vector<int>> res;
        if(!root) return res;
        q.push(root);
        while(q.size())
        {
            vector<int> tmp;
            int len=q.size();
            while(len--)
            {
                auto t=q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                tmp.push_back(t->val);
            }
            res.push_back(tmp);
        }
        reverse(res.begin(),res.end());//层次遍历后翻转结果即可 
        return res;  
    }
};
