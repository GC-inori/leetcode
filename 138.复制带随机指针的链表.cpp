第一步，将新生成的结点放在原结点的后边，即 1 -> 1' -> 2 -> 2' -> NULL。新结点的随机指针指向原结点。
第二步，扫描合成的链表，更新新结点的随机指针为原来指向结点的后一个节点。
第三步，将两个链表分离，恢复原链表，返回新链表的头结点。
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
        for(auto p=head;p;p=p->next->next)//复制链表 
        {
            auto q=new Node(p->val);
            q->next=p->next;
            p->next=q;
        }
        for(auto p=head;p;p=p->next->next)//更新随机节点 
        {
            auto q=p->next;
            if(p->random)
                q->random=p->random->next;
            else q->random=NULL;
        }
        Node *res=new Node(0),*q=res;
        for(auto p=head;p;p=p->next)//拆分链表 
        {
            q->next=p->next;
            p->next=p->next->next;
            q=q->next;
        }
        q->next=NULL;
        return res->next;   
    }
};
