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
        creat(p->right,p->next?p->next->left:NULL);//���p����һ������ p����������һ����Ϊp��һ���������� ����Ϊ�� 
    }
    Node* connect(Node* root) 
    {
        creat(root,NULL);
        return root;    
    }
};
