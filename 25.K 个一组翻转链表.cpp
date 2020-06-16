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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head) return NULL;
        ListNode* t=head,*tmp;
        for(int i=0;i<k-1;i++)
        {
            if(t->next) t=t->next;
            else return head;
        }
        ListNode* h=new ListNode;
        ListNode* nxt=t->next;
        t=head;
        for(int i=0;i<k;i++)
        {
            tmp=head->next;
            head->next=h->next;
            h->next=head;
            head=tmp;
        }
        t->next=reverseKGroup(nxt,k);
        t=h;
        h=h->next;
        delete t;
        return h;
    }
};
