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
        for(auto t=headB;t;t=t->next) lb++;//求出两个链表长度 
        if(la<lb)
        {
            swap(la,lb);
            swap(headA,headB);
        }
        for(int i=0;i<la-lb;i++) headA=headA->next;//长的先走 
        while(headB!=headA)//剩下相同长度一起走 
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;      
    }
    //法二
	//第一个指针从headA开始走 走完headA之后从headB开始走
	//第二个指针从headB开始走 走完headB之后从headA开始走
	//设headA到交点距离为a headB到交点距离为b 交点到结尾为c 当两个指针都走了a+b+c时会在交点相遇
	//如果没有交点 会在NULL相遇 
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
