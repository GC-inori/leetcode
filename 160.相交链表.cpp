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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)  
    {
        if(headA==headB) return headA;
        int la=0,lb=0;
        for(auto t=headA;t;t=t->next) la++;
        for(auto t=headB;t;t=t->next) lb++;//������������� 
        if(la<lb)
        {
            swap(la,lb);
            swap(headA,headB);
        }
        for(int i=0;i<la-lb;i++) headA=headA->next;//�������� 
        while(headB!=headA)//ʣ����ͬ����һ���� 
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;      
    }
    //����
	//��һ��ָ���headA��ʼ�� ����headA֮���headB��ʼ��
	//�ڶ���ָ���headB��ʼ�� ����headB֮���headA��ʼ��
	//��headA���������Ϊa headB���������Ϊb ���㵽��βΪc ������ָ�붼����a+b+cʱ���ڽ�������
	//���û�н��� ����NULL���� 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        auto p=headA,q=headB;
        while(p!=q)
        {
            p=p?p->next:headB;
            q=q?q->next:headA;
        }
        return p;
    }
};
