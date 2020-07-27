/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* creat(Node* node,vector<Node*> &f)
    {
        if(f[node->val]) return f[node->val];//����Ѿ�������ֱ�ӷ��ظ�ָ�� 
        Node *r=new Node(node->val);
        f[node->val]=r;
        for(auto &c:node->neighbors)
            r->neighbors.push_back(creat(c,f));
        return r;
    }
    Node* cloneGraph(Node* node) 
    {
        if(!node) return NULL;
        vector<Node*> f(110,NULL);//��f�����Ѿ������õĽڵ� 
        return creat(node,f);
    }
};
