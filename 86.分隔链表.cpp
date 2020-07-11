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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* h1=new ListNode(1),*h2=new ListNode(1),*p=h1,*q=h2;//创建两个链表h1和h2 小于x的接在h1结尾 其他接在h2结尾 
        while(head)// p q插入指针 
        {
            if(head->val<x) p->next=head,p=head;
            else q->next=head,q=head;
            head=head->next;
        }
        q->next=NULL;
        p->next=h2->next;
        return h1->next;    
    }
};
