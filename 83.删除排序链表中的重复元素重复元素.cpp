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
    int pre=-1e9;
    ListNode* delete1(ListNode* head)
    {
        if(!head) return NULL;
        if(head->val==pre) return delete1(head->next);
        pre=head->val;
        head->next=delete1(head->next);
        return head;
    } 
    ListNode* deleteDuplicates(ListNode* head) 
    {
        int pre=-1e9;
        return delete1(head);    
    }
};
