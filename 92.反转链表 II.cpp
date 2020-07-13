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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        auto h=new ListNode;
        h->next=head;//虚拟头节点 
        auto now=h;//当前位置 
        for(int i=1;i<m;i++)//找到第m-1的位置 
            now=now->next;
        auto tail=now->next;//反转后的结尾是第m位置的元素 
        auto p=now;//p是头插法的头 
        now=now->next;//移动到第m位 
        for(int i=m;i<=n;i++)//头插法翻转链表 
        {
            auto tmp=now->next;
            now->next=p->next;
            p->next=now;
            now=tmp;
        }
        tail->next=now;//将结尾元素和之后链表拼在一起 
        return h->next;
    }
};
