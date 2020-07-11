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
        ListNode* h1=new ListNode(1),*h2=new ListNode(1),*p=h1,*q=h2;//������������h1��h2 С��x�Ľ���h1��β ��������h2��β 
        while(head)// p q����ָ�� 
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
