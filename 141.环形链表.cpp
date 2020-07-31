����ָ�뷨 
������ָ���ͷ��ʼɨ�裬��ָ��ÿ����һ������ָ��ÿ���������������ָ���ߵ� null��˵�������ڻ��������������ָ����������˵�����ڻ���
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
