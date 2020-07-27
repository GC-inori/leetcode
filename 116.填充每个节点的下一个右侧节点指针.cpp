/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void creat(Node* p,Node*q)
    {
        if(!p) return;
        p->next=q;
        creat(p->left,p->right);
        creat(p->right,p->next?p->next->left:NULL);//如果p的下一个存在 p右子树的下一个即为p下一个的左子树 否则为空 
    }
    Node* connect(Node* root) 
    {
        creat(root,NULL);
        return root;    
    }
};
