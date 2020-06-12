双指针
在头部之前添加头结点。
设置两个指针 fast 和 slow，均指向头结点。
fast 指针先向后移动 n 个结点。
然后 slow 和 fast 指针同时向后移动，直到 fast 指针指向空，此时 slow 结点指向的下一个结点需要删除。 
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
