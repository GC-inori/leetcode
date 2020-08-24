/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {//本质是迭代版中序遍历 
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) 
    {
        while(root)//左子树入栈 
        {
            s.push(root);
            root=root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() 
    {
        auto t=s.top(),res=t;//访问栈顶元素 
        s.pop();
        t=t->right;
        while(t)//右链入栈 
        {
            s.push(t);
            t=t->left;
        }
        return res->val; 
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return s.size();//如果栈中还有元素说明还有未被访问的元素 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
