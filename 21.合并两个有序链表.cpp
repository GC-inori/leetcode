/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)  //迭代合并 
    {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val>l2->val) return mergeTwoLists(l2, l1);
        ListNode *res=l1,*t=res;
        l1=l1->next;
        while(l1&&l2)
        {
            if(l1->val<l2->val) 
            {
                t->next=l1;
                t=t->next;
                l1=l1->next;
            }
            else
            {
                t->next=l2;
                t=t->next;
                l2=l2->next;
            }
        }
        if(l1)
            t->next=l1;
        else
            t->next=l2;
        return res;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) //递归合并 
    {
        if(!l1) return l2; 
        if(!l2) return l1;
        if(l1->val<l2->val)
        {
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        l2->next=mergeTwoLists(l1,l2->next);
        return l2;
    }
};
