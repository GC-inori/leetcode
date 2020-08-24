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
        t->next=head;//添加结尾 可能删除了结尾 
        return h->next;
    }
};
