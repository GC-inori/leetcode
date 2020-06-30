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
        while(tail->next)  //��һ�α����ҵ���β �������ܽ����cnt 
        {
            tail=tail->next;
            cnt++;
        }
        k=k%cnt;
        if(!k) return head;
        while(k)   //����ָ���ҵ�������k����� 
        {
            fast=fast->next;
            k--;
        }
        while(fast!=tail)
        {
            fast=fast->next;
            slow=slow->next;
        }
        fast=slow->next; //ƴ������ fast��ʱָ������k���ڵ� 
        slow->next=NULL; //slow������k+1����� 
        tail->next=head;//tail��β 
        return fast;
    }
};
