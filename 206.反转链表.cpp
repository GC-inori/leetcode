class Solution {
public:
	//����ͷ�巨 
    ListNode* reverseList(ListNode* head) 
    {
        auto h=new ListNode(0);
        for(auto t=head;head;head=t)
        {
            t=t->next;
            head->next=h->next;
            h->next=head;
        }
        return h->next;
    }
    //�ݹ�д�� 
    ListNode* reverseList(ListNode* head) 
    {
        if(!head||!head->next) return head;
        auto t=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return t;
    }
};
