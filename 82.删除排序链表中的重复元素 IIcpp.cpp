Ϊ�˷��㴦��߽����������һ������Ԫ�� r ָ������ͷ�ڵ㡣
Ȼ���ǰ����ɨ����������ÿ��ɨ��Ԫ����ͬ��һ�Σ��������е�Ԫ�ظ�������1����������Ԫ��ֱ��ɾ����
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *r=new ListNode(-1e9),*p=r,*q=head;
        p->next=q;
        while(p->next)
        {
            while(q&&q->val==p->next->val) q=q->next;//������ȵ�Ԫ�أ�ֱ��Ϊ�ջ��һ������ȵ�Ԫ�� 
            if(q==p->next->next) p=p->next; //���û����ͬԪ��ֱ�Ӻ��� 
            else p->next=q; //����ɾ�� 
        }
        return r->next;    
    }
};
