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
    ListNode* insertionSortList(ListNode* head) 
    {
        auto h=new ListNode(0);
        while(head)
        {
            auto t=head,p=h;
            head=head->next;
            while(p->next&&p->next->val<t->val) p=p->next;//Ñ°ÕÒ²åÈëµãp 
            t->next=p->next;
            p->next=t; 
        }
        return h->next;
    }
};
