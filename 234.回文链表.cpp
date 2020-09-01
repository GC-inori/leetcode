/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 快慢指针找到中间位置 将后一半翻转 判断前后两部分是否相等 
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
