/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 自底向上的归并排序 
class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        int cnt=0;
        for(auto p=head;p;p=p->next) cnt++;//计算链表长度 
        auto h=new ListNode(0),cur=h,p=head,q=p,ne=p;//p第一个归并段起始位置 q第二个归并段起始位置 ne下一次归并开始位置 
        h->next=head;//h虚拟头节点 
        for(int i=1;i<cnt;i<<=1)//i归并段长度 
        {
            cur=h;//cur插入位置 
            for(int j=1;j+i<=cnt;j+=2*i)//枚举开始位置 
            {
                q=p=cur->next;
                for(int k=0;k<i&&q;k++) q=q->next;//q向后移动i个到达第二个归并段起始位置 
                ne=q;
                for(int k=0;k<i&&ne;k++) ne=ne->next;//ne向后移动i个到达 ne下一次归并开始位置 
                int n1=0,n2=0;
                while(n1<i&&n2<i&&p&&q)//归并 
                {
                    if(p->val<=q->val) cur=cur->next=p,p=p->next,n1++;
                    else cur=cur->next=q,q=q->next,n2++;
                }
                while(n1<i&&p) cur=cur->next=p,p=p->next,n1++;//归并剩余元素 
                while(n2<i&&q) cur=cur->next=q,q=q->next,n2++;
                cur->next=ne;//将下次开始位置接过来 
            }
        }
        return h->next;
    }
};
