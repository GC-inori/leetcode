首先快慢指针找到中间位置，头插法将后一半元素翻转。
再将两段链表合并 
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
        //找到中间节点的前一个节点（如果有两个中间节点,slow是靠前的那个）
        while(quick->next && quick->next->next)
        {
            slow = slow->next;
            quick = quick->next->next;
        }
        //反转slow后面的所有节点
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
        //合并
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
