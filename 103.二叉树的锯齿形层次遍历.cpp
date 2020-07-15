与上题类似 只需要遍历完一层厚判断是否需要翻转即可 
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        if(!root) return res;
        bool f=0;
        while(q.size())
        {
            int len=q.size();
            vector<int> tmp;
            while(len--)
            {
                auto t=q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                tmp.push_back(t->val);
            }
            if(f) reverse(tmp.begin(),tmp.end());
            f=!f;
            res.push_back(tmp);
        }
        return res;
    }
};
