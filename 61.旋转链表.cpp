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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head) return head;
        int cnt=1;
        ListNode* tail=head,*fast=head,*slow=head;
        while(tail->next)  //第一次遍历找到结尾 和链表总结点数cnt 
        {
            tail=tail->next;
            cnt++;
        }
        k=k%cnt;
        if(!k) return head;
        while(k)   //快慢指针找到倒数第k个结点 
        {
            fast=fast->next;
            k--;
        }
        while(fast!=tail)
        {
            fast=fast->next;
            slow=slow->next;
        }
        fast=slow->next; //拼接链表 fast此时指向倒数第k个节点 
        slow->next=NULL; //slow倒数第k+1个结点 
        tail->next=head;//tail结尾 
        return fast;
    }
};
