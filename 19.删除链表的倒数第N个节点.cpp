˫ָ��
��ͷ��֮ǰ���ͷ��㡣
��������ָ�� fast �� slow����ָ��ͷ��㡣
fast ָ��������ƶ� n ����㡣
Ȼ�� slow �� fast ָ��ͬʱ����ƶ���ֱ�� fast ָ��ָ��գ���ʱ slow ���ָ�����һ�������Ҫɾ���� 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *h=new ListNode;
        h->next=head;
        ListNode *slow=h,*fast=h,*tmp;
        n++; 
        while(n--)
            fast=fast->next;
        while(fast)
        {
            fast=fast->next;
            slow=slow->next;
        }
        tmp=slow->next;
        slow->next=slow->next->next;
        delete tmp;
        head=h->next;
        delete h;
        return head;
    }
};
