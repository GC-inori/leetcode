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
//ֱ��ģ����Ӽ���
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry=0; //��ʾ��λ
        ListNode* res=new ListNode; //ͷ���
        ListNode* cur=res;
        while(l1||l2)
        {
            if(l1) carry+=l1->val,l1=l1->next;;
            if(l2) carry+=l2->val,l2=l2->next;;
            cur->next=new ListNode(carry%10);
            if(carry>=10) carry=1;
            else carry=0;
            cur=cur->next;
        }
        if(carry) cur->next=new ListNode(1);  //���λ��λΪ1
        return res->next;
    }
};
