����ָ�� 
������ָ�� fast,slow.fast,slow�ֱ����㿪ʼ�ߣ�slowÿ����һ����fastÿ����������
���������fast�ߵ�null����˵�������ڻ���
���� fast �� slow �������� slow ������㣬fast ����ԭ�ز�����Ȼ������ָ��ÿ�ηֱ���һ����������ʱ����������ǻ�����ڡ�
����ڵ�������Ϊl1 ��ڵ���һ������λ�þ���Ϊl2 ��һ������ʱ��ָ������l1+l2+k1*s(sΪ�����ܳ�) ��ָ������ l1+l2+k2s 
��ָ������������ָ��ľ���  l1+l2+k1*s=2*(l1+l2+k2s) �� (k1-k2)*s=l1+l2;
��ʱ��ָ���ٴ�ͷ��l1 ��ʱ��ָ���l2����l1λ��l1+l2 �� (k1-k2)*s=l1+l2����ָ�����ָ����ԭ������ 
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
