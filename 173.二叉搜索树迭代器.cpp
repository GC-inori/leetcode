/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {//�����ǵ������������ 
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) 
    {
        while(root)//��������ջ 
        {
            s.push(root);
            root=root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() 
    {
        auto t=s.top(),res=t;//����ջ��Ԫ�� 
        s.pop();
        t=t->right;
        while(t)//������ջ 
        {
            s.push(t);
            t=t->left;
        }
        return res->val; 
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return s.size();//���ջ�л���Ԫ��˵������δ�����ʵ�Ԫ�� 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
