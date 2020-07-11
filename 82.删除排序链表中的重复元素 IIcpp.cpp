为了方便处理边界情况，定义一个虚拟元素 r 指向链表头节点。
然后从前往后扫描整个链表，每次扫描元素相同的一段，如果这段中的元素个数多于1个，则将整段元素直接删除。
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *r=new ListNode(-1e9),*p=r,*q=head;
        p->next=q;
        while(p->next)
        {
            while(q&&q->val==p->next->val) q=q->next;//跳过相等的元素，直到为空或第一个不相等的元素 
            if(q==p->next->next) p=p->next; //如果没有相同元素直接后移 
            else p->next=q; //否则删除 
        }
        return r->next;    
    }
};
