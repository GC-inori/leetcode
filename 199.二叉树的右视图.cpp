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
    void dfs(TreeNode* r,int h,vector<int> &v)
    {
        if(!r) return;
        if(h>v.size()) v.push_back(r->val);//���������һ�����Ҳ������ 
        if(r->right) dfs(r->right,h+1,v);//�ȵݹ������� 
        if(r->left) dfs(r->left,h+1,v);
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> res;
        dfs(root,1,res);
        return res;
    }
};
py ���������ÿһ�����һ����ӵ����� 
from queue import Queue
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root :
            return []
        q=Queue();
        res=[];
        q.put(root)
        while q.qsize() :
            l= q.qsize();
            for i in range (0,l) :
                t=q.get();
                if t.left :
                    q.put(t.left)
                if t.right :
                    q.put(t.right)
                if i==l-1 :
                    res.append(t.val)
        return res
