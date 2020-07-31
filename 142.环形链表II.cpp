快慢指针 
用两个指针 fast,slow.fast,slow分别从起点开始走，slow每次走一步，fast每次走两步。
如果过程中fast走到null，则说明不存在环。
否则当 fast 和 slow 相遇后，让 slow 返回起点，fast 待在原地不动，然后两个指针每次分别走一步，当相遇时，相遇点就是环的入口。
设入口到起点距离为l1 入口到第一次相遇位置距离为l2 第一次相遇时快指针走了l1+l2+k1*s(s为环的周长) 慢指针走了 l1+l2+k2s 
快指针走了两倍慢指针的距离  l1+l2+k1*s=2*(l1+l2+k2s) 即 (k1-k2)*s=l1+l2;
此时慢指针再从头走l1 此时快指针从l2走了l1位于l1+l2 而 (k1-k2)*s=l1+l2即快指针和慢指针在原点相遇 
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
    ListNode *detectCycle(ListNode *head) 
    {
        if(!head) return NULL;
        auto h=new ListNode(0),slow=h,fast=h;
        h->next=head;
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) break;
        }
        if(fast!=slow) return NULL;
        slow=h;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};
