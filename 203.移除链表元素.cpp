/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode *h=new ListNode(0),*t=h;
        h->next=head;
        while(head)
        {
            if(head->val!=val)
                t->next=head,t=t->next;
            head=head->next;
        }
        t->next=head;//��ӽ�β ����ɾ���˽�β 
        return h->next;
    }
};
