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
    void creat(Node* p,Node *q)
    {
        if(!p) return;
        p->next=q;
        while(q&&!q->left&&!q->right) q=q->next;
        q=q?(q->left?q->left:q->right):NULL;//Ѱ��p��������ָ��λ��  ��һ���ǿ����� 
        if(p->left&&p->right)
        {
            creat(p->right,q);//�ȴ��������� ��Ϊ��q��ֵ��Ҫ�Ұ��next����Ϣ 
            creat(p->left,p->right);
        }
        else if(p->left)
            creat(p->left,q);
        else creat(p->right,q);
    }
    Node* connect(Node* root) {
        creat(root,NULL);

        return root;
    }
};
