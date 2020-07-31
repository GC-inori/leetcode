���ȿ���ָ���ҵ��м�λ�ã�ͷ�巨����һ��Ԫ�ط�ת��
�ٽ���������ϲ� 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) 
    {
        if(!head || !head->next || !head->next->next) return;
        ListNode* h=new ListNode(0,head);
        ListNode* slow = h;
        ListNode* quick = h;
        //�ҵ��м�ڵ��ǰһ���ڵ㣨����������м�ڵ�,slow�ǿ�ǰ���Ǹ���
        while(quick->next && quick->next->next)
        {
            slow = slow->next;
            quick = quick->next->next;
        }
        //��תslow��������нڵ�
        ListNode* h1 = new ListNode(0,NULL);
        ListNode* cur = slow->next;
        slow->next = NULL;
        while(cur)
        {
            ListNode* temp = cur;
            cur=cur->next;
            temp->next=h1->next;
            h1->next=temp;
        }
        //�ϲ�
        cur=h;
        auto p=h->next,q=h1->next;
        while(p)
        {
            cur->next=p;
            cur=p;
            p=p->next;
            cur->next=q;
            cur=q;
            if(q) q=q->next;
        }
    }
};
