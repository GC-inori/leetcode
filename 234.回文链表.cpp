/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ����ָ���ҵ��м�λ�� ����һ�뷭ת �ж�ǰ���������Ƿ���� 
class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        ListNode *h=new ListNode(0),*fast=h,*slow=h;
        h->next=head;
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        auto t=slow->next;
        slow->next=NULL;
        for(;t;t=fast)
        {
            fast=t->next;
            t->next=slow->next;
            slow->next=t;
        }
        fast=slow->next,slow=h->next;
        while(fast)
        {
            if(fast->val!=slow->val) return 0;
            fast=fast->next;
            slow=slow->next;
        }
        return 1;
    }
};
