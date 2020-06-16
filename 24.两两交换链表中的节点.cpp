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
    ListNode* swapPairs(ListNode* head)   //µü´ú½»»» 
    {
        if(!head) return NULL;
        ListNode *res=new ListNode;
        ListNode *pre=head,*now=head->next,*nxt=head->next?head->next->next:NULL,*cur=res;
        while(now)
        {
            cur->next=now;
            cur->next->next=pre;
            cur=pre;
            pre=nxt;
            now=pre?pre->next:NULL;
            nxt=now?now->next:NULL;

        }
        cur->next=pre;
        cur=res;
        res=res->next;
        delete cur;
        return res;
    }
    ListNode* swapPairs(ListNode* head)  //µÝ¹é°æ±¾ 
    {
        if(!head||!head->next) return head;
        ListNode* tmp=head->next->next,*t=head->next;
        t->next=head;
        head->next=swapPairs(tmp);
        return t;
    }
};
