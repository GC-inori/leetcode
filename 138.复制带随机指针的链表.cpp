��һ�����������ɵĽ�����ԭ���ĺ�ߣ��� 1 -> 1' -> 2 -> 2' -> NULL���½������ָ��ָ��ԭ��㡣
�ڶ�����ɨ��ϳɵ����������½������ָ��Ϊԭ��ָ����ĺ�һ���ڵ㡣
��������������������룬�ָ�ԭ���������������ͷ��㡣
/* 
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        for(auto p=head;p;p=p->next->next)//�������� 
        {
            auto q=new Node(p->val);
            q->next=p->next;
            p->next=q;
        }
        for(auto p=head;p;p=p->next->next)//��������ڵ� 
        {
            auto q=p->next;
            if(p->random)
                q->random=p->random->next;
            else q->random=NULL;
        }
        Node *res=new Node(0),*q=res;
        for(auto p=head;p;p=p->next)//������� 
        {
            q->next=p->next;
            p->next=p->next->next;
            q=q->next;
        }
        q->next=NULL;
        return res->next;   
    }
};
