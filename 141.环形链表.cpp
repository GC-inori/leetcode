快慢指针法 
用两个指针从头开始扫描，慢指针每次走一步，快指针每次走两步。如果快指针走到 null，说明不存在环；否则如果两个指针相遇，则说明存在环。
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
    bool hasCycle(ListNode *head) 
    {
        auto fast=head,slow=head;
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) return 1;
        }
        return 0;    
    }
};
